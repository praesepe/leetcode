class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        // read real number and complex number
        int a_real, a_complex;
        int b_real, b_complex;
        read(a, a_real, a_complex);
        read(b, b_real, b_complex);

        // calculate real part, -1 = i^2
        int real = (a_real * b_real) + (a_complex * b_complex) * -1;

        // calculate comlex part
        int complex = (a_real * b_complex) + (a_complex * b_real);

        // result
        string result = to_string(real) + "+" +  to_string(complex) + "i";
        return result;
    }

    void read(string s, int& real, int& complex) {
        int pos = s.find("+");
        real = stoi(s.substr(0, pos));
        complex = stoi(s.substr(pos + 1, s.length() - pos - 2));
    }
};

