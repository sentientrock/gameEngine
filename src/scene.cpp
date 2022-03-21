#include "scene.h"
#include "texture.h"
#include "resource_manager.h"
#include "sprite_renderer.h"

Scene::Scene()
{

}

Texture2D Scene::LoadBackground(Texture2D BackText)
{
    background = BackText;
    return BackText;
}


