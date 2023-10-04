#pragma once
//@author Maltseva K.V.
#include "tree_node.h"
#include"BinSearchTree.h"

using namespace std;
//������������ ������������ �����������
template<class T>
void TestCopyConstructor() {
    // ������� ������ ������
    BinSearchTree<int> tree1;
    tree1.Insret(5);
    tree1.Insret(3);
    tree1.Insret(8);

    // ������� ������ ������ � �������������� ��� ������ ������� ������
    BinSearchTree<int> tree2(tree1);

    // ��������� ������� ��������
    assert(tree1.ListSize() == 3);
    assert(tree2.ListSize() == 3);
    // �������� ������ ������
    tree1.Insret(10);

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
    tree1.Insret(5);
    tree1.Insret(3);
    tree1.Insret(7);
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
    tree1.Insret(5);
    tree1.Insret(3);
    tree1.Insret(7);
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
    tree1.Insret(5);
    tree1.Insret(3);
    tree1.Insret(7);

    // ������� ������ ������
    BinSearchTree<int> tree2;
    tree2.Insret(10);
    tree2.Insret(8);
    tree2.Insret(12);

  
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