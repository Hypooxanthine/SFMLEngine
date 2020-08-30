#ifndef LEVELGAME_HPP
#define LEVELGAME_HPP

#include "../Engine/Level.hpp"
#include "Player.hpp"


class LevelGame : public Level
{
    public:
        LevelGame(std::string name, Application* engine);
        virtual ~LevelGame();

        virtual void EventLevelOpened();

    protected:

    private:
        Player* m_PlayerPawn;

};

#endif
