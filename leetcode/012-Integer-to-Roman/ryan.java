public class Solution {
    public String getRoman_0To9(int num, String one, String five, String ten) {
        switch (num) {
            case 1:
                return one;
            case 2:
                return one + one;
            case 3:
                return one + one + one;
            case 4:
                return one + five ;
            case 5:
                return five;
            case 6:
                return five + one;
            case 7:
                return five + one + one;
            case 8:
                return five + one + one + one;
            case 9:
                return one + ten;
            default:
                return "";
        }
    }

    public String intToRoman(int num) {
        Map<Integer, String[]> map = new HashMap();
        map.put(0, new String[]{"I", "V", "X"}); // for 1, 2, ... , 9, 10
        map.put(1, new String[]{"X", "L", "C"}); // for 10, 20, ... , 90, 100
        map.put(2, new String[]{"C", "D", "M"}); // for 100, 200, ... , 900, 1000
        map.put(3, new String[]{"M", "A", "B"}); // for 1000, 2000, ... , 9000, 10000
        
        StringBuilder sb = new StringBuilder();
        int idx = 0;
        while(num != 0) {
            int mod = num % 10;
            num /= 10;
            sb.insert(0, getRoman_0To9(mod, map.get(idx)[0], map.get(idx)[1], map.get(idx)[2]));
            idx++;
        }

        return sb.toString();
    }
}