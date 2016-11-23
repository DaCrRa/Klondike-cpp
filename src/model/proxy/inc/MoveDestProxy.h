/*
 * MoveDestProxy.h
 *
 *  Created on: 22 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_PROXY_INC_MOVEDESTPROXY_H_
#define SRC_MODEL_PROXY_INC_MOVEDESTPROXY_H_

#include <MoveDest.h>
#include <GameElementProxy.h>

class MoveDestProxy : virtual public MoveDest, virtual public GameElementProxy {
public:
    MoveDestProxy(const std::string& h, int id, char elementId) :
        GameElementProxy(h, id, elementId) {}
    bool cardCanBeAdded(const Card* cardToAdd) const;
    bool cardsCanBeAdded(const Pile& cards) const;
    void addCard(const Card* c);
    virtual void accept(MoveDestVisitor* visitor) = 0;
    virtual ~MoveDestProxy() {}
};

#endif /* SRC_MODEL_PROXY_INC_MOVEDESTPROXY_H_ */
