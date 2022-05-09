#include <iostream>
#include "deque.h"

using namespace std;

int main() {

    deque test;

    cout << (test.isEmpty() ? "empty!\n" : "full!\n");
    cout << (test.isFull() ? "full!\n" : "empty!\n");
    cout << "size: "<< test.size_d() << endl;
    test.pop_front();
    test.pop_back();
    test.push_back(150);
    test.push_back(160);
    test.push_front(90);
    test.push_front(80);
    cout << (test.isEmpty() ? "empty!\n" : "full!\n");
    cout << (test.isFull() ? "full!\n" : "empty!\n");
    cout << "size: "<< test.size_d() << endl;
    test.print_normal();
    test.print_backward();
    test.pop_front();
    test.print_normal();
    test.pop_back();
    test.print_normal();
    cout << "cleaning deque...\n";
    test.clear();
    cout << (test.isEmpty() ? "empty!\n" : "full!\n");
    cout << (test.isFull() ? "full!\n" : "empty!\n");
    cout << "size: "<< test.size_d() << endl;

}
