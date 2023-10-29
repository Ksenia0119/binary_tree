#pragma once
//@author Maltseva K.V.
#include "tree_node.h"
#include"TestsTreeNode.h"
#include"BinSearchTree.h"

using namespace std;
//������������ ������������ �����������
template<class T>
void TestCopyConstructor() {
    // ������� ������ ������
    BinSearchTree<int> tree1;
    tree1.Insert(5);
    tree1.Insert(3);
    tree1.Insert(8);

    // ������� ������ ������ � �������������� ��� ������ ������� ������
    BinSearchTree<int> tree2(tree1);

    // ��������� ������� ��������
    assert(tree1.ListSize() == 3);
    assert(tree2.ListSize() == 3);
    // �������� ������ ������
    tree1.Insert(10);

    // ���������, ��� ��������� ������� ������ �� ������ �� ������ ������
    assert(tree1.ListSize() == 4);
    assert(tree2.ListSize () == 3);

    cout << "����������� ����������� ���� �������" << endl;
}
//������������ ��������� ������������ �����������
template<class T>
void TestCopyOperator() {
    // ������� ������ ������
    BinSearchTree<int> tree1;
    tree1.Insert(5);
    tree1.Insert(3);
    tree1.Insert(7);
    // ������� ������ ������,�������� ��� �������� �� ������� ����� �������� ������������ �����������
    BinSearchTree<int> tree2;
    tree2 = tree1;
    // ��������� ������� ��������
    assert(tree1.ListSize() == 3);
    assert(tree2.ListSize() == 3);
    // �������� ������ ������
    tree1.Delete(7);

    // ���������, ��� ��������� ������� ������ �� ������ �� ������ ������
    assert(tree1.ListSize() == 2);
    assert(tree2.ListSize() == 3);

    cout << "�������� ������������ ����������� ���� �������" << endl;

}
//������������ ������������ �����������
template<class T>
void TestMoveConstructor() {
    // ������� ������ ������
    BinSearchTree<int> tree1;
    tree1.Insert(5);
    tree1.Insert(3);
    tree1.Insert(7);
    // �������� ����������� ����������� ������ �� tree1 � tree2
    BinSearchTree<int> tree2 (std::move(tree1));
    // ��������� ������ � ������� ������� �����a
    assert(tree1.ListSize() == 0);
    assert(tree1.ListEmpty() ==true);
    //���������, ��� tree2 �������� ������������ ������
    assert(tree2.ListSize() == 3);
    assert(tree2.ListEmpty() == false);

    cout << "����������� ����������� ���� �������" << endl;
}
//������� std::move() ����� �������������� ������ ���, ����� ����� ������������ l - value 
// ��� r - value � ����� ������������� ��������� ����������� ������ ��������� �����������.
template<class T>
void TestMoveOperator() {
    // ������� ������ ������
    BinSearchTree<int> tree1;
    tree1.Insert(5);
    tree1.Insert(3);
    tree1.Insert(7);

    // ������� ������ ������
    BinSearchTree<int> tree2;
    tree2.Insert(10);
    tree2.Insert(8);
    tree2.Insert(12);

  
    // ����������� ������ ������ ������� � ������� ��������� ������������ � ������������
    tree1 = std::move(tree2);// �������������� lvalue � rvalue - �������� ������������ � ������������

    // ��������� ������ � ������� ������� ������
    assert(tree1.ListSize() == 3);
    assert(tree1.ListEmpty() == false);
    // ���������, ��� tree2 ���� ������
    assert(tree2.ListSize() == 0);
    assert(tree2.ListEmpty() == true);

    cout << "�������� ������������ ����������� ���� �������" << endl;
}

