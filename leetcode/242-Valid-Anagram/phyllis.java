class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() == t.length()){
            char sCharArray[] = s.toCharArray();
            char tCharArray[] = t.toCharArray();
            Arrays.sort(sCharArray);
            Arrays.sort(tCharArray);
            for(int i = 0; i < s.length(); i++){
                if(sCharArray[i] != tCharArray[i])
                    return false;
            }
        } else {
            return false;
        }
        
        return true;
    }
}
