#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <cmath>
#include <algorithm>
#include "randfiller.h"
#include "timecounter.h"
#include "sorts.hpp"

int main(void){
    randfiller rf;
    int const dim = 100; //lunghezza vettore di vettori

    std::ofstream file_dati("risultati_benchmark_release.csv");
    
    file_dati << "Dimensione,Tempo_Insertion,Tempo_Quick,Tempo_Optimized,Tempo_Standard\n";

    for(int n = 1; n < 101; n++){

    std::vector<std::vector<int>> vi;
    vi.resize(dim);
    for(int i = 0; i < dim; i++){
        vi[i].resize(n); //dimensione vettore componente [i]
        rf.fill(vi[i], -10000, 10000);
    }

    std::vector<std::vector<int>> vi_i = vi;
    std::vector<std::vector<int>> vi_q = vi;
    std::vector<std::vector<int>> vi_o = vi;
    std::vector<std::vector<int>> vi_d = vi;

    timecounter tc;
    tc.tic();

    for(int i=0; i < vi_i.size(); i++){
        insertion_sort(vi_i[i]);
    }

    double secs_i = tc.toc();
    std::cout << "Tempo medio per insertion sort in " << n << " dimensioni: " << secs_i/dim << "seconds \n";


    tc.tic();

    for(int q=0; q < vi_q.size(); q++){
        quick_sort(vi_q[q], 0, vi_q[q].size() - 1);
    }

    double secs_q = tc.toc();
    std::cout << "Tempo medio per quick sort in " << n << " dimensioni: " << secs_q/dim << "seconds \n\n\n";


    tc.tic();

    for(int o=0; o < vi_o.size(); o++){
        opt_sort(vi_o[o], 0, vi_o[o].size() - 1);
    }

    double secs_o = tc.toc();
    std::cout << "Tempo medio per optimized sort in " << n << " dimensioni: " << secs_o/dim << "seconds \n";

    tc.tic();

    for(int i=0; i < vi_i.size(); i++){
        std::sort(vi_d[i].begin(), vi_d[i].end());
    }

    double secs_d = tc.toc();
    std::cout << "Tempo medio per standard sort in " << n << " dimensioni: " << secs_d/dim << "seconds \n";

    file_dati << n << "," << secs_i/dim << "," << secs_q/dim << "," << secs_o/dim << "," << secs_d/dim << "\n";

    }

    file_dati.close(); //Mi sono aiutato con Gemini per generare il file .csv contenente i tempi misurati
    std::cout << "Dati esportati con successo in risultati_benchmark_release.csv\n"; 
    return 0;
}