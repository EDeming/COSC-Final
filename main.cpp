#include "Node.h"
#include "Tree.h"

using namespace std;

int main()
{
    int ibuff = 0;
    string sbuff = "";
    bool done = false;

    cout << "Welcome to the Tracking Tree!" << endl;
    cout << "Please enter an event for the tree root: ";
    getline(cin, sbuff);
    tree t1(sbuff);
    cin.clear();

    while(!done)
    {
        cout << "1 = New Node, 2 = Edit Node, 3 = Print Node" << endl;
        cout << "4 = Print Tree, 0 = Exit Program (Tree Prints on Exit)" << endl;
        cout << "Please enter a value listed above: ";
        cin >> ibuff;

        switch(ibuff)
        {
            case 1:
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Creating new node! Please enter an event for this node: ";
                    getline(cin, sbuff);
                    cout << endl;
                    t1.newNode(sbuff);
                    cin.clear();
                    break;
                }
            case 2:
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Please enter the ID of the node you wish to edit: ";
                    getline(cin, sbuff);
                    string ID = sbuff;
                    cin.clear();
                    cout << "Please enter the new event for the node: ";
                    getline(cin, sbuff);
                    string event = sbuff;
                    cout << endl;
                    t1.editNode(ID, event);
                    cin.clear();
                    break;
                }
            case 3:
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Please enter the ID of the node you wish to print: ";
                    getline(cin, sbuff);
                    cout << endl;
                    t1.printNode(sbuff);
                    cin.clear();
                    break;
                }
            case 4:
                {
                    cin.clear();
                    cout << endl;
                    t1.printTree(t1.root);
                    cin.clear();
                    break;
                }
            case 0:
                {
                    cin.clear();
                    done = true;
                    cout << endl;
                    t1.printTree(t1.root);
                    cin.clear();
                    break;
                }
            default:
                {
                    cin.clear();
                    cout << endl;
                    cout << "Please enter a valid operation." << endl;
                    cin.clear();
                }
        }
    }

    return 0;
}
