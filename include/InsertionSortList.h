struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* insertionSortList(ListNode* head) 
{
    ListNode* dummy = new ListNode();
    dummy->next = head;

    ListNode* prev = dummy;
    ListNode* curr = head;

    while (curr)
    {
        if (curr->next && curr->val > curr->next->val)
        {
            while (prev->next && prev->next->val < curr->next->val)
            {
                prev = prev->next;
            }
            auto tmp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = tmp;
            prev = dummy;
        }
        else
        {
            curr = curr->next;
        }
    }
    return dummy->next;
}