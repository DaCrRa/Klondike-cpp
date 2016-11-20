/*
 * MoveOrigin.h
 *
 *  Created on: 4 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_MOVEORIGIN_H_
#define SRC_MODEL_INC_MOVEORIGIN_H_

#include <Pile.h>
#include <GameElement.h>
#include <MoveOriginVisitor.h>

#include <assert.h>

class MoveOrigin : virtual public GameElement {
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
        return GameElement::removeCards(n);
    }
    virtual void accept(MoveOriginVisitor* v) = 0;
    virtual ~MoveOrigin() {}
};

#endif /* SRC_MODEL_INC_MOVEORIGIN_H_ */
