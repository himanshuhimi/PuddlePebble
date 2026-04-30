#pragma once

#include "map.h"
#include "../sprites/grass.h"
#include "../sprites/player.h"

class Level
{
public:
    Player player;
    vector<Grass> grasses;
    Map map;
    Vector2D Camera;
    Level(SDL_Renderer *renderer, int number);
    void render();
    void handle(double dt);
};