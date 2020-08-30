#ifndef ANIMATOR_HPP_INCLUDED
#define ANIMATOR_HPP_INCLUDED

#include "Object.hpp"

struct animation
{
    //Identity
        std::string uniqueName;
    //Rendering
        sf::Texture* flipBook;
        std::vector<sf::IntRect> frameRects;
    //Time
        float initTimePerFrame;
        float timePerFrame;
        float scale;

    void SetAnimationScale(float newScale)
    {
        scale = newScale;
        timePerFrame = initTimePerFrame * scale;
    }
};

class Actor;

class Animator : public Object
{
    public:
        Animator(Application* engine, Actor* owner);

        void AddAnimation(animation* anim);
        void AddAnimation(std::string name, sf::Texture* flipBook, std::vector<sf::IntRect> framesRects, float timePerFrame);
        void PlayAnimation(std::string animationName, bool forceRestart = false);

        //Events
            virtual void EventTick(float delta);
        //Setters
            void SetOwner(Actor* owner);
        //Getters
            animation* GetCurrentAnimation();
            animation* GetAnimation(std::string animName);
        //Static methods
            static std::vector<sf::IntRect> GenerateIntRectFramesVector(int x, int y, int lines, int columns, int lastLineEmpty = 0, int startLine = 1, int startColumn = 1);

    private:

    protected:
        //Animations
            void PlayAnimation(int animIndex);
            int GetAnimationIndex(std::string animationName);

            std::vector<animation*>* m_Animations;
            int m_ActiveAnimation;
            float m_EllapsedTime;
        //Frames Managing
            void NextFrame();

            int m_ActiveFrame;
        //Actor reference
            Actor* m_Owner;
};

#endif // ANIMATOR_HPP_INCLUDED
