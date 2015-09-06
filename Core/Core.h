//
// Created by unknown on 02.09.15.
//

#pragma once
#include "../GUI/GUI.h"

namespace Core {
    class Core final {
    private: ///////////////// Fields
        GUI::GUI mGUI;
    public:  ///////////////// Public Methods
        Core();
        ~Core();
        void Run();
    private: ///////////////// Private Methods
    };
}

