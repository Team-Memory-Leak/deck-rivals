#pragma once
#include <vector>

using std::string;

class GameMap {
  private:
    unsigned int id;
    std::string name;
    std::string backgroundImagePath;
    std::string mapImagePath;
    vector<vector<int>> grid;
    unsigned int width;
    unsigned int height;
  public:
    GameMap(int width, int height, int id, const std::string &name, const std::string &backgroundImagePath, const std::string &mapImagePath); // For a Default Map
    GameMap(int width, int height, int id, const std::string &name, const std::string &backgroundImagePath, const std::string &mapImagePath, vector<vector<int>> grid); // Standard Constructor
    ~GameMap();
    GameMap(GameMap&) = delete;
    GameMap &operator=(GameMap&) = delete;

    unsigned int GetID() const;
    std::string GetName() const;

    std::string GetBackgroundImagePath() const;

    std::string GetMapImagePath() const;
};