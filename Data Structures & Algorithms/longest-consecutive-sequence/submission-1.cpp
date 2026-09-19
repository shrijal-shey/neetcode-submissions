
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin() , nums.end());
        int maxi = 0;
        for(auto num: nums){
            if(st.find(num-1) == st.end()){
                int len = 1;
                int current = num;

                while(st.find(current+1) != st.end()){
                    current++;
                    len++;
                }
                maxi = max(len , maxi);
            }
        }
        return maxi;

    }
};
