/*
 * UndoGameAction.h
 *
 *  Created on: 30 de ago. de 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_UNDOGAMEACTION_H_
#define SRC_MODEL_INC_UNDOGAMEACTION_H_

#include <GameAction.h>

class UndoGameAction: public GameAction {
protected:
    void action();
public:
    UndoGameAction();
    bool canBeDone();
};

#endif /* SRC_MODEL_INC_UNDOGAMEACTION_H_ */
