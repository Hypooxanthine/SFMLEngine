#ifndef PAWN_HPP_INCLUDED
#define PAWN_HPP_INCLUDED

#include "../Engine/Actor.hpp"

class Pawn : public Actor
{
    public:
        Pawn(Application* engine);

        virtual void EventTick(float delta);

        float GetMoveSpeed();

        void SetMoveSpeed(float speed);


    protected:
        float m_MoveSpeed;

    private:

};

#endif // PAWN_HPP_INCLUDED
