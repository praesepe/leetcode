class Solution {
public:
    string intToRoman(int num) {
        char cstr[16] = {'\0'};
        char sign[13] ={'C','D','M', 'X', 'L', 'C', 'I', 'V', 'X'};
        int i = 0;
        int divide =1000;
        int sign_ptr = 0;
        
        // handle thousands of digits，num = 1000~4000
        if(num >= 1000){
            int total = num / 1000;
            while(i < total){
                cstr[i++] = 'M';
            }
        }
        
        while(divide >= 10){
            num = num % divide;
            divide = divide /10;
            
            // e.g. num = 900~999 
            if(num >= 9*divide){
                cstr[i++] = sign[sign_ptr];
                cstr[i++] = sign[sign_ptr+2];
            // e.g. num = 500~899    
            } else if(num >= 5*divide){
                cstr[i++] = sign[sign_ptr+1];
                int append = (num-5*divide)/divide;
                while(append-- > 0){
                    cstr[i++] = sign[sign_ptr];
                }
            // e.g. num = 400~499      
            } else if(num >= 4*divide){
                cstr[i++] = sign[sign_ptr];
                cstr[i++] = sign[sign_ptr+1];
            // e.g. num = 100~399
            } else if(num >= divide){
                int total = num/divide;
                while(total-- > 0){
                    cstr[i++] = sign[sign_ptr];;
                }
            }
            sign_ptr = sign_ptr + 3;
        }
    
        std::string str(cstr);
    
        return str;
    }
};



