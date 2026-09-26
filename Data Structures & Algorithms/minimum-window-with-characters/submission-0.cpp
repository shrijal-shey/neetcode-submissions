class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int , int>mp;
        for(auto it: t) mp[it]++;

        int minLen = INT_MAX;
        int sIndex = -1;

        int l=0 , r=0;
        int cnt = 0;
        for(int r=0 ; r<s.size() ; r++){
            char ch = s[r];
            if(mp[ch]> 0) {
                cnt++;
            }
            mp[ch]--;
            while(cnt == t.size()){
               if(r-l+1 < minLen){
                 minLen = r-l+1;
                 sIndex = l;
               }
               mp[s[l]]++;
               if(mp[s[l]] > 0) cnt = cnt-1;
               l++;
            }
        }
        return sIndex == -1 ? "" : s.substr(sIndex , minLen);
    }
};
