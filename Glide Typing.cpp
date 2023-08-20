BNY Mellon - Glide Typing

#define ll long 

string getValidWord(string &s,vector<string> &dictionary){
    int n=dictionary.size();
    sort(dictionary.begin(),dictionary.end());
    string ans;
    for(auto &it : dictionary){
        int i=0,j=0;
        while(i<it.size() && j<s.size()){
            if(it[i]==s[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }
        if(i==it.size()){
            if(ans.empty())ans=it;
            else ans=min(ans,it);
        }
    }
    string nans="-1";
    if(ans.empty())return nans;
    else return ans;
}
