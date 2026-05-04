#include <vector>
#include <optional>
#include <limits>
#include <string>
#include <type_traits>
#include <algorithm>

template <typename T>
std::optional<T> max_elem(const std::vector<T>& vec)
{
    if (vec.size() == 0) { 
        return {}; 
    }
    
    T vec_max = vec[0];
    
    for (size_t i = 1; i < vec.size(); i++) {
        vec_max = std::max(vec_max, vec[i]);
    }
    
    return vec_max;
}

template <typename T>
bool is_sorted(const std::vector<T>& vec)
{
    if (vec.size() == 0) { 
        return {}; 
    }

    for(int i = 1; i < vec.size(); i++){
        if (vec[i] < vec[i-1]){
            return false;
        }
    }
    return true;
}

template <typename T>
void bubble_sort(std::vector<T>& vec)
{
    if (vec.size() == 0) { 
        return; 
    }

    for (size_t i = 0; i < vec.size(); i++) {
        for (size_t j = vec.size() - 1; j > i; j--){
            if (vec[j] < vec[j-1]) { 
                T k = vec[j];
                vec[j] = vec[j-1];
                vec[j-1] = k;
            }       
        }
    }
}

template <typename T>
void insertion_sort(std::vector<T>& vec)
{
    if (vec.size() == 0) { 
        return; 
    }

    for (size_t j = 1; j < vec.size(); j++) {
        T key = vec[j];
        int i = j - 1;
        while (i>=0 && vec[i] > key){
            vec[i+1] = vec[i];
            i = i - 1;
        }
        vec[i+1] = key;
    }
}

template <typename T>
void selection_sort(std::vector<T>& vec)
{
    if (vec.size() == 0) { 
        return; 
    }

    for (size_t i = 0; i < vec.size() - 1; i++) {    
        int min_idx = i; 
        for (size_t j = i + 1; j < vec.size(); j++) {
            if (vec[j] < vec[min_idx]) {
                min_idx = j; 
            }
        }

        if (min_idx != i) {
            std::swap(vec[i], vec[min_idx]);
        }
    }
}

template <typename T>
void merge(std::vector<T>& vec, int p, int q, int r) {

    if (vec.size() == 0){
        return;
    }

    int n1 = q - p + 1;
    int n2 = r - q;

    std::vector<T> L(n1 + 1);
    std::vector<T> R(n2 + 1);

    for (int i = 0; i < n1; i++) {
        L[i] = vec[p + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = vec[q + 1 + j];
    }

    //Qui ho usato Gemini
    if constexpr (std::is_same_v<T, std::string>) {
        L[n1] = "\xff";
        R[n2] = "\xff";
    } else {
        L[n1] = std::numeric_limits<T>::max();
        R[n2] = std::numeric_limits<T>::max();
    }

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; ++k) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
    }
}

template <typename T>
void merge_sort(std::vector<T>& vec, int p, int r)
{
    if (vec.size() == 0){
        return;
    }

    if (p < r) {
        int q = (p + r) / 2;

        merge_sort(vec, p, q);
        merge_sort(vec, q + 1, r);
        merge(vec, p, q, r);
    }
}

template <typename T>
int partition(std::vector<T>& vec, int p, int r) {
    T x = vec[r];      
    int i = p - 1;      

    for (int j = p; j <= r - 1; j++) {
        if (vec[j] <= x) {
            i = i + 1;
            std::swap(vec[i], vec[j]); 
        }
    }
    std::swap(vec[i + 1], vec[r]);  
    
    return i + 1;            
}

template <typename T>
void quick_sort(std::vector<T>& vec, int p, int r) {
    if (p < r) {
        int q = partition(vec, p, r);
        quick_sort(vec, p, q - 1);    
        quick_sort(vec, q + 1, r);  
    }
}

template <typename T>
void opt_sort(std::vector<T>& vec, int p, int r) {
    if (vec.size() <= 50){
        insertion_sort(vec);
    }
    else {
        quick_sort(vec, p, r);
    }
}

template<typename T>
void
print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

