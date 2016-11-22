/*
 * KlondikeImpl.cc
 *
 *  Created on: 17 Nov 2016
 *      Author: dancre
 */

#include <KlondikeImpl.h>
#include <FoundationImpl.h>

#include <assert.h>

KlondikeImpl::KlondikeImpl(DeckPtr d) {
    deck = d;
    deckType = deck->getDeckType();
    stockImpl = std::shared_ptr<StockImpl> (new StockImpl());
    for (int i = 0; i < NUM_TABLEAU_PILES; i++) {
        tableauImpl.push_back(std::shared_ptr<TableauPileImpl>(new TableauPileImpl(deck->getNumCardsPerSuit() - 1 )));
    }
    stock = stockImpl;
    tableau.insert(tableau.end(), tableauImpl.begin(), tableauImpl.end());
    score = 0;
}

void KlondikeImpl::initialize() {
    assert(foundations.empty());
    for (int i = 0; i < deck->getNumSuits(); i++) {
        foundations.push_back(FoundationPtr(new FoundationImpl(deck->getNumCardsPerSuit())));
    }
    int i = 0;
    for (std::shared_ptr<TableauPileImpl> tableauPile : tableauImpl) {
        for (int j = 0; j < i + 1; j++) {
            tableauPile->addToCovered(deck->removeRandomCard());
        }
        tableauPile->turnUpCard();
        i++;
    }
    while (deck->hasCards()) {
        stockImpl->addToCovered(deck->removeRandomCard());
    }
}

void KlondikeImpl::initialize(KlondikeInitParameters& params) {
    score = params.getScore();
    for(int id : params.getStockCardsIds()) {
        stockImpl->addToCovered(deck->removeCard(id));
    }
    for(int id : params.getWasteCardsIds()) {
        stockImpl->recoverCard(deck->removeCard(id));
    }
    for(std::vector<int> foundationIds : params.getFoundationsCardsIds()) {
        foundations.push_back(FoundationPtr(new FoundationImpl(deck->getNumCardsPerSuit())));
        for(int id : foundationIds) {
            foundations.back()->recoverCard(deck->removeCard(id));
        }
    }
    assert(params.getTableauInitParams().size() == NUM_TABLEAU_PILES);
    std::vector<std::shared_ptr<TableauPileImpl> >::iterator it = tableauImpl.begin();
    for(std::shared_ptr<TableauPileInitParameters> tableauPileParams : params.getTableauInitParams()) {
        for(int cardId : tableauPileParams->getCoveredCardsIds()) {
            (*it)->addToCovered(deck->removeCard(cardId));
        }
        for(int cardId : tableauPileParams->getUncoveredCardsIds()) {
            (*it)->recoverCard(deck->removeCard(cardId));
        }
        ++it;
    }
}

bool KlondikeImpl::isCompleted() {
    bool completed = true;
    for (FoundationPtr foundation : foundations) {
        completed &= foundation->isCompleted();
    }
    return completed;
}

int KlondikeImpl::getScore() const {
    return score;
}

void KlondikeImpl::updateScore(int delta) {
    score += delta;
}
