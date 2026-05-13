#include "../fruit.h"

Fruit::Fruit(SDL_Renderer *renderer, float x, float y)
    : Sprite(renderer, "fruit.png", x, y) {}

void Fruit::render(Vector2D Camera)
{
    if (taken)
        return;
    Sprite::render(Camera);
}