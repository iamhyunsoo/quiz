struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head)        //Iterative with no extra spaces
{
    ListNode* tmp = nullptr;
    while(head && head->next && head->next->next)
    {
        tmp = head;
        while (tmp->next->next)
        {
            tmp = tmp->next;
        }
        tmp->next->next = head->next;
        head->next = tmp->next;
        tmp->next = nullptr;
        head = head->next->next;
    }
}

#include <stack>
void reorderList2(ListNode* head)        //Using stack
{
    if ((!head) || (!head->next) || (!head->next->next)) 
        return;

    std::stack<ListNode*> st;
    ListNode* ptr = head;
    int size = 0;
    while (ptr != nullptr)
    {
        st.push(ptr);
        size++;
        ptr = ptr->next;
    }

    ptr = head;
    for (int i = 0; i < size / 2; i++)
    {
        ListNode *element = st.top();
        st.pop();
        element->next = ptr->next;
        ptr->next = element;
        ptr = ptr->next->next;
    }
    ptr->next = nullptr;
}