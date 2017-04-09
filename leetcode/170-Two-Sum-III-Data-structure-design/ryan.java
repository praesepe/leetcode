import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Algo170_TwoSum3 {

    private List<Integer> nums = new ArrayList();

    public void add(int input) {
        this.nums.add(input);
    }

    public boolean find(int target) {
        if (this.nums.size() < 2) {
            return false;
        }
        Collections.sort(this.nums);
        int left = 0;
        int right = this.nums.size() - 1;
        while (right > left) {
            int sum = this.nums.get(left) + this.nums.get(right);
            if (sum == target) {
                return true;
            } else if (sum > target) {
                right--;
            } else if (sum < target) {
                left++;
            }
        }
        return false;
    }

    public static void main(String[] args) {

        Algo170_TwoSum3 tw = new Algo170_TwoSum3();
        tw.add(1);
        tw.add(3);
        tw.add(5);
        System.out.println(tw.find(4));

    }
}
