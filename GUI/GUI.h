//
// Created by unknown on 06.09.15.
//

#pragma once
typedef struct GLFWwindow GLFWwindow;

namespace GUI {
    class GUI final {
    private: ///////////////// Fields
        bool mInitialized;
        GLFWwindow* mWindow;
    public:  ///////////////// Public Methods
        GUI();
        ~GUI();
        void Initialize();
        bool Tick();
    private: ///////////////// Private Methods
        void initCreateWindow();
    };
}



