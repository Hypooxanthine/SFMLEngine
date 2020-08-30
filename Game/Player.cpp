#include "Player.hpp"
#include "PlayerAnimator.hpp"
#include <cmath>

using namespace std;

Player::Player(Application* engine) : Pawn(engine)
{
    PlayerAnimator* animator = new PlayerAnimator(engine, this);
    SetAnimator(animator);
}


//Events
void Player::EventStart()
{
    SetMoveSpeed(3);
    m_SpriteSheet = new sf::Texture();
    m_Direction = Down;
}

void Player::EventTick(float delta)
{
    m_IsMoving = false;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        QuitGame();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        SetActorPosition(sf::Vector2f(m_ActorPosition.x - m_MoveSpeed, m_ActorPosition.y));
        m_IsMoving = true;
        m_Direction = Left;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        SetActorPosition(sf::Vector2f(m_ActorPosition.x + m_MoveSpeed, m_ActorPosition.y));
        m_IsMoving = true;
        m_Direction = Right;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        SetActorPosition(sf::Vector2f(m_ActorPosition.x, m_ActorPosition.y - m_MoveSpeed));
        m_IsMoving = true;
        m_Direction = Up;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        SetActorPosition(sf::Vector2f(m_ActorPosition.x, m_ActorPosition.y + m_MoveSpeed));
        m_IsMoving = true;
        m_Direction = Down;
    }
}


//Getters
direction Player::GetDirection()
{
    return m_Direction;
}

bool Player::GetIsMoving()
{
    return m_IsMoving;
}
