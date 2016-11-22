/*
 * MoveDestImpl.h
 *
 *  Created on: 21 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_IMPLEMENTATION_INC_MOVEDESTIMPL_H_
#define SRC_MODEL_IMPLEMENTATION_INC_MOVEDESTIMPL_H_

#include <GameElementImpl.h>
#include <MoveDest.h>

class MoveDestImpl : virtual public MoveDest, virtual public GameElementImpl {
public:
    virtual bool cardMeetsFirstCardCondition(const Card* card) const = 0;
    virtual bool addCardCondition(const Card* referenceCard, const Card* cardToAdd) const = 0;
    bool cardCanBeAdded(const Card* cardToAdd) const;
    bool cardsCanBeAdded(const Pile& cards) const;
    void addCard(const Card* c);
    virtual void accept(MoveDestVisitor* visitor) = 0;
    virtual ~MoveDestImpl() {}
};

#endif /* SRC_MODEL_IMPLEMENTATION_INC_MOVEDESTIMPL_H_ */
