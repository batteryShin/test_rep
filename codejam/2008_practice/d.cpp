#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iomanip>

#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <cfloat>

#include <assert.h>
#include <unistd.h>

#define CODE_DEBUG 0
#if CODE_DEBUG
#define LOGD(str) do { std::cout << "+++++ " << str << std::endl; } while( false )
#define LOGD_INL(str) do{ std::cout << str; } while( false )
#else
#define LOGD(str) do { } while ( false )
#define LOGD_INL(str) do { } while ( false )
#endif

using namespace std;

struct Shop {
    pair<int,int> pos;
    vector< pair<string,int> > s_items;
    int rep;
    bool perishable;
};

bool cmp_asc(const Shop& ref, const Shop& cmp) { return (ref.rep < cmp.rep); }
bool cmp_desc(const Shop& ref, const Shop& cmp) { return (ref.rep > cmp.rep); }

void get_separated_line(istream &is, char *sep, vector<string> &v) {
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
}


int get_reps(vector<string> &list, string item) {
    int res = 0;

    for(int i=0; i<list.size(); i++) {
        if( !strcmp(list.at(i).c_str(),item.c_str()) ) {
            res = pow(2,i);
            break;
        }
    }

    return res;
}

bool get_perishable(int rep, vector<int> &pa_items) {
    bool res = false;

    for(int i=0; i<pa_items.size(); i++) {
        if(rep & (int)pow(2,pa_items.at(i))) {
            res = true;
            break;
        }
    }

    return res;
}

int get_itemcost(vector<Shop> &shops, int nshop, vector<string> &list, int nitem) {
    int res = 0;
    for(int i=0; i<shops.at(nshop).s_items.size(); i++) {
        if( !strcmp(shops.at(nshop).s_items.at(i).first.c_str(),list.at(nitem).c_str()) ) {
            res = shops.at(nshop).s_items.at(i).second;
            break;
        }
    }

    return res;
};

double get_dist(vector<Shop> &shops, int from, int to) {
    double res = 0.;
    if( from==to )  return 0.;
    if( from==-1 ) {
        res = sqrt( pow(shops.at(to).pos.first,2)+pow(shops.at(to).pos.second,2) );
    } else if(to==-1) {
        res = sqrt( pow(shops.at(from).pos.first,2)+pow(shops.at(from).pos.second,2) );
    } else {
        res = sqrt( pow(shops.at(from).pos.first-shops.at(to).pos.first,2) +
                    pow(shops.at(from).pos.second-shops.at(to).pos.second,2) );
    }

    return res;
};

void sort_by_dist(vector<Shop> &shops, vector<int> &v) {
    vector<int> vout;
    vector<int>::iterator it;
    int p = -1;
    int min_p = -1;
    double d = 0;
    double min_d = DBL_MAX;

    if( !v.empty() ) {
        it = v.begin();
    }
    while( !v.empty() ) {
        if( it==v.end() ) {
            it = v.begin();
        }

        min_d = DBL_MAX;
        for(int i=0; i<v.size(); i++) {
            if( (d=get_dist(shops,p,v.at(i))<=min_d) ) {
                min_p = i;
                min_d = d;
            }
        }

        p = min_p;
        vout.push_back(v.at(p));
        v.erase(v.begin()+p);
    }

    while( !vout.empty() ) {
        it = v.begin();
        v.insert( it, vout.back() );
        vout.pop_back();
    }
};

