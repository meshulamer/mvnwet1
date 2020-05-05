//
// Created by meshu on 30/04/2020.
//

#ifndef WET2_DSAVLTREE_H
#define WET2_DSAVLTREE_H

#include <stdlib.h>
typedef enum {DS_SUCCESS,DS_FAILURE,DS_NULL_ARG,DS_NO_MEMORY,DS_ALREADY_EXISTS,DS_DOEST_EXISTS} DSResult;

template<class T, class CompareT>
class DSAVLTree {
    class Node{
        T keyT;
        K keyK;
        Element* data;
        Node* right_son;
        Node* left_son;
        Node* father;
        int nodeHeight;
    public:
        Node(Element* data, T keyT, K keyK=K());
        Node(const Node& other);
        ~Node();
        friend int operator<(const Node& node1, const Node& node2);

    };
private:
    Node* root;
    Node* min;
    Node* iterator;
    DSResult rotateRight(Node* node);
    DSResult rotateLeft(Node* node);
    Node* findNode(T& t, K& k);
public:
    template <class generate>
    DSAVLTree(int n, T& e, generate g);
    DSAVLTree(const DSAVLTree& other);
    ~DSAVLTree();
    Element& getMin();
    const T& getKeyT(Node& node);
    const K& getKeyK(Node& node);
    DSResult addElement(T keyT, K keyK, Element& e);
    DSResult removeElement(T keyT, K keyK, Element& e);
    Element& findElement(T& t, K& k);
    template <class doSomething>
    Element& inorder(doSomething f);
};


#endif //WET2_DSAVLTREE_H
