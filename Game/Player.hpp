#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include "Pawn.hpp"

enum direction{Up, Down, Left, Right};

class Player : public Pawn
{
    public:
        Player(Application* engine);

        //Getters
        direction GetDirection();
        bool GetIsMoving();

    protected:
        virtual void EventTick(float delta);
        virtual void EventStart();

        sf::Texture* m_SpriteSheet;
        direction m_Direction;
        bool m_IsMoving;

        void CreateAnimations();

    private:
};

#endif // PLAYER_HPP_INCLUDED
