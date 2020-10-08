#include<iostream>
#include<string>
#include<stack>

using namespace std;

string calc(string& l, string& r, const string& op)
{
    //support + -
    string s;
	if (op == "-")
    {
        s = to_string(stoi(l) - stoi(r));
    }
    if (op == "+")
    {
        s = to_string(stoi(l) + stoi(r));
    }
    
	return s;
}

int main()
{
    string s("1+2*(7-4)");
    stack<string> stack;
    for(auto it = s.begin();it != s.end();)
    {
        if (*it == '(')
        {
            stack.push(string(1, *it));
            ++it;
            while(*it != ')')
            {
                stack.push(string(1, *it));
                ++it;
            }
        }
        else if(*it == ')')
        {
            string r = stack.top();
            stack.pop();
            string op = stack.top();
            stack.pop();
            string l = stack.top();
            stack.pop();

            stack.pop();
            stack.push(calc(l,r,op));
            ++it;
        }
        else
        {
            ++it;
        }
        
    }
    while (!stack.empty())
    {
        cout << stack.top() << endl;
        stack.pop();
    }
    
    return 0;
}