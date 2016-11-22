/*
 * Klondike.cc
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#include <Klondike.h>

Stock* Klondike::getStock() {
    return stock.get();
}

void Klondike::accept(KlondikeVisitor* visitor) {
    visitor->visitDeckType(deck->getDeckType());
    visitor->visitScore(score);
    visitor->visitStock(stock.get());
    for(FoundationPtr foundation : foundations) {
        visitor->visitFoundation(foundation.get());
    }
    visitor->allFoundationsVisited();
    for(TableauPilePtr tableauPile : tableau) {
        visitor->visitTableauPile(tableauPile.get());
    }
    visitor->allTableauPilesVisited();
}
