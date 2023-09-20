
#pragma once
//@author Maltseva K.V.

#include <cassert>

using namespace std;

// ���������� ������� ��� ���� ��������� ������
template <class T>
struct TreeNode
{

    // ��������� ������ � ������� �������� �����
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode<T>* parent;

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

//�������� ������
template <class T>
void DeleteTree(TreeNode<T>* root){
    if (root == nullptr)
        return;

    DeleteTree(root->Left());
    DeleteTree(root->Right());

    delete root;


}
//������������ ������������ ������ ���������� ����� �����
template<class T>
void DeleteTreeNode(TreeNode<T>* node){
    delete node;
}

//������ ������ ����
template <class T>
void PrintNode(const TreeNode<T>* node){
    if (node == nullptr)
    {
        cout << "���� ����" << endl;
    }
    else
    {
        cout << node->data << "  ";
    }
}

//������� ������� ������,�.� �����, ������� �� ����� ��������
template <class T>
void CountLeaf(TreeNode<T>* t, int& count) {
    // ������������� ��������� ������ �����������
    if (t != nullptr)
    {
        CountLeaf(t->Left(), count); //������ ����� ���������
        CountLeaf(t->Right(), count);// ������ ������ ���������

        // ���������,�������� �� ������ ���� ������
        //���� ��, �� ���������� ���������� ���������� count
        if (t->Left() == nullptr && t->Right() == nullptr)
            count++;
    }

}
//������� ����� ������
template<class T>
int CountNodes(TreeNode<T>* t) {
    int left_value, right_value;
    //���� � ������ � ����� ������� �����
    if (t->Left() == nullptr && t->Right() == nullptr)
        return 1;
    //���� ����� ��������� �� ����, �������
    if (t->Left() != nullptr)
        left_value = CountNodes(t->Left());
    //����� ����
    else left_value = 0;
    //���� ������ ��������� �� ����, �������
    if (t->Right() != nullptr)
        right_value = CountNodes(t->Right());
    //����� ����
    else right_value = 0;
    //������� ����� ����� ����� + �������
    return left_value + right_value + 1;
}


//������� ������� (�������) ������
template<class T>
int Depth(TreeNode<T>* t) {
    int depthLeft, depthRight, depthValue;
    //���� ������ ������,��� �������=-1
    if (t == nullptr)
    {
        depthValue = -1;
    }
    else
        //�������� ����� �����������
        //���������� ������� ������� � ������ �����������
        //����������� �� ���������������
    {
        depthLeft = Depth(t->Left());
        depthRight = Depth(t->Right());
        //��������� ��������(�������? true:false)
        //�������� ������������ ����� depthLeft � depthRight
        depthValue = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
    }
    return depthValue;
}

//�������� ����������� ����������� ����� ������(����� �����) LRN
template <class T>
void Postorder_print(TreeNode<T>* root) {
   
    //����������� ����������� ����������� �� ������ ���������
    if (root == nullptr)
        return;
    Postorder_print(root->Left());//���������� �� ������ ���������
    Postorder_print(root->Right());//���������� �� ������� ���������
    PrintNode(root);

}
//������������ ����������� ����� ������(����� �������)
template <class T>
void Inorder_print(const TreeNode<T>* node) {
    //����������� ����������� ����������� �� ������ ���������
    if (node != nullptr) {
        Inorder_print(node->Left());//���������� �� ������ ���������
        PrintNode(node);//�������� ����
        Inorder_print(node->Right());//���������� �� ������� ���������
    }
}
//����������� ������ � ������ �������(������ ����)
template <class T>
void Preorder_print(TreeNode<T>* node) {
  
    if (node != nullptr) {
        PrintNode(node);//�������� ����
        Preorder_print(node->Left());//���������� �� ������ ���������
        Preorder_print(node->Right());//���������� �� ������� ���������
    }
}





//���������� ����� ��������
const int indentBlock = 6;
//�������� num�������� � ������� ������
void IndentBlanks(int num) {
    for (int i = 0; i < num; i++)
        cout << "  ";
}
//������ ������ �����,��������� RNL- �����������
template<class T>
void PrintTree(TreeNode<T>* node, int level) {
    //�������� ������ ������ ���� node, ���� �� �� ����� nullptr
    if (node != nullptr)
    {
        //�������� ������ ��������� ���� node
        PrintTree(node->Right(), level + 1);
        //��������� ������� ������� � ������� ���� ������
        IndentBlanks(indentBlock * level);
        cout << node->data << endl;
        //�������� ����� ��������� ���� node
        PrintTree(node->Left(), level + 1);
    }
}




//���������� ����� �����
template <class T>
TreeNode<T>* AddNode(TreeNode<T>* node, const T& item)

{
    //���� ����� �� ����������

    if (node == nullptr)

    { //�������� �� � ������� � ��� ������

        return new TreeNode<int>(item, nullptr, nullptr);

    }

   
    if (item < node->data) {
        // ���������� ��������� �������� � ����� ���������
        node->left = AddNode(node->left, item);
    }
    else if (item > node->data) {
        // ���������� ��������� �������� � ������ ���������
        node->right = AddNode(node->right, item);
    }

    // ���� �������� ��� ������������ � ������, ������ �� ������

    return node;
}
//������ ������ � ������
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
//���������� ��������� ������ �� �������
template<class T>
void BinaryTreeFromVector(vector<T> vec) {
    // �������� ��������� ���� � ������ ��������� �������
    TreeNode<int>* root = new TreeNode<int>(vec.at(0), nullptr, nullptr);
    for (int i = 0; i < vec.size(); i++) {
        int left = 2 * i + 1;// ���������� ������� ������ �������
        int right = left + 1; // ���������� ������� ������� �������
        if (left < vec.size())
        AddNode(root, vec.at(i));
        if (right < vec.size())
            AddNode(root, vec.at(i));
       
    }
    PrintTree(root, 0);
}

     
////����� ���� �� ��������
//template<class T>
//bool Search(TreeNode<T>* node, const T& data) {
//    if (node == nullptr) {
//        // ������ ������ ��� ��������� ����� ����� (���� ��� ��������)
//        return false;
//    }
//
//    if (data == node->data) {
//        // �������� ������� � ������� ����
//        return true;
//    }
//    else if (data < node->data) {
//        // ���������� ���� �������� � ����� ���������
//        return Search(node->left, data);
//    }
//    else {
//        // ���������� ���� �������� � ������ ���������
//        return Search(node->right, data);
//    }
//}

//����� ���� �� ��������(����� ��� ������)
template<class T>
int Search(TreeNode<T>* node, const T& data, int level = 0) {
    if (node == nullptr) {
        // ������ ������ ��� ��������� ����� ����� (���� ��� ��������)
        return -1; // ���������� -1, ����� �������, ��� ������� �� ������
    }

    if (data == node->data) {
        // �������� ������� � ������� ����
        return level;
    }
    else if (data < node->data) {
        // ���������� ���� �������� � ����� ���������
        return Search(node->left, data, level + 1);
    }
    else {
        // ���������� ���� �������� � ������ ���������
        return Search(node->right, data, level + 1);
    }
}

//�������� ���� ��������� ������
template<class T>
TreeNode<T>* Remove(TreeNode<T>* root, const T& data) {
    //��������, parent, ������� ����� ��������� �������� ���������� ����
    TreeNode<T>* parent;

    if (root == nullptr) {
        // ������ ������ ��� ��������� ����� ����� (���� ��� ��������)
        return nullptr;
    }

    if (data < root->data) {
        // ���������� ������� �������� �� ������ ���������
        root->left = Remove(root->left, data);
    }
    else if (data > root->data) {
        // ���������� ������� �������� �� ������� ���������
        root->right = Remove(root->right, data);
    }
    else {
        // ������ ����, ������� ����� �������

        if (root->left == nullptr && root->right == nullptr) {
            // ���� �������� ������ (�� ����� ��������)
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr) {
            // ���� ����� ������ ������� �������
           
            parent = root;
            root = root->right;
            delete parent;
        }
        else if (root->right == nullptr) {
            // ���� ����� ������ ������ �������
            
            parent = root;
            root = root->left;
            delete parent;
        }
        else {
            // ���� ����� ��� �������

            TreeNode<T>* parent = Succ(root->right);
            root->data = parent->data;
            root->right = Remove(root->right, parent->data);
        }
    }

    return root;
}
//����� ���������� 
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
//������������ ������� �������� ���� 
void TestRemove()
{
    // ������� �������� ������ ��� ������������
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

    // ����������� ������, ������ ������
    DeleteTree(root);
}
//������������ ������� ������
void TestSearch() {
    // ������� ������� �������� ������ ��� ������������
   
    TreeNode<int>* root = new TreeNode<int>(5, nullptr, nullptr);
    AddNode(root, 3);
    AddNode(root, 7);
    AddNode(root, 2);
    AddNode(root, 4);
    AddNode(root, 6);
    AddNode(root, 8);
    PrintTree(root, 1);
    
    assert(Search(root, 5) == 0); // �������� 5 ��������� �� ������ 0
    assert(Search(root, 3) == 1); // �������� 3 ��������� �� ������ 1
    assert(Search(root, 7) == 1); // �������� 7 ��������� �� ������ 1
    assert(Search(root, 2) == 2); // �������� 2 ��������� �� ������ 2
    assert(Search(root, 4) == 2); // �������� 4 ��������� �� ������ 2
    assert(Search(root, 6) == 2); // �������� 6 ��������� �� ������ 2
    assert(Search(root, 8) == 2); // �������� 8 ��������� �� ������ 2

    // ��������� ����� �� ������������� ���������
    assert(Search(root, 1) == -1); // �������� 1 ����������� � ������
    assert(Search(root, 9) == -1); // �������� 9 ����������� � ������

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
    assert(root->left->left==nullptr);
    assert(root->left->right->data== 30);
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
    // ��������� ������� ������
    assert(Depth(root) == 4);
    // ����������� ������, ������ ������
    DeleteTree(root);

    // ������� �������� ������ ��� ������������
    TreeNode<int>* root1 = new TreeNode<int>(15, nullptr, nullptr);
    // ��������� ������� ������
    assert(Depth(root1) == 0);
    // ����������� ������, ������ ������
    DeleteTree(root1);


    // ������� �������� ������ ��� ������������
    TreeNode<int>* root2 = new TreeNode<int>(40, nullptr, nullptr);
    AddNode(root2, 25);
    AddNode(root2, 70);
    AddNode(root2, 30);
    AddNode(root2, 45);
    AddNode(root2, 43);
    // ��������� ������� ������
    assert(Depth(root2) == 3);
    // ����������� ������, ������ ������
    DeleteTree(root2);
    cout << "������� ������� �������" << endl;
}
//������������ ������� �������� �����
void TestCountNodes() {
    // ������� �������� ������ ��� ������������
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
    AddNode(root2, 25);
    AddNode(root2, 70);
    AddNode(root2, 30);
    AddNode(root2, 45);
    AddNode(root2, 43);
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
void TestCountLeaf() {
    // ������� �������� ������ ��� ������������
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
    // ���������, ��� ���������� ������� ����� ���������� ��������
    assert(count == 5);
    // ����������� ������, ������ ������
    DeleteTree(root);


   
    // ������� �������� ������ ��� ������������
    TreeNode<int>* root2 = new TreeNode<int>(40, nullptr, nullptr);
    AddNode(root2, 25);
    AddNode(root2, 70);
    AddNode(root2, 30);
    AddNode(root2, 45);
    AddNode(root2, 43);
   
    int count2 = 0;
    CountLeaf(root2, count2);
    // ���������, ��� ���������� ������� ����� ���������� ��������
    assert(count == 5);
    // ����������� ������, ������ ������
    DeleteTree(root2);
    cout << "������� ������� �������" << endl;
}