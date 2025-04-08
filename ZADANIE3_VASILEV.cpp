#include<iostream>
#include<ctime>
using namespace std;

struct Node
{
    char data;
    Node* next;
};

void fillP(Node*&);
void printP(Node*);
void findPtrElemCInLinst(Node*, char);
void deleteList(Node*&);

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(nullptr));
    Node* P = nullptr;
    fillP(P);
    cout << "Список: ";
    printP(P);
    cout << "\n";
    char C;
    cout << "Введите значение С: ";
    cin >> C;
    findPtrElemCInLinst(P, C);
    deleteList(P);
    system("pause");
    return 0;
}
void fillP(Node*& P)
{
    int sizeP;
    cout << "Введите размер списка: ";
    cin >> sizeP;
    cout << "\n";
    for (size_t count = 0; count < sizeP; count++)
    {
        char newCharElem = (rand() % (126 - 32 + 1)) + 32;
        Node* NewTempVar = new Node{ newCharElem, P };
        P = NewTempVar;
    }
}
void printP(Node* P)
{
    Node* current = P;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
}
void findPtrElemCInLinst(Node* head, char C)
{
    bool flag = true;
    cout << "Вот адресса элементов списка, которые совподают с C";
    cout << "\nАдреса: ";
    while (head != nullptr)
    {
        if ((head->data == C))
        {
            cout << head << " ";
            head = head->next;
            flag = false;
        }
        else
        {
            head = head->next;
        }
    }
    if (flag)
    {
        cout << "такого элемента нет в списке!!!";
    }
}
void deleteList(Node*& head)
{
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}
