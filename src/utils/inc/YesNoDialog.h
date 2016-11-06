/*
 * YesNoDialog.h
 *
 *  Created on: 5 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_UTILS_INC_YESNODIALOG_H_
#define SRC_UTILS_INC_YESNODIALOG_H_

#include <ItemSelectionDialog.h>

class YesNoDialog {
private:
    ItemSelectionDialog<bool> itemSelectionDialog;
public:
    YesNoDialog(const std::string& promptMsg) :
        itemSelectionDialog(promptMsg,
                            std::map<char, bool>( {
        {'y', true
        }
    }),
    'n') {}
    bool userSaidYes() {
        while (true) {
            try {
                return itemSelectionDialog.getSelectedItem();
            } catch (CancelledDialogException& e) {
                return false;
            }
        }
    }
    bool userSaidNo() {
        return !userSaidYes();
    }
};

#endif /* SRC_UTILS_INC_YESNODIALOG_H_ */
