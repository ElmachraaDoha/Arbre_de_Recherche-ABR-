#include <iostream>
#include "ArbreR.h"

using namespace std;

Noeud* CreateNoeud(int v)
{
    Noeud* n = new Noeud;
    n->value = v;
    n->fg = nullptr;
    n->fd = nullptr;
    return n;
}
// Delete the entire tree to free memory
void LibererArbre(Noeud* root)
{
    if (root != nullptr)
    {
        LibererArbre(root->fg);
        LibererArbre(root->fd);
        delete root;
    }
}

Noeud* Insert(Noeud* root, int v)
{
    if (root == nullptr)
        return CreateNoeud(v);

    if (v < root->value)
        root->fg = Insert(root->fg, v);
    else if (v > root->value)
        root->fd = Insert(root->fd, v);

    return root;
}

void Display(Noeud* root)
{
    if (root != nullptr)
    {
        Display(root->fg);
        cout << root->value << "  ";
        Display(root->fd);
    }
}

Noeud* FindNoeud(Noeud* root, int v)
{
    if (root == nullptr || root->value == v)
        return root;

    if (v < root->value)
        return FindNoeud(root->fg, v);
    else
        return FindNoeud(root->fd, v);
}

Noeud* Min(Noeud* root)
{
    while (root != nullptr && root->fg != nullptr)
        root = root->fg;

    return root;
}

Noeud* Delete(Noeud* root, int v)
{
    if (root == nullptr)
        return nullptr;

    if (v < root->value)
        root->fg = Delete(root->fg, v);
    else if (v > root->value)
        root->fd = Delete(root->fd, v);
    else
    {
        if (root->fg == nullptr)
        {
            Noeud* temp = root->fd;
            delete root;
            return temp;
        }
        else if (root->fd == nullptr)
        {
            Noeud* temp = root->fg;
            delete root;
            return temp;
        }

        Noeud* temp = Min(root->fd);
        root->value = temp->value;
        root->fd = Delete(root->fd, temp->value);
    }

    return root;
}

int Level(Noeud* root, int v)
{
    if (root == nullptr)
        return -1;

    if (root->value == v)
        return 0;

    int n;

    if (v < root->value)
        n = Level(root->fg, v);
    else
        n = Level(root->fd, v);

    if (n == -1)
        return -1;

    return n + 1;
}

int Height(Noeud* root)
{
    if (root == nullptr)
        return 0;

    int hG = Height(root->fg);
    int hD = Height(root->fd);

    if (hG > hD)
        return hG + 1;
    else
        return hD + 1;
}
