#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
#include <locale>
#include <clocale>

using namespace std;

int getConclusion(int value1, int value2, int value3)
{
    int conclusion;
    conclusion = value1 + value2 - value3;
    return conclusion;
}

void mainFunction()
{
    ofstream file;
    file.open("bill.txt", ios::app);

    ofstream file2;
    file2.open("CarParkManagementSystem.txt", ios::app);

    cin.ignore();

    const int password = 123456789;
    const int daysperweek = 7;
    const int hoursperday = 24;
    const int maxCapacity = 100;
    const int minVehicleCount = 0;
    int gottenPassword = 0;
    int price = 0;
    int enteredcar = 0;
    int quittedcar = 0;
    int carcount = 0;
    int systemMode = 0;
    float timeSpent = 0.00;
    bool continue01 = false;
    string plate = "XX XXX XX";

    cout << "Système de gestion de parking" << endl;

    while (true)
    {
        cout << "Veuillez entrer le mot de passe pour l'utilisateur-1 :" << endl;
        cin >> gottenPassword;

        if (gottenPassword == password)
            break;
        else
            cout << "Mot de passe incorrect. Veuillez réessayer." << endl;
    }

    while (true)
    {
        cout << "Veuillez choisir le mode du système :\n"
             << "1 - Système de facturation\n"
             << "2 - Système de gestion du parking\n"
             << "3 - Quitter" << endl;
        cin >> systemMode;

        if (systemMode == 3)
            break;

        switch (systemMode)
        {
            case 1:
            cout << "Tarifs selon la durée de stationnement :" << endl;
            cout << "1 heure ou moins => Gratuit\n"
                 << "1-2 heures => 5 USD\n"
                 << "2-3 heures => 7 USD\n"
                 << "3-4 heures => 10 USD\n"
                 << "4-5 heures => 15 USD\n"
                 << "Plus de 5 heures => 20 USD\n";

            while (true)
            {
                cout << "Veuillez entrer la plaque d'immatriculation du véhicule :" << endl;
                getline(cin, plate);

                cout << "Veuillez entrer la durée de stationnement (format X.XX) :" << endl;
                cin >> timeSpent;

                if (timeSpent < 1.00)
                    price = 0;
                else if (timeSpent < 2.00)
                    price = 5;
                else if (timeSpent < 3.00)
                    price = 7;
                else if (timeSpent < 4.00)
                    price = 10;
                else if (timeSpent < 5.00)
                    price = 15;
                else
                    price = 20;

                file << "Véhicule : " << plate
                     << "\nPrix : " << price << " USD\n\n";

                cout << "Souhaitez-vous continuer ? (1 = Oui, 0 = Non)" << endl;
                cin >> continue01;

                if (!continue01)
                {
                    cout << "Processus terminé." << endl;
                    Sleep(200);
                    cout << "La facture a été enregistrée avec succès." << endl;
                    break;
                }
            }
            break;

            case 2:
            for (int i = 0; i < daysperweek; i++)
            {
                for (int j = 0; j < hoursperday; j++)
                {
                    while (true)
                    {
                        cout << "Heure " << j + 1
                             << " : Nombre de véhicules entrés :" << endl;
                        cin >> enteredcar;

                        if (enteredcar < minVehicleCount || enteredcar > maxCapacity)
                        {
                            cout << "Valeur invalide." << endl;
                            continue;
                        }

                        cout << "Heure " << j + 1
                             << " : Nombre de véhicules sortis :" << endl;
                        cin >> quittedcar;

                        if (quittedcar < minVehicleCount || quittedcar > maxCapacity)
                        {
                            cout << "Valeur invalide." << endl;
                            continue;
                        }

                        carcount = getConclusion(carcount, enteredcar, quittedcar);

                        cout << "Véhicules actuellement dans le parking : "
                             << carcount << endl;

                        file2 << "Jour " << i + 1
                              << " - Heure " << j + 1
                              << " - Véhicules : " << carcount << endl;

                        if (carcount == 0)
                            cout << "Le parking est vide." << endl;
                        else if (carcount >= maxCapacity)
                            cout << "Le parking est plein." << endl;
                        else if (carcount >= maxCapacity * 0.75)
                            cout << "Le parking est presque plein." << endl;
                        else if (carcount >= maxCapacity / 2)
                            cout << "La moitié du parking est occupée." << endl;

                        Sleep(300);
                        break;
                    }
                }

                cout << "Jour " << i + 1
                     << " terminé. Véhicules restants : "
                     << carcount << endl;
            }
            break;
        }
    }

    file.close();
    file2.close();
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "French");

    system("color 0A");
    Sleep(300);

    mainFunction();

    system("pause");
    return 0;
}
