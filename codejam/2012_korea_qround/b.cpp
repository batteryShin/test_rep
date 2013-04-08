#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <unistd.h>

#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

#define compute_A(cb,cy,mul,carry)  ((int)((cy)-'0') - (mul)*(int)((cb)-'0') - (carry))
#define compute_B(ca,cy,mul,carry)  ((mul) * ((int)((cy)-'0') - ((int)((ca)-'0')+(carry))))
#define compute_Y(ca,cb,mul,carry)  ((int)((ca)-'0')+(carry) + ((mul)*(int)((cb)-'0')))

void recompute_position(char *str_a, char *str_b, char *str_y, int mul, int *state, int *carry, int pos) {
    char ch[2];
    int res = 0;
    int flag = true;
    while( flag ) {
        flag = false;
        res = (int)(str_a[pos]-'0')+carry[pos] + mul*(int)(str_b[pos]-'0') - (int)(str_y[pos]-'0');

        if( res!=0 ) {
            switch( state[pos] ) {
                case 1:
                    if( res==1 ) {
                        sprintf( ch, "%d", (int)(str_a[pos]-'0')-1 );
                    } else if( res==-1 ) {
                        sprintf( ch, "%d", (int)(str_a[pos]-'0')+1 );
                    }
                    str_a[pos] = ch[0];
                    break;
                case 2:
                    if( res==1 ) {
                        sprintf( ch, "%d", (int)(str_b[pos]-'0')-mul );
                    } else if( res==-1 ) {
                        sprintf( ch, "%d", (int)(str_b[pos]-'0')+mul );
                    }
                    str_b[pos] = ch[0];
                    break;
                case 4:
                    if( res==1 ) {
                        sprintf( ch, "%d", (int)(str_y[pos]-'0')+1 );
                    } else if( res==-1 ) {
                        sprintf( ch, "%d", (int)(str_y[pos]-'0')-1 );
                    }
                    str_y[pos] = ch[0];
                    break;
                default:
//                    flag = true;
//                    printf("other cases are still exist !! \n");
                    break;
            }

        }
    }

    cout << "It could be make an error...Please check it again!!" << endl;
    cout << "State: " << state[pos] << " , " << str_a[pos] << " + " << str_b[pos] << " = " << str_y[pos] << endl;
}

