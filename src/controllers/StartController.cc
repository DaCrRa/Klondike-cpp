/*
 * StartController.cpp
 *
 *  Created on: 16 de may. de 2016
 *      Author: dancre
 */

#include <StartController.h>

StartController::StartController(Klondike* k) {
	// TODO Auto-generated constructor stub

}

void StartController::accept(ControllerVisitor* v) {
	v->visit(this);
}
