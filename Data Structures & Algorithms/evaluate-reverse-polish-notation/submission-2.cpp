class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto& it : tokens) {
            if (it == "+" || it == "-" || it == "*" || it == "/"){
                int x = st.top();
                st.pop(); 
                int y = st.top(); 
                st.pop();  

                if (it == "+") st.push(y + x);
                else if (it == "-") st.push(y - x);
                else if (it == "*") st.push(y * x);
                else st.push(y / x); 
            } 
            else st.push(stoi(it));
        }
        return st.top();
    }
};