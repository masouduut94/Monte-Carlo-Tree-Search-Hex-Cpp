#include <gtest/gtest.h>
#include <vector>
#include "../headers/GameState.h"

//TEST(TestGameState, TestGameStateInitialization) {
//
//        // Test initializations.
//        GameState state(8);
//        state.set_board(10);
//
//        ////test if it is initialized with white taking first move.
//        //int turn = state.get_turn();
//        //ASSERT_EQ(turn, GameMeta::TURN["white"]);
//
//        //// Test if setting turn manually is working
//        //state.set_turn(2);
//        //ASSERT_EQ(state.get_turn(), GameMeta::TURN["black"]);
//
//        //// Test GameState.play
//        //Cell move(1, 1);
//        //state.play(move);
//
//        //// Check if the cell is taken by player.
//        //std::vector <std::vector<int>> board = state.get_board();
//        //std::cout << board[1][1] << std::endl;
//        //ASSERT_EQ(board[1][1], GameMeta::TURN["black"]);
//}

TEST(TestGameState, TestGameStateFindNeighborCells) 
{

        /**********   TEST1: GameState::neighbors()    ***********/
        // Test initializations.
        GameState state;
        state.set_size(3);
        std::vector<Cell> all_cells;

        for (size_t i = 0; i <= state.get_size(); i++)
        {
                for (size_t j = 0; j <= state.get_size(); j++)
                {
                        Cell move(i, j);
                        all_cells.push_back(move);
                }
        }

        // Check the number of cells first.
        std::vector<Cell> neighbors = state.neighbors(all_cells[0]);
        ASSERT_EQ(neighbors.size(), 2);
}

TEST(TestGameState, TestGameStateAvailableMoves)
{
        // Test initializations.
        GameState state;
        state.set_size(3);
        std::vector<Cell> all_cells;

        for (size_t i = 0; i <= state.get_size(); i++)
        {
                for (size_t j = 0; j <= state.get_size(); j++)
                {
                        Cell move(i, j);
                        all_cells.push_back(move);
                }
        }

        /**********   TEST2: GameState::get_moves()    ***********/
        // Let's play a move and check if available moves are any different.
        state.play(all_cells[0]);
        std::vector<Cell> available_moves = state.get_moves();
        ASSERT_EQ(available_moves.size(), all_cells.size() - 1);

}


TEST(TestGameState, TestGameStateChainingRule)
{
        // We want to test UnionFind module that whether it is detecting the connection between 2 sides for 
        // both black and white players.

        /**********   TEST3: GameState::winner    ***********/

        GameState state;
        state.set_size(3);
        state.reset_board(3);

        // Cells to test chaining rule from Left to Right (Black Player)
        Cell m1(0, 0);
        Cell m2(0, 1);
        Cell m3(0, 2);

        // Cells to test chaining rule from Top to Bottom (white Player)
        Cell m4(0, 0);
        Cell m5(1, 0);
        Cell m6(2, 0);

        state.place_black(m1);
        int w = state.winner();
        ASSERT_EQ(GameMeta::PLAYERS["none"], w);

        state.place_black(m2);
        w = state.winner();
        ASSERT_EQ(GameMeta::PLAYERS["none"], w);

        state.place_black(m3);
        w = state.winner();
        ASSERT_EQ(GameMeta::PLAYERS["black"], w);

        // Test the GameState::clone() 
        // Check if GameState::clone creates a new object and the values of original GameState are not changing.

        state.reset_board(3);
        GameState state_copy(state);
        //std::cout << "INIT STATE: " << state.winner() << std::endl;
        state.place_black(m1);
        state.place_black(m2);
        state.place_black(m3);
        /*std::cout << "######################" << std::endl;
        std::cout << "STATE" << std::endl;*/

        //state.unionfind_display();
        /*std::cout << "######################" << std::endl;
        std::cout << "NEW STATE" << std::endl;*/
        state_copy.place_white(m4);
        state_copy.place_white(m5);
        state_copy.place_white(m6);
        //state_copy.unionfind_display();
        //state.play(m3);
        /*std::cout << "AFTER 3 Black moves |  STATE: " << state.winner() << std::endl;
        std::cout << "NEW STATE: " << state_copy.winner() << std::endl;*/
        ASSERT_EQ(state_copy.winner(), GameMeta::PLAYERS["white"]);


}