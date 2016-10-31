/*
 * UserGameActionController.h
 *
 *  Created on: 12 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_INC_USERGAMEACTIONCONTROLLER_H_
#define SRC_CONTROLLERS_INC_USERGAMEACTIONCONTROLLER_H_

#include <GameActionController.h>
#include <GameActionHistoryController.h>

#include <memory>

class UserGameActionController: public GameActionController {
private:
    std::shared_ptr<GameActionHistoryController> historyController;
public:
    UserGameActionController(std::shared_ptr<Klondike>& game) :
        GameActionController(game),
        historyController(new GameActionHistoryController()) {};
    UserGameActionController(const UserGameActionController& copy) :
        GameActionController(copy.game),
        historyController(new GameActionHistoryController(*(copy.historyController))) {}
    void acceptGameActionControllerVisitor(GameActionControllerVisitor* visitor);
    std::shared_ptr<GameActionHistoryController> getGameActionHistoryController();
    GameActionController* clone();
};

#endif /* SRC_CONTROLLERS_INC_USERGAMEACTIONCONTROLLER_H_ */
