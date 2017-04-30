class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int div = 1;
        int tmp = x;
        // for getting 1st digit
        while((tmp = tmp/10)> 0)
        {
            div = div *10;
        }

        while(div >= 10){
                                        //e.g. case:2053333502
            if(((x / div) == x % 10) || (x < div && x % 10 ==0))
            {
                x = x % div;
                x = x / 10;
            
                div = div/100;
            }else
            { 
                return false;    
            }
        }
        return true;
    }   
};
