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

        ListNode* tmp = head;
        while(tmp)
        {
            while(tmp->next && tmp->val == tmp->next->val)
            {
                ListNode* rm = tmp->next;
                tmp->next = rm->next;
                delete rm;
            }
            tmp = tmp->next;
        }
        return head;
    }
};