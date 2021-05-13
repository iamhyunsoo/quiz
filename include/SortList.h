struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution  //Using Merge-Sort with a constant space
{
public:
    ListNode* sortList(ListNode* head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        const int size = GetCount(head);
        ListNode* start = head;
        ListNode dummy{0};
        for (int i = 1; i < size; i *= 2)
        {
            this->tail = &dummy;
            while (start)
            {
                if (!start->next)
                {
                    tail->next = start;
                    break;
                }

                ListNode* mid = Split(start, i);
                Merge(start, mid);
                start = rest;
            }
            start = dummy.next;
        }
        return dummy.next;
    }
private:
    ListNode* Split(ListNode* head, const int size)
    {
        ListNode* prevMid = head;
        ListNode* end = head->next;

        for (int i = 1; i < size && end->next; i++)
        {
            if (prevMid->next)
            {
                prevMid = prevMid->next;
            }
            if (end->next)
            {
                end = end->next->next ? end->next->next : end->next;
            }
        }
        ListNode* mid = prevMid->next;
        rest = end->next;
        prevMid->next = nullptr;
        end->next = nullptr;
        return mid;
    }

    void Merge(ListNode* l1, ListNode* l2)
    {
        ListNode dummy {0};
        ListNode* tmpTail = &dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tmpTail->next = l1;
                l1 = l1->next;
                tmpTail = tmpTail->next;
            }
            else
            {
                tmpTail->next = l2;
                l2 = l2->next;
                tmpTail = tmpTail->next;
            }
        }
        tmpTail->next = l1 ? l1 : l2;
        while (tmpTail->next)
        {
            tmpTail = tmpTail->next;
        }
        this->tail->next = dummy.next;
        this->tail = tmpTail;
    }

    int GetCount(ListNode* head)
    {
        int cnt {0};
        while (head)
        {
            head = head->next;
            cnt++;
        }
        return cnt;
    }
private:
    ListNode* tail;
    ListNode* rest;
};