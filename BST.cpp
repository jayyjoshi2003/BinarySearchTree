#include <iostream>
#include <stdlib.h>
using namespace std;

class BstNode
{
public:
    int data;
    BstNode *left, *right;

    BstNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

BstNode *InsertNode(BstNode *root, int data)
{
    BstNode *newnode;
    if (root == NULL)
    {
        newnode = new BstNode(data);
        return newnode;
    }

    else if (data < root->data)
    {
        root->left = InsertNode(root->left, data);
    }

    else
    {
        root->right = InsertNode(root->right, data);
    }

    return root;
}

bool SearchNode(BstNode *root, int data)
{
    if (root == NULL)
    {
        return false;
    }

    if (data == root->data)
    {
        return true;
    }

    else if (data < root->data)
    {
        return SearchNode(root->left, data);
    }

    else
    {
        return SearchNode(root->right, data);
    }

    return false;
}

BstNode *MinNode(BstNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    return MinNode(root->left);
}

BstNode *MaxNode(BstNode *root)
{
    if (root == NULL)
        return NULL;

    return MaxNode(root->right);
}

void inOrder(BstNode *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(BstNode *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BstNode *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

BstNode *DeleteNode(BstNode *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }

    else if (root->data == data)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child
        // left child
        else if (root->left != NULL && root->right == NULL)
        {
            BstNode *temp = root->left;
            delete root;
            return temp;
        }

        // right child
        else if (root->left == NULL && root->right != NULL)
        {
            BstNode *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        else if (root->left != NULL && root->right != NULL)
        {
            int min = MinNode(root->right)->data;
            root->data = min;
            root->right = DeleteNode(root->right, min);
            return root;
        }
    }

    else if (root->data < data)
    {
        root->right = DeleteNode(root->right, data);
        return root;
    }

    else
    {
        root->right = DeleteNode(root->right, data);
        return root;
    }
}

int main()
{

    BstNode *root = NULL;
    int ch;

    while (ch != 7)
    {
        cout << "\n\t\t****MENU DRIVEN PROGRAM OF BINARY SEARCH TREE****" << endl;
        cout << "1.INSERTION\n2.DELETION\n3.SEARCHING\n4.MINIMUM NODE\n5.MAXIMUM NODE\n6.DISPLAY\n7.EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int val;
            cout << "Enter data to be inseretd:" << endl;
            cin >> val;
            if (SearchNode(root, val))
            {
                cout << "Node already present" << endl;
            }
            else
            {
                root = InsertNode(root, val);
                cout << "Node inserted!!" << endl;
            }

            break;

        case 2:
            cout << "Enter data to be deleted:" << endl;
            cin >> val;
            root = DeleteNode(root, val);
            cout << "Node deleted!!" << endl;
            break;

        case 3:
            cout << "Enter data to be searched:" << endl;
            cin >> val;
            if (SearchNode(root, val))
            {
                cout << "Node contains " << val << " found" << endl;
            }
            else
            {
                cout << "Node contains " << val << " not found" << endl;
            }

            break;

        case 4:
            cout << "Minimum node: " << MinNode(root)->data << endl;
            break;

        case 5:
            cout << "Maximum node: " << MaxNode(root)->data << endl;
            break;

        case 6:
            cout << "Preorder Traversal: ";
            preOrder(root);

            cout << "Ineorder Traversal: ";
            inOrder(root);

            cout << "Postorder Traversal: ";
            postOrder(root);
            break;

        case 7:
            exit(0);
            break;
        default:
            cout << "Invalid choice, try again" << endl;
            break;
        }
    }
    return 0;
}