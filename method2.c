/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdlib.h>
#define max(x,y) ((x)>(y)?(x):(y))

void RecursionF(struct TreeNode* root, bool* check, int* h){
    if(NULL==root) {*check=true; *h=0;return;}
    bool checkRTmp,checkLTmp;
    int hLTmp,hRTmp;
    
    if((NULL==root->left)&&(NULL==root->right)){
        *check=true;
        *h=1;
        return;
    }
    if((root->left)&&(NULL==root->right)){
        
        RecursionF(root->left,&checkLTmp,&hLTmp);
        
        *check=(hLTmp==1);
        *h=hLTmp+1;
        
        return;
        
    }
    
    if((NULL==root->left)&&(root->right)){
        
        RecursionF(root->right,&checkRTmp,&hRTmp);
        
        *check=(hRTmp==1);
        *h=hRTmp+1;
        
        return;
        
        
    }
    //if((NULL==root->left)&&(NULL==root->right)){}
    
    
    RecursionF(root->left,&checkLTmp,&hLTmp);
    
    if(checkLTmp==false) {
        *check=false;
        *h=-1;
        return;
    }
    
    RecursionF(root->right,&checkRTmp,&hRTmp);
    
    if(checkRTmp==false){
        *check=false;
        *h=-1;
        return;
        
    }
    
    
    
    *check= ( abs(hLTmp-hRTmp) <= 1);
    *h=       max(hLTmp,hRTmp)+1;
    
    
    
}


bool isBalanced(struct TreeNode* root){
    bool check;
    int h;
    RecursionF(root,&check, &h);
    
    return(check);
    
    
}
