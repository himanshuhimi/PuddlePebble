#include "../level.h"

Level::Level(SDL_Renderer *renderer, int number)
    : player(renderer, 0, 0),
      map(
          renderer,
          "maps/" + std::to_string(number - 1) + ".tmx")
{
    for (Map::Object obj : map.objectGroup.objects)
    {
        const char *name = obj.name.c_str();
        if (!strcmp(name, "player"))
            player = Player(renderer, obj.x, obj.y - SPRITE_SIZE);
        else if (!strcmp(name, "grasses"))
            for (int x = 0; x < obj.width; x += SPRITE_SIZE)
                grasses.push_back(Grass(renderer, x, obj.y));
    }
}

void Level::render() 
{
    map.render(Camera);
    for (auto grass : grasses)
        grass.render(Camera);
    player.render(Camera);
}

void Level::handle(double dt) 
{
    player.handle(dt, grasses);
    float targetX = player.Position.x - CAMERA_X;
    float targetY = player.Position.y - CAMERA_Y;
    float maxX = std::max<float>(0.0f, map.pixelWidth - WIDTH);
    float maxY = std::max<float>(0.0f, map.pixelHeight - HEIGHT);
    Camera.x = std::clamp(targetX, 0.0f, maxX);
    Camera.y = std::clamp(targetY, 0.0f, maxY);
}