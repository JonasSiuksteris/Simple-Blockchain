#include <time.h>
#include "Block.h"
#include "Hash.h"

Block::Block()
{
    _Version = 1;
    _Nonce = -1;
    _Difficulty = 4;
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

int Block::MineBlockv2(uint32_t Difficulty, int limit) {
    char cstr[Difficulty + 1];
    for (uint32_t i = 0; i < Difficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[Difficulty] = '\0';

    string str(cstr);

    do {
        _Nonce++;
        _Hash = Hash64(_CalculateHash() + _Transactions[0][0]);
    } while (_Hash.substr(0, Difficulty) != str && _Nonce <= limit);

    if(_Nonce <= limit)
    {
        cout << "Block mined: " << _Hash << endl;
        cout << "Cicles:" << _Nonce << endl;
        return 1;
    }
    else
    {
        cout <<"Block took too long to mine\n";
        return 0;
    }
}

inline string Block::_CalculateHash() const {
    stringstream ss;
    ss << _Time << _Version << _Nonce << PrevHash << _Difficulty << _MarkelHash;

    return Hash64(ss.str());
}

void Block::NewTransaction(string name1, string name2, int amount)
{
    vector<string> temp{Hash64(name1+name2+to_string(amount)),name1,name2,to_string(amount)};
    _Transactions.push_back(temp);
}

vector<string> Block::GetLastTransaction()
{
    return _Transactions.back();
}

void Block::RemoveLastTransaction()
{
    _Transactions.pop_back();
}

void Block::create_merkle()
{
    vector<string> merkle, merkle2;
    for(int i = 0; i < _Transactions.size(); i++)
    {
        merkle.push_back( _Transactions[i][0]);
    }


    // Stop if hash list is empty or contains one element
    if (merkle.empty())
        _MarkelHash = "1234567890abcdeffedcba09876543211234567890abcdeffedbca0987654321";
    else if (merkle.size() == 1)
        _MarkelHash = merkle[0];

    // While there is more than 1 hash in the list, keep looping...
    while (merkle.size() > 1)
    {
        merkle2.clear();
        // If number of hashes is odd, duplicate last hash in the list.
        if (merkle.size() % 2 != 0)
            merkle.push_back(merkle.back());
        // List size is now even.
        for(int i = 0; i < merkle.size(); i+=2)
        {
            merkle2.push_back(Hash64(merkle[i] + merkle[i+1])) ;
        }

        merkle = merkle2;
    }
    // Finally we end up with a single item.
    _MarkelHash = merkle[0];
}