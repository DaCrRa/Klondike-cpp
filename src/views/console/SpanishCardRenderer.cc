/*
 * SpanishCardRenderer.cc
 *
 *  Created on: 15 Nov 2016
 *      Author: dancre
 */

#include <SpanishCardRenderer.h>

#include <iostream>

SpanishCardRenderer::SpanishCardRenderer() :
    SPANISH_RANKS( {
    "As", "2", "3", "4", "5", "6", "7", "Sota", "Caballo", "Rey"
}),
SPANISH_SUITS({"OROS", "COPAS", "ESPADAS", "BASTOS"}) {}

void SpanishCardRenderer::renderCard(const Card* c) {
    std::cout << "{";
    c->acceptCardVisitor(*this);
    std::cout << "}";
}

void SpanishCardRenderer::visitRank(int rank) const {
    std::cout << SPANISH_RANKS[rank] << "|";
}

void SpanishCardRenderer::visitSuit(int suit) const {
    std::cout << SPANISH_SUITS[suit];
}
