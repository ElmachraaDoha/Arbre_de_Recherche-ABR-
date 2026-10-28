#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>
#include <string>
#include "ArbreR.h"

using namespace std;
using namespace chrono;

int main()
{
    int tailles[] = {
        1000, 2000, 3000, 4000, 5000,
        10000, 15000, 20000, 30000, 40000,
        50000, 60000, 70000, 80000, 90000,
        100000
    };

    int repetitions = 10;

    random_device rd;
    mt19937 gen(rd());

    cout << "\n";
    cout << "===============================================\n";
    cout << "       ETUDE DE PERFORMANCE D'UN ABR\n";
    cout << "===============================================\n";
    cout << "Operation : insertion de nombres aleatoires\n";
    cout << "Repetitions par taille : " << repetitions << "\n";
    cout << "Unite de mesure : millisecondes (ms)\n\n";

    cout << left
         << setw(15) << "Elements"
         << setw(18) << "Moyenne (ms)"
         << setw(18) << "Minimum (ms)"
         << setw(18) << "Maximum (ms)"
         << "\n";

    cout << string(69, '-') << "\n";

    for (int taille : tailles)
    {
        vector<int> valeurs(taille);

        for (int i = 0; i < taille; i++)
            valeurs[i] = i + 1;

        double total = 0;
        double tempsMin = 1e100;
        double tempsMax = 0;

        for (int r = 0; r < repetitions; r++)
        {
            shuffle(valeurs.begin(), valeurs.end(), gen);

            Noeud* root = nullptr;

            auto debut = steady_clock::now();

            for (int v : valeurs)
                root = Insert(root, v);

            auto fin = steady_clock::now();

            double temps = duration<double, milli>(
                fin - debut
            ).count();

            total += temps;

            if (temps < tempsMin)
                tempsMin = temps;

            if (temps > tempsMax)
                tempsMax = temps;

            LibererArbre(root);
        }

        double moyenne = total / repetitions;

        cout << left
             << setw(15) << taille
             << fixed << setprecision(3)
             << setw(18) << moyenne
             << setw(18) << tempsMin
             << setw(18) << tempsMax
             << "\n";
    }

    cout << string(69, '-') << "\n";
    cout << "Fin des tests.\n";
    cout << "===============================================\n";

    return 0;
}
