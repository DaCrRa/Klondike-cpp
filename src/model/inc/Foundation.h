/*
 * Foundation.h
 *
 *  Created on: 2 Apr 2016
 *      Author: dancre
 */

#ifndef FOUNDATION_H
#define FOUNDATION_H

#include <Pile.h>
#include <MoveDest.h>
#include <MoveOrigin.h>

class Foundation : public MoveDest, public MoveOrigin {
private:
    Pile pile;
    const int NUM_CARDS_TO_COMPLETE;
public:
    Foundation(const int n) : NUM_CARDS_TO_COMPLETE(n) {}
    void add(const Card* c);
    bool cardCanBeAdded(const Card* c);
    bool hasCardAvailable() const;
    const Card* showAvailableCard() const;
    const Card* removeAvailableCard();
    bool isCompleted() const;
    int getNumCards() const;
    const Card* top() const;
    void accept(MoveOriginVisitor* v);
    void accept(MoveDestVisitor* v);
};

#endif
