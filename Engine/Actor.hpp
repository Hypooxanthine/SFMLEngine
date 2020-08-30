#ifndef ACTOR_HPP_INCLUDED
#define ACTOR_HPP_INCLUDED

#include "Object.hpp"

class Animator;

class Actor : public Object
{
    public:
        Actor(Application* engine);

        //Setters
            void SetActorPosition(sf::Vector2f pos);
            void SetSpritePosition(sf::Vector2f pos);
            void SetAnimator(Animator* animator);

        //Getters
            sf::Sprite* GetSprite();
            sf::Vector2f GetPosition();
            Animator* GetAnimator();

        virtual void Draw(sf::RenderWindow* window);

    protected:
        //Positioning
            sf::Vector2f m_ActorPosition;
            sf::Vector2f m_SpritePosition;
        //Rendering
            sf::Sprite* m_Sprite;
        //Animating
            Animator* m_Animator;

    private:

};

#endif // ACTOR_HPP_INCLUDED
