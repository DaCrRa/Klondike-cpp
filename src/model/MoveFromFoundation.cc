/*
 * MoveFromFoundation.cc
 *
 *  Created on: 30 Oct 2016
 *      Author: dancre
 */

#include <MoveFromFoundation.h>

MoveOrigin* MoveFromFoundation::getMoveOrigin() {
    return origin;
}

ForwardGameActionPtr MoveFromFoundation::duplicate() {
    ForwardGameActionPtr(new MoveFromFoundation(*this));
}

void MoveFromFoundation::acceptMoveVisitor(MoveVisitor* visitor) {
    visitor->visit(this);
}
