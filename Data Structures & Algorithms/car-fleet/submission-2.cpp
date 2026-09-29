class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (position.size() != speed.size()) return 0;
        vector<pair<int, int>> vCarDetails;
        for (int i = 0; i < position.size(); i++)
            vCarDetails.push_back(pair{position[i], speed[i]});

        sort(vCarDetails.begin(), vCarDetails.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) { return a.first > b.first; });

        double refTime = -1.0;
        int nbFleet = 0;

        for (const auto& car : vCarDetails) {
            double timeToReach = static_cast<double>(target - car.first) / car.second;
            if (timeToReach > refTime) {
                refTime = timeToReach;
                nbFleet++;
            }
        }

        return nbFleet;
    }
};
