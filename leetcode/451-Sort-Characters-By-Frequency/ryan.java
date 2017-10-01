class Solution {
    public String frequencySort(String s) {
        // count_map
        Map<Character, Integer> count_map = new HashMap();
        for (char c : s.toCharArray()) {
            if (!count_map.containsKey(c)) {
                count_map.put(c, 0);
            }
            count_map.put(c, count_map.get(c) + 1);
        }
        // sort
        Map<Integer, List<Character>> sort = new HashMap();
        int max = 0;
        for (Character c : count_map.keySet()) {
            Integer count = count_map.get(c);
            if (!sort.containsKey(count)) {
                sort.put(count, new ArrayList());
            }
            sort.get(count).add(c);
            max = Math.max(max, count);
        }
        // print
        StringBuilder sb = new StringBuilder();
        for (int i = max; i > 0; i--) {
            if (sort.containsKey(i)) {
                for (Character c : sort.get(i)) {
                    for (int times = i; times > 0; times--) {
                        sb.append(c);
                    }
                }
            }
        }

        return sb.toString();
    }
}