//
// Created by unknown on 02.09.15.
//

#include "Core.h"

Core::Core::Core()
    : mGUI()
{

}

Core::Core::~Core() {

}

void Core::Core::Run() {
    mGUI.Initialize();

    bool run = true;
    while(run) {
        run = run && !mGUI.Tick();
    }
}
