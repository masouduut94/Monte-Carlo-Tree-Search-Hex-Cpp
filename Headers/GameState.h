#include <vector>
#include "UnionFind.h"

#pragma once
class GameState {
        /*
        * Description:
        *       Stores information representing the current state of a game of hex, namely
        *       the board and the current turn.
        *       Also provides functions for playing game.
        */
private:
        int size = 8;
        int turn = GameMeta::PLAYERS["white"];
        std::vector<std::vector<int>> board;
        int white_played = 0;
        int black_played = 0;
        UnionFind white_groups;
        UnionFind black_groups;

public:
        /*GameState();*/
        GameState()
        {
                this->set_turn(GameMeta::TURN["white"]);
                this->reset_board(this->size);
                int white_played = 0;
                int black_played = 0;
                UnionFind white_groups;
                UnionFind black_groups;
                std::vector<Cell> vec = { GameMeta::EDGE1 , GameMeta::EDGE2 };
                white_groups.set_ignored_element(vec);
                black_groups.set_ignored_element(vec);
        };
        GameState(GameState  &sample)
        {
                // TRY THIS https://stackoverflow.com/questions/12902751/how-to-clone-object-in-c-or-is-there-another-solution
                // TRY THIS https://www.techiedelight.com/how-to-clone-objects-in-cpp/
                this->size = sample.size;
                this->board = sample.board;
                this->turn = sample.turn;
                this->white_played = sample.white_played;
                this->black_played = sample.black_played;
                this->white_groups = UnionFind(sample.white_groups);
                this->black_groups = UnionFind(sample.black_groups);
        };

        /*GameState& operator=(GameState sample) 
        {
                this->size = sample.size;
                this->board = sample.board;
                this->turn = sample.turn;
                this->white_played = sample.white_played;
                this->black_played = sample.black_played;
                this->white_groups = sample.white_groups;
                this->black_groups = sample.black_groups;
        }*/

        void set_size(int inp_size) { this->size = inp_size - 1; }
        int get_size() { return this->size; }

        void set_turn(int turn);
        int get_turn() { return this->turn; }

        int get_white_played() { return this->white_played; }
        int get_black_played() { return this->black_played; }

        void reset_board(int inp_size);
        std::vector<std::vector<int>> get_board() { return this->board; }

        void play(Cell move);
        void place_white(Cell move);
        void place_black(Cell move);
        std::vector<Cell> get_moves();
        std::string print_board();
        std::vector<Cell> neighbors(Cell move);
        //GameState* clone() { return new GameState(*this); }
        int winner();
        void unionfind_display();
};

