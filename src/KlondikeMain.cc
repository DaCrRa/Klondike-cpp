#include <ConsoleView.h>
#include <KlondikeAppStateContext.h>
#include <GamePausedState.h>
#include <KlondikeApp.h>

int main(int argc, char* argv[]) {
    ConsoleView view;
    KlondikeAppStateContext logic(KlondikeAppStatePtr(new GamePausedState()));

    KlondikeApp(&view, &logic).run();
}
