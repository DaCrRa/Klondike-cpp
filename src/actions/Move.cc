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

int Move::getNumberOfCards() {
    return numberOfCards;
}

void Move::forwardAction() {
    Pile cardsToMove(getMoveOrigin()->removeCards(numberOfCards));
    dest->addCards(cardsToMove);
}

bool Move::canBeDone() {
    return dest->cardsCanBeAdded(getMoveOrigin()->showAvailableCards(numberOfCards));
}

void Move::undoImpl() {
    Pile cardsToMove(dest->removeCards(numberOfCards));
    for (const Card* c : cardsToMove) {
        getMoveOrigin()->recoverCard(c);
    }
}

void Move::accept(ForwardGameActionVisitor* visitor) {
    visitor->visit(this);
}


void Move::acceptDestVisitor(MoveDestVisitor* destVisitor) {
    dest->accept(destVisitor);
}
