class Solution {
private:
    bool possible(vector<int>& piles, int h , int rate){
        int time = 0;
        for(int i=0 ; i<piles.size() ; i++){
            time += (piles[i] + rate - 1)/rate;
            if(time > h) return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin() , piles.end());
        int ans = e;
        while(s < e){
            int mid = s + (e - s) / 2;
            if(possible(piles , h , mid)){
               ans = mid;
               e = mid;
            }
            else s = mid+1; 
        }
        return ans;
    }
};
