#include <stdio.h>


int main(void) {
    int res = 3, proc = 5; //res and proc
    int is_finished = 0;

    int resNum[3]; // number of resource
    int availableRes[3]; // number of available resources

    int c[5][3];
    int r[5][3];

    FILE* input_file = fopen("C:\\Users\\42072\\OneDrive\\Documents\\Innopolis\\OperatingSystems\\Labs\\13\\input_ok.txt", "r");
    FILE* output = fopen("ex1_output.txt", "w");
    int current;

    int n = 1;
    int a = 0;

    int unoccupiedREs[5]; // unoccupied resources
    for(int i = 0; i < proc; i++){
        unoccupiedREs[i] = 0;
    }

    for(int i=0; i < res; i++){
        fscanf(input_file, "%d", &current);
        resNum[i] = current;
    }

    for(int i=0; i < res; i++){
        fscanf(input_file, "%d", &current);
        availableRes[i] = current;
    }

    for(int i=0; i < proc; i++){
        for(int j=0; j < res; j++){
            fscanf(input_file, "%d", &current);
            c[i][j] = current;

        }
    }

    for(int i=0; i < proc; i++){
        for(int j=0; j < res; j++){
            fscanf(input_file, "%d", &current);
            r[i][j] = current;
        }
    }


    while(n == 1){
        n = 0;

        for(int i = 0; i < proc; i++){
            a = 0;
            for(int j = 0; j < res; j++){
                if(r[i][j] <= availableRes[j]){
                    a++;
                }
            }
            if(a == res && unoccupiedREs[i] == 0){
                for(int pg = 0; pg < res; pg++){
                    availableRes[pg] += c[i][pg];
                }
                n=1;

                unoccupiedREs[i] = 1;
            }
        }

    }
    int hgh = 1;
    for(int i = 0; i < proc; i++){
        if(unoccupiedREs[i] == 0){
            hgh = 0;
            fprintf(output, "There has occured a deadlock in process %d \n", i);
        }
    }
    if(hgh == 1){
        fprintf(output, "No deadlock detected\n");
    }
    return 0;
}