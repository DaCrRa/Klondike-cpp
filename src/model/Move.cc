/*
 * Move.cpp
 *
 *  Created on: 4 de may. de 2016
 *      Author: dancre
 */

#include <Move.h>

#include <assert.h>

void Move::setOrigin(MoveOrigin* o) {
    origin = o;
}

void Move::setDest(MoveDest* d) {
    dest = d;
}

void Move::doMove() {
    assert(dest->cardCanBeAdded(origin->showAvailableCard()));
    dest->add(origin->removeAvailableCard());
}

void Move::accept(GameActionVisitor* visitor) {
    visitor->visit(this);
}

GameActionPtr Move::duplicate() {
    return GameActionPtr(new Move(*this));
}

void Move::acceptOriginVisitor(MoveOriginVisitor* origVisitor) {
    origin->accept(origVisitor);
}

void Move::acceptDestVisitor(MoveDestVisitor* destVisitor) {
    dest->accept(destVisitor);
}
