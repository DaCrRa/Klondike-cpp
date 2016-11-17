/*
 * Klondike.cc
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#include <Klondike.h>

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
