class Solution {
public:
    int maximumDifference(vector<int>& nums) {
       int n = nums.size();

       int minEl = nums[0]; 

       int maxDiff = -1 ; 

       for(int j=1; j<n; j++){
           if(nums[j] > minEl){
              maxDiff = max(maxDiff, nums[j] - minEl);
           }
           else{
            minEl = nums[j];
           }
       }
       return maxDiff; 
    }
};

int main(){

    return 0; 
}