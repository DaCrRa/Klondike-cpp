/*
 * KlondikeApp.cpp
 *
 *  Created on: 23 de may. de 2016
 *      Author: dancre
 */

#include <KlondikeApp.h>

KlondikeApp::KlondikeApp(ConsoleView* view, Logic* logic) :
    view(view), logic(logic) {}

void KlondikeApp::run() {
    try {
        while (true) {
            view->interact(logic->getNextController());
        }
    } catch (NoMoreControllersException& e) {}
}

