class Solution {
public:
    void sortArr(vector<int>& nums1,int indx1, vector<int>& nums2,  int indx2){
        if(nums1[indx1]>nums2[indx2]){
            swap(nums1[indx1],nums2[indx2]);
        }
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int len=m+n;
       int gap=(len/2)+(len%2);
       while(gap>0){
            int left=0;
            int right=left+gap;
            while(right<len){
                if(left<m && right>=m){
                    sortArr(nums1,left,nums2,right-m);
                }
                else if(left>=m){
                    sortArr(nums2,left-m,nums2,right-m);
                }
                else{
                    sortArr(nums1,left,nums1,right);
                }
                left++;
                right++;
            }
            if (gap==1)break;
            gap=(gap/2)+(gap%2);
       }
       for(int i=0;i<n;i++){
            nums1[m+i] = nums2[i];
        }
    }
};