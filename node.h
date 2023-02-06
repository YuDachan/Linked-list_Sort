#ifndef NODE
#define NODE
#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    /********************************************************************* 
    ** Function:  operator=
    ** Description: assignment operator
    ** Parameters:  Node*
    ** Pre-Conditions: none
    ** Post-Conditions: data is copied
    *********************************************************************/
    Node& operator= (Node*& node);

};
#endif // !NODE
