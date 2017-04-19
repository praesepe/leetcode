public class Solution {
    public boolean isNumber(String s) {
        if (s.isEmpty()) {
            return false;
        }
        s = s.trim();
        int i = 0;
        if (i < s.length() && (s.charAt(i) == '-' || s.charAt(i) == '+')) {
            i++;
        }
        Map<Character, Integer> posMap = new HashMap();
        boolean hasNum = false;
        while (i < s.length()) {
            if (s.charAt(i) == '-' || s.charAt(i) == '+') {
                // + - must next to e.
                if (!posMap.containsKey('e')) {
                    return false;
                } else if (i != posMap.get('e') + 1) {
                    return false;
                }
                posMap.put(s.charAt(i), i);
            } else if (s.charAt(i) == '.') {
                // . must before e.
                if (posMap.containsKey('e') || posMap.containsKey('.')) {
                    return false;
                }
                posMap.put(s.charAt(i), i);
            } else if (s.charAt(i) == 'e') {
                // e
                if (posMap.containsKey('e')) {
                    return false;
                } else {
                    if (!hasNum) {
                        return false;
                    }
                    hasNum = false;
                }
                posMap.put(s.charAt(i), i);
            } else if (Character.isDigit(s.charAt(i))) {
                hasNum = true;
            } else {
                return false;
            }
            i++;
        }

        return hasNum;
    }
}