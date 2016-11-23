/*
 * TableauPileProxy.cc
 *
 *  Created on: 23 Nov 2016
 *      Author: dancre
 */

#include <TableauPileProxy.h>

bool TableauPileProxy::cardCanBeTurnUp() {
    httpRequest("GET", std::vector<std::string>({"turnUp"}));
    std::cout << "deserialize boolean" << std::endl;
    return false;
}

void TableauPileProxy::turnUpCard() {
    httpRequest("POST", std::vector<std::string>({"turnUp"}));
}

void TableauPileProxy::turnDownCard() {
    httpRequest("POST", std::vector<std::string>({"turnDown"}));
}

int TableauPileProxy::getNumCoveredCards() const {
    httpRequest("POST", std::vector<std::string>({"numCovered"}));
    std::cout << "deserialize integer" << std::endl;
    return 1;
}

int TableauPileProxy::getNumCardsAvailableToMove() const {
    return MoveOriginProxy::getNumCardsAvailableToMove();
}

PileIterator TableauPileProxy::uncoveredCardsBegin() const {
    httpRequest("GET", std::vector<std::string>({""}));
    std::cout << "deserialize pile, assign it to cards" << std::endl;
    return cards.begin();
}

PileIterator TableauPileProxy::uncoveredCardsEnd() const {
    return cards.end();
}

void TableauPileProxy::accept(MoveOriginVisitor* v) {
    v->visit(this);
}

void TableauPileProxy::accept(MoveDestVisitor* v) {
    v->visit(this);
}

void TableauPileProxy::acceptTableauPileVisitor(TableauPileVisitor* visitor) {
    httpRequest("GET", std::vector<std::string>({"covered"}));
    std::cout << "deserialize pile, and iterate" << std::endl;
    visitor->allCoveredCardsVisited();
    httpRequest("GET", std::vector<std::string>({""}));
    std::cout << "deserialize pile, and iterate" << std::endl;
    visitor->allUncoveredCardsVisited();
}
