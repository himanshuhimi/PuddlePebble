#include "../sprite.h"

Sprite::Sprite(SDL_Renderer *renderer, string imgSource, float x, float y)
{
    image = new Image(renderer, imgSource);
    SDL_GetTextureSize(image->texture, &rect.w, &rect.h);
    Position = Vector2D{x - rect.w / 2, y};
    rect.x = Position.x;
    rect.y = Position.y;
}

void Sprite::handle(double dt)
{
    Position.x += Velocity.x * dt;
    Position.y += Velocity.y * dt;
    rect.x = Position.x;
    rect.y = Position.y;
}

void Sprite::render(Vector2D Camera)
{
    SDL_FRect dst = rect;
    dst.x -= Camera.x;
    dst.y -= Camera.y;
    image->render(nullptr, &dst);
}