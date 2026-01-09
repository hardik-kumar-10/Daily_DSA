class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0;
        int rsum=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
            lsum=lsum+cardPoints[i];
        }
        int maxSum = lsum;
        int rindex=n-1;
        for(int i=k-1;i>=0;i--){
            lsum=lsum-cardPoints[i];
            rsum=rsum+cardPoints[rindex];
            rindex=rindex-1;
            maxSum=max(maxSum,lsum+rsum);
        }
        return maxSum;
    }
};