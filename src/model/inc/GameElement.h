/*
 * GameElement.h
 *
 *  Created on: 8 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_GAMEELEMENT_H_
#define SRC_MODEL_INC_GAMEELEMENT_H_

#include <Pile.h>

class GameElement {
protected:
    Pile faceUpCards;
public:
    virtual Pile removeCards(int n) {
        return faceUpCards.removeLastCards(n);
    }
    virtual ~GameElement() {}
};

#endif /* SRC_MODEL_INC_GAMEELEMENT_H_ */
