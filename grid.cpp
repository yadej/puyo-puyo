
#include "grid.h"
#include "assert.h"
using namespace std;


Grille::Grille(){};


// C'est un constructeur

Grille::Grille(vector<vector<puyoType>>tableau):contient(tableau){
}

/** Change les types puyotypes en caractères
 *
 * @param p un type puyo
 * @return un charactères
 *
 */

char PuyoToChar(puyoType p) {
    if(p==Bleu){
        return 'B';
   }else if(p==Rouge){
       return 'R';
   }else if(p==Jaune){
       return 'J';
   }else if(p==Vert){
       return 'V';
   }else if(p==Magenta){
       return 'M';
   }else if(p==None){
       return '.';
    }
    return ' ';
}

/** Change un caractère en un type puyo si le caractère fait partie de cela
 *
 * \param un char p
 *
 * \return un puyotype
 *
 */

puyoType CharToPuyo(char p) {
   if(p=='B'){
        return Bleu;
   }else if(p=='R'){
       return Rouge;
   }else if(p=='J'){
       return Jaune;
   }else if(p=='V'){
       return Vert;
   }else if(p=='M'){
       return Magenta;
   }else if(p=='.'){
       return None;
    }
    return None;
}
/**  test si le haut du tableau est rempli
 *
 * @return true si c'est vrai sinon false
 *
 */


bool Grille::IsGameOver(){
    vector<vector<puyoType>>over=contient;
    for(int i=0;i<colo;i++){
        if(over[0][i]!=puyoType::None){
                return true;
        }
    }
    return false;
}
/**  créer la prochaine piece qui va tomber et la placer
 *
 * @param  un entier n  un entier w
 * @param  un caractère p  un caractère z
 */

void Grille::createnextpiece(int n,int w,char p,char z){
    if(IsGameOver()){
            return;
    }else if(w==0){
        contient[0][n-1]=CharToPuyo(p);
        contient[0][n]=CharToPuyo(z);
    }else if(w==1){
        contient[1][n-1]=CharToPuyo(p);
        contient[0][n-1]=CharToPuyo(z);
    }else if(w==2){
        contient[0][n]=CharToPuyo(p);
        contient[0][n-1]=CharToPuyo(z);
    }else if(w==3){
        contient[0][n-1]=CharToPuyo(p);
        contient[1][n-1]=CharToPuyo(z);
    }

}
/** Vérifie le placement et le score
 */
void Grille::testplacement1(){
    assert(contient[0][2]==Bleu);
    assert(contient[1][2]==Vert);
}
/** Fait quelque teste en plaçant des puyos
 */

void Grille::testplacement2(){
    assert(contient[10][2]==Bleu);
    assert(contient[11][2]==Vert);
    contient[11][4]=Rouge;
    contient[10][4]=Rouge;
    contient[11][5]=Rouge;
    contient[10][5]=Rouge;
    contient[9][5]=Jaune;
    contient[9][4]=Jaune;
    contient[9][3]=Jaune;
    contient[8][4]=Jaune;
    contient[9][2]=Magenta;
    contient[8][3]=Magenta;
    contient[8][2]=Magenta;
    contient[9][1]=Magenta;
    contient[8][1]=Bleu;
    contient[7][1]=Bleu;
    contient[6][1]=Bleu;
    contient[5][1]=Bleu;
    contient[8][5]=Vert;
    contient[7][5]=Vert;
    contient[7][4]=Vert;
    contient[7][3]=Vert;
    contient[6][3]=Vert;
    contient[7][2]=Vert;

}

/** Fait tomber les puyos dans le bas du tableau et renvoie false si ils sont tous tombés
 * \return false si les puyos sont tous tombés
 *
 */

bool Grille::jeugravite(){
    vector<vector<puyoType>>tombe=contient;
    for(int y=0;y<colo;y++){
        for(int x=0;x<ligne-1;x++){
            if(tombe[x][y]==None)continue;
            if(tombe[x][y] && !tombe[x+1][y]){
                contient[x+1][y]=tombe[x][y];
                contient[x][y]=puyoType::None;
            }

        }


    }

     for(int i=0;i<ligne-1;i++){
        for(int j=0;j<colo;j++){
            if(contient[i][j]==None)continue;
            if(contient[i][j]!=contient[i+1][j]&&contient[i+1][j]==None){
                return true;
            }
        }
     }
     return false;
     }

