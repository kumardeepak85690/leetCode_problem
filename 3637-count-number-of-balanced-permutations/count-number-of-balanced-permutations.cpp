constexpr long long mod=1e9+7;

int dp[10][41][361];
static constexpr auto Pascal_triangle() {
    array<array<long long, 41>, 41> a{};
    for (int i=0; i<41; i++) {
        a[i][0]=a[i][i]=1;
        for (int j=1; j<=i/2; j++) {
            long long x=a[i-1][j-1]+a[i-1][j];
            if (x>=mod) x-=mod;
            a[i][j]=a[i][i-j] = x;
        }
    }
    return a;
}

class Solution {
public:
    array<int, 10> freq={0};
    static constexpr auto comb=Pascal_triangle();
    int f(int i, int even, int odd, int remain) {
        if (even==0 && odd==0 && remain==0)
            return 1;
        if (i<0 || even<0 || odd<0 || remain<0)
            return 0;
 
        if (dp[i][odd][remain] != -1)
            return dp[i][odd][remain];

        long long ans = 0;
        int max_j=min(freq[i], odd);
        
        for (int j=0; j<=max_j; j++) {
            int even_rem=freq[i]-j;
            if (even_rem<=even && remain >= i*j) {
                // Additional prune: check if remaining achievable sum is valid
                if (remain-i*j > (odd-j+even-even_rem)*(i-1)) 
                    continue;

                ans=(ans+comb[odd][j]*comb[even][even_rem]%mod*
                       f(i-1, even-even_rem, odd-j, remain-i*j)%mod)%mod;
            }
        }
        return dp[i][odd][remain]=ans;
    }

    int countBalancedPermutations(string& num) {
        const int n=num.size();
        int sum=0, maxD=-1;
        for (char c : num) {
            int x=c-'0';
            maxD=max(x, maxD);
            freq[x]++;
            sum+=x;
        }
        if (sum&1)
            return 0;
        sum/=2;
        int evenLen=n/2, oddLen=n-evenLen;

        memset(dp, -1, sizeof(dp));
        return f(maxD, evenLen, oddLen, sum);
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();