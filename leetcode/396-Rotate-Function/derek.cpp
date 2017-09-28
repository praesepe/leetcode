class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        // calculate sum and F(0)
        int sum = 0, t = 0, n = A.size();
        for (int i = 0; i < n; i++) {
            sum += A[i];
            t += i * A[i];
        }

        // iterate through F(1) to F(N-1)
        int result = t;
        for (int i = 1; i < n; i++) {
            t = t + sum - 4 * A[n - i];
            result = max(result, t);
        }

        return result;
    }
};

