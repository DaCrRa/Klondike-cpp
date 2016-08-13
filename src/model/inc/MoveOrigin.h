/*
 * MoveOrigin.h
 *
 *  Created on: 4 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_MOVEORIGIN_H_
#define SRC_MODEL_INC_MOVEORIGIN_H_

#include <Card.h>
#include <GameElement.h>
#include <MoveOriginVisitor.h>

class MoveOrigin : virtual public GameElement {
public:
    virtual bool hasCardAvailable() const = 0;
    virtual const Card* showAvailableCard() const = 0;
    virtual const Card* removeAvailableCard() = 0;
    virtual void accept(MoveOriginVisitor* v) = 0;
    virtual ~MoveOrigin() {}
};

#endif /* SRC_MODEL_INC_MOVEORIGIN_H_ */
