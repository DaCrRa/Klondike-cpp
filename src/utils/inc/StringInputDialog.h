/*
 * StringInputDialog.h
 *
 *  Created on: 5 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_UTILS_STRINGINPUTDIALOG_H_
#define SRC_UTILS_STRINGINPUTDIALOG_H_

#include <string>

class StringInputDialog {
private:
    const std::string promptMessage;
public:
    StringInputDialog(const std::string& promptMessage);
    std::string getUserInput();
};

#endif /* SRC_UTILS_STRINGINPUTDIALOG_H_ */
