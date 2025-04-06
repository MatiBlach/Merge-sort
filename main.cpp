#include <iostream>
#include <cstring>
using namespace std;


int compare(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 < len2)
        return -1;
    else if (len1 > len2)
        return 1;
    else
        return strcmp(str1, str2);
}

void merge(char** T, int p, int q, int r) {
    int i, j, k;
    int l_size = q - p + 1;
    int r_size = r - q;

    char** L = new char* [l_size];
    char** R = new char* [r_size];

    for (i = 0; i < l_size; i++)
        L[i] = T[p + i];
    for (j = 0; j < r_size; j++)
        R[j] = T[q + 1 + j];

    i = 0;
    j = 0;
    k = p;
    while (i < l_size && j < r_size) {
        if (compare(L[i], R[j]) <= 0) {
            T[k] = L[i];
            i++;
        }
        else {
            T[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < l_size) {
        T[k] = L[i];
        i++;
        k++;
    }

    while (j < r_size) {
        T[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(char** T, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(T, p, q);
        mergeSort(T, q + 1, r);
        merge(T, p, q, r);
    }
}

int main() {
    int N;
    cin >> N;

    char** liczby = new char*[N];

    for (int i = 0; i < N; i++) {
        liczby[i] = new char[100];
        cin >> liczby[i];
    }

    mergeSort(liczby, 0, N - 1);

    for (int i = 0; i < N; i++)
        cout << liczby[i] << endl;

    for (int i = 0; i < N; i++)
        delete[] liczby[i];

    delete[] liczby;

    return 0;
}
