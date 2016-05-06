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
#include <GameAction.h>
#include <GameActionVisitor.h>

class GameActionController: public Controller, public GameActionVisitor {
private:
	Klondike* game;
public:
	GameActionController(Klondike* g);
	void doAction(GameActionPtr action);
	void accept(ControllerVisitor* visitor);
	void visit(StockAction* stockAction);
	void visit(Move* move);

	Stock* getStock();
	std::vector<MoveOrigin*> getAvailableOrigins();

};

#endif /* SRC_INC_GAMEACTIONCONTROLLER_H_ */
