//
//  main.cpp
//  OpenGL
//
//  Created by Crunchy on 6/4/20.
//  Copyright © 2020 AnOrganization. All rights reserved.
//

#include <iostream>
#include "OpenGL.h"

int main(int argc, const char * argv[])
{
    OpenGL * opengl = OpenGL::Instance();
    if (!opengl)
    {
        std::cerr << "Unable To Initialize GLFW!" << std::endl;
        return 1;
    }
    
    std::cout << "Completed" << std::endl;
    return 0;
}
