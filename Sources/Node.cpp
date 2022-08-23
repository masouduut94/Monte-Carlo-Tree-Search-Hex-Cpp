#include "../headers/Node.h"
#include <iostream>
// ###################################### UCT Node Methods


Node::Node(std::pair<int, int> inp_move, Node* parent_inp) 
{
        this->cell = inp_move;
        this->parent = parent_inp;
        this->Q = 0;
        this->N = 0;
        this->N_RAVE = 0;
        this->Q_RAVE = 0;
}

void Node::add_children(std::vector<std::pair<int, int>> list_of_children) 
{
        for (std::pair<int, int> item : list_of_children) {
                Node* node = new Node(item, this);
                this->children.push_back(node);
        }
}

void Node::display_children()
{
        if (this->children.empty()) 
        {
                return;
        }
        for (Node* ch : this->children)
        {
                printf("{Cell: '%c-%i'}", ch->get_move_char());
        }
}

double Node::value(const float explore_const, int rave_const) 
{
        /* 
        Description:
                Returns the RAVE + UCT value of node in MCTS algorithm.
        
        Note:
                If you consider using UCT, just pass -1 for RAVE_CONST.
        
        */
        if (N == 0) return GameMeta::INF;
        else 
        {
                double alpha = 0;
                double AMAF = 0.0;
                double UCT = (this->Q / this->N) + (double)(explore_const * (sqrt(log10(static_cast<double>(this->parent->N) / this->N))));
                double explore = sqrt(log10(static_cast<double>(this->parent->N) / this->N));
                if (rave_const > 0)
                {
                        alpha = std::max(0.0, (static_cast<double>(rave_const - this->N) / rave_const));
                        if (this->N_RAVE != 0)
                        {
                                AMAF = static_cast<double>(this->Q_RAVE / this->N_RAVE);
                        }
                        
                }
                return static_cast<double>((1 - alpha) * UCT + alpha * AMAF);
        }
}

std::pair<char, int> Node::get_move_char()
{
        auto a = this->cell;
        char ch = GameMeta::mapper[a.first];
        return std::pair<char, int>(ch, a.second);
}

std::pair<bool, Node*>  Node::find_child(std::pair<int, int> move) 
{
        /*  Returns the child which constructed for input move.

        */
        bool flag_found = false;
        Node* value = nullptr;

        for (Node* child : this->children)
        {
                if ((child->get_move() == move)) 
                {
                        flag_found = true;
                        value = child;
                        break;
                }
        }
        return std::make_pair(flag_found, value);
}


