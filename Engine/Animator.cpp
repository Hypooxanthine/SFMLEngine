#include "Animator.hpp"
#include "Actor.hpp"
#include "Animation.hpp"

using namespace std;

Animator::Animator(Application* engine, Actor* owner) : Object(engine)
{
    m_Animations = new vector<animation*>();
    m_ActiveAnimation = -1;
    m_EllapsedTime = 0;
    SetOwner(owner);
}

void Animator::AddAnimation(animation* anim)
{
    bool first = (m_Animations->size() == 0) ? true : false;

    anim->initTimePerFrame = anim->timePerFrame;
    anim->scale = 1;

    m_Animations->push_back(anim);

    if(first)
        PlayAnimation(0);
}

void Animator::AddAnimation(std::string name, sf::Texture* flipBook, std::vector<sf::IntRect> framesRects, float timePerFrame)
{
    struct animation* anim = new animation{
        name,
        flipBook,
        framesRects,
        timePerFrame,
        timePerFrame,
        1};

    AddAnimation(anim);
}

void Animator::PlayAnimation(string animationName, bool forceRestart)
{
    if(forceRestart || m_Animations->at(m_ActiveAnimation)->uniqueName != animationName)
    {
        int index = GetAnimationIndex(animationName);

        if(index >= 0)
            PlayAnimation(index);
        else
            cerr << animationName << " doesn't exist." << endl;
    }
}


void Animator::PlayAnimation(int animIndex)
{
    m_ActiveAnimation = animIndex;
    m_Owner->GetSprite()->setTexture(*GetCurrentAnimation()->flipBook);
    m_EllapsedTime = 0;
    m_ActiveFrame = 0;
}

int Animator::GetAnimationIndex(string animationName)
{
    for(unsigned int i = 0 ; i < m_Animations->size() ; i++)
    {
        if(m_Animations->at(i)->uniqueName == animationName)
        {
            return i;
        }
    }

    return -1;
}

void Animator::NextFrame()
{
    m_ActiveFrame += 1;
    m_ActiveFrame %= GetCurrentAnimation()->frameRects.size();
}

//Events
void Animator::EventTick(float delta) //Animation update
{
    if(m_Animations->size() > 0 && m_ActiveAnimation >= 0)
    {
        m_EllapsedTime += delta;

        if(m_EllapsedTime >= GetCurrentAnimation()->timePerFrame)
        {
            NextFrame();
            m_EllapsedTime = 0;
        }
    }

    m_Owner->GetSprite()->setTextureRect(GetCurrentAnimation()->frameRects.at(m_ActiveFrame));
}


//Setters
void Animator::SetOwner(Actor* owner)
{
    m_Owner = owner;
}


//Getters
animation* Animator::GetCurrentAnimation()
{
    return m_Animations->at(m_ActiveAnimation);
}

animation* Animator::GetAnimation(string animName)
{
    int index = GetAnimationIndex(animName);

    if(index >= 0)
        return m_Animations->at(index);
    else
        return new animation;
}

//Static methods
vector<sf::IntRect> Animator::GenerateIntRectFramesVector(int x, int y, int lines, int columns, int lastLineEmpty, int startLine, int startColumn)
{
    vector<sf::IntRect> frames;

    for(int j = startLine - 1 ; j < startLine + lines - 1 ; j++)
    {
        for(int i = startColumn - 1 ; i < startColumn + columns - 1 ; i++)
        {
            frames.push_back(sf::IntRect(i * x, j * y, x, y));
        }
    }

    for(int i = 0 ; i < lastLineEmpty ; i++)
        frames.pop_back();

    return frames;
}
