#pragma once


// объявление объекта для узла бинарного дерева
template <class T>
class TreeNode
{
private:
    // указатели левого и правого дочерних узлов
    TreeNode<T>* left;
    TreeNode<T>* right;

public:

    // открытый элемент, допускающий обновление
    T data;

    // конструктор инициализирует поля данных и указателей
    // значение NULL соответствует пустому поддереву
    TreeNode(const T& item, TreeNode<T>* lptr, TreeNode<T>* rptr)
        //: data(item), left(lptr), right(rptr)
    {
        data = item;
        left = lptr;
        right = rptr;
    }
    // методы доступа к полям указателей
    TreeNode<T>* Left() const { return left; }
    TreeNode<T>* Right() const { return right; }
};

