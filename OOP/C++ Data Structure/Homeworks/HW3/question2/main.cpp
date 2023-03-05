// binary search tree
#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;
// Node structure for a binary search tree
struct Node
{
    int info;
    Node *left;
    Node *right;
};
Node *CreateNode(int data);
void insert(Node *&root, int info);
Node *search(Node *root, int info);
void inorder(Node *temp, Node *p);
void preorder(Node *root);
void postorder(Node *root);
void printTree(Node *root, int indent);

Node *CreateNode(int info)
{
    Node *newNode = new Node();
    if (!newNode)
    {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->info = info;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(Node *&root, int info)
{
    if (root == NULL)
    {
        root = CreateNode(info);
    }

    queue<Node* > q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        else
        {
            temp->left = CreateNode(info);
        }

        if (temp->right != NULL)
            q.push(temp->right);
        else
        {
            temp->right = CreateNode(info);
        }
    }
}
void inorder(Node *temp, Node *p)
{
    if (temp == NULL)
        return;

    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->info << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
int main()
{
    // Create an empty binary search tree
    Node *root = NULL;

    // Insert some nodes into the binary search tree
    insert(root, 5);
    insert(root, 8);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 4);
    insert(root, 6);
    insert(root, 9);

    // print binary search tree left (root) to right (leaves)
    printTree(root, 0);

    // Perform a binary search for the data 4
    Node *result = search(root, 4);

    // Check if the data was found
    if (result)
    {
        cout << result->info << " is found." << endl;
    }

    cout << "inorder traversal : ";
    inorder(root);
    cout << endl
         << "preorder traversal : ";
    preorder(root);
    cout << endl
         << "postorder traversal : ";
    postorder(root);

    return -1;
}

// print binary search tree left (root) to right (leaves)
void printTree(Node *root, int indent)
{
    // If the tree is empty, return
    if (!root)
        return;

    // Print the right subtree
    printTree(root->right, indent + 4);

    // Print the current node
    if (indent)
    {
        cout << setw(indent) << ' ';
    }
    cout << root->info << std::endl;

    // Print the left subtree
    printTree(root->left, indent + 4);
}
