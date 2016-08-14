/*
 * TableauPileObserver.h
 *
 *  Created on: 14 de ago. de 2016
 *      Author: dancre
 */

#ifndef SRC_MODEL_INC_TABLEAUPILEOBSERVER_H_
#define SRC_MODEL_INC_TABLEAUPILEOBSERVER_H_

class TableauPileObserver {
public:
    virtual void onCardTurnUp() = 0;
    virtual ~TableauPileObserver() {}
};



#endif /* SRC_MODEL_INC_TABLEAUPILEOBSERVER_H_ */
