/*
 * MoveOriginImpl.h
 *
 *  Created on: 21 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_IMPLEMENTATION_INC_MOVEORIGINIMPL_H_
#define SRC_MODEL_IMPLEMENTATION_INC_MOVEORIGINIMPL_H_

#include <MoveOrigin.h>
#include <GameElementImpl.h>

#include <assert.h>

class MoveOriginImpl : virtual public MoveOrigin, virtual public GameElementImpl {
public:
    void recoverCard(const Card* c) {
        faceUpCards.add(c);
    }
    virtual int getNumCardsAvailableToMove() const = 0;
    const Pile showAvailableCards(int n) const {
        assert(n <= getNumCardsAvailableToMove());
        return faceUpCards.showLastCards(n);
    }
    Pile removeCards(int n) {
        assert(n <= getNumCardsAvailableToMove());
        return GameElementImpl::removeCards(n);
    }
    virtual void accept(MoveOriginVisitor* v) = 0;
    virtual ~MoveOriginImpl() {}

};

#endif /* SRC_MODEL_IMPLEMENTATION_INC_MOVEORIGINIMPL_H_ */
