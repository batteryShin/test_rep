#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

void print_states(string& w_str, int p, vector<string>& candidates, vector< vector<int> >& states) {
    char pp[100] = {0,};
    cout << "\n" << w_str[p] << "(" << p << ")\n";
    for(int i=0; i<states.size(); i++) {
        memset(pp, 0, sizeof(pp)); 
        cout << candidates[i] << " = " << states[i][0];
        pp[ states[i][0] ] = true;
        for(int j=1; j<states[i].size(); j++) {
            cout << ", " << states[i][j];
            pp[ states[i][j] ] = 1;
        }
        cout << "\n";
        for(int j=0; j<candidates[i].size(); j++) {
            if( pp[j]==1 ) {
                cout << "|";
            } else {
                cout << " ";
            }
        }
        cout << "\n";
    }
    
    cout << "\n";
}

bool cmp_string(const string& ref, const string& cmp) {
    int p = 0;
    char lc = ref[p];
    char rc = cmp[p];

    while(lc==rc) {
        p++;
        lc = ref[p];
        rc = cmp[p];
    }

    return (lc<rc);
}

void search(string& w_str, vector<string>& candidates, vector< vector<int> >& states) {
    int p = 0;
    bool reoccurs = false;
    vector<int> v;

    // initial search
    if( w_str[p]=='*' ) {
        for(int i=0; i<candidates.size(); i++) {
            for(int j=0; j<candidates[i].size(); j++) {
                v.push_back(j);
            }
            states.push_back( v );
            v.clear();
        }
        reoccurs = true;
    } else if( w_str[p]=='?' ) {
        for(int i=0; i<candidates.size(); i++) {
            for(int j=1; j<candidates[i].size(); j++) {
                v.push_back(j);
            }
            states.push_back( v );
            v.clear();
        }
    } else {
        for(int i=0; i<candidates.size(); i++) {
            if( candidates[i][0]==w_str[p] ) {
                v.push_back(1);
            } else {
                v.push_back(candidates[i].size()+1);
            }

            states.push_back( v );
            v.clear();
        }
    }

//    print_states(w_str, p, candidates, states);

    // intermediate search
    p++;
    vector<int> tmp;
    vector<int>::iterator it;
    while( p<w_str.size() ) {
        if( w_str[p]=='*' ) {
            reoccurs = true;
        } else if( w_str[p]=='?' ) {
            for(int i=0; i<candidates.size(); i++) {
                for(int j=0; j<states[i].size(); j++) {
                    if( reoccurs ) {
                        for(int k=states[i][j]; k<candidates[i].size(); k++) {
                            tmp.push_back(k+1);
                        }
                    } else {
                        if( states[i][j]+1 <= candidates[i].size() ) {
                            tmp.push_back(states[i][j]+1);
                        }
                    }
                }

                if( tmp.empty() ) {
                    tmp.push_back(candidates[i].size()+1);
                }
                states[i].swap( tmp );
                tmp.clear();
            }
            reoccurs = false;
        } else {
            for(int i=0; i<candidates.size(); i++) {
                for(int j=0; j<states[i].size(); j++) {
                    if( reoccurs ) {
                        for(int k=states[i][j]; k<candidates[i].size(); k++) {
                            if( candidates[i][k]==w_str[p] ) {
                                tmp.push_back(k+1);
                            }
                        }
                    } else {
                        if( candidates[ i ][ states[i][j] ]==w_str[p] ) {
                            tmp.push_back(states[i][j]+1);
                        }
                    }
                }

                if( tmp.empty() ) {
                    tmp.push_back(candidates[i].size()+1);
                }
                sort(tmp.begin(), tmp.end());
                it = unique(tmp.begin(), tmp.end());
                tmp.resize( distance(tmp.begin(),it) );
                states[i].swap( tmp );
                tmp.clear();
            }
            reoccurs = false;
        }

//        print_states(w_str, p, candidates, states);
        p++;
    }

    // final correction
    bool flag;
    vector<string> results;
    for(int i=0; i<candidates.size(); i++) {
        flag = false;
        if( w_str[w_str.size()-1]=='*' ) {
            if( states[i][0]!=candidates[i].size()+1 ) {
                flag = true;
            }
        } else {
            flag = false;
            for(int j=0; j<states[i].size(); j++) {
                if( states[i][j]==candidates[i].size() ) {
                    flag = true;
                    break;
                }
            }
        }

        if( flag ) {
            results.push_back(candidates[i]);
        }
    }

    candidates.swap( results );
    results.clear();
    return;
}

int main() {
    string w_str, inp_str;
    int num;
    vector< vector<int> > states;
    vector<string> candidates;
    int tcases;
    cin >> tcases;
    while(tcases-->0) {
        candidates.clear();
        for(int i=0; i<states.size(); i++) {
            states[i].clear();
        }
        states.clear();

        cin >> w_str;
        cin >> num;
        for(int i=0; i<num; i++) {
            cin >> inp_str;
            candidates.push_back(inp_str);
        }

        sort(candidates.begin(), candidates.end(), cmp_string);
        search(w_str, candidates, states);

        for(int i=0; i<candidates.size(); i++) {
            cout << candidates[i] << "\n";
        }
    }
}
