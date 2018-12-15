#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include "Node.h"

using namespace std;

class tree
{
public:
    node* root;

    tree(string rawE);
    void newNode(string rawE);
    void editNode(string inputID, string inputE);
    void printNode(string inputID);
    void printTree(node* node);
    void updateHash(node* node);
};

#endif // TREE_H_INCLUDED
