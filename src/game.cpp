#include "game.h"
#include "resource_manager.h"
#include "sprite_renderer.h"
#include "scene.h"
#include "text_renderer.h"
#include <iostream>


// Game-related State data
SpriteRenderer  *Renderer;
TextRenderer    *Text;

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
    ResourceManager::LoadTexture("resources/bedroom.png", true, "secondBack");
    Scene BackScene;
    Scene NextScene;
    BackScene.AddBackground(ResourceManager::GetTexture("face"));
    BackScene.AddSprite(ResourceManager::GetTexture("char"), 955.0f, 0.0f, 503.0f, 700.0f, 0.0f, 1.0f, 1.0f, 1.0f);
    NextScene.AddBackground(ResourceManager::GetTexture("secondBack"));
    NextScene.AddSprite(ResourceManager::GetTexture("char"), 955.0f, 0.0f, 503.0f, 700.0f, 0.0f, 1.0f, 1.0f, 1.0f);
    ResourceManager::LoadScene(BackScene, "background");
    ResourceManager::LoadScene(NextScene, "nextScene");
    ResourceManager::SetCurrentScene(BackScene);

    Text = new TextRenderer(this->Width, this->Height);
    Text->Load("fonts/LilitaOne-Regular.ttf", 50);
}

void Game::Update(float dt)
{
    if (Keys[GLFW_KEY_W]) {
        ResourceManager::SetCurrentScene(ResourceManager::GetScene("nextScene"));
    }
    
}

void Game::ProcessInput(float dt)
{
   
}

void Game::Render()
{
    Scene myTexture1 = ResourceManager::GetCurrentScene();
    myTexture1.RenderScene(Renderer, Text);
}