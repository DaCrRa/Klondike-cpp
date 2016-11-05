/*
 * BestScoresView.cpp
 *
 *  Created on: 21 de ago. de 2016
 *      Author: dancre
 */

#include <BestScoresView.h>

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <assert.h>

void BestScoresView::showBestScores(BestScoresController* bsc) {
    std::vector<int>& bestScores = bsc->getBestScores();
    int postionColumnWidth = getNumOfDigits(BestScoresController::MAX_BEST_SCORES);
    int scoresColumnWidth = getNumOfDigits(*bestScores.rbegin());
    int i = 0;
    for (std::vector<int>::reverse_iterator it = bestScores.rbegin(); it != bestScores.rend(); ++it) {
        std::cout << "   ";
        std::cout << ( (i == bsc->getLastRegisteredPosition()) ? ">" : " ");
        std::cout << " ";
        std::cout << std::setw(postionColumnWidth) << ++i;
        std::cout << ".  ";
        std::cout << std::setw(scoresColumnWidth) << *it << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Press enter to continue...";
    std::cin.get();
    std::cin.get();
}

int BestScoresView::getNumOfDigits(long value) {
    int digits = 0;
    if (value < 0) {
        digits++;
    }
    int absValue = std::abs(value);
    do {
        absValue /= 10;
        digits++;
    } while (absValue > 0);
    assert(digits > 0);
    return digits;
}

