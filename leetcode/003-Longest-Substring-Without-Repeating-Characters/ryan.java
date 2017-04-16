public class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) {
            return 0;
        }
        int maxLen = 0;
        Map<Character, Integer> posMap = new HashMap();
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            if (posMap.containsKey(s.charAt(i))) {
                // find new start index
                start = Math.max(posMap.get(s.charAt(i)) + 1, start);
            }
            posMap.put(s.charAt(i), i);
            maxLen = Math.max(maxLen, i - start + 1);
        }

        return maxLen;
    }
}