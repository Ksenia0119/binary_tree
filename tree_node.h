#pragma once


// ���������� ������� ��� ���� ��������� ������
template <class T>
class TreeNode
{
private:
    // ��������� ������ � ������� �������� �����
    TreeNode<T>* left;
    TreeNode<T>* right;

public:

    // �������� �������, ����������� ����������
    T data;

    // ����������� �������������� ���� ������ � ����������
    // �������� NULL ������������� ������� ���������
    TreeNode(const T& item, TreeNode<T>* lptr, TreeNode<T>* rptr)
        //: data(item), left(lptr), right(rptr)
    {
        data = item;
        left = lptr;
        right = rptr;
    }
    // ������ ������� � ����� ����������
    TreeNode<T>* Left() const { return left; }
    TreeNode<T>* Right() const { return right; }
};

