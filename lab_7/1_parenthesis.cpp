#include <bits/stdc++.h>
using namespace std;

void count_parenthesis(string s){
    int ans = 0;
    int size = 0;
    int invalid = -1;

    stack<pair<char,int>> st;
    
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == '('){
            st.push({'(', i});
            size++;           
        }
        else if(s[i] == ')'){

            if(!st.empty() && st.top().first == '('){
                st.pop();

                if (st.empty()) {
                    ans = max(ans, i - invalid);
                }
                else {
                    ans = max(ans, i - st.top().second);
                }
            }
            else{
                invalid = i;
            }
        }
    }
    cout << "max length : " << ans << "\n";
    cout << "stack size used : " << size << "\n";
}

int main() {

    string s = ")()())";

    count_parenthesis(s);

    return 0;
}
