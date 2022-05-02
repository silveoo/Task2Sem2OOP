#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void rev(int*);
void sortRev(int*);
void sort(int*);
void (*check(int*))(int*);

int main()
{
    setlocale(LC_ALL, "rus");
    int* mas = new int[10];
    cout << "Сгенерированный массив:    [";
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int temp = 1 + rand() % 100;
        mas[i] = temp;
        if (i == 9) {
            cout << temp;
        }
        else {
            cout << temp << " ";
        }
    }
    cout << "]\n" << endl;

    void(*call)(int*);
    call = check(mas);
    call(mas);
    cout << "Отсортированный массив:    [";
    for (int i = 0; i < 10; i++)
    {
        if (i == 9) {
            cout << mas[i];
        }
        else {
            cout << mas[i] << " ";
        }
    }
    cout << ']' << endl;
    return 0;
}


void (*check(int* list))(int*)
{
    void (*pattern)(int*);
    int temp = 0;
    for (int i = 0; i < 10; i++)
    {
        temp += list[i];
    }
    if (temp == list[0]) {
        pattern = rev;
    }
    else if (temp > list[0]) {
        pattern = sortRev;
    }
    else {
        pattern = sort;
    }
    return pattern;
}

void rev(int* list) {
    int temp[10];
    for (int i = 0; i < 10; i++) { temp[i] = list[i]; }
    for (int i = 0; i < 10; i++) { list[i] = temp[4 - i]; }
}

void sort(int* list) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (list[j] < list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

void sortRev(int* list) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (list[j] > list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
