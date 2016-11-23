/*
 * MoveOriginProxy.h
 *
 *  Created on: 22 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_PROXY_INC_MOVEORIGINPROXY_H_
#define SRC_MODEL_PROXY_INC_MOVEORIGINPROXY_H_

#include <MoveOrigin.h>
#include <GameElementProxy.h>

#include <sstream>

class MoveOriginProxy : virtual public MoveOrigin, virtual public GameElementProxy {
public:
    MoveOriginProxy(const std::string& h, int id, char elementId) :
        GameElementProxy(h, id, elementId) {}

    void recoverCard(const Card* c) {
        httpRequest("PATCH", std::vector<std::string>());
        std::cout << "Card c is serialized in request body" << std::endl;
    }
    int getNumCardsAvailableToMove() const {
        httpRequest("GET", std::vector<std::string>({"numCardsAvailableToMove"}));
        return 1;
    }
    const Pile showAvailableCards(int n) const {
        std::stringstream paramStream;
        paramStream << n;
        httpRequest("GET", std::vector<std::string>({paramStream.str()}));
        return Pile();
    }
    Pile removeCards(int n) {
        return Pile();
    }
    virtual void accept(MoveOriginVisitor* v) = 0;
    virtual ~MoveOriginProxy() {}
};

#endif /* SRC_MODEL_PROXY_INC_MOVEORIGINPROXY_H_ */
