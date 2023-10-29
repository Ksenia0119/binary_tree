#pragma once

//@author Maltseva K.V.
     #include<stack>
    #include "tree_node.h"
    #include"AbstractIterator.h"
    #include<stack>
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

        //BinSearchTree foo() {
        //    BinSearchTree b;

        //    return b;
        //}


        //void bar() {
        //    BinSearchTree b2 = foo();
        //}

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
        void Insert(const T& item);
        void Delete(const T& item);
        void Clear(TreeNode<T>* node);
        bool ListEmpty()const;
        int ListSize()const;

        //класс итератора бинарного дерева поиска LNR обхода
        template<class T>
        class BinSearchTreeIterator :public Iterator<T> {
        private:
            TreeNode<T>* curr;  // Указатель на текущий узел
            //стек узлов для обхода в глубину 
            stack<TreeNode<T>*> stack;

            //помещение узлов дерева в стек
            void pushNodesintoStack(TreeNode<T>* node) {
                //пока узел не равен nullptr
                while (node != nullptr)
                {
                    //помещаем узлы в стек
                    stack.push(node);
                    //переходим к левому поддереву
                    node = node->left;
                }
            }
        public:
            //Конструктор
            //BinSearchTreeIterator(TreeNode<T>* node) : curr(node) {}

            BinSearchTreeIterator(TreeNode<T>* root) {
                pushNodesintoStack(root);
                if (!stack.empty()) {
                    curr = stack.top();
                    stack.pop();
                }
                else 
                    curr = nullptr;
                
            } 
            
            // Оператор разыменования-доступа к данным
            T& operator*() const override {
                //возвращает данные текущего узла
                return curr->data;
            }
            //Оператор инкремента для BST
            BinSearchTreeIterator& operator++() override {
                //если текущий не равен nullptr
                if (curr->right != nullptr) {
                    //помещаем в стек правое поддерево
                    pushNodesintoStack(curr->right);
                }
                //если стек пустой
                if (!stack.empty()) {
                    //текущий-вершина стека
                    curr = stack.top();
                    //вытащить элемент
                    stack.pop();

                }
                //иначе текущии = nullptr
                else {
                    curr = nullptr;
                }
                //if (nodeStack.empty() && curr == nullptr) {
                //    // Если стек пуст и текущий указатель равен nullptr, значит достигнут конец дерева
                //    return *this;
                //}

                //if (curr != nullptr) {
                //    // Если текущий указатель не равен nullptr, переходим к правому поддереву
                //    while (curr != nullptr) {
                //        nodeStack.push(curr);
                //        curr = curr->right;  // Изменили на правый потомок для обратного симметричного порядка
                //    }
                //}
                //else {
                //    // Если текущий указатель равен nullptr, извлекаем узел из стека
                //    curr = nodeStack.top();
                //    nodeStack.pop();
                //}

                return *this;
            }
            // Оператор равенства
            bool operator==(const Iterator<T>& other) const override {
                const BinSearchTreeIterator* otherIterator = dynamic_cast<const BinSearchTreeIterator*>(&other);
                return otherIterator && curr == otherIterator->curr;
            }
            // Оператор неравенства
            bool operator!=(const Iterator<T>& other) const override {
                return !(*this == other);
            }
            


        };
        // Итератор начала списка
        BinSearchTreeIterator<T> begin() const {
            //возвращает итератор ,который указывает на головной узел списка
            return BinSearchTreeIterator<T>(root);
        }
        // Итератор начала списка
        BinSearchTreeIterator<T> end() const {
            //возвращает итератор ,который указывает на позицию после последнего узла списка
            return BinSearchTreeIterator<T>(nullptr);
        }
    };
    //проверка на пустое дерево
    template<class T>
    bool BinSearchTree<T>::ListEmpty() const {
        return (root == nullptr);
    }

    //очистка дерева
    template<class T>
    void BinSearchTree<T>::Clear(TreeNode<T>* node) {  //
        if (root == nullptr)
            return;

        DeleteTree(root->Left());
        DeleteTree(root->Right());

        delete root;
        
    }
    // Поиск узла по значению и вывод его уровня
    template<class T>
    int BinSearchTree<T>::Find(const T& item) {
        return Search(root, item);
    }

    // Вставка нового элемента
    template<class T>
    void BinSearchTree<T>::Insert(const T& item) {
        root = AddNode(root, item);
        size++;
        //nodeStack.push(item);
        
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
    