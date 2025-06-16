class Solution {
public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int n = heights.size(); 
        long long result = LLONG_MAX; 
        
        // Iterate through each tower height as a potential target height
        for(int i = 0; i < n; i++){
            long long total = 0; 
            int target_height = heights[i]; // Make all towers this height
            
            // Calculate the cost to make all other towers equal to target_height
            for(int j = 0; j < n; j++){
                total += (long long)abs(heights[j] - target_height) * cost[j];
            }
            
            // taking the minimum value from it
            result = min(result, total); 
        }
        // The problem statement implies the result should fit in an int,
        // but intermediate sums can be large, so long long is appropriate for `total` and `result`.
        // If the final result can exceed INT_MAX, then return type should be long long.
        // Assuming it's safe to cast to int for the final return based on the function signature.
        return (int)result;
    }
};