//
// Created by Jonas on 2019-11-14.
//
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

Block Blockchain::_GetLastBlock() const {
    return _Chain.back();
}

