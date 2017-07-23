public class Solution {
    public int maximumGap(int[] nums) {
        if (nums == null || nums.length < 2) {
            return 0;
        }
        // get the max and min value of the array
        int min = nums[0];
        int max = nums[0];
        for (int i : nums) {
            min = Math.min(min, i);
            max = Math.max(max, i);
        }
        // the minimum possibale gap
        int gap = Math.max(1, (max - min) / (nums.length - 1));
        int totalBucketNum = (max - min) / gap + 1;
        int[] bucketsMIN = new int[totalBucketNum];
        int[] bucketsMAX = new int[totalBucketNum];
        int[] bucketsCnt = new int[totalBucketNum];
        Arrays.fill(bucketsMIN, Integer.MAX_VALUE);
        Arrays.fill(bucketsMAX, Integer.MIN_VALUE);
        Arrays.fill(bucketsCnt, 0);
        // put numbers into buckets
        for (int i : nums) {
            int idx = (i - min) / gap;
            bucketsMIN[idx] = Math.min(i, bucketsMIN[idx]);
            bucketsMAX[idx] = Math.max(i, bucketsMAX[idx]);
            bucketsCnt[idx]++;
        }
        // scan the buckets for the max gap
        int maxGap = Integer.MIN_VALUE;
        int last_max = min;
        for (int i = 0; i < totalBucketNum; i++) {
            if (bucketsCnt[i] > 0) {
                maxGap = Math.max(maxGap, bucketsMIN[i] - last_max);
                last_max = bucketsMAX[i];
            }
        }
        return maxGap;
    }
}