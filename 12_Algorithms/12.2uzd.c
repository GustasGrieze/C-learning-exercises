#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int comparisonsBubble = 0, assignmentsBubble = 0;
int comparisonsQuick = 0, assignmentsQuick = 0;
int comparisonsInsertion = 0, assignmentsInsertion = 0;
int comparisonsSelection = 0, assignmentsSelection = 0;
int comparisonsMerge = 0, assignmentsMerge = 0;
double timeBubble = 0.0, timeQuick = 0.0, timeInsertion = 0.0, timeSelection = 0.0, timeMerge = 0.0;


void fillArrayWithRandomData(int *array, int size);
int isSorted(int *array, int size);
void bubbleSort(int *array, int size);
int partition(int *array, int low, int high);
void quickSort(int *array, int low, int high);
void insertionSort(int *array, int size);
void selectionSort(int *array, int size);
void mergeSort(int *array, int l, int r);
void runSortsAndPrintResults(int *array, int size, int numberOfExperiments);
void resetCounters();

int main() {
    const int ARRAY_SIZE = 100;
    const int NUMBER_OF_EXPERIMENTS = 10;

    int array[ARRAY_SIZE];
    fillArrayWithRandomData(array, ARRAY_SIZE);

    runSortsAndPrintResults(array, ARRAY_SIZE, NUMBER_OF_EXPERIMENTS);

    return 0;
}

void fillArrayWithRandomData(int *array, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

int isSorted(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void bubbleSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            comparisonsBubble++;
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                assignmentsBubble += 3;
            }
        }
    }
}

int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        comparisonsQuick++;
        if (array[j] < pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            assignmentsQuick += 3;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    assignmentsQuick += 3;
    return (i + 1);
}

void quickSort(int *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void insertionSort(int *array, int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        comparisonsInsertion++;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
            assignmentsInsertion++;
            comparisonsInsertion++;
        }
        array[j + 1] = key;
        assignmentsInsertion++;
    }
}

void selectionSort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            comparisonsSelection++;
            if (array[j] < array[min_idx]) {
                min_idx = j;
            }
        }
        int temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;
        assignmentsSelection += 3;
    }
}

void merge(int *array, int l, int m, int r) {
  int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        comparisonsMerge++;
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
        assignmentsMerge++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
        assignmentsMerge++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
        assignmentsMerge++;
    }
}

void mergeSort(int *array, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}

void runSortsAndPrintResults(int *array, int size, int numberOfExperiments) {
    int *tempArray = malloc(size * sizeof(int));
    if (tempArray == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    resetCounters();

    for (int exp = 0; exp < numberOfExperiments; exp++) {
        fillArrayWithRandomData(array, size);

        // Bubble Sort
        memcpy(tempArray, array, size * sizeof(int));
        resetCounters();
        clock_t startBubble = clock();
        bubbleSort(tempArray, size);
        clock_t endBubble = clock();
        timeBubble += ((double)(endBubble - startBubble)) / CLOCKS_PER_SEC;

        // Quick Sort
        memcpy(tempArray, array, size * sizeof(int));
        resetCounters();
        clock_t startQuick = clock();
        quickSort(tempArray, 0, size - 1);
        clock_t endQuick = clock();
        timeQuick += ((double)(endQuick - startQuick)) / CLOCKS_PER_SEC;

        // Insertion Sort
        memcpy(tempArray, array, size * sizeof(int));
        resetCounters();
        clock_t startInsertion = clock();
        insertionSort(tempArray, size);
        clock_t endInsertion = clock();
        timeInsertion += ((double)(endInsertion - startInsertion)) / CLOCKS_PER_SEC;

        // Selection Sort
        memcpy(tempArray, array, size * sizeof(int));
        resetCounters();
        clock_t startSelection = clock();
        selectionSort(tempArray, size);
        clock_t endSelection = clock();
        timeSelection += ((double)(endSelection - startSelection)) / CLOCKS_PER_SEC;

        // Merge Sort
        memcpy(tempArray, array, size * sizeof(int));
        resetCounters();
        clock_t startMerge = clock();
        mergeSort(tempArray, 0, size - 1);
        clock_t endMerge = clock();
        timeMerge += ((double)(endMerge - startMerge)) / CLOCKS_PER_SEC;
    }

    // Print average results for each algorithm
    printf("Bubble Sort\t\t%d\t\t%d\t\t%.6f\n", comparisonsBubble / numberOfExperiments, assignmentsBubble / numberOfExperiments, timeBubble / numberOfExperiments);
    printf("Quick Sort\t\t%d\t\t%d\t\t%.6f\n", comparisonsQuick / numberOfExperiments, assignmentsQuick / numberOfExperiments, timeQuick / numberOfExperiments);
    printf("Insertion Sort\t\t%d\t\t%d\t\t%.6f\n", comparisonsInsertion / numberOfExperiments, assignmentsInsertion / numberOfExperiments, timeInsertion / numberOfExperiments);
    printf("Selection Sort\t\t%d\t\t%d\t\t%.6f\n", comparisonsSelection / numberOfExperiments, assignmentsSelection / numberOfExperiments, timeSelection / numberOfExperiments);
    printf("Merge Sort\t\t%d\t\t%d\t\t%.6f\n", comparisonsMerge / numberOfExperiments, assignmentsMerge / numberOfExperiments, timeMerge / numberOfExperiments);

    free(tempArray);
}


void resetCounters() {
    comparisonsBubble = assignmentsBubble = 0;
    timeBubble = 0.0;

    comparisonsQuick = assignmentsQuick = 0;
    timeQuick = 0.0;

    comparisonsInsertion = assignmentsInsertion = 0;
    timeInsertion = 0.0;

    comparisonsSelection = assignmentsSelection = 0;
    timeSelection = 0.0;

    comparisonsMerge = assignmentsMerge = 0;
    timeMerge = 0.0;
}

