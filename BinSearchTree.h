#pragma once

//@author Maltseva K.V.
     #include<stack>
    #include "tree_node.h"
    #include"AbstractIterator.h"
    #include<stack>
    using namespace std;


    // ����� ��������� ������
    template <class T>
    class BinSearchTree
    { private:
        // ��������� �� ������
        TreeNode<T>* root;
        // ��������� �� ������� ����
        TreeNode<T>* curr;
        //���������� ��������� ������
        int size;
     
        
       public:
        // ����������� �� ���������
        BinSearchTree() : root(nullptr), curr(nullptr), size(0) {}
        // ����������� � �����������
        BinSearchTree(const T& item) : root(nullptr), curr(nullptr), size(0)
        {
            Insert(item);
        }

        // ����������� �����������
        BinSearchTree(const BinSearchTree& other)
        {
            // �������� ������
            this->size = other.size;
            // �������� ������
            this->root = CopyTree(other.root);
            // ������������� ��������� �� ������� ���� � ������
            this->curr = this->root;
        }

        //� ����� ������, ������ ��������� ������������ ������� �� ���� ������ : 
        //��������� ������ �� ������� ������ ����������,
            //� ����� ��������� ����������� � ���� ����� ����������.
            //������ �� ������������ ����������� �� ����� ������� �����,
            //��� �������� ������� ����������� � ���� ������ � ������� ���.

        // �������� ������������ �����������
        BinSearchTree& operator=(const BinSearchTree& other)
        {  // �������� ����������������
            if (this != &other) {
                // �������� ������
                this->size = other.size;
                // �������� ������
                Clear(this->root); // ������� ������� ������
                this->root = CopyTree(other.root);
                // ������������� ��������� �� ������� ���� � ������
                this->curr = this->root;
            }
            return *this; // ���������� ������� ������
        }

        //BinSearchTree foo() {
        //    BinSearchTree b;

        //    return b;
        //}


        //void bar() {
        //    BinSearchTree b2 = foo();
        //}

        // ����������� �����������
        BinSearchTree(BinSearchTree&& other)
        {
            // ���������� ��������� �� ������
            this->root = other.root;
            // ���������� ��������� �� ������� ����
            this->curr = other.curr;
            // ���������� ���������� ��������� ������
            this->size = other.size;

           //�������� ��������� ��������� �������
            other.root = nullptr;
            other.curr = nullptr;
            other.size = 0;
        }

        //��������� ������������ � ������������
        BinSearchTree& operator=( BinSearchTree&& other)
        { // �������� ����������������
            if (&other != this) {
                Clear(this->root); // ������� ������� ������
                // ���������� ��������� �� ������
                this->root = other.root;
                // ���������� ��������� �� ������� ����
                this->curr = other.curr;
                // ���������� ���������� ��������� ������
                this->size = other.size;

                //�������� ��������� ��������� �������
                other.root = nullptr;
                other.curr = nullptr;
                other.size = 0;
            }
            return *this;// ���������� ������� ������
        }
        // ����������
        ~BinSearchTree() { Clear(root); }

        TreeNode<T>* Curr() const { return curr; };
        int Find(const T& item);
        void Insert(const T& item);
        void Delete(const T& item);
        void Clear(TreeNode<T>* node);
        bool ListEmpty()const;
        int ListSize()const;

        //����� ��������� ��������� ������ ������ LNR ������
        template<class T>
        class BinSearchTreeIterator :public Iterator<T> {
        private:
            TreeNode<T>* curr;  // ��������� �� ������� ����
            //���� ����� ��� ������ � ������� 
            stack<TreeNode<T>*> stack;

            //��������� ����� ������ � ����
            void pushNodesintoStack(TreeNode<T>* node) {
                //���� ���� �� ����� nullptr
                while (node != nullptr)
                {
                    //�������� ���� � ����
                    stack.push(node);
                    //��������� � ������ ���������
                    node = node->left;
                }
            }
        public:
            //�����������
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
            
            // �������� �������������-������� � ������
            T& operator*() const override {
                //���������� ������ �������� ����
                return curr->data;
            }
            //�������� ���������� ��� BST
            BinSearchTreeIterator& operator++() override {
                //���� ������� �� ����� nullptr
                if (curr->right != nullptr) {
                    //�������� � ���� ������ ���������
                    pushNodesintoStack(curr->right);
                }
                //���� ���� ������
                if (!stack.empty()) {
                    //�������-������� �����
                    curr = stack.top();
                    //�������� �������
                    stack.pop();

                }
                //����� ������� = nullptr
                else {
                    curr = nullptr;
                }
                //if (nodeStack.empty() && curr == nullptr) {
                //    // ���� ���� ���� � ������� ��������� ����� nullptr, ������ ��������� ����� ������
                //    return *this;
                //}

                //if (curr != nullptr) {
                //    // ���� ������� ��������� �� ����� nullptr, ��������� � ������� ���������
                //    while (curr != nullptr) {
                //        nodeStack.push(curr);
                //        curr = curr->right;  // �������� �� ������ ������� ��� ��������� ������������� �������
                //    }
                //}
                //else {
                //    // ���� ������� ��������� ����� nullptr, ��������� ���� �� �����
                //    curr = nodeStack.top();
                //    nodeStack.pop();
                //}

                return *this;
            }
            // �������� ���������
            bool operator==(const Iterator<T>& other) const override {
                const BinSearchTreeIterator* otherIterator = dynamic_cast<const BinSearchTreeIterator*>(&other);
                return otherIterator && curr == otherIterator->curr;
            }
            // �������� �����������
            bool operator!=(const Iterator<T>& other) const override {
                return !(*this == other);
            }
            


        };
        // �������� ������ ������
        BinSearchTreeIterator<T> begin() const {
            //���������� �������� ,������� ��������� �� �������� ���� ������
            return BinSearchTreeIterator<T>(root);
        }
        // �������� ������ ������
        BinSearchTreeIterator<T> end() const {
            //���������� �������� ,������� ��������� �� ������� ����� ���������� ���� ������
            return BinSearchTreeIterator<T>(nullptr);
        }
    };
    //�������� �� ������ ������
    template<class T>
    bool BinSearchTree<T>::ListEmpty() const {
        return (root == nullptr);
    }

    //������� ������
    template<class T>
    void BinSearchTree<T>::Clear(TreeNode<T>* node) {  //
        if (root == nullptr)
            return;

        DeleteTree(root->Left());
        DeleteTree(root->Right());

        delete root;
        
    }
    // ����� ���� �� �������� � ����� ��� ������
    template<class T>
    int BinSearchTree<T>::Find(const T& item) {
        return Search(root, item);
    }

    // ������� ������ ��������
    template<class T>
    void BinSearchTree<T>::Insert(const T& item) {
        root = AddNode(root, item);
        size++;
        //nodeStack.push(item);
        
    }

    // �������� ���� �� ��������
    template<class T>
    void BinSearchTree<T>::Delete(const T& item) {
        root = Remove(root, item);
        size--;
    }

    //������� ������� ������
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
    //        // ���� ������ ������, ����� ���� ���������� ������
    //        root = newNode;
    //    }
    //    else {
    //        TreeNode<T>* current = root;
    //        while (true) {
    //            if (item < current->data) {
    //                // ���� �������� item ������ �������� �������� ����, ��������� �����
    //                if (current->left == nullptr) {
    //                    // ���� ������ ��������� ���, ��������� ����� ���� �����
    //                    current->left = newNode;
    //                    break;
    //                }
    //                else {
    //                    // ����� ��������� � ������ ���������
    //                    current = current->left;
    //                }
    //            }
    //            else {
    //                // ���� �������� item ������ ��� ����� �������� �������� ����, ��������� ������
    //                if (current->right == nullptr) {
    //                    // ���� ������� ��������� ���, ��������� ����� ���� ������
    //                    current->right = newNode;
    //                    break;
    //                }
    //                else {
    //                    // ����� ��������� � ������� ���������
    //                    current = current->right;
    //                }
    //            }
    //        }
    //    }
    //    size++;  // ����������� ������ ������
    //}
    