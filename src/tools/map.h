#pragma once

#include "../core/config.h"

using namespace tinyxml2;

class Map
{
public:
    int width, height, tileWidth, tileHeight, pixelWidth, pixelHeight;
    tinyxml2::XMLDocument doc;
    XMLElement *mapElement;
    string source;
    SDL_Renderer *renderer = nullptr;
    struct Layer
    {
        int width, height;
        string num, csvText;
        vector<int> gids;
        XMLElement *dataElement;
    };
    struct Tileset
    {
        int firstGID, columns, rows;
        Image *image;
    };
    struct Object
    {
        string name;
        float x, y, width, height;
    };
    struct ObjectGroup
    {
        vector<Object> objects;
    };
    vector<Layer> layers;
    Tileset tileset;
    ObjectGroup objectGroup;
    Map(SDL_Renderer *renderer, string source);
    void loadLayer(XMLElement *child);
    void loadTileset(XMLElement *child);
    void loadObjectGroup(XMLElement *child);
    void render(Vector2D Camera);
    ~Map();
};