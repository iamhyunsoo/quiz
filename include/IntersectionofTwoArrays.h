vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
{
    std::unordered_set<int> s(nums1.begin(), nums1.end());
    std::vector<int> ret;

    for (auto const& n : nums2)
    {
        if (s.count(n))
        {
            ret.push_back(n);
            s.erase(n);
        }
    }
    return ret;
}
