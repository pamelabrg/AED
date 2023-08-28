/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int nx, ny, paix, paiy;

bool isCousins ( struct TreeNode* root, int x, int y ) {
    ProcuraValor ( root, x, y, 0, 0 );

    if ( ( nx == ny ) && ( paix != paiy ) ) return true;
    else return false;
}

void ProcuraValor ( struct TreeNode* root, int x, int y, int nivel, int valor ) {
    if ( root == NULL ) return;
    if ( root->val == x ) {
        nx = nivel;
        paix = valor;
        return;
    }
    if ( root->val == y ) {
        ny = nivel;
        paiy = valor;
        return;
    }
    ProcuraValor ( root->left, x, y, nivel+1, root->val );
    ProcuraValor ( root->right, x, y, nivel+1, root->val );
}