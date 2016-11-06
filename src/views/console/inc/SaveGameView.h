/*
 * SaveGameView.h
 *
 *  Created on: 5 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_VIEWS_CONSOLE_INC_SAVEGAMEVIEW_H_
#define SRC_VIEWS_CONSOLE_INC_SAVEGAMEVIEW_H_

#include <SaveGameController.h>

class CancelledSaveException : public std::exception {
public:
    const char* what() const throw() {
        return "Save game cancelled!";
    };
};

class SaveGameView {
private:
    std::string getGameName(SaveGameController* saveGameController);
public:
    void interact(SaveGameController* saveGameController);
};

#endif /* SRC_VIEWS_CONSOLE_INC_SAVEGAMEVIEW_H_ */
