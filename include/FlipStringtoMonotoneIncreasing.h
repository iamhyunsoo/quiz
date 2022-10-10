int minFlipsMonoIncr(string s) {
    int ans {0};
    int flip {0};
    for (char const& c : s)
    {
        if (c == '0')
        {
            ans = std::min(ans + 1, flip);
        }
        else
        {
            ++flip;
        }
    }
    return ans;
}
