#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>

const int MAXN = 1e6 + 6;

using namespace std;

int nr_books;
int nr_lib;
int days,cost[MAXN];/// cartile sunt de la 0

//ifstream in("b_read_on.txt");
ifstream in("a_example.txt");
ofstream out("output.txt");

struct lib{
    int carti_zi,n,proces;
    vector<int>carti;
};
bool cmp(pair<lib,int> a,pair<lib,int> b){
    if(a.first.carti_zi > b.first.carti_zi)
        return true;
    return false;
}
bool cmp_carti(int a,int b){
    if(cost[a] > cost[b])
        return true;
    return false;
}
vector<pair<lib,int>>libs;


void citire(){
    in>>nr_books>>nr_lib>>days;
    for(int i = 0; i < nr_books; i++)
        in>>cost[i];
    for(int i = 0; i < nr_lib; i++){
        lib a;
        in>>a.n>>a.proces>>a.carti_zi;

        for(int j = 0; j < a.n; j++){
            int carte;
            in>>carte;
            a.carti.push_back(carte);
        }
        libs.push_back({a,i});
    }
}
void solve(){
    sort(libs.begin(),libs.end(),cmp);
    for(int i = 0; i < libs.size(); i++){
        sort(libs[i].first.carti.begin(),libs[i].first.carti.end(),cmp_carti);
    }
    out<<libs.size()<<"\n";
    for(int i = 0; i < libs.size(); i++){
        out<<libs[i].second<<" "<<libs[i].first.carti.size()<<"\n";
        vector<int>v = libs[i].first.carti;
        for(auto carte : v)
            out<<carte<<" ";
        out<<"\n";

    }
}


int main()
{
    citire();
    solve();
    return 0;
}
