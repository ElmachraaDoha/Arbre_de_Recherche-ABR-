#include <iostream>
#include "ArbreR.h"

using namespace std;

int main1()
{
    Noeud* root = nullptr;
    int choix, v;

    do
    {
        cout << "\n===== MENU ABR =====" << endl;
        cout << "1. Inserer un nombre" << endl;
        cout << "2. Rechercher un nombre" << endl;
        cout << "3. Supprimer un nombre" << endl;
        cout << "4. Afficher l'arbre (ordre croissant)" << endl;
        cout << "5. Calculer le niveau d'un nombre" << endl;
        cout << "6. Calculer la hauteur de l'arbre" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix)
        {
            case 1:
                cout << "Nombre a inserer : ";
                cin >> v;
                root = Insert(root, v);
                cout << "Nombre insere!" << endl;
                break;

            case 2:
                cout << "Nombre a rechercher : ";
                cin >> v;

                if (FindNoeud(root, v) != nullptr)
                    cout << "Nombre trouve !" << endl;
                else
                    cout << "Nombre introuvable!" << endl;
                break;

            case 3:
                cout << "Nombre a supprimer : ";
                cin >> v;

                if (FindNoeud(root, v) != nullptr)
                {
                    root = Delete(root, v);
                    cout << "Nombre supprime!" << endl;
                }
                else
                    cout << "Nombre introuvable." << endl;
                break;

            case 4:
                cout << "Arbre en ordre croissant : ";
                Display(root);
                cout << endl;
                break;

            case 5:
                cout << "Nombre : ";
                cin >> v;

                if (FindNoeud(root, v) != nullptr)
                    cout << "Niveau : " << Level(root, v) << endl;
                else
                    cout << "Nombre introuvable!" << endl;
                break;

            case 6:
                cout << "Hauteur de l'arbre : "
                     << Height(root) << endl;
                break;

            case 0:
                cout << " Fin du programme " << endl;
                break;

            default:
                cout << " Choix invalide !" << endl;
        }

    } while (choix != 0);

    return 0;
}
