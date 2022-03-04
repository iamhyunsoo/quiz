class MyCalendar    // Very inefficient. Chose the worst data structure, vector, 
                    // and keep sorting it manually by calling std::sort whenever doing push_back.
{
    std::vector<std::pair<int, int>> mVec;
public:
    MyCalendar() {}

    bool book(int start, int end)
    {
        if (mVec.size() == 0)
        {
            mVec.push_back({start, end});
            return true;
        }
        else
        {
            std::pair<int, int> schedule = {start, end};
            auto cmp_prev = [](std::pair<int,int> const& info, int value){
                return info.second > value;
            };

            auto cmp_next = [](int value, std::pair<int, int> const& info){
                return info.second > value;
            };
            
            auto schedule_prev = std::lower_bound(mVec.begin(), mVec.end(), start, cmp_prev);
            auto schedule_next = std::upper_bound(mVec.begin(), mVec.end(), start, cmp_next);

            if ((schedule_prev == mVec.end() || schedule_prev->second <= start) && (schedule_next == mVec.end() || schedule_next->first>= end))
            {
                mVec.push_back(schedule);
                std::sort(mVec.begin(), mVec.end(), [](auto const& a, auto const& b){ return a.first < b.first; });
                return true;
            }
        }
        return false;
    }
};

class MyCalendar    // Use std::set, which sorts elements automatically. 
{    
    set<pair<int, int>> books;
public:
    bool book(int s, int e) 
    {
        auto next = books.lower_bound({s, e});
        
        if (next != books.end() && next->first < e) 
        {   return false;  }
        if (next != books.begin() && s < (--next)->second) 
        {   return false;  }
        
        books.insert({ s, e });
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */


