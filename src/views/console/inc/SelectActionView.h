/*
 * SelectActionView.h
 *
 *  Created on: 2 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_INC_SELECTACTIONVIEW_H_
#define SRC_INC_SELECTACTIONVIEW_H_

#include <GameAction.h>

#include <map>

class SelectActionView {
private:
	std::map<char, GameActionPtr> availableActions;
public:
	SelectActionView();
	GameActionPtr getAction();
};

#endif /* SRC_INC_SELECTACTIONVIEW_H_ */
