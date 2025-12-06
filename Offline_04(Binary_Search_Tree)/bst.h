#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
};

Node *insertNode(Node *node, int val)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST and
    // the value to be inserted
    // Returns the pointer to the root of the modified BST.

    if (node == nullptr)
    {
        Node *temp = new Node;
        temp->val = val;
        temp->left = nullptr;
        temp->right = nullptr;
        return temp;
    }

    if (node->val > val)
    {
        node->left = insertNode(node->left, val);
    }
    else if (node->val < val)
    {
        node->right = insertNode(node->right, val);
    }
    return node;
}

Node *find(Node *node, int val)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST and
    // the value to be searched.
    // Returns the pointer to the node that contains val.
    // Returns NULL if not found.

    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->val > val)
    {
        return find(node->left, val);
    }
    else if (node->val < val)
    {
        return find(node->right, val);
    }
    return node;
}

Node *deleteNode(Node *node, int val)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST and
    // the value to be deleted.
    // Returns the pointer to the root of the modified BST.

    if (node == nullptr)
    {
        cout << "The value is not in the tree.";
        cout << " Please enter a valid value to delete" << endl;
        return nullptr;
    }

    if (node->val > val)
    {
        node->left = deleteNode(node->left, val);
    }
    else if (node->val < val)
    {
        node->right = deleteNode(node->right, val);
    }

    else
    {

        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            return nullptr;
        }

        else if (node->left == nullptr)
        {
            Node *rightChild = node->right;

            // delete node;
            // return rightChild;
            node->val = rightChild->val;
            node->left = rightChild->left;
            node->right = rightChild->right;
            delete rightChild;
            return node;
        }
        else if (node->right == nullptr)
        {
            Node *leftChild = node->left;

            // delete node;
            // return leftChild;
            node->val = leftChild->val;
            node->left = leftChild->left;
            node->right = leftChild->right;
            delete leftChild;
            return node;
        }

        Node *inOrderSr = node->right;
        while (inOrderSr->left != nullptr)
        {
            inOrderSr = inOrderSr->left;
        }

        node->val = inOrderSr->val;
        node->right = deleteNode(node->right, inOrderSr->val);
    }

    return node;
}

void inOrder(Node *node)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST
    // Prints the in-order traversal of the given BST
    if (node == nullptr)
    {
        return;
    }
    inOrder(node->left);
    cout << node->val << " ";
    inOrder(node->right);
}

void preOrder(Node *node)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST
    // Prints the pre-order traversal of the given BST
    if (node == nullptr)
    {
        return;
    }
    cout << node->val << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(Node *node)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST
    // Prints the post-order traversal of the given BST
    if (node == nullptr)
    {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    cout << node->val << " ";
}

void printTree(Node *root)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST
    // Prints parenthesized representation of the given BST
    if (root == nullptr)
    {
        cout << "_";
        return;
    }

    cout << root->val;
    if (root->left != nullptr || root->right != nullptr)
    {
        cout << " (";
        printTree(root->left);
        cout << ", ";
        printTree(root->right);
        cout << ")";
    }
}