#include <concepts>
#include <iostream>
#include <ostream>
#include "rational.hpp"

int main(void){
    int a1 = 0;
    int b1 = 0;
    int a2 = 34;
    int b2 = 12;

    rational<int> r1(a1,b1);
    rational<int> r2(a2,b2);
    rational<int> R = r1 + r2;
    rational<int> P = r1 * r2;
    rational<int> D = r1 / r2;

    rational<int> frazioni[5] = {r1, r2, R, P, D};

    for (int i=0; i<5; i++){
        int a = frazioni[i].num();
        int b = frazioni[i].den();
        int res = 1;
        if(b != 0){
            while(res != 0){
            res = a % b;
            a = b;
            b = res;
        }
        int mcd = a;
        int nuovo_num = frazioni[i].num() / mcd;
        int nuovo_den = frazioni[i].den() / mcd;
        
        frazioni[i] = rational<int>(nuovo_num, nuovo_den);
        } 
    }

    if (r1.num() == r1.den() && r1.num() != 0){
        std::cout << a1 << "/" << b1 << " = " << 1 << "\n";
    }

    else if (r1.num() == -r1.den() && r1.num() != 0){
        std::cout << a1 << "/" << b1 << " = " << -1 << "\n";
    }

    else{
        if (r1.den() == 1){
            std::cout << a1 << "/" << b1 << " = " << r1.num() << "\n";
        }
        else{
            std::cout << a1 << "/" << b1 << " = " << r1 << "\n";
        }
    }

    if (r2.num() == r2.den() && r2.num() != 0){
        std::cout << a2 << "/" << b2 << " = " << 1 << "\n";
    }

    else if (r2.num() == -r2.den() && r2.num() != 0){
        std::cout << a2 << "/" << b2 << " = " << -1 << "\n";
    }

    else{
        if (r2.den() == 1){
            std::cout << a2 << "/" << b2 << " = " << r2.num() << "\n";
        }
        else{
            std::cout << a2 << "/" << b2 << " = " << r2 << "\n";
        }
    }

    if (R.num() == R.den() && R.num() != 0){
        std::cout << r1 << " + " << r2 << " = " << 1 << "\n";
    }

    else if (R.num() == -R.den() && R.num() != 0){
        std::cout << r1 << " + " << r2 << " = " << -1 << "\n";
    }

    else{
        if (R.den() == 1){
            std::cout << r1 << " + " << r2 << " = " << R.num() << "\n";
        }
        else{
            std::cout << r1 << " + " << r2 << " = " << R << "\n";
        }
    }

    if (P.num() == P.den() && P.num() != 0){
        std::cout << r1 << " * " << r2 << " = " << 1 << "\n";
    }

    else if (P.num() == -P.den() && P.num() != 0){
        std::cout << r1 << " * " << r2 << " = " << -1 << "\n";
    }

    else{
        if (P.den() == 1){
            std::cout << r1 << " * " << r2 << " = " << P.num() << "\n";
        }
        else{
            std::cout << r1 << " * " << r2 << " = " << P << "\n";
        }
    }

    if (D.num() == D.den() && D.num() != 0){
        std::cout << r1 << " / " << r2 << " = " << 1 << "\n";
    }

    else if (D.num() == -D.den() && D.num() != 0){
        std::cout << r1 << " / " << r2 << " = " << -1 << "\n";
    }

    else{
        if (D.den() == 1){
            std::cout << r1 << " / " << r2 << " = " << D.num() << "\n";
        }
        else{
            std::cout << r1 << " / " << r2 << " = " << D << "\n";
        }
    }
}


