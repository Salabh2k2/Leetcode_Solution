class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int  n  = students.size();
        queue<int>q;
        stack<int>st;
        for(auto it:students)
        {
            q.push(it);
        }
        for(int i = n-1;i>=0;i--)
        {
            st.push(sandwiches[i]);
        }
        int ct = 0;
        while(ct<n && q.size())
        {
            if(q.front()!=st.top())
            {
                int k = q.front();
                q.pop();
                q.push(k);
                ct++;
            }
            else{
                q.pop();
                st.pop();
                ct = 0;
            }
        }
        return q.size();

    }
};