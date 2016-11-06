/*
 * KlondikeVisitor.h
 *
 *  Created on: 6 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_KLONDIKEVISITOR_H_
#define SRC_MODEL_INC_KLONDIKEVISITOR_H_

#include <Foundation.h>
#include <Stock.h>
#include <TableauPile.h>

class KlondikeVisitor {
public:
    virtual void visitScore(int score) {}
    virtual void visitStock(Stock* s) {}
    virtual void visitTableauPile(TableauPile* tp) {}
    virtual void allTableauPilesVisited() {};
    virtual void visitFoundation(Foundation* f) {}
    virtual void allFoundationsVisited() {};
    virtual ~KlondikeVisitor() {}
};

#endif /* SRC_MODEL_INC_KLONDIKEVISITOR_H_ */
