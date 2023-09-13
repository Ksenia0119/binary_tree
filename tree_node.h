
#pragma once
//@author Maltseva K.V.


using namespace std;

// ���������� ������� ��� ���� ��������� ������
template <class T>
struct TreeNode
{

    // ��������� ������ � ������� �������� �����
    TreeNode<T>* left;
    TreeNode<T>* right;


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
        //��������� ��������
        //�������� ������������ ����� depthLeft � depthRight
        depthValue = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
    }
    return depthValue;
}

//�������� ����������� ����������� ����� ������(����� �����)
template <class T>
void Postorder(TreeNode<T>* root) {
    //����������� ����������� ����������� �� ������ ���������
    if (root == nullptr)
        return;
    Postorder(root->Left());//���������� �� ������ ���������
    Postorder(root->Right());//���������� �� ������� ���������
    PrintNode(root);

}
//������������ ����������� ����� ������(����� �������)
template <class T>
void Inorder(const TreeNode<T>* node) {
    //����������� ����������� ����������� �� ������ ���������
    if (node != nullptr) {
        Inorder(node->Left());//���������� �� ������ ���������
        PrintNode(node);//�������� ����
        Inorder(node->Right());//���������� �� ������� ���������
    }
}
//����������� ������ � ������ �������(������ ����)
template <class T>
void Preorder(TreeNode<T>* node) {
    if (node != nullptr) {
        PrintNode(node);//�������� ����
        Preorder(node->Left());//���������� �� ������ ���������
        Preorder(node->Right());//���������� �� ������� ���������
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

//����������� ����� ��������
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




// ������� ������ TreeNode � ������������� ������ lptr � rptr.
// �� ��������� ��������� �������� NULL.
template <class T>
TreeNode<T>* GetTreeNode(T item, TreeNode<T>* lptr = nullptr,
    TreeNode<T>* rptr = nullptr)
{
    TreeNode<T>* p;

    // ������� new ��� �������� ������ ����
    // �������� ���� ��������� lptr � rptr
    p = new TreeNode<T>(item, lptr, rptr);

    // ���� ������ ������������, ��������� 
    // ��������� ���������� �� ������
    if (p == nullptr)
    {
        cout << 
            "������ ��� ��������� ������!\n";
            exit(1);
    }
    // ������� ��������� �� ���������� �������� ������
    return p;
}


