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
public:
    void add(const Card* c);
    bool accept(const Card* c);
    bool hasCardAvailable() const;
    const Card* showAvailableCard() const;
    const Card* removeAvailableCard();
    bool isCompleted() const;
    int getNumCards() const;
    const Card* top() const;
    void accept(MoveOriginVisitor* v);
};

#endif
