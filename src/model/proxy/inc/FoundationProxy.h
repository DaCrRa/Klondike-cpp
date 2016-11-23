/*
 * FoundationProxy.h
 *
 *  Created on: 23 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_PROXY_INC_FOUNDATIONPROXY_H_
#define SRC_MODEL_PROXY_INC_FOUNDATIONPROXY_H_

#include <Foundation.h>
#include <MoveOriginProxy.h>
#include <MoveDestProxy.h>

class FoundationProxy : public Foundation,
    public MoveOriginProxy,
    public MoveDestProxy {
private:
    std::shared_ptr<Card> topCard;
public:
    FoundationProxy(const std::string& h, int id, char elementId);
    int getNumCardsAvailableToMove() const;
    bool isCompleted() const;
    int getNumCards() const;
    const Card* top() const;
    void accept(MoveOriginVisitor* v);
    void accept(MoveDestVisitor* v);
    void acceptFoundationVisitor(FoundationVisitor* v);
};

#endif /* SRC_MODEL_PROXY_INC_FOUNDATIONPROXY_H_ */
