#include <map>
#include <iostream>
#include <stack>
#include <string>
#include <unistd.h>
#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>

int main()
{

	return 0;
}

    void dec(std::string key) {

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

    std::string getMaxKey() {
        cout << "Line58::" << buckets.rbegin()->value << endl;
        return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
    }
    
    std::string getMinKey() {
        return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
    }
