#pragma once
//@author Maltseva K.V.
#include "tree_node.h"
#include"BinSearchTree.h"

using namespace std;
//тестирование конструктора копировани€
template<class T>
void TestCopyConstructor() {
    // —оздаем первое дерево
    BinSearchTree<int> tree1;
    tree1.Insret(5);
    tree1.Insret(3);
    tree1.Insret(8);

    // —оздаем второе дерево и инициализируем его копией первого дерева
    BinSearchTree<int> tree2(tree1);

    // ѕровер€ем размеры деревьев
    assert(tree1.ListSize() == 3);
    assert(tree2.ListSize() == 3);
    // »змен€ем первое дерево
    tree1.Insret(10);

    // ѕровер€ем, что изменение первого дерева не вли€ет на второе дерево
    assert(tree1.ListSize() == 4);
    assert(tree2.ListSize () == 3);

    cout << " онструктор копировани€ тест пройден" << endl;
}
//тестирование оператора присваивани€ копировани€
template<class T>
void TestCopyOperator() {
    // —оздаем первое дерево
    BinSearchTree<int> tree1;
    tree1.Insret(5);
    tree1.Insret(3);
    tree1.Insret(7);
    // —оздаем второе дерево,присвоив ему значени€ из первого через оператор присваивани€ копировани€
    BinSearchTree<int> tree2;
    tree2 = tree1;
    // ѕровер€ем размеры деревьев
    assert(tree1.ListSize() == 3);
    assert(tree2.ListSize() == 3);
    // »змен€ем первое дерево
    tree1.Delete(7);

    // ѕровер€ем, что изменение первого дерева не вли€ет на второе дерево
    assert(tree1.ListSize() == 2);
    assert(tree2.ListSize() == 3);

    cout << "ќператор присваивани€ копировани€ тест пройден" << endl;

}
//тестирование конструктора перемещени€
template<class T>
void TestMoveConstructor() {
    // —оздаем первое дерево
    BinSearchTree<int> tree1;
    tree1.Insret(5);
    tree1.Insret(3);
    tree1.Insret(7);
    // ¬ызываем конструктор перемещени€ данных из tree1 в tree2
    BinSearchTree<int> tree2 (std::move(tree1));
    // ѕровер€ем размер и пустоту первого деревa
    assert(tree1.ListSize() == 0);
    assert(tree1.ListEmpty() ==true);
    //ѕровер€ем, что tree2 содержит перемещенные данные
    assert(tree2.ListSize() == 3);
    assert(tree2.ListEmpty() == false);

    cout << " онструктор перемещени€ тест пройден" << endl;
}
//‘ункци€ std::move() может использоватьс€ вс€кий раз, когда нужно обрабатывать l - value 
// как r - value с целью использовани€ семантики перемещени€ вместо семантики копировани€.
template<class T>
void TestMoveOperator() {
    // —оздаем первое дерево
    BinSearchTree<int> tree1;
    tree1.Insret(5);
    tree1.Insret(3);
    tree1.Insret(7);

    // —оздаем второе дерево
    BinSearchTree<int> tree2;
    tree2.Insret(10);
    tree2.Insret(8);
    tree2.Insret(12);

  
    // ѕрисваиваем второе дерево первому с помощью оператора присваивани€ с перемещением
    tree1 = std::move(tree2);// преобразование lvalue в rvalue - оператор присваивани€ с перемещением

    // ѕровер€ем размер и пустоту первого дерева
    assert(tree1.ListSize() == 3);
    assert(tree1.ListEmpty() == false);
    // ѕровер€ем, что tree2 стал пустым
    assert(tree2.ListSize() == 0);
    assert(tree2.ListEmpty() == true);

    cout << "ќператор присваивани€ перемещени€ тест пройден" << endl;
}