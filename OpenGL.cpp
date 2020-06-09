//
//  OpenGL.cpp
//  OpenGL
//
//  Created by Crunchy on 6/4/20.
//  Copyright © 2020 AnOrganization. All rights reserved.
//

#include "OpenGL.h"
#include <stdexcept>

/*
// Static Variable(s)
//
/////////////////////////////////*/
OpenGL * OpenGL::_instance = NULL;
GLFWwindow * OpenGL::_window = NULL;

volatile bool OpenGL::_initGLFW = false;
volatile bool OpenGL::_initGLAD = false;

/*
// Constructor / Destructor
//
/////////////////////////////////*/
OpenGL::~OpenGL()
{
    if (_initGLFW)
        glfwTerminate();
}

/*
// Static Methods
//
/////////////////////////////////*/
void OpenGL::Init(uint32_t major, uint32_t minor)
{
    if (!_initGLFW)
    {
        // Initialize GLFW
        /*---------------------------------*/
        if (glfwInit() == GLFW_TRUE)
        {
            _initGLFW = true;

            // Define version and compatibility settings
            /*---------------------------------*/
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
            glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
                
#ifdef __APPLE__
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
        }
    }
}

OpenGL * OpenGL::Instance()
{
    if (!_instance)
        _instance = new OpenGL;
    
    return _instance;
}

/*
// Window
//
/////////////////////////////////*/
GLFWwindow * OpenGL::Window()
{
    return _window;
}

GLFWwindow * OpenGL::CreateWindow(int width, int height, const char * name)
{
    _window = glfwCreateWindow(width, height, name, NULL, NULL);
    if (_window)
    {
//        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//            throw new std::runtime_error("[glad] Failed to initialize");
    }
    return _window;
}

void OpenGL::_framebufferCallback(GLFWwindow * window, int width, int height)
{
    glViewport(0, 0, width, height);
}
