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
    renderStock();
    std::cout << std::endl;
    renderFoundations();
    std::cout << std::endl;
    renderTableau();
    std::cout << std::endl;
}

void KlondikeConsoleRenderer::renderStock() {
    assert(game != nullptr);
    const Stock* stock = game->getStock();
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
}

void KlondikeConsoleRenderer::renderFoundations() {
    assert(game != nullptr);
    std::vector<Foundation>& foundations = game->getFoundations();
    char foundationId = 'A';
    for (std::vector<Foundation>::const_iterator it = foundations.begin(); it != foundations.end(); ++it) {
        std::cout << "Foundation " << foundationId++ << ": ";
        renderFoundation(it.base());
    }
}

void KlondikeConsoleRenderer::renderFoundation(const Foundation* f) {
    assert(f != nullptr);
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

void KlondikeConsoleRenderer::renderTableau() {
    assert(game != nullptr);
    std::vector<TableauPile>& tableau = game->getTableau();
    int tableauPileId = 1;
    for (std::vector<TableauPile>::const_iterator it = tableau.begin(); it != tableau.end(); ++it) {
        std::cout << "Tableau Pile " << tableauPileId++ << ": ";
        renderTableauPile(it.base());
    }
}

void KlondikeConsoleRenderer::renderTableauPile(const TableauPile* tp) {
    assert(tp != nullptr);
    for (int i = 0; i < tp->getNumCoveredCards(); ++i) {
        std::cout << "[";
    }
    for (PileIterator it = tp->uncoveredCardsBegin(); it != tp->uncoveredCardsEnd(); ++it) {
        cardRenderer.renderCard(*it);
    }
    std::cout << std::endl;
}
