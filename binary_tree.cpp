// binary_tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>

#include "tree_node.h"

using namespace std;


template <class T>
void DeleteTree(TreeNode<T>* root)
{
    if (root != nullptr) {
        //  return;

        DeleteTree(root->Left());
        DeleteTree(root->Right());

        delete root;
    }
   // root = nullptr;
}

template <class T>
void PrintNode(const TreeNode<T>* node)
{
    if (node == nullptr)
    {
        cout << "Узел пуст" << endl;
    }
    else
    {
        cout << "Значение узла: " << node->data << endl;
    }
}
// создать объект TreeNode с указательными полями lptr и rptr.
// по умолчанию указатели содержат NULL.
template <class T>
TreeNode<T>* GetTreeNode(T item, TreeNode<T>* lptr = NULL,
    TreeNode<T>* rptr = NULL)
{
    TreeNode<T>* p;

    // вызвать new для создания нового узла
    // передать туда параметры lptr и rptr
    p = new TreeNode<T>(item, lptr, rptr);

    // если памяти недостаточно, завершить 
    // программу сообщением об ошибке
    if (p == NULL)
    {
        cout << 
            "Ошибка при выделении памяти!\n";
            exit(1);
    }
    // вернуть указатель на выделенную системой память
    return p;
}
int main()
{
    setlocale(LC_ALL, "rus");

    // Создание узлов
   /* TreeNode<int>* root = new TreeNode<int>(1, nullptr, nullptr);
    TreeNode<int>* node2 = new TreeNode<int>(2, nullptr, nullptr);
    TreeNode<int>* node3 = new TreeNode<int>(3, nullptr, nullptr);
    TreeNode<int>* node4 = new TreeNode<int>(4, nullptr, nullptr);
    TreeNode<int>* node5 = new TreeNode<int>(5, nullptr, nullptr);*/


    // Создание узлов
    TreeNode<int>* node5 = new TreeNode<int>(5, nullptr, nullptr);
    TreeNode<int>* node4 = new TreeNode<int>(4, nullptr, nullptr);
    TreeNode<int>* node3 = new TreeNode<int>(37, nullptr, nullptr);
    TreeNode<int>* node2 = new TreeNode<int>(2, node4, node5);
    TreeNode<int>* root = new TreeNode<int>(1, node2, node3);
    //// Установка связей между узлами
    //root->left = node2;
    //root->right = node3;
    //node2->left = node4;
    //node2->right = node5;

    root->data = 10;
 
    //     10
    //   2     37
    // 4 5     null  null  
    // 
    // Просмотр содержимого узлов
    PrintNode(root);
    PrintNode(node2);
    PrintNode(node3);
    PrintNode(node4);
    PrintNode(node5);

    GetTreeNode(12,node4,node5);
    // Удаление всех узлов
    DeleteTree(root);
    if (root == nullptr)
    {
        cout << "Дерево пустое";
    }
    return 0;
}