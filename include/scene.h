#ifndef SCENE_H
#define SCENE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>

#include "texture.h"
#include "sprite_renderer.h"
#include "text_renderer.h"

//class for the scene object, has a background texture

struct sprite {
    Texture2D texture;
    float xpos, ypos, xsize, ysize, rotate, colorr, colorg, colorb;
    sprite(Texture2D spritetexture, float apos, float bpos, float size1, float size2, float srotate,  float color1, float color2, float color3)
    : texture(spritetexture), xpos(apos), ypos(bpos), xsize(size1), ysize(size2), rotate(srotate), colorr(color1), colorg(color2), colorb(color3)
    {}
};

class Scene 
{
    public:
        
        Texture2D           background;
        std::string         nextScene;
        std::string         sceneText;
        std::string         renderText;
        std::vector<sprite> sprites;
        float               sceneTime;
        int                 character;

        Scene();

        // update method for scene
        void Update(float dt);

        // sets the background scene
        Texture2D LoadBackground(Texture2D BackTex);

        // adds a sprite to the scene's sprites
        void AddSprite(Texture2D texture, float xpos, float ypos, float xsize, float ysize,
            float rotate, float colorr, float colorg, float colorb);

        // helper method to add background with default values
        void AddBackground(Texture2D texture);

        // set text of scene
        void SetText(std::string text);

        // renders the scene 
        void RenderScene(SpriteRenderer *Renderer, TextRenderer *Text);
};

#endif