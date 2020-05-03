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
    private:
        T keyT;
        Node* right_son;
        Node* left_son;
        Node* father;
        int nodeHeight;
    public:
        Node(T keyT, Node* father): this.keyT(new T), this.father(new Node*){
            this->keyT = keyT;
            this->right_son = nullptr;
            this->left_son = nullptr;
            this->father = father;
            this->nodeHeight = father->nodeHeight - 1;
        }
        Node(const Node& other): this.keyT(other.keyT), this.right_son(other.right_son),
        this.left_son(other.left_son), this.father(other.father), this.nodeHeight(other.nodeHeight){
        }
        ~Node(){
            delete keyT;
            delete right_son;
            delete left_son;
            delete father;
        }
        int getBalance(){
            if(this->nodeHeight = 0) return 0;
            if((left_son == nullptr)&&(right_son != nullptr)) return -(right_son->nodeHeight);
            if((left_son != nullptr)&&(right_son == nullptr)) return left_son->nodeHeight;
            return (left_son->nodeHeight)-(right_son->nodeHeight);
        }
        Node* findNode(T& t){
            result = compareT(t, this->keyT);
            if(result == 0) return this;
            if(result < 0){
                if(this->left_son == nullptr){
                    return this;
                }
                return this->left_son->findNode(t);
            }
            else if(result > 0){
                if(this->right_son == nullptr){
                    return this;
                }
                return this->right_son->findNode(t);
            }
        }
        DSResult insert(T& t) {
            if (this == nullptr) {
                this = Node(t, nullptr);
                return DS_SUCCESS;
            }
            Node n1(this->findNode());
            int result = compareT(t, n1->keyT);
            if (result == 0) return DS_ALREADY_EXISTS;
            else if (result < 0) {
                n1->left_son = Node(t, n1);
                return DS_SUCCESS;
            } else if (result > 0) {
                n1.right_son = Node(t, n1);
                return DS_SUCCESS;
            }
        }
        DSResult remove(T& t){
            if(this == nullptr) return DS_DOEST_EXISTS;
            Node n1 = this->findNode(t);
            int result = compareT(t, n1.keyT);
            if(result != 0) return DS_DOEST_EXISTS;
            else if(n1.nodeHeight == 0){

            }
        }
        int getHeight(){
            return this->nodeHeight;
        }

        friend int operator<(const Node& node1, const Node& node2);

    };
private:
    Node* root;
    Node* min;
    Node* iterator;
    int height;
    DSResult rotateRight(Node* node);
    DSResult rotateLeft(Node* node);
    Node* findNode(T& t);
    Node* generateTree(int n, Element* e){
        if(n==0) return nullptr;
        int left = 0, right = n-1, mid = (left+right)/2;
        if(n==1) {
            Node n1(e, nullptr, 1, 0);
            return n1;
        }
        Node root(e, nullptr, mid, 0);
        while(mid > =1){
            root
        }
    }
public:
    DSAVLTree(){
        root = nullptr;
        min = nullptr;
        iterator = nullptr;
        height = 0;
    }
    DSAVLTree(int n, T& keyT){
        generateTree(n, keyT);
    }
    DSAVLTree(const DSAVLTree& other):this->root(other.root){
        while()
    }
    ~DSAVLTree();
    T& getMin(){
        return this->min->keyT;
    }
    const T& getKeyT(Node& node);
    DSResult insert(T keyT){
        if(keyT == nullptr)
            return DS_NULL_ARG;
        DSResult result = root->insert(keyT);
        return result;
    }
    DSResult removeElement(T keyT){
        root.remove(keyT);
    }
    T& findElement(T& t);
    template <class doSomething>
    T& startInorder();
    T& inorderGetNext():
    T& inorderGetCurrent();
    int getTreeHeight(){
        return this->root->getHeight();
    }
};


#endif //WET2_DSAVLTREE_H
