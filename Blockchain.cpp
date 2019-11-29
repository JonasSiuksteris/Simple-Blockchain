#include "Blockchain.h"

Blockchain::Blockchain() {
    _Chain.emplace_back(Block("Base"));
}

void Blockchain::AddBlock(Block bNew) {
    bNew.PrevHash = _GetLastBlock().GetHash();
    bNew.MineBlock(bNew.GetDifficulty());
    bNew.SetMarkel();
    _Chain.push_back(bNew);
}

int Blockchain::AddBlockv2(vector<Block> bNew, int limit) {
    int cycles = 0, success = 0;

    while(cycles < 5 && success == 0){
        bNew[cycles].PrevHash = _GetLastBlock().GetHash();
        success = bNew[cycles].MineBlockv2(bNew[cycles].GetDifficulty(),limit);
        bNew[cycles].create_merkle();
        cycles ++;
    }
    if(cycles == 5)
        return 0;
    else
    {
        _Chain.push_back(bNew[cycles]);
        return 1;
    }
}

Block Blockchain::_GetLastBlock() const {
    return _Chain.back();
}

