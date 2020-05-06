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
        T* keyT;
        Node* right_son;
        Node* left_son;
        Node* father;
        int nodeHeight;
    public:
        Node(T keyT, Node* father){
            this->keyT = keyT.clone();
            this->right_son = nullptr;
            this->left_son = nullptr;
            this->father = father;
            this->nodeHeight = 0;
        }
        ~Node(){
            delete keyT;
        }
        int getBalance(){
            if(this->nodeHeight = 0) return 0;
            if((left_son == nullptr)&&(right_son != nullptr)) return -(right_son->nodeHeight +1);
            if((left_son != nullptr)&&(right_son == nullptr)) return left_son->nodeHeight +1;
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
        int max(int a, int b){
            return (a > b) ? a:b;
        }
        void updateHeight(){
            this->nodeHeight = 1+max(this->right_son->nodeHeight, this->right_son->nodeHeight);
        }
        void balance(){
            int b_factor = this->getBalance();
            if(b_factor > 1){
                if(this->left_son->getBalance() >0){
                    this.LL_Rotate();
                }
                else{
                    this.LR_Rotate();
                }
            }
            else if(b_factor < -1){
                if(this->right_son->getBalance() > 0){
                    this.RL_Rotate();
                }
                else{
                    this.RR_Rotate();
                }
            }
        }
        T& insert(T& t, Node* father, bool isLeft) {
            if (this == nullptr) {
                this = new Node(t, father);
                if(isLeft == true){
                    this->father->left_son = this;
                }
                else{
                    this->father->right_son = this;
                }
                this->nodeHeight = 0;
                return this->keyT;
            }
            T* t;
            int result = compareT(t, this->keyT);
            if (result < 0) {
                t = this->left_son.insert(t, this->left_son, true);
            } else if (result > 0) {
                t = this->right_son->insert(t, this->right_son, false);
            }
            this->updateHeight();
            this->balance();
            return t;
        }
        void RR_Rotate(){
            Node* temp = this->right_son);
            this->right_son = temp->left_son;
            temp->left_son = this;
            temp->father = this->father;
            this->father = temp;
            temp->father->right_son = temp;
        }
        void LL_Rotate(){
            Node* temp = this->left_son);
            this->left_son = temp->right_son;
            temp->right_son = this;
            temp->father = this->father;
            this->father = temp;
            temp->father->left_son = temp;
        }
        void LR_Rotate(){
            this->left_son->RRRotate();
            this->LLRotate();
        }
        void RL_Rotate() {
            this->right_son->LLRotate();
            this->RRRotate();
        }
        DSResult remove(T& t){
            if(this == nullptr) return DS_DOEST_EXISTS;
            int result = compareT(t, this.keyT);
            if(result < 0){
                this->left_son->remove(t, this);
            }
            else if(result > 0){
                this->right_son->remove(t, this);
            }
            else{
                if(this->nodeHeight == 0){
                    this->removeLeaf();
                }
                else if(this->left_son == nullptr && this->right_son != nullptr){
                    this->removeFatherWithOnlyRightSon();
                }
                else if(this->left_son != nullptr && this->right_son == nullptr){
                    this->removeFatherWithOnlyLeftSon();
                }
                else{
                    this->removeFatherWithTwoSons();
                }
            }
            this->updateHeight();
            this->balance();
            return DS_SUCCESS;
        }
        void removeLeaf(){
            delete this;
            this->updateHeight();
        }
        void removeFatherWithOnlyRightSon(){
            if(father->left_son == this){
                this.father->left_son = this->right_son;
            }
            else{
                this.father->right_son = this->right_son;
            }
            this->right_son->father = this->father;
            delete this;
        }
        void removeFatherWithOnlyLeftSon(){
            if(this.father->left_son == this){
                this.father->left_son = this->left_son;
            }
            else{
                this.father->right_son = this->left_son;
            }
            this->left_son->father = this->father;
            delete this;
        }
        void removeFatherWithTwoSons(){
            Node* temp = this->right_son;
            while(temp->left_son != nullptr){
                temp = temp->left_son;
            }
            Node* temp2 = temp->right_son;
            Node* temp3 = temp->father;
            temp3->left_son = this;
            temp->father = this->father;
            if(this->father->left_son == this){
                this->father->left_son = temp;
            }
            else{
                this->father->right_son = temp;
            }
            temp->left_son = this->left_son;
            temp->right_son = this->right_son;
            temp->left_son->father = temp;
            temp->right_son->father = temp;
            this->right_son = temp2;
            temp2->father = this;
            this->left_son = nullptr;
            this->father = temp3;
            if(this->right_son == nullptr){
                this->removeLeaf();
            }
            else{
                this->removeFatherWithOnlyRightSon();
            }
        }
        int getHeight(){
            return this->nodeHeight;
        }
        Node* inOrderGetNext() {
            Node *temp = this->right_son;
            if (temp == nullptr) {
                return nullptr;
            }
            while (temp->left_son != nullptr) {
                temp = temp->left_son;
            }
            return temp;
        }
    };
private:
    Node* root;
    Node* min;
    Node* iterator;
    int height;
    Node* generateTree(int start, int end, Node* father, generate generate) {
        if (generate == nullptr) DS_NULL_ARG;
        if ((end - start) == 0) {
            Node n0(generate(start), father);
            return n0;
        }
        int mid = (start + end) / 2;
        try{
            Node *node = new Node(generate(mid), father);
        }
        catch (...) {
            delete node;
            throw;
        }
        try{
            node->left_son = (generateTree(start, mid - 1, node, generate));
            node->right_son = (generateTree(mid + 1, end, node, generate));
        }
        catch (...){
            node.left_son.destroyTree();
            node.right_son.destroyTree();
        }
        return node;
    }
public:
    DSAVLTree(){
        root = nullptr;
        min = nullptr;
        iterator = nullptr;
        height = 0;
    }
    template<class generate>
    DSAVLTree(int n, generate g){
        if(n == 1){
            root = Node(generate(0), nullptr);
            min = root;
        }
        if(n > 1){
            root = generateTree(0, n, nullptr, g);
        }
    }
    ~DSAVLTree(){
        for(Node *n = min; n != nullptr; n = n->inOrderGetNext()){
            delete n;
        }
    }
    T& getMin(){
        return this->min->keyT;
    }
    DSResult insertElement(T keyT){
        if(keyT == nullptr)
            return DS_NULL_ARG;
        DSResult ds_r = DS_ALREADY_EXISTS;
        int result = compareT(keyT, root->keyT);
        if(result < 0){
            ds_r = root->insert(keyT, root, true);
        }
        else if(result > 0){
            ds_r = root->insert(keyT, root, false);
        }
        return ds_r;
    }
    void removeElement(T keyT){
        root->remove(keyT);
    }
    T& findElement(T& t){
        if(t == nullptr){
            return nullptr;
        }
        return (findNode(t))->keyT;
    }

    T* startInorder(){
        iterator = min;
        return min->keyT;
    }
    T* inorderGetNext(){
        iterator = iterator->inOrderGetNext();
        return iterator->keyT;
    }
    T* inorderGetCurrent(){
        return iterator;
    }
    int getTreeHeight(){
        return this->root->getHeight();
    }
    bool isEmpty(){
        if(root == nullptr) return true;
        return false;
    }
};


#endif //WET2_DSAVLTREE_H
