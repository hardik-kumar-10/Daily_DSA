class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        const int HashLen = 256; 
        int hash[HashLen];

        for (int i = 0; i < HashLen; i++) {
            hash[i] = -1;
        }

        int l = 0, r = 0, maxLen = 0;

        while (r < n) {
            unsigned char c = s[r];

            if (hash[c] != -1) {
                l = max(l, hash[c] + 1);
            }

            int len = r - l + 1;
            maxLen = max(len, maxLen);

            hash[c] = r;  
            r++;
        }

        return maxLen;
    }
};
