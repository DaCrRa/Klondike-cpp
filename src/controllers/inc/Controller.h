/*
 * Controller.h
 *
 *  Created on: 8 Apr 2016
 *      Author: dancre
 */

#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_

#include <memory>

class ControllerVisitor;

class Controller;
typedef std::shared_ptr<Controller> ControllerPtr;

class Controller {
public:
    virtual void accept(ControllerVisitor* v) = 0;
    virtual ~Controller() {}
};

#endif
