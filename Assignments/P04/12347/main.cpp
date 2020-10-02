#include<bits/stdc++.h>
#include <iostream>
using namespace std;

struct node{
    int nodeV;
    node *leftC;
    node *rightC;
};

node *newbst(int nodeV){
    node *temp = (node*) malloc(sizeof(node));
    temp->nodeV = nodeV;
    temp->leftC = temp->rightC = NULL;
    return temp;
}

node *preInsert(node *node, int nodeV)
{
    if(node == NULL) {
        return newbst(nodeV);
    }
    else if(nodeV> node->nodeV){
        node->rightC = preInsert(node->rightC, nodeV);
    }
    else {
      node->leftC = preInsert(node->leftC, nodeV);
    }
    return node;
}

void postOrder(node *node){
    if(node){   
    postOrder(node->leftC);
    postOrder(node->rightC);
    cout << node->nodeV <<endl;
    }
}

int main()
{
    node *root = NULL;
    int nodeV;
    while(cin >> nodeV)
    {
      root = preInsert(root, nodeV);
    }
    postOrder(root);
    return 0;
}
