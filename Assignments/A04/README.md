## Assignment 4 - Binary Trees 
### Micah-Lyn Scotland
### Description:


### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [1264](https://github.com/Micah-Lyn/4883-Programming_Techniques-Scotland/blob/master/Assignments/A04/1264.pdf)     | problem 1                                             |
|   2   | [12347](https://github.com/Micah-Lyn/4883-Programming_Techniques-Scotland/blob/master/Assignments/A04/12347.pdf)           |problem 2                   |



### Example Num 1

- This is a typical BST implementation using a class
- Deals with in order traversal lnr (left, node, right)
- All the values less than the root node will be on the left and those greater than the root node will be on the left.

```cpp
// C++ program to demonstrate insertion 
// in a BST recursively. 
#include <iostream> 
using namespace std; 
  
class BST 
{ 
    int data; 
    BST *left, *right; 
  
    public: 
      
    // Default constructor. 
    BST(); 
      
    // Parameterized constructor. 
    BST(int); 
      
    // Insert function. 
    BST* Insert(BST *, int); 
      
    // Inorder traversal. 
    void Inorder(BST *); 
}; 
  
// Default Constructor definition. 
BST :: BST() : data(0), left(NULL), right(NULL){} 
  
// Parameterized Constructor definition. 
BST :: BST(int value) 
{ 
    data = value; 
    left = right = NULL; 
} 
  
// Insert function definition. 
BST* BST :: Insert(BST *root, int value) 
{ 
    if(!root) 
    { 
        // Insert the first node, if root is NULL. 
        return new BST(value); 
    } 
  
    // Insert data. 
    if(value > root->data) 
    { 
        // Insert right node data, if the 'value' 
        // to be inserted is greater than 'root' node data. 
          
        // Process right nodes. 
        root->right = Insert(root->right, value); 
    } 
    else
    { 
        // Insert left node data, if the 'value'  
        // to be inserted is greater than 'root' node data. 
          
        // Process left nodes. 
        root->left = Insert(root->left, value); 
    } 
      
    // Return 'root' node, after insertion. 
    return root; 
} 
  
// Inorder traversal function. 
// This gives data in sorted order. 
void BST :: Inorder(BST *root) 
{ 
    if(!root) 
    { 
        return; 
    } 
    Inorder(root->left); 
    cout << root->data << endl; 
    Inorder(root->right); 
} 
  
// Driver code 
int main() 
{ 
    BST b, *root = NULL; 
    root = b.Insert(root, 50); 
    b.Insert(root, 30); 
    b.Insert(root, 20); 
    b.Insert(root, 40); 
    b.Insert(root, 70); 
    b.Insert(root, 60); 
    b.Insert(root, 80); 
  
    b.Inorder(root); 
    return 0; 
} 
  
// This code is contributed by pkthapa 
```
- Source: https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/


### Example Num 2

- This is a typical BST implementation using a linked list
- It only deals with creating and traversal, other functions could be added
- Dynamically Allocated Memory


```cpp
#include <iostream>
using namespace std;

struct nod {
   nod *l, *r;
   int d;
}*r = NULL, *p = NULL, *np = NULL, *q;

void create() {
   int v,c = 0;
   while (c < 6) {
      if (r == NULL) {
         r = new nod;
         cout<<"enter value of root node\n";
         cin>>r->d;
         r->r = NULL;
         r->l = NULL;
      } else {
         p = r;
         cout<<"enter value of node\n";
         cin>>v;
         while(true) {
            if (v< p->d) {
               if (p->l == NULL) {
                  p->l = new nod;
                  p = p->l;
                  p->d = v;
                  p->l = NULL;
                  p->r = NULL;
                  cout<<"value entered in left\n";
                  break;
               } else if (p->l != NULL) {
                  p = p->l;
               }
            } else if (v >p->d) {
               if (p->r == NULL) {
                  p->r = new nod;
                  p = p->r;
                  p->d = v;
                  p->l = NULL;
                  p->r = NULL;
                  cout<<"value entered in right\n";
                  break;
               } else if (p->r != NULL) {
                  p = p->r;
               }
            }
         }
      }
      c++;
   }
}

void inorder(nod *p) {
   if (p != NULL) {
      inorder(p->l);
      cout<<p->d<<endl;
      inorder(p->r);
   }
}

void preorder(nod *p) {
   if (p != NULL) {
      cout<<p->d<<endl;
      preorder(p->l);
      preorder(p->r);
   }
}

void postorder(nod *p) {
   if (p != NULL) {
      postorder(p->l);
      postorder(p->r);
      cout<<p->d<<endl;
   }
}

int main() {
   create();
   cout<<" traversal in inorder\n";
   inorder(r);
   cout<<" traversal in preorder\n";
   preorder(r);
   cout<<" traversal in postorder\n";
   postorder(r);
}
```
- Source: https://www.tutorialspoint.com/cplusplus-program-to-implement-a-binary-search-tree-using-linked-lists

