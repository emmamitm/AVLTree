#include <iostream>
#include "AVL.h"
#include "CodeRunner.h"

int main() {
    Tree tree;
    runMyCode runMyCode;

    string s;
    int numOfLines;
    cin >> numOfLines;
    vector<string> vecs;
    getline(cin, s);
    while (numOfLines>0)
    {
        getline(cin, s);
        vecs.push_back(s);
        numOfLines--;
    }
    for (int i = 0; i < vecs.size(); ++i) {
        runMyCode.parser(vecs.at(i), tree);
    }
    return 0;
}

