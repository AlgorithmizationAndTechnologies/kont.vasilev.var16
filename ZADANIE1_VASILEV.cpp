#include <iostream>
#include <set>
#include <string>

using namespace std;

const int SIZE = 15; 
set<string> arraysport;

struct SportInfo
{
    string surname;
    string sportname;
    int ves;
};

void findmiddle(SportInfo sportsmens[SIZE], string nsport);

int main()
{
    setlocale(LC_ALL, "rus");
    SportInfo sportsmens[SIZE] =
    {
        {"Ivanov", "football", 109},
        {"Zakharov", "basketball", 84},
        {"Efimov", "tennis", 98},
        {"Egorov", "football", 77},
        {"Smirnova", "basketball", 83},
        {"Maksimova", "tennis", 86},
        {"Ermakov", "hockey", 69},
        {"Abramova", "volleyball", 78},
        {"Volkov", "tennis", 107},
        {"Kruglova", "volleyball", 59},
        {"Lobanov", "football", 89},
        {"Dubinina", "volleyball", 85},
        {"Kozyrev", "basketball", 79},
        {"Malceva", "hockey", 95},
        {"Vasiliev", "hockey", 71}
    };

    for (int i = 0; i < SIZE; i++)
    {
        arraysport.insert(sportsmens[i].sportname);
    }

    cout << " ВСЕ ВИДЫ СПОРТА ИЗ СПИСКА:";

    for (string str : arraysport)
    {
        cout << " " << str;
    }
    cout << endl;
    string sname;
    while (true)
    {
        cout << " ВВЕДИТЕ НАЗВАНИЕ СПОРТА ИЗ ЗАДАННОГО СПИСКА - ";
        cin >> sname;

        bool found = false;
        for (string sport : arraysport)
        {
            if (sport == sname)
            {
                found = true;
                break;
            }
        }

        if (found)
        {
            break;
        }
        else
        {
            cout << " ОШИБКА: такого вида спорта нет в списке! Попробуйте снова." << endl;
        }
    }
 
    findmiddle(sportsmens, sname);
    system("pause");
}

void findmiddle(SportInfo sportsmens[SIZE], string nsport)
{
    int vesves = 0;
    int count = 0;

    for (int i = 0; i < SIZE; i++) 
    {
        if (nsport == sportsmens[i].sportname)
        {
            vesves += sportsmens[i].ves;
            count++;
        }
    }

    if (count == 0) {
        cout << " НЕТ СПОРТСМЕНОЫ С ТАКИМ ВИОМ СПОРТА " << endl;
        return;
    }

    int middle = vesves / count;
    cout << " СРЕДНИЙ ВЕС В ДАННОМ ВИДЕ СПОРТА РАВЕН = " << middle << endl;

    int count2 = 0;

    for (int i = 0; i < SIZE; i++)
    {
        if ((nsport == sportsmens[i].sportname) && (sportsmens[i].ves < middle))
        {
            count2++;
        }
    }
    cout << " КОЛИЧЕСТВО ЛЮДЕЙ С ВЕСОМ МЕНЬШЕ - " << count2 << endl;
}
