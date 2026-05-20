#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <utility>

template <typename T>
class unidirected_edge {
private:
    T _from;
    T _to;

public:
    unidirected_edge(T n1, T n2) {
        _from = std::min(n1, n2);
        _to   = std::max(n1, n2);
    }

    T from() const {
        return _from;
    }

    T to() const {
        return _to;
    }

    bool operator<(const unidirected_edge<T>& other) const{
        if (_from != other._from){
            return _from < other._from;
        }
        return _to < other._to;
    }

    bool operator==(const unidirected_edge<T>& other) const{
        return (_from == other._from) && (_to == other._to);
    }
};

template <typename T>
std::ostream&
operator<<(std::ostream& os, const unidirected_edge<T>& edge)
{
    os << "(" <<edge.from()<< "," << edge.to() << ")" << "\n";
    return os;
}

template <typename T>
class unidirected_graph{
    private: 
        std::unordered_map<T, std::set<T>> ad_list;
        std::vector<unidirected_edge<T>> edges;
        std::set<T> nodes;
        std::map<unidirected_edge<T>, int> edge_to_id;

    public:
        unidirected_graph() = default;
        unidirected_graph(const unidirected_graph<T>& other) = default;

        void add_edge(T n1, T n2){

        if (n1 == n2){
            return;
        }

        unidirected_edge<T> new_edge(n1,n2);
        if (edge_to_id.count(new_edge) > 0){
            return;
        }

        ad_list[n1].insert(n2);
        ad_list[n2].insert(n1);

        int id = edges.size();
        edge_to_id[new_edge] = id;

        edges.push_back(new_edge);

        if (nodes.count(n1) == 0){
            nodes.insert(n1);
        }

        if (nodes.count(n2) == 0){
            nodes.insert(n2);
            }
        }

        std::set<T> neighbours(const T& node) const{
            if (ad_list.count(node) == 0){
                return std::set<T>();
            }
            else {
                return ad_list.at(node);
            }
        }

        std::vector<unidirected_edge<T>> all_edges() const{
            return edges;
        }

        std::set<T> all_nodes() const{
            return nodes;
        }

        int edge_number(const unidirected_edge<T>& arco){
            return edge_to_id[arco];
        }

        unidirected_edge<T> edge_at(const int& id){
            return edges[id];
        }

        unidirected_graph<T> operator-(const unidirected_graph<T>& other){
            unidirected_graph<T> G_ris;
            for (int i = 0; i < edges.size(); i++){
                if (other.edge_to_id.count(edges[i]) == 0){
                    G_ris.add_edge(edges[i].from(), edges[i].to());
                }
           }

           return G_ris;
        }
};

template <typename T>
class fifo {
private:
    std::queue<T> coda; 

public:
    fifo() = default; 

    void put(const T& val) {
        coda.push(val); 
    }

    T get() {
        T val = coda.front(); 
        coda.pop();             
        return val;          
    }

    bool empty() const {
        return coda.empty();  
    }
};


template <typename T>
class lifo {
private:
    std::stack<T> pila; 

public:
    lifo() = default; 

    void put(const T& val) {
        pila.push(val); 
    }

    T get() {
        T val = pila.top();
        pila.pop();           
        return val;        
    }

    bool empty() const {
        return pila.empty();  
    }
};

template <typename T, typename C> //Mi sono aiutato con Gemini perché gli alberi che visualizzavo con GraphViz non erano corretti.
unidirected_graph<T> graph_visit(const unidirected_graph<T>& G, const T& nodo_iniziale, C& c) {
    
    unidirected_graph<T> albero_visita;
    std::map<T, bool> reached;
    
    for (const T& nodo : G.all_nodes()) {
        reached[nodo] = false;
    }

    c.put({nodo_iniziale, nodo_iniziale});

    while (!c.empty()) {
        std::pair<T, T> arco = c.get();
        T u = arco.first;   
        T padre = arco.second; 

        if (reached[u]) {
            continue; 
        }

        reached[u] = true;


        if (u != nodo_iniziale) {
            albero_visita.add_edge(padre, u);
        }

        for (const T& w : G.neighbours(u)) {  
            if (!reached[w]) {
                c.put({w, u});
            }
        }
    }
    
    return albero_visita;
}

template <typename T> 
void dfs(const unidirected_graph<T>& G, const T& u, unidirected_graph<T>& tree, std::map<T, bool>& reached){
    reached[u] = true;
    
    for (const T& w : G.neighbours(u)){ 
            if(!reached[w]){
                tree.add_edge(u, w);
                dfs(G, w, tree, reached); //Mi sono aiutato con Gemini per definire la struttura della ricorsione
            }
        }
}

template <typename T> 
unidirected_graph<T> recursive_dfs(const unidirected_graph<T>& G, const T& v){
    unidirected_graph<T> tree;
    std::map<T, bool> reached;

    dfs(G, v, tree, reached);

    return tree;
}

template <typename T>
struct DijkstraResult {
    std::map<T, int> dist;
    std::map<T, T> pred;
};

template <typename T>
DijkstraResult<T> dijkstra(const unidirected_graph<T>& G, const T& v){
    DijkstraResult<T> r;
    std::priority_queue<std::pair<int, T>, 
                    std::vector<std::pair<int, T>>, 
                    std::greater<std::pair<int, T>>> PQ;

    for (const T& n : G.all_nodes()){
        r.dist[n] = 9999999;
    }

    r.pred[v] = v;
    r.dist[v] = 0;

    for (const T& n : G.all_nodes()){
        PQ.push({r.dist[n], n});
    }

    while(!PQ.empty()){
        int d = PQ.top().first;
        T u = PQ.top().second;
        PQ.pop();
        
        if (d > r.dist[u]) {
            continue;
        }

        for (const T& w : G.neighbours(u)){
            if(r.dist[w] > r.dist[u] + 1){
                r.dist[w] = r.dist[u] + 1;
                r.pred[w] = u;
                
                PQ.push({r.dist[w], w});
            }
    }
}

    return r;
}