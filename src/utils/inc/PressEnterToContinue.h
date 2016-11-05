/*
 * PressEnterToContinue.h
 *
 *  Created on: 5 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_UTILS_INC_PRESSENTERTOCONTINUE_H_
#define SRC_UTILS_INC_PRESSENTERTOCONTINUE_H_

#include <string>
#include <iostream>

class PressEnterToContinue {
private:
    std::string promptMessage;
public:
    PressEnterToContinue(std::string s = "Press enter to continue...") :
        promptMessage(s) {}
    void waitForEnter() {
        std::cout << promptMessage;
        std::string s;
        std::getline(std::cin, s);
    }
};

#endif /* SRC_UTILS_INC_PRESSENTERTOCONTINUE_H_ */
