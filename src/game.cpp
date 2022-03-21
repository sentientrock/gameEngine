#include "game.h"
#include "resource_manager.h"
#include "sprite_renderer.h"
#include "scene.h"
#include <iostream>


// Game-related State data
SpriteRenderer  *Renderer;


Game::Game(unsigned int width, unsigned int height) 
    : State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{ 

}

Game::~Game()
{
    delete Renderer;
}

void Game::Init()
{
    // load shaders
    ResourceManager::LoadShader("shaders/vertex", "shaders/fragment", nullptr, "sprite");
    // configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width), 
        static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // set render-specific controls
    Shader myShader;
    myShader = ResourceManager::GetShader("sprite");
    Renderer = new SpriteRenderer(myShader);
    // load textures
    ResourceManager::LoadTexture("resources/taylor worried.png", true, "char");
    ResourceManager::LoadTexture("resources/classroom light.png", true, "face");
    Scene BackScene;
    BackScene.LoadBackground(ResourceManager::GetTexture("face"));
    ResourceManager::LoadScene(BackScene, "background");
}

void Game::Update(float dt)
{
    
}

void Game::ProcessInput(float dt)
{
   
}

void Game::Render()
{
    Texture2D myTexture2;
    Texture2D myTexture1;
    myTexture1 = ResourceManager::GetScene("background").background;
    myTexture2 = ResourceManager::GetTexture("char");
    Renderer->DrawSprite(myTexture1, glm::vec2(0.0f, 0.0f), glm::vec2(static_cast<float>(this->Width), 
        static_cast<float>(this->Height)), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
    Renderer->DrawSprite(myTexture2, glm::vec2(955.0f,0.0f), glm::vec2(503.0f, 700.0f), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
}