/*
 * MoveCardController.h
 *
 *  Created on: 7 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLERS_MOVECARDCONTROLLER_H_
#define SRC_CONTROLLERS_MOVECARDCONTROLLER_H_

#include <Klondike.h>
#include <MoveOrigin.h>
#include <MoveDest.h>

class MoveCardController {
public:
	MoveCardController(Klondike* k);
	Stock* getStock();
	std::vector<MoveOrigin*> getAvailableOrigins();
	std::vector<MoveDest*> getAvailableDests(MoveOrigin* origin);
private:
	Klondike* game;
};

#endif /* SRC_CONTROLLERS_MOVECARDCONTROLLER_H_ */
