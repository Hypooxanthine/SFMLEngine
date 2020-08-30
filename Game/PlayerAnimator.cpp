#include "PlayerAnimator.hpp"
#include "Player.hpp"

using namespace std;

PlayerAnimator::PlayerAnimator(Application* engine, Actor* owner) : Animator(engine, owner)
{
    m_FlipBook = new sf::Texture();
}

void PlayerAnimator::EventStart()
{
    CreateAnimations();
}

void PlayerAnimator::EventTick(float delta)
{
    Animator::EventTick(delta);

    Player* asPlayer = dynamic_cast<Player*>(m_Owner);

    if(asPlayer != NULL)
    {
        if(asPlayer->GetIsMoving())
        {
            switch(asPlayer->GetDirection())
            {
                case Up:
                    PlayAnimation("Anim_Walking_Up");
                    break;
                case Down:
                    PlayAnimation("Anim_Walking_Down");
                    break;
                case Left:
                    PlayAnimation("Anim_Walking_Left");
                    break;
                case Right:
                    PlayAnimation("Anim_Walking_Right");
                    break;
            }
        }
        else
        {
            switch(asPlayer->GetDirection())
            {
                case Up:
                    PlayAnimation("Anim_Idle_Up");
                    break;
                case Down:
                    PlayAnimation("Anim_Idle_Down");
                    break;
                case Left:
                    PlayAnimation("Anim_Idle_Left");
                    break;
                case Right:
                    PlayAnimation("Anim_Idle_Right");
                    break;
            }
        }
    }
}

void PlayerAnimator::CreateAnimations()
{
    if(m_FlipBook->loadFromFile("Content/spritesheet.PNG"))
    {
        //Idle animations
        AddAnimation("Anim_Idle_Up",
                        m_FlipBook,
                        GenerateIntRectFramesVector(36, 54, 1, 1, 0, 1, 1),
                        150);
        AddAnimation("Anim_Idle_Down",
                        m_FlipBook,
                        GenerateIntRectFramesVector(36, 54, 1, 1, 0, 2, 1),
                        150);
        AddAnimation("Anim_Idle_Left",
                        m_FlipBook,
                        GenerateIntRectFramesVector(36, 54, 1, 1, 0, 3, 1),
                        150);
        AddAnimation("Anim_Idle_Right",
                        m_FlipBook,
                        GenerateIntRectFramesVector(36, 54, 1, 1, 0, 4, 1),
                        150);

        //Walking animations
        AddAnimation("Anim_Walking_Up",
                        m_FlipBook,
                        GenerateIntRectFramesVector(36, 54, 1, 4, 0, 1, 1),
                        150);
        AddAnimation("Anim_Walking_Down",
                        m_FlipBook,
                        GenerateIntRectFramesVector(36, 54, 1, 4, 0, 2, 1),
                        150);
        AddAnimation("Anim_Walking_Left",
                        m_FlipBook,
                        GenerateIntRectFramesVector(36, 54, 1, 4, 0, 3, 1),
                        150);
        AddAnimation("Anim_Walking_Right",
                        m_FlipBook,
                        GenerateIntRectFramesVector(36, 54, 1, 4, 0, 4, 1),
                        150);
    }
    else
        QuitGame();
}
