#include <iostream>

#include "scene.h"
#include "texture.h"
#include "resource_manager.h"
#include "sprite_renderer.h"

Scene::Scene()
{
    std::vector<sprite> spriteList;
    sprites = spriteList;
}

Texture2D Scene::LoadBackground(Texture2D BackText)
{
    background = BackText;
    return BackText;
}

void Scene::AddSprite(Texture2D texture, float xpos, float ypos, float xsize, float ysize, float rotate, float colorr, float colorg, float colorb)
{
    sprites.push_back(sprite(texture, xpos, ypos, xsize, ysize, rotate, colorr, colorg, colorb));
}

void Scene::AddBackground(Texture2D texture)
{
    this->AddSprite(texture, 0.0f, 0.0f, 1458.0f, 700.0f, 0.0f, 1.0f, 1.0f, 1.0f);
}

void Scene::RenderScene(SpriteRenderer *Renderer, TextRenderer *Text)
{
    for (auto i : sprites) {
        Renderer->DrawSprite(i.texture, glm::vec2(i.xpos, i.ypos), glm::vec2(i.xsize, i.ysize), 
        i.rotate, glm::vec3(i.colorr, i.colorg, i.colorb));
        Text->RenderText("THIS IS SOME TEXT", 100.0f, 300.0f, 3.0f, glm::vec3(0.0f,0.0f,0.0f));
    }
}

