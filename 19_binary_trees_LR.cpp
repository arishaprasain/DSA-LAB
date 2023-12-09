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
    void preorder_traversal(Node *r)    // root -> left -> right
    {
        // precondition
        if (r != NULL)
        {
            cout << r->data << " " ;
            preorder_traversal(r->left);
            preorder_traversal(r->right);

        }
        
        
    }

    void postorder_traversal(Node *r)       //left -> right -> root
    {
        // precondition
        if (r!= NULL)
        {

            postorder_traversal(r->left);
            postorder_traversal(r->right);
            cout << r->data << " ";

        }
        
    }

     void inorder_traversal(Node *r)       //left -> root -> right 
    {
        // precondition
        if (r!= NULL)
        {

            inorder_traversal(r->left);
            cout << r->data << " " ;
            inorder_traversal(r->right);

        }
        
    }

};

int main()
{
    // Binary Tree
    //            2
        //       /  \
        //     23     343
        //    / \    /  \
        // 67   100 90   12

         
    Node* second = new Node(23);
    Node* third = new Node(343);
    Node* root = new Node(2, second, third);
    Node* fourth = new Node(67);
    Node* fifth = new Node(100);

    // Set left and right pointers using setters
    second->set_left(fourth);
    second->set_right(fifth);

    Node* sixth = new Node(90);
    Node* seventh = new Node(12);

    // Set left and right pointers for third node
    third->set_left(sixth);
    third->set_right(seventh);


    Tree t;

    cout << "PREORDER TRAVERSAL :" << endl;
    t.preorder_traversal(root) ;     //OUTPUT : 2 23 67 100 343 90 12
    cout << endl << "-------------------------------" << endl;

    // postorder_traversal(root);
    cout << "POSTORDER TRAVERSAL :" << endl;
    t.postorder_traversal(root);     //OUTPUT :  67 100 23 90 12 343 2 
    cout << endl << "-------------------------------" << endl;

    // inorder_traversal(root);
    cout << "INORDER TRAVERSAL :" << endl;
    t.inorder_traversal(root) ;     //OUTPUT :  67 23  100 2  90 343 12
    



        
    

    return 0;
}
