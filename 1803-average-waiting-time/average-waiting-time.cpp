class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double ans;
        double sum = 0;
        int currtime = customers[0][0]+customers[0][1];
        sum+=currtime-customers[0][0];
        cout<<sum<<endl;
        for(int i = 1;i<n;i++)
        {
            int time = max(customers[i][0], currtime);
            int taken = time+customers[i][1];
            int wait = taken-customers[i][0];
            sum+=wait;
            currtime = taken;
            cout<<wait<<endl;
        }
        return (double)(sum/n);
    }
};