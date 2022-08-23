#include <iostream>
#include <vector>
#include <unordered_map>
#include "utils.h"
#include <functional>
#include<algorithm>
#pragma once

using Cell2ParentMap = std::unordered_map<Cell, Cell, pair_hash>;
using Cell2RankMap = std::unordered_map<Cell, int, pair_hash>;
using Cell2Groups = std::unordered_map<Cell, std::vector<Cell>, pair_hash>;

// A class to represent a disjoint set  (UnionFind)
class UnionFind
{
private:
        Cell2ParentMap parent;
        // stores the depth of trees
        Cell2RankMap rank;
        Cell2Groups groups;
        std::vector <Cell> ignored;

public:
        UnionFind()
        {
                Cell2ParentMap parent={};
                // stores the depth of trees
                Cell2RankMap rank={};
                Cell2Groups groups={};
                std::vector <Cell> ignored={};
        };
        ~UnionFind() {};

        UnionFind(UnionFind& sample) 
        {
                this->parent = sample.parent;
                this->rank = sample.rank;
                this->groups = sample.groups;
                this->ignored = sample.ignored;
        };

        /*UnionFind& operator=(UnionFind &sample)
        {
                this->parent = sample.parent;
                this->rank = sample.rank;
                this->groups = sample.groups;
                this->ignored = sample.ignored;
        }*/


        bool join(Cell x, Cell y);
        Cell find(Cell x);
        bool connected(Cell x, Cell y);
        void set_ignored_element(std::vector<Cell> ignore);
        Cell2Groups get_groups();
        void reset();
        void show_parents(); // TODO;
};
