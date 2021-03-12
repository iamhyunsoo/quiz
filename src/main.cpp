
#include <algorithm>
#include <iostream>
#include <string.h>
#include <iostream>
#include <vector>
#include "MergeKLists.h"

using namespace std;


int main()
{
    Solution s;

    ListNode* a = new ListNode(2);
    a->next = new ListNode(6);
    a->next->next = new ListNode(8);

    ListNode* b = new ListNode(1);
    b->next = new ListNode(3);
    b->next->next = new ListNode(7);

    ListNode* c = new ListNode(-12);
    c->next = new ListNode(6);
    c->next->next = new ListNode(8);
    
    vector< ListNode* > sett = {a, b, c};

    s.mergeKLists(sett);
}