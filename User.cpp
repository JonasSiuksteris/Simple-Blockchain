//
// Created by Jonas on 2019-12-12.
//

#include "User.h"
#include "Hash.h"

User::User(const string& name, int cash)
{
    _name = name;
    _Ecoin = cash;
    _publich_hash = Hash64(_name + to_string(_Ecoin));
}

string User::GetName()
{
    return _name;
}
string User::GetInfo()
{
    return "Name : " + _name + " public hash " + _publich_hash + " Ecoin: " + to_string(_Ecoin);
}
int User::GetCash()
{
    return _Ecoin;
}
void User::AddCash(int cash)
{
    _Ecoin += cash;
}
void User::RemoveCash(int cash)
{
    _Ecoin -= cash;
}