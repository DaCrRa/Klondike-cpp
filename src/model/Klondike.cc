/*
 * Klondike.cc
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#include <Klondike.h>

#include <assert.h>

Klondike::Klondike(DeckPtr d) :
    deck(d),
    tableau(NUM_TABLEAU_PILES, TableauPile(deck->getNumCardsPerSuit() - 1 )),
    score(0)
{}

void Klondike::initialize() {
    assert(foundations.empty());
    foundations = std::vector<Foundation>(deck->getNumSuits(), Foundation(deck->getNumCardsPerSuit()));
    int i = 0;
    for (std::vector<TableauPile>::iterator it = tableau.begin(); it != tableau.end(); ++it, ++i) {
        for (int j = 0; j < i + 1; j++) {
            it->addToCovered(deck->removeTop());
        }
        it->turnUpCard();
    }
    while (deck->hasCards()) {
        stock.addToCovered(deck->removeTop());
    }
}

void Klondike::initialize(KlondikeInitParameters& params) {
    score = params.getScore();
    for(int id : params.getStockCardsIds()) {
        stock.addToCovered(deck->removeCard(id));
    }
    for(int id : params.getWasteCardsIds()) {
        stock.recoverCard(deck->removeCard(id));
    }
    for(std::vector<int> foundationIds : params.getFoundationsCardsIds()) {
        foundations.push_back(Foundation(deck->getNumCardsPerSuit()));
        for(int id : foundationIds) {
            foundations.back().recoverCard(deck->removeCard(id));
        }
    }
    assert(params.getTableauInitParams().size() == NUM_TABLEAU_PILES);
    std::vector<TableauPile>::iterator it = tableau.begin();
    for(std::shared_ptr<TableauPileInitParameters> tableauPileParams : params.getTableauInitParams()) {
        for(int cardId : tableauPileParams->getCoveredCardsIds()) {
            it->addToCovered(deck->removeCard(cardId));
        }
        for(int cardId : tableauPileParams->getUncoveredCardsIds()) {
            it->recoverCard(deck->removeCard(cardId));
        }
        ++it;
    }
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
    visitor->visitDeckType(deck->getDeckType());
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
