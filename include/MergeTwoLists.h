
struct ListNode 
{
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    ListNode* dummy = new ListNode();
    ListNode* ret = dummy;

    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            dummy->next = l1;
            l1 = l1->next;
        }
        else
        {
            dummy->next = l2;
            l2 = l2->next;
        }
        dummy = dummy->next;
    }
    if (l1)
    {
        dummy->next = l1;
    }
    else if (l2)
    {
        dummy->next = l2;
    }

    return ret->next;
}