//
// Created by Emma Mitchell on 10/1/23.
//

#ifndef GATORAVL_CODERUNNER_H
#define GATORAVL_CODERUNNER_H
#include "iostream"
#include "string"
struct runMyCode{//code running method called from main
    bool isUFID(string num){ //method to check if a string of numbers is a valid UFID
        int count =0;
        bool b = true;
        for (int i = 0; i < num.length(); ++i) {
            if (!isdigit(num[i])){//if not a digit it is not an ID
                b = false;
                break;
            }
            else{
                count++;
            }
        }
        if (count !=8){//if the UFID does not have 8 numbers
            b= false;
        }
        return b; //else it is valid
    }//UFID checker
    bool isAName(string name){//method to check if a given name is REGEX valid
        bool isName = true;
        for (int i = 0; i < name.length(); ++i) {
            if (!(isalpha(name[i]) || isspace(name[i]))){//if it does not have a letter or space then it is not a valid name
                isName = false;
                break;
            }
        }
        return isName;
    }//Name checker
    void parser(string &s, Tree& tree){//parse through the string of inputs
        bool determineIfValidCommand = true; // go in with the assumption that the command is true
        string one; //will hold command
        string two;//will hold name if applicable
        string three;// will hold UFID if applicable
        one =s.substr(0, s.find_first_of(' '));//get the command

        if (s== "printInorder" ){ //if the command was "printInorder"
            vector<string> vectorToPrint;//blank vector of strings
            tree.printInorder(tree.root, vectorToPrint);//call method to fill vector
            for (int i = 0; i < vectorToPrint.size(); ++i) {//print separated by commas
                cout<< vectorToPrint[i];
                if (i < vectorToPrint.size()-1){
                    cout<< ", ";
                }
                else{
                    cout<< endl;
                }
            }
            vectorToPrint.clear();//clear vector
        }
        else if (s== "printPreorder" ){//if the command was "printPreorder"
            vector<string> vectorToPrint;//blank vector of strings
            tree.printPreorder(tree.root, vectorToPrint);//call method to fill vector
            for (int i = 0; i < vectorToPrint.size(); ++i) {//print separated by commas
                cout<< vectorToPrint[i];
                if (i < vectorToPrint.size()-1){
                    cout<< ", ";
                }
                else{
                    cout<< endl;
                }
            }
            vectorToPrint.clear();//clear vector
        }
        else if (s== "printPostorder"){//if the command was "printPostorder"
            vector<string> vectorToPrint;//blank vector of strings
            tree.printPostorder(tree.root, vectorToPrint);//call method to fill vector
            for (int i = 0; i < vectorToPrint.size(); ++i) {//print separated by commas
                cout<< vectorToPrint[i];
                if (i < vectorToPrint.size()-1){
                    cout<< ", ";
                }
                else{
                    cout<< endl;
                }
            }
            vectorToPrint.clear();
        }
        else if (s== "printLevelCount" ){//print level count
            int levels= tree.printLevelCount(tree.root); // use this method to get the number of levels
            cout<< levels << endl;
        }
        else if(one == "insert"){//if user's command is "insert"
            //going to see if the count of the tree nodes changes
            int count1;//count before insert
            int count2;//count after insert
            two= s.substr(s.find_first_of(" ")+2);
            three= two.substr(two.find_first_of('\"')+2);//UFID
            two= two.substr(0,two.find_first_of('\"')); //name

            if (isUFID(three) && isAName(two)){//if the name and UFID are valid
                count1 = tree.numOfNodes();//get count before inserting
                tree.insert(two, three);//insert the node
                count2 = tree.numOfNodes();//get count after inserting
                if (count2 == count1){//if nothing was inserted
                    determineIfValidCommand =false; //not valide
                }
            }
            else{
                determineIfValidCommand =false;//not valid
            }

            if (!determineIfValidCommand){ //if the command was not valid
                cout<<"unsuccessful"<<endl;
            } else
                cout<< "successful"<<endl;

        }
        else if (one == "remove"){//the user's command is "remove"
            int count1;//count before remove
            int count2;//count after remove
            two= s.substr(s.find_first_of(" ")+1);//UFID

            if (isUFID(two)){//check if the UFID is valid
                count1 = tree.numOfNodes();//get nodes before removal
                tree.remove(tree.root, two);//remove node
                count2 = tree.numOfNodes();//get nodes after removal
                if (count2 < count1){//if a node was removed
                    determineIfValidCommand = true;
                } else
                    determineIfValidCommand= false;
            }
            else{//not valid because UFID was not valid
                determineIfValidCommand= false;
            }

            //what to print
            if (!determineIfValidCommand){
                cout<<"unsuccessful"<<endl;
            } else
                cout<< "successful"<<endl;
        }
        else if( one == "search"){//if user's command is "search"
            two= s.substr(s.find_first_of(" ")+1);//name or ID from user
            if (two[0]=='\"'){//could be a name
                two= two.substr(1);
                two= two.substr(0, two.find_first_of('\"'));
                if (isAName(two)){//is a name
                    tree.search(two);
                }
            }
            else if (isUFID(two)){//is an ID
                tree.search(stoi(two));
            }
            else{//no valid
                cout<< "unsuccessful"<< endl;
            }
        }
        else if (one == "removeInorder"){//command is removeInorder
            two= s.substr(s.find_first_of(" ")+1);//get the number to remove
            bool dig= true; //assume that the digit is valid
            for (int i = 0; i < two.length(); ++i) {
                if (!isdigit(two[i])){
                    dig = false;//the digit is not valid
                    break;
                }
            }
            if (dig){//the number is valid
                    tree.removeInorder(tree.root, stoi(two));
            } else{//was not valid
                cout<<"unsuccessful"<<endl;
            }
        }
        else{//none of the commands entered were valid
            cout<<"unsuccessful"<<endl;
        }
    }
};
#endif //GATORAVL_CODERUNNER_H
