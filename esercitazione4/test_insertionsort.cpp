#include <iostream>
#include <vector>
#include "randfiller.h"
#include "sorts.hpp"

int main(void){
    randfiller rf;
    for (int i = 0; i < 100; i++){

        std::vector<int> vi;
        int n = rand() %991 + 10;
        vi.resize(n);
        rf.fill(vi, -10000, 10000); 
        insertion_sort(vi);
        if (is_sorted(vi) == false){
            std::cout << "WARNING! L'algoritmo insertion sort non ha funzionato correttamente!" << "\n";
            return EXIT_FAILURE;
        }

        std::vector<float> vf;
            n = rand() %991 + 10;
            vf.resize(n);
            rf.fill(vf, -100.5f, 1000.5f); 
            insertion_sort(vf);
            if (is_sorted(vf) == false){
                std::cout << "WARNING: L'algoritmo insertion sort non ha funzionato correttamente!" << "\n";
                return EXIT_FAILURE;
            }
        
        std::vector<double> vd;
            n = rand() %991 + 10;
            vd.resize(n);
            rf.fill(vd, -500.5, 750.5); 
            insertion_sort(vd);
            if (is_sorted(vd) == false){
                std::cout << "WARNING: L'algoritmo insertion sort non ha funzionato correttamente!" << "\n";
                return EXIT_FAILURE;
            }
    }
    
    std::vector<std::string> vs = {"astronave", "casa", "laura", "quantitativamente", "balestra", "federico", "cetriolo", "zanzara", "vetta", "riposare"};
            insertion_sort(vs);
            print_vector(vs);
            if (is_sorted(vs) == false){
                std::cout << "WARNING: L'algoritmo insertion sort per le stringhe non ha funzionato correttamente!" << "\n";
                return EXIT_FAILURE;
            }

    std::cout << "SUCCESS! L'algoritmo insertion sort ha ordinato i vettori correttamente" << "\n";
    return EXIT_SUCCESS;
}