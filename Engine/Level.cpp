#include "Level.hpp"
#include "Application.hpp"
#include "Actor.hpp"
#include "Animator.hpp"

using namespace std;

Level::Level(string name)
{
    m_UniqueName = name;

    m_Objects = new vector<Object*>();
}

Level::Level(string name, Application* engine)
{
    m_UniqueName = name;

    m_Objects = new vector<Object*>();

    m_Engine = engine;
}

void Level::AddObject(Object* object)
{
    m_Objects->push_back(object);
    cout << "Adding object to " << m_UniqueName << "." << endl;

    Actor* asActor = dynamic_cast<Actor*>(object);

    if(asActor != NULL)
    {
        m_Objects->push_back(asActor->GetAnimator());
        asActor->GetAnimator()->EventStart();
    }

    object->EventStart();
}

void Level::EventLevelOpened()
{

}

void Level::EventTick(float delta)
{

}

void Level::EventLevelClosed()
{

}

void Level::OpenLevel(string levelName)
{
    if(m_Engine != NULL)
        m_Engine->OpenLevel(levelName);
}

void Level::Open()
{
    cout << "Opening level \"" << m_UniqueName << "\"." << endl;
}

void Level::Close()
{
    cout << endl << "Exiting level \"" << m_UniqueName << "\"." << endl;
}


//Getters
string Level::GetName()
{
    return m_UniqueName;
}

vector<Object*>* Level::GetObjects()
{
    return m_Objects;
}


//Destructor
Level::~Level()
{
    cout << "Deleting Objects from level \"" << m_UniqueName << "\"." << endl;

    delete m_Objects;
}
