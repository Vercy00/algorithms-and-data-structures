//
// Created by david on 16.10.2023.
//

#ifndef LAB_2_NODE_H
#define LAB_2_NODE_H

namespace app {

    template<typename T>
    struct node {
        node *prevNode;
        node *nextNode;
        T obj;

        node(T obj): obj(obj) {}
        node(node *prevNode, node *nextNode, T obj): prevNode(prevNode), nextNode(nextNode), obj(obj) {}
    };

} // app

#endif //LAB_2_NODE_H
