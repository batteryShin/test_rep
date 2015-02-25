#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int tcases;
int n;
int m;
vector<int> nlist;
vector< pair<int,int> > alist;
vector< pair<int,int> > blist;
pair<int,int> p;
int tot_cnt;
int nfound;

inline int factorial(int x) {
      return (x == 1 ? x : x * factorial(x - 1));
}

bool cmp_pair(const pair<int,int>& lhs, const pair<int,int>& rhs) {
    return (lhs.first==rhs.first) ?
                (lhs.second<rhs.second) : (lhs.first<rhs.first);
}

bool cmp_pair2(pair<int,int>& lhs, pair<int,int>& rhs) {
    return (lhs.first==rhs.first && lhs.second==rhs.second);
}

void search_pair(vector<int>& l, int& cnt, int& found) {
    vector< pair<int,int> >::iterator it;
    vector<int>::iterator itn;

    // base condition..
    if( found==0 ) {
        for(int i=0; i<l.size(); i++) {
            itn = l.begin();
            itn += i;
            blist.push_back(pair<int,int>(*itn,-1));
            l.erase(itn);
            found++;

            search_pair(l, cnt, found);

            l.push_back(blist.back().first);
            sort(l.begin(), l.end());
            blist.pop_back();
            found--;
        }

    } else if( found==1 ) {
        itn = find(l.begin(), l.end(), blist.back().first);
//        cout << "founded=" << *itn;
        for(int i=0; i<l.size(); i++) {
            itn = l.begin();
            itn += i;
            it = find(alist.begin(), alist.end(), pair<int,int>(blist.back().first,*itn));


            if( it!=alist.end() ) {
//                cout << " next=" << *itn << " pair=" << (*it).first << "," << (*it).second << endl;
                blist.back().second = *itn;
                l.erase(itn);
                found++;

                search_pair(l, cnt, found);

                l.push_back(blist.back().second);
                sort(l.begin(), l.end());
                blist.back().second = -1;
                found--;
            }
        }

    } else if( found==2 ) {
        if( l.empty() ) {
/*            
            cout << cnt+1 << " output pairs =";
            for(int i=0; i<blist.size(); i++) {
                cout << " " << blist[i].first << "," << blist[i].second;
            }
            cout << endl;
*/            
            cnt++;
            return;
        } else {
            found = 0;
            search_pair(l, cnt, found);
            found = 2;
        }
    }
}


int main() {
    cin >> tcases;
    cin.ignore();
    for(int t=1; t<=tcases; t++) {
        cin >> n >> m;
        cin.ignore();

        nlist.clear();
        for(int i=0; i<n; i++) {
            nlist.push_back(i);
        }

        alist.clear();
        blist.clear();
        for(int i=0; i<m; i++) {
            cin >> p.first >> p.second;
            alist.push_back(p);
        }
        sort(alist.begin(), alist.end(), cmp_pair);

        tot_cnt = nfound = 0;
        search_pair(nlist,tot_cnt,nfound);
        
        tot_cnt /= factorial(n/2);

        cout << /*"Case #" << t << ": " << */tot_cnt << endl;
    }
}
