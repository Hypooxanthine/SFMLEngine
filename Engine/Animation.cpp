#include "Animation.hpp"

using namespace std;

Animation::Animation(Application* engine, sf::Texture* flipBook, string name, float timePerFrame) : Object(engine)
{
    m_FlipBook = flipBook;
    m_UniqueName = name;
    m_TimePerFrame = timePerFrame;
}

//Events


//Setters
void Animation::SetFlipBook(sf::Texture* flipBook)
{
    m_FlipBook = flipBook;
}

void Animation::SetTimePerFrame(float milliseconds)
{
    m_TimePerFrame = milliseconds;
}


//Getters
float Animation::GetMillisecondsPerFrame()
{
    return m_TimePerFrame;
}
