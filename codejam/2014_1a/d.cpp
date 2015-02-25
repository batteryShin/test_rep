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

#define CODE_DEBUG 1
#if CODE_DEBUG
#define LOGD(str) do { std::cout << "+++++ " << str << std::endl; } while( false )
#define LOGD_INL(str) do{ std::cout << str; } while( false )
#else
#define LOGD(str) do { } while ( false )
#define LOGD_INL(str) do { } while ( false )
#endif

using namespace std;

bool weight_cmp_asc(const double &lhs, const double &rhs) {
    return (lhs<rhs);
}
bool weight_cmp_desc(const double &lhs, const double &rhs) {
    return (lhs>rhs);
}

void shift_mass_to_back(vector<double>& arr, int p) {
    double val=0;

    vector<double>::iterator iter;
    iter = arr.begin()+p;

    val = *iter;
    arr.erase(iter);
    arr.push_back(val);
}


int main()
{
    int tcases;
    int n, y, z;

    vector<double> naomi;
    vector<double> ken;

    double mass;
    double ken_heavist;

    cin >> tcases;
    cin.ignore();
    for(int t=1; t<=tcases; t++) {
        cin >> n;
        cin.ignore();

        for(int i=0; i<n; i++) {
            cin >> mass;
            naomi.push_back(mass);
        }
        cin.ignore();
        for(int i=0; i<n; i++) {
            cin >> mass;
            ken.push_back(mass);
        }

        sort( ken.begin(), ken.end(), weight_cmp_desc );
        sort( naomi.begin(), naomi.end(), weight_cmp_desc );

        y = 0;
        // TODO : move naomi's mass...to maximize
/*        
        for(int i=0; i<n; i++) {
            if( naomi[i]>ken[i] ) {
                y = n-i;
                break;
            }
        }
*/
        sort( ken.begin(), ken.end(), weight_cmp_asc );

        z = 0;
        for(int i=0; i<n; i++) {
            if( naomi[i]>ken[i] ) {
                if( naomi[i]>*max_element(ken.begin()+i,ken.end()) ) {
                    z = n-i;
                    break;
                } else {
                    while( naomi[i]>ken[i] ) {
                        shift_mass_to_back(ken,i);
                        cout << "[debug] naomi = ";
                        for(int r=0; r<n; r++) {
                            cout << " " << naomi[r];
                        }
                        cout << endl;
                        cout << "[debug] ken = ";
                        for(int r=0; r<n; r++) {
                            cout << " " << ken[r];
                        }
                        cout << endl << endl;
                    }
                }
            }
        }

        cout << "Case #" << t << ": " << y << " " << z << endl;

        naomi.clear();
        ken.clear();
    }
}

