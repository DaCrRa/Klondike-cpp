/*
 * CardVisitor.h
 *
 *  Created on: 15 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_CARDS_INC_CARDVISITOR_H_
#define SRC_CARDS_INC_CARDVISITOR_H_

class CardVisitor {
public:
    virtual void visitRank(int rank) const = 0;
    virtual void visitSuit(int suit) const = 0;
    virtual ~CardVisitor() {}
};

#endif /* SRC_CARDS_INC_CARDVISITOR_H_ */
