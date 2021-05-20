#include "PascalTriangle.h"
#include "PascalTriangle2.h"
#include <iostream>
#include <cstring>
#include <string>
#include "MaxPointsonaLine.h"
using namespace std;
using std::vector;


#include "MaximumGap.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool identicalTrees(TreeNode* a, TreeNode* b)
{
    if (!a && !b)
        return true;
    else if (!a || !b)
        return false;
    else if (a->val != b->val)
    {
        return false;
    }
    return identicalTrees(a->left, b->left) && identicalTrees(a->right, b->right);
}

int twoChildren(TreeNode* node)
{
    if (!node)
    {
        return 0;
    }
    else if (node->left && node->right)
    {
        return twoChildren(node->left) + twoChildren(node->right) + 1;
    }
    else
    {
        return 0;
    }
}
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void selectionSort(ListNode* node)
{
    ListNode* copy = node;
    while (copy)
    {
        ListNode* least = copy;
        ListNode* remainer = least->next;

        while (remainer)
        {
            if (least->val > remainer->val)
            {
                least = remainer;
            }
            remainer = remainer->next;
        }

        int tmp = copy->val;
        copy->val = least->val;
        least->val = tmp;
        copy = copy->next;
    }
}

bool isSymmetric(std::vector< std::vector<int> > vec)
{
    const int row = vec.size();
    const int col = vec[0].size();

    if (row != col)
        return false;

    for (int i = 0 ; i < row ; i++ )
    {
        for (int j = 0; j < col; j++)
        {
            if (vec[i][j] != vec[j][i])
            {
                return false;
            }
        }
    }
    return true;
}


ListNode* divideList(ListNode* node)
{
    if (!node)
        return nullptr;
    
    ListNode* slow = node;
    ListNode* fast = node;

    while (fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    ListNode* node = new ListNode(5);
    node->next = new ListNode(6);
    node->next->next = new ListNode(7);
    node->next->next->next = new ListNode(8);
    node->next->next->next->next = new ListNode(9);
    node->next->next->next->next->next = new ListNode(10);
    node->next->next->next->next->next->next = new ListNode(11);
    node->next->next->next->next->next->next->next = new ListNode(12);

    cout << divideList(node)->val << endl;



}
