Class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int size = tokens.size();
        
        for(string& s : tokens){
            if(s == "+" ||  s == "-" || s == "*" || s == "/"){
                const char *c = s.c_str();
                int b = nums.top();
                nums.pop();
                int a = nums.top();
                nums.pop();
            
                switch(*c){
                    case '+':
                        nums.push(a+b);
                        break;
                    case '-':
                        nums.push(a-b);
                        break;
                    case '*':
                        nums.push(a*b);
                        break;
                    case '/':
                        nums.push(a/b);
                        break;
                }
                
            }else{
                nums.push(stoi(s));
            }
        }
        
        return nums.top();
    }
};


