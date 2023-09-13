//@author Maltseva K.V.
// 
#include <iostream>
#include "tree_node.h"



int main()
{
    setlocale(LC_ALL, "rus");

    // Создание узлов
    TreeNode<int>* root = new TreeNode<int>(1, nullptr, nullptr);
    TreeNode<int>* node2 = new TreeNode<int>(2, nullptr, nullptr);
    TreeNode<int>* node3 = new TreeNode<int>(3, nullptr, nullptr);
    TreeNode<int>* node4 = new TreeNode<int>(4, nullptr, nullptr);
    TreeNode<int>* node5 = new TreeNode<int>(5, nullptr, nullptr);
    TreeNode<int>* node6 = new TreeNode<int>(6, nullptr, nullptr);
    root->left = node2;
    root->right = node3;
    node3->left = node4;
    node3->right = node5;
    node5->right = node6;
    //     1
    //   2             3
    // null null     4     5
    //                  6
    // Создание узлов

    /*TreeNode<int>* node5 = new TreeNode<int>(8, nullptr, nullptr);
    TreeNode<int>* node4 = new TreeNode<int>(7, nullptr, nullptr);
    TreeNode<int>* node3 = new TreeNode<int>(37, nullptr, nullptr);
    TreeNode<int>* node2 = new TreeNode<int>(2, node4, node5);
    TreeNode<int>* root = new TreeNode<int>(10, node2, node3);*/
    //// Установка связей между узлами
    root->left = node2;
    root->right = node3;
    node3->left = node4;
    node3->right = node5;
 
    //     10
    //   2     37
    // null null     7  8 
    // 
    // Просмотр содержимого узлов
   /* PrintNode(root);*/
   /* PrintNode(node2);
    PrintNode(node3);
    PrintNode(node4);
    PrintNode(node5);*/

   // GetTreeNode(12,node4,node5);
    // Удаление всех узлов
   // DeleteTree(root);
   // PrintNode(node3);
    //Inorder(root,PrintNode(data));
    int leafCount = 0;

    Postorder(root);
   
    cout << endl;
    Inorder(root);
    cout << endl;
    Preorder(root);
    cout << endl;
    CountLeaf(root, leafCount);
    PrintTree(root, Depth(root));
    cout << "Число листьев в дереве равно = " << leafCount << endl;
    cout << "Глубина дерева равна = " << Depth(root) << endl;

    //GetTreeNode(10,node6);
    PrintTree(root, Depth(root));
    return 0;
}