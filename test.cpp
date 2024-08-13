
/*#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#define private public
#include "../src/AVL.h"
#include "../src/CodeRunner.h"
#include "math.h"

	/*To check output (At the Project1 directory):
		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp && build/test


TEST_CASE("BST Insert", "[flag]"){//INSERT 3 INCORRECT
        Tree tree;   // Create a Tree object
        runMyCode run;

        //TEST 1 -->
        //Name and string are incorrect for insertion
        string name1= "A11y";
        string ID1= "1";
        if (run.isUFID(ID1)&& run.isAName(name1)){
            tree.insert(name1, ID1);
        }
        //name correct but ID incorrect
        string name2= "betty";
        string ID2= "1234567";
        if (run.isUFID(ID2)&& run.isAName(name2)){
            tree.insert(name2, ID2);
        }
        //name incorrect ID correct
        string name3= "bett8";
        string ID3= "12345678";
        if (run.isUFID(ID3)&& run.isAName(name3)){
            tree.insert(name3, ID3);
        }

        int count2= tree.numOfNodes();
        REQUIRE(count2 ==0);
}

TEST_CASE("Remove Non-existant Node", "[flag]"){//EDGE CASE
    Tree tree;
    Node* node= tree.remove(tree.root, "12345678");
    REQUIRE(node == nullptr);
}

TEST_CASE("Remove In Order Node that does Not Exist"){//EDGE CASE
    Tree tree;
    tree.insert("Sydney", "33333300");
    tree.removeInorder(tree.root, 1);
    vector<string> actualOutput;
    tree.printInorder(tree.root, actualOutput);
    vector<string> expectedOutput = {"Sydney"};
    REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Check to make sure a blank tree has a level count of 0"){//EDGE CASE
    Tree tree;
    int actualLevelCount= tree.printLevelCount(tree.root);
    int expectedLevelCount=0;
    REQUIRE(actualLevelCount== expectedLevelCount);
}

TEST_CASE("Test All 4 Rotation Cases--> Left Left Imbalance"){
    Tree tree;
    tree.insert("Sydney", "33333300");
    tree.insert("Bob", "22222200");
    tree.insert("Billy", "11111100");
    vector<string> actualOutput;
    tree.printPreorder(tree.root, actualOutput);
    vector<string> expectedOutput = {"Bob","Billy", "Sydney"};
    REQUIRE(expectedOutput== actualOutput);
}
TEST_CASE("Test All 4 Rotation Cases--> Right Right Imbalance"){
    Tree tree;
    tree.insert("Sydney", "33333300");
    tree.insert("Bob", "44444400");
    tree.insert("Billy", "55555500");
    vector<string> actualOutput;
    tree.printPreorder(tree.root, actualOutput);
    vector<string> expectedOutput = {"Bob", "Sydney", "Billy"};
    REQUIRE(expectedOutput== actualOutput);
}
TEST_CASE("Test All 4 Rotation Cases--> Right Left Imbalance"){
    Tree tree;
    tree.insert("Sydney", "33333300");
    tree.insert("Bob", "44444400");
    tree.insert("Billy", "40000000");
    vector<string> actualOutput;
    tree.printPreorder(tree.root, actualOutput);
    vector<string> expectedOutput = {"Billy", "Sydney","Bob" };
    REQUIRE(expectedOutput== actualOutput);
}
TEST_CASE("Test All 4 Rotation Cases-->  Left Right Imbalance"){
    Tree tree;
    tree.insert("Sydney", "33333300");
    tree.insert("Bob", "11111100");
    tree.insert("Billy", "20000000");
    vector<string> actualOutput;
    tree.printPreorder(tree.root, actualOutput);
    vector<string> expectedOutput = {"Billy", "Bob","Sydney" };
    REQUIRE(expectedOutput== actualOutput);
}
TEST_CASE("Deletion Case: two children"){
    Tree tree;
    tree.insert("Sydney", "33333300");
    tree.insert("Bob", "11111100");
    tree.insert("Billy", "40000000");
    tree.remove(tree.root,"33333300" );
    vector<string> actualOutput;
    tree.printInorder(tree.root, actualOutput);
    vector<string> expectedOutput = {"Bob","Billy" };
    REQUIRE(expectedOutput== actualOutput);
}
TEST_CASE("Deletion Case: no children"){
    Tree tree;
    tree.insert("Sydney", "33333300");
    tree.insert("Bill", "44000000");
    tree.remove(tree.root,"44000000" );
    vector<string> actualOutput;
    tree.printInorder(tree.root, actualOutput);
    vector<string> expectedOutput= {"Sydney"};
    REQUIRE(actualOutput == expectedOutput);
}
TEST_CASE("Deletion Case: one child"){
    Tree tree;
    tree.insert("Sydney", "33333300");
    tree.insert("Bill", "44000000");
    tree.remove(tree.root,"33333300" );
    vector<string> actualOutput;
    tree.printInorder(tree.root, actualOutput);
    vector<string> expectedOutput= {"Bill"};
    REQUIRE(actualOutput == expectedOutput);
}
TEST_CASE("BST Insert Large", "[flag]"){//inserting 100 nodes and then removing 10 random ones
    Tree inputTree;
    vector<int> expectedOutput;
    vector<string> actualOutput;
    vector<int> outputtoInt;
    int b=1;
    for(int i = 0; i < 100; i++)
    {
        int randomInput = rand();
        if (count(expectedOutput.begin(), expectedOutput.end(), randomInput) == 0)
        {
            expectedOutput.push_back(randomInput);
            inputTree.insert(to_string(randomInput), to_string(randomInput));
            if(i ==b){
                inputTree.remove(inputTree.root, to_string(randomInput));
                expectedOutput.pop_back();
                b= b+10;
            }
        }
    }
    inputTree.printInorder(inputTree.root, actualOutput);
    for (int i = 0; i < actualOutput.size(); ++i) {
        outputtoInt.push_back(stoi(actualOutput.at(i)));
    }
    std::sort(expectedOutput.begin(), expectedOutput.end());
    REQUIRE(expectedOutput == outputtoInt);
}
*/