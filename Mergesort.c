#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    FILE* input_file = fopen("unsorted_data.txt", "r");
    if (input_file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    int MAX_SIZE = 1000; // Adjust this according to your requirements
    int arr[MAX_SIZE];
    int num_elements = 0;

    while (fscanf(input_file, "%d", &arr[num_elements]) != EOF) {
        num_elements++;
    }

    fclose(input_file);

    mergeSort(arr, 0, num_elements - 1);

    FILE* output_file = fopen("sorted_data.txt", "w");
    if (output_file == NULL) {
        printf("Error creating output file.\n");
        return 1;
    }

    for (int i = 0; i < num_elements; i++) {
        fprintf(output_file, "%d ", arr[i]);
    }

    fclose(output_file);

    printf("Data sorted and written to sorted_data.txt successfully.\n");

    return 0;
}
