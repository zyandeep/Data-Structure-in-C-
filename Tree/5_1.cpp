#include <iostream>
using namespace std;

struct Node
{
    int num;
    Node *left;
    Node *right;
};

Node *root=NULL;

class BSTree
{
public:
    int select(void);
    Node* create_new_node(int);
    Node* insert(Node *, int);
    Node* del_node(Node *, int);
    Node* findMin(Node *);
    void inorder(Node *);
};


int main(void)
{
    int choice, digit;
    BSTree tr;
    
    while(1)
    {
        choice=tr.select();
        switch(choice)
        {
            case 1:
                cout<<"Enter an integer: (type 0 to quit)"<<endl;
                cin>>digit;
                while(digit != 0)
                {
                    root=tr.insert(root, digit);
                    cin>>digit;
                }
                break;
            case 2:
               cout<<"Enter the number to delete: ";
               cin>>digit;
               tr.del_node(root, digit);
               break;
            case 3:
               cout<<"Inorder traversal..."<<endl;
               tr.inorder(root);
               break;
            case 4:
               cout<<"Quitting..."<<endl;
               return 0;
        }
    }
}


int BSTree::select()
{
    int selection;
    do
    {
        cout<<endl<<"Enter 1: Insert a node in the BST";
        cout<<endl<<"Enter 2: Delete a node from the BST";
        cout<<endl<<"Enter 3: Display (inorder)the BST";
        cout<<endl<<"Enter 4: END";
        cout<<endl<<"Enter your choice: ";
        cin>>selection;
        if((selection < 1) || (selection > 4))
        {
            cout<<"Wrong choice:Try again!";
        }

    } while((selection < 1) || (selection > 4));
    
    return(selection);
}


Node* BSTree::findMin(Node *root)
{
    if(root->left == NULL)
        return root;

    // Search in the left suBSTree
    return findMin(root->left);
}


Node* BSTree::create_new_node(int data)
{
    Node *temp = new Node;
    temp->num = data;
    temp->left=temp->right = NULL;
    return temp;
}


Node* BSTree::insert(Node* root, int digit)
{
    if(root == NULL)
    {
        root = create_new_node(digit);
    }
    else if (digit < root->num)
    {
        root->left = insert(root->left, digit);
    }
    else if (digit > root->num)
    {
        root->right = insert(root->right, digit);
    }
    else
    {
        cout<<"Duplicate node can't be instered!!"<<endl;
    }

    return root;
}


Node* BSTree::del_node(Node *root, int data)
{
    if(root == NULL)
    {
        cout<<"Item couldn't be found!"<<endl;
    }         
    else if(data < root->num)
        root->left = del_node(root->left, data);
    else if(data > root->num)
        root->right = del_node(root->right, data);
    
    else if(data == root->num)  // Node to be deleted has beeen found
    {
        // Case 1: No child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }

        // Case 2: One child
        else if(root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }

        // Case 3: 2 children
        else
        {
            Node *temp = findMin(root->right);
            root->num = temp->num;
            root->right = del_node(root->right, temp->num);
        }
    }

    return root;
}


void BSTree::inorder(Node *root)
{
    if(root!=NULL)
    {
       inorder(root->left);
       cout<<endl<<root->num;
       inorder(root->right);
    }
}