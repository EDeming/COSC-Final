#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class node
{
public:
    string ID;   //node ID
    string PID;  //parent ID
    string raw_event;
    node * lft;
    node * rght;
    string LHash;
    string RHash;
    vector<string> LHist;
    vector<string> RHist;

    node(string PIDin, string rawE);

    void setRaw(string newRaw);

    void setPID(string newPID);

    string getPID();

    string getID();

    string getHash();

    void setLHash(string in);

    void setRHash(string in);

    void print(void);
};

#endif // NODE_H_INCLUDED
