#include <map>
#include <unordered_map>
#include "../headers/utils.h"


std::map<std::string, int> GameMeta::PLAYERS = {
            {"none",  0},
            {"white", 1},
            {"black", 2}
};
std::map<std::string, int> GameMeta::TURN = {
            {"white", 1},
            {"black", 2}
};
float GameMeta::INF = INFINITY;
int GameMeta::GAME_OVER = -1;
int GameMeta::GAME_ON = 1;

Cell GameMeta::EDGE1 = { 100, 100 };
Cell GameMeta::EDGE2 = { 200, 200 };
int GameMeta::RAVE_CONST = 300;
int GameMeta::EXP_CONST = 0.5;

int GameMeta::NEIGHBOR_PATTERNS[6][2] = {
        {-1, 0},
        {0, -1},
        {-1, 1},
        {0, 1},
        {1, 0},
        {1, -1}
};
std::unordered_map<int, char> GameMeta::mapper = {
    {0, 'A'},
    {1, 'B'},
    {2, 'C'},
    {3, 'D'},
    {4, 'E'},
    {5, 'F'},
    {6, 'G'},
    {7, 'H'},
    {8, 'I'},
    {9, 'J'},
    {10, 'K'},
    {11, 'L'},
    {12, 'M'},
    {13, 'N'},
    {14, 'O'},
    {15, 'P'},
    {16, 'Q'},
    {17, 'R'},
    {18, 'S'},
    {19, 'T'},
    {20, 'U'},
    {21, 'V'},
    {22, 'W'},
    {23, 'X'},
    {24, 'Y'},
    {25, 'Z'},
};

