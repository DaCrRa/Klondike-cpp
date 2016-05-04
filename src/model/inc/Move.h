/*
 * Move.h
 *
 *  Created on: 4 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_MOVE_H_
#define SRC_MODEL_INC_MOVE_H_

#include <MoveOrigin.h>
#include <MoveDest.h>
#include <GameActionVisitor.h>
#include <GameAction.h>

class Move : public GameAction {
private:
	MoveOrigin* origin;
	MoveDest* dest;
public:
	void setOrigin(MoveOrigin* o);
	void setDest(MoveDest* d);
	void accept(GameActionVisitor* visitor);
};

#endif /* SRC_MODEL_INC_MOVE_H_ */
