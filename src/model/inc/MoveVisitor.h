/*
 * MoveVisitor.h
 *
 *  Created on: 30 Oct 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_MOVEVISITOR_H_
#define SRC_MODEL_INC_MOVEVISITOR_H_

class MoveFromStock;
class MoveFromTableauPile;
class MoveFromFoundation;

class MoveVisitor {
public:
    virtual void visit(MoveFromStock* move) = 0;
    virtual void visit(MoveFromTableauPile* move) = 0;
    virtual void visit(MoveFromFoundation* move) = 0;
    virtual ~MoveVisitor() {}
};

#endif /* SRC_MODEL_INC_MOVEVISITOR_H_ */
