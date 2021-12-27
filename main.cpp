/*Подготовить текстовый файл, содержащий не менее 15 целых чисел.
 *Прочитать данные из этого файла и сформировать односвязный список.
 *Изменить последовательность указателей так, чтобы отрицательные числа находились в начале списка.
 *Распечатать исходный и итоговый списки.
 *После завершения работы со списком освободите занимаемую им динамическую память.

В списке реализовать:
1. Вставку\чтение\удаление из начала.
2. Вставку\чтение\удаление из конца.
3. Вставку\чтение\удаление элемента с индексом i.
Доступ к последнему элементу не должен приводить к просмотру\проходу всего списка.*/


#include <iostream>
#include <fstream>
#include "list.h"

using namespace std;


void ListIn(List *list)   // Чтение файла
{
    ifstream FileIn("Input.txt");
    //если файл был не создан, то вылезает ошибка
    if (FileIn.is_open())
        cout << "Код был успешно выполнен" << endl;
    else
    {
        cout << "Создайте файл Input.txt" << endl;
        exit(404);
    }

    int k;

    while (FileIn>>k)
    {
        list->append(k);
    }
    FileIn.close();
}


void ChangeList(List *list)
{

}

int main() {
    List list1;
    ListIn(&list1);
    list1.display();
    cout<<endl<<endl;
//    list1.popPos(4);
    list1.sort();
    list1.display();
//    list1.popPos(3);
//    list1.display();
//    cout<<list1.readPos(3);
//    list1.appPos(25, 3);
//    list1.display();
//    list1.sort();
//    list1.display();


    return 0;
}
