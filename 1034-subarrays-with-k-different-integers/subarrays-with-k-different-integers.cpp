class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
private:
    int atMost(vector<int>& nums, int k) {
        int l = 0, r = 0, cnt = 0;
        unordered_map<int, int> freq;
        
        while (r < nums.size()) {
            freq[nums[r]]++;
            while (freq.size() > k) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) {
                    freq.erase(nums[l]);
                }
                l++; 
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
};