double dist_sum_aligned(vector<Shop> &shops, int *where, int ssize) {
    // voting for shops
    map<int,int> votes;
    pair<map<int,int>::iterator,bool> r;
    map<int,int>::iterator it;
    map<int,int>::iterator itt;

    for(int i=0; i<ssize; i++) {
        r = votes.insert( pair<int,int>(where[i],1) );
        if( r.second==false ) {
            r.first->second++;
        }
    }

    for(it=votes.begin();it!=votes.end();it++) {
        LOGD("votes = " << it->first << "," << it->second);
    }

    // make clustering structure for voting output
    vector< pair<int,vector<int> > > clus;
    vector<int> clus_elem;
    for(it=votes.begin();it!=votes.end();) {
        if( shops.at(it->first).perishable ) {
            clus.push_back( pair< int,vector<int> >(it->first,clus_elem) );
            itt = it;
            itt++;
            votes.erase(it);
            it = itt;
        } else {
            it++;
        }
    }
    LOGD("cluster number = " << clus.size());

    // clustering...
    int p = -1;
    int min_c = -1;
    int min_p = -1;
    double d = 0;
    double min_d = DBL_MAX;

    if( !votes.empty() ) {
        it = votes.begin();
    }

    if( clus.size()==0 ) {
        clus.push_back( pair< int,vector<int> >(-1,clus_elem) );
        for(it=votes.begin();it!=votes.end();) {
            clus.at(0).second.push_back( it->first );
            itt = it;
            itt++;
            votes.erase(it);
            it = itt;
        }
    } else if( clus.size()==1 ) {
        for(it=votes.begin();it!=votes.end();) {
            clus.at(0).second.push_back( it->first );
            itt = it;
            itt++;
            votes.erase(it);
            it = itt;
        }
    } else {
        for(it=votes.begin();it!=votes.end();) {
            min_c = min_p = -1;
            min_d = DBL_MAX;
            for(int j=0; j<clus.size(); j++) {
                d = get_dist(shops, it->first, clus.at(j).first);
                if( d<=min_d ) {
                    min_p = it->first;
                    min_c = j;
                    min_d = d;
                }
            }
            clus.at(min_c).second.push_back(min_p);
            itt = it;
            itt++;
            votes.erase(it);
            it = itt;
        }
    }

    for(int i=0; i<clus.size(); i++) {
        LOGD_INL("+++++ clusters[" << i << "] = " << clus.at(i).first << "( ");
        for(int j=0; j<clus.at(i).second.size(); j++) {
            LOGD_INL(clus.at(i).second.at(j) << " ");
        }
        LOGD_INL(")" << endl);
    }

    // sort by distance for each inner cluster
    for(int i=0; i<clus.size(); i++) {
        sort_by_dist(shops, clus.at(i).second);
    }

    for(int i=0; i<clus.size(); i++) {
        LOGD_INL("+++++ sorted clusters[" << i << "] = " << clus.at(i).first << "( ");
        for(int j=0; j<clus.at(i).second.size(); j++) {
            LOGD_INL(clus.at(i).second.at(j) << " ");
        }
        LOGD_INL(")" << endl);
    }


    // compute aligned distance
    double res = 0;
    for(int i=0; i<clus.size(); i++) {
        p = -1;
        for(int j=0; j<clus.at(i).second.size(); j++) {
            res += get_dist(shops, p, clus.at(i).second.at(j));
            p = clus.at(i).second.at(j);
        }
        clus.at(i).second.clear();

        res += get_dist(shops, p, clus.at(i).first);
        res += get_dist(shops, clus.at(i).first, -1);
    }
    clus.clear();

    





/*
    bool psb_flag = false;
    while( !votes.empty() ) {
        if( it==votes.end() ) {
            it = votes.begin();
        }

        if( !psb_flag ) {
            for(it=votes.begin(); it!=votes.end(); it++) {
                if( !shops.at(it->first).perishable &&
                    (d=get_dist(shops,p,it->first))<=min_d ) {
                    min_p = it->first;
                    min_d = d;
                }
            }

            if( min_p==-1 ) {
                psb_flag = true;
            }
        } 
        
        // remainning shops are only for selling perishable items...
        if( psb_flag ) {
            for(it=votes.begin(); it!=votes.end(); it++) {
                if( shops.at(it->first).perishable &&
                    (d=get_dist(shops, p, it->first))<=min_d ) {
                    min_p = it->first;
                    min_d = d;
                }
            }
        }

        p = min_p;
        res += min_d;
        if( psb_flag ) {
            res += get_dist(shops,p,-1);
            p = -1;
        }

        votes.erase( min_p );
        LOGD("min_p = " << min_p << " votes size = " << votes.size());
        if( votes.empty() && !psb_flag ) {
            res += get_dist(shops,p,-1);
            break;
        }

        min_p = -1;
        min_d = DBL_MAX;
    }
*/
    LOGD("dist_ormal+dist_perishable = " << res);

    return res;
};

