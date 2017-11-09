#include "machine.h"
#include "state.h"
#include "states/level_1.h"
#include "states/menu.h"
#include "states/stateInit.h"
#include "states/stateExit.h"

Machine::Machine(){
    running = true;

    state = StateId::INIT;

    //Write states
    //states.emplace(StateId::(nameofstate), new State(name));
    states.emplace(StateId::INIT, new StateInit());
    states.emplace(StateId::MENU, new StateMenu());
    states.emplace(StateId::EXIT, new StateExit());
    states.emplace(StateId::level_1, new level_1());
}

Machine::~Machine() {
    //Remove state from memory
    for(auto state: states){
        delete state.second;
    }

    states.clear();
}

void Machine::GoNext(sf::RenderWindow* window) {
    states[state]->GoNext(*this, window);
}

void Machine::SetState(StateId state) {
    this->state = state;
}

State* Machine::GetState() {
    return states[state];
}