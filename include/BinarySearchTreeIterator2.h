
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class BSTIterator {
private:
    std::vector<int> mVals;
    int mIdx = -1;
public:
    BSTIterator(TreeNode* root) {
        this->makeArray(root);
    }

    void makeArray(TreeNode* root) {
        if (!root) { return; }
        makeArray(root->left);
        mVals.push_back(root->val);
        makeArray(root->right);
    }
    
    bool hasNext() {
        return (mIdx + 1) < (int)mVals.size();
    }
    
    int next() {
        return ++mIdx >= 0 && mIdx < (int)mVals.size() ? mVals[mIdx] : -1;
    }
    
    bool hasPrev() {
        return (mIdx - 1) >= 0 && (mIdx - 1) < (int)mVals.size();
    }
    
    int prev() {
        return --mIdx >= 0 && mIdx < (int)mVals.size() ? mVals[mIdx] : -1;
    }
};
