class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size()<p.size()) return res;
        vector<int> countp(26,0),counts(26,0);
        for(int i=0;i<p.size();i++){
            countp[p[i]-'a']++;
            counts[s[i]-'a']++;
        }
        if(countp==counts) res.push_back(0);
        for(int i=p.size();i<s.size();i++){
            counts[s[i]-'a']++;
            counts[s[i-p.size()]-'a']--;
            if(counts==countp) res.push_back(i-p.size()+1);
        }
        return res;
    }
};