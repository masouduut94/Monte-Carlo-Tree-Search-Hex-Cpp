#pragma once
#include <math.h>
#include <map>
#include<string>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <string>
#include <utility>
#include <iostream>

struct pair_hash
{
        // Hashing function of a std::pair
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1, T2>& p) const {
                auto h1 = std::hash<T1>{}(p.first);
                auto h2 = std::hash<T2>{}(p.second);
                return h1 ^ h2;
        }
};

using Cell = std::pair<int, int>;

template <class T1, class T2>
extern bool key_exists(T1& MapData, T2& x)
{
        if (MapData.count(x) > 0)
        {
                return true;
        }
        return false;
}

template <class T1, class T2>
extern bool contains(T1 vec, T2& elem)
{
        bool result = false;
        if (std::find(vec.begin(), vec.end(), elem) != vec.end())
        {
                result = true;
        }
        return result;
};

namespace GameMeta {
        extern std::map<std::string, int> PLAYERS;
        extern std::map<std::string, int> TURN;
        extern float INF;
        extern int GAME_OVER;
        extern int GAME_ON;
        extern Cell EDGE1;
        extern Cell EDGE2;
        extern int NEIGHBOR_PATTERNS[6][2];
        extern int RAVE_CONST;
        extern int EXP_CONST;
        extern std::unordered_map<int, char> mapper;
        };




