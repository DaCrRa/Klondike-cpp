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

#include <memory>

class Foundation;
typedef std::shared_ptr<Foundation> FoundationPtr;

class Foundation : virtual public MoveDest, virtual public MoveOrigin {
public:
    static const int MAX_CARDS_ALLOWED_TO_MOVE_FROM_FOUNDATION;

    Foundation() {}
    virtual int getNumCardsAvailableToMove() const = 0;
    virtual bool cardMeetsFirstCardCondition(const Card* card) const = 0;
    virtual bool addCardCondition(const Card* referenceCard, const Card* cardToAdd) const = 0;
    virtual bool isCompleted() const = 0;
    virtual int getNumCards() const = 0;
    virtual const Card* top() const = 0;
    virtual void accept(MoveOriginVisitor* v) = 0;
    virtual void accept(MoveDestVisitor* v) = 0;
    virtual void acceptFoundationVisitor(FoundationVisitor* v) = 0;
    virtual ~Foundation() {}
};

#endif
