class Solution {
    public int countPrimes(int n) {
         boolean[] notPrime = new boolean[n];
         if(n < 3) 
             return 0;
        
         // count include number 2 in the beginning
         int count = 1;
        
         // to check every number
         for(int i = 3; i < n; i+=2){             
              if (notPrime[i] == false) {
                count++;
                for (int j = 2; i*j < n; j++) {
                    notPrime[i*j] = true;
                }
              }
         }
        
         return count;

    }
}

