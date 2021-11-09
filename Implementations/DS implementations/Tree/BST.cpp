#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class BST
{
public:
    int data;
    BST *left;
    BST *right;
    BST(int data)
    {
        this->data = data;
        left = right = NULL;
    }

    BST()
    {
        this->data = 0;
        left = right = NULL;
    }

    BST *insert(BST *root, int data)
    {
        if (!root)
            return new BST(data);
        else if (root->data < data)
            root->right = insert(root->right, data);
        else
            root->left = insert(root->left, data);
        return root;
    }

    int search(BST *root, int key)
    {
        int depth = 0;
        BST *temp = new BST;
        temp = root;
        while (temp != NULL)
        {
            depth++;
            if (temp->data == key)
                return depth;
            else if (temp->data > key)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return -1;
    }

    void inorder(BST *node)
    {
        // left root right
        if (node == NULL)
            return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    BST *minValueNode(BST *node)
    {
        BST *curr = node;

        while (curr->left != NULL)
            curr = curr->left;

        return curr;
    }

    BST *deleteNode(BST *node, int key)
    {
        if (node == NULL)
            return node;

        if (key < node->data)
            node->left = deleteNode(node->left, key);
        else if (key > node->data)
            node->right = deleteNode(node->right, key);
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                return NULL;
            }
            else if (node->left == NULL)
            {
                BST *temp = node->right;
                free(node);
                return temp;
            }
            else if (node->right == NULL)
            {
                BST *temp = node->left;
                free(node);
                return temp;
            }

            BST *temp = minValueNode(node->right);
            node->data = temp->data;

            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    BST* BSTfromPreorder(vector<int> preorder){
        int size = preorder.size();

        if(size == 0) return NULL;
        BST* root = NULL;

        for(auto x: preorder) {
            root = insert(root, x);
        }
        return root;
    }

    bool checkBST(BST* root, int min, int max){
        int d = root->data;
        if(root == NULL) return true;
        // BST *temp = new BST;
        // temp = root;
        // bool isBST = true;

        // while(temp!= NULL){
        //     if(temp->data > temp->left->data) temp = temp->left;
        //     else {
        //         isBST = false;
        //         break;
        //     }
        //     if(temp->data < temp->right->data) temp = temp->right;
        //     else {
        //         isBST = false;
        //         break;
        //     }
        // }

        if (root->data < max || root->data > min){
            return false;
        }
        
        return checkBST(root->left, min, d - 1) && checkBST(root->right, d + 1, max);
    }
};

int main()
{
    BST b;
    BST *root = NULL;
    root = b.insert(root, 50);
    b.insert(root, 30);
    b.insert(root, 20);
    b.insert(root, 40);
    b.insert(root, 70);
    b.insert(root, 60);
    b.insert(root, 80);
    b.insert(root, 10);
    b.insert(root, 5);

    // cout << "Inorder Traversal: ";
    // b.inorder(root);
    // cout << endl;

    // int key = 40;
    // if (b.search(root, key) == -1)
    //     cout << "Element Not Found." << endl;
    // else
    //     cout << "Element " << key << " Found at Depth: " << b.search(root, key) << endl;

    // cout << "minValueNode: " << (b.minValueNode(root))->data << endl;

    // int key2 = 30;
    // cout << "delete " << key2 << endl;
    // root = b.deleteNode(root, key2);
    // cout << "Inorder Traversal: ";
    // b.inorder(root);
    // cout << endl;

    // int key3 = 5;
    // cout << "delete " << key3 << endl;
    // root = b.deleteNode(root, key3);
    // cout << "Inorder Traversal: ";
    // b.inorder(root);
    // cout << endl;

    // BST from Preorder

    // vector<int> preorder{10, 5, 1, 7, 40, 50 };

    // BST* root2 = b.BSTfromPreorder(preorder);

    // b.inorder(root2);

    bool isBST = b.checkBST(root, INT_MIN, INT_MAX);
    cout<<((isBST == true) ? "YES" : "NO");

    return 0;
}
