#ifndef PLAYERANIMATOR_HPP
#define PLAYERANIMATOR_HPP

#include "../Engine/Animator.hpp"


class PlayerAnimator : public Animator
{
    public:
        PlayerAnimator(Application* engine, Actor* owner);
    protected:
        virtual void EventStart();
        virtual void EventTick(float delta);

        void CreateAnimations();

        sf::Texture* m_FlipBook;

    private:
};

#endif // PLAYERANIMATOR_HPP
