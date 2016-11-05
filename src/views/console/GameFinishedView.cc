/*
 * GameFinishedView.cc
 *
 *  Created on: 15 de ago. de 2016
 *      Author: dancre
 */

#include <GameFinishedView.h>
#include <BestScoresView.h>
#include <PressEnterToContinue.h>

#include <iostream>

void GameFinishedView::show(BestScoresController* bsc) {
    renderer.render();
    std::cout << std::endl;
    std::cout << "Game completed!!" << std::endl;
    std::cout << std::endl;
    PressEnterToContinue().waitForEnter();
    std::cout << std::endl;
    if (bsc->gameScoreIsInRanking()) {
        std::cout << "CONGRATULATIONS!! Your score is in top " << BestScoresController::MAX_BEST_SCORES << std::endl;
        std::cout << std::endl;
        BestScoresView().showBestScores(bsc);
    }
}
