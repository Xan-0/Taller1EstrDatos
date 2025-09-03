#include "LinkedList.hpp"

LinkedList::LinkedList(){
    start = nullptr;
}

/*void LinkedList::add(int value){
    if (start == nullptr) {
        Node *nuevo = new Node();
        nuevo -> setValue(value);
        nuevo -> setNext(nullptr);
        start = nuevo;
        return;
    }
    
    Node *cursor = start;
    while (cursor -> getNext() != nullptr){
        cursor = cursor -> getNext();
    }
    
    Node *add = new Node();
    add -> setValue(value);
    add -> setNext(nullptr);
    cursor -> setNext(add);
    return;
}*/

void LinkedList::add(int value, int index){
    if (start == nullptr) {
        if (index == 0){
            Node *nuevo = new Node();
            nuevo -> setValue(value);
            nuevo -> setNext(nullptr);
            start = nuevo;
            return;
        }
        return;
    }
    
    int i = 0;
    Node *cursor = start;
    Node *anterior = nullptr;
    while (cursor -> getNext() != nullptr){
        if(i == index){
            break;
        }
        anterior = cursor;
        cursor = cursor -> getNext();
        i++;
    }
    Node *add = new Node();
    add -> setValue(value);
    
    anterior -> setNext(add);
    add -> setNext(cursor);
    return;
}

void LinkedList::remove(int index){
    if (start == nullptr){
        return;
    }
    
    int i = 0;
    Node *cursor = start;
    Node *anterior = nullptr;
    while (cursor -> getNext() != nullptr){
        if(i == index){
            break;
        }
        anterior = cursor;
        cursor = cursor -> getNext();
        i++;
    }
    Node *siguiente = cursor -> getNext();
    cursor -> ~Node();
    
    if (siguiente != nullptr){
        anterior -> setNext(siguiente);
        return;
    }
    anterior -> setNext(nullptr);
    return;
}

int LinkedList::get(int index){
    if (start == nullptr){
        return 0;
    }
    
    int i = 0;
    Node *cursor = start;
    while (cursor -> getNext() != nullptr){
        if(i == index){
            return cursor -> getValue();
        }
        cursor = cursor -> getNext();
        i++;
    }
    
    if(index == 0){
        return start -> getValue();
    }
    return 0;
}

bool LinkedList::isEmpty(){
    if (start == nullptr){
        return true;
    }
    return false;
}