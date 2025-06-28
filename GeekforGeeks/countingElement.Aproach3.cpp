class Solution {
  public:
  
    int binarySearch(vector<int>&b, int x){
        int s = 0; 
        int e = b.size() - 1;
        while(s <=e){
            int mid = s + (e - s)/2;
            if(b[mid] <= x){
                s = mid + 1;
            }
            else{
                e = mid - 1; 
            }
        }
        return s; 
    }
    
    vector<int> countLessEq(vector<int>& a, vector<int>& b){
        // code here
        int n = a.size();
        int m = b.size();
        
        vector<int> ans(n);
        
        sort(b.begin(),b.end());
        
        for(int i=0; i<n; i++){
            
            ans[i] = upper_bound(b.begin(),b.end(), a[i]) - b.begin();
            
        }
        
        return ans; 
    }
};