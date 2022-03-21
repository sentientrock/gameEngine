#ifndef SCENE_H
#define SCENE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

#include "texture.h"

//class for the scene object, has a background texture

class Scene 
{
    public:
        
        Texture2D      background;
        std::string    nextScene;

        Scene();

        // sets the background scene
        Texture2D LoadBackground(Texture2D BackTex);


};

#endif