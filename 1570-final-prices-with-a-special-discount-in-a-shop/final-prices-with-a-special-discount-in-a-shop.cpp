class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            bool flag=false;
            for(int j=i+1;j<n;j++){
                if(prices[j]<=prices[i]){
                    res.push_back(prices[i]-prices[j]);
                    flag=true;
                    break;
                }
            }
            if(!flag)
            res.push_back(prices[i]);
        }
        return res;
    }
};