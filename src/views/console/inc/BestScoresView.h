/*
 * BestScoresView.h
 *
 *  Created on: 21 de ago. de 2016
 *      Author: dancre
 */

#ifndef SRC_VIEWS_CONSOLE_BESTSCORESVIEW_H_
#define SRC_VIEWS_CONSOLE_BESTSCORESVIEW_H_

#include <BestScoresController.h>

class BestScoresView {
private:
    int getNumOfDigits(long value);
public:
    void showBestScores(BestScoresController* bsc);
};

#endif /* SRC_VIEWS_CONSOLE_BESTSCORESVIEW_H_ */
