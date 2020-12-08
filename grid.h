#ifndef GRID_H
#define GRID_H
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

enum puyoType
    {
        None=0,Rouge=1,Vert=2,Jaune=3,Bleu=4,Magenta=5
    };

puyoType CharToPuyo(char p);
char PuyoToChar(puyoType p);

class Grille
{
    public:
    static const int colo=6;
    static const int ligne=12;

    std::vector<std::vector<int>>tableauligne;
    std::vector<std::vector<puyoType>>tableau;
    std::vector<std::vector<int>>pos;
    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    //*Initialiser du tableau Grid
    Grille();
    Grille(std::vector<std::vector<puyoType>>tableau);
    void montrepuyo();
    void compte_puyo();
    void testplacement1();
    void testplacement2();
    bool jeugravite();
    bool IsGameOver();
    void del(std::vector<std::vector<int>>lav);
    void createnextpiece(int n,int w,char p,char z);
    void retransforme(std::ofstream& abc);
    void montre_score();
    void game_over(std::ofstream& abc);
    void Count(int x,int y,puyoType c);
    int scoreplus(int a,int combo,int b,int groupe);
    int combo;
    int puyo;
    int puyocount;
    int groupe;
    int score=0;
    int n;
    int w;
    private:
    std::vector<std::vector<puyoType>>contient;

};



#endif
