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
        static ListNode* reverseKGroup(ListNode* head, int k)
        {   
            if (k <= 1)
                return head;

            ListNode* nextNode = head;
            
            int i {0};
            for (; i < k; i++)
            {
                if (!nextNode)
                {
                    return head;
                }
                nextNode = nextNode->next;
            }

            ListNode* prev = head;
            ListNode* next = head->next;
            for (i = 0; i < k - 1; i++)
            {
                ListNode* tmp = next->next;
                next->next = prev;
                prev = next;
                next = tmp;   
            }
            head->next = reverseKGroup(nextNode, k);
            return prev;
        }
};