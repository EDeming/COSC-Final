#include "Node.h"
#include <cstdlib>
#include <ctime>

using namespace std;

node::node(string PIDin, string rawE)
{
    raw_event = rawE;
    if(PIDin.compare("") == 0)
    {
        srand(time(NULL));
        PID = "00000001";
    }
    else
    {
        PID = PIDin;
    }

    hash<string> str_hash;

    ID = to_string(str_hash(PID + raw_event) % 100000000);

    lft = NULL;
    rght = NULL;
}

void node::setRaw(string newRaw)
{
    raw_event = newRaw;

    hash<string> str_hash;

    ID = to_string(str_hash(PID + raw_event) % 100000000);
}

void node::setPID(string newPID)
{
    PID = newPID;

    hash<string> str_hash;

    ID = to_string(str_hash(PID + raw_event) % 100000000);
}

string node::getPID()
{
    return PID;
}

string node::getID()
{
    return ID;
}

string node::getHash()
{
    hash<string> str_hash;

    ID = to_string(str_hash(PID + raw_event + RHash + LHash) % 100000000);

    return ID;
}

void node::setLHash(string in)
{
    LHash = in;
}

void node::setRHash(string in)
{
    RHash = in;
}

void node::print()
{
    cout << "ID: " << ID << endl;
    cout << "PID: " << PID << endl;
    cout << "Event Details: " << raw_event << endl;
    cout << "Left Hash: " << LHash << endl;
    cout << "Right Hash: " << RHash << endl;

    cout << "Left History:" << endl;

    for(int i = 0; i < LHist.size(); i++)
    {
        cout << LHist[i] << endl;
    }

    cout << "Right History:" << endl;

    for(int i = 0; i < RHist.size(); i++)
    {
        cout << RHist[i] << endl;
    }

    cout << endl;
}
