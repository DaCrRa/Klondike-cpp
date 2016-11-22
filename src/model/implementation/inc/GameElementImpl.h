/*
 * GameElementImpl.h
 *
 *  Created on: 21 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_IMPLEMENTATION_INC_GAMEELEMENTIMPL_H_
#define SRC_MODEL_IMPLEMENTATION_INC_GAMEELEMENTIMPL_H_

#include <GameElement.h>

class GameElementImpl : virtual public GameElement {
protected:
    Pile faceUpCards;
public:
    virtual Pile removeCards(int n) {
        return faceUpCards.removeLastCards(n);
    }
    virtual ~GameElementImpl() {}
};


#endif /* SRC_MODEL_IMPLEMENTATION_INC_GAMEELEMENTIMPL_H_ */
