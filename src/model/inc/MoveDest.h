/*
 * MoveDest.h
 *
 *  Created on: 4 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_MOVEDEST_H_
#define SRC_MODEL_INC_MOVEDEST_H_

#include <Pile.h>
#include <GameElement.h>
#include <MoveDestVisitor.h>

class MoveDest : virtual public GameElement {
protected:
    Pile faceUpCards;
public:
    virtual bool cardMeetsFirstCardCondition(const Card* card) const = 0;
    virtual bool addCardCondition(const Card* referenceCard, const Card* cardToAdd) const = 0;
    bool cardCanBeAdded(const Card* cardToAdd) const;
    bool cardsCanBeAdded(const Pile& cards) const;
    void addCard(const Card* c);
    virtual void accept(MoveDestVisitor* visitor) = 0;
    virtual ~MoveDest() {}
};

#endif /* SRC_MODEL_INC_MOVEDEST_H_ */
