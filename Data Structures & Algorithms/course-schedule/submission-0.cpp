class Solution {
    bool DFSRec(const vector<vector<int>>& adjList, int source, vector<bool>& visited, vector<bool>& pathVisited )
    {
        visited[source] = true;
        pathVisited[source] = true;

        for(auto v : adjList[source])
        {
            if(visited[v] == true && pathVisited[v] == true)
                return false; // impossible
            else if(visited[v] == false && false == DFSRec(adjList, v, visited, pathVisited))
                return false;
        }
        pathVisited[source] = false;

        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(const auto vec : prerequisites)
            adjList[vec[1]].push_back(vec[0]);

        vector<bool> visited(numCourses, false);
        vector<bool> pathVisited(numCourses, false);
        for(int i = 0; i < numCourses; i++)
        {
            if(visited[i] == false && false == DFSRec(adjList, i, visited, pathVisited))
                return false;
        }
        return true;
    }
};
