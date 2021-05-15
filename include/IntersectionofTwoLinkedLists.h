struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
    auto original = headA;

    while (headA)
    {
        headA->val *= -1;
        headA = headA->next;
    }    

    while (headB)
    {
        if (headB->val < 0)
        {
            break;
        }
        headB = headB->next;
    }

    headA = original;
    while (headA)
    {
        headA->val *= -1;
        headA = headA->next;
    }

    return headB;
}

#include <unordered_set>
ListNode* getIntersectionNode2(ListNode* headA, ListNode* headB)    //unordered_set version in case of Node's val would be signed.
{
    std::unordered_set<ListNode*> set;
      
    while (headA)
    {
        set.insert(headA);
        headA = headA->next;
    }

    while (headB)
    {
        if (set.count(headB))
        {
            break;
        }
        headB = headB->next;
    }

    return headB;
}