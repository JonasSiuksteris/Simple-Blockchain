//
// Created by Jonas on 2019-11-14.
//

#ifndef BLOCKCHAINV2_BLOCKCHAIN_H
#define BLOCKCHAINV2_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;

class Blockchain{
public:
    Blockchain();

    void AddBlock(Block bNew);

    int AddBlockv2(vector<Block> bNew, int limit);

private:
    vector<Block> _Chain;

    Block _GetLastBlock() const;

};

#endif //BLOCKCHAINV2_BLOCKCHAIN_H
