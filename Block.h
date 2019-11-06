//
// Created by Jonas on 2019-11-14.
//

#ifndef BLOCKCHAINV2_BLOCK_H
#define BLOCKCHAINV2_BLOCK_H

#include <cstdint>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Block{
public:
    string PrevHash;

    Block();

    Block(string base);

    string GetHash();

    uint32_t GetDifficulty();

    void MineBlock(uint32_t Difficulty);

    int MineBlockv2(uint32_t Difficulty, int limit);

    void SetMarkel();

    void NewTransaction(string name1, string name2, int amount);

    void RemoveLastTransaction();

    vector<string> GetLastTransaction();
private:
    time_t _Time;
    string _Version;
    int64_t _Nonce;
    uint32_t _Difficulty;
    string _MarkelHash;
    string _Hash;
    vector<vector <string>> _Transactions;
    string _CalculateHash() const;
};

#endif //BLOCKCHAINV2_BLOCK_H
