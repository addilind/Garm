//
// Created by unknown on 06.09.15.
//

#include "GUI.h"
#include <glbinding/gl/gl.h>
#include <glbinding/Binding.h>
#include <GLFW/glfw3.h>

GUI::GUI::GUI()
        : mInitialized(false), mWindow(nullptr)
{

}
GUI::GUI::~GUI()
{
    if(mInitialized) {
        glfwTerminate();
    }
}
void GUI::GUI::Initialize() {
    if (!glfwInit())
        throw std::runtime_error("Can not initialize GLFW!");
    initCreateWindow();
    mInitialized = true;

    glbinding::Binding::initialize();
}

void GUI::GUI::initCreateWindow() {
    mWindow = glfwCreateWindow(640, 480, "Garm - built " __DATE__, nullptr, nullptr);
    if (!mWindow)
    {
        glfwTerminate();
        throw std::runtime_error("Can not create window!");
    }

    glfwMakeContextCurrent(mWindow);
}

bool GUI::GUI::Tick() {
    glfwSwapBuffers(mWindow);
    glfwPollEvents();
    return glfwWindowShouldClose(mWindow) != 0;
}
