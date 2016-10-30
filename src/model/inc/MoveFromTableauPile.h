/*
 * MoveFromStock.h
 *
 *  Created on: 30 Oct 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_MOVEFROMTABLEAU_H_
#define SRC_MODEL_INC_MOVEFROMTABLEAU_H_

#include <Move.h>
#include <TableauPile.h>

class MoveFromTableauPile: public Move {
private:
    TableauPile* origin;
protected:
    MoveOrigin* getMoveOrigin();
public:
    MoveFromTableauPile(TableauPile* tp, ForwardGameActionObserverPtr o = ForwardGameActionObserverPtr()) :
        Move(o),
        origin(tp) {}
    ForwardGameActionPtr duplicate();
    void acceptMoveVisitor(MoveVisitor* visitor);
    TableauPile* getOriginTableauPile();
};

#endif /* SRC_MODEL_INC_MOVEFROMTABLEAU_H_ */
