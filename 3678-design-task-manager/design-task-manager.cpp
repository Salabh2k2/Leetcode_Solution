class TaskManager {
public:
    unordered_map<int,pair<int,int>>mp;
    set<pair<int,int>,greater<pair<int,int>>>st;

    TaskManager(vector<vector<int>>& tasks) {
        for(auto& it:tasks){
            mp[it[1]]={it[0],it[2]};//taskId->{userId,priority}
            st.insert({it[2],it[1]});//{priority,taskId}
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId]={userId,priority};
        st.insert({priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        pair<int,int>element={mp[taskId].second,taskId};
        pair<int,int>newElement={newPriority,taskId};

        auto it=st.find(element);
        st.erase(it);
        st.insert(newElement);

        mp[taskId].second=newPriority;
    }
    
    void rmv(int taskId) {
        pair<int,int>element={mp[taskId].second,taskId};
        auto it=st.find(element);
        st.erase(it);

        mp.erase(taskId);
    }
    
    int execTop() {
        auto firstElement = *st.begin();
        int taskId=firstElement.second;
        
        if(mp.find(taskId)!=mp.end()){
            int ansUserId=mp[taskId].first;
            rmv(taskId);
            return ansUserId;
        }
        else return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */