
// s1 = 25 --> 25 + 2 + 5 = 32   They join at 25! 
// s2 = 17 --> 17 + 1 + 7 = 25   Return 25 as an answer.
// Constraints: Two numbers must join at some number
// JointNumber < 2000000000
int findJointNumber(int s1, int s2)
{
    if (s1 == s2) return s1;

    std::unordered_set<int> st1;
    std::unordered_set<int> st2;
    st1.insert(s1);
    st2.insert(s2);

    bool isJoint = false;
    while (!isJoint)
    {
        std::string str1 = std::to_string(s1);
        std::string str2 = std::to_string(s2);
        for (char const& c : str1)
        {
            s1 += (c - '0');
        }
        for (char const& c : str2)
        {
            s2 += (c - '0');
        }

        st1.insert(s1);
        st2.insert(s2);

        if (st2.find(s1) != st2.end())
        {
            isJoint = true;
            return s1;
        }
        if (st1.find(s2) != st1.end())
        {
            isJoint = true;
            return s2;
        }
    }
    return -1;
}
