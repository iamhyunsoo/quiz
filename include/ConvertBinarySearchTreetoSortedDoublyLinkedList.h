/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
    Node* start;
    Node* end;
public:
    Node* treeToDoublyList(Node* root) 
    {
        if (!root) { return nullptr; }
        ConvertViaInorder(root);
        end->right = start;
        start->left = end;
        return start;
    }
private:
    void ConvertViaInorder(Node* root)
    {
        if (!root) return;
        ConvertViaInorder(root->left);
        if (end)
        {
            end->right = root;
            root->left = end;
        }
        else 
        {
            start = root;
        }
        end = root;
        ConvertViaInorder(root->right);
    }
};
