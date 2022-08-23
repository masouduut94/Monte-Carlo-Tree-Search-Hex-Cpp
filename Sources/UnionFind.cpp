#include "../headers/UnionFind.h"


bool UnionFind::join(Cell x, Cell y) 
{
        Cell rep_x = this->find(x);
        Cell rep_y = this->find(y);

        // if they are in the same group, so no join is necessary.
        if (rep_x == rep_y) { return false; } 

        // if x rank is lower than y, set y = parent(x).
        if (this->rank[rep_x] < this->rank[rep_y]) 
        {
                this->parent[rep_x] = rep_y;
                for (auto item : this->groups[rep_x]) 
                {
                        this->groups[rep_y].emplace_back(item);
                }
        }
        else if (this->rank[rep_x] > this->rank[rep_y])
        {
                this->parent[rep_y] = rep_x;
                for (auto item : this->groups[rep_y])
                {
                        this->groups[rep_x].emplace_back(item);
                }
        }
        else 
        {
                this->parent[rep_x] = rep_y;
                this->rank[rep_x] += 1;
                for (auto item : this->groups[rep_y])
                {
                        this->groups[rep_x].emplace_back(item);
                }
        }
}

Cell UnionFind::find(Cell x)
{
        if (!key_exists(this->parent, x))
        {
                this->parent[x] = x;
                this->rank[x] = 0;
                if (contains(this->ignored, x))
                {
                        this->groups[x] = {};
                }
                else
                {
                        this->groups[x] = {x};
                }
        }
        Cell px = this->parent[x];

        if (x==px)
        {
                return x;
        }

        Cell gx = this->parent[px];
        
        if (gx==px)
        {
                return px;
        }

        this->parent[x] = gx;

        return this->find(gx);
}

bool UnionFind::connected(Cell x, Cell y)
{
        return (this->find(x) == this->find(y));
}

void UnionFind::set_ignored_element(std::vector<Cell> ignore)
{
        this->ignored = ignore;
}

Cell2Groups UnionFind::get_groups()
{
        return this->groups;
}

void UnionFind::reset() 
{
        this->rank = {};
        this->parent = {};
        this->groups = {};
        this->ignored = {};
};

void UnionFind::show_parents() 
{
        for (auto item : this->groups)
        {
                std::cout << "P: (" << item.first.first << " , " << item.first.second << ") => ";
                for (Cell item2 : item.second) 
                {
                        std::cout << "C: ( " << item2.first << " , " << item2.second << ") | ";
                }
                std::cout << std::endl;
        }
};
