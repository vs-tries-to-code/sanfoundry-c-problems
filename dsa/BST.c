//word dictionary usig BST
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode{
    char word[50];
    char meaning[50];
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNode node;

void searchWord(node* root, char word[50]){
    if(!root){
        printf("not found");
        return;
    }
    if(strcmp(root->word, word) == 0){
        printf("Word found\n");
        printf("Meaning : %s", root->meaning);
        return;
    }
    
    else if(strcmp(root->word, word) > 0){
        return searchWord(root->left, word);
    }
    
    else{
        return searchWord(root->right, word);
    }
}

node* insertNode(node* root, char word[50], char meaning[50]){
    node* newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->word, word); 
    strcpy(newNode->meaning, meaning);
    newNode->left = NULL;
    newNode->right = NULL;

    if(!root){
        return newNode;
    }

    int cmp = strcmp(word, root->word);
    if(cmp>0){
       root->right =  insertNode(root->right, word, meaning);
    }

    else if (cmp < 0){
        root->left = insertNode(root->left, word, meaning);
    }

    else{
        strcpy(root->meaning, meaning);
        printf("word exists");
    }

    return root;
}


node* findMin(node* root){
    while (root->left) {
        root = root->left;
    }
    return root;
}

//leftmost node in right subtree (if subtree exists) ; otherwise, ancestor
node* inorderSucc(node* root, char word[50]){
    node* s = NULL;
    int c = strcmp(word, root->word);
    //binary search for target whose successor is to be found
    if (c>0){
        root  = root->right;
    }
    //target word is alphabetically less than the current word, so current word could be a potential successor
    else if(c<0){
        s = root;
        root = root->left;
    }

    else{
        if(root->right){
            findMin(root->right);
        }

        return s;
    }

    //largest node got no successor
    return NULL;
}

node* findMax(node* root){
    while(root->right){
        root = root->right;
    }
    return root;
}

//rightmost (max) in left subtree is subtree exists ; otherwise ancestor
node* inorderPredecessor(node* root, node* Node, char word[50]){
    node* p = NULL;
    
    int c = strcmp(word, root->word);
    //binary search to find target node (which will be greater than predeccessor)
    if (c>0){
        p = root; //target word is alphabetically after current node, so current node could be a predecessor
        root  = root->right;
    }

    else if(c<0){
        root = root->left;
    }

    else{
        if(root->left){
            findMax(root->left);
        }

        return p;
    }

    //smallest node has no predecessor
    return NULL;
    
}

node* deleteNode(node* root, char word[50]){
    if(!root){
        return root;
    }
    int c = strcmp(word, root->word);

    if(c>0){
        root->right = deleteNode(root->right, word);
    }

    else if(c<0){
        root->left = deleteNode(root->left, word);
    }

    else{
        //word found
        // case 1 : no left child (includes leaves as well)
        if(!root->left){
            node* temp = root->right;
            free(root);
            return temp;
        }
        //no right child
        else if(!root->right){
            node* temp = root->left;
            free(root);
            return temp;
        }
        //both children 
        node* temp = inorderSucc(root, root->word);
        strcpy(root->word, temp->word);
        strcpy(root->meaning, temp->meaning);
        root->right = deleteNode(root->right, temp->word);
        
    }

    return root;
    
}


