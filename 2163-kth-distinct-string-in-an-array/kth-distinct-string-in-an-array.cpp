class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        mp.reserve(arr.size());
        for(string& s: arr)
            mp[s]++;

        for(string& s: arr){
            if (mp[s]==1) k--;
            if (k==0)  return s;
        }
        return "";  
    }
};


