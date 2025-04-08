#include <iostream>
#include <set>
#include <ctime>

using namespace std;

const int SIZE = 1000;

void Random(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 51;
    }
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void findUniq(int arr1[], int m, int arr2[], int n)
{
    set<int> uniqArr1;
    set<int> duplicates;
    set<int> numArr2;
    set<int> result;

    for (int i = 0; i < m; i++)
    {
        if (duplicates.count(arr1[i]))
        {
            continue;
        }
        if (uniqArr1.count(arr1[i]))
        {
            uniqArr1.erase(arr1[i]);
            duplicates.insert(arr1[i]);
        }
        else
        {
            uniqArr1.insert(arr1[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        numArr2.insert(arr2[i]);
    }

    for (int num : uniqArr1)
    {
        if (!numArr2.count(num))
        {
            result.insert(num);
        }
    }

    cout << endl << " : ";
    cout << " ЧИСЛА ВСТРЕЧАЮЩИЕСЯ 1 РАЗ В ПЕРВОЙ ПОСЛЕДОВАТЕЛЬНОСТИ И ОТСУТСТВУЮЩИЕ ВО ВТОРОЙ: ";
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << endl << " МОЩНОСТЬ МНОЖЕСТВА: " << result.size() << endl;
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    int M, N;
    cout << " ВВЕДИТЕ ДЛИНУ ПОСЛЕДОВАТЕЛЬНОСТИ M: ";
    cin >> M;
    cout << " ВВЕДИТЕ ДЛИНУ ПОСЛЕДОВАТЕЛЬНОСТИ N: ";
    cin >> N;
    int arr1[SIZE], arr2[SIZE];

    Random(arr1, M);
    Random(arr2, N);
    cout << " ПОСЛЕДОВАТЕЛЬНОСТЬ M: ";
    print(arr1, M);
    cout << " ПОСЛЕДОВАТЕЛЬНОСТЬ N: ";
    print(arr2, N);

    findUniq(arr1, M, arr2, N);

    system("pause");
}