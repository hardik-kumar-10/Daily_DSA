class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max=INT_MIN;
        int sum=0;
        int ansEnd=-1;
        int ansStart=-1;
        int start;
        for(int i=0;i<nums.size();i++){
            if(sum==0)
                start=i;        
            sum=sum+nums[i];
            if(sum>max){
                max=sum;
                ansStart=start,ansEnd=i;
            }
            if(sum<0){
                sum=0;
            }
        }
        return max;
    }
};