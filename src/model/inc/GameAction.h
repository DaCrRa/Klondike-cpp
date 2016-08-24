/*
 * GameAction.h
 *
 *  Created on: 24 de ago. de 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_GAMEACTION_H_
#define SRC_MODEL_INC_GAMEACTION_H_

#include <assert.h>

class GameAction {
protected:
    virtual void action() = 0;
public:
    virtual bool canBeDone() = 0;
    void doAction() {
        assert(canBeDone());
        action();
    }
    virtual ~GameAction() {}
};

#endif /* SRC_MODEL_INC_GAMEACTION_H_ */
