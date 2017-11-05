写个逆波兰

```c++
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

```



再写个符号匹配

```
//引入IO流头文件
#include<iostream>
//引入栈头文件
#include<stack>
#include<vector>
#include<string>
using namespace std;

class Solution {
    public:
        bool isValid(string str) {
            stack<int> s;
            int size = str.length();
            int result, rnum, lnum;
            for (int i=0; i < size; i++) {
                switch(str[i]) {
                    case '{':
                    case '[':
                    case '(':
                        s.push(str[i]);
                        break;
                    case ')':
                        if (s.empty() || s.top() != '(')
                            return false;
                        s.pop();
                        break;
                    case ']':
                        if (s.empty() || s.top() != '[')
                            return false;
                        s.pop();
                        break;
                    case '}':
                        if (s.empty() || s.top() != '{')
                            return false;
                        s.pop();
                        break;
                    default:
                        break;
                }
                
            }
            if(s.empty()) 
                return true;
            return false;
        }
};

int main() {
    bool res = Solution().isValid("[{(}]");
    cout<<res<<" ";
    cout<<endl;

    return 0;
}

```