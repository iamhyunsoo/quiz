struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* detectCycle(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    bool isCycle = false;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            isCycle = true;
            break;   
        }
    }
    if (isCycle)
    {
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;

        }
        return slow;
    }
    return nullptr;
}