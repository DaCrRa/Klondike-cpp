/*
 * MoveDest.h
 *
 *  Created on: 4 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_MOVEDEST_H_
#define SRC_MODEL_INC_MOVEDEST_H_

#include <Pile.h>
#include <GameElement.h>
#include <MoveDestVisitor.h>

class MoveDest : virtual public GameElement {
public:
    virtual bool cardsCanBeAdded(const Pile& c) = 0;
    virtual void addCards(Pile& c) = 0;
    virtual void accept(MoveDestVisitor* visitor) = 0;
    virtual ~MoveDest() {}
};

#endif /* SRC_MODEL_INC_MOVEDEST_H_ */
