//FIND ALL ANAGRAMS IN A STRING
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size(), m = p.size();

        if (m > n) return ans;

        vector<int> pCount(26, 0), winCount(26, 0);

        for (char c : p)
            pCount[c - 'a']++;

        for (int i = 0; i < n; i++) {
            winCount[s[i] - 'a']++;

            if (i >= m)
                winCount[s[i - m] - 'a']--;

            if (winCount == pCount)
                ans.push_back(i - m + 1);
        }

        return ans;
    }
};