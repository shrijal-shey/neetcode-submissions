class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int maxAmt = 0;

        while(left < right){
            int width = right-left;
            int height = min(heights[left] , heights[right]);
            maxAmt = max(maxAmt , width*height);

            if(heights[left] < heights[right]) left++;
            else right--;
        }
        return maxAmt;
    }
};
