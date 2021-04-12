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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode* ans = new ListNode(0);
        ListNode* prev = ans;
        ListNode* iter = nullptr;

        ans->next = head;
        while (prev && prev->next)
        {
            iter = prev->next;
            while (iter->next && iter->val == iter->next->val)
            {
                iter = iter->next;
            }
            if (iter == prev->next)
            {
                prev = iter;
            }
            else
            {
                prev->next = iter->next;
            }
        }
        return ans->next;
    }
};

typedef ListNode ln;
ListNode* deleteDuplicates(ListNode* head) 
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ln* ans = new ln(0);
    ln* prev = ans;
    ln* iter = nullptr;
    ans->next = head;
    
    while (prev && prev->next)
    {
        iter = prev->next;
        while (iter->next && iter->val == iter->next->val)
        {
            iter = iter->next;
        }
        if (iter == prev->next)
        {
            prev = prev->next;
        }
        else
        {
            prev->next = iter->next;
        }
    }
    return ans->next;
}