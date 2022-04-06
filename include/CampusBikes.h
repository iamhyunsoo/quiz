class Solution 
{
public:
    std::vector<int> assignBikes(std::vector<std::vector<int>>& workers, std::vector<std::vector<int>>& bikes) 
	  {
      std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int,int,int>>, std::greater<std::tuple<int, int, int>>> pq;
      std::vector<std::vector<std::tuple<int, int, int>>> distances;
      std::vector<bool> bikesAssigned(bikes.size(), false);
      std::vector<int> workerBikePairs(workers.size(), -1);

      for (size_t i = 0; i < workers.size(); i++)
      {
        std::vector<std::tuple<int, int, int>> distancesFromWorker;
        for (size_t j = 0; j < bikes.size(); j++)
        {
          distancesFromWorker.push_back({this->findDistance(workers[i], bikes[j]), i, j});
        }

        std::sort(distancesFromWorker.begin(), distancesFromWorker.end(), std::greater<std::tuple<int, int, int>>());
        auto smallest = distancesFromWorker.back();
        pq.push(smallest);

        distancesFromWorker.pop_back();
        distances.push_back(distancesFromWorker);
      }		

      while (!pq.empty())
      {
        auto[distance, worker, bike] = pq.top();
        pq.pop();

        if (!bikesAssigned[bike])
        {
          workerBikePairs[worker] = bike;
          bikesAssigned[bike] = true;
        }
        else
        {
          pq.push(distances[worker].back());
          distances[worker].pop_back();
        }
      }
      return workerBikePairs;
    }
private:
    int findDistance(std::vector<int>& worker, std::vector<int>& bike) 
    {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
};
