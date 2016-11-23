/*
 * FoundationProxy.cc
 *
 *  Created on: 23 Nov 2016
 *      Author: dancre
 */

#include <FoundationProxy.h>

FoundationProxy::FoundationProxy(const std::string& h, int id, char elementId) :
    MoveOriginProxy(h, id, elementId),
    MoveDestProxy(h, id, elementId),
    GameElementProxy(h, id, elementId) {
    topCard = std::shared_ptr<Card>(new Card(0, 0, 0, 0));
}

int FoundationProxy::getNumCardsAvailableToMove() const {
    MoveOriginProxy::getNumCardsAvailableToMove();
}

bool FoundationProxy::isCompleted() const {
    httpRequest("GET", std::vector<std::string>({"isCompleted"}));
    std::cout << "deserialize boolean" << std::endl;
    return false;
}

int FoundationProxy::getNumCards() const {
    httpRequest("GET", std::vector<std::string>({"numCards"}));
    std::cout << "deserialize integer" << std::endl;
    return 0;
}

const Card* FoundationProxy::top() const {
    httpRequest("GET", std::vector<std::string>({""}));
    std::cout << "deserialize pile and return top card" << std::endl;
    return topCard.get();
}

void FoundationProxy::accept(MoveOriginVisitor* v) {
    v->visit(this);
}

void FoundationProxy::accept(MoveDestVisitor* v) {
    v->visit(this);
}

void FoundationProxy::acceptFoundationVisitor(FoundationVisitor* v) {
    httpRequest("GET", std::vector<std::string>({""}));
    std::cout << "deserialize pile and iterate over it" << std::endl;
    v->visitCard(topCard.get());
    v->allCardsVisited();
}
