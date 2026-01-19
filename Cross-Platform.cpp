#include <iostream>
#include <fstream>
#include <cstring>

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
    bool continue01  = false;
    string plate = "XX XXX XX";

    cout << "Car Park Management System" << endl;
    
    while (true)
    {
        cout << "Enter Password for user-1. " << endl;
        cin >> gottenPassword;

        if (gottenPassword == password)
        {
            break;
        }
        else
        {
            cout << "Invalid password. Please try again. " << endl;
        }
    }
    while (true)
    {
        cout << "Choose the system program mode. Type 1 for bill system, 2 for car park management system and 3 to quit. " << endl;
        cin >> systemMode;
        if (systemMode == 3)
        {
            break;
        }
        else
        {
            switch (systemMode)
            {
                case 1:
                cout << "Price for Cars stayed in the park: " << endl;
                cout << "1 hour or less => free\n1-2 hours => 5 USD\n2-3 hours => 7 USD\n3-4 hours => 10 USD\n4-5 hours => 15 USD\nMore than 5 hours => 20 USD\n";

                while (true)
                {
                    cout << "Car no: 1. Please enter the plate text of vehicle. " << endl;
                    getline(cin, plate);
                    cout << "Please enter the time vehicle stayed in the park. Use the format: X.XX" << endl;
                    cin >> timeSpent;

                    if (timeSpent < 1.00)
                    {
                        price = 0;
                    }
                    else if (timeSpent > 1.00 && timeSpent < 2.00)
                    {
                        price = 5;
                    }
                    else if (timeSpent > 2.00 && timeSpent < 3.00)
                    {
                        price = 7;
                    }
                    else if (timeSpent > 3.00 && timeSpent < 4.00)
                    {
                        price = 10;
                    }
                    else if (timeSpent > 4.00 && timeSpent < 5.00)
                    {
                        price = 15;
                    }
                    else
                    {
                        price = 20;
                    }

                    file << "Vehicle: " << plate << "\nPrice: " << price << "\n\n";
                    cout << "Do you want to continue the process? Type 1 for yes, 0 for no. " << endl;
                    cin >> continue01;

                    if (continue01 == false)
                    {
                        cout << "Process ended. " << endl;
                        cout << "Bill saved in the direct location of C++ program. " << endl;
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
                            while (true)
                            {
                                cout << "Hour: " << j + 1 << ". Type the count of vehicles entered this hour. " << endl;
                                cin >> enteredcar;
                                
                                if (enteredcar <= maxCapacity && enteredcar >= minVehicleCount)
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "Invalid value. Please type again. " << endl;
                                }
                            }
                            while (true)
                            {
                                cout << "Hour " << j + 1 << ". Type the count of vehicles quitted this hour. " << endl;
                                cin >> quittedcar;

                                if (quittedcar <= maxCapacity && quittedcar >= minVehicleCount)
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "Invalid value. Please type again. " << endl;
                                }
                            }
                            carcount = getConclusion(carcount, enteredcar, quittedcar);
                            cout << "There are " << carcount << " cars inside the car park. " << endl;
                            file2 << "Hour: " << j + 1 << "\nVehicle Count: " << carcount << endl << endl;

                            if (carcount == maxCapacity)
                            {
                                cout << "Car Park is full. " << endl;
                                file2 << "Car park is full. Day: " << i + 1 << ", Hour: " << j + 1 << "\n";
                            }
                            else if (carcount >= maxCapacity - 20)
                            {
                                cout << "Car park is almost full. Day: " << i + 1 << ", Hour: " << j + 1 << "\n";
                                file2 << "Car park is almost full. Day: " << i + 1 << ", Hour: " << j + 1 << "\n";
                            }
                            else if (carcount >= maxCapacity / 2)
                            {
                                cout << "Half of the car park is full. Day: " << i + 1 << ", Hour: " << j + 1 << "\n";
                                file2 << "Half of the car park is full. Day: " << i + 1 << ", Hour: " << j + 1 << "\n";
                            }
                            else if (carcount >= maxCapacity / 4)
                            {
                                cout << "Quarter of the car park is full. Day: " << i + 1 << ", Hour: " << j + 1 << "\n";
                                file2 << "Quarter of the car park is full. Day: " << i + 1 << ", Hour: " << j + 1 << "\n";
                            }
                            else if (carcount < maxCapacity / 4 && carcount > 0)
                            {
                                cout << "Less than the quarter of the car park is full. Day: " << i + 1 << ", Hour: " << j + 1 << "\n";
                                file2 << "Less than the quarter of the car park is full. Day: " << i + 1 << ", Hour: " << j + 1 << "\n";
                            }
                            else
                            {
                                cout << "Car park is empty. " << endl;
                                file2 << "Car park is empty. Day: " << i + 1 << ", Hour: " << j + 1 << "\n";
                            }

                            break;
                        }
                        cout << "Day: " << i + 1 << ". Vehicles inside the car park: " << carcount << endl;
                        file2 << "Day: " << i + 1 << "\nThere are " << carcount << " vehicles inside the car park. " << endl;
                    }
                    cout << "Week ended. Vehicle count: " << carcount << ". " << endl;
                    file2 << "Week 1 ended. There are " << carcount << " vehicles inside the car park. " << endl;
                }
                break;
            }
        }
    }
    file.close();
    file2.close();
}

int main()
{
    cin.ignore();
    mainFunction();

    return 0;
}
