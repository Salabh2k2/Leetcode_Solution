class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
       int n = deck.size();
        vector<int>result(n);
        deque<int>indices;
        for(int i = 0;i<n;i++)
        {
            indices.push_back(i);
        }

        for(auto it: deck)
        {
            int ind = indices.front();
            indices.pop_front();
            result[ind] = it;
            if(!indices.empty()){
                int k = indices.front();
                indices.pop_front();
                indices.push_back(k);
            }
        }
        return result;

    }
};