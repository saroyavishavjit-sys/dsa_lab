#include <bits/stdc++.h>
using namespace std;

string infix_to_postfix(string s){
    stack<char> st;
    string ans = "";
    unordered_map<char, int> mp;

    mp['('] = 0;
    mp['+'] = 1;
    mp['-'] = 1;
    mp['/'] = 2;
    mp['*'] = 2;
    mp['%'] = 2;
    mp['^'] = 3;

    for(auto it : s){
        if(isdigit(it)){
            ans += it;
        }
        else{
            if(it == '('){
                st.push('(');
            }
            else if(it == ')'){
                while(st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else if(st.empty()){
                st.push(it);
            }
            else if(mp[st.top()] > mp[it] && !((it == '^')&&(st.top() == '^'))){
                while(!st.empty() && st.top() != '(' && (mp[st.top()] > mp[it] || (mp[st.top()] == mp[it] && it != '^'))){
                    ans += st.top();
                    st.pop();
                }
                st.push(it);
            }
            else{
                st.push(it);
            }
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main(){
    string s = "1+5-3*5/(6+8)%6";

    cout << "Infix:   " << s << endl;
    cout << "Postfix: " << infix_to_postfix(s) << endl;
}

