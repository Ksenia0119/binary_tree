#pragma once
//@author Maltseva K.V.

#include "tree_node.h"

// ������� ��� ���������� ������ ���������� �������
//int numNodes - ����� �����, T minValue - �����������, T maxValue - ������������
template <class T>
void Tre�Random(TreeNode<T>* root, int numNodes, T minValue, T maxValue) {
    for (int i = 0; i < numNodes; i++) {
        T randomNum = rand() % (maxValue - minValue + 1) + minValue;
        AddNode(root, randomNum);
    }
}
//������� ��� �������� ������ � ����������� ���������� � ������ �����
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

//������������ ������� ����������� ������
void TestCopyTree()
{
    // ������� �������� ������ ��� ������������
    TreeNode<int>* root = new TreeNode<int>(25, nullptr, nullptr);
    Tre�Random(root, 10, 10, 50);
    //����������� ������
    TreeNode<int>* copiedRoot = CopyTree(root);
     DeleteTree(root);
     PrintTree(root, 1);
    cout << "����� ������" << endl;
    PrintTree(copiedRoot, 1);
    assert(root == nullptr);
    assert(copiedRoot !=nullptr );
    assert(copiedRoot->data = 25);


    // ������� �������� ������ ��� ������������
    TreeNode<int>* root1 = new TreeNode<int>(15, nullptr, nullptr);
    Tre�Random(root, 5, 5, 20);
    //����������� ������
    TreeNode<int>* copiedRoot1 = CopyTree(root1);
    DeleteTree(root1);
    assert(root1 == nullptr);
    assert(copiedRoot1 != nullptr);
    assert(copiedRoot1->data = 15);

    cout << "����������� ������ ��������" << endl;
}

