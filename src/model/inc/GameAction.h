/*
 * GameAction.h
 *
 *  Created on: 24 de ago. de 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_GAMEACTION_H_
#define SRC_MODEL_INC_GAMEACTION_H_

#include <GameActionVisitor.h>

#include <assert.h>
#include <memory>

class GameAction;
typedef std::shared_ptr<GameAction> GameActionPtr;

class GameAction {
private:
    int scoreDelta;
protected:
    virtual void action() = 0;
public:
    virtual bool canBeDone() = 0;
    void doAction() {
        assert(canBeDone());
        action();
    }
    virtual void setScoreDelta(int d) {
        scoreDelta = d;
    }
    int getScoreDelta() {
        return scoreDelta;
    }
    virtual void acceptGameActionVisitor(GameActionVisitor* visitor) = 0;
    virtual ~GameAction() {}
};

#endif /* SRC_MODEL_INC_GAMEACTION_H_ */
