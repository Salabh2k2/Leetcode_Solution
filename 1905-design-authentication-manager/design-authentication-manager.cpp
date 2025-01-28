#include <set>
#include <map>
#include <string>
using namespace std;

class AuthenticationManager {
public:
    int delta = 0;
    set<pair<int, string>> st;
    map<string, int> mp;

    AuthenticationManager(int timeToLive) {
        delta = timeToLive;
        st.clear();
        mp.clear();
    }
    
    void generate(string tokenId, int currentTime) {
        cleanup(currentTime);
        st.insert({currentTime, tokenId});
        mp[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        cleanup(currentTime);
        if (mp.find(tokenId) != mp.end()) {
            int t = mp[tokenId];
            if (currentTime - t < delta) {
                st.erase({t, tokenId});
                st.insert({currentTime, tokenId});
                mp[tokenId] = currentTime;
            }
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        cleanup(currentTime);
        return st.size();
    }

private:
    void cleanup(int currentTime) {
        while (!st.empty() && currentTime - st.begin()->first >= delta) {
            auto p = *st.begin();
            st.erase(st.begin());
            mp.erase(p.second);
        }
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
