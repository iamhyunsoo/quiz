struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        ListNode* a = l1;
        ListNode* b = l2;
        int carry = 0;
        int sum = 0;
        int x = 0;
        int y = 0;
        while (a != nullptr || b != nullptr)
        {
            x = (a != nullptr) ? a->val : 0;
            y = (b != nullptr) ? b->val : 0;
            sum = x + y + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (a != nullptr)
                a = a->next;
            if (b != nullptr)
                b = b->next;
        }
        if (carry)
        {
            curr->next = new ListNode(carry);
        }
        return dummy->next;
    }

    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2)
    {
        int carry {0};
        int sum {0};
        
        ListNode Dummy(0, nullptr);
        ListNode *res = &Dummy;
        
        while (l1 || l2 || carry) {
            sum = 0;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            } 
            sum += carry;

            carry = sum / 10;
            res->next = new ListNode(sum%10, nullptr);
            res = res->next;
        }
        
        return Dummy.next;
    } 
};
