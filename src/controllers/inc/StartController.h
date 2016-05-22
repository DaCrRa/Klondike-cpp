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
#include <Klondike.h>

#include <memory>
#include <vector>

class StartController : public Controller {
private:
	std::shared_ptr<Klondike>& game;
	std::shared_ptr<GameActionController> selectedGameActionController;
public:
	StartController(std::shared_ptr<Klondike>& k);
	bool isGameInProgress();
	std::vector<std::shared_ptr<GameActionController> > getGameActionControllers();
	void setSelectedGameActionController(const std::shared_ptr<GameActionController>& controller);
	GameActionController* getSelectedGameActionController();
	void startGame();
	void resumeGame();
	void accept(ControllerVisitor* v);
};

#endif /* SRC_CONTROLLERS_STARTCONTROLLER_H_ */
