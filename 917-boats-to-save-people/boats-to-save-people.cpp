class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int ans = 0;
        sort(people.begin(), people.end());
        auto it = lower_bound(people.begin(),people.end(),limit)-people.begin();
        cout<<"it: "<<it<<endl;
        if(it<n)
        {
            ans+=(n-1)-it+1;
        }
        cout<<"ans: "<<ans<<endl;
        int left = 0;
        int right = it-1;
        while(left<=right)
        {
            cout<<"left: "<<left<<" right: "<<right<<endl;
            if(left==right)
            {
                ans++;
                break;
            }
            if(people[left]+people[right]<=limit)
            {
                ans++;
                left++;
                right--;
            }
            else{
                ans+=1;
                right--;
            }
        }
        return ans;
    }
};