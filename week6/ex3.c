#include <stdio.h>
#define PROCESSES 30

/*
 * Compare & Contrast:
 *
 * Seeing the results, we cannot say that one particular scheduling algorithm is better than some other, becuase it depends on defined priorities and specifications of that system.
 *
 * If our goal is for example to maximize throughput, than the most effective algorithm would be "Shortest Job First",
 * on the other hand if we want to make sure that the CPU time will be fairly distributed, than the preemptive could be better choice.
 * The Round Robin is good algorithm if is our goal to avoid starvation.
 * */

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

void calculateWaitingTime(int wT[], int aT[], int bT[], int n, int q) {

    int rem[PROCESSES];
    for (int i = 0; i < n; i++) {
        rem[i] = bT[i];
    }
    int timer = aT[0];
    int undone = n;

    while(undone !=0) {
        for (int i = 0; i < n; i++) {

            if (rem[i] == 0) { // process is done
                continue;
            } else if (rem[i] > 0 && aT[i] <= timer) { // still pending
                if (rem[i] > q) {
                    timer += q;
                    rem[i] = rem[i] - q;
                    if (rem[i] < 0) {
                        rem[i] = 0;
                    }
                } else { // the process has been done
                    undone--;
                    timer = timer + rem[i];
                    wT[i] = timer - bT[i] - aT[i];
                    if (wT[i] < 0) {
                        wT[i] = 0;
                    }
                    rem[i] = 0;
                }
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
    int quantum;
    printf("How many processes are there?\n");
    scanf_s("%d", &n);
    printf("What is the quantum?\n");
    scanf_s("%d", &quantum);

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

    calculateWaitingTime(waitingT, arrivalT, burstT, n, quantum);
    calculateTurnaroundTime(turnaroundT, burstT, waitingT, n);
    calculateCompletionTime(completationT, turnaroundT, arrivalT, n);

    printResults(burstT, arrivalT, completationT, waitingT, turnaroundT, n, avgArr(waitingT, n), avgArr(turnaroundT, n));

    return 0;
}



