#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include"functions.h"
#include"struct.h"
#include"train.h"
#include <time.h>


int main() {
    double dataset[110][3]; // enregistrer dataset de excel dans une matrice
    int row = 0;

    FILE *file = fopen("datacsv.csv", "r");
    if (file == NULL) {
        printf("Error\n");
        return 0;
    }

    char ligne[100];
    while (fgets(ligne, sizeof(ligne), file)) {
        char *token = strtok(ligne, ",");
        int col = 0;
        while (token != NULL && col < 3) {
            dataset[row][col] = atof(token);
            token = strtok(NULL, ",");
            col++;
        }
        row++;
    }
    printf("the file contains:\n");
       for (int i = 0; i < row; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%f\t", dataset[i][j]);
        }
        printf("\n");
    }

    fclose(file);

    // Initialisation du neurone

    double w1, w2, bias;
    srand(time(NULL));

    //  between -1 and 1
    w1 = ((double)rand() / (double)RAND_MAX) * 2.0 - 1.0;
    w2 = ((double)rand() / (double)RAND_MAX) * 2.0 - 1.0;
    bias = ((double)rand() / (double)RAND_MAX) * 2.0 - 1.0;

    printf("Randomly generated weights:\n");
    printf("w1 = %.6f\n", w1);
    printf("w2 = %.6f\n", w2);
    printf("Randomly generated bias:\n");
    printf("bias = %.6f\n", bias);

        Neurone neurone;
        neurone.w1=w1;neurone.w2=w2;neurone.biais=bias;

    double tauxApprentissage = 0.001;

    // Entraînement du neurone
        entrainerNeurone(&neurone, dataset,tauxApprentissage);

    printf("after training\n");
    printf("weight 1\n%f\n", neurone.w1);
    printf("weight 2\n%f\n", neurone.w2);
    printf("bias\n%f\n", neurone.biais);
//tester la neurone :
    printf("verify results with new weights\n");

int x=0;
for (int i = 0; i < 100; i++) {
            double x1 = dataset[i][0];
            double x2 = dataset[i][1];
            double yi = dataset[i][2];

            double y = sigmoid(x1 * neurone.w1 + x2 * neurone.w2 + neurone.biais);
            y=round(y);
            printf("\n",y);
    printf("expected %.f\t",y);
        printf("actually %.f\t",yi);
if(yi==y){
    x++;
}

}    printf("\n");

    printf("\t\t\t\t\t%d/100 are correctly expected \t",x);

printf("\n");
    return 0;
}
