#include <vector>
#include <optional>
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

template<typename T>
void
print_vector(const std::vector<T>& v)
{
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

