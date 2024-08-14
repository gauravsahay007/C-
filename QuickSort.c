#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    quickSort(arr, 0, num_elements - 1);

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
