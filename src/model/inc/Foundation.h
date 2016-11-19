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
#include <FoundationVisitor.h>

class Foundation : public MoveDest, public MoveOrigin {
private:
    static const int MAX_CARDS_ALLOWED_TO_MOVE_FROM_FOUNDATION;
    Pile pile;
    const int NUM_CARDS_TO_COMPLETE;
public:
    Foundation(const int n) : NUM_CARDS_TO_COMPLETE(n) {}
    void addCards(Pile& cards);
    void recoverCard(const Card* c);
    bool cardsCanBeAdded(const Pile& cards) const;
    int getNumCardsAvailableToMove() const;
    const Card* showAvailableCard() const;
    const Card* removeAvailableCard();
    bool isCompleted() const;
    int getNumCards() const;
    const Card* top() const;
    void accept(MoveOriginVisitor* v);
    void accept(MoveDestVisitor* v);
    void acceptFoundationVisitor(FoundationVisitor* v);
};

#endif
