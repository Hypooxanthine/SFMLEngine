#include "Object.hpp"
#include "Application.hpp"

using namespace std;

Object::Object(Application* engine)
{
    m_Engine = engine;
}

void Object::EventDestruct()
{

}

void Object::EventStart()
{

}

void Object::EventTick(float delta)
{

}

void Object::Draw(sf::RenderWindow* window)
{

}

void Object::QuitGame()
{
    if(m_Engine != NULL)
        m_Engine->QuitGame();
}


//Getters
int Object::GetZAxis()
{
    return m_ZAxis;
}


//Setters


//Destructor
Object::~Object()
{
    cout << "Deleting Object." << endl;
}
