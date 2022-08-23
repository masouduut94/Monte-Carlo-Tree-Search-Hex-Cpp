#include <gtest/gtest.h>
#include <vector>
#include "../headers/Node.h"


TEST(TestNode, TestRootNode) {
        // Testing Constructor
        Cell move(3, 5);
        Node root(move, nullptr);

        // Testing Node::add_children.
        Cell ch1 (1, 2);
        Cell ch2 (3, 4);
        Cell ch3 (10, 4);
        Cell ch4 (22, 5);

        std::vector<Cell> moves = { ch1, ch2, ch3 };
        root.add_children(moves);

        // Testing Node::find_child   if found
        std::pair<bool, Node*> output;
        output = root.find_child(ch1);
        bool is_found = output.first;
        Cell move1 = output.second->get_move();

        ASSERT_EQ(is_found, true);
        ASSERT_EQ(ch1, move1);

        // Testing Node::find_child if not found

        output = root.find_child(ch4);
        is_found = output.first;
        //Cell move4 = output.second->get_move();
        
        ASSERT_EQ(is_found, false);

        // root.display_children();

        // Test node value UCT




        // Test Node value RAVE



}



