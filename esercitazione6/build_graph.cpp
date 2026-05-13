#include <iostream>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include "graph.hpp"

int main(void){
    unidirected_graph<int> grafo;

    std::vector<int> nodi = {12, 5, 18, 2, 9, 20, 14, 7, 3, 11, 16, 1, 8, 19, 4, 15, 10, 6, 17, 13, 5, 12, 8, 2, 19, 14, 7, 20, 1, 9};

    for (int i = 0; i < nodi.size() - 3; i++){
        for(int j = i; j < nodi.size() - 3; j++){
            grafo.add_edge(nodi[i], nodi[j+3]);
        }
    }

    std::vector<unidirected_edge<int>> archi = grafo.all_edges();

    std::set<int> all_nodi = grafo.all_nodes();

    int x = 10;
    std::set<int> vicini_di_x = grafo.neighbours(nodi[x]);

    int id_arco_x = grafo.edge_number(archi[x]);
    unidirected_edge<int> arco_x = grafo.edge_at(x);

    unidirected_graph<int> grafo2;
    std::vector<int> nodi2 = {8, 17, 3, 14, 20, 1, 9, 12, 5, 19, 2, 15, 7, 11, 4, 18, 6, 10, 13, 16, 9, 1, 20, 14, 3, 8, 17, 5, 12, 19};
    
    for (int i = 0; i < nodi2.size() - 3; i++){
        for(int j = i; j < nodi2.size() - 3; j++){
            grafo2.add_edge(nodi2[i], nodi2[j+3]);
        }
    }

    unidirected_graph<int> G = grafo - grafo2;

    //Ho utilizzato Gemini per generare questi cout

    std::cout << "--- ANALISI GRAFO 1 ---\n";
    std::cout << "Nodi unici totali: " << all_nodi.size() << "\n";
    std::cout << "Archi totali generati: " << archi.size() << "\n\n";
    std::cout << "I primi 3 archi: " << archi[0] << archi[1] << archi[2] << "\n\n";

    std::cout << "--- TEST METODI SINGOLI ---\n";
    std::cout << "Valore x scelto: " << x << "\n";
    std::cout << "Il nodo all'indice x (" << x << ") e': " << nodi[x] << "\n";
    std::cout << "Il nodo " << nodi[x] << " ha " << vicini_di_x.size() << " vicini.\n";
    
    std::cout << "L'arco all'indice x e': " << arco_x; 
    std::cout << "L'ID calcolato per questo arco e': " << id_arco_x << " (Dovrebbe essere identico a x!)\n\n";

    std::cout << "--- TEST OPERATORE DI SOTTRAZIONE ---\n";
    std::cout << "Archi in Grafo 1: " << grafo.all_edges().size() << "\n";
    std::cout << "Archi in Grafo 2: " << grafo2.all_edges().size() << "\n";
    std::cout << "Archi in G (Grafo 1 - Grafo 2): " << G.all_edges().size() << "\n";
    
    if(G.all_edges().size() == 0) {
        std::cout << "Risultato: Grafo 2 contiene tutti gli archi di Grafo 1!\n";
    }

    return 0;
}