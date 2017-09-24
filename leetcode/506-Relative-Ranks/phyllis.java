class Solution {
    public String[] findRelativeRanks(int[] nums) {
        Map<Integer, Integer> map = 
                        new TreeMap<Integer, Integer>();
        int length = nums.length;
        String[] ranks = new String[length];
        String[] medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        for(int i = 0; i < length; i++){
             map.put(nums[i], i);
        }       
       
        int order = length;
        for(Integer key: map.keySet()) {
            int idx = map.get(key);          
            String strOrder = order <= 3 ? medals[order - 1] : String.valueOf(order); 
            ranks[idx] = String.valueOf(strOrder);
            order--;
        }
        
        return ranks;
    }
}
