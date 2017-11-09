//
// Created by XONCRY on 12.10.2017.
//
#include <map>
#include <SFML/Graphics/RenderWindow.hpp>

#ifndef LAZCORN_MACHINE_H
#define LAZCORN_MACHINE_H

class State;

class Machine {
public:
    enum class StateId{ //Write state namn
        level_1,
        MENU,
        INIT,
        EXIT
    };

    Machine();
    ~Machine();

    void GoNext(sf::RenderWindow* window);
    void SetState(StateId state);
    bool GetRunning() const { return running; }
    void SetRunning(bool running) { this->running = running; }
    State* GetState();

protected:
    bool running;
    StateId state;
    std::map<StateId, State*> states;
};

#endif //LAZCORN_MACHINE_H
