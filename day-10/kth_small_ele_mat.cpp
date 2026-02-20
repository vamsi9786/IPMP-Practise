similar algo to median by in median req=(n*m)/2 but here req=k-1;

class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n=mat.size();
        int low=INT_MAX,high=INT_MIN;
        for(int i=0;i<n;i++){
            low=min(low,mat[i][0]);
            high=max(high,mat[i][n-1]);
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            int c=0;
            for(int i=0;i<n;i++){
                c+=upper_bound(mat[i].begin(),mat[i].end(),mid) - mat[i].begin();
            }
            if(c<=k-1){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};
