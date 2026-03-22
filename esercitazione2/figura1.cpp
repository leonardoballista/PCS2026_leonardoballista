#include <iostream> 

int main(){
    double ad[4] = {0.0, 1.1, 2.2, 3.3};
    float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    int ai[3] = {0, 1, 2};
    
    int x = 1;
    float y = 1.1;

    (&y)[1] = 0;

    std::cout << x << "\n"; //0

    for (int i = 0; i < 4; i++){
        std::cout << "Indirizzo di ad[" << i << "]: " << &ad[i] << " " << "Valore: " << ad[i] << "\n";
    }

    // posizione ad[1] all'ultima esecuzione: 140.735.210.483.248 in dec, 7FFF 783A 6E30 in hex
    // "       " ad [2] "                   " 140.735.210.483.256 in dec, 7FFF 783A 6E38 in hex
    //...


    std::cout << "\n";

    for (int i = 0; i < 8; i++){
        std::cout << "Indirizzo di af[" << i << "]: " << &af[i] << " " << "Valore: " << af[i] << "\n";
    }

    // posizione af[1] all'ultima esecuzione: 140.735.210.483.216 in dec, 7FFF 783A 6E10 in hex
    // posizione af[2] all'ultima esecuzione: 140.735.210.483.220 in dec, 7FFF 783A 6E14 in hex
    //...

    std::cout << "\n";

    std::cout << &x << "\n"; //posizione x all'ultima esecuzione: 140.735.210.483.200 in dec, 7FFF 783A 6E00 in hex
    std::cout << &y << "\n"; //posizione y all'ultima esecuzione: 140.735.210.483.196 in dec, 7FFF 783A 6DFC in hex
    std::cout << (&y)[1] << "\n"; //0
    std::cout << "\n";

    return 0;
}