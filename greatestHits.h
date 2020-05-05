//
// Created by meshu on 29/04/2020.
//

#ifndef WET2_GREATESTHITS_H
#define WET2_GREATESTHITS_H
#include <stdlib.h>
#include <stdio.h>
#include <bits/exception.h>
#include <string.h>

template <class T>
class greatestHits {

public:
    class GHNode{
    public:
        int key;
        T element;
        GHNode*  next;
        GHNode* prev;
    };
    greatestHits(){
        try {
            min = new(GHNode);
            max = min;
            min->next = min->prev = nullptr;
            min->key = 0;
        }
        catch(...){
            throw OUT_OF_MEM();
        }
    }

    ~greatestHits(){
        GHNode* current = min;
        GHNode* temp;
        while(current!= nullptr){
            temp = current;
            current = temp->next;
            delete temp;
        }

    }

    GHNode& getMin(){
        return (*min)&;
    }
    GHNode& getMax(){
        return (*max)&;
    }

    class OUT_OF_MEM : public std::exception{
        const char* what() const throw(){
            return "Out Of Memory";
        }
    };
    private:
        GHNode* min;
        GHNode* max;

};

void removeGHNode(greatestHits<class T>::GHNode* node){
    if(node.key==0) return;
    node.prev.next = node.next;
    if(node.next!= nullptr){
        node.next.prev = node.prev;
        delete node;
    }
}
static GHNode* advance(GHNode& node){
    try {
        if (node.next == nullptr || node.key + 1 != node.next.key) {
            GHNode *end_chain = node.next;
            GHNode *new_chain = node.next = new(GHNode);
            new_chain->next = end_chain;
            if(endchain!= nullptr) {
                end_chain->prev = new_chain;
            }
            else{
                max = new_chain;
            }
            new_chain->key = node.key + 1;
            return new_chain;
        }
        return node.next;
    }
    catch(...){
        throw OUT_OF_MEM();

    }

}

template <class T>
void removeGHNode(greatestHits<class T>::GHNode* node){
    if(node.key==0) return;
    node.prev.next = node.next;
    if(node.next!= nullptr){
        node.next.prev = node.prev;
        delete node;
    }
}

#endif //WET2_GREATESTHITS_H
