/*
 * StockProxy.cc
 *
 *  Created on: 22 Nov 2016
 *      Author: dancre
 */

#include <StockProxy.h>

int StockProxy::moveForward() {
    httpRequest("POST", std::vector<std::string>({"moveFwd"}));
    std::cout << "Deserialize integer" << std::endl;
    return 1;
}

int StockProxy::getNumCardsAvailableToMove() const {
    MoveOriginProxy::getNumCardsAvailableToMove();
}

void StockProxy::moveBackward(int numCards) {
    std::stringstream paramStream;
    paramStream << numCards;
    httpRequest("POST", std::vector<std::string>({"moveBack", paramStream.str()}));
}

bool StockProxy::hasCoveredCards() const {
    httpRequest("GET", std::vector<std::string>({"hasCoveredCards"}));
    std::cout << "Deserialize boolean" << std::endl;
    return true;
}

bool StockProxy::hasCards() const {
    httpRequest("GET", std::vector<std::string>({"hasCards"}));
    std::cout << "Deserialize boolean" << std::endl;
    return true;
}

void StockProxy::accept(MoveOriginVisitor* v) {
    v->visit(this);
}

void StockProxy::acceptStockVisitor(StockVisitor* visitor) {
    // TODO
}
