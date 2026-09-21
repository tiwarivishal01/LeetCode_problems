class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<n;i++){
            if(!st.empty() &&st.top()==s[i]){
                st.pop();
            }else{
                st.push(s[i]);
            }
            
        }
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();

        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};