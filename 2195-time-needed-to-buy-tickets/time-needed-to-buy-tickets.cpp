class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int small = 0;
        int token = tickets[k];

        for(int i = 0;i<n;i++)
        {
            small+=min(tickets[k]-(i>k), tickets[i]);
        }
        return small;
        
    }
};