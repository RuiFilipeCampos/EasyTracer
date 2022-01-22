#include <iostream>

using namespace std; 

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList(){};


template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(){};

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(T first_element){
    this->head.content = first_element;
    this->head.next = NULL;
};


template <typename T>
void SinglyLinkedList<T>::print_contents(){
    Node<T> *node_ptr = &this->head;
    cout << node_ptr->content;
    while (node_ptr->next != NULL) {
        cout << node_ptr->content;
        node_ptr = node_ptr->next;
    };
};


template <typename T>
T SinglyLinkedList<T>::operator[](int index){
    int i = 0;

    while (1){
        
    };
    
};

template <typename T>
Node<T> *SinglyLinkedList<T>::get_last_node(){
    Node<T> *node_ptr = &this->head;

    while (node_ptr->next != NULL){
        node_ptr = node_ptr->next;
    };

    return node_ptr;
};

template <typename T>
void SinglyLinkedList<T>::append(T value){
    Node<T> *last_node = this->get_last_node();

    last_node->next = new Node<T>;
    last_node->next->content = value;

};

