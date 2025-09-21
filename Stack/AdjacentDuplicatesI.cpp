#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        if(s.empty()) return "";
        stack<char> stringStack;
        stringStack.push(s[0]);
    
        for(int i = 1;i < s.length(); i++){
            if(!stringStack.empty() && stringStack.top() == s[i]){
                stringStack.pop();
            }
            else stringStack.push(s[i]);
        }
        string res = "";
        while(!stringStack.empty()){
            res+=stringStack.top();
            stringStack.pop();
            
        }
        reverse(res.begin(),res.end());
        return res;
    }
};