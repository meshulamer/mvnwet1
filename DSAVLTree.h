//
// Created by meshu on 30/04/2020.
//

#ifndef WET2_DSAVLTREE_H
#define WET2_DSAVLTREE_H

template<class T, class K, class Element>
class DSAVLTree {
    class Node{
        T keyT;
        K keyK;
        Element data;
        Node* right_son;
        Node* left_son;
        Node* father;
    };
private:
    Node* root;
    Node* min;
    Node* iterator;
public:
    explicit DSAVLTree(bool duoKey);
    DSAVLTree(Element startValueK, K m, T startValueT=T());

};


#endif //WET2_DSAVLTREE_H
