class Solution {
public:
    int binsrch(vector<int>& nums,int tar,int l,int r){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==tar) return mid;
            else if(nums[mid]>tar) r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=1,r=n-2,f=0;
        while(l<=r){
            if(nums[l-1]>nums[l]){
                break;
            }
            if(nums[r]>nums[r+1]){
                f=1;
                break;
            }
            l++;r--;
        }
        int idx;
        if(f) idx=r;
        else idx=l-1;
        int idx1=binsrch(nums,target,0,idx);
        int idx2=binsrch(nums,target,idx+1,n-1);
        if(idx1==-1 && idx2!=-1) return idx2;
        else if(idx1!=-1 && idx2==-1) return idx1;
        else return -1;
    }
};
