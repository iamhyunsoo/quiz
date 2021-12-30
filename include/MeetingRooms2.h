int minMeetingRooms(vector<vector<int>>& intervals) {

    std::vector<std::vector<int>> rooms;
    std::sort(intervals.begin(), intervals.end(), [](vector<int> const& a, vector<int> const& b){
        return a[0] < b[0];
    });

    for (auto const& interval : intervals)
    {
        bool newNeeded = true;
        for (size_t i = 0; i < rooms.size(); i++)
        {
            if (rooms[i][1] <= interval[0])
            {
                rooms[i][1] = interval[1];
                newNeeded = false;
                break;
            }
        }
        if (newNeeded)
        {
            rooms.push_back(interval);
        }
    }

    return static_cast<int>(rooms.size());
}
