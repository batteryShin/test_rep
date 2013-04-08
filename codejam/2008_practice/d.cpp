#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iomanip>

#include <string>
#include <cstring>
#include <vector>
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
    int perishable;
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

int main()
{
//    freopen("D-small-practice.in", "rt", stdin);

    int tcases;
    cin >> tcases;
    cin.ignore();

    int nitems, nstores, pgas;
    string str;

    vector<Shop> shops;
    vector<string> slist;
    vector<string> shop_elem;

    Shop shop;
    pair<string,int> shop_item;
    string item_name;

    for(int t=1; t<=tcases; t++) {
        cin >> nitems >> nstores >> pgas;
        cin.ignore();

        get_separated_line(cin, " \r\n\0", slist);

        // TODO: consideration of perishable items..
        LOGD_INL("shopping lists are -> ");
        int found;
        for(int i=0; i<slist.size(); i++) {
            found = slist.at(i).rfind('!');
            if( found!=string::npos ) {
                LOGD_INL("<" << found << ">");
                slist.at(i)[found] = '\0';
            }
            LOGD_INL(slist.at(i));
            LOGD_INL("(" << (int)slist.at(i)[slist.at(i).length()-1] << ") ");
        }
        LOGD_INL(endl);

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
                shop_elem.erase(shop_elem.begin());
                shop_item.second = (int)( strtol(shop_elem.front().c_str(), NULL, 10) );
                shop_elem.erase(shop_elem.begin());

                shop.s_items.push_back(shop_item);
                LOGD(shop.s_items.back().first << ":" << shop.s_items.back().second);
            }

            LOGD("shop #" << i << " pos=(" << shop.pos.first << "," << shop.pos.second << ") rep=" << shop.rep);
            shops.push_back(shop);

            // clear memory
            shop.s_items.clear();
            shop_elem.clear();
        }

        // Test each of possible "where[p]" cases to find the minimum W.
        sort(shops.begin(), shops.end(), cmp_desc);

        int proc_cnt = 0;
        int max_proc = 1;
        for(int i=0; i<shops.size(); i++) {
            max_proc *= shops.at(i).s_items.size();
        }

        double min_cost = DBL_MAX;
        double cost_sum = 0;
        bool next_flag;
        int where[15];
        int prev[15];
        int pshop = -1;
        bool first_ref = true;
        int ref_cnt = 0;

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
            if( where[0]==-1 || proc_cnt++ > max_proc ) {
                break;
            }

            pshop = -1;
            cost_sum = 0;
            next_flag = false;
            for(int m=0; m<slist.size(); m++) {
                cost_sum += get_itemcost(shops,where[m],slist,m);
                cost_sum += get_dist(shops,pshop,where[m])*pgas;
                if( cost_sum >= min_cost ) {
                    next_flag = true;
                    break;
                }
                pshop = where[m];
            }

            if( next_flag ) {
                continue;
            } else {
                min_cost = cost_sum + get_dist(shops,pshop,-1)*pgas;
            }
        }

        // clear memory
        shops.clear();
        slist.clear();

        cout << "Case #" << t << ": " << std::fixed << setprecision(7) << min_cost << endl; 
    }

    fclose(stdin);
}
