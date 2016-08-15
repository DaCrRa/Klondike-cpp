/*
 * Klondike.cc
 *
 *  Created on: 3 Apr 2016
 *      Author: dancre
 */

#include <Klondike.h>

Klondike::Klondike() :
    tableau(7), //TODO magic number
    foundations(deck.getNumSuits(), Foundation(2)), //TODO 2 is a test value, should be deck.getNumCardsPerSuit()
    score(0),
    paused(true)
{
    moveOrigins.push_back(&stock);
    for (std::vector<Foundation>::iterator it = foundations.begin(); it != foundations.end(); ++it) {
        moveOrigins.push_back(it.base());
        moveDests.push_back(it.base());
    }
    for (std::vector<TableauPile>::iterator it = tableau.begin(); it != tableau.end(); ++it) {
        moveOrigins.push_back(it.base());
        moveDests.push_back(it.base());
    }
}

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
    paused = false;
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

std::vector<Foundation>& Klondike::getFoundations() {
    return foundations;
}

std::vector<TableauPile>& Klondike::getTableau() {
    return tableau;
}

std::vector<MoveOrigin*> Klondike::getPossibleMoveOrigins() {
    std::vector<MoveOrigin*> possibleMoveOrigins;
    for (std::vector<MoveOrigin*>::iterator it = moveOrigins.begin(); it != moveOrigins.end(); ++it) {
        if ((*it)->hasCardAvailable()) {
            possibleMoveOrigins.push_back(*it);
        }
    }
    return possibleMoveOrigins;
}

std::vector<MoveDest*> Klondike::getPossibleMoveDests(MoveOrigin* origin) {
    std::vector<MoveDest*> possibleMoveDests;
    for (std::vector<MoveDest*>::iterator it = moveDests.begin(); it != moveDests.end(); ++it) {
        if ((*it)->cardCanBeAdded(origin->showAvailableCard())) {
            possibleMoveDests.push_back(*it);
        }
    }
    return possibleMoveDests;
}

int Klondike::getScore() const {
    return score;
}

void Klondike::updateScore(int delta) {
    score += delta;
}

bool Klondike::isPaused() {
    return paused;
}

void Klondike::togglePause() {
    paused = !paused;
}


