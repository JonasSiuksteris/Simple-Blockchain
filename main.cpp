#include <iostream>
#include <vector>
#include "Blockchain.h"
#include "Transactions.cpp"
#include "User.h"

int main()
{
    std::vector<User> Users;
    Blockchain bChain = Blockchain();
    int choice = 0, amount;
    while(choice != 4)
    {
        cout << "1 - Generuoti naujus vartotojus\n2 - Vykdyti transakcijas\n3 - Vykdyti transakcijas(patobulinta)\n4 - Iseiti\n" << endl;
        cin >> choice;
        while(!(choice == 1 || choice == 2 || choice == 3 || choice == 4) || !cin){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Bloga ivestis, kartokite!" << endl;
            cin >> choice;
        };
        switch(choice){
            case 1:
                cout << "Iveskite norima vartotoju skaiciu(int)" << endl;
                cin >> amount;
                GenerateUser(amount, Users);
                break;
            case 2:
                if(Users.empty())
                {
                    cout << "Pirma sukurkite vartotojus" << endl;
                    break;
                }

                cout << "Iveskite norimu transakciju skaiciu(int)" << endl;
                cin >> amount;
                RandomTransactions(amount, Users, bChain);
                break;
            case 3:
                if(Users.empty())
                {
                    cout << "Pirma sukurkite vartotojus" << endl;
                    break;
                }

                cout << "Iveskite norimu transakciju skaiciu(int)" << endl;
                cin >> amount;
                RandomTransactionsv2(amount, Users, bChain);
                break;
            case 4:
                cout << "Programa uzdaroma" << endl;
        }
    }



    //for(int i = 0; i < 1000; i++)
     //   cout << Users[i].GetInfo() << endl;


    return 0;
}