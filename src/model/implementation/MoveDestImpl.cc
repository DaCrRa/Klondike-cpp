/*
 * MoveDestImpl.cc
 *
 *  Created on: 21 Nov 2016
 *      Author: dancre
 */

#include <MoveDestImpl.h>

#include <assert.h>

bool MoveDestImpl::cardCanBeAdded(const Card* cardToAdd) const {
    if (! faceUpCards.hasCards()) {
        return cardMeetsFirstCardCondition(cardToAdd);
    } else {
        return addCardCondition(faceUpCards.showTopCard(), cardToAdd);
    }
}

bool MoveDestImpl::cardsCanBeAdded(const Pile& cards) const {
    if (!cards.hasCards()) {
        return false;
    }

    return cardCanBeAdded(*(cards.begin())) &&
    cards.isOrdered([&](const Card* card1, const Card* card2) -> bool {
        return addCardCondition(card1, card2);
    });
}

void MoveDestImpl::addCard(const Card* c) {
    assert(cardCanBeAdded(c));
    faceUpCards.add(c);
}
