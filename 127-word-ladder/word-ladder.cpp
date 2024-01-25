class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.size();
        int N = wordList.size();
        unordered_set<string>mp(wordList.begin(),wordList.end());
        mp.erase(beginWord);
        if(mp.find(endWord)==mp.end())
        {
            return 0;
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty())
        {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word==endWord) return step;
            for(int i = 0;i<word.size();i++)
            {
                char c = word[i];
                for(int j = 'a';j<='z';j++)
                {
                    word[i] = j;
                    if(mp.find(word)!=mp.end())
                    {
                        mp.erase(word);
                        q.push({word,step+1});
                    }
                }
               word[i] = c;
            }
        }
        return 0;
    }
};