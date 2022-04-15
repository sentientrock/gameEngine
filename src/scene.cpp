#include <iostream>

#include "scene.h"
#include "texture.h"
#include "resource_manager.h"
#include "sprite_renderer.h"

Scene::Scene() : sceneTime(0.0), character(0)
{
    std::vector<sprite> spriteList;
    sprites = spriteList;
}

void Scene::Update(float dt)
{
    sceneTime+= dt;
    if (sceneTime >= 0.05 && renderText.length() != sceneText.length()) {
        renderText = renderText + sceneText[character];
        sceneTime = 0;
        character++;
    }

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

void Scene::SetText(std::string text)
{
    sceneText = text;
    renderText = "";
}

void Scene::RenderScene(SpriteRenderer *Renderer, TextRenderer *Text)
{
    for (auto i : sprites) {
        Renderer->DrawSprite(i.texture, glm::vec2(i.xpos, i.ypos), glm::vec2(i.xsize, i.ysize), 
        i.rotate, glm::vec3(i.colorr, i.colorg, i.colorb));
    }
    Text->RenderText(renderText, 200.0f, 200.0f, 1.0f);
}

