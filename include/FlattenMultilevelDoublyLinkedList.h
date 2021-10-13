class Node 
{
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution 
{
public:
    Node* flatten(Node* head) 
    {
        for (Node* curr = head; curr ;curr = curr->next)
        {
            if (curr->child)
            {
                auto next = curr->next;
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = nullptr;

                auto childNext = curr->next;
                while (childNext->next)
                {
                    childNext = childNext->next;
                }

                childNext->next = next;

                if (next)
                {
                    next->prev = childNext;
                }
            }
        }
        return head;
    }
};