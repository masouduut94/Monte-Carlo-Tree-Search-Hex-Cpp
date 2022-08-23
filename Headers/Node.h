#pragma once
#include <vector>
#include "utils.h"


class Node {
private:
        std::pair<int, int> cell;
        int Q = 0;
        int N = 0;
        int N_RAVE = 0;
        int Q_RAVE = 0;
        int OUTCOME = GameMeta::GAME_ON;
        Node* parent;
        std::vector <Node*> children;

public:
        Node() {};
        ~Node() {};
        Node(std::pair<int, int> inp_move, Node* parent_inp);

        double value(const float explore_const=0.5, int rave_const=-1);
        void add_children(std::vector<std::pair<int, int>>);
        void win() { this->N++; this->Q++; }
        void loss() { this->N++; this->Q--; }
        void rave_win() { this->N_RAVE++; this->Q_RAVE++; }
        void rave_loss() { this->N_RAVE++; this->Q_RAVE--; }
        std::pair<int, int> get_move() { return this->cell; }
        std::pair<char, int> get_move_char();
        std::pair<bool, Node*> find_child(std::pair<int, int> move);
        bool has_children() { return this->children.empty(); };
        void display_children();
        Node* clone() const { return new Node(*this); }
};





