/*
 * GameAction.h
 *
 *  Created on: 24 de abr. de 2016
 *      Author: dancre
 */

#ifndef SRC_INC_GAMEACTION_H_
#define SRC_INC_GAMEACTION_H_

class GameActionVisitor;

class GameAction {
public:
	virtual void accept(GameActionVisitor* visitor) = 0;
	virtual ~GameAction() {}
};

#endif /* SRC_INC_GAMEACTION_H_ */
