struct ListNode 
{
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head)  //My Idea
{   
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    for (ListNode* tmp = head; tmp != nullptr && tmp->next != nullptr; tmp = tmp->next->next)
    {
        int val = tmp->val;
        tmp->val = tmp->next->val;
        tmp->next->val = val;
    }
    return head;
}

ListNode* swapPairsRecursive(ListNode* head)   // Recursion version (from someone)
{
    if (!head || !head->next)
    {
        return head;
    }
    ListNode* rec = swapPairsRecursive(head->next->next);
    ListNode* ret = head->next;
    ret->next = head;
    head->next = rec;

    return ret;
}