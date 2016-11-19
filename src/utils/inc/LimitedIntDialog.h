/*
 * LimitedIntDialog.h
 *
 *  Created on: 19 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_UTILS_INC_LIMITEDINTDIALOG_H_
#define SRC_UTILS_INC_LIMITEDINTDIALOG_H_

#include <string>

#include <CancelledDialogException.h>

class LimitedInputDialog {
private:
    std::string promptMessage;
    int lowerBound;
    int upperBound;
public:
    LimitedInputDialog(std::string prompt, int low, int up) :
        promptMessage(prompt),
        lowerBound(low),
        upperBound(up) {}
    int getUserInput();
};

#endif /* SRC_UTILS_INC_LIMITEDINTDIALOG_H_ */
