//
// Created by Jonas on 2019-12-12.
//

#ifndef BLOCKCHAINV2_USER_H
#define BLOCKCHAINV2_USER_H

#include <sstream>

using namespace std;

class User{
private:
    string _name;
    string _publich_hash;
    int _Ecoin;
public:
    User(const string& name, int cash);
    string GetName();
    string GetInfo();
    int GetCash();
    void AddCash(int cash);
    void RemoveCash(int cash);
};

#endif //BLOCKCHAINV2_USER_H
