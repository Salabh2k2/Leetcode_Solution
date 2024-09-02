class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        cout<<n<<endl;
        long long sum = 0;
        for(auto it:chalk)
        {
            sum+=it;
        }
        k%=sum;
        cout<<"k "<<k<<endl;
        int i = 0;
        while(k)
        {
            if(chalk[i]>k)
            {
                return i;
            }
            else {k-=chalk[i]; i++;}
        }
        return i;
    }
};