#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include <iostream>
#include <SFML/Graphics.hpp>

class Level;
class Object;

class Application
{
    public:
        Application(std::string windowName, bool fullscreen = true, int frameRateLimit = 60, bool verticalSync = true);
        ~Application();

        void Start();

        void AddLevel(Level* level, bool defaultLevel = false);

        void OpenLevel(int levelIndice);
        void OpenLevel(std::string levelName);
        void OpenDefaultLevel();

        void QuitGame();

    private:
        void GameLoop();

        void DrawObjects();
        void TriggerEventsTick();

        int GetLevelIndice(std::string levelName);


        sf::RenderWindow *m_Window;
        int m_FrameRateLimit;

        std::vector<int> m_ZAxis;

        sf::Clock m_TickDelta;

        std::vector<Level*> *m_Levels;
        int m_OpenedLevel;
        int m_DefaultLevel;

    protected:

};

#endif // APPLICATION_HPP_INCLUDED
