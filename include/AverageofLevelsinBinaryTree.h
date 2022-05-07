/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    std::vector<double> mAns;
    std::vector<int> mFreq;
public:
    vector<double> averageOfLevels(TreeNode* root) {
        this->helper(root, 0);
        for (size_t i = 0; i < mAns.size(); ++i)
        {
            mAns[i] /= mFreq[i];
        }
        return mAns;
    }
private:
    void helper(TreeNode* root, int level)
    {
        if (!root)
        {
            return;
        }
        
        if (mAns.size() == (size_t)level)
        {
            mAns.push_back(0);
            mFreq.push_back(0);
        }
        
        
        mAns[level] += root->val;
        mFreq[level]++;
        
        helper(root->left, level + 1);
        helper(root->right, level + 1);
    }
};
