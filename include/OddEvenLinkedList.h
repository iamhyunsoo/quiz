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
    ListNode* oddEvenList(ListNode* head) 
    {
      if (!head) return head;

      ListNode* oddFirst = head;
      ListNode* evenFirst = head->next;
      auto evenFirstIndex = evenFirst;

      while (oddFirst->next && evenFirst->next)
      {
        oddFirst->next = evenFirst->next;
        oddFirst = oddFirst->next;

        evenFirst->next = oddFirst->next;
        evenFirst = evenFirst->next;
      }
      oddFirst->next = evenFirstIndex;
      return head;
    }
};
