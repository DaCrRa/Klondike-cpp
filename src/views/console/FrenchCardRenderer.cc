/*
 * FrenchCardRenderer.cc
 *
 *  Created on: 15 Nov 2016
 *      Author: dancre
 */

#include <FrenchCardRenderer.h>

#include <iostream>

FrenchCardRenderer::FrenchCardRenderer() :
    FRENCH_RANKS( {
    "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"
}),
FRENCH_SUITS({"HEARTS-R", "CLUBS-B", "DIAMONDS-R", "PIKES-B"}) {}

void FrenchCardRenderer::renderCard(const Card* c) {
    std::cout << "{";
    c->acceptCardVisitor(*this);
    std::cout << "}";
}

void FrenchCardRenderer::visitRank(int rank) const {
    std::cout << FRENCH_RANKS[rank] << "|";
}

void FrenchCardRenderer::visitSuit(int suit) const {
    std::cout << FRENCH_SUITS[suit];
}
