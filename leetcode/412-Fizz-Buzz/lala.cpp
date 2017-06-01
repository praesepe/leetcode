#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result(n);
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) {
                result[i - 1] = "FizzBuzz";
            } else if (i % 5 == 0) {
                result[i - 1] = "Buzz";
            } else if (i % 3 == 0) {
                result[i - 1] = "Fizz";
            } else {
                stringstream ss;
                ss << i;
                result[i - 1] = ss.str();
            }
        }
 
        return result;
    }
};
