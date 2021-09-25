#include <stdio.h>
#define PROCESSES 30

/**
 * Sort by arrival time
 */

void sortByArrivalTime(int burst[], int arrival[], int n){
    for(int i = 0; i < n - 1; i ++){
        int j = i + 1;
        int current = arrival[j];
        int currentB = burst[j];
        while(current < arrival[j - 1] && j > 0){
            arrival[j] = arrival[j - 1];
            burst[j] = burst[j-1];
            j--;
        }
        arrival[j] = current;
        burst[j] = currentB;
    }
}

/* printing function*/
void print_array(int size, int *param_array){
    printf("%d", param_array[0]);
    for(int i = 1; i < size; i++){
        printf("\t%d", param_array[i]);
    }
}

void calculateWaitingTime(int wT[], int aT[], int bT[], int n){
    for(int i = 0; i < n; i++){
        if(i == 0){
            wT[i] = 0;
        }
        else{
            int bNet = aT[0];
            for(int j = 0; j < i; j++){
                bNet += bT[j];
            }
            wT[i] = bNet - aT[i];
            if(wT[i] < 0){
                wT[i] = 0;
            }
        }
    }
}

void calculateTurnaroundTime(int taT[], int bT[], int wT[], int n){
    for(int i = 0; i < n; i++){
        taT[i] = bT[i] + wT[i];
    }
}

void calculateCompletionTime(int cT[], int taT[], int aT[], int n){
    for(int i = 0; i < n; i++){
        cT[i] = taT[i] + aT[i];
    }
}

float avgArr(int arr[], int n){
    float sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    return(sum / n);
}

void printResults(int bT[], int aT[], int cT[], int wT[], int taT[], int n, float avTat, float avWt){
    printf("-------------------------------------------------------------------------------------------------------\n");
    printf("\t Process id \t Arrival Time \t Burst Time \t Completion Time \t Waiting Time \t Turnaround Time \n");
    for(int i = 0; i < n; i++){
        printf("\t %d \t %d \t %d \t %d \t %d \t %d \n", i, aT[i], bT[i], cT[i], wT[i], taT[i]);
    }
    printf("-------------------------------------------------------------------------------------------------------\n");
    printf("\t Average: \t \t \t \t %f \t %f \n", avTat, avWt);
}

int main() {

    int n;
    printf("How many processes are there?\n");
    scanf_s("%d", &n);

    int burstT[PROCESSES];
    int arrivalT[PROCESSES];
    int completationT[PROCESSES];
    int waitingT[PROCESSES];
    int turnaroundT[PROCESSES];

    for(int i = 0; i < n; i++){
        printf("What is the burst time for the %d process?\n", i);
        scanf_s("%d", &burstT[i]);
        printf("What is the arrival time for the %d process?\n", i);
        scanf_s("%d", &arrivalT[i]);
    }

    sortByArrivalTime(burstT, arrivalT, n);

    /*print_array(n, arrivalT);
    printf("\n");
    print_array(n, burstT);*/

    calculateWaitingTime(waitingT, arrivalT, burstT, n);
    calculateTurnaroundTime(turnaroundT, burstT, waitingT, n);
    calculateCompletionTime(completationT, turnaroundT, arrivalT, n);

    printResults(burstT, arrivalT, completationT, waitingT, turnaroundT, n, avgArr(waitingT, n), avgArr(turnaroundT, n));

    return 0;
}
