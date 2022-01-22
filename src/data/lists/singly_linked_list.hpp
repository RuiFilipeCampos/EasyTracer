#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct Node{
    T content;
    Node<T> *next;
};

template <typename T>
class SinglyLinkedList{
    private:
        Node<T> head;
        Node<T> *get_last_node();
    
    public:
        SinglyLinkedList(){};
        ~SinglyLinkedList(){};

        SinglyLinkedList(T first_element){
            this->head.content = first_element;
            this->head.next = NULL;
        };

        void print_contents(){
            Node<T> *node_ptr = &this->head;
            cout << node_ptr->content;
            while (node_ptr->next != NULL) {
                cout << node_ptr->content;
                node_ptr = node_ptr->next;
            };
        };

        void append(T value){
            Node<T> *last_node = this->get_last_node();
            last_node->next = new Node<T>;
            last_node->next->content = value;
        };  
};

