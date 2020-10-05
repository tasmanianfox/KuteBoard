#include "game.h"

static string FEN_START_POSITION = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

Game::Game()
{

}

void Game::newGame()
{
    this->position.setFromFEN(FEN_START_POSITION);
}
