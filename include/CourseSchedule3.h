#include <algorithm>
#include <queue>
#include <vector>

using std::vector;

int 
scheduleCourse
(
    vector< vector< int > >& courses
)
{
    std::priority_queue<int> queue;
    std::sort(courses.begin(), courses.end(), 
    [](auto const& a, auto const& b){
        return a[1] < b[1];
    });

    int sum {0};
    for (auto const& course : courses)
    {
        if (sum + course[0] <= course[1])
        {
            queue.push(course[0]);
            sum += course[0];
        }
        else if (!queue.empty() && queue.top() > course[0])
        {
            sum += course[0] - queue.top();
            queue.pop();
            queue.push(course[0]);
        }
    }
    return queue.size();
}