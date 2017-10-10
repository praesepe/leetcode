class Solution {
    public int countPrimes(int n) {         
         if(n < 3) 
             return 0;
        
         // count include number 2 in the beginning
         int count = 1;
        
         // to check every number
         for(int i = 3; i < n; i+=2){             
             boolean isPrime = false;             
 
            // to check if i is prime
             for(int j = 3; j * j <= i; j+=2){
                 if(i % j == 0){
                     isPrime = true;
                     break;
                 }                
             }
             
             if(!isPrime)
                 count++;
         }
        
         return count;

    }
}
