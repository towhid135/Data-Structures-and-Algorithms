#include <bits/stdc++.h>
using namespace std;

class matrix{
    int m[3][3];
    public:
        void read(void){
            cout<<"insert elements of 3x3 matrix: "<<endl;
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    cout<<"m["<<i<<"]["<<j<<"]: ";
                    cin>>m[i][j];
                }
            }
        };
        void display(void){
            cout<<"The 3x3 matrix is: "<<endl;
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    cout<<m[i][j]<<" ";
                }
                cout<<endl;
            }
        }

        //it will return object of matrix class, that's why return type is matrix
        friend matrix trans(matrix mat);
};

matrix trans(matrix mat){
    matrix m1;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            m1.m[i][j] = mat.m[j][i];
        }
    }

    return m1;
}

int main(){
    matrix result,m;
    m.read();
    cout<<"before calling friend func: "<<endl;
    m.display();

    cout<<"after calling friend func: "<<endl;
    result = trans(m);

    result.display();

    return 0;
}