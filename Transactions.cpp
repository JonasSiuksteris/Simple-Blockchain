//
// Created by Jonas on 2019-11-14.
//

#include <random>
#include <cstdint>
#include <iomanip>
#include "User.h"
#include "Hash.h"
#include "Blockchain.h"

void inline GenerateUser(int count, vector<User>& Users)
{
    random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator
    uniform_int_distribution<> distr(100, 1000000); // define the range

    int cash;



    ofstream file("Users.txt");
    file << "User   EvilCoin   Public_key" << endl;
    for(int i = 0; i < count; i++)
    {
        cash = distr(eng);
        Users.emplace_back(User("User" +to_string(i), cash));
        file << "User" + to_string(i) << " " << cash << " " << Hash64("User" + to_string(i) + to_string(cash)) << endl;
    }
}
void inline RandomTransactionsv2(int count, vector<User>& Users, Blockchain& bChain) {
    vector<Block> Blocks;

    int first, second, success = 0, cyclecount;
    for (int i = 1; i + 1 < count; i++) {
        random_device rd;
        mt19937 eng(rd());

        uniform_int_distribution<> distr(0, Users.size() - 1);

        if ((i - 1) % 100 == 0) {
            Blocks.clear();
            for(int j = 0; j < 5; j++)
                Blocks.emplace_back();
        }


        for(int j = 0; j < 5; j++)
        {
            first = distr(eng);
            do {
                second = distr(eng);
            } while (first == second);


            uniform_int_distribution<> Ramount(1, Users[first].GetCash());
            int amount = Ramount(eng);

            Blocks[j].NewTransaction(Users[first].GetName(), Users[second].GetName(), amount);
            //cout << Blocks[j].GetLastTransaction()[0] << " " << Blocks[j].GetLastTransaction()[3] << endl;
            //Checking if transaction is valid
            if(Hash64(Users[first].GetName() + Users[second].GetName() + to_string(amount)) != Blocks[j].GetLastTransaction()[0])
            {
                Blocks[j].RemoveLastTransaction();
                cout << "\nInvalid transaction\n";
            }


            Users[first].RemoveCash(amount);
            Users[second].AddCash(amount);
        }
        if(i % 100 == 0){
            cyclecount = 1;
            success = 0;
            cout << i / 100 << endl;
            while(success == 0){
                success = bChain.AddBlockv2(Blocks,cyclecount * 10000);
                cyclecount ++;
            }
        }


    }
}
void inline RandomTransactions(int count, vector<User>& Users, Blockchain& bChain)
{
    random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator

    uniform_int_distribution<> distr(0, Users.size() - 1); // define the range

    Block bNew = Block();
    int first, second;

    for(int i = 1; i+1 < count; i++)
    {
        if((i-1) % 100 == 0)
        {
            bNew = Block();
        }


        first = distr(eng);
        do{
            second = distr(eng);
        }while(first == second);

        uniform_int_distribution<> Ramount(1, Users[first].GetCash());
        int amount = Ramount(eng);
        bNew.NewTransaction(Users[first].GetName(), Users[second].GetName(), amount);
        //Checking if transaction is valid
        if(Hash64(Users[first].GetName() + Users[second].GetName() + to_string(amount)) != bNew.GetLastTransaction()[0])
        {
            bNew.RemoveLastTransaction();
            cout << "\nInvalid transaction\n";
        }

        Users[first].RemoveCash(amount);
        Users[second].AddCash(amount);

        if(i % 100 == 0){
            cout << i / 100 << endl;
            bChain.AddBlock(bNew);
        }
    }
}