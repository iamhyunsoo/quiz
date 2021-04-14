#include "PartitionList.h" 
#include "ScrambleString.h"

#include <iostream>
using namespace std;
using ln = ListNode;
int main()
{
    string a = "great";
    string b = "taerg";
    cout << isScramble(a,b) << endl;
    
    ln* node = new ln(1);
    node->next = new ln(4);
    node->next->next = new ln(3);
    node->next->next->next = new ln(2);
    node->next->next->next->next = new ln(5);
    node->next->next->next->next->next = new ln(2);

    Solution s;
    ln* ans = s.partition(node, 3);
    while (ans != nullptr)
    {
        cout << ans->val << "->";
        ans = ans->next;
    }
    cout << endl;
}
