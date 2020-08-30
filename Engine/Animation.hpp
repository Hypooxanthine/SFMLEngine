#ifndef ANIMATION_HPP_INCLUDED
#define ANIMATION_HPP_INCLUDED

#include "Object.hpp"

class Animation : public Object
{
    public:
        Animation(Application* engine, sf::Texture* flipBook, std::string name, float timePerFrame = 150);

        //Events
        //Getters
            float GetMillisecondsPerFrame();
        //Setters
            void SetFlipBook(sf::Texture* flipBook);
            void SetTimePerFrame(float milliseconds);


    protected:


    private:
        //Identity
            std::string m_UniqueName;
        //Rendering
            sf::Texture* m_FlipBook;
            std::vector<sf::IntRect> m_FrameRects;
        //Time managing
            float m_TimePerFrame;

};

#endif
