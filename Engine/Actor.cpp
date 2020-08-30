#include "Actor.hpp"
#include "Animator.hpp"

Actor::Actor(Application* engine) : Object(engine)
{
    m_Sprite = new sf::Sprite();
    m_Animator = new Animator(engine, this);
}

void Actor::Draw(sf::RenderWindow* window)
{
    if(m_Sprite != NULL)
    {
        window->draw(*m_Sprite);
    }
}

//Setters
void Actor::SetActorPosition(sf::Vector2f pos)
{
    m_ActorPosition = pos;
    m_Sprite->setPosition(m_ActorPosition + m_SpritePosition);
}

void Actor::SetSpritePosition(sf::Vector2f pos)
{
    m_SpritePosition = pos;
    m_Sprite->setPosition(m_ActorPosition + m_SpritePosition);
}

void Actor::SetAnimator(Animator* animator)
{
    m_Animator = animator;
    m_Animator->SetOwner(this);
}

//Getters
sf::Vector2f Actor::GetPosition()
{
    return m_ActorPosition;
}

sf::Sprite* Actor::GetSprite()
{
    return m_Sprite;
}

Animator* Actor::GetAnimator()
{
    return m_Animator;
}
