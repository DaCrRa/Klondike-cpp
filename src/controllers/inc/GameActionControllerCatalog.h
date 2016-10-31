/*
 * GameActionControllerCatalog.h
 *
 *  Created on: 24 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_GAMEACTIONCONTROLLERCATALOG_H_
#define SRC_CONTROLLERS_GAMEACTIONCONTROLLERCATALOG_H_

#include <Klondike.h>
#include <memory>
#include <vector>
#include <GameActionController.h>

class GameActionControllerCatalog {
private:
    const std::vector<std::shared_ptr<GameActionController> > availableControllers;
    std::shared_ptr<GameActionController> selectedController;
public:
    GameActionControllerCatalog(std::shared_ptr<Klondike>& game);
    const std::vector<std::shared_ptr<GameActionController> >& getAvailableGameActionControllers();
    void selectGameActionController(size_t selected);
    std::shared_ptr<GameActionController> getSelectedGameActionController();
};

#endif /* SRC_CONTROLLERS_GAMEACTIONCONTROLLERCATALOG_H_ */
