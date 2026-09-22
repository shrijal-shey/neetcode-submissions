class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int>freqS1(26 , 0);
        vector<int>freqS2(26 , 0);

        for(int i=0 ; i<s1.size() ; i++){
            freqS1[s1[i] - 'a']++;
            freqS2[s2[i] - 'a']++;
        }
        if(freqS1 == freqS2) return true;

        for(int i=s1.size() ; i<s2.size() ; i++){
            freqS2[s2[i] - 'a']++;
            freqS2[s2[i-s1.size()] - 'a']--;

            if(freqS1 == freqS2) return true;
        }
        return false;
    }
};
