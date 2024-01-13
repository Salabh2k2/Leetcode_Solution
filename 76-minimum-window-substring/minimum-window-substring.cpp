class Solution {
public:
    string minWindow(string s, string t) {
    string final;
    if(t.size()>s.size()){
        return final;
    }
    unordered_map<char, int>list;
    for(auto it: t){
        list[it]++;
    }
    int i=0, j=0, llen=list.size(), slen=s.size()+1;
    while(j<s.size()){
        if(list.find(s[j])!=list.end()){
            list[s[j]]--;
            if(list[s[j]]==0){
                llen--;
            }
        }
        if(llen>0){
            j++;
        }
        else if(llen==0){
            while(list.find(s[i])==list.end() || list[s[i]]<0){
                if(list.find(s[i])!=list.end()){
                    list[s[i]]++;
                }
                i++;
            }
            if(slen>j-i+1){
                slen=j-i+1;
                final=s.substr(i, j-i+1);
            }
            if(list.find(s[i])!=list.end()){
                list[s[i]]++;
                if(list[s[i]]==1){
                    llen++;
                }
            }
            i++;
            j++;
        }
    }
    return final;
}
};