#include <iostream>
#include <fstream>
#include <vector>

const int MAXN = 1e6 + 6;

using namespace std;

int nr_books;
int nr_lib;
int days,cost[MAXN];/// cartile sunt de la 0

//ifstream in("b_read_on.txt");
ifstream in("a_example.txt");

struct lib{
    int carti_zi,n,proces;
    vector<int>carti;
};
vector<lib>librarys;

void citire(){
    in>>nr_books>>nr_lib>>days;
    for(int i = 0; i < nr_books; i++)
        in>>cost[i];
    librarys.reserve(nr_books);

    for(int i = 0; i < nr_lib; i++){
        lib a;
        in>>a.n>>a.proces>>a.carti_zi;
        a.carti.reserve(a.n);
        for(int j = 0; j < a.n; j++)
            in>>a.carti[j];
        librarys[i] = a;
    }
}


int main()
{
    citire();
    return 0;
}
