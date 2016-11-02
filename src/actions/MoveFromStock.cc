/*
 * MoveFromStock.cc
 *
 *  Created on: 30 Oct 2016
 *      Author: dancre
 */

#include <MoveFromStock.h>

MoveOrigin* MoveFromStock::getMoveOrigin() {
    return origin;
}

ForwardGameActionPtr MoveFromStock::duplicate() {
    ForwardGameActionPtr(new MoveFromStock(*this));
}

void MoveFromStock::acceptMoveVisitor(MoveVisitor* visitor) {
    visitor->visit(this);
}
