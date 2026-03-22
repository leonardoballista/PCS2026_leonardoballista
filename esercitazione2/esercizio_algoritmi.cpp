#include <iostream>
#include <cmath>
#include <algorithm>

static const int N = 10;
double arr[N] = {1.2, 4.5, 12.4, 65.3, 128.23, 5.1, 0.2, 0.001, 16.16, 2.4};
double min = arr[0];
double max = arr[1];
double sum = 0.0;
double varx = 0.0;
int itermax = 50;

int main(){
    for (int i = 0; i < N; i++){
        double el = arr[i];
        if (el < min) {
            min = el;
        }
    }

    std::cout << "Il minimo del vettore è: " << min << "\n";

    for (int i = 0; i < N; i++){
        double el = arr[i];
        if (el > max) {
            max = el;
        }
    }

    for (int i = 0; i < N; i++){
        double el = arr[i];
        sum = sum + el;
    }
    double cmean = sum/N;

    for (int i = 0; i < N; i++){
        double sqdiff = (arr[i] - cmean)*(arr[i] - cmean);
        varx = varx + sqdiff;
    }

    double stdev = sqrt(varx/(N-1)); //Uso lo stimatore non distorto della varianza campionaria

    for (int i = 0; i < itermax; i++){
        for (int k = 1; k < N; k++){
            if (arr[k] < arr[k-1]) {
                //inizialmente avevo scritto:
              //arr[k]=arr[k-1];
              //arr[k-1] = arr[k];
                //senza accorgermi che l'elemento arr[k] andava perso e di conseguenza arr[k-1] e arr[k] avevano lo stesso valore. Ho corretto l'errore chiedendo a Gemini...
                double t = arr[k];
                arr[k] = arr[k-1];
                arr[k-1] = t;
            }
        }
    } //potrei fare in modo che il ciclo finisca non appena il vettore è ordinato con un do-while al posto di usare la condizione i < itermax, in modo da rendere l'algoritmo più efficiente
    std::cout << "Il massimo del vettore è: " << max << "\n";
    std::cout << "La deviazione standard del campione è: " << stdev << "\n";
    std::cout << "La varianza del campione è: " << varx/(N-1) << "\n";
    std::cout << "Il vettore ordinato è: ";
    for (int n = 0; n < N; n++) {
        std::cout << arr[n] << " ";
    }
    return 0;
}




