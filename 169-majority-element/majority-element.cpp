class Solution {
public:
    int majorityElement(vector<int>& nums) {
        vector<int> ls;              
        map<int,int> mpp;
        int n = nums.size();
        int mini = n/2;
        for (int i=0;i<n;i++) {
            int c =++mpp[nums[i]];
            if (c>mini) {          
                return nums[i];     
            }
            if ((int)ls.size()==3) break; 
        }
        return -1;
    }
};
