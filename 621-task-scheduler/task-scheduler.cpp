class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};

        for(char c: tasks)
        {
            freq[c-'A']++;
        }
        sort(freq, freq+26);

        int batchcnt = freq[25];
        int slot = (--batchcnt)*n;
        for(int i = 0;i<25;i++)
        {
            slot -= min(freq[i],batchcnt);
        }
        return slot>0 ? tasks.size() + slot : tasks.size();
    }
};