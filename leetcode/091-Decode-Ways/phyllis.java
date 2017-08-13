public class Solution {
    public int numDecodings(String s) {
        int length = s.length();
        int ways = 0;
        int last_one = 1;
        int last_two = 1;       
        
        if (length == 0) 
            return 0;        
      
        if(s.charAt(0) == '0') 
            return 0;        
       public class Solution {
    public int numDecodings(String s) {
        int length = s.length();
        int ways = 0;
        int last_one = 1;
        int last_two = 1;       
        
        if (length == 0) 
            return 0;        
      
        if(s.charAt(0) == '0') 
            return 0;        
        
        if (length == 1) 
            return 1;
        
        for(int i=2; i <= s.length(); i++)
        {
            ways = 0;            
            int num = Integer.parseInt(s.substring(i-2,i));
            if(num >= 10 && num <= 26) 
                ways = last_two;
            
            if(s.charAt(i-1) != '0') 
                ways += last_one;
            
            last_two = last_one;
            last_one = ways;            
        }
        
        return last_one;
        
    }
} 
        if (length == 1) 
            return 1;
        
        for(int i=2; i <= s.length(); i++)
        {
            ways = 0;            
            int num = Integer.parseInt(s.substring(i-2,i));
            if(num >= 10 && num <= 26) 
                ways = last_two;
            
            if(s.charAt(i-1) != '0') 
                ways += last_one;
            
            last_two = last_one;
            last_one = ways;            
        }
        
        return last_one;
        
    }
}
