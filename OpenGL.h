//
//  OpenGL.h
//  OpenGL
//
//  Created by Crunchy on 6/4/20.
//  Copyright © 2020 AnOrganization. All rights reserved.
//

#ifndef OpenGL_h
#define OpenGL_h

#include <stddef.h>
#include <glad/3.3/glad.h>
#include <GLFW/glfw3.h>

class OpenGL
{
public:
    ~OpenGL();
    static void Init(uint32_t major =3, uint32_t minor =3);
    static OpenGL * Instance();
    
    static GLFWwindow * CreateWindow(int, int, const char *);
    static GLFWwindow * Window();
    
private:
    OpenGL() {};
    OpenGL(const OpenGL& copy) {};
    OpenGL& operator=(OpenGL const&);
    
    // Variables
    static OpenGL * _instance;
    static GLFWwindow * _window;
    
    static volatile bool _initGLFW;
    static volatile bool _initGLAD;
    
    // Methods
    void _framebufferCallback(GLFWwindow *, int, int);
};

#endif /* OpenGL_h */
