class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size(),ans = INT_MIN;
        unordered_set<int>st;
        vector<vector<int>>freq(n,vector<int>(5,0));
        for(int i=0;i<n;i++){
            if(i)freq[i] = freq[i-1];
            freq[i][s[i]-'0']++;
        }
        for(auto &i:s){
            st.insert(i-'0');
        }
        for(int a=0;a<=4;a++){  
            if(st.find(a)==st.end())continue;
            for(int b=0;b<=4;b++){
                if(st.find(b)==st.end())continue;
                if(a==b)continue;
                map<pair<int,int>,vector<pair<int,int>>>mp; 
                int odd = 0,even = 0;
                for(int i=0;i<n;i++){
                    char c = s[i]-'0';
                    if(c==a)odd++;
                    else if(c==b)even++; 
                    if(odd&1 && even%2==0 && i+1>=k && even>0){   
                        ans = max(ans,odd-even);
                    }  
                        pair<int,int>x = {odd%2==0?1:0,even%2==0?0:1};
                        if(mp.find(x)!=mp.end() && !mp[x].empty()){ 
                            auto it = upper_bound(mp[x].begin(),mp[x].end(),make_pair(i-k+1,INT_MIN));
                            if(it!=mp[x].begin()){ 
                                it--; 
                                int start = 0,end = it-mp[x].begin(),localAns = INT_MAX;
                                while(start<=end){
                                    int mid = (start+(end-start)/2);
                                    int index = mp[x][mid].first,value = mp[x][mid].second;
                                    if(freq[i][b]!=freq[index][b]){
                                        localAns = value;
                                        start = mid+1;
                                    }
                                    else end = mid-1;
                                }
                                if(localAns!=INT_MAX){
                                    ans = max(ans,odd-even-localAns);
                                }
                            }
                        } 
                    x = {odd%2,even%2};
                    if(mp.find(x)==mp.end()){
                        mp[x].push_back({i,odd-even});
                    }
                    else{
                        int prev = mp[x].back().second;
                        mp[x].push_back({i,min(prev,odd-even)});
                    }
                } 
            }
        }
        return ans;
    }
};