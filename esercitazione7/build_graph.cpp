#include <iostream>
#include <fstream>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include "methods.hpp"

// Funzione di supporto per esportare un grafo in formato DOT
template <typename T>
void export_to_dot(unidirected_graph<T>& graph, const std::string& filename, const std::string& graph_name) {
    std::ofstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Errore: Impossibile aprire il file " << filename << " per la scrittura.\n";
        return;
    }

    // Inizia la definizione del grafo non orientato (graph)
    file << "graph " << graph_name << " {\n";

    // 1. Dichiara tutti i nodi (utile per mostrare anche eventuali nodi isolati)
    std::set<T> nodes = graph.all_nodes();
    for (const T& node : nodes) {
        file << "    " << node << ";\n";
    }

    // 2. Dichiara tutti gli archi
    std::vector<unidirected_edge<T>> edges = graph.all_edges();
    for (const auto& edge : edges) {
        // ATTENZIONE: Modifica 'edge.u' ed 'edge.v' con i nomi reali 
        // degli attributi o metodi usati in "methods.hpp" per accedere ai due nodi.
        // Ad esempio: edge.first e edge.second
        file << "    " << edge.from() << " -- " << edge.to() << ";\n";
    }

    file << "}\n";
    file.close();
    
    std::cout << "File " << filename << " generato con successo.\n";
}

int main(void){
    unidirected_graph<int> grafo;
    std::vector<int> nodi = {1, 2, 3, 4, 5};
    grafo.add_edge(1, 2);
    grafo.add_edge(1, 3);
    grafo.add_edge(1, 4);
    grafo.add_edge(1, 5);
    grafo.add_edge(2, 3);
    grafo.add_edge(2, 5);
    grafo.add_edge(3, 4);
    grafo.add_edge(3, 5);
    grafo.add_edge(4, 5);

    std::vector<unidirected_edge<int>> archi = grafo.all_edges();

    std::set<int> all_nodi = grafo.all_nodes();

    int x = 2;
    std::set<int> vicini_di_x = grafo.neighbours(nodi[x]);

    int id_arco_x = grafo.edge_number(archi[x]);
    unidirected_edge<int> arco_x = grafo.edge_at(x);

    std::vector<int> nodi2 = {1, 2, 3, 4, 5};
    unidirected_graph<int> grafo2;

    grafo2.add_edge(1, 2);
    grafo2.add_edge(1, 3);
    grafo2.add_edge(2, 3);
    grafo2.add_edge(3, 4);
    grafo2.add_edge(3, 5);
    grafo2.add_edge(4, 5);

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

    int start_node = 1;

    std::cout << "--- TEST BFS (Visita in Ampiezza su 'grafo2') ---\n";
    fifo<std::pair<int, int>> coda; 
    unidirected_graph<int> bfs_tree = graph_visit(grafo2, start_node, coda);
    std::cout << "Albero BFS generato. Nodi raggiunti: " << bfs_tree.all_nodes().size() 
              << " / " << grafo2.all_nodes().size() << "\n";
    std::cout << "Archi dell'albero BFS:\n";
    for (const auto& arco : bfs_tree.all_edges()) {
        std::cout << "  " << arco << "\n";
    }
    std::cout << "\n";

    std::cout << "--- TEST DFS ITERATIVA (su 'grafo2') ---\n";
    lifo<std::pair<int, int>> stack; 
    unidirected_graph<int> dfs_tree = graph_visit(grafo2, start_node, stack);
    std::cout << "Albero DFS iterativo generato. Nodi raggiunti: " << dfs_tree.all_nodes().size() 
              << " / " << grafo2.all_nodes().size() << "\n\n";
    std::cout << "Archi dell'albero DFS:\n";
    for (const auto& arco : dfs_tree.all_edges()) {
        std::cout << "  " << arco << "\n";
    }
    std::cout << "\n";

    std::cout << "--- TEST DFS RICORSIVA (su 'grafo2') ---\n";
    unidirected_graph<int> rec_dfs_tree = recursive_dfs(grafo2, start_node);
    std::cout << "Albero DFS ricorsivo generato. Nodi raggiunti: " << rec_dfs_tree.all_nodes().size() 
              << " / " << grafo2.all_nodes().size() << "\n\n";
    std::cout << "Archi dell'albero DFS ricorsiva:\n";
    for (const auto& arco : rec_dfs_tree.all_edges()) {
        std::cout << "  " << arco << "\n";
    }
    std::cout << "\n";

    std::cout << "--- TEST DIJKSTRA (su 'grafo2') ---\n";
    auto result = dijkstra(grafo2, start_node);
    std::cout << "Distanze minime dal nodo sorgente [" << start_node << "]:\n";
    
    for (const int& nodo : grafo2.all_nodes()) {
        std::cout << " -> Distanza per [" << nodo << "] = " << result.dist[nodo];
        if (nodo == start_node) {
            std::cout << " (Sorgente)\n";
        } else {
            std::cout << " (Precedessore: " << result.pred[nodo] << ")\n";
        }
    }
    std::cout << "\n=== TEST CONCLUSI ===\n";

    export_to_dot(grafo, "grafo.dot", "Grafo1");
    export_to_dot(grafo2, "grafo2.dot", "Grafo2");
    export_to_dot(bfs_tree, "bfs_tree.dot", "AlberoBFS");
    export_to_dot(dfs_tree, "dfs_tree.dot", "AlberoDFS");
    export_to_dot(rec_dfs_tree, "rec_dfs_tree.dot", "AlberoREC_DFS");

    return 0;
}