/*
 * FoundationImpl.h
 *
 *  Created on: 21 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_IMPLEMENTATION_INC_FOUNDATIONIMPL_H_
#define SRC_MODEL_IMPLEMENTATION_INC_FOUNDATIONIMPL_H_

#include <Foundation.h>
#include <MoveDestImpl.h>
#include <MoveOriginImpl.h>

class FoundationImpl : public Foundation,
    public MoveOriginImpl,
    public MoveDestImpl {

private:
    const int NUM_CARDS_TO_COMPLETE;
public:

    FoundationImpl(const int n) : NUM_CARDS_TO_COMPLETE(n) {}
    bool isCompleted() const;
    int getNumCards() const;
    const Card* top() const;
    bool cardMeetsFirstCardCondition(const Card* card) const;
    bool addCardCondition(const Card* referenceCard, const Card* cardToAdd) const;
    int getNumCardsAvailableToMove() const ;
    void accept(MoveOriginVisitor* v);
    void accept(MoveDestVisitor* v);
    void acceptFoundationVisitor(FoundationVisitor* v);
};

#endif /* SRC_MODEL_IMPLEMENTATION_INC_FOUNDATIONIMPL_H_ */
