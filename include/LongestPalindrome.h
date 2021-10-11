int longestPalindrome(string s) {
    std::vector<int> table(59, 0);
    for (auto const& c : s)
    {
        table[c - 'A']++;
    }

    int oddCnt{ 0 };
    for (auto const& cnt : table)
    {
        oddCnt += (cnt & 1);
    }

    return s.length() - oddCnt + (oddCnt > 0);
}
