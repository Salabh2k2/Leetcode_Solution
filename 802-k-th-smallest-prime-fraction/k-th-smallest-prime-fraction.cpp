class Solution {
public:
    struct ComparePairs {
        bool operator()(const pair<double, pair<int, int>>& p1, const pair<double, pair<int, int>>& p2) {
            return p1.first > p2.first; 
        }
    };
    
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<int> ans(2);
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, ComparePairs> pq;
        int n = arr.size();
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) { 
                double fraction = static_cast<double>(arr[i]) / arr[j]; 
                pq.push({fraction, {arr[i], arr[j]}}); 
            }
        }
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        
        ans[0] = pq.top().second.first;
        ans[1] = pq.top().second.second;
        
        return ans;
    }
};
