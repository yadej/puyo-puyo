#include "Mode.h"
#include "grid.h"
#include "assert.h"


using namespace std;

// constructeur


Mode::Mode(){};
Mode::Mode(vector<vector<puyoType>>tableau){
    contient=Grille(tableau);
};
/** \brief lit un fichier en mode simulation et place les puyos dans le tableau
 *          format
 *          <pieces>
 *          <rotation>  <position>
*param  abc le nom du fichier
 * \return void
 *
 */


void Mode::Mode_Simulation(ifstream& abc){
    ofstream sortie("Sortie_regle2_Simulation.txt");
    string a;
    int n,w;
    while(abc>>a>>w>>n){
            char p=a[0];
            char z=a[1];
            assert(w<=3);
            contient.createnextpiece(n,w,p,z);
            do{
                while(contient.jeugravite()==true){
                    contient.jeugravite();
                }
                contient.compte_puyo();
            }
            while(contient.jeugravite()==true);

            contient.compte_puyo();
            if(contient.IsGameOver()){
                    contient.game_over(sortie);
                    contient.retransforme(sortie);
                    return;
            }
    }

    contient.retransforme(sortie);
    sortie.close();
};
/** \brief lit un fichier en mode IA et place les puyos dans le tableau
 *
 * \param un fichier abc de format
 *          <pieces>
 * \return void
 *
 */

void Mode::Mode_IA(ifstream& abc){
    ofstream sortie("Sortie_regle2_IA.txt");
    string a;
    int w,n;
    srand(time(NULL));
    while(abc>>a){
        char p=a[0];
        char z=a[1];
        w = rand()%4;
        n = rand()%5;
        n++;
        contient.createnextpiece(n,w,p,z);
        do{
                while(contient.jeugravite()==true){
                    contient.jeugravite();
                }
                contient.compte_puyo();
            }
            while(contient.jeugravite()==true);
        if(contient.IsGameOver()){
                contient.game_over(sortie);
                contient.retransforme(sortie);
               return;
        }
    }

        contient.retransforme(sortie);
        sortie.close();
};
/** \brief lit un fichier en mode Solo et on place les puyos dans le tableau
 *
 * \param un fichier abc de format
 *          <pieces>
 * \return void
 *
 */
void Mode::Mode_Solo(ifstream& abc){
    ofstream sortie("Sortie_regle2_solo.txt");
    ofstream SimMode("Sortie.txt");
    SimMode<<"MODE SIMULATION";
    string a;
    int w,n;
    while(abc>>a){
        SimMode<<endl<<a<<endl;
        char p=a[0];
        char z=a[1];
        cout<<endl<<p<<z<<endl;
        cout<<"donnez la rotation:";
        cin>>w;
        w = w%4;
        cout<<w<<endl;
        SimMode<<w<<" ";
        cout<<"donnez la position:";
        cin>>n;
        n = n%5+1;
        cout<<n<<endl;
        SimMode<<n;
        contient.createnextpiece(n,w,p,z);
        do{
            while(contient.jeugravite()==true){
                contient.jeugravite();
            }
            contient.compte_puyo();
        } while(contient.jeugravite()==true);
        if(contient.IsGameOver()){
            contient.montrepuyo();
            contient.game_over(sortie);
            contient.retransforme(sortie);
            return;
        }
        contient.montrepuyo();
        contient.montre_score();
        }
        contient.retransforme(sortie);
        sortie.close();

};

