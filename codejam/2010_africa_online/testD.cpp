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

//#define RELEASE_VEC(v)  

#define USE_PIPE_IO 1
#define USE_TIME_CMD 1

#define U_STATE (0)   // unknown

#define T_STATE (-1)   // truthtown
#define L_STATE (-2)   // liarville
#define S_STATE (-4)    // same state (for Statement class)
#define D_STATE (-8)   // different state (for Statement class)

#define FROM_TA (1)
#define FROM_PA (2)

#define JACOBI_ROTATE(a, i, j, k, l)    { g = a[i][j]; h = a[k][l]; a[i][j] = g-s*(h+g*tau); a[k][l]=h+s*(g-h*tau); }

typedef unsigned long long int ULINT;

using namespace std;

// ----- class for matrix equation -----
class Mat {
public:
    Mat(int rows, int cols, double val=0):m_rows(rows),m_cols(cols) {
        p = new double*[rows];
        for(int ii=0;ii<rows;ii++) {
            p[ii] = new double[cols+1];
            memset(p[ii], val, sizeof(double)*(cols+1));
        }
    }

    ~Mat() {
        clear();
    }

    void clear() {
        if( p!=NULL ) {
            for(int ii=0;ii<m_rows;ii++){
                delete [] p[ii];
            }
                
            delete [] p;
        }
    }

    // ----- matrix operations -----
    void inverse()
    {
    }

    // ----- redefine operators -----
    Mat& operator=(const Mat& mat) {
        if( this == &mat )  // check for calling itself
            return *this;

        if( p!=NULL ) {
            clear();
            printf("matrix is not null, so we clear its data..\n");
        }

        m_rows = mat.m_rows;
        m_cols = mat.m_cols;

        p = new double*[m_rows];
        for(int i=0 ; i<m_rows ; i++)
        {
            p[i] = new double[m_cols];
            memcpy(p[i], mat.p[i], sizeof(double)*m_cols);
        }

        return *this;
    }

    const Mat operator+(const Mat& mat) const {
        assert( p != NULL );
        assert( m_rows == mat.m_rows && m_cols == mat.m_cols );

        register int i, j;

        Mat temp(m_rows, m_cols);

        for( j = 0 ; j < m_rows ; j++ )
        for( i = 0 ; i < m_cols ; i++ )
            temp.p[j][i] = p[j][i] + mat.p[j][i];

        return temp;
    }

    const Mat operator-(const Mat& mat) const {
        assert( p != NULL );
        assert( m_rows == mat.m_rows && m_cols == mat.m_cols );

        register int i, j;

        Mat temp(m_rows, m_cols);

        for( j = 0 ; j < m_rows ; j++ )
        for( i = 0 ; i < m_cols ; i++ )
            temp.p[j][i] = p[j][i] - mat.p[j][i];

        return temp;
    }

    const Mat operator*(const Mat& mat) const {
        assert( p != NULL );

        int row1 = m_rows;
        int col1 = m_cols;
        int row2 = mat.m_rows;
        int col2 = mat.m_cols;

        assert( col1 == row2 );

        register int i, j, k;

        Mat temp(row1, col2);

        for( j = 0 ; j < row1 ; j++ )
        for( i = 0 ; i < col2 ; i++ )
        for( k = 0 ; k < row2 ; k++ )
            temp.p[j][i] += (p[j][k] * mat.p[k][i]);

        return temp;
    }

    const Mat operator*(const double x) const {
        assert( p != NULL );

        register int i, j;

        Mat temp(m_rows, m_cols);

        for( j = 0 ; j < m_rows ; j++ )
        for( i = 0 ; i < m_cols ; i++ )
            temp.p[j][i] = p[j][i] * x;

        return temp;
    }

    
    // ----- member variables -----
public:
    int m_rows;
    int m_cols;
    double **p;
};

class Statement {
public:
    Statement() {}
    ~Statement() {}

    Statement operator=(Statement& ins) {
        teller = ins.teller;
        state = ins.state;
        lhs = ins.lhs;
        rhs = ins.rhs;
    }

    int teller;
    int state;
    int lhs;
    int rhs;
};

bool cmp_asc(const int& ref, const int& cmp) { return (ref < cmp); }
bool cmp_desc(const int& ref, const int& cmp) { return (ref > cmp); }
bool cmp_teller_asc(const Statement& ref, const Statement& cmp) { return (ref.teller < cmp.teller); }

void convert_matrix_form(vector<Statement>& slist, Mat *smat, Mat *rmat) {
   for(int i=0; i<slist.size(); i++) {
       switch(slist[i].state) {
           case T_STATE:
               rmat->p[ i ][ 0 ] = 0;
               smat->p[ i ][ slist[i].teller-1 ] = 1;
               smat->p[ i ][ slist[i].lhs-1    ] = 1;
               break;
           case L_STATE:
               rmat->p[ i ][ 0 ] = 1;
               smat->p[ i ][ slist[i].teller-1 ] = 1;
               smat->p[ i ][ slist[i].lhs-1    ] = 1;
               break;
           case S_STATE:
               rmat->p[ i ][ 0 ] = 0;
               smat->p[ i ][ slist[i].teller-1 ] = 1;
               smat->p[ i ][ slist[i].lhs-1    ] = 1;
               smat->p[ i ][ slist[i].rhs-1    ] = 1;
               break;
           case D_STATE:
               rmat->p[ i ][ 0 ] = 1;
               smat->p[ i ][ slist[i].teller-1 ] = 1;
               smat->p[ i ][ slist[i].lhs-1    ] = 1;
               smat->p[ i ][ slist[i].rhs-1    ] = 1;
               break;
       }
   }

   return;
}

void solve_matrix_modular(Mat *lmat, Mat *rmat, Mat *umat, int nmod) {

    Mat *flmat = new Mat();
//    gauss_elimination(lmat, flmat);
    flmat = lmat.inverse();

    rmat = flmat * umat;
}


int main()
{
    int ncases;
    cin >> ncases;
    cin.ignore();

    int nnum, mnum;

    char cstate;
    Statement *s;

    vector<Statement> slist;

    for(int i=0; i<ncases; i++) {
        cin >> nnum;
        cin >> mnum;

        for(int j=0; j<mnum; j++) {
            s = new Statement();
            cin >> s->teller;

            cin >> cstate;
            if( cstate=='T' ) {
                s->state = T_STATE;
            } else if( cstate=='L' ) {
                s->state = L_STATE;
            } else if( cstate=='S' ) {
                s->state = S_STATE;
            } else if( cstate=='D' ) {
                s->state = D_STATE;
            }

            cin >> s->lhs;

            if( s->state==S_STATE || s->state==D_STATE )  cin >> s->rhs;

            slist.push_back(*s);
        }
        sort(slist.begin(), slist.end(), cmp_teller_asc);

        Mat *lmat = new Mat(mnum, nnum, 0);     // statement matrix..
        Mat *rmat = new Mat(nnum, 1, 0);        // matrix for modular equation(answer)..
        Mat *umat = new Mat(mnum, 1, 0);        // result matrix..
        convert_matrix_form(slist, lmat, umat);

        solve_matrix_modular(lmat, rmat, umat, 2);

        cout << "Case #" << i+1 << ": " << rmat->p[0][0];
        for(int j=1; j<nnum; j++)   cout << " " << rmat->p[j][0];
        cout << endl;

        lmat->clear();
        rmat->clear();
        umat->clear();

        slist.clear();
    }
    
    return 0;
}

