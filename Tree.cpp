#include "Tree.h"
#include <queue>

using namespace std;

tree::tree(string rawE)
{
    root = new node("", rawE);
    cout << "Tree created. Root node ID: " << root->ID << endl;
}

void tree::newNode(string rawE)
{
    queue<node*> searchTree;
    searchTree.push(root);
    node* current = searchTree.front();
    bool found = false;

    while(!found)
    {
        current = searchTree.front();
        searchTree.pop();
        if(current->lft == NULL || current->rght == NULL)
        {
            found = true;
        }
        if(current->lft != NULL && current->rght != NULL)
        {
            searchTree.push(current->lft);
            searchTree.push(current->rght);
        }
    }

    if(current->lft == NULL)
    {
        current->lft = new node(current->getID(), rawE);
        current->setLHash(current->lft->getID());
        current->LHist.push_back(current->LHash);
        cout << "Node created. Node Details: " << endl;
        current->lft->print();
    }
    else if(current->rght == NULL)
    {
        current->rght = new node(current->ID, rawE);
        current->setRHash(current->rght->getID());
        current->RHist.push_back(current->RHash);
        cout << "Node created. Node Details: " << endl;
        current->rght->print();
    }
}

void tree::editNode(string inputID, string inputE)
{
    queue<node*> searchTree;
    searchTree.push(root);
    node* current = searchTree.front();
    bool found = false;
    bool finished = false;
    string curString = "";

    while(!found || !finished)
    {
        current = searchTree.front();
        searchTree.pop();
        curString = current->getID();
        if(curString.compare(inputID) == 0)
        {
            found = true;
        }
        if(current->lft == NULL && current->rght == NULL)
        {
            finished = true;
        }
        if(current->lft != NULL)
        {
            searchTree.push(current->lft);
        }
        if(current->rght != NULL)
        {
            searchTree.push(current->rght);
        }
        if(current->lft == NULL && current->rght == NULL)
        {
            finished = true;
        }
    }

    if(found == true)
    {
        current->setRaw(inputE);
        updateHash(root);
        cout << "Event updated. New ID: " << current->ID << endl;
    }
    else
    {
        cout << "Event not found. Please try a different ID." << endl;
    }
}

void tree::printNode(string inputID)
{
    queue<node*> searchTree;
    searchTree.push(root);
    node* current = searchTree.front();
    bool found = false;
    bool finished = false;
    string curString = "";

    while(!found || !finished)
    {
        current = searchTree.front();
        searchTree.pop();
        curString = current->getID();
        if(curString.compare(inputID) == 0)
        {
            found = true;
        }
        if(current->lft == NULL && current->rght == NULL)
        {
            finished = true;
        }
        if(current->lft != NULL)
        {
            searchTree.push(current->lft);
        }
        if(current->rght != NULL)
        {
            searchTree.push(current->rght);
        }
        if(current->lft == NULL && current->rght == NULL)
        {
            finished = true;
        }
    }

    if(found == true)
    {
        current->print();
    }
    else
    {
        cout << "Event not found. Please try a different ID." << endl;
    }
}

void tree::updateHash(node* node)
{
    if(node == NULL)
    {
        return;
    }

    updateHash(node->lft);

    updateHash(node->rght);

    node->LHash = (node->lft->getID());

    if(node->LHist.back() != node->lft->getID())
    {
        node->LHist.push_back(node->LHash);
    }

    node->RHash = (node->rght->getID());

    if(node->RHist.back() != node->rght->getID())
    {
        node->RHist.push_back(node->RHash);
    }
}

void tree::printTree(node* node)
{
    if(node != NULL)
    {
        node->print();
        cout << endl;

        printTree(node->lft);

        printTree(node->rght);
    }
}
