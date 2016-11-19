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
public:
    virtual Pile removeCards(int n) = 0;
    virtual ~GameElement() {}
};

#endif /* SRC_MODEL_INC_GAMEELEMENT_H_ */
