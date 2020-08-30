#ifndef LEVEL_HPP_INCLUDED
#define LEVEL_HPP_INCLUDED

#include <iostream>
#include "Object.hpp"

class Application;

class Level
{
    public:
        Level(std::string name);
        Level (std::string name, Application* engine);
        ~Level();

        void AddObject(Object* object);

        virtual void EventLevelOpened();
        virtual void EventTick(float delta);
        virtual void EventLevelClosed();

        std::string GetName();
        std::vector<Object*>* GetObjects();

        void Open();
        void Close();

    private:

    protected:
        void OpenLevel(std::string levelName);


        Application* m_Engine;
        std::vector<Object*>* m_Objects;
        std::string m_UniqueName;
};

#endif
