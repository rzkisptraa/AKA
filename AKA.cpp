#include "AKA.h"
#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Membuat array sementara
    int leftArr[100], rightArr[100]; // Asumsi ukuran maksimum 100

    // Menyalin data ke array sementara
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Menggabungkan array sementara ke dalam array asli
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Menyalin elemen yang tersisa dari leftArr
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Menyalin elemen yang tersisa dari rightArr
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Fungsi rekursif untuk melakukan Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Memecah array menjadi dua bagian
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Menggabungkan bagian-bagian yang sudah diurutkan
        merge(arr, left, mid, right);
    }
}

// Fungsi untuk melakukan Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Memilih pivot
    int i = (low - 1); // Indeks elemen yang lebih kecil

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // Menggunakan variabel sementara untuk pertukaran
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Menggunakan variabel sementara untuk pertukaran pivot
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Mengurutkan elemen sebelum dan sesudah partisi
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fungsi untuk mencari median
int findMedian(int arr[], int n) {
    // Mengurutkan array menggunakan Merge Sort
    mergeSort(arr, 0, n - 1);

    // Jika jumlah elemen genap
    if (n % 2 == 0) {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2;
    } else {
        return arr[n / 2];
    }
}
