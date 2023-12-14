#include <iostream>

using namespace std;

class Tree;
class Node
{
private:
    int data;
    Node *left;
    Node *right;

public:
    Node(){}; // default constructor
    Node(int a)
    {
        data = a;
        left = NULL;
        right = NULL;
    }

    Node(int a, Node *l, Node *r)
    {
        data = a;
        left = l;
        right = r;
    }
    void set_left(Node* l) {
        left = l;
    }

    void set_right(Node* r) {
        right = r;
    }


    friend class Tree;

    
};
class Tree
{
public:  

    ///method 1 for checking if a tree is a BST or not ==> The inorder traversal should give a sorted list in ascending order
    
     void isBST_M1(Node *r)       //left -> root -> right 
    {
        // precondition
        if (r!= NULL)
        {

            isBST_M1(r->left);
            cout << r->data << " " ;
            isBST_M1(r->right);

        }
        
    }

    //method 2 ==> checking if left tree's values are smaller than root and  all nodes in right trees are greater than root, 
    // and recursively calling the left and right sub trees (multiple traversak of the nodes)
    bool isSubTreeLesser(Node* n, int root_value)
    {
        if (n == NULL)
            return true;
        if (n != NULL && n->data < root_value )
        {
            isSubTreeLesser(n->left, root_value);
            isSubTreeLesser(n->right, root_value);
            return true;

        }
        else
            return false;
    }

    bool isSubTreeGreater(Node* n, int root_value)
    {
        if (n == NULL)
            return true;
        if (n != NULL && n->data > root_value )
        {
            isSubTreeGreater(n->left, root_value);
            isSubTreeGreater(n->right, root_value);
            return true;

        }
        else
            return false;
    }

    bool isBST_M2(Node* root)
    {
        if(root == NULL)
            return true;
        if (
            isSubTreeLesser(root->left , root->data) &&
            isSubTreeGreater(root->right , root->data) &&
            isBST_M2(root->left) &&
            isBST_M2(root->right)

            )
            return true;

        else    
            return false;
      
    }

    //method 3
    // setting ranges of value for each root node's left and right value
    bool isBST_M3(Node* root, int min , int max)
    {
        if(root == NULL) 
            return true;
        if (root->data  > min  &&
            root->data < max &&
            isBST_M3(root->left , min , root->data ) &&
            isBST_M3(root->right, root->data, max) )
          return true;

        else
            return false;
   
    }
};

int main()
{
    Node* root = new Node(200);
    Node* n2 = new Node(100);
    Node* n3 = new Node(300);
    Node* n4 = new Node(50);
    Node* n5 = new Node(150);
    Node* n6 = new Node(250);
    Node* n7 = new Node(350);
    Node* n8 = new Node(25);
    Node* n9 = new Node(75);

    //setting left and right nodes
    root->set_left(n2);
    root->set_right(n3);
    n2->set_left(n4);
    n2->set_right(n5);
    n3->set_left(n6);
    n3->set_right(n7);
    n4->set_left(n8);
    n4->set_right(n9);

    //making a tree object
    Tree t;

    cout << "USING METHOD 1(INORDER TREVERSAL gives sorted array in ascending order)" << endl;
    cout << "This array must be sorted if the tree is a BST : " << endl;
    t.isBST_M1(root);
    cout << "\n------------------------------------------------------------ " << endl;


    cout << "USING METHOD 2(RECURSION IN LEFT AND RIGHT TREES)" << endl;
    bool isBST = t.isBST_M2(root);
    if(isBST)
    {
        cout << "The tree is a BST" << endl;
    }
    else
    {
         cout << "The tree is not a BST" << endl;
    }
    cout << "\n-------------------------------------------------------------" << endl;


    cout << "USING METHOD 3(SPECIFYING THE LIMITS OF MAX AND MIN VALUE IN EACH ROOT NODE)" << endl;
    isBST = t.isBST_M3(root, -1000, 1000);
    if(isBST)
    {
        cout << "The tree is a BST" << endl;
    }
    else
    {
         cout << "The tree is not a BST" << endl;
    }
    cout << "\n-------------------------------------------------------------" << endl;


    

 





}
