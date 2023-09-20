
#pragma once
//@author Maltseva K.V.

#include <cassert>

using namespace std;

// объявление объекта для узла бинарного дерева
template <class T>
struct TreeNode
{

    // указатели левого и правого дочерних узлов
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode<T>* parent;

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

//удаление дерева
template <class T>
void DeleteTree(TreeNode<T>* root){
    if (root == nullptr)
        return;

    DeleteTree(root->Left());
    DeleteTree(root->Right());

    delete root;


}
//освобождение динамической памяти занимаемой одним узлом
template<class T>
void DeleteTreeNode(TreeNode<T>* node){
    delete node;
}

//печать одного узла
template <class T>
void PrintNode(const TreeNode<T>* node){
    if (node == nullptr)
    {
        cout << "Узел пуст" << endl;
    }
    else
    {
        cout << node->data << "  ";
    }
}

//подсчет листьев дерева,т.е узлов, которые не имеют потомков
template <class T>
void CountLeaf(TreeNode<T>* t, int& count) {
    // использование обратного метода прохождения
    if (t != nullptr)
    {
        CountLeaf(t->Left(), count); //пройти левое поддерево
        CountLeaf(t->Right(), count);// пройти правое поддерево

        // проверить,является ли данный узел листом
        //если да, то произвести приращение переменной count
        if (t->Left() == nullptr && t->Right() == nullptr)
            count++;
    }

}
//подсчет узлов дерева
template<class T>
int CountNodes(TreeNode<T>* t) {
    int left_value, right_value;
    //если в правой и левой стороне пусто
    if (t->Left() == nullptr && t->Right() == nullptr)
        return 1;
    //если левое поддерево не ноль, считаем
    if (t->Left() != nullptr)
        left_value = CountNodes(t->Left());
    //иначе ноль
    else left_value = 0;
    //если правое поддерево не ноль, считаем
    if (t->Right() != nullptr)
        right_value = CountNodes(t->Right());
    //иначе ноль
    else right_value = 0;
    //считаем общее число узлов + вершина
    return left_value + right_value + 1;
}


//подсчет глубины (уровней) дерева
template<class T>
int Depth(TreeNode<T>* t) {
    int depthLeft, depthRight, depthValue;
    //если дерево пустое,его глубина=-1
    if (t == nullptr)
    {
        depthValue = -1;
    }
    else
        //обратный метод прохождения
        //вычисление глубины правого и левого поддеревьев
        //возвращение их результирующего
    {
        depthLeft = Depth(t->Left());
        depthRight = Depth(t->Right());
        //тернарный оператор(условие? true:false)
        //выбирает максимальное между depthLeft и depthRight
        depthValue = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
    }
    return depthValue;
}

//обратное рекурсивное прохождение узлов дерева(снизу вверх) LRN
template <class T>
void Postorder_print(TreeNode<T>* root) {
   
    //рекурсивное прохождение завершается на пустом поддереве
    if (root == nullptr)
        return;
    Postorder_print(root->Left());//спуститься по левому поддереву
    Postorder_print(root->Right());//спуститься по правому поддереву
    PrintNode(root);

}
//симметричное прохождение узлов дерева(слева направо)
template <class T>
void Inorder_print(const TreeNode<T>* node) {
    //рекурсивное прохождение завершается на пустом поддереве
    if (node != nullptr) {
        Inorder_print(node->Left());//спуститься по левому поддереву
        PrintNode(node);//посетить узел
        Inorder_print(node->Right());//спуститься по правому поддереву
    }
}
//прохождение дерева в прямом порядке(сверху вниз)
template <class T>
void Preorder_print(TreeNode<T>* node) {
  
    if (node != nullptr) {
        PrintNode(node);//посетить узел
        Preorder_print(node->Left());//спуститься по левому поддереву
        Preorder_print(node->Right());//спуститься по правому поддереву
    }
}





//промежуток между уровнями
const int indentBlock = 6;
//вставить numпробелов в текущей строке
void IndentBlanks(int num) {
    for (int i = 0; i < num; i++)
        cout << "  ";
}
//печать дерева боком,используя RNL- прохождение
template<class T>
void PrintTree(TreeNode<T>* node, int level) {
    //печатать правое дерево узла node, пока он не равет nullptr
    if (node != nullptr)
    {
        //печатать правое поддерево узла node
        PrintTree(node->Right(), level + 1);
        //выровнять текущий уровень и вывести поле данных
        IndentBlanks(indentBlock * level);
        cout << node->data << endl;
        //печатать левое поддерево узла node
        PrintTree(node->Left(), level + 1);
    }
}




//добавление новых узлов
template <class T>
TreeNode<T>* AddNode(TreeNode<T>* node, const T& item)

{
    //Если ветки не существует

    if (node == nullptr)

    { //создадим ее и зададим в нее данные

        return new TreeNode<int>(item, nullptr, nullptr);

    }

   
    if (item < node->data) {
        // Рекурсивно вставляем значение в левое поддерево
        node->left = AddNode(node->left, item);
    }
    else if (item > node->data) {
        // Рекурсивно вставляем значение в правое поддерево
        node->right = AddNode(node->right, item);
    }

    // Если значение уже присутствует в дереве, ничего не делаем

    return node;
}
//печать дерева в массив
template<class T>
int PrintArr(TreeNode<T>* t, T arr[], int i) {
    if (t == nullptr) {
        return i;
    }
    if (t->left != nullptr) {
    i = PrintArr(t->left, arr, i); }

    arr[i] = t->data;
    i++;

    if (t->right != nullptr) {
        i = PrintArr(t->right, arr, i);
    }
    return i;
}
//построение бинарного дерева из массива
template<class T>
void BinaryTreeFromVector(vector<T> vec) {
    // Создание корневого узла с первым элементом вектора
    TreeNode<int>* root = new TreeNode<int>(vec.at(0), nullptr, nullptr);
    for (int i = 0; i < vec.size(); i++) {
        int left = 2 * i + 1;// Вычисление индекса левого потомка
        int right = left + 1; // Вычисление индекса правого потомка
        if (left < vec.size())
        AddNode(root, vec.at(i));
        if (right < vec.size())
            AddNode(root, vec.at(i));
       
    }
    PrintTree(root, 0);
}

     
////поиск узла по значению
//template<class T>
//bool Search(TreeNode<T>* node, const T& data) {
//    if (node == nullptr) {
//        // Дерево пустое или достигнут конец ветки (лист без значения)
//        return false;
//    }
//
//    if (data == node->data) {
//        // Значение найдено в текущем узле
//        return true;
//    }
//    else if (data < node->data) {
//        // Рекурсивно ищем значение в левом поддереве
//        return Search(node->left, data);
//    }
//    else {
//        // Рекурсивно ищем значение в правом поддереве
//        return Search(node->right, data);
//    }
//}

//поиск узла по значению(вывод его уровня)
template<class T>
int Search(TreeNode<T>* node, const T& data, int level = 0) {
    if (node == nullptr) {
        // Дерево пустое или достигнут конец ветки (лист без значения)
        return -1; // Возвращаем -1, чтобы указать, что элемент не найден
    }

    if (data == node->data) {
        // Значение найдено в текущем узле
        return level;
    }
    else if (data < node->data) {
        // Рекурсивно ищем значение в левом поддереве
        return Search(node->left, data, level + 1);
    }
    else {
        // Рекурсивно ищем значение в правом поддереве
        return Search(node->right, data, level + 1);
    }
}

//удаление узла бинарного дерева
template<class T>
TreeNode<T>* Remove(TreeNode<T>* root, const T& data) {
    //указател, parent, который будет храненить родителя удаляемого узла
    TreeNode<T>* parent;

    if (root == nullptr) {
        // Дерево пустое или достигнут конец ветки (лист без значения)
        return nullptr;
    }

    if (data < root->data) {
        // Рекурсивно удаляем значение из левого поддерева
        root->left = Remove(root->left, data);
    }
    else if (data > root->data) {
        // Рекурсивно удаляем значение из правого поддерева
        root->right = Remove(root->right, data);
    }
    else {
        // Найден узел, который нужно удалить

        if (root->left == nullptr && root->right == nullptr) {
            // Узел является листом (не имеет потомков)
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr) {
            // Узел имеет только правого потомка
           
            parent = root;
            root = root->right;
            delete parent;
        }
        else if (root->right == nullptr) {
            // Узел имеет только левого потомка
            
            parent = root;
            root = root->left;
            delete parent;
        }
        else {
            // Узел имеет оба потомка

            TreeNode<T>* parent = Succ(root->right);
            root->data = parent->data;
            root->right = Remove(root->right, parent->data);
        }
    }

    return root;
}
//поиск следующего 
template<class T>
TreeNode<T>* Succ(TreeNode<T>* root) {
    if (root == nullptr) {
        return nullptr;
    }
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}
//тестирование функции удаления узла 
void TestRemove()
{
    // Создаем бинарное дерево для тестирования
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
    cout << endl;
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
    assert(node7->data ==15);
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


    Remove(root,3 );
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
}
//тестирование функции поиска
void TestSearch() {
    // Создаем простое бинарное дерево для тестирования
   
    TreeNode<int>* root = new TreeNode<int>(5, nullptr, nullptr);
    AddNode(root, 3);
    AddNode(root, 7);
    AddNode(root, 2);
    AddNode(root, 4);
    AddNode(root, 6);
    AddNode(root, 8);
    PrintTree(root, 1);
    
    assert(Search(root, 5) == 0); // Значение 5 находится на уровне 0
    assert(Search(root, 3) == 1); // Значение 3 находится на уровне 1
    assert(Search(root, 7) == 1); // Значение 7 находится на уровне 1
    assert(Search(root, 2) == 2); // Значение 2 находится на уровне 2
    assert(Search(root, 4) == 2); // Значение 4 находится на уровне 2
    assert(Search(root, 6) == 2); // Значение 6 находится на уровне 2
    assert(Search(root, 8) == 2); // Значение 8 находится на уровне 2

    // Тестируем поиск на отсутствующих значениях
    assert(Search(root, 1) == -1); // Значение 1 отсутствует в дереве
    assert(Search(root, 9) == -1); // Значение 9 отсутствует в дереве

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
    assert(root->left->left==nullptr);
    assert(root->left->right->data== 30);
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
    // Проверяем глубину дерева
    assert(Depth(root) == 4);
    // Освобождаем память, удаляя дерево
    DeleteTree(root);

    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root1 = new TreeNode<int>(15, nullptr, nullptr);
    // Проверяем глубину дерева
    assert(Depth(root1) == 0);
    // Освобождаем память, удаляя дерево
    DeleteTree(root1);


    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root2 = new TreeNode<int>(40, nullptr, nullptr);
    AddNode(root2, 25);
    AddNode(root2, 70);
    AddNode(root2, 30);
    AddNode(root2, 45);
    AddNode(root2, 43);
    // Проверяем глубину дерева
    assert(Depth(root2) == 3);
    // Освобождаем память, удаляя дерево
    DeleteTree(root2);
    cout << "Подсчет глубины пройден" << endl;
}
//тестирование функции подсчета узлов
void TestCountNodes() {
    // Создаем бинарное дерево для тестирования
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
    AddNode(root2, 25);
    AddNode(root2, 70);
    AddNode(root2, 30);
    AddNode(root2, 45);
    AddNode(root2, 43);
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
void TestCountLeaf() {
    // Создаем бинарное дерево для тестирования
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
    int count = 0;
    CountLeaf(root, count);
    // Проверяем, что количество листьев равно ожидаемому значению
    assert(count == 5);
    // Освобождаем память, удаляя дерево
    DeleteTree(root);


   
    // Создаем бинарное дерево для тестирования
    TreeNode<int>* root2 = new TreeNode<int>(40, nullptr, nullptr);
    AddNode(root2, 25);
    AddNode(root2, 70);
    AddNode(root2, 30);
    AddNode(root2, 45);
    AddNode(root2, 43);
   
    int count2 = 0;
    CountLeaf(root2, count2);
    // Проверяем, что количество листьев равно ожидаемому значению
    assert(count == 5);
    // Освобождаем память, удаляя дерево
    DeleteTree(root2);
    cout << "Подсчет листьев пройден" << endl;
}