//������������ ������� �������� ���� 
void TestRemove()
{
    // ������� �������� ������ ��� ������������
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

    // ����������� ������, ������ ������
    DeleteTree(root);
    cout << "�������� ��������" << endl;
}
//������������ ������� ������
void TestSearch() {
    // ������� �������� ������ ��� ������������
    TreeNode<int>* root = CreateTree<int>();
    PrintTree(root, 1);

    assert(Search(root, 35) == 0); // �������� 35 ��������� �� ������ 0
    assert(Search(root, 25) == 1); // �������� 25 ��������� �� ������ 1
    assert(Search(root, 38) == 1); // �������� 38 ��������� �� ������ 1
    assert(Search(root, 7) == 2);  // �������� 7 ��������� �� ������ 2
    assert(Search(root, 26) == 2); // �������� 26 ��������� �� ������ 2
    assert(Search(root, 40) == 2); // �������� 40 ��������� �� ������ 2
    assert(Search(root, 16) == 3); // �������� 16 ��������� �� ������ 3
    assert(Search(root, 3) == 3);  // �������� 3 ��������� �� ������ 3 
    assert(Search(root, 39) == 3); // �������� 39 ��������� �� ������ 3
    assert(Search(root, 55) == 3); // �������� 55 ��������� �� ������ 3
    assert(Search(root, 15) == 4); // �������� 15 ��������� �� ������ 4
    // ��������� ����� �� ������������� ���������
    assert(Search(root, 1) == -1);  // �������� 1 ����������� � ������
    assert(Search(root, 9) == -1);  // �������� 9 ����������� � ������
    assert(Search(root, 100) == -1);  // �������� 100 ����������� � ������

    // ����������� ������, ������ ������
    DeleteTree(root);
    cout << "����� �������" << endl;
}
//������������ ������� ����������
void TestAddNode() {
    // ������� �������� ������ ��� ������������
    TreeNode<int>* root = new TreeNode<int>(40, nullptr, nullptr);
    AddNode(root, 25);
    AddNode(root, 70);
    AddNode(root, 30);
    AddNode(root, 45);
    AddNode(root, 43);

    //PrintTree(root, 1);


    // ������� 0
    assert(root->data == 40);

    // ������� 1
    assert(root->left->data == 25);
    assert(root->right->data == 70);

    // ������� 2
    assert(root->left->left == nullptr);
    assert(root->left->right->data == 30);
    assert(root->right->right == nullptr);
    assert(root->right->left->data == 45);

    // ������� 3
    assert(root->right->left->left->data == 43);

    // ����������� ������, ������ ������
    DeleteTree(root);

    cout << "���������� ��������" << endl;
}
//������������ ������� �������
void TestDepth() {
    // ������� �������� ������ ��� ������������
    TreeNode<int>* root = new TreeNode<int>(25, nullptr, nullptr);
    Tre�Random(root, 9, 11, 87);
    // ��������� ������� ������
     assert(Depth(root) ==3 );
    // ����������� ������, ������ ������
    DeleteTree(root);

    // ������� �������� ������ ��� ������������
    TreeNode<int>* root1 = new TreeNode<int>(15, nullptr, nullptr);
    // ��������� ������� ������
    assert(Depth(root1) == 0);
    // ����������� ������, ������ ������
    DeleteTree(root1);


    // ������� �������� ������ ��� ������������
    TreeNode<int>* root2 = new TreeNode<int>(23, nullptr, nullptr);
    Tre�Random(root, 21, 1, 80);
    // ��������� ������� ������
    assert(Depth(root2) == 8);
    // ����������� ������, ������ ������
    DeleteTree(root2);
    cout << "������� ������� �������" << endl;
}
//������������ ������� �������� �����
void TestCountNodes() {
    // ������� �������� ������ ��� ������������
    TreeNode<int>* root = new TreeNode<int>(35, nullptr, nullptr);
    Tre�Random(root, 10, 20, 100);
    PrintTree(root, 1);
    // ��������� ���������� ����� � ������
    assert(CountNodes(root) == 11);
    // ����������� ������, ������ ������
    DeleteTree(root);

    // ������� �������� ������ ��� ������������
    TreeNode<int>* root1 = new TreeNode<int>(15, nullptr, nullptr);
    // ��������� ���������� ����� � ������
    assert(CountNodes(root1) == 1);
    // ����������� ������, ������ ������
    DeleteTree(root1);

    // ������� �������� ������ ��� ������������
    TreeNode<int>* root2 = new TreeNode<int>(40, nullptr, nullptr);
    Tre�Random(root, 5, 20, 50);
    // ��������� ���������� ����� � ������
    assert(CountNodes(root2) == 6);
    // ����������� ������, ������ ������
    DeleteTree(root2);

    cout << "������� ����� �������" << endl;
}

//void TestDeleteTree() {
//    // ������� �������� ������ ��� ������������
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
//    // ������� ������
//    DeleteTree(root);
//    // ���������, ��� ������ � ��� ���� ������ ������� (����� nullptr)
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
//    cout << "�������� ������ ��������" << endl;
//}
//������������ ������� �������� �������

//������������ ������� �������� �������
void TestCountLeaf() {
    // ������� �������� ������ ��� ������������
    TreeNode<int>* root = new TreeNode<int>(35, nullptr, nullptr);
    Tre�Random(root, 10, 10, 50);
    int count = 0;
    CountLeaf(root, count);
    // ���������, ��� ���������� ������� ����� ���������� ��������
    assert(count == 3);
    // ����������� ������, ������ ������
    DeleteTree(root);



    // ������� �������� ������ ��� ������������
    TreeNode<int>* root2 = new TreeNode<int>(40, nullptr, nullptr);
    Tre�Random(root, 15, 20, 60);
    int count2 = 0;
    CountLeaf(root2, count2);
    // ���������, ��� ���������� ������� ����� ���������� ��������
    assert(count == 5);
    // ����������� ������, ������ ������
    DeleteTree(root2);
    cout << "������� ������� �������" << endl;
}