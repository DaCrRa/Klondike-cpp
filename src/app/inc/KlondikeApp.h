/*
 * KlondikeApp.h
 *
 *  Created on: 23 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_APP_KLONDIKEAPP_H_
#define SRC_APP_KLONDIKEAPP_H_

#include <ConsoleView.h>

#include <KlondikeAppStateContext.h>

class KlondikeApp {
private:
    ConsoleView* view;
    KlondikeAppStateContext* logic;
public:
    KlondikeApp(ConsoleView* view, KlondikeAppStateContext* logic);
    void run();
};

#endif /* SRC_APP_KLONDIKEAPP_H_ */
