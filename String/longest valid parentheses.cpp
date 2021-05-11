
// the idea is that you simply use stack and 
// for open parenthesis you store the indexes and 
// as soon you encounter with a closing parenthesis
// you do calculate length which is the current index value
// minus the top of stack after popping out there
// any case you have stack as empty 
// you do fill the stack with the current indices value


class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> sk;
        int maxl=0,i=0;
        sk.push(-1);
        int len;
        while(i!=s.size()){
            if(s[i]=='('){
                sk.push(i);
            }
            else if(s[i]==')'){
                sk.pop();
                if(sk.empty()){
                sk.push(i);
                }
                else{
                    maxl=max(maxl,i-(sk.top()));
                }
                
            }
           
            i++;
        }
        return maxl;
    }
};