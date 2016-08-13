#include <GameActionScoreCalculator.h>

void GameActionScoreCalculator::visit(StockAction* stockAction) {
    scoreDelta = 0;
}
void GameActionScoreCalculator::visit(Move* move) {
    MoveScoreCalculator calculator(move);
    move->acceptOriginVisitor(&calculator);
    scoreDelta = calculator.getScoreDelta();
}
int GameActionScoreCalculator::getScoreDelta() const {
    return scoreDelta;
}
