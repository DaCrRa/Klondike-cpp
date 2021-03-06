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
    bool cardTurnedUp;
protected:
    MoveOrigin* getMoveOrigin();
    void forwardAction();
    void undoImpl();
public:
    MoveFromTableauPile(TableauPile* tp, ForwardGameActionObserverPtr o = ForwardGameActionObserverPtr()) :
        Move(o),
        origin(tp),
        cardTurnedUp(false) {}
    ForwardGameActionPtr duplicate();
    void setNumberOfCards(int n);
    bool cardWasTurnUp();
    void acceptMoveVisitor(MoveVisitor* visitor);
};

#endif /* SRC_MODEL_INC_MOVEFROMTABLEAU_H_ */
