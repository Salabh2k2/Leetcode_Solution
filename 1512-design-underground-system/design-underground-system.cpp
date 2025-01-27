class UndergroundSystem {
public:
    map<int,pair<int, string>>mp;
    map<pair<string,string>, vector<int>>time;
    UndergroundSystem() {
        mp.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id] = {t, stationName};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<int, string>p = mp[id];
        mp.erase(id);
        time[{p.second, stationName}].push_back(t-p.first);
    }
    
    double getAverageTime(string startStation, string endStation) {
        vector<int>tim = time[{startStation, endStation}];
        double avg = 0;
        double sum = 0;
        int n = tim.size();
        sum = accumulate(tim.begin(),tim.end(),0);
        avg = static_cast<double>(sum)/n;
        return avg;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */