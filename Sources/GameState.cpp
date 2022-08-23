#include "../headers/GameState.h"

// ####################################### GameState Module...

void GameState::reset_board(int inp_size) {
        /*
        * Description:
        *       This function initializes the game board.
        *
        * Args:
        *        inp_size(int)
        */

        this->set_size(inp_size);
        this->board.clear();

        std::vector<int> v1;

        for (int i = 0; i <= this->size; i++)
        {
                v1.clear();
                for (int j = 0; j <= this->size; j++)
                {
                        v1.push_back(0);
                }
                this->board.push_back(v1);
        }

        this->white_played = 0;
        this->black_played = 0;
        this->white_groups.reset();
        this-> black_groups.reset();
        std::vector<Cell> vec = { GameMeta::EDGE1 , GameMeta::EDGE2 };
        this->white_groups.set_ignored_element(vec);
        this->black_groups.set_ignored_element(vec);
}

void GameState::set_turn(int turn_inp) {
        /*
        * Description:
        *       Manually sets the turn.
        *
        * Args:
        *       turn_inp(int): if equals to 1 -> white  |  if equals to 2 -> black.
        */
        turn = turn_inp;
}

void GameState::play(Cell move) {
        /*
        * Description:
        *       Playing a move by placing white/black stone on the game board.
        *
        * Args:
        *       move(Move object)
        */

        if (this->turn == GameMeta::TURN["white"])
        {
                this->place_white(move);
                this->set_turn(GameMeta::TURN["black"]);
        }
        else
        {
                this->place_black(move);
                this->set_turn(GameMeta::TURN["white"]);
        }
}

void GameState::place_white(Cell move) {
        /*
        Description:
                Places the white stone on cell and changes the turn to black
        Args:
                move(Move object)
        */

        if (this->board[move.first][move.second] == GameMeta::PLAYERS["none"])
        {
                this->board[move.first][move.second] = GameMeta::PLAYERS["white"];
                this->white_played += 1;
        }
        else {
                printf("The cell is occupied before.");
        }

        // 2. Deal with chaining cells.
        // 2.1 First check for edge touch and join accordingly if needed.
        if (move.first == 0)
        {
                this->white_groups.join(GameMeta::EDGE1, move);
        }
        if (move.first == this->size)
        {
                this->white_groups.join(GameMeta::EDGE2, move);
        }

        // 2.2 Then check for neighbor cells touch and join them to a group
        std::vector<Cell> neighbors = this->neighbors(move);
        for (Cell cell : neighbors)
        {
                if (this->board[cell.first][cell.second] == GameMeta::PLAYERS["white"])
                {
                        this->white_groups.join(cell, move);
                }
        }

}

void GameState::place_black(Cell move) {
        /*
        Description:
                Places the black stone on cell and changes the turn to white
        Args:
                move(Move object)
        */
        if (this->board[move.first][move.second] == GameMeta::PLAYERS["none"]) {
                this->board[move.first][move.second] = GameMeta::PLAYERS["black"];
                this->white_played += 1;
        }
        else {
                printf("The cell is occupied before.");
        }
       
        // 2. Deal with chaining cells.
        // 2.1 First check for edge touch and join accordingly if needed.
        if (move.second == 0)
        {
                this->black_groups.join(GameMeta::EDGE1, move);
        }
        if (move.second == this->size)
        {
                this->black_groups.join(GameMeta::EDGE2, move);
        }

        // 2.2 Then check for neighbor cells touch and join them to a group
        std::vector<Cell> neighbors = this->neighbors(move);
        for (Cell cell : neighbors)
        {
                if (this->board[cell.first][cell.second] == GameMeta::PLAYERS["black"])
                {
                        this->black_groups.join(cell, move);
                }
        }
}

std::vector<Cell> GameState::get_moves() {
        /*
        Description:
                Returns list of unoccupied cells
        */
        std::vector<Cell> unoccupied_cells;
        for (int i = 0; i <= this->get_size(); i++)
        {
                for (int j = 0; j <= this->get_size(); j++)
                {
                        if (this->board[i][j] == GameMeta::PLAYERS["none"])
                        {
                                Cell move = { i, j };
                                unoccupied_cells.push_back(move);
                        }
                }
        }
        return unoccupied_cells;
}

std::string GameState::print_board() {
        // Prints a string of the board.
        // white player -> O (board left/right)  
        // black player -> @ (board up/down) 
        // No player -> .

        std::string board_map = "";
        std::string white = "O";
        std::string black = "@";
        std::string empty = ".";
        std::string ret = "\n";



        // https://github.com/kenjyoung/mopyhex/blob/763cc4f20472be131fa01ce9ba5052cb1ddf191c/gamestate.py#L127

        return "NOTHING";
}

std::vector<Cell> GameState::neighbors(Cell cell) {
        /*
        * Description:
        *       Returns all the unoccupied cells around input cell.
        *
        * Args:
        *       cell(Move object)
        *
        */
        auto x = cell.first;
        auto y = cell.second;

        bool flag_x_lt, flag_x_gt, flag_y_lt, flag_y_gt;
        std::vector<Cell> neighbor_cells;
        for (auto item : GameMeta::NEIGHBOR_PATTERNS)
        {
                flag_x_gt = item[0] + x >= 0;
                flag_x_lt = item[0] + x <= this->size;
                flag_y_lt = item[1] + y >= 0;
                flag_y_gt = item[1] + y <= this->size;


                if ((flag_x_gt && flag_x_lt) && (flag_y_gt && flag_y_lt))  // TODO: Double-check if this comparison is working
                {
                        Cell move = { x + item[0], y + item[1] };
                        neighbor_cells.push_back(move);
                }
        }

        return neighbor_cells;
}

int GameState::winner()
{
        if (this->white_groups.connected(GameMeta::EDGE1, GameMeta::EDGE2)) { return GameMeta::PLAYERS["white"]; }
        else if (this->black_groups.connected(GameMeta::EDGE1, GameMeta::EDGE2)) { return GameMeta::PLAYERS["black"]; }
        else { return GameMeta::PLAYERS["none"]; }
}

void GameState::unionfind_display()
{
        std::cout << "WHITE GROUPS" << std::endl;
        this->white_groups.show_parents();
        
        std::cout << "BLACK GROUPS" << std::endl;
        this->black_groups.show_parents();
}
