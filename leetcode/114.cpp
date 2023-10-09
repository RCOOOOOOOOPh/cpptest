#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void flatten(TreeNode* root) {
        if (!root) return;
        vector<TreeNode*> temp;
        TreeNode* p = root;
        while (temp.size() || p->left || p->right)
        {
            if (p->right) temp.push_back(p->right);
            if (p->left)
            {
                p->right = p->left;
                p = p->right;
            }
            else
            {
                p->right = *(temp.end()-1);
                temp.pop_back();
                p = p->right;
            }
        }
        return;
    }

void traverse(TreeNode* n)
{
    cout<<n->val<<endl;
    if (n->left) traverse(n->left);
    if (n->right) traverse(n->right);
}

int main(){
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n2 = new TreeNode(2, n3, n4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n1 = new TreeNode(1, n2, n5);
    n5->right = n6;
    flatten(n1);
    traverse(n1);
}