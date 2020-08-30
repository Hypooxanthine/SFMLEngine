#include "LevelGame.hpp"

using namespace std;

LevelGame::LevelGame(string name, Application* engine) : Level(name, engine)
{

}


//Events
void LevelGame::EventLevelOpened()
{
    Player* m_PlayerPawn = new Player(m_Engine);
    AddObject(m_PlayerPawn);
}

LevelGame::~LevelGame()
{

}
