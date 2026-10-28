#ifndef ARBRER_H_INCLUDED
#define ARBRER_H_INCLUDED

struct Noeud {

    int value;
    Noeud* fg;
    Noeud* fd;
};

//create
Noeud* CreateNoeud(int v);

//free Arbre
void LibererArbre(Noeud* root);

//insert
Noeud* Insert(Noeud* root, int v);

//display
void Display(Noeud* root);

//find
Noeud* FindNoeud(Noeud* root, int v);

//min
Noeud* Min(Noeud* root);

//delete
Noeud* Delete(Noeud* root, int v);

//Level  - Height
int Level(Noeud* root, int v);
int Height(Noeud* root);

#endif
