// MULTIDIMENSIONES.cpp: define el punto de entrada de la aplicación.
//

#include "MULTIDIMENSIONES.h"

#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;



double distanciaEuclediana(vector<int>& sds1, vector<int>& sds2) {
    double distancia = 0.0;
    for (int i = 0; i < int(sds1.size()); i++) {
        distancia += pow(sds1[i] - sds2[i], 2);
    }
    return sqrt(distancia);
}

void setter(vector<vector<int>>& datos, int N, int dimensions) {
    datos.resize(N);
    for (auto& sdst : datos) {
        for (int i = 0; i < dimensions; i++) {
            sdst.push_back(rand() % 1000 + 500);
        }
    }
}

double tomarTiempo(vector<vector<int>>& datos) {
    unsigned t0, t1;

    t0 = clock();

    for (auto& sdst : datos) {
        for (auto& sdst_o : datos) {
            distanciaEuclediana(sdst, sdst_o);
        }
    }

    t1 = clock();

    return (double(t1 - t0) / CLOCKS_PER_SEC) * 1000.0;
}

int main() {
    srand(time(NULL));
    vector<vector<vector<int>>> VECTORES;
    int tams[4] = { 10000,15000,20000,25000 };
    int dims[4] = { 5,10,15,20 };
    for (int tam = 0; tam < 4; tam++) {
        for (int dim = 0; dim < 4; dim++) {
            vector<vector<int>> DS;
            setter(DS, tams[tam], dims[dim]);
            VECTORES.push_back(DS);
        }
    }

    for (auto& svec : VECTORES) {
        cout << "TIEMPO (" << int(svec.size()) << "," << int(svec[0].size()) << "): " << tomarTiempo(svec) << endl;
    }
    system("pause");
    return 0;
}
