int minimumDeletions(string s) {
    int rm {0};
    int ans {0};
    for (char const& c : s)
    {
        if (c == 'a') 
        {
            ans = std::min(ans + 1, rm);
        }
        else
        {
            ++rm;
        }
    }
    return ans;
}
