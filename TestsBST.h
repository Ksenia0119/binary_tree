#pragma once
//@author Maltseva K.V.
#include "tree_node.h"
#include"TestsTreeNode.h"
#include"BinSearchTree.h"

using namespace std;
//тестирование конструктора копирования
template<class T>
void TestCopyConstructor() {
    // Создаем первое дерево
    BinSearchTree<int> tree1;
    tree1.Insert(5);
    tree1.Insert(3);
    tree1.Insert(8);

    // Создаем второе дерево и инициализируем его копией первого дерева
    BinSearchTree<int> tree2(tree1);

    // Проверяем размеры деревьев
    assert(tree1.ListSize() == 3);
    assert(tree2.ListSize() == 3);
    // Изменяем первое дерево
    tree1.Insert(10);

    // Проверяем, что изменение первого дерева не влияет на второе дерево
    assert(tree1.ListSize() == 4);
    assert(tree2.ListSize () == 3);

    cout << "Конструктор копирования тест пройден" << endl;
}
//тестирование оператора присваивания копирования
template<class T>
void TestCopyOperator() {
    // Создаем первое дерево
    BinSearchTree<int> tree1;
    tree1.Insert(5);
    tree1.Insert(3);
    tree1.Insert(7);
    // Создаем второе дерево,присвоив ему значения из первого через оператор присваивания копирования
    BinSearchTree<int> tree2;
    tree2 = tree1;
    // Проверяем размеры деревьев
    assert(tree1.ListSize() == 3);
    assert(tree2.ListSize() == 3);
    // Изменяем первое дерево
    tree1.Delete(7);

    // Проверяем, что изменение первого дерева не влияет на второе дерево
    assert(tree1.ListSize() == 2);
    assert(tree2.ListSize() == 3);

    cout << "Оператор присваивания копирования тест пройден" << endl;

}
//тестирование конструктора перемещения
template<class T>
void TestMoveConstructor() {
    // Создаем первое дерево
    BinSearchTree<int> tree1;
    tree1.Insert(5);
    tree1.Insert(3);
    tree1.Insert(7);
    // Вызываем конструктор перемещения данных из tree1 в tree2
    BinSearchTree<int> tree2 (std::move(tree1));
    // Проверяем размер и пустоту первого деревa
    assert(tree1.ListSize() == 0);
    assert(tree1.ListEmpty() ==true);
    //Проверяем, что tree2 содержит перемещенные данные
    assert(tree2.ListSize() == 3);
    assert(tree2.ListEmpty() == false);

    cout << "Конструктор перемещения тест пройден" << endl;
}
//Функция std::move() может использоваться всякий раз, когда нужно обрабатывать l - value 
// как r - value с целью использования семантики перемещения вместо семантики копирования.
template<class T>
void TestMoveOperator() {
    // Создаем первое дерево
    BinSearchTree<int> tree1;
    tree1.Insert(5);
    tree1.Insert(3);
    tree1.Insert(7);

    // Создаем второе дерево
    BinSearchTree<int> tree2;
    tree2.Insert(10);
    tree2.Insert(8);
    tree2.Insert(12);

  
    // Присваиваем второе дерево первому с помощью оператора присваивания с перемещением
    tree1 = std::move(tree2);// преобразование lvalue в rvalue - оператор присваивания с перемещением

    // Проверяем размер и пустоту первого дерева
    assert(tree1.ListSize() == 3);
    assert(tree1.ListEmpty() == false);
    // Проверяем, что tree2 стал пустым
    assert(tree2.ListSize() == 0);
    assert(tree2.ListEmpty() == true);

    cout << "Оператор присваивания перемещения тест пройден" << endl;
}

