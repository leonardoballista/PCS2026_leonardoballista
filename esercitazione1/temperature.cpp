#include <fstream> 
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
    if (argc < 2) {
        cout << "Errore: devi inserire il nome del file.\n";
        return 1;
    }
    string filename = argv[1];
    ifstream ifs(filename);
    if (ifs.is_open()){
        string city;
            double temp00;
            double temp06;
            double temp12;
            double temp18;
            double media;
        while (ifs >> city >> temp00 >> temp06 >> temp12 >> temp18) {
            media = (temp00 + temp06 + temp12 + temp18) / 4.0;
            cout << city << " " << media << "\n";    
        }
        ifs.close();
    }
    else { 
        cout << "Impossibile aprire il file" << filename << "\n";
    }
    return 0;
}