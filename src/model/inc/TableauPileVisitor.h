/*
 * TableauPileVisitor.h
 *
 *  Created on: 6 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_TABLEAUPILEVISITOR_H_
#define SRC_MODEL_INC_TABLEAUPILEVISITOR_H_

#include <Card.h>

class TableauPileVisitor {
public:
    virtual void visitCoveredCard(const Card* c) = 0;
    virtual void visitUncoveredCard(const Card* c) = 0;
    virtual void allCoveredCardsVisited() = 0;
    virtual void allUncoveredCardsVisited() = 0;
    virtual ~TableauPileVisitor() {}
};

#endif /* SRC_MODEL_INC_TABLEAUPILEVISITOR_H_ */