template<class T>
//���� �������
void TestInsert() {
    // ������� ������ ������
    BinSearchTree<T> tree;
    assert(tree.ListSize() ==0);
    // ��������� �������� � ������
    tree.Insert(5);
    assert(tree.ListSize() == 1);
    tree.Insert(3);
    assert(tree.ListSize() == 2);
    tree.Insert(7);
    assert(tree.ListSize() == 3);
    tree.Insert(2);
    assert(tree.ListSize() == 4);
    tree.Insert(4);
//��������� � ������ � ���������
    // ��������� ������ ������
    assert(tree.ListSize() == 5);
    cout << "������� ��������" << endl;
}
template<class T>
//���� ��������
void TestRemove() {
    
    BinSearchTree<T> tree;

    // ��������� �������� � ������
    tree.Insert(5);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(2);
    tree.Insert(4);
    // ������� �������� �� ������
    tree.Delete(5);
    tree.Delete(2);

    // ��������� ������ ������ ����� ��������
    assert(tree.ListSize() == 3);
    // �������� ������ ������
    int treeSize = tree.ListSize();

    // ������� ������ ��� �������� ��������� ������
    int* arr = new int[treeSize];

    // �������� ������ � ������
    PrintArr(tree.Curr(), arr, 0);


    // ��������� ��������� ���������
    assert(arr[0] == 3);
    assert(arr[1] == 4);
    assert(arr[2] == 7);

    // ����������� ���������� ������
    delete[] arr;
    cout << "�������� ���� �������" << endl;
}
template<class T>
//���� �����
void TestFind() {

    BinSearchTree<T> tree;

    // ��������� �������� � ������
    tree.Insert(5);
    tree.Insert(3);
    tree.Insert(7);
    tree.Insert(2);
    tree.Insert(4);

    // ��������� ����� ���������
    assert(tree.Find(5)==0);  // ������� 5 ������ ���� ������
    assert(tree.Find(2)==2);  // ������� 2 ������ ���� ������
    assert(tree.Find(6)==-1); // ������� 6 �� ������ ���� ������
    cout << "����� ���� �������" << endl;
}
//������� �������� �������� ������ 
BinSearchTree<int> CreateTestBST() {
    // ������� ������ ������ BinSearchTree
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

//������� �������� ����������� ����� �������� ������ 
BinSearchTree<int> CreateTestBSTLeft() {
    // ������� ������ ������ BinSearchTree
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

    // �������� �������� ������ ������
    auto it = bst.begin();

    // ��������� �������� �������� ���� ����� �������� �������������
    assert(*it == 3);


    BinSearchTree<int> bst1 = CreateTestBSTLeft();
    // �������� �������� ������ ������
    auto it1 = bst1.begin();

    // ��������� �������� �������� ���� ����� �������� �������������
    assert(*it1 == 1);

    cout << "�������� ������ BST �������" << endl;
}
void TestBSTDataOperator() {
    BinSearchTree<int> bst = CreateTestBST();

    // �������� �������� ������ ������
    auto it = bst.begin();

    // ��������� �������� �������� ���� ����� �������� �������������
    assert(*it == 3);

    // ��������� � ���������� ����
    ++it;

    // ��������� �������� �������� ���� ����� �������� �������������
    assert(*it == 7);
    ++it;
    assert(*it == 15);
    ++it;
    assert(*it == 16);


    BinSearchTree<int> bst1 = CreateTestBSTLeft();
    // �������� �������� ������ ������
    auto it1 = bst1.begin();

    // ��������� �������� �������� ���� ����� �������� �������������
    assert(*it1 == 1);

    // ��������� � ���������� ����
    ++it1;

    // ��������� �������� �������� ���� ����� �������� �������������
    assert(*it1 == 2);
    ++it1;
    assert(*it1 == 4);
    ++it1;
    assert(*it1 == 6);
    cout << "�������� ������������� �������" << endl;
}

// ���� ���������� ���������
void TestIncOperator() {
    BinSearchTree<int> bst = CreateTestBST();

    // �������� �������� ������ ������
    auto it = bst.begin();

    // ��������� �������� �������� ���� ����� �������� �������������
    assert(*it == 3);

    // ��������� � ���������� ����
    ++it;

    // ��������� �������� �������� ���� ����� �������� �������������
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
   
    cout << "�������� ������������� �������" << endl;
}
//���� ��������� ���������
void TestOperatorEqual() {
    BinSearchTree<int> bst = CreateTestBST();

    //�������� ���������
    auto it1 = bst.begin();
    auto it2 = bst.begin();

    // ���������, ��� ��������� ����� ���� ����� � ������� ��������� ���������
    assert(it1 == it2);



    cout << "�������� ��������� �������" << endl;
}

void TestOperatorUnequal() {
    BinSearchTree<int> bst = CreateTestBST();

    //�������� ���������
    auto it1 = bst.begin();
    auto it2 = bst.begin();
    ++it2;
    // ���������, ��� ��������� ����� ���� ����� � ������� ��������� ���������
    assert(it1 != it2);



    cout << "�������� ����������� �������" << endl;
}
