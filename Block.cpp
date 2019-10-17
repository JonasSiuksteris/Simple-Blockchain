//
// Created by Jonas on 2019-11-14.
//
#include <time.h>
#include "Block.h"
#include "Hash.h"

Block::Block()
{
    _Version = 1;
    _Nonce = -1;
    _Difficulty = 3;
    _Time = time(nullptr);
}
Block::Block(string base)
{
    _Version = 1;
    _Nonce = -1;
    _Difficulty = 3;
    _Time = time(nullptr);
    PrevHash = Hash64(base);
}
string Block::GetHash() {
    return _Hash;
}

uint32_t Block::GetDifficulty(){
    return _Difficulty;
}

void Block::SetMarkel()
{
    _MarkelHash = Hash64(_Hash + PrevHash);
}

void Block::MineBlock(uint32_t Difficulty) {
    char cstr[Difficulty + 1];
    for (uint32_t i = 0; i < Difficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[Difficulty] = '\0';

    string str(cstr);

    do {
        _Nonce++;
        _Hash = _CalculateHash();
    } while (_Hash.substr(0, Difficulty) != str);

    cout << "Block mined: " << _Hash << endl;
    cout << "Cicles:" << _Nonce << endl;
}

inline string Block::_CalculateHash() const {
    stringstream ss;
    ss << _Time << _Version << _Nonce << PrevHash << _Difficulty << _MarkelHash;

    return Hash64(ss.str());
}

void Block::NewTransaction(string name1, string name2, int amount)
{
    vector<string> temp{name1,name2,to_string(amount)};
    _Transactions.push_back(temp);
}
