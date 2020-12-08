
#include "mode.h"
using namespace std;

int main(){
    int colo=6;
    int ligne=12;
    vector<vector<puyoType>>tableau(ligne,vector<puyoType>(colo,None));
    string b,c;
    ifstream suite;
    //suite.open("0_rotations.txt");
    //suite.open("0_petit.txt");
    //suite.open("1_groupe_simple.txt");
    //suite.open("1_moyen.txt");
    //suite.open("2_combos.txt");
    //suite.open("3_groupes_simult.txt");
    //suite.open("4_combos_et_groupes.txt");
    //suite.open("5_mega_combo_regle2.txt");
    //suite.open("0_petit_solo.txt");
    suite.open("1_moyen_solo.txt");
    Mode mode(tableau);
    suite>>b>>c;
    cout<<b+c;
    if(b+c=="MODESIMULATION"){
        mode.Mode_Simulation(suite);
    }
    if(b+c=="MODEIA"){
        mode.Mode_IA(suite);
    }
    if(b+c=="MODESOLO"){
        mode.Mode_Solo(suite);
    }
}
