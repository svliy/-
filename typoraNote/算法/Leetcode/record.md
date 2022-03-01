# 刷题记录表

|                             题目                             | 难度 |   标签    | 完成 |
| :----------------------------------------------------------: | :--: | :-------: | :--: |
| [700. 二叉搜索树中的搜索](https://leetcode-cn.com/problems/search-in-a-binary-search-tree/) | 简单 | 递归+迭代 |  ✔   |
|                                                              |      |           |      |

使得



```c++
TreeNode* searchBST(TreeNode* root, int val) {
    while(root){
        if(val == root->val){
            return root;
        }
        root = root->val > val ? root->left : root->right;
    }
    return nullptr;
}
TreeNode* searchBST(TreeNode* root, int val) {
    if(root == nullptr)
        return nullptr;
    if(val == root->val)
        return root;
    return searchBST(root->val > val ? root->left : root->right,val);
}
```

