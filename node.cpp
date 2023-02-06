#include "node.h"

using namespace std;

Node& Node::operator= (Node*& node) {
    data = node->data;
    next = node->next;
}