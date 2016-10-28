#include <GameActionScoreCalculator.h>
#include <UndoGameAction.h>

void GameActionScoreCalculator::visit(StockAction* stockAction) {
    scoreDelta = 0;
}

void GameActionScoreCalculator::visit(ForwardGameAction* fwdGameAction) {
    fwdGameAction->accept(this);
}

void GameActionScoreCalculator::visit(UndoGameAction* undoGameAction) {
    ForwardGameActionPtr actionUndone = undoGameAction->getForwardGameAction();
    scoreDelta = -actionUndone->getScoreDelta();
}

void GameActionScoreCalculator::visit(Move* move) {
    moveScoreCalculator = std::make_shared<MoveScoreCalculator>(move, scoreDelta);
    move->acceptOriginVisitor(moveScoreCalculator.get());
}

int GameActionScoreCalculator::getScoreDelta() const {
    return scoreDelta;
}
