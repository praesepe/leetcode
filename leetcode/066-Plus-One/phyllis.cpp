ss Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int plus_num = 1;
        int tmp;
        auto it = digits.rbegin();
        while(it != digits.rend())
        {
            tmp = *it + plus_num;
            *it = tmp % 10;
            plus_num = tmp / 10;
            ++it; 
        }
       
        if( plus_num == 1 ){
            digits.resize(digits.size()+1);
            digits.at(0) = 1;
        }
  
        return digits;
    }
};

