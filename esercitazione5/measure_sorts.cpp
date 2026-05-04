#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>
#include <algorithm>
#include "randfiller.h"
#include "timecounter.h"
#include "sorts.hpp"

int main(void)
{
    randfiller rf;

    for (int n = 1; n <= 100; n++){
        std::vector<int> vi;

        int dim = n;
        vi.resize(dim);
        rf.fill(vi, -10000, 10000); 

        std::vector<int> vi_b = vi;
        std::vector<int> vi_i = vi;
        std::vector<int> vi_s = vi;
        std::vector<int> vi_m = vi;
        std::vector<int> vi_q = vi;
        std::vector<int> vi_d = vi;
        std::vector<int> vi_o = vi;

        std::cout << "GARA IN " << dim << " DIMENSIONI\n\n";
    
    //BUBBLE SORT
        timecounter tc; 
        tc.tic();       

        bubble_sort(vi_b);
        
        double secs_b = tc.toc(); 
        std::cout << "Bubble sort: "<< secs_b << " seconds\n";

    //INSERTION SORT
        tc.tic();       

        insertion_sort(vi_i);
        
        double secs_i = tc.toc(); 
        std::cout << "Insertion sort: "<< secs_i << " seconds\n";

    //SELECTION SORT
        tc.tic();       

        selection_sort(vi_s);
        
        double secs_s = tc.toc(); 
        std::cout << "Selection sort: " << secs_s << " seconds\n";
    
    //MERGE SORT
        tc.tic();       

        merge_sort(vi_m, 0, vi_m.size() - 1);
        
        double secs_m = tc.toc(); 
        std::cout << "Merge sort: " << secs_m << " seconds\n";
    
    //QUICK SORT
        tc.tic();       

        quick_sort(vi_q, 0, vi_q.size() - 1);
        
        double secs_q = tc.toc(); 
        std::cout << "Quick sort: " << secs_q << " seconds\n";

    //OPTIMIZED SORT
        tc.tic();

        opt_sort(vi_o, 0, vi_o.size() - 1);

        double secs_o = tc.toc();
        std::cout << "Optimized sort: " << secs_o << " seconds\n";

    //DEFAULT SORT 
    
        tc.tic(); 
        std::sort(vi_d.begin(), vi_d.end());
        double secs_d = tc.toc();
        std::cout << "Default sort: "<< secs_d << " seconds\n\n"; 

    //WINNER
        std::vector<double> time = {secs_b, secs_i, secs_s, secs_m, secs_q, secs_o, secs_d};
        std::sort(time.begin(), time.end());
        if (time[0] == secs_b){std::cout << "VINCITORE: BUBBLE SORT\n\n\n";};
        if (time[0] == secs_i){std::cout << "VINCITORE: INSERTION SORT\n\n\n";};
        if (time[0] == secs_s){std::cout << "VINCITORE: SELECTION SORT\n\n\n";};
        if (time[0] == secs_m){std::cout << "VINCITORE: MERGE SORT\n\n\n";};
        if (time[0] == secs_q){std::cout << "VINCITORE: QUICK SORT\n\n\n";};
        if (time[0] == secs_o){std::cout << "VINCITORE: OPTIMIZED SORT\n\n\n";};
        if (time[0] == secs_d){std::cout << "VINCITORE: DEFAULT SORT\n\n\n";};
        
         /* sleep for some time */
        //std::this_thread::sleep_for( std::chrono::milliseconds(1234) );
    }

    return 0;
}