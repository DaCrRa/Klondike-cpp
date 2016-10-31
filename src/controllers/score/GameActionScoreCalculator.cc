#include <GameActionScoreCalculator.h>
#include <UndoGameAction.h>
#include <RedoGameAction.h>
#include <UserSelectedMove.h>

void GameActionScoreCalculator::visit(StockAction* stockAction) {
    scoreDelta = 0;
}

void GameActionScoreCalculator::visit(ForwardGameAction* fwdGameAction) {
    fwdGameAction->accept(this);
}

void GameActionScoreCalculator::visit(UserSelectedMove* userSelectedMove) {
    visit(userSelectedMove->getMove().get());
}

void GameActionScoreCalculator::visit(UndoGameAction* undoGameAction) {
    ForwardGameActionPtr actionUndone = undoGameAction->getForwardGameAction();
    scoreDelta = -actionUndone->getScoreDelta();
}

void GameActionScoreCalculator::visit(RedoGameAction* redoGameAction) {
    ForwardGameActionPtr actionRedone = redoGameAction->getForwardGameAction();
    scoreDelta = actionRedone->getScoreDelta();
}


void GameActionScoreCalculator::visit(Move* move) {
    moveScoreCalculator = std::make_shared<MoveScoreCalculator>(scoreDelta);
    move->acceptMoveVisitor(moveScoreCalculator.get());
}

void GameActionScoreCalculator::setActionScore() {
    action->acceptGameActionVisitor(this);
    action->setScoreDelta(scoreDelta);
}
