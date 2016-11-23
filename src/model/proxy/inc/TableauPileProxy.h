/*
 * TableauPileProxy.h
 *
 *  Created on: 23 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_PROXY_INC_TABLEAUPILEPROXY_H_
#define SRC_MODEL_PROXY_INC_TABLEAUPILEPROXY_H_

#include <TableauPile.h>
#include <MoveOriginProxy.h>
#include <MoveDestProxy.h>

class TableauPileProxy: public TableauPile,
    public MoveOriginProxy,
    public MoveDestProxy {
private:
    Pile cards;
public:
    TableauPileProxy(const std::string& h, int id, char elementId) :
        MoveOriginProxy(h, id, elementId),
        MoveDestProxy(h, id, elementId),
        GameElementProxy(h, id, elementId) {}
    bool cardCanBeTurnUp();
    void turnUpCard();
    void turnDownCard();
    int getNumCoveredCards() const;
    int getNumCardsAvailableToMove() const;
    PileIterator uncoveredCardsBegin() const;
    PileIterator uncoveredCardsEnd() const;
    void accept(MoveOriginVisitor* v);
    void accept(MoveDestVisitor* v);
    void acceptTableauPileVisitor(TableauPileVisitor* visitor);
};

#endif /* SRC_MODEL_PROXY_INC_TABLEAUPILEPROXY_H_ */
