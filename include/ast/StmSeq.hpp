//
// Created by CanhDo on 2024/11/20.
//

#ifndef STMSEQ_HPP
#define STMSEQ_HPP

#include "ast/StmNode.hpp"

class StmSeq {
public:
    StmSeq();

    ~StmSeq() = default;

    void addStm(StmNode *stm);

    StmNode *getHead() const;

    StmNode *getTail() const;

    void dump(bool recursive = true);

private:
    StmNode *head;
    StmNode *tail;
};

#endif //STMSEQ_HPP