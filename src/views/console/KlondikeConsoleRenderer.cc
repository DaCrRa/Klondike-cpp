/*
 * KlondikeConsoleRenderer.cpp
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#include <KlondikeConsoleRenderer.h>

#include <iostream>
#include <iterator>
#include <assert.h>

void KlondikeConsoleRenderer::render() {
    std::cout << std::endl;
    game->accept(this);
}

void KlondikeConsoleRenderer::visitScore(int score) {
    std::cout << "Score: " << score << std::endl;
    std::cout << std::endl;
}

void KlondikeConsoleRenderer::visitStock(Stock* stock) {
    assert(stock != nullptr);
    std::cout << "Stock: ";
    if (stock->hasCoveredCards()) {
        std::cout << "[~]";
    } else {
        std::cout << "[_]";
    }
    if (stock->hasCardAvailable()) {
        std::cout << " --> ";
        cardRenderer.renderCard(stock->showAvailableCard());
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void KlondikeConsoleRenderer::visitFoundation(Foundation* f) {
    assert(f != nullptr);
    std::cout << "Foundation " << foundationTag++ << ": ";
    if (f->getNumCards() == 0) {
        std::cout << "[_]";
    }
    if (f->getNumCards() > 1) {
        std::cout << "...";
    }
    if (f->getNumCards() > 0) {
        cardRenderer.renderCard(f->top());
    }
    if (f->isCompleted()) {
        std::cout << "  COMPLETED!";
    }
    std::cout << std::endl;
}

void KlondikeConsoleRenderer::visitTableauPile(TableauPile* tp) {
    assert(tp != nullptr);

    std::cout << "Tableau Pile " << tableauPileTag++ << ": ";

    for (int i = 0; i < tp->getNumCoveredCards(); ++i) {
        std::cout << "[";
    }
    for (PileIterator it = tp->uncoveredCardsBegin(); it != tp->uncoveredCardsEnd(); ++it) {
        cardRenderer.renderCard(*it);
    }
    std::cout << std::endl;
}

void KlondikeConsoleRenderer::allFoundationsVisited() {
    std::cout << std::endl;
}

void KlondikeConsoleRenderer::allTableauPilesVisited() {
    std::cout << std::endl;
}
