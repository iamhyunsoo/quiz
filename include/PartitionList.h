struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution 
{
public:
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* before = new ListNode();
        ListNode* after  = new ListNode();
        ListNode* first_after = after;
        ListNode* ans = before;

        while (head != nullptr)
        {
            if (head->val < x)
            {
                before->next = head;
                before = before->next;
            }
            else
            {
                after->next = head; 
                after = after->next;
            }

            head = head->next;
        }
        after->next = nullptr;
        before->next = first_after->next;

        return ans->next; 
    }
};