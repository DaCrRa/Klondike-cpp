/*
 * Controller.h
 *
 *  Created on: 8 Apr 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_

class Controller {
public:
	virtual void operate() = 0;
	virtual ~Controller() {}
};

#endif
