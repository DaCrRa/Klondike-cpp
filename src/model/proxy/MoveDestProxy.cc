/*
 * MoveDestProxy.cc
 *
 *  Created on: 22 Nov 2016
 *      Author: dancre
 */

#include <MoveDestProxy.h>

bool MoveDestProxy::cardCanBeAdded(const Card* cardToAdd) const {
    httpRequest("GET", std::vector<std::string>({"canBeAdded"}));
    std::cout << "card serialized in request body" << std::endl;
    std::cout << "deserialize boolean" << std::endl;
    return true;
}

bool MoveDestProxy::cardsCanBeAdded(const Pile& cards) const {
    httpRequest("GET", std::vector<std::string>({"canBeAdded"}));
    std::cout << "pile serialized in request body" << std::endl;
    std::cout << "deserialize boolean" << std::endl;
    return true;
}

void MoveDestProxy::addCard(const Card* c) {
    httpRequest("POST", std::vector<std::string>({""}));
    std::cout << "card serialized in request body" << std::endl;
}
