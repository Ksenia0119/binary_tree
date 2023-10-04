#pragma once

//@author Maltseva K.V.
    #include "tree_node.h"

    using namespace std;


    // класс бинарного дерева
    template <class T>
    class BinSearchTree
    { private:
        // указатель на корень
        TreeNode<T>* root;
        // указатель на текущий узел
        TreeNode<T>* curr;
        //количество элементов дерева
        int size;

       public:
        // Конструктор по умолчанию
        BinSearchTree() : root(nullptr), curr(nullptr), size(0) {}
        // Конструктор с параметрами
        BinSearchTree(const T& item) : root(nullptr), curr(nullptr), size(0)
        {
            Insert(item);
        }

        // Конструктор копирования
        BinSearchTree(const BinSearchTree& other)
        {
            // Копируем размер
            this->size = other.size;
            // Копируем дерево
            this->root = CopyTree(other.root);
            // Устанавливаем указатель на текущий узел в корень
            this->curr = this->root;
        }

        //В общем случае, работа оператора присваивания состоит из двух этапов : 
        //корректно убрать из объекта старое содержимое,
            //а затем корректно скопировать в него новое содержимое.
            //Работа же конструктора копирования не имеет первого этапа,
            //ибо никакого старого содержимого в этот момент в объекте нет.

        // Оператор присваивания копирования
        BinSearchTree& operator=(const BinSearchTree& other)
        {  // избегаем самоприсваивания
            if (this != &other) {
                // Копируем размер
                this->size = other.size;
                // Копируем дерево
                Clear(this->root); // Очищаем текущее дерево
                this->root = CopyTree(other.root);
                // Устанавливаем указатель на текущий узел в корень
                this->curr = this->root;
            }
            return *this; // возвращаем текущий объект
        }
        // Конструктор перемещения
        BinSearchTree(BinSearchTree&& other)
        {
            // Перемещаем указатель на корень
            this->root = other.root;
            // Перемещаем указатель на текущий узел
            this->curr = other.curr;
            // Перемещаем количество элементов дерева
            this->size = other.size;

           //обнуляем указатели исходного объекта
            other.root = nullptr;
            other.curr = nullptr;
            other.size = 0;
        }

        //опрератор присваивания с перемещением
        BinSearchTree& operator=( BinSearchTree&& other)
        { // избегаем самоприсваивания
            if (&other != this) {
                Clear(this->root); // Очищаем текущее дерево
                // Перемещаем указатель на корень
                this->root = other.root;
                // Перемещаем указатель на текущий узел
                this->curr = other.curr;
                // Перемещаем количество элементов дерева
                this->size = other.size;

                //обнуляем указатели исходного объекта
                other.root = nullptr;
                other.curr = nullptr;
                other.size = 0;
            }
            return *this;// возвращаем текущий объект
        }
        // Деструктор
        ~BinSearchTree() { Clear(root); }

        TreeNode<T>* Curr() const { return curr; };
        int Find(const T& item);
        void Insret(const T& item);
        void Delete(const T& item);
        void Clear(TreeNode<T>* node);
        bool ListEmpty()const;
        int ListSize()const;

    };
    //проверка на пустое дерево
    template<class T>
    bool BinSearchTree<T>::ListEmpty() const {
        return (root == nullptr);
    }
    //очистка дерева
    template<class T>
    void BinSearchTree<T>::Clear(TreeNode<T>* node) {
        if (node) {
            Clear(node->left);
            Clear(node->right);
            delete node;
        }
    }
    // Поиск узла по значению и вывод его уровня
    template<class T>
    int BinSearchTree<T>::Find(const T& item) {
        return Search(root, item);
    }

    // Вставка нового элемента
    template<class T>
    void BinSearchTree<T>::Insret(const T& item) {
        root = AddNode(root, item);
        size++;
    }

    // Удаление узла по значению
    template<class T>
    void BinSearchTree<T>::Delete(const T& item) {
        root = Remove(root, item);
        size--;
    }

    //подсчет размера дерева
    template<class T>
    int BinSearchTree<T>::ListSize() const {
        return size;
    }


   /* 
    template <class T>
    int Find(T& item) {
        TreeNode<T>* parent;
        curr = Search(parent, item,0);
        if (curr!= nullptr){
            item = curr->data;
             return 1; 
        }
        else
        { return 0; }
    }*/



    //template <class T>
    //void Insert(const T& item, TreeNode<T>* root, int size) {
    //    root = AddNode(root, item);
    //    size++;
    //}

    //template <class T>
    //void BinSearchTree<T>::Insert(const T& item) {
    //    TreeNode<T>* newNode = new TreeNode<T>(item);
    //    if (root == nullptr) {
    //        // Если дерево пустое, новый узел становится корнем
    //        root = newNode;
    //    }
    //    else {
    //        TreeNode<T>* current = root;
    //        while (true) {
    //            if (item < current->data) {
    //                // Если значение item меньше значения текущего узла, двигаемся влево
    //                if (current->left == nullptr) {
    //                    // Если левого поддерева нет, добавляем новый узел слева
    //                    current->left = newNode;
    //                    break;
    //                }
    //                else {
    //                    // Иначе переходим к левому поддереву
    //                    current = current->left;
    //                }
    //            }
    //            else {
    //                // Если значение item больше или равно значению текущего узла, двигаемся вправо
    //                if (current->right == nullptr) {
    //                    // Если правого поддерева нет, добавляем новый узел справа
    //                    current->right = newNode;
    //                    break;
    //                }
    //                else {
    //                    // Иначе переходим к правому поддереву
    //                    current = current->right;
    //                }
    //            }
    //        }
    //    }
    //    size++;  // Увеличиваем размер дерева
    //}
    