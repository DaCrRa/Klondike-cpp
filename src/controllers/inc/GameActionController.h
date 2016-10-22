/*
 * GameActionController.h
 *
 *  Created on: 24 de abr. de 2016
 *      Author: dancre
 */

#ifndef SRC_INC_GAMEACTIONCONTROLLER_H_
#define SRC_INC_GAMEACTIONCONTROLLER_H_

#include <Klondike.h>
#include <Controller.h>
#include <ControllerVisitor.h>
#include <ForwardGameAction.h>
#include <ForwardGameActionVisitor.h>
#include <GameActionControllerVisitor.h>
#include <ScoreController.h>

class GameActionController: public Controller {
protected:
    std::shared_ptr<Klondike>& game;
    ScoreController scoreController;
public:
    GameActionController(std::shared_ptr<Klondike>& game);
    std::shared_ptr<Klondike>& getGame();
    void doAction(GameActionPtr action);
    virtual void acceptGameActionControllerVisitor(GameActionControllerVisitor* visitor) = 0;
    void accept(ControllerVisitor* visitor);
    ~GameActionController() {}
};

#endif /* SRC_INC_GAMEACTIONCONTROLLER_H_ */
