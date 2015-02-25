#include <cstdlib>
#include <cstdio>
#include <iostream>

#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits>
#include <math.h>

#include <assert.h>
#include <unistd.h>

#define CODE_DEBUG 0

typedef unsigned long long int ULINT;

using namespace std;

struct Process {
    string name;
    int stime;
    int etime;
    float cpu_use;
    float proc_use;
    float percent;
};

bool cmp_process(const Process &ref, const Process &cmp) {
    bool res;
    if(ref.percent==cmp.percent) {
        res = (strcmp(ref.name, cmp.name)>0);
    } else {
        res = (ref.percent > cmp.percent);
    }
    
    return res;
}

int get_separated_line(istream &is, char *sep, vector<string> &v) {
    string str;
    char *w, *pw;
    int n_w = 0;

    getline(is, str);

    w = new char[str.size()+1];
    strcpy(w, str.c_str());

    pw = strtok(w, sep);
    while(pw!=NULL) {
        v.push_back( string(pw) );
        pw = strtok(NULL, sep);
        n_w++;
    }

    delete [] w;

    return n_w;
}

int main()
{
    int *chk_times;
    int chk_size;
    vector<Process> p;
    Process p_elem;

    vector<string> vstr;
    vector<string>::iterator it;

    get_separated_line(cin,csep,vstr);
    chk_size = vstr.size(); 
    chk_times = new int[chk_size];

    for(int i=0; i<vstr.size(); i++) {
        chk_times[i] = strtol(vstr.at(i).c_str(),NULL,10);
    }
    vstr.clear();

    do {
        cin >> p_elem.name >> p_elem.stime >> p_elem.etime >> p_elem.cpu_use;
        p.push_back(p_elem);
    } while( getchar()!="\0" ) {

    int total_use = 0;
    for(int i=0; i<p.size(); i++) {
        p.at(i).proc_use = p.at(i).cpu_use / (p.at(i).etime-p.at(i).stime);
        total_use += p.at(i).proc_use;
    }

    for(int i=0; i<p.size(); i++) {
        p.at(i).percent = p.at(i).proc_use / total_use;
    }

    sort(p.begin(), p.end(), cmp_process);

    for(int i=0; i<chk_size; i++) {
        cout << chk_times[i] << endl;
        for(int j=0; j<p.size(); j++) {
            cout << p.at(j).name << p.at(j).percent*100 << endl;
        }
        cout << endl;
    }
    
    return 0;
}


