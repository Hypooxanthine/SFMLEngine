#ifndef OBJECT_HPP_INCLUDED
#define OBJECT_HPP_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>

class Application;

class Object
{
    public:
        Object();
        Object(Application* engine);
        ~Object();

        virtual void Draw(sf::RenderWindow* window);
        int GetZAxis();

        virtual void EventTick(float delta);
        virtual void EventStart();
        virtual void EventDestruct();

    private:
        Application* m_Engine;

    protected:
        void QuitGame();


        int m_ZAxis;
};

#endif // OBJECT_HPP_INCLUDED
