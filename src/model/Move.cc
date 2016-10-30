/*
 * Move.cpp
 *
 *  Created on: 4 de may. de 2016
 *      Author: dancre
 */

#include <Move.h>

#include <assert.h>

void Move::setDest(MoveDest* d) {
    dest = d;
}

void Move::forwardAction() {
    dest->add(getMoveOrigin()->removeAvailableCard());
}

bool Move::canBeDone() {
    return dest->cardCanBeAdded(getMoveOrigin()->showAvailableCard());
}

void Move::undoAction() {
    getMoveOrigin()->recoverCard(dest->removeAvailableCard());
}

void Move::accept(ForwardGameActionVisitor* visitor) {
    visitor->visit(this);
}


void Move::acceptDestVisitor(MoveDestVisitor* destVisitor) {
    dest->accept(destVisitor);
}
