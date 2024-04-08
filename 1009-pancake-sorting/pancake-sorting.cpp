class Solution {
public:
    void flip(vector<int> &arr, int j){
        int i=0;
        while(i<=j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int n=arr.size();
        for(int i=n-1;i>0;i--){
            for(int j=0;j<=i;j++){
                if(arr[j]==i+1){
                    flip(arr,j);
                    ans.push_back(j+1);
                    break;
                }
            }
            flip(arr,i);
            ans.push_back(i+1);
        }
        return ans;
    }
};