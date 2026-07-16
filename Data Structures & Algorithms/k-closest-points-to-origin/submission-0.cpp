class comp {
public:
    bool operator()(const vector<int>& point1, const vector<int>& point2)
{
    int x = point1[0] * point1[0] + point1[1] * point1[1];
    int y = point2[0] * point2[0] + point2[1] * point2[1];
    return x < y;
}
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, comp> pq;
        vector<vector<int>> result;
        for(int i = 0; i < points.size(); i++)
        {
            pq.push(points[i]);
        }
        while(pq.size() > k)
        {
            pq.pop();
        }
        while(!pq.empty())
        {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};
