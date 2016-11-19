/*
 * CancelledDialogException.h
 *
 *  Created on: 19 Nov 2016
 *      Author: dancre
 */

#ifndef SRC_UTILS_INC_CANCELLEDDIALOGEXCEPTION_H_
#define SRC_UTILS_INC_CANCELLEDDIALOGEXCEPTION_H_

class CancelledDialogException : public std::exception {
public:
    const char* what() const throw() {
        return "Cancelled dialog!";
    };
};

#endif /* SRC_UTILS_INC_CANCELLEDDIALOGEXCEPTION_H_ */