int main()
{
    string str;
    char *w, *pw;
    int xsum, ysum, rsum;
    int mul, slen;

    int n;
    vector<string> vin;
    int arb[5];
    int len_a, len_b, len_op, len_eq, len_y, len_sp;
    char *str_a, *str_b, *str_y;
    char oprnd;
    int *diff, *carry, *state, *_state;
    
    char ch[3] = {0,};

    int biglen=0;

    freopen("B-small-practice.in", "rt", stdin);

    cin >> n;
    cin.ignore();

    for(int i=0; i<n; i++) {
        getline(cin, str);
//        printf("string was extracted - %d bytes\n", str.size());

        w = new char[str.size()+1];
        strcpy(w, str.c_str());

        pw = strtok(w, " ");
        while(pw!=NULL) {
            vin.push_back( string(pw) );
            pw = strtok(NULL, " ");
//            printf("string token - %s\n", vin.back().c_str());
        }

        len_op = len_eq = len_sp = 1;
        len_a = strlen(vin.at(0).c_str());
        len_b = strlen(vin.at(2).c_str());
        len_y = strlen(vin.at(4).c_str());

        biglen = max(len_y,max(len_a,len_b));

        str_a = new char[biglen];
        str_b = new char[biglen];
        str_y = new char[biglen];

        diff = new int[biglen];
        carry = new int[biglen];
        state = new int[biglen];
        _state = new int[biglen];

        memset(diff, 0, sizeof(int)*biglen);
        memset(carry, 0, sizeof(int)*biglen);
        memset(state, 0, sizeof(int)*biglen);

        strcpy( str_a, string(vin.at(0).rbegin(),vin.at(0).rend()).c_str() );
        strcpy( str_b, string(vin.at(2).rbegin(),vin.at(2).rend()).c_str() );
        strcpy( str_y, string(vin.at(4).rbegin(),vin.at(4).rend()).c_str() );
        
        for(int j=0; j<biglen; j++) {
            if( j>=len_a )  str_a[j] = '0';
            if( j>=len_b )  str_b[j] = '0';
            if( j>=len_y )  str_y[j] = '0';

        }

        oprnd = w[len_a+len_sp];
//        printf("string token reversed - %s %s %s\n", str_a, str_b, str_y);

        mul = (oprnd=='+')?1:-1;

        for(int j=biglen-1; j>=0; j--) {
            if(str_a[j]=='?')   state[j]+=1;
            if(str_b[j]=='?')   state[j]+=2;
            if(str_y[j]=='?')   state[j]+=4;
        }

        memcpy(_state, state, sizeof(int)*biglen);

        // first determined calculation from backward
        for(int j=0; j<biglen; j++) {
            switch( state[j] ) {
                case 0:
                    diff[j] = compute_Y(str_a[j],str_b[j],mul,carry[j]);
                    if( diff[j]<0 || diff[j]>9 ) {
                        carry[j+1] = mul;
                    }
                    break;
                case 1:
                    diff[j] = compute_A(str_b[j],str_y[j],mul,carry[j]);
                    if( diff[j]<0 ) {
                        carry[j+1] = mul;
                        sprintf( ch, "%d", diff[j]+10 );
                    } else if( diff[j]>9 ) {
                        carry[j+1] = mul;
                        sprintf( ch, "%d", diff[j]-10 );
                    } else {
                        sprintf( ch, "%d", diff[j] );
                    }
                    str_a[j] = ch[0];
                    state[j] = 0;
                    break;
                case 2:
                    diff[j] = compute_B(str_a[j],str_y[j],mul,carry[j]);
                    if( diff[j]<0 ) {
                        carry[j+1] = mul;
                        sprintf( ch, "%d", diff[j]+10 );
                    } else if( diff[j]>9 ) {
                        carry[j+1] = mul;
                        sprintf( ch, "%d", diff[j]-10 );
                    } else {
                        sprintf( ch, "%d", diff[j] );
                    }
                    str_b[j] = ch[0];
                    state[j] = 0;
                    break;
                case 4:
                    diff[j] = compute_Y(str_a[j],str_b[j],mul,carry[j]);
                    if( diff[j]<0 ) {
                        carry[j+1] = mul;
                        sprintf( ch, "%d", diff[j]+10 );
                    } else if( diff[j]>9 ) {
                        carry[j+1] = mul;
                        sprintf( ch, "%d", diff[j]-10 );
                    } else {
                        sprintf( ch, "%d", diff[j] );
                    }
                    str_y[j] = ch[0];
                    state[j] = 0;
                    break;
                default:
                    break;
            }
        }

        cout << "(SemiRes) Input " << i << ": ";
        for(int j=0; j<5; j++) {
            cout << vin.at(j);
        }
        cout << endl;
/*
        cout << "(SemiRes) state[] =\t";
        for(int j=0; j<biglen; j++) {
            cout << state[j] << "\t";
        }
        cout << endl;

        cout << "(SemiRes) diff[] =\t";
        for(int j=0; j<biglen; j++) {
            cout << diff[j] << "\t";
        }
        cout << endl;

        cout << "(SemiRes) carry[] =\t";
        for(int j=0; j<biglen; j++) {
            cout << carry[j] << "\t";
        }
        cout << endl;
*/
        

        cout << "(SemiRes) Output " << i << ": ";
        for(int j=len_a-1; j>=0; j--) {
            cout << str_a[j];
        }
        cout << " " << oprnd << " ";
        for(int j=len_b-1; j>=0; j--) {
            cout << str_b[j];
        }
        cout << " = ";
        for(int j=len_y-1; j>=0; j--) {
            cout << str_y[j];
        }
        cout << endl;

        // repeat calculation to find minimum character from onward
        bool flag;
        char sl[2], sr[2], sy[2];
        int sres;
        
        // calc for minimum A.
        flag = true;
        while ( flag ) {
            flag = false;
            sprintf( sl, "%s", "?" );
            sprintf( sr, "%s", "?" );
            sprintf( sy, "%s", "?" );
            for(int j=biglen-1; j>=0; j--) {
                if(str_a[j]=='?') {
                    sprintf( sl, "%d", 0 );
                    switch( state[j] ) {
                        case 3:
                            if( j==biglen-1 ) {
                                if( mul<0 ) {
                                    sres = compute_A('1',str_y[j],mul,carry[j]);
                                    if( sres<0 ) {
                                        sprintf( sl, "%d", sres+10 );
                                        carry[j+1] = mul;
                                        recompute_position(str_a, str_b, str_y, mul, _state, carry, j+1);
                                    } else {
                                        sprintf( sl, "%d", sres );
                                    }
                                    sprintf( sr, "%d", 1 );
                                } else {
                                    sprintf( sl, "%d", 1 );
                                    sres = compute_B('1',str_y[j],mul,carry[j]);
                                    if( sres>9 ) {
                                        sprintf( sr, "%d", sres-10 );
                                        carry[j+1] = mul;
                                        recompute_position(str_a, str_b, str_y, mul, _state, carry, j+1);
                                    } else {
                                        sprintf( sr, "%d", sres );
                                    }
                                }
                            } else {
                                sprintf( sl, "%d", 0 );
                                sres = compute_B('0',str_y[j],mul,carry[j]);
                                if( sres<0 ) {
                                    sprintf( sr, "%d", sres+10 );
                                    carry[j+1] = mul;
                                    recompute_position(str_a, str_b, str_y, mul, _state, carry, j+1);
                                } else if( sres>9 ) {
                                    sprintf( sr, "%d", sres-10 );
                                    carry[j+1] = mul;
                                    recompute_position(str_a, str_b, str_y, mul, _state, carry, j+1);
                                } else {
                                    sprintf( sr, "%d", sres );
                                }
                            }
                            str_a[j] = sl[0];
                            str_b[j] = sr[0];
                            state[j] = 0;
                            break;
                        case 5:
                            if( j==biglen-1 ) {
                                if( mul<0 ) {
                                    sres = compute_A(str_b[j],'1',mul,carry[j]);
                                    if( sres<0 ) {
                                        sprintf( sl, "%d", sres+10 );
                                        carry[j+1] = mul;
                                        recompute_position(str_a, str_b, str_y, mul, _state, carry, j+1);
                                    } else {
                                        sprintf( sl, "%d", sres );
                                    }
                                    sprintf( sy, "%d", 1 );
                                } else {
                                    sprintf( sl, "%d", 1 );
                                    sres = compute_Y('1',str_b[j],mul,carry[j]);
                                    if( sres>9 ) {
                                        sprintf( sy, "%d", sres-10 );
                                        carry[j+1] = mul;
                                        recompute_position(str_a, str_b, str_y, mul, _state, carry, j+1);
                                    } else {
                                        sprintf( sy, "%d", sres );
                                    }
                                }
                            } else {
                                sprintf( sl, "%d", 0 );
                                sres = compute_Y('0',str_b[j],mul,carry[j]);
                                if( sres<0 ) {
                                    sprintf( sy, "%d", sres+10 );
                                    carry[j+1] = mul;
                                    recompute_position(str_a, str_b, str_y, mul, _state, carry, j+1);
                                } else if( sres>9 ) {
                                    sprintf( sy, "%d", sres-10 );
                                    carry[j+1] = mul;
                                    recompute_position(str_a, str_b, str_y, mul, _state, carry, j+1);
                                } else {
                                    sprintf( sy, "%d", sres );
                                }
                            }
                            str_a[j] = sl[0];
                            str_y[j] = sy[0];
                            state[j] = 0;
                            break;
                        case 7:
                            if( j==biglen-1 ) {
                                sprintf( sl, "%d", 1 );
                            } else {
                                sprintf( sl, "%d", 0 );
                            }
                            str_a[j] = sl[0];
                            state[j] -= 1;
                            break;
                    }

                    flag = true;
                }
            }
        }

        // calc for minimum B. (only for case 6.)
        flag = true;
        while ( flag ) {
            flag = false;
            for(int j=biglen-1; j>=0; j--) {
                if(str_b[j]=='?') {
                    if( j==biglen-1 ) {
                        sprintf( sr, "%d", 1 );
                        sres = compute_Y(str_a[j],'1',mul,carry[j]);
                    } else {
                        sprintf( sr, "%d", 0 );
                        sres = compute_Y(str_a[j],'0',mul,carry[j]);
                    }

                    if( sres<0 ) {
                        sprintf( sy, "%d", sres+10 ); 
                    } else if( sres>9 ) {
                        sprintf( sy, "%d", sres-10 ); 
                    } else {
                        sprintf( sy, "%d", sres ); 
                    }
                    
                    str_b[j] = sr[0];
                    str_y[j] = sy[0];
                    state[j] = 0;
                    flag = true;
                }
            }
        }

        cout << "Case #" << i << ": ";
        for(int j=len_a-1; j>=0; j--) {
            cout << str_a[j];
        }
        cout << " " << oprnd << " ";
        for(int j=len_b-1; j>=0; j--) {
            cout << str_b[j];
        }
        cout << " = ";
        for(int j=len_y-1; j>=0; j--) {
            cout << str_y[j];
        }
        cout << endl;

        delete [] w;

        delete [] str_a;
        delete [] str_b;
        delete [] str_y;

        delete [] diff;
        delete [] carry;
        delete [] state;
        delete [] _state;

        vin.clear();
    }

}
