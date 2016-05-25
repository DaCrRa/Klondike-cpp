/*
 * StartController.h
 *
 *  Created on: 16 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_STARTCONTROLLER_H_
#define SRC_CONTROLLERS_STARTCONTROLLER_H_

#include <Controller.h>
#include <ControllerVisitor.h>
#include <GameStatusController.h>
#include <GameActionControllerCatalog.h>
#include <Klondike.h>

#include <memory>
#include <vector>

class StartController : public Controller {
private:
    GameStatusController gameStatusController;
    GameActionControllerCatalog& gameActionControllerCatalog;
    bool terminateAppFlag;
public:
    StartController(std::shared_ptr<Klondike>& k, GameActionControllerCatalog& catalog);
    bool isGameInProgress();
    const std::vector<std::shared_ptr<GameActionController> > getAvailableGameActionControllers();
    void setSelectedGameActionController(size_t controller);
    void startGame();
    void resumeGame();
    void terminateApp();
    bool continueApp();
    void accept(ControllerVisitor* v);
};

#endif /* SRC_CONTROLLERS_STARTCONTROLLER_H_ */
