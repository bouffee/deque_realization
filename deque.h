#ifndef DEQUE_H
#define DEQUE_H
#pragma once

//дэк, но с указателями

class deque {
private:

    struct node{
        node* next;
        node* previous;
        int num;
        int check= 0;
        explicit node (const int itm, node *n = nullptr, node *p = nullptr){
            num = itm;
            check++;
            next = n;
            previous = p;
        }

    };

    int size;
    node *first;
    node *last;

public:

    deque(){ //конструктор
        size = 0;
        first = last = nullptr;
    }

    ~deque(){ //деструктор
        this->clear();
    }

    void push_front(int x){ //вставить в начало дэка число
        node *node_temp = new node(x);
        if (first == nullptr){
            last = node_temp;
        }
        else {
            first->previous = node_temp;
            node_temp->next = first;
        }
        first = node_temp;
        size++;
    }

    void push_back(int x){ //вставить в конец дэка число
        node *node_temp = new node(x);
        if (last == nullptr){
            first = node_temp;
        }
        else {
            last->next = node_temp;
            node_temp->previous = last;
        }
        last = node_temp;
        size++;
    }

    void pop_front(){ //удалить первый элемент дэка
        node* node_temp;
        if(first != nullptr){
            node_temp = first;
            first = first->next;
            delete node_temp;
            if(first == nullptr){
                last = nullptr;
            }
            else first->previous = nullptr;
            size--;
        }
        else {
            std::cout<<"Error! Nothing to delete\n";
        }
    }

    void pop_back(){ //удалить последний элемент дэка
        node* node_temp;
        if(last != nullptr){
            node_temp = last;
            last = last->previous;
            delete node_temp;
            if(last == nullptr){
                first = nullptr;
            }
            else last->next = nullptr;
            size--;
        }
        else {
            std::cout<<"Error! Nothing to delete\n";
        }
    }

    bool isEmpty() const{
        if (size == 0){
            return true;
        }
        return false;
    }

    bool isFull() const{
        if (size != 0){
            return true;
        }
        else false;
    }

    void print_normal(){ //печать дэка с первого элемента и до последнего
        node *front = first;
        if(front == nullptr){
            std::cout<<"Deque is empty!";
        }
        while (front){
            std::cout << front->num << " ";
            front = front->next;
        }
        std::cout << "\n";
    }

    void print_backward(){ //печать дэка с последнего элемента и до первого
        node *back = last;
        if (back == nullptr){
            std::cout<<"Deque is empty!";
        }
        while (back){
            std::cout << back->num << " ";
            back = back->previous;
        }
        std::cout << "\n";
    }

    int size_d() const{ //размер дэка
        return size;
    }

    void clear(){ //очистить дэк, используется в деструкторе
        node *current = nullptr;
        node *next = first;
        while (next){
            current = next;
            next = next->next;
            delete current;
        }
        size = 0;
        first = last = nullptr;
    }

};

#endif
