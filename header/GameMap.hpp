#pragma once
#include <vector>
#include <string>

using std::string;
using std::vector;

class GameMap {
  private:
    unsigned int id;
    string name;
    string backgroundImagePath;
    string mapImagePath;
    vector<vector<int>> grid;
    unsigned int width;
    unsigned int height;
  public:
    GameMap(int width, int height, int id, const string &name, const string &backgroundImagePath, const string &mapImagePath); // For a Default Map
    GameMap(int width, int height, int id, const string &name, const string &backgroundImagePath, const string &mapImagePath, vector<vector<int>> grid); // Standard Constructor
    ~GameMap();
    GameMap(GameMap&) = delete;
    GameMap &operator=(GameMap&) = delete;

    unsigned int GetID() const;
    string GetName() const;

    string GetBackgroundImagePath() const;

    string GetMapImagePath() const;
};