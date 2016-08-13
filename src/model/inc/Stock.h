/*
 * Stock.h
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#ifndef STOCK_H_
#define STOCK_H_

#include <Pile.h>
#include <MoveOrigin.h>

class Stock : public MoveOrigin {
private:
    Pile covered;
    Pile waste;

    void rotate();

public:
    void addToCovered(const Card* c);
    void move();
    bool hasCardAvailable() const;
    bool hasCoveredCards() const;
    bool hasCards() const;
    void accept(MoveOriginVisitor* v);
    const Card* showAvailableCard() const;
    const Card* removeAvailableCard();
};

#endif
