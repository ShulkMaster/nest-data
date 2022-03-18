#ifndef NEST_GRAPH_H
#define NEST_GRAPH_H
#include "Node.h"

template <typename T>
class Graph {
public:
    bool add();
    bool remove();
    bool clear();
    Node* getNodes();
    Graph();
};


#endif //NEST_GRAPH_H
