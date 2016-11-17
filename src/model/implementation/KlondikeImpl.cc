/*
 * KlondikeImpl.cc
 *
 *  Created on: 17 Nov 2016
 *      Author: dancre
 */

#include <KlondikeImpl.h>

#include <assert.h>

KlondikeImpl::KlondikeImpl(DeckPtr d) {
    deck = d;
    tableau = std::vector<TableauPile>(NUM_TABLEAU_PILES, TableauPile(deck->getNumCardsPerSuit() - 1 )),
    score = 0;
}

void KlondikeImpl::initialize() {
    assert(foundations.empty());
    foundations = std::vector<Foundation>(deck->getNumSuits(), Foundation(deck->getNumCardsPerSuit()));
    int i = 0;
    for (std::vector<TableauPile>::iterator it = tableau.begin(); it != tableau.end(); ++it, ++i) {
        for (int j = 0; j < i + 1; j++) {
            it->addToCovered(deck->removeRandomCard());
        }
        it->turnUpCard();
    }
    while (deck->hasCards()) {
        stock.addToCovered(deck->removeRandomCard());
    }
}

void KlondikeImpl::initialize(KlondikeInitParameters& params) {
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

bool KlondikeImpl::isCompleted() {
    bool completed = true;
    for (std::vector<Foundation>::iterator it = foundations.begin(); it != foundations.end() && completed; ++it) {
        completed &= it->isCompleted();
    }
    return completed;
}

Stock* KlondikeImpl::getStock() {
    return &stock;
}

int KlondikeImpl::getScore() const {
    return score;
}

void KlondikeImpl::updateScore(int delta) {
    score += delta;
}
