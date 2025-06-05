class Solution {
public:
    array<vector<int>, 26> adj;
    int root[26];
    bitset<26> viz=0;
    int dfs(int i, vector<int>& component){
        viz[i]=1;
        int ans=root[i];
        component.push_back(i);
        for(int j:adj[i]){
            if (viz[j]) continue;
            ans=min(ans, dfs(j, component));
        }
        return ans;
    }
    string smallestEquivalentString(string& s1, string& s2, string baseStr) {
        iota(root, root+26, 0);
        const int n=s1.size(), m=baseStr.size();
        for(int i=0; i<n; i++){
            const int u=s1[i]-'a', v=s2[i]-'a';
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0; i<26; i++){
            if (viz[i]) continue;
            vector<int> component;
            int x=dfs(i, component);
            for(int j: component) root[j]=x;
        }
        string ans(m, ' ');
        for(int i=0; i<m; i++)
            ans[i]='a'+root[baseStr[i]-'a'];
        return ans;
    }
};