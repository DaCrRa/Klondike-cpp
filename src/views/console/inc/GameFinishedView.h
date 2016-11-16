
#include <KlondikeConsoleRenderer.h>
#include <BestScoresController.h>
#include <DeckTypes.h>

class GameFinishedView {
private:
    std::shared_ptr<Klondike>& game;
    KlondikeConsoleRenderer renderer;
public:
    GameFinishedView(std::shared_ptr<Klondike>& g, DeckType t) :
        game(g),
        renderer(game, t) {}
    void show(BestScoresController* bsc);
};
