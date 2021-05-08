#include <unordered_map>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution
{
public:
    Node* copyRandomList(Node* head)
    {
        std::unordered_map<Node*, Node*> map;
        Node* copy = head;
        while (copy)
        {
            map[copy] = new Node(copy->val);
            copy = copy->next;
        }

        copy = head;
        while (copy)
        {
            map[copy]->next = map[copy->next];
            map[copy]->random = map[copy->random];
            copy = copy->next;
        }

        return map[head];
    }

    Node* copyRandomListRecursive(Node* head)
    {
        if (!head)
        {
            return nullptr;
        }
        if (mMap[head])
        {
            return mMap[head];
        }
        mMap[head] = new Node(head->val);
        mMap[head]->next = copyRandomListRecursive(head->next);
        mMap[head]->random = copyRandomListRecursive(head->random);
        return mMap[head];
    }
private:
    std::unordered_map<Node*, Node*> mMap;
};