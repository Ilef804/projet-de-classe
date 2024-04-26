#include"struct.h"
void entrainerNeurone(Neurone *neurone, double dataset[][3], double tauxApprentissage) {
    double currentLoss;
    int maxEpochs = 1000;
    int epoch = 0;

    while (epoch < maxEpochs) {
        currentLoss = 0.0;

        for (int i = 0; i < 100; i++) {
            double x1 = dataset[i][0];
            double x2 = dataset[i][1];
            double yi = dataset[i][2];

            double y = sigmoid(x1 * neurone->w1 + x2 * neurone->w2 + neurone->biais);

            currentLoss += Loss(yi, y);

            neurone->w1 -= tauxApprentissage * deriveeLoss(yi, y, x1);
            neurone->w2 -= tauxApprentissage * deriveeLoss(yi, y, x2);
            neurone->biais -= tauxApprentissage * (y - yi);
        }

        currentLoss /= 100;
        if (currentLoss < 0.01) {
            break;
        }

        epoch++;
    }
}
