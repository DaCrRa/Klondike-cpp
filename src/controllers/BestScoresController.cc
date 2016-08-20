/*
 * BestScoresController.cc
 *
 *  Created on: 15 de ago. de 2016
 *      Author: dancre
 */

#include <BestScoresController.h>

#include <algorithm>
#include <assert.h>

void BestScoresController::accept(ControllerVisitor* visitor) {
    visitor->visit(this);
}

std::shared_ptr<Klondike>& BestScoresController::getGame() {
    return game;
}

std::vector<int>& BestScoresController::getBestScores() {
    return bestScores;
}

int BestScoresController::insertScore(int newScore) {
    std::vector<int>::iterator scorePostion = std::lower_bound(bestScores.begin(), bestScores.end(), newScore);
    int insertionPosition = bestScores.end() - scorePostion;
    bestScores.insert(scorePostion, newScore);
    return insertionPosition;
}

void BestScoresController::trimBestScores() {
    while (bestScores.size() > MAX_BEST_SCORES) {
        bestScores.erase(bestScores.begin());
    }
}

bool BestScoresController::gameScoreIsInRanking() {
    assert(lastRegisteredPosition >= 0);
    return lastRegisteredPosition < MAX_BEST_SCORES;
}

void BestScoresController::registerScore() {
    lastRegisteredPosition = insertScore(game->getScore());
    trimBestScores();
}
