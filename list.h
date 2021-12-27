//
// Created by Анатолий Миронченко on 13.12.2021.
//

#ifndef SIAODVEVMLAB3_LIST_H
#define SIAODVEVMLAB3_LIST_H


class List {
private:
    int sizeOfList=0;
    class Node {
    public:
        int data;
        Node* next;
    };
    Node* head;
    Node* last;
public:
    List() {head = nullptr; last = nullptr;}
    ~List();
    void appstart(int value); //вставить в начало элемент
    int pop(); // удалалить первый элемент
    int readstart(); // прочитать первый элемент

    void append(int value); // добавить в конец элемент
    int popend(); // удалить элемент с конца
    int readend(); // чтение последнего элемента

    int readPos(int position);
    void appPos(int app, int position);
    int popPos(int position);


    void display();
    int size() const;
    int front() const;
    void sort();

    List& operator= (const List &list);
};

#endif //SIAODVEVMLAB3_LIST_H
