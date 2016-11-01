#include <ConsoleView.h>
#include <GamePausedState.h>
#include <KlondikeApp.h>
#include <Logic.h>

int main(int argc, char* argv[]) {
    ConsoleView view;
    Logic logic;

    KlondikeApp(&view, &logic).run();
}
