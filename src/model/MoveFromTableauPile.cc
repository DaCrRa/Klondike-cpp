/*
 * MoveFromTableauPile.cc
 *
 *  Created on: 30 Oct 2016
 *      Author: dancre
 */

#include <MoveFromTableauPile.h>

MoveOrigin* MoveFromTableauPile::getMoveOrigin() {
    return origin;
}

ForwardGameActionPtr MoveFromTableauPile::duplicate() {
    ForwardGameActionPtr(new MoveFromTableauPile(*this));
}

void MoveFromTableauPile::acceptMoveVisitor(MoveVisitor* visitor) {
    visitor->visit(this);
}

void MoveFromTableauPile::forwardAction() {
    Move::forwardAction();
    if (origin->cardCanBeTurnUp()) {
        origin->turnUpCard();
        cardTurnedUp = true;
    }
}

void MoveFromTableauPile::undoAction() {
    if (cardTurnedUp) {
        origin->turnDownCard();
    }
    Move::undoAction();
}

bool MoveFromTableauPile::cardWasTurnUp() {
    return cardTurnedUp;
}
