class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;

        for (int i=0; i<s.size(); i++){
            if (s[i] == '('){
                st.push(make_pair(s[i], i));
            }
            else if (s[i] == ')'){
                if (st.empty() || st.top().first != '('){
                    s[i] = '/';
                }
                else{
                    st.pop();
                }
            }
        }

        while (!st.empty()){
            s[st.top().second] = '/';
            st.pop();
        }

        string res = "";
        for(int i=0; i<s.size(); i++){
            if (s[i] != '/') res += s[i];
        }

        return res;
    }
};
