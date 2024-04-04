class Solution {
public:
    int maxDepth(string s) {
       string k = "";
       for(auto it: s)
       {
        if(it=='(' || it==')')
        {
            k+=it;
        }
       } 
       cout<<k<<endl;
      int maxDepth = 0;
    int currentDepth = 0;

    for (char c : k) {
        if (c == '(') {
            currentDepth++;
            maxDepth = max(maxDepth, currentDepth);
        } else if (c == ')') {
            currentDepth--;
        }
    }

    return maxDepth;

    }
};