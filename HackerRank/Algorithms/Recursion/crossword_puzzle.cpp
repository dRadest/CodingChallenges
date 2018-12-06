#include <bits/stdc++.h>

using namespace std;

// Complete the crosswordPuzzle function below.
bool check(vector<string> &cc,const  string &s,int pos){
    bool br = (pos&1);
    pos/=2;
    int y = pos%100,x = pos/100;
    for(int c:s){
        if(cc[x][y]=='-') 
            cc[x][y] = c;
        else if(cc[x][y]!=c) 
            return false;
        if(br) x++;
        else y++;
    }    
    return true;
}

bool dfs(vector<string> cw,const vector<pair<int,int>> &vp,int curvp, unordered_map<int,vector<string>>& ump, unordered_map<int,vector<int>> &umpp,vector<string> &res,int x ){
    if(x == vp[curvp].first){
        x=0;
        if(++curvp==vp.size()){
            res = cw;
            return true;
        }
    }
    int n = vp[curvp].second;
    const string &ss = ump[n][x];
    auto &arr = umpp[n];
    for(int y:arr){
        vector<string> cc = cw;
        if(check(cc,ss,y)&&(dfs(cc,vp,curvp,ump,umpp,res,x+1)))
            return true;
    }
    return false;
}

vector<string> crosswordPuzzle(vector<string> crossword, string words) {
    unordered_map<int,vector<string>>ump;
    int n = words.size();
    int priv = 0;
    for(int i = 0; i <= n; i++){
        if(i == n || words[i]==';'){
            ump[i-priv].push_back(words.substr(priv,i-priv));
            priv = i+1;
        }
    }
    vector<pair<int,int>>vp;
    for(auto i:ump)
        vp.push_back({i.second.size(),i.first});
    auto com = [](pair<int,int>&a, pair<int, int> &b){
        if(a.first==b.first) return a.second<b.second;
        return  a.first<b.first;
    };
    sort(vp.begin(),vp.end(),com);
    int rc = 0,cc=0,rp,cp;
    unordered_map<int,vector<int>> umpp;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j <= 10; j++){
            if(j<10 && crossword[i][j]=='-'){
                if(rc++ == 0) rp = (i*100+j)*2;
            }else{
                if(rc>0) umpp[rc].push_back(rp);
                rc = 0;
            }
            if(j<10 && crossword[j][i]=='-'){
                if(cc++ == 0) cp = (j*100+i)*2+1;
            }else{
                if(cc>0) umpp[cc].push_back(cp);
                cc = 0;
            }
        }
    }
    vector<string> res=crossword;
    if(vp.size() > 0) dfs(crossword,vp,0,ump,umpp,res,0);
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<string> crossword(10);

    for (int i = 0; i < 10; i++) {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }

    string words;
    getline(cin, words);

    vector<string> result = crosswordPuzzle(crossword, words);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
