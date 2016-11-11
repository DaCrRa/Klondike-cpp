/*
 * FoundationVisitor.h
 *
 *  Created on: 11 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_FOUNDATIONVISITOR_H_
#define SRC_MODEL_INC_FOUNDATIONVISITOR_H_

class FoundationVisitor {
public:
    virtual void visitCard(const Card* card) = 0;
    virtual void allCardsVisited() = 0;
    virtual ~FoundationVisitor() {}
};

#endif /* SRC_MODEL_INC_FOUNDATIONVISITOR_H_ */
