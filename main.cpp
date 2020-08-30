#include <iostream>

#include "Engine/Application.hpp"
#include "Game/LevelGame.hpp"

int main()
{
    //Init engine
    Application* app = new Application("Game");



    //Init levelGame
    LevelGame* levelGame = new LevelGame("Level_Game", app);
    //Notifying the engine that levelGame exists (registry)
    app->AddLevel(levelGame, true);



    //Starting the engine
    app->Start();

    return EXIT_SUCCESS;
}
