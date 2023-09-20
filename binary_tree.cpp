//@author Maltseva K.V.
// 
#include <iostream>
#include <vector>
#include "tree_node.h"



int main()
{
    setlocale(LC_ALL, "rus");

    // Создание узлов
   /* TreeNode<int>* root = new TreeNode<int>(5, nullptr, nullptr);
    TreeNode<int>* node2 = new TreeNode<int>(3, nullptr, nullptr);
    TreeNode<int>* node3 = new TreeNode<int>(6, nullptr, nullptr);
    TreeNode<int>* node4 = new TreeNode<int>(4, nullptr, nullptr);
    TreeNode<int>* node5 = new TreeNode<int>(7, nullptr, nullptr);
    TreeNode<int>* node6 = new TreeNode<int>(8, nullptr, nullptr);
    root->left = node2;
    root->right = node3;
    node3->left = node4;
    node3->right = node5;
    node5->right = node6;*/
    //     1
    //   2               3
    // null null     4       5
    // 
    //                     6   null  
    // Создание узлов

    /*TreeNode<int>* node5 = new TreeNode<int>(8, nullptr, nullptr);
    TreeNode<int>* node4 = new TreeNode<int>(7, nullptr, nullptr);
    TreeNode<int>* node3 = new TreeNode<int>(37, nullptr, nullptr);
    TreeNode<int>* node2 = new TreeNode<int>(2, node4, node5);
    TreeNode<int>* root = new TreeNode<int>(10, node2, node3);*/
    //// Установка связей между узлами

    //вектор , из которого будет построено дерево
    vector<int> vec={19,5,23,24,3,22,25};
 
    int leafCount = 0;
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
    cout << "Обратный проход" << endl;
    Postorder_print(root);
   
    cout << endl;
    cout << "Симметричный проход" << endl;
    Inorder_print(root);
    cout << endl;
    cout << "Прямой проход" << endl;
    Preorder_print(root);
    cout << endl;
    CountLeaf(root, leafCount);
    PrintTree(root,0);
    cout << "Число листьев в дереве = " << leafCount << endl;
    cout << "Глубина дерева = " << Depth(root) << endl;
    //Search(root,5);

    cout <<"Число узлов в дереве = "<<CountNodes(root);
    cout << endl;
   
   int* arr = new int[CountNodes(root)];
    PrintArr(root, arr, 0);
    for (int i = 0; i < CountNodes(root); i++) {
        cout << arr[i]<<"  ";
    }
    cout << endl;
   
    cout << "Значение найдено в дереве на уровне = "<<Search(root, 55) << endl;

    
    
    Remove(root,7 );
    PrintTree(root, 0);
    cout << endl;
    cout << endl;
    //BinaryTreeFromVector(vec);
    //PrintTree(root, 0);
    //TestRemove();
    TestSearch();
    TestAddNode();
    TestDepth();
    TestCountNodes();
    TestCountLeaf();
    delete arr;

    /*bool found = Search(root, 55);
   if (found) {
       cout << "Значение найдено в дереве" << endl;
   }
   else {
       cout << "Значение не найдено в дереве" << endl;
   }*/
    return 0;
}