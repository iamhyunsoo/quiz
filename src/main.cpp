#include <map>
#include <iostream>
#include <stack>
#include <string>
#include <unistd.h>
#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class AllOne {
public:

    void inc(string key) {
        
        // If the key doesn't exist, insert it with value 0.
        if (!bucketOfKey.count(key))
            bucketOfKey[key] = buckets.insert(buckets.begin(), {0, {key}});
            
        // Insert the key in next bucket and update the lookup.
        auto next = bucketOfKey[key], bucket = next++;
        if (next == buckets.end())
        {
            cout << "MOO ya HO\n";
        }
		if (next == buckets.end() || next->value > bucket->value + 1)
        {
            cout << "key:" << key << endl;
            cout << "next value:" << next->value << " , ::" << next->keys.size() << endl;
            cout << "bucket value:" << bucket->value << " , ::" << bucket->keys.size() << endl;
            cout << "-------------------------" << endl;
            next = buckets.insert(next, {bucket->value + 1, {}});
        }
        next->keys.insert(key);
        bucketOfKey[key] = next;
        
        // Remove the key from its old bucket.
        bucket->keys.erase(key);
        if (bucket->keys.empty())
            buckets.erase(bucket);
    }

    void dec(string key) {

        // If the key doesn't exist, just leave.
        if (!bucketOfKey.count(key))
            return;

        // Maybe insert the key in previous bucket and update the lookup.
        auto prev = bucketOfKey[key], bucket = prev--;
        bucketOfKey.erase(key);
        if (bucket->value > 1) {
            if (bucket == buckets.begin() || prev->value < bucket->value - 1)
                prev = buckets.insert(bucket, {bucket->value - 1, {}});
            prev->keys.insert(key);
            bucketOfKey[key] = prev;
        }
        
        // Remove the key from its old bucket.
        bucket->keys.erase(key);
        if (bucket->keys.empty())
            buckets.erase(bucket);
    }

    string getMaxKey() {
        cout << "Line58::" << buckets.rbegin()->value << endl;
        return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
    }
    
    string getMinKey() {
        return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
    }

private:
    struct Bucket { int value; unordered_set<string> keys; };
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> bucketOfKey;
};

int main()
{
    AllOne ao;
    ao.inc("sibal");
    ao.inc("sibal");
    ao.inc("dw");
    ao.inc("dw");
    cout << ao.getMaxKey() << " : " << ao.getMinKey() << endl;
    ao.dec("dw");
    cout << ao.getMaxKey() << " : " << ao.getMinKey() << endl;

    unordered_set<string> kk({"sibal", "fsdf"});
    for (auto x : kk)
    {
        cout << x << endl;
    }

    std::list<int> ll;
    ll.insert(ll.begin(), 2);
    ll.insert(ll.begin(), 55);

    for (auto x : ll)
    {
        cout << x << endl;
    }

}