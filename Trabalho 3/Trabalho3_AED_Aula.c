/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isCousins(struct TreeNode* root, int x, int y){
    int a = procuraValor(root, x, 1);
    int b = procuraValor(root, y, 1);
    if(a >0) return true;
    //if(a == b) return true;
    else return false;
}

int procuraValor(struct TreeNode* root, int valor, int nivel){
    struct TreeNode* aux = root;
    
    if(root->val == valor) return nivel;
    if(root->left){
        aux = root->left;
        nivel++;
        nivel = procuraValor(aux, valor, nivel);
    } 
    if (root->right){
        aux = root->right;
        nivel++;
        nivel = procuraValor(aux, valor, nivel);
    } 
    return -1;
}


