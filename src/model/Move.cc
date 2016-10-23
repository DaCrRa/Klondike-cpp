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

void Move::forwardAction() {
    dest->add(origin->removeAvailableCard());
}

bool Move::canBeDone() {
    return dest->cardCanBeAdded(origin->showAvailableCard());
}

void Move::undoAction() {

}

void Move::accept(ForwardGameActionVisitor* visitor) {
    visitor->visit(this);
}

ForwardGameActionPtr Move::duplicate() {
    return ForwardGameActionPtr(new Move(*this));
}

void Move::acceptOriginVisitor(MoveOriginVisitor* origVisitor) {
    origin->accept(origVisitor);
}

void Move::acceptDestVisitor(MoveDestVisitor* destVisitor) {
    dest->accept(destVisitor);
}
