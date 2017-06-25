class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        int size = s.size();
        const char* cstr = s.c_str();
        
        for(int i = 0; i < size; i++){
            char c = cstr[i];
            
            if(c == '(' || c == '[' || c == '{') {
                brackets.push(c);
                
            } else if(!brackets.empty()){
                if(brackets.top() == '(' && c == ')') {
                    brackets.pop();
                } else if(brackets.top() == '[' && c == ']') {
                    brackets.pop();
                } else if(brackets.top() == '{' && c == '}') {
                    brackets.pop();
                } else
                    return false;
                
            } else {
                return false;
            }
        }
        
        if(!brackets.empty())
            return false;
            
        return true;
    }
};