template<class T>
//тест вставка
void TestInsert() {
    // Создаем объект дерева
    BinSearchTree<T> tree;
    assert(tree.ListSize() ==0);
    // Вставляем элементы в дерево
    tree.Insert(5);
    assert(tree.ListSize() == 1);
    tree.Insert(3);
    assert(tree.ListSize() == 2);
    tree.Insert(7);
    assert(tree.ListSize() == 3);
    tree.Insert(2);
    assert(tree.ListSize() == 4);
    tree.Insert(4);
//перевести в массив и проверить
    // Проверяем размер дерева
    assert(tree.ListSize() == 5);
    cout << "Вставка пройдена" << endl;
}
template<class T>
//тест удаление
void TestRemove() {
    
    BinSearchTree<T> tree;

    // Вставляем элементы в дерево
    tree.Insert(5);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(2);
    tree.Insert(4);
    // Удаляем элементы из дерева
    tree.Delete(5);
    tree.Delete(2);

    // Проверяем размер дерева после удаления
    assert(tree.ListSize() == 3);
    // Получаем размер дерева
    int treeSize = tree.ListSize();

    // Создаем массив для хранения элементов дерева
    int* arr = new int[treeSize];

    // Печатаем дерево в массив
    PrintArr(tree.Curr(), arr, 0);


    // Проверяем ожидаемый результат
    assert(arr[0] == 3);
    assert(arr[1] == 4);
    assert(arr[2] == 7);

    // Освобождаем выделенную память
    delete[] arr;
    cout << "Удаление тест пройден" << endl;
}
template<class T>
//тест поиск
void TestFind() {

    BinSearchTree<T> tree;

    // Вставляем элементы в дерево
    tree.Insert(5);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(2);
    tree.Insert(4);

    // Проверяем поиск элементов
    assert(tree.Find(5)==0);  // Элемент 5 должен быть найден
    assert(tree.Find(2)==2);  // Элемент 2 должен быть найден
    assert(tree.Find(6)==-1); // Элемент 6 не должен быть найден
    cout << "Поиск тест пройден" << endl;
}
//создаем тестовое бинарное дерево 
BinSearchTree<int> CreateTestBST() {
    // Создаем объект класса BinSearchTree
    BinSearchTree<int> bst;

    bst.Insert(35);
    bst.Insert(25);
    bst.Insert(7);
    bst.Insert(16);
    bst.Insert(15);
    bst.Insert(3);
    bst.Insert(26);
    bst.Insert(38);
    bst.Insert(40);
    bst.Insert(39);
    bst.Insert(55);
    return bst;
}

//создаем тестовое вырожденное влево бинарное дерево 
BinSearchTree<int> CreateTestBSTLeft() {
    // Создаем объект класса BinSearchTree
    BinSearchTree<int> bst;

    bst.Insert(27);
    bst.Insert(25);
    bst.Insert(17);
    bst.Insert(16);
    bst.Insert(10);
    bst.Insert(9);
    bst.Insert(6);
    bst.Insert(4);
    bst.Insert(2);
    bst.Insert(1);
    return bst;
}
void TestBSTIterator() {
    BinSearchTree<int> bst= CreateTestBST();

    // Получаем итератор начала списка
    auto it = bst.begin();

    // Проверяем значение текущего узла через оператор разыменования
    assert(*it == 3);


    BinSearchTree<int> bst1 = CreateTestBSTLeft();
    // Получаем итератор начала списка
    auto it1 = bst1.begin();

    // Проверяем значение текущего узла через оператор разыменования
    assert(*it1 == 1);

    cout << "Итератор начала BST пройден" << endl;
}
void TestBSTDataOperator() {
    BinSearchTree<int> bst = CreateTestBST();

    // Получаем итератор начала списка
    auto it = bst.begin();

    // Проверяем значение текущего узла через оператор разыменования
    assert(*it == 3);

    // Переходим к следующему узлу
    ++it;

    // Проверяем значение текущего узла через оператор разыменования
    assert(*it == 7);
    ++it;
    assert(*it == 15);
    ++it;
    assert(*it == 16);


    BinSearchTree<int> bst1 = CreateTestBSTLeft();
    // Получаем итератор начала списка
    auto it1 = bst1.begin();

    // Проверяем значение текущего узла через оператор разыменования
    assert(*it1 == 1);

    // Переходим к следующему узлу
    ++it1;

    // Проверяем значение текущего узла через оператор разыменования
    assert(*it1 == 2);
    ++it1;
    assert(*it1 == 4);
    ++it1;
    assert(*it1 == 6);
    cout << "Оператор разыменования пройден" << endl;
}

// тест инкремента итератора
void TestIncOperator() {
    BinSearchTree<int> bst = CreateTestBST();

    // Получаем итератор начала списка
    auto it = bst.begin();

    // Проверяем значение текущего узла через оператор разыменования
    assert(*it == 3);

    // Переходим к следующему узлу
    ++it;

    // Проверяем значение текущего узла через оператор разыменования
    assert(*it == 7);
    ++it;
    assert(*it == 15);
    ++it;
    assert(*it == 16);
    ++it;
    assert(*it == 25);
    ++it;
    assert(*it == 26);
    ++it;
    assert(*it == 35);
    ++it;
    assert(*it == 38);
    ++it;
    assert(*it == 39);
    ++it;
    assert(*it == 40);
    ++it;
    assert(*it == 55);
   
    cout << "Оператор разыменования пройден" << endl;
}
//тест оператора равенства
void TestOperatorEqual() {
    BinSearchTree<int> bst = CreateTestBST();

    //Получаем итераторы
    auto it1 = bst.begin();
    auto it2 = bst.begin();

    // Проверяем, что итераторы равны друг другу с помощью оператора равенства
    assert(it1 == it2);



    cout << "Оператор равенства пройден" << endl;
}

void TestOperatorUnequal() {
    BinSearchTree<int> bst = CreateTestBST();

    //Получаем итераторы
    auto it1 = bst.begin();
    auto it2 = bst.begin();
    ++it2;
    // Проверяем, что итераторы равны друг другу с помощью оператора равенства
    assert(it1 != it2);



    cout << "Оператор неравенства пройден" << endl;
}
