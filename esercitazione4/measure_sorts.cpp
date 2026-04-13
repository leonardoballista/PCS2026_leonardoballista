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

    for (int n = 2; n <= 13; n++){
        std::vector<int> vi;

        int dim = std::pow(2,n);
        vi.resize(dim);
        rf.fill(vi, -10000, 10000); 

        std::vector<int> vi_b = vi;
        std::vector<int> vi_i = vi;
        std::vector<int> vi_s = vi;
        std::vector<int> vi_d = vi;

        std::cout << "GARA IN " << dim << " DIMENSIONI\n\n";
    
    //BUBBLE SORT
        timecounter tc; /* instantiate the timecounter */
        tc.tic();       /* start it */

        bubble_sort(vi_b);
        
        double secs_b = tc.toc(); /* stop the timecounter, get time and print it */
        std::cout << "Bubble sort: "<< secs_b << " seconds\n";

    //INSERTION SORT
        tc.tic();       /* start it */

        insertion_sort(vi_i);
        
        double secs_i = tc.toc(); /* stop the timecounter, get time and print it */
        std::cout << "Insertion sort: "<< secs_i << " seconds\n";

    //SELECTION SORT
        tc.tic();       /* start it */

        selection_sort(vi_s);
        
        double secs_s = tc.toc(); /* stop the timecounter, get time and print it */
        std::cout << "Selection sort: " << secs_s << " seconds\n";

    //DEFAULT SORT
        tc.tic();       /* start it */

        std::sort(vi_d.begin(), vi_d.end());
        
        double secs_d = tc.toc(); /* stop the timecounter, get time and print it */
        std::cout << "Default sort: "<< secs_d << " seconds\n\n";

    //WINNER
        std::vector<double> time = {secs_b, secs_i, secs_s, secs_d};
        std::sort(time.begin(), time.end());
        if (time[0] == secs_b){std::cout << "VINCITORE: BUBBLE SORT\n\n\n";};
        if (time[0] == secs_i){std::cout << "VINCITORE: INSERTION SORT\n\n\n";};
        if (time[0] == secs_s){std::cout << "VINCITORE: SELECTION SORT\n\n\n";};
        if (time[0] == secs_d){std::cout << "VINCITORE: DEFAULT SORT\n\n\n";};
        
         /* sleep for some time */
        //std::this_thread::sleep_for( std::chrono::milliseconds(1234) );
    }

    return 0;
}