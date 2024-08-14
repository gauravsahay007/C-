#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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

    insertionSort(arr, num_elements);

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
