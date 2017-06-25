class Solution {
public:
     // to divide two steps into one step : p(n,1)...p(n,n) 
    int climbStairs(int n) {
        if(n == 0 || n == 1 || n == 2){
            return n;
        }
        
        int step[n];
        step[0] = 1;
        step[1] = 2;
        for(int i = 2; i < n; i++){
            step[i] = step[i-1] + step[i-2];
        }
        return step[n-1];
    }
};
