#pragma once
//@author Maltseva K.V.

#include "tree_node.h"

// Функция для заполнения дерева случайными числами
//int numNodes - число узлов, T minValue - минимальное, T maxValue - максимальное
template <class T>
void TreеRandom(TreeNode<T>* root, int numNodes, T minValue, T maxValue) {
    for (int i = 0; i < numNodes; i++) {
        T randomNum = rand() % (maxValue - minValue + 1) + minValue;
        AddNode(root, randomNum);
    }
}
//Функция для создания дерева с конкретными значениями в данных узлов
template <class T>
TreeNode<T>* CreateTree() {
    TreeNode<int>* root = new TreeNode<int>(35, nullptr, nullptr);
    AddNode(root, 25);
    AddNode(root, 7);
    AddNode(root, 16);
    AddNode(root, 15);
    AddNode(root, 3);
    AddNode(root, 26);
    AddNode(root, 38);
    AddNode(root, 40);
    AddNode(root, 39);
    AddNode(root, 55); 
    return root;
}

//тестирование функции копирования дерева
void TestCopyTree()
{
    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root = new TreeNode<int>(25, nullptr, nullptr);
    TreеRandom(root, 10, 10, 50);
    //Копирование дерева
    TreeNode<int>* copiedRoot = CopyTree(root);
     DeleteTree(root);
     PrintTree(root, 1);
    cout << "Копия дерева" << endl;
    PrintTree(copiedRoot, 1);
    assert(root == nullptr);
    assert(copiedRoot !=nullptr );
    assert(copiedRoot->data = 25);


    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root1 = new TreeNode<int>(15, nullptr, nullptr);
    TreеRandom(root, 5, 5, 20);
    //Копирование дерева
    TreeNode<int>* copiedRoot1 = CopyTree(root1);
    DeleteTree(root1);
    assert(root1 == nullptr);
    assert(copiedRoot1 != nullptr);
    assert(copiedRoot1->data = 15);

    cout << "Копирование дерева пройдено" << endl;
}

