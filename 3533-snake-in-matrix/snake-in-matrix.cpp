class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int ans = 0;
        for(auto it:commands)
        {
            if(it=="LEFT") ans--;
            if(it=="RIGHT") ans++;
            if(it=="DOWN") ans+=n;
            if(it=="UP") ans-=n;
        }
        return ans;
    }
};