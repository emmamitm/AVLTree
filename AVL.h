//
// Created by Emma Mitchell on 10/1/23.
//

#ifndef GATORAVL_AVL_H
#define GATORAVL_AVL_H

#include "string"
#include "vector"
#include <iostream>
#pragma once
using namespace std;

struct Node{
    string name;//student's name
    int UFID;//student's UFID
    int height=1;//height should be initialized to 1 when the node is first added
    Node* LeftChild;//Left child pointer
    Node* RightChild;//Right child pointer
    Node(): name(""), UFID(0), LeftChild(nullptr), RightChild(nullptr){}
    Node(string Name, int id){name = Name; UFID = id; LeftChild = nullptr; RightChild = nullptr;};
};

class Tree{//Tree class that holds linked nodes
public:
    vector<int> vector1;//helper vector for remove in order
    vector<Node*> vector2;//helper vector for search name
    Node* root= nullptr; //root initialization

    //Height Calculation
    int NodeH(Node* node){
        if(node == nullptr){
            return 0;//height is 0 if nullptr
        }
        else{
            int h =  node->height;//get and return the height of the node
            return h;//return the height of node
        }
    }//height helper
    //Balance Calculation
    int balanceofNode(Node* node){//method to calculate the node balance
        if (node == nullptr)
            return 0;//nullptr = value of 0
        else
        {
            int h= NodeH(node->LeftChild)- NodeH(node->RightChild); //difference in Left- Right
            return h;//return the difference
        }
    }//balance helper

    //Insert Method
    Node* insert(string name, string UFID){
        this-> root = insertHelper(this->root, name, UFID); //update the root
    }//what the user will call
    Node* insertHelper(Node* node, string name, string UFID){
            int x = stoi(UFID);//convert ID to int

            if(node == nullptr){// base case
                return new Node(name, x);
            }
            else{
                if (node-> UFID == x){//no changes made to the tree
                    return node;
                }
                else if (node->UFID < x){//go right
                    node->RightChild=  insertHelper(node->RightChild, name, UFID);
                }
                else{//go left
                    node->LeftChild= insertHelper(node->LeftChild,name, UFID);
                }
            }

        node->height= 1+ max(NodeH(node->LeftChild), NodeH(node->RightChild));//update the height
        int bal = balanceofNode(node);//find the balance
        if (bal < -1){//RIGHT OVERALL
            if (balanceofNode(node->RightChild)<=0){//RR
                return rotateLeft(node);
            }
            else if (balanceofNode(node->RightChild)>0){//RL
                return rotateRightLeft(node);
            }
        }
        else if (bal > 1){//LEFT OVERALL
            if (balanceofNode(node->LeftChild)>= 0){//LL
                return rotateRight(node);
            }
            else if(balanceofNode(node->LeftChild )<0){//LR
                return rotateLeftRight(node);
            }
        }

        return node; //update the tree
    }//real insert method
    //Remove Method
    Node* remove(Node* node, string UFID){
        int x= stoi(UFID);//convert ID to int

        if (node == nullptr){//base case
            return node;
        }

        if (x<node->UFID){//go left
            node->LeftChild = remove(node->LeftChild, UFID);
        }
        else if (x>node->UFID){//go right
            node->RightChild = remove(node->RightChild, UFID);

        }
        else {
            if (node->LeftChild== nullptr && node->RightChild == nullptr){//no children
                Node* curr = node;
                node= nullptr;
                free(curr);
            }
            else if (node->LeftChild== nullptr || node->RightChild == nullptr){//one child
                if (node->LeftChild != nullptr){//left side is the child
                    Node* curr = node->LeftChild;
                    *node = *curr;
                    free(curr);
                }
                else{//right side is the child
                    Node* curr = node->RightChild;
                    *node = *curr;
                    free(curr);
                }
            }
            else if (node->LeftChild!= nullptr && node->RightChild != nullptr){//2 children
                Node* rightSubSmall= node->RightChild;//finding the smallest node on the right side
                Node* leftSubLarge= node->LeftChild;// finding the largest node on the left side
                while (rightSubSmall->LeftChild != nullptr){
                    rightSubSmall = rightSubSmall->LeftChild; //smallest right
                }
                while (leftSubLarge->RightChild!= nullptr){
                    leftSubLarge = leftSubLarge->RightChild; //biggest left
                }
                if (abs(rightSubSmall->UFID-x) < abs(leftSubLarge->UFID-x)){//the rightside node was closer to it
                    node->UFID = rightSubSmall->UFID;//reassign the ID
                    node->name = rightSubSmall->name;//reassign the name
                    node->RightChild = remove(node->RightChild, to_string(rightSubSmall->UFID));//make a deletion
                }
                else{ // the leftside node was closer to it
                    node->UFID = leftSubLarge->UFID;//reassign the ID
                    node->name = leftSubLarge->name;//reassign the name
                    node->LeftChild = remove(node->LeftChild, to_string(leftSubLarge->UFID));//make a deletion
                }
            }
        }
        if (node==NULL)
            return node;

        node->height= 1+ max(NodeH(node->LeftChild), NodeH(node->RightChild));//update the height
        int bal = balanceofNode(node);//find the balance
        if (bal < -1){//RIGHT OVERALL
            if (balanceofNode(node->RightChild)<=0){//RR
                return rotateLeft(node);
            }
            else if (balanceofNode(node->RightChild)>0){//RL
                return rotateRightLeft(node);
            }
        }
        else if (bal > 1){//LEFT OVERALL
            if (balanceofNode(node->LeftChild)>= 0){//LL
                return rotateRight(node);
            }
            else if(balanceofNode(node->LeftChild )<0){//LR
                return rotateLeftRight(node);
            }
        }

        return node;//fix the tree
    }//method to remove a given node from the root

