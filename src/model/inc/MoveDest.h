/*
 * MoveDest.h
 *
 *  Created on: 4 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_MOVEDEST_H_
#define SRC_MODEL_INC_MOVEDEST_H_

#include <Card.h>
#include <GameElement.h>

class MoveDest : virtual public GameElement {
public:
    virtual bool cardCanBeAdded(const Card* c) = 0;
    virtual void add(const Card* c) = 0;
    virtual ~MoveDest() {}
};

#endif /* SRC_MODEL_INC_MOVEDEST_H_ */
