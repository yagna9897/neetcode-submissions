class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int m = 0;
        for (auto num : piles) 
        {
            m = std::max(m,num);
        }
        int l = 1;
        int r = m;
        int result = m;
        while(l <= r)
        {
            int i = l + (r-l)/2;

            int hours = 0;
            for(auto pile : piles)
            {
                hours += (pile + i - 1) / i;
            }

            if(hours <= h)
            {
                result = i;
                r = i - 1;
            }
            else 
                l = i + 1;
        }
       
        return result;
    }
};
