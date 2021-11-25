std::vector<int> pathInZigZagTree(int label) 
{
    int level {0};
    while ((1 << level) <= label)
    {
        level++;
    }

    std::vector<int> ret(level, 0);
    for ( ; label > 0; label /= 2, level--)
    {
        ret[level - 1] = label;
        label = ((1 << level) - 1) + (1 << (level - 1)) - label;
    }

    return ret;
}
