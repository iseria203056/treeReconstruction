#include <math.h>
#include <stdio.h>
#include <string.h>

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Node {
   public:
    int value;
    Node *left;
    Node *right;
   
};
Node* newNode(int data) 
{ 
    Node* node = new Node();
    node->value = data; 
    node->left = NULL; 
    node->right = NULL; 
 
    return (node); 
} 
void printPostOrder(Node *root) {
    if (root == NULL) {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->value;

}
int getRootIndex(int root, vector<int> *inorder) {
    for (int i = 0; i < inorder->size(); i++) {
        if (inorder->at(i) == root) {
            return i;
        }
    }

}
Node *buildTree(queue<int> *preorder, vector<int> inorder) {
    if (!preorder->empty() && !inorder.empty()) {
        int rootNum = preorder->front();
        int rootIndex = getRootIndex(rootNum, &inorder);
        Node* rootAD=newNode(rootNum);
        preorder->pop();
        vector<int> leftPart, rightPart;
        if(!preorder->empty()){
        for (int i = 0; i < rootIndex; i++) {
            leftPart.push_back(inorder[i]);
        }
        for (int i = rootIndex + 1; i < inorder.size(); i++) {
            rightPart.push_back(inorder[i]);
        }
        rootAD->left=buildTree(preorder, leftPart);
        rootAD->right=buildTree(preorder, rightPart);
        }

        // cout<<"num="<<rootAD->value<<endl;
        return rootAD;
    }
    return NULL;
}
int main() {
    int cases, numOfNode;
    cin >> cases;
    int intTemp;
    for (int i = 0; i < cases; i++) {
        cin>>numOfNode;
        queue<int> preorder;
        vector<int> inorder;

        for (int k = 0; k < numOfNode; k++) {
            cin >> intTemp;
            preorder.push(intTemp);
        }

        for (int k = 0; k < numOfNode; k++) {
            cin >> intTemp;
            inorder.push_back(intTemp);
        }
        // Node *root = buildTree(&preorder, inorder);
        Node *root=buildTree(&preorder, inorder);
        printPostOrder(root);
        cout<<"\n";
        
        
       
    }
}