//
// Created by Анатолий Миронченко on 13.12.2021.
//

#include <iostream>
#include "list.h"

using namespace std;

List::~List() {
    Node* current = head;
    while( current != nullptr ) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}


void List::appstart(int value) {
    Node *new_node = new Node();
    new_node->data = value;
    if (head == nullptr){
        new_node->next = nullptr;
        head = new_node;
        last = new_node;
    }else{
        new_node->next = head;
        head = new_node;
    }
    sizeOfList++;
} //вставить в начало элемент

int List::pop() {
    if (head == nullptr) {
        cout << "Not allowed function POP for empty List" << endl;
        throw "Not allowed function POP for empty List";
    }
    // ??
    Node *delNode = head;
    head = head->next;
    int first = delNode->data;
    if (head == nullptr)
        last = nullptr;
    delete delNode;
    sizeOfList--;
    return first;
} //удалалить первый элемент

int List::readstart() {
    int val;
    if (head == nullptr){
        cout<<"список пуст"<<endl;
        throw "Not allowed function POP for empty List";
    }
    val = this->head->data;
    return val;
} // прочитать первый элемент


void List::append(int value) {
    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = nullptr;
    if (head == nullptr) {
        head = new_node;
        last = new_node;
    }
    else{
        last->next = new_node;
        last = new_node;
    }
    sizeOfList++;
} // добавить в конец элемент

int List::popend() {
    int res = 0;
    if (last == nullptr) {
        cout << "Not allowed function POP for empty List" << endl;
        throw "Not allowed function POP for empty List";
    }else{
        Node* delLast = last;
        last = head->next;
        while(last->next != delLast){
            last = last->next;
        }
        last->next = nullptr;
        res = delLast->data;
        delete delLast;
        sizeOfList--;
    }
    return res;
} // удалить элемент с конца

int List::readend() {
    if (last == nullptr){
        throw "список пуст";
    }
    int value = last->data;
    return value;
} // чтение последнего элемента


int List::readPos(int position) {
    Node *res = head;
    int i = 0;
//    bool flag = false;
    if (position > sizeOfList){
        throw "position > sizeOfList";
    }
    while (res){
        if (i == position){
            return res->data;
        }
        i++;
        res = res->next;
    }
}

void List::appPos(int app, int position) {
    cout<<"вставка"<<endl;
    Node *last1 = head;
    int  i = 0;
    bool flag = false;
    if (position > sizeOfList){
        throw "position > sizeOfList";
    }
    while (last1){
        if (i+1 == position){
            Node *pos = new Node;
            pos->data = app;
            pos->next = last1->next;
            last1->next = pos;
            sizeOfList++;
            flag = true;
        }
        if (flag){break;}
        i++;
        last1 = last1->next;
    }
}

int List::popPos(int position)
{
//    cout<<"удаление"<<endl;
    Node *last1 = head;
    int  i = 0;
    int res = 0;
    bool flag = false;
    if (position > sizeOfList){
        throw "position > sizeOfList";
    }
    while (last1){
        if (last1->next != nullptr && i+1 == position){
            res = last1->next->data;
            Node *pos = last1->next;
            last1->next = last1->next->next;
            delete pos;
            sizeOfList--;
            flag = true;
        }
        if (flag){break;}
        i++;
        last1 = last1->next;
    }
    return res;
}


void List::display() {
    if (head == nullptr) {
        cout << "Sorry,but head is not defined" << endl;
        return;
    } else {
        int i = 0;
        Node *print = head;
        while (print) {
            printf("In %d position value: %d \n", i++, print->data);
            print = print->next;
        }
    }
}

int List::size() const {
    return sizeOfList;
}

int List::front() const{
    if (head == nullptr)
        throw "Head == nullptr";
    return head->data;
}

void List::sort()
{
    Node *inHead = head;
    int i = 0;
    while(inHead){
        if (inHead->next != nullptr && inHead->next->data < 0){
            Node *inh = inHead->next;
            inHead->next = inHead->next->next;
            inh->next = head;
            head = inh;
            i++;
        }else{
            i++;
            inHead = inHead->next;
        }
    }
    last = head;
    while (last->next != nullptr){
        last = last->next;
    }
}