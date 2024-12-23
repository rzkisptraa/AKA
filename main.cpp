#include <iostream>
#include "AKA.h"

using namespace std;

int main() {
    int arr[100]; // Asumsi ukuran maksimum 100
    int n;

    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    cout << "Masukkan elemen array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Menampilkan array sebelum diurutkan
    cout << "Array sebelum diurutkan: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Menggunakan Merge Sort
    mergeSort(arr, 0, n - 1);
    cout << "Array setelah diurutkan (Merge Sort): ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Menggunakan Quick Sort
    int arr2[100]; // Array kedua untuk Quick Sort cout << "Masukkan elemen array untuk Quick Sort: ";
    cout << "Masukkan elemen array kedua: ";
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    // Menampilkan array sebelum diurutkan
    cout << "Array sebelum diurutkan (Quick Sort): ";
    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";
    cout << endl;

    // Menggunakan Quick Sort
    quickSort(arr2, 0, n - 1);
    cout << "Array setelah diurutkan (Quick Sort): ";
    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";
    cout << endl;

    // Mencari median
    int median = findMedian(arr, n);
    cout << "Median dari array: " << median << endl;

    return 0;
}
