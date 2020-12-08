
#include "grid.h"
#include "mode.h"
#include "assert.h"
using namespace std;

int main(){
    int colo=6;
    int ligne=12;
    vector<vector<puyoType>>tableau(ligne,vector<puyoType>(colo,None));

    int w;
    string nextpuyo;
    string b,c;
    string a;
    ifstream suite;
    ofstream sortie;
    sortie.open("test.txt");
    Grille contient(tableau);
    a="BV";
    char p=a[0];
    char z=a[1];
    w=3;
    assert(w<=3);
    contient.createnextpiece(3,3,p,z);
    contient.testplacement1();
    while(contient.jeugravite()){
        contient.jeugravite();
    }
    contient.createnextpiece(1,3,p,z);
    while(contient.jeugravite()){
        contient.jeugravite();
    }
    contient.createnextpiece(2,3,p,z);
    while(contient.jeugravite()){
        contient.jeugravite();
    }
    contient.createnextpiece(4,3,p,z);
    while(contient.jeugravite()){
        contient.jeugravite();
    }
    //contient.testplacement2();

    contient.compte_puyo();
    contient.montrepuyo();
    contient.retransforme(sortie);
    sortie.close();
    suite.close();
    return 0;
}
