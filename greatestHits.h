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
        min = new(GHNode);
        max = min;
        min->next = min->prev = nullptr;
        min->key =0;

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

    GHNode* getmin(){
        return min;
    }
    GHNode* getmax(){
        return max;
    }

    static GHNode* advance(GHNode& node){
        if(node.next == nullptr||node.key + 1 != node.next.key) {
            GHNode *end_chain = node.next;
            GHNode *new_chain = node.next = new(GHNode);
            new_chain->next = end_chain;
            end_chain->prev = new_chain;
            new_chain->key = node.key + 1;
            return new_chain;
        }
        return node.next;
        }
    private:
        GHNode* min;
        GHNode* max;

};

void removeGHNode(greatestHits<class T>::GHNode* node){
    node.prev.next = node.next;
    if(node.next!= nullptr){
        node.next.prev = node.prev;
        delete node;
    }
}

#endif //WET2_GREATESTHITS_H
