#include "Application.hpp"
#include "Level.hpp"
#include "Object.hpp"

using namespace std;

Application::Application(string windowName, bool fullscreen, int frameRateLimit, bool verticalSync)
{
    cout << "Instancing the engine." << endl << endl;

    m_OpenedLevel = -1;

    m_Window = new sf::RenderWindow(sf::VideoMode(1920, 1080, 32), windowName, ((fullscreen) ? sf::Style::Fullscreen : sf::Style::Default));
    m_Levels = new vector<Level*>();


    m_FrameRateLimit = frameRateLimit;
    m_Window->setFramerateLimit(m_FrameRateLimit);
    m_Window->setVerticalSyncEnabled(verticalSync);
}

void Application::Start()
{
    cout << "Starting the engine." << endl << endl;

    OpenDefaultLevel();
    GameLoop();
}

void Application::GameLoop()
{
    cout << "Entering the Game Loop." << endl;

    while(m_Window->isOpen())
    {
        TriggerEventsTick();

        sf::Event event;

        while(m_Window->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                QuitGame();
        }

        m_Window->clear();
        DrawObjects();
        m_Window->display();
    }
}

void Application::TriggerEventsTick()
{
    m_Levels->at(m_OpenedLevel)->EventTick(m_TickDelta.getElapsedTime().asMilliseconds());

    vector<Object*>* objects = m_Levels->at(m_OpenedLevel)->GetObjects();

    for(unsigned int i = 0 ; i < objects->size() ; i++)
    {
        objects->at(i)->EventTick(m_TickDelta.getElapsedTime().asMilliseconds());
    }

    m_TickDelta.restart();
}

void Application::DrawObjects()
{
    vector<Object*>* objects = m_Levels->at(m_OpenedLevel)->GetObjects();

    for(unsigned int i = 0 ; i < objects->size() ; i++)
    {
        objects->at(i)->Draw(m_Window);
    }
}

void Application::AddLevel(Level* level, bool defaultLevel)
{
    m_Levels->push_back(level);

    if(defaultLevel)
        m_DefaultLevel = m_Levels->size() - 1;

    cout << "Adding level \"" << level->GetName() << "\". Default level : " << (defaultLevel ? "true" : "false") << "." << endl;
}

void Application::OpenLevel(int levelIndice)
{
    if(m_OpenedLevel >= 0)
    {
        m_Levels->at(m_OpenedLevel)->Close();
        m_Levels->at(m_OpenedLevel)->EventLevelClosed();
    }

    m_OpenedLevel = levelIndice;
    m_Levels->at(m_OpenedLevel)->Open();
    m_Levels->at(m_OpenedLevel)->EventLevelOpened();
}

void Application::OpenLevel(string levelName)
{
    OpenLevel(GetLevelIndice(levelName));
}

void Application::OpenDefaultLevel()
{
    cout << "Opening default level." << endl;
    OpenLevel(m_DefaultLevel);
}

int Application::GetLevelIndice(string levelName)
{
    for(unsigned int i = 0 ; i < m_Levels->size() ; i++)
    {
        if(levelName == m_Levels->at(i)->GetName())
            return i;
    }

    return -1;
}

void Application::QuitGame()
{
    m_Window->close();
}

//Destructor
Application::~Application()
{
    cout << "Deleting Levels." << endl;
    delete m_Levels;
}
