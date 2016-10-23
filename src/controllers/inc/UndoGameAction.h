/*
 * UndoGameAction.h
 *
 *  Created on: 30 de ago. de 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_UNDOGAMEACTION_H_
#define SRC_MODEL_INC_UNDOGAMEACTION_H_

#include <GameAction.h>
#include <GameActionHistoryController.h>

class UndoGameAction: public GameAction {
private:
    std::shared_ptr<GameActionHistoryController> historyController;
protected:
    void action();
public:
    UndoGameAction(const std::shared_ptr<GameActionHistoryController>& hc) :
        historyController(hc) {};
    bool canBeDone();
    void acceptGameActionVisitor(GameActionVisitor* visitor);
};

#endif /* SRC_MODEL_INC_UNDOGAMEACTION_H_ */
