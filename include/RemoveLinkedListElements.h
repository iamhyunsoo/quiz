struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val)
{
    ListNode** list = &head;
    while (*list)
    {
        if ( (*list)->val == val )
        {
            *list = (*list)->next;
        }
        else
        {
            list = &(*list)->next;
        }
    }
    return head;
}