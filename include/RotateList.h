
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || !k)
            return head;
        
        int cnt {1};
        ListNode* tmp = head;

        while (head->next)
        {
            cnt++;
            head = head->next;
        }
        head->next = tmp;

        k = cnt - (k % cnt);

        while (--k)
        {
            tmp = tmp->next;
        }
        
        head = tmp;
        tmp = tmp->next;
        head->next = nullptr;
        return tmp;
    }
};