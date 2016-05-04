/*
 * MoveOrigin.h
 *
 *  Created on: 4 de may. de 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_MOVEORIGIN_H_
#define SRC_MODEL_INC_MOVEORIGIN_H_

#include <Card.h>

class MoveOrigin {
public:
	virtual Card* showAvailableCard() = 0;
	virtual Card* removeAvaiblableCard() = 0;
	virtual ~MoveOrigin() {}
};

#endif /* SRC_MODEL_INC_MOVEORIGIN_H_ */