//тестирование функции удаления узла 
void TestRemove()
{
    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root = CreateTree<int>();
    PrintTree(root, 1);

    Remove(root, 38);
    TreeNode<int>* node38 = root->right;
    assert(node38 != nullptr);
    assert(node38->data == 40);
    cout << endl;
    PrintTree(root, 1);
    cout << endl;
    cout << endl;

    Remove(root, 7);
    TreeNode<int>* node7 = root->left->left;
    assert(node7 != nullptr);
    assert(node7->data == 15);
    cout << endl;
    PrintTree(root, 1);
    cout << endl;
    cout << endl;


    Remove(root, 15);
    TreeNode<int>* node15 = root->left->left;
    assert(node15 != nullptr);
    assert(node15->data == 16);
    cout << endl;
    PrintTree(root, 1);
    cout << endl;
    cout << endl;


    Remove(root, 3);
    TreeNode<int>* node3 = root->left->left->left;
    assert(node3 == nullptr);
    cout << endl;
    PrintTree(root, 1);
    cout << endl;
    cout << endl;

    Remove(root, 40);
    TreeNode<int>* node40 = root->right;
    assert(node40 != nullptr);
    assert(node40->data == 55);
    cout << endl;
    PrintTree(root, 1);
    cout << endl;
    cout << endl;

    // Освобождаем память, удаляя дерево
    DeleteTree(root);
    cout << "Удаление пройдено" << endl;
}
//тестирование функции поиска
void TestSearch() {
    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root = CreateTree<int>();
    PrintTree(root, 1);

    assert(Search(root, 35) == 0); // Значение 35 находится на уровне 0
    assert(Search(root, 25) == 1); // Значение 25 находится на уровне 1
    assert(Search(root, 38) == 1); // Значение 38 находится на уровне 1
    assert(Search(root, 7) == 2);  // Значение 7 находится на уровне 2
    assert(Search(root, 26) == 2); // Значение 26 находится на уровне 2
    assert(Search(root, 40) == 2); // Значение 40 находится на уровне 2
    assert(Search(root, 16) == 3); // Значение 16 находится на уровне 3
    assert(Search(root, 3) == 3);  // Значение 3 находится на уровне 3 
    assert(Search(root, 39) == 3); // Значение 39 находится на уровне 3
    assert(Search(root, 55) == 3); // Значение 55 находится на уровне 3
    assert(Search(root, 15) == 4); // Значение 15 находится на уровне 4
    // Тестируем поиск на отсутствующих значениях
    assert(Search(root, 1) == -1);  // Значение 1 отсутствует в дереве
    assert(Search(root, 9) == -1);  // Значение 9 отсутствует в дереве
    assert(Search(root, 100) == -1);  // Значение 100 отсутствует в дереве

    // Освобождаем память, удаляя дерево
    DeleteTree(root);
    cout << "Поиск пройден" << endl;
}
//тестирование функции добавления
void TestAddNode() {
    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root = new TreeNode<int>(40, nullptr, nullptr);
    AddNode(root, 25);
    AddNode(root, 70);
    AddNode(root, 30);
    AddNode(root, 45);
    AddNode(root, 43);

    //PrintTree(root, 1);


    // Уровень 0
    assert(root->data == 40);

    // Уровень 1
    assert(root->left->data == 25);
    assert(root->right->data == 70);

    // Уровень 2
    assert(root->left->left == nullptr);
    assert(root->left->right->data == 30);
    assert(root->right->right == nullptr);
    assert(root->right->left->data == 45);

    // Уровень 3
    assert(root->right->left->left->data == 43);

    // Освобождаем память, удаляя дерево
    DeleteTree(root);

    cout << "Добавление пройдено" << endl;
}
//тестирование функции глубины
void TestDepth() {
    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root = new TreeNode<int>(25, nullptr, nullptr);
    TreеRandom(root, 9, 11, 87);
    // Проверяем глубину дерева
     assert(Depth(root) ==3 );
    // Освобождаем память, удаляя дерево
    DeleteTree(root);

    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root1 = new TreeNode<int>(15, nullptr, nullptr);
    // Проверяем глубину дерева
    assert(Depth(root1) == 0);
    // Освобождаем память, удаляя дерево
    DeleteTree(root1);


    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root2 = new TreeNode<int>(23, nullptr, nullptr);
    TreеRandom(root, 21, 1, 80);
    // Проверяем глубину дерева
    assert(Depth(root2) == 8);
    // Освобождаем память, удаляя дерево
    DeleteTree(root2);
    cout << "Подсчет глубины пройден" << endl;
}
//тестирование функции подсчета узлов
void TestCountNodes() {
    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root = new TreeNode<int>(35, nullptr, nullptr);
    TreеRandom(root, 10, 20, 100);
    PrintTree(root, 1);
    // Проверяем количество узлов в дереве
    assert(CountNodes(root) == 11);
    // Освобождаем память, удаляя дерево
    DeleteTree(root);

    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root1 = new TreeNode<int>(15, nullptr, nullptr);
    // Проверяем количество узлов в дереве
    assert(CountNodes(root1) == 1);
    // Освобождаем память, удаляя дерево
    DeleteTree(root1);

    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root2 = new TreeNode<int>(40, nullptr, nullptr);
    TreеRandom(root, 5, 20, 50);
    // Проверяем количество узлов в дереве
    assert(CountNodes(root2) == 6);
    // Освобождаем память, удаляя дерево
    DeleteTree(root2);

    cout << "Подсчет узлов пройден" << endl;
}

//void TestDeleteTree() {
//    // Создаем бинарное дерево для тестирования
//    TreeNode<int>* root = new TreeNode<int>(35, nullptr, nullptr);
//    AddNode(root, 25);
//    AddNode(root, 7);
//    AddNode(root, 16);
//    AddNode(root, 15);
//    AddNode(root, 3);
//    AddNode(root, 26);
//    AddNode(root, 38);
//    AddNode(root, 40);
//    AddNode(root, 39);
//    AddNode(root, 55);
//    // Удаляем дерево
//    DeleteTree(root);
//    // Проверяем, что корень и все узлы дерева удалены (равны nullptr)
//    //assert(left);
//    assert((left == nullptr && right == nullptr));
//    /*assert(root->right == nullptr);
//    assert(root->left->left == nullptr);
//    assert(root->left->right == nullptr);
//    assert(root->right->left == nullptr);
//    assert(root->right->right->right == nullptr);
//    assert(root->right->right->left == nullptr);
//    assert(root->left->left->left == nullptr);
//    assert(root->left->left->right == nullptr);*/
//    cout << "Удаление дерево пройдено" << endl;
//}
//тестирование функции подсчета листьев

//тестирование функции подсчета листьев
void TestCountLeaf() {
    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root = new TreeNode<int>(35, nullptr, nullptr);
    TreеRandom(root, 10, 10, 50);
    int count = 0;
    CountLeaf(root, count);
    // Проверяем, что количество листьев равно ожидаемому значению
    assert(count == 3);
    // Освобождаем память, удаляя дерево
    DeleteTree(root);



    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root2 = new TreeNode<int>(40, nullptr, nullptr);
    TreеRandom(root, 15, 20, 60);
    int count2 = 0;
    CountLeaf(root2, count2);
    // Проверяем, что количество листьев равно ожидаемому значению
    assert(count == 5);
    // Освобождаем память, удаляя дерево
    DeleteTree(root2);
    cout << "Подсчет листьев пройден" << endl;
}