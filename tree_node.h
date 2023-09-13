
#pragma once
//@author Maltseva K.V.


using namespace std;

// объявление объекта для узла бинарного дерева
template <class T>
struct TreeNode
{

    // указатели левого и правого дочерних узлов
    TreeNode<T>* left;
    TreeNode<T>* right;


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
////освобождение динамической памяти занимаемой одним узлом
//template<class T>
//void DeleteTreeNode(TreeNode<T>* node){
//    delete node;
//}

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

//обратное рекурсивное прохождение узлов дерева(снизу вверх)
template <class T>
void Postorder(TreeNode<T>* root) {
   
    //рекурсивное прохождение завершается на пустом поддереве
    if (root == nullptr)
        return;
    Postorder(root->Left());//спуститься по левому поддереву
    Postorder(root->Right());//спуститься по правому поддереву
    PrintNode(root);

}
//симметричное прохождение узлов дерева(слева направо)
template <class T>
void Inorder(const TreeNode<T>* node) {
    //рекурсивное прохождение завершается на пустом поддереве
    if (node != nullptr) {
        Inorder(node->Left());//спуститься по левому поддереву
        PrintNode(node);//посетить узел
        Inorder(node->Right());//спуститься по правому поддереву
    }
}
//прохождение дерева в прямом порядке(сверху вниз)
template <class T>
void Preorder(TreeNode<T>* node) {
  
    if (node != nullptr) {
        PrintNode(node);//посетить узел
        Preorder(node->Left());//спуститься по левому поддереву
        Preorder(node->Right());//спуститься по правому поддереву
    }
}




//template<class t>
//void Inorder(const TreeNode<t>* node, void visit(t& item)) {
//    if (node != nullptr) {
//        inorder(node->left(), visit);
//        visit(node->data);
//        inorder(node->right(), visit);
//    }
//}

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




// создать объект TreeNode с указательными полями lptr и rptr.
// по умолчанию указатели содержат NULL.
template <class T>
TreeNode<T>* GetTreeNode(T item, TreeNode<T>* lptr = nullptr,
    TreeNode<T>* rptr = nullptr)
{
    TreeNode<T>* p;

    // вызвать new для создания нового узла
    // передать туда параметры lptr и rptr
    p = new TreeNode<T>(item, lptr, rptr);

    // если памяти недостаточно, завершить 
    // программу сообщением об ошибке
    if (p == nullptr)
    {
        cout << 
            "Ошибка при выделении памяти!\n";
            exit(1);
    }
    // вернуть указатель на выделенную системой память
    return p;
}

//добавление новых узлов
template <class T>
TreeNode<T>* Add(TreeNode<T>* node, const T& item)

{

    //Если ветки не существует

    if (node == nullptr)

    { //создадим ее и зададим в нее данные

        return new TreeNode<int>(item, nullptr, nullptr);

    }

   
    if (item < node->data) {
        // Рекурсивно вставляем значение в левое поддерево
        node->left = Add(node->left, item);
    }
    else if (item > node->data) {
        // Рекурсивно вставляем значение в правое поддерево
        node->right = Add(node->right, item);
    }

    // Если значение уже присутствует в дереве, ничего не делаем

    return node;
}

//поиск узла по значению
template<class T>
bool Search(TreeNode<T>* node, const T& data) {
    if (node == nullptr) {
        // Дерево пустое или достигнут конец ветки (лист без значения)
        return false;
    }

    if (data == node->data) {
        // Значение найдено в текущем узле
        return true;
    }
    else if (data < node->data) {
        // Рекурсивно ищем значение в левом поддереве
        return Search(node->left, data);
    }
    else {
        // Рекурсивно ищем значение в правом поддереве
        return Search(node->right, data);
    }
}



