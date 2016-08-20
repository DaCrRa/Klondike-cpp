
#include <KlondikeConsoleRenderer.h>
#include <BestScoresController.h>

class GameFinishedView {
private:
    std::shared_ptr<Klondike>& game;
    KlondikeConsoleRenderer renderer;
public:
    GameFinishedView(std::shared_ptr<Klondike>& g) :
        game(g),
        renderer(game) {}
    void show(BestScoresController* bsc);
};
