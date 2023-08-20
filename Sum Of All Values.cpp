BNY Mellon  - Sum Of All Values

#define ll long 

ll ans=0;
const int MOD=1e9+7;
set<vector<string>> st;
void f(string &num,int index,vector<string>& ds){
    if (index==num.size()) {
        string make;
        for(auto &it : ds)make+=it;
        if(make!=num)return;
        if(st.count(ds))return;
        st.insert(ds);
        for(auto &it : ds){
            // cout<<it<<" ";
            ans+=stoi(it);
            ans%=MOD;
        }
        // cout<<endl;
        return;
    }
    for (int i = 0; i < ds.size(); i++) {
        ds[i].push_back(num[index]);
        f(num, index + 1, ds);
        ds[i].pop_back();
    }
    ds.push_back({ num[index] });
    f(num, index + 1, ds);
    ds.pop_back();
}
int getExpressionSums(string &num){
    vector<string> ds;
    f(num,0,ds);
    return ans%MOD;
}
