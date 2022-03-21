#ifndef NEST_GRAPH_H
#define NEST_GRAPH_H

#include "Node.h"

namespace DataStrut {

    enum Direction {
        Up,
        UpLeft,
        UpRight,
        Left,
        Right,
        Down,
        DownLeft,
        DownRight,
    };

    class Graph {
    private:
        Node const *currentNode;
    public:

        bool add(Node* node);

        bool connect(Node* node1, Node* node2);

        bool remove(Node* node);

        bool clear();

        explicit Graph(Node *seed);

        void navigate(Direction direction);
    };

}
#endif //NEST_GRAPH_H