    //Rotation Methods
    Node* rotateLeft(Node* node)
    {//method if we have a right right case
        Node* curr =node;
        node= node->RightChild;
        curr->RightChild = nullptr;
        node->LeftChild= curr;
        //recalculate the height
        curr->height = max(NodeH(curr->LeftChild),
                           NodeH(curr->RightChild)) + 1;
        node->height = max(NodeH(node->LeftChild),
                         NodeH(node->RightChild)) + 1;
        //update root if needed
        if (this->root->UFID == curr->UFID){
            this->root =node;
        }
        //return the new node
        return node;
    } //method to rotate left to balance
    Node* rotateRight(Node *node)
    {
        Node* curr= node;
        node= node->LeftChild;
        curr->LeftChild= nullptr;
        node->RightChild= curr;

        curr->height = max(NodeH(curr->LeftChild),
                           NodeH(curr->RightChild)) + 1;
        node->height = max(NodeH(node->LeftChild),
                           NodeH(node->RightChild)) + 1;
        if (this->root->UFID == curr->UFID){
            this->root =node;

        }

        return node;
    }//method to rotate right to balance
    Node* rotateLeftRight(Node *node)
    {
        Node* curr = node->LeftChild;
        Node* curr2= curr->RightChild;
        node->LeftChild=curr2;
        curr2->LeftChild = curr;
        curr->RightChild = nullptr;
        if (node->UFID == this->root->UFID){
            this->root=node;
        }
        node = rotateRight(node);
        return node;
    }//method to rotate left and then right to balance
    Node* rotateRightLeft(Node *node){
        Node* curr = node->RightChild;
        Node* curr2= curr->LeftChild;
        node->RightChild=curr2;
        curr2->RightChild = curr;
        curr->LeftChild = nullptr;
        if (node->UFID == this->root->UFID){
            this->root=node;
        }
        node = rotateLeft(node);
        return node;
    }//method to rotate right and then left to balance

    //Search method for UFID returns true or false
    bool search(int UFID){
        Node* curr = root;
        bool find = false;//assume that the node was not found
        while(curr!= nullptr){
            if (UFID==curr->UFID){//found the node
                cout<< curr->name<< endl;
                find= true;
                break;
            }
            else if(UFID>curr->UFID){//move right
                curr= curr->RightChild;
            }
            else if (UFID<curr->UFID){//move left
                curr= curr->LeftChild;
            }
        }
        if (!find)
            cout<< "unsuccessful"<<endl;//print if you did not find it
        return find;
    }//search for UFID in tree

