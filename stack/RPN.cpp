//引入IO流头文件
#include<iostream>
//引入栈头文件
#include<stack>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
    public:
        int evalRPN(vector<string>&tokens) {
            stack<int> s;
            int size = tokens.size();
            int result, rnum, lnum;
            for (int i=0; i < size; i++) {
                
                if (tokens[i] == "*") {
                    lnum = s.top();
                    s.pop();
                    rnum = s.top();
                    s.pop();
                    s.push(lnum * rnum);
                } else if (tokens[i] == "/") {
                    lnum = s.top();
                    s.pop();
                    rnum = s.top();
                    s.pop();
                    s.push(lnum / rnum);
                } else if (tokens[i] == "-") {
                    lnum = s.top();
                    s.pop();
                    rnum = s.top();
                    s.pop();
                    s.push(lnum - rnum);
                } else if (tokens[i] == "+") {
                    lnum = s.top();
                    s.pop();
                    rnum = s.top();
                    s.pop();
                    s.push(lnum + rnum);
                } else {
                
                    s.push(atoi(tokens[i].c_str()));
                }
            }
            return s.top();
        }
};

int main() {
    string n[] = {"2", "1", "+", "3", "*"} ;
    vector<string> str(n, n+5) ; 
    int res = Solution().evalRPN(str);
    cout<<res<<" ";
    cout<<endl;

    return 0;
}
