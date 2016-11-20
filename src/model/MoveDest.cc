/*
 * MoveDest.cc
 *
 *  Created on: 20 Nov 2016
 *      Author: dancre
 */

#include <MoveDest.h>

#include <assert.h>

bool MoveDest::cardCanBeAdded(const Card* cardToAdd) const {
    if (! faceUpCards.hasCards()) {
        return cardMeetsFirstCardCondition(cardToAdd);
    } else {
        return addCardCondition(faceUpCards.showTopCard(), cardToAdd);
    }
}

bool MoveDest::cardsCanBeAdded(const Pile& cards) const {
    if (!cards.hasCards()) {
        return false;
    }

    return cardCanBeAdded(*(cards.begin())) &&
    cards.isOrdered([&](const Card* card1, const Card* card2) -> bool {
        return addCardCondition(card1, card2);
    });
}

void MoveDest::addCard(const Card* c) {
    assert(cardCanBeAdded(c));
    faceUpCards.add(c);
}