/** écrit dans le fichier le tableau des puyos en char
 * \param  abc un fichier ofstream
 * \return void
 */


void Grille::retransforme(ofstream& abc){
    abc<<endl;
    for(int i=0;i<ligne;i++){
        for(int j=0;j<colo;j++){
            abc<<PuyoToChar(contient[i][j]);
        }
        abc<<endl;
    }
    abc<<score<<" "<<"points"<<endl;
}
/** Montre la place des puyo dans le terminal
 */

void Grille::montrepuyo(){
    for(int i=0;i<ligne;i++){
        for(int j=0;j<colo;j++){
            cout<<PuyoToChar(contient[i][j]);
        }
        cout<<endl;
    }
}
/** \brief compte les puyo et les enleve quand il y a assez côte à côte et définit le score en plus
 * \return void
 */

void Grille::compte_puyo(){
    tableauligne=vector<vector<int>>(ligne,vector<int>(colo,false));
    puyo=0;
     for(int j = 0; j<colo; j++){
            for(int i =ligne-1; i>=0; i--){
                    pos.clear();
            if(contient[i][j]!=None){
                puyocount = 0;
                Count(i, j, contient[i][j]);
            }
            if(pos.size()<4){
                pos.clear();
            }
            if(pos.size()>3){
                puyo=puyo+pos.size();
                del(pos);
            }


        }

    }
    if(puyo<8)groupe=1;
    if(puyo<12 && puyo>7)groupe=2;
    if(puyo<16 && puyo>11)groupe=3;
    if(score!=scoreplus(score,combo,puyo,groupe)){
        score=scoreplus(score,combo,puyo,groupe);
        combo++;
    }else{
        combo=1;
    }
}
/** compte les puyos si ils sont égale au puyo d'origine et rajoute leur coordonné dans un tableau
 *
 * @param un entier x, un entier y et une type puyoType c
 * @return void
 *
 */

void Grille::Count(int x,int y,puyoType c){

    for(int i=0;i<pos.size();i++){
        if(x==pos[i][0] && y==pos[i][1]){
            return;
        }
    }
    pos.push_back({x,y});
    if(contient[x][y]!= c ||contient[x][y]==None)return;

     for(int n = 0; n<4; n++){
        int nx = dx[n] + x;
        int ny = dy[n] + y;

        if(0<=nx && nx<ligne && 0<=ny && ny<colo){
            if(contient[nx][ny] == c  ){
                puyocount++;
                Count(nx, ny, c);
            }
        }
    }
}
/** \ enlève les puyos  dont les positions sont mis dans un tableau
 * \param lav un tableau2D
 * \return void
 */

void Grille::del(vector<vector<int>>lav){
    for(int i=0;i<lav.size();i++){
        contient[lav[i][0]][lav[i][1]]=None;
    }

}
/** Calcule le score cumulé
 *
 * \param un entier a,un entier combo,un entier puyo,un entier groupe
 * \return return a sinon return 999999 si a superieur à ce nombre
 *
 */

int Grille::scoreplus(int a, int combo,int puyo,int groupe){
    int k=1;
    int m=1;
    while (combo>0){
        k*=k;
        combo--;
    }
    while (groupe>0){
        m*=4;
        groupe--;
    }
    a=a + (10*puyo*(k+m));
    puyo=0;
    groupe=1;
    if(a>=999999||a<=-15000){
            a= 999999;
    }
    return a;
}
/** écrit défaite sur un fichier quand on demande la fontion
 *
 * \param abc le fichier
 * \return void
 *
 */

void Grille::game_over(std::ofstream& abc){
    abc<<"Défaite"<<endl;
}
/** \ Affiche le score
 * \return void
 */

void Grille::montre_score(){
    cout<<score;
}


