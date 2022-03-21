#ifndef NEST_NODE_H
#define NEST_NODE_H

namespace DataStrut {
    class Node {
    private:
        const Node *connections[24];

    public:
        void getClosest(const Node array[8]);

        const Node *const getAdjacencyList();

        int getValue();
    };

}
#endif //NEST_NODE_H
