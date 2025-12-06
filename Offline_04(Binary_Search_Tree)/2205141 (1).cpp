#include "bst.h"
#include <iostream>

using namespace std;

int countInRange(Node* node, int start, int end){
    // Write your code here.
    if(node == nullptr){
        return 0;
    }
    int count = 0;
    if(node->val < start){
        count = countInRange(node->right,start,end);
    }
    else if(node->val > end){
        count = countInRange(node->left,start,end);
    }
    
    else if(node->val >= start && node->val <= end){
        count = 1 + countInRange(node->left,start,end) + countInRange(node->right,start,end);
    }
    
    return count;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    char option;
    int val;
    int a, b;

    Node *root = NULL;
    
    while(scanf("%c %d\n", &option, &val) == 2){
        if(option == 'I'){
            root = insertNode(root, val);
            printTree(root);
            printf("\n");
        } else if (option == 'D'){
            root = deleteNode(root, val);
            printTree(root);
            printf("\n");
        } else if (option == 'F'){
            if(find(root, val) != NULL)
                printf("Found\n");
            else
                printf("Not Found\n");
        } else if(option == 'T'){
            if(val == 1){
                inOrder(root);
                printf("\n");
            }
            else if (val == 2)
            {
                preOrder(root);
                printf("\n");                
            }
            else{
                postOrder(root);
                printf("\n");
            }
        } else if(option == 'C'){
            a = val;
            scanf("%d\n", &b);
            printf("%d\n", countInRange(root, a, b));
        }
    }
    return 0;
}