    //ALL the Printing Methods
    void printInorder(Node* node,vector<string> &vectorToPrint){//printing all the numbers in order but will print names
        //start from bottom left subtree
        //go to the subtree root and then go to the right
        if(node == nullptr){
            return;
        }
        printInorder(node->LeftChild, vectorToPrint);
        vectorToPrint.push_back(node->name);//add to vector given in function
        printInorder(node->RightChild, vectorToPrint);

    }//print in numerical order
    void printPostorder(Node* node, vector<string> &vectorToPrint){//printing all the numbers in order
        if(node == nullptr){
            return;
        }
        printPostorder(node->LeftChild, vectorToPrint);
        printPostorder(node->RightChild, vectorToPrint);
        vectorToPrint.push_back(node->name);//insert into the vector from function call
    }//print in post order
    void printPreorder(Node* node, vector<string> &vectorToPrint){//printing all the numbers in order

        if(node == nullptr){
            return;
        }
        vectorToPrint.push_back(node->name);//add to the vector
        printPreorder(node->LeftChild, vectorToPrint);
        printPreorder(node->RightChild, vectorToPrint);
    }//print in pre order
    int printLevelCount(Node* node) {
        if (node== nullptr){
            return 0;//if root is not existant
        }
        return (root->height ) ;// else return the height of the root
    }

    //Methods for counting nodes
    void traverse(Node* node, int &number){//traversal of the entire tree
        if(node == nullptr){
            return;//base case
        }
        traverse(node->LeftChild, number);//go left
        number++;// increment num
        traverse(node->RightChild, number);//go right
    }//this method will help me get the node count
    int numOfNodes(){
        int number=0;//start with 0 as the count
        traverse(root, number);// go through the entire tree and count all of the nodes
        return number;
    } //will return the number of nodes in the tree

    //All methods needed for removeInorder
    [[nodiscard]] Node* search2(int UFID) {
        Node* curr = root;
        while(curr!= nullptr){
            if (UFID==curr->UFID){
                break;
            }
            else if(UFID>curr->UFID){
                curr= curr->RightChild;
            }
            else if (UFID<curr->UFID){
                curr= curr->LeftChild;
            }
        }
        return curr;
    }//used in remove in order
    void PrintInorder2(Node* node){//printing all the numbers in order
        if(node == nullptr){
            return;
        }
        PrintInorder2(node->LeftChild);
        vector1.push_back(node->UFID);//add to vector from the remove in order
        PrintInorder2(node->RightChild);

    }//used for the removeInorder method
    void removeInorder(Node* node, int N){
        PrintInorder2(node);//call this method to get a vector of all of the in order nodes
        if (vector1.size() > N){
            int id = vector1.at(N);
            node= search2(id);
            remove(this->root, to_string(id));
            vector1.clear();
            cout<< "successful"<<endl; //if it was removed
        }else
            cout<< "unsuccessful"<<endl;//if the node was not removed
    }//takes in a value and removes the node that is Nth in the in order tree

    //all methods used for Search Name
    void PrintPreorder2(Node* node){//printing all the numbers in order
        if(node == nullptr){
            return;
        }
        vector2.push_back(node); //add to vector 2 for the Search name method
        PrintPreorder2(node->LeftChild);
        PrintPreorder2(node->RightChild);
    }//used for the search name method in case name shows up more than once
    void search(const string& Name){//search name function
        PrintPreorder2(root);//add all names in preorder value to the vector
        vector<Node*> matchingNames;//blank vector of nodes
        for (auto & i : vector2) { //loops through all of the names stored in preorder
            if (i->name == (Name) ){
                matchingNames.push_back(i);//add matching names to this vector
            }
        }
        if (matchingNames.empty()){//if there were no matching names
            cout<< "unsuccessful"<< endl;
        }
        else{
            for (int i = 0; i < matchingNames.size()-1; ++i) {//print out all of the matching names
                cout<< matchingNames[i]->UFID << ", ";
            }
            cout<< matchingNames.at(matchingNames.size()-1)->UFID << endl;

        }
        //clear all the vectors
        matchingNames.clear();
        vector2.clear();
    }//search name function

};


#endif //GATORAVL_AVL_H
