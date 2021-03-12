#include <vector>
#include <queue>
using namespace std;

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
ListNode* merge(ListNode* l1, ListNode* l2)
{
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    ListNode* dummy = new ListNode();
    ListNode* ret = dummy;

    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            dummy->next = l1;
            l1 = l1->next;
        }
        else
        {
            dummy->next = l2;
            l2 = l2->next;
        }
        dummy = dummy->next;
    }

    dummy->next = (l1) ? l1 : l2;

    return ret->next;
}

ListNode* mergeKLists(std::vector<ListNode*>& lists, int s, int e)
{
    if (s == e)
    {
        return lists[s];
    }
    int mid = (s + e) / 2;
    ListNode* a = mergeKLists(lists, s, mid);
    ListNode* b = mergeKLists(lists, mid+1, e);
    
    return merge(a, b);
}

ListNode* mergeKLists(std::vector<ListNode*>& lists)
{
    int size = lists.size();
    if (size == 0)
    {
        return nullptr;
    }
    if (size == 1)
    {
        return lists[0];
    }
    return mergeKLists(lists, 0, size - 1);
}
};


class comparator{
    public:
    bool operator()(ListNode *x,ListNode *y){
        return (x->val>y->val);
    }
};
class Solution_Priority_Queue 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<ListNode*,vector<ListNode*>,comparator> pq;
        
        for(int i=0;i<lists.size();i++){
            if(lists[i])
                pq.push(lists[i]);
        }
        print_queue(pq);
        
        ListNode *dummy=new ListNode(-1);
        ListNode *tail=dummy;
        
        while(!pq.empty()){
            ListNode *top=pq.top();
            pq.pop();
            tail->next=top;
            tail=tail->next;
            if(top->next)
                pq.push(top->next);
        }   
        return dummy->next;
    }
    
template<typename T>            //Just for checking
void print_queue(T q) {
    while(!q.empty()) {
        ListNode* tmp = q.top();
        while (tmp)
        {
            cout << tmp->val << ", ";
            tmp = tmp->next;
        }
        cout << endl;
        
        q.pop();
    }
    std::cout << '\n';
}
};
    

