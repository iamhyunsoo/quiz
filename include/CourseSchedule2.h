#include <queue>
#include <unordered_map>
#include <vector>

using std::queue;
using std::vector;
using std::unordered_map;

class Solution  //BFS
{
public:
    std::vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        std::vector<int> ret;
        vector<int> degrees(numCourses,0);
        std::unordered_map<int,std::vector<int>> graph;
        
        for (int i=0; i<prerequisites.size(); ++i) 
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degrees[prerequisites[i][0]]++;
        }

        queue<int> que;
        for (int i = 0; i < numCourses; i++)
        {
            if (!degrees[i])
            {
                que.push(i);
            }
        } 

        int total {0};
        int curr {0};
        while (!que.empty())
        {
            curr = que.front();
            que.pop();
            ret.push_back(curr);

            for (auto const& pointTo : graph[curr])
            {
                degrees[pointTo]--;
                if (!degrees[pointTo])
                {
                    que.push(pointTo);
                }
            }
            total++;
        }

        if (total != numCourses)
        {
            return {};
        }
        return ret;
    }
};
