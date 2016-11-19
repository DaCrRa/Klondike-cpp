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
    Pile cardsToMove;
    cardsToMove.add(getMoveOrigin()->removeAvailableCard());
    dest->addCards(cardsToMove);
}

bool Move::canBeDone() {
    Pile cardsToMove;
    cardsToMove.add(getMoveOrigin()->showAvailableCard());
    return dest->cardsCanBeAdded(cardsToMove);
}

void Move::undoImpl() {
    getMoveOrigin()->recoverCard(dest->removeAvailableCard());
}

void Move::accept(ForwardGameActionVisitor* visitor) {
    visitor->visit(this);
}


void Move::acceptDestVisitor(MoveDestVisitor* destVisitor) {
    dest->accept(destVisitor);
}
