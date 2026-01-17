class Solution {
  public:
    vector<int> sieve(int n) {
        int l=2,r=n;
        vector<int> ar;
        if(n==1) return ar;
        while(l<=r){
            if(l==r){
                int f=0;
                for(int i=2;i<=(int)sqrt(l);i++){
                    if(l%i==0){
                        f=1;break;
                    }
                }
                if(!f) ar.push_back(l); 
            }
            else{
                int f=0;
                for(int i=2;i<=(int)sqrt(l);i++){
                    if(l%i==0){
                        f=1;break;
                    }
                }
                if(!f) ar.push_back(l); 
                
                f=0;
                for(int i=2;i<=(int)sqrt(r);i++){
                    if(r%i==0){
                        f=1;break;
                    }
                }
                if(!f) ar.push_back(r); 
            }
            l++;r--;
        }
        sort(ar.begin(),ar.end());
        return ar;
    }
};
