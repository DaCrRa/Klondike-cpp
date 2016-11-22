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

class MoveOrigin : virtual public GameElement {
public:
    virtual void recoverCard(const Card* c) = 0;
    virtual int getNumCardsAvailableToMove() const = 0;
    virtual const Pile showAvailableCards(int n) const = 0;
    virtual Pile removeCards(int n) = 0;
    virtual void accept(MoveOriginVisitor* v) = 0;
    virtual ~MoveOrigin() {}
};

#endif /* SRC_MODEL_INC_MOVEORIGIN_H_ */
