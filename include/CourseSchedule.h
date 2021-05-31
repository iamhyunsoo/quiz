#include <unordered_map>
#include <vector>

using std::vector;

class Solution  //BFS
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> degrees(numCourses,0);
        std::unordered_map<int,std::vector<int>> graph;
        
        for (int i=0; i<prerequisites.size(); ++i) 
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degrees[prerequisites[i][0]]++;
        }

        for (int i = 0; i < numCourses; i++)
        {
            int j {0};
            for (; j < numCourses; j++)
            {
                if (!degrees[j])
                {
                    break;
                }                
            }

            if (j == numCourses)
            {
                return false;
            }

            degrees[j]--;

            for (auto const& v : graph[j])
            {
                degrees[v]--;
            }
        }
        return true;
    }
};

class Solution2     //DFS
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        std::vector< std::vector< int >> graph = makeGraph(numCourses, prerequisites);
        std::vector<bool> todo(numCourses, false);
        std::vector<bool> done(numCourses, false);

        for (int i = 0; i < numCourses; i++)
        {
            if (!done[i] && !findCycle(i, graph, todo, done))
            {
                return false;
            }
        }
        return true;
    }
private:
    std::vector< std::vector< int >> makeGraph(const int& numCourses, vector<vector<int>>& prerequisites)
    {
        std::vector< std::vector< int >> ret(numCourses);
        for (auto const& prerequisite : prerequisites)
        {
            ret[prerequisite[1]].push_back(prerequisite[0]);
        }
        return ret;
    }

    bool findCycle(const int& node, const std::vector< std::vector< int >>& graph, std::vector<bool>& todo, std::vector<bool>& done)
    {
        if (todo[node])
        {
            return false;
        }

        if (done[node])
        {
            return true;
        }

        todo[node] = done[node] = true;

        for (auto const& i : graph[node])
        {
            if (!findCycle(i, graph, todo, done))
            {
                return false;
            }
        }

        todo[node] = false;
        return true;
    }
};