//
// Created by meshu on 03/05/2020.
//

#include "Song.h"
Song *Generate::operator()(int m) {
    return new Song(m,listNode);
}

Generate::Generate(ListNode& node): listNode(node){}

Song::Song(int id, ListNode &listNode):id(id),listNode(listNode){}

Song *Song::clone() {
    return new Song(id,listNode);
}

int compareSong::operator()(const Song& s1, const Song& s2){
    int first_comp = s2.listNode.key - s1.listNode.key;
    if (first_comp == 0) {
        return s1.id-s2.id;
    }
    return first_comp;
}