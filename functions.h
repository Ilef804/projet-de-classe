double Loss(double yi, double y) {

    return -((yi * log(y)) + ((1 - yi) * log(1 - y)));
}

double deriveeLoss(double yi, double y, double xi) {

    return (y - yi) * xi;//c'est la simplification de la formule de derivee de loss par rapport a w
}

// Fonction d'activation Sigmoïd(2)
double sigmoid(double x) {
    return 1/(1 + exp(-x));
}
