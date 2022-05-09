#ifndef DEQUE_H
#define DEQUE_H
#pragma once

#define MAX 10

//дэк, но с использованием статического массива

class deque {
public:

    int array[MAX];
    int front = 5;
    int back = 5;
    int size = 0;

    deque(){ //конструктор
        size = 0;
        front = back = 5;
    }

    ~deque(){ //деструктор
        this->clear();
    }

    void push_front(int x){ //вставить элемент в начало
        if (front == 0){
            std::cout<<"Deque is full!\n";
        }
        else {
            front--;
            array[front]=x;
            size++;
        }
    }

    void push_back(int x){ //вставить элемент в конец
        if (back == 10){
            std::cout << "Deque is full!\n";
        }
        else{
            array[back] = x;
            back++;
            size++;
        }
    }

    int pop_front(){ //удалить первый элемент
        if (front != back){
            front++;
            size--;
            return array[front - 1];
        }
        else {
            std::cout << "Deque is empty!\n";
            return array[front];
        }
    }

    int pop_back(){ //удалить последний элемент
        if (front != back){
            back--;
            size--;
            return array[back];

        }
        else {
            std::cout << "Deque is empty!\n";
            return array[back+1];
        }
    }

    bool isEmpty() const{ //пустой ли дэк
        return front == back;
    }

    bool isFull() const{
        return !(front==back);
    }

    void print_normal(){ //печать справа налево (от 0 до конца)
        for (int i = front; i < back; i++){
            std::cout<<array[i]<<" ";
        }
        std::cout<<std::endl;
    }

    void print_backward(){ //печать наоборот (от конца до 0)
        for (int i = back-1; i >= front; i--){
            std::cout<<array[i]<<" ";
        }
        std::cout<<std::endl;
    }

    int size_d() const{ //размер дэка
        return size;
    }

    int clear(){ //очистка дэка, используется в деструкторе
        if (front != back) {
            back = 5;
            front = 5;
            size = 0;
            return array[back];
        }
        else{
            std::cout << "Deque is already empty!\n";
            return 0;
        }

    }

};

#endif