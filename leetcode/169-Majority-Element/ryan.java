class Solution {
    public int majorityElement(int[] nums) {
        int head = 0;
        int tail = nums.length - 1;
        Map<Integer, Integer> count_map = new HashMap();
        int max_count = 0;
        int res = nums[0];
        while (head <= tail) {
            if (nums[head] == nums[tail]) {
                int val = nums[head];
                if (!count_map.containsKey(val)) {
                    count_map.put(val, 0);
                }
                int count = count_map.get(val) + (head != tail ? 2 : 1);
                count_map.put(val, count);
                if (count > max_count) {
                    max_count = count;
                    res = val;
                }
            }
            head++;
            tail--;
        }

        return res;
    }
}