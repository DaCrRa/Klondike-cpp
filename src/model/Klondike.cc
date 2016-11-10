/*
 * Klondike.cc
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#include <Klondike.h>

Klondike::Klondike() :
    tableau(NUM_TABLEAU_PILES, TableauPile(deck.getNumCardsPerSuit())),
    foundations(/*deck.getNumSuits()*/ 4, Foundation(deck.getNumCardsPerSuit())),
    score(0)
{}

void Klondike::initialize() {
    int i = 0;
    for (std::vector<TableauPile>::iterator it = tableau.begin(); it != tableau.end(); ++it, ++i) {
        for (int j = 0; j < i + 1; j++) {
            it->addToCovered(deck.removeTop());
        }
        it->turnUpCard();
    }
    while (deck.hasCards()) {
        stock.addToCovered(deck.removeTop());
    }
}

void Klondike::initialize(KlondikeInitParameters& params) {
}

bool Klondike::isCompleted() {
    bool completed = true;
    for (std::vector<Foundation>::iterator it = foundations.begin(); it != foundations.end() && completed; ++it) {
        completed &= it->isCompleted();
    }
    return completed;
}

Stock* Klondike::getStock() {
    return &stock;
}

int Klondike::getScore() const {
    return score;
}

void Klondike::updateScore(int delta) {
    score += delta;
}

void Klondike::accept(KlondikeVisitor* visitor) {
    visitor->visitScore(score);
    visitor->visitStock(&stock);
    for(Foundation& foundation : foundations) {
        visitor->visitFoundation(&foundation);
    }
    visitor->allFoundationsVisited();
    for(TableauPile& tableauPile : tableau) {
        visitor->visitTableauPile(&tableauPile);
    }
    visitor->allTableauPilesVisited();
}
