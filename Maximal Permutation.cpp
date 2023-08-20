BNY Mellon - Maximal Permutation

#define ll long 

void dfs(int node,vector<vector<ll>> &g,vector<bool> &vis,vector<ll> &index,vector<ll> &ds,vector<ll> &container){
    
    vis[node]=1;
    index.push_back(node);
    ds.push_back(container[node]);

    for(auto &it: g[node]){
        if(!vis[it]){
            dfs(it,g,vis,index,ds,container);
        }
    }
}
vector<int> f(vector<int> &container,vector<int> &firstIndex,vector<int> &secondIndex,vector<int> &slides){
    ll n=container.size();
    ll m=firstIndex.size();
    vector<vector<ll>> g(n);
    for(ll i=0;i<m;i++){
        ll l=firstIndex[i]-slides[i];
        l=l+1000000000*n;
        l%=n;
        ll r=secondIndex[i]+slides[i];
        r%=n;
        g[l].push_back(r);
        g[r].push_back(l);
    }
    vector<bool> vis(n);
    vector<int> ans(n);
    for(ll i=0;i<n;i++){
        vector<ll> index;
        vector<ll> ds;
        if(!vis[i]){
            dfs(i,g,vis,index,ds,container);
        }
        if(index.empty())continue;
        sort(index.begin(),index.end());
        sort(ds.begin(),ds.end(),greater<ll>());

        for(ll i=0;i<index.size();i++){
            ans[index[i]]=ds[i];
        }
    }
    return ans;
}