int main()
{
//    freopen("D-small-practice.in", "rt", stdin);

    int tcases;
    cin >> tcases;
    cin.ignore();

    int nitems, nstores, pgas;

    vector<Shop> shops;
    vector<string> slist;
    vector<int> perishable;

    for(int t=1; t<=tcases; t++) {
        cin >> nitems >> nstores >> pgas;
        cin.ignore();

        get_separated_line(cin, " \r\n\0", slist);

        LOGD_INL("shopping lists are -> ");
        int found;
        for(int i=0; i<slist.size(); i++) {
            found = slist.at(i).rfind('!');
            if( found!=string::npos ) {
                perishable.push_back(i);
                LOGD_INL("<" << found << ">");
                slist.at(i).erase(found,1);
            }
            LOGD_INL(slist.at(i));
            LOGD_INL("(" << slist.at(i)[slist.at(i).length()-1] << ") ");
        }
        LOGD_INL(endl);

        Shop shop;
        vector<string> shop_elem;
        pair<string,int> shop_item;
        for(int i=0; i<nstores; i++) {
            get_separated_line(cin, " :\r\n\0", shop_elem);
            shop.pos.first = (int)( strtol(shop_elem.front().c_str(),NULL,10) );
            shop_elem.erase(shop_elem.begin());
            shop.pos.second = (int)( strtol(shop_elem.front().c_str(), NULL, 10) );
            shop_elem.erase(shop_elem.begin());


            shop.rep = 0;
            while( !shop_elem.empty() ) {
                shop_item.first = shop_elem.front().c_str();
                shop.rep |= get_reps(slist,shop_item.first);
                shop.perishable = get_perishable(shop.rep, perishable);
                shop_elem.erase(shop_elem.begin());
                shop_item.second = (int)( strtol(shop_elem.front().c_str(), NULL, 10) );
                shop_elem.erase(shop_elem.begin());

                shop.s_items.push_back(shop_item);
                LOGD(shop.s_items.back().first << ":" << shop.s_items.back().second);
            }

            LOGD("shop #" << i << " pos=(" << shop.pos.first << "," << shop.pos.second << ") rep=" << shop.rep << " perishable=" << shop.perishable);
            shops.push_back(shop);

            // clear memory
            shop.s_items.clear();
            shop_elem.clear();
        }

        // Test each of possible "where[p]" cases to find the minimum W.
        sort(shops.begin(), shops.end(), cmp_desc);

        double min_cost = DBL_MAX;
        double cost_sum = 0;
        bool next_flag;
        int where[15];
        int prev[15];
        int pshop = -1;
        bool first_ref = true;

        memset(where, -1, sizeof(int)*15);
        memset(prev, -1, sizeof(int)*15);

        while( true ) {
            if( first_ref ) {
                // assign values for the 1st time...
                for(int m=0; m<slist.size(); m++) {
                    for(int n=0; n<shops.size(); n++) {
                        LOGD( "compare rep -> " << shops.at(n).rep << " & " << get_reps(slist, slist.at(m)) << " = " << (int)(shops.at(n).rep & get_reps(slist, slist.at(m))) );
                        if( shops.at(n).rep & get_reps(slist, slist.at(m)) ) {
                            where[m] = n;
                            prev[m] = n;
                            break;      // jump to check next unassigned prev[]
                        }
                    }
                }
                first_ref = false;

            } else {
                for(int m=slist.size()-1; m>=0; m--) {
                    where[m] = -1;
                    for(int n=prev[m]+1; n<shops.size(); n++) {
                        LOGD( "compare rep -> " << shops.at(n).rep << " & " << get_reps(slist, slist.at(m)) << " = " << (int)(shops.at(n).rep & get_reps(slist, slist.at(m))) );
                        if( shops.at(n).rep & get_reps(slist,slist.at(m)) ) {
                            where[m] = n;
                            prev[m] = n;
                            m = -1;    // jump to loop out
                            break;     // jump to loop out
                        }
                    }

                    if(where[m]==-1) {
                        prev[m] = -1;
                    }
                }

                if( where[0]>=0 ) {
                    for(int m=1; m<slist.size(); m++) {
                        if( where[m]>=0 ) continue;
                        for(int n=0; n<shops.size(); n++) {
                            if( shops.at(n).rep & get_reps(slist, slist.at(m)) ) {
                                where[m] = n;
                                prev[m] = n;
                                break;      // jump to check next unassigned prev[]
                            }
                        }
                    }
                }

            }
            // the condition of escape the loop...
            // check all the possible choosement
            if( where[0]==-1 ) {
                break;
            }

            cost_sum = dist_sum_aligned(shops,where,slist.size()) * pgas;
            LOGD("costs of gas = " << cost_sum);

            pshop = -1;
            next_flag = false;
            for(int m=0; m<slist.size(); m++) {
                cost_sum += get_itemcost(shops,where[m],slist,m);
                LOGD("min_cost = " << std::scientific << min_cost << ", cost_sum = " << cost_sum);
                if( cost_sum >= min_cost ) {
                    next_flag = true;
                    break;
                }
                pshop = where[m];
            }

            if( next_flag ) {
                continue;
            } else {
                min_cost = cost_sum; 
            }
        }

        // clear memory
        shops.clear();
        slist.clear();
        perishable.clear();

        cout << "Case #" << t << ": " << std::fixed << setprecision(7) << min_cost << endl; 
    }

//    fclose(stdin);
}
