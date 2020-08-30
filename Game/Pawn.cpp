#include "Pawn.hpp"
#include "../Engine/Animator.hpp"

using namespace std;

Pawn::Pawn(Application* engine) : Actor(engine)
{

}


//Events
void Pawn::EventTick(float delta)
{

}


//Getters
float Pawn::GetMoveSpeed()
{
    return m_MoveSpeed;
}


//Setters
void Pawn::SetMoveSpeed(float speed)
{
    m_MoveSpeed = speed;
}
