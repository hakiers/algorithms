#include <iostream>
#include "ahocorasick.hpp"

int main(){
    ahocorasick::AhoCorasick Aho;

    Aho.add_pattern("alakota");
    Aho.add_pattern("kota");
    Aho.add_pattern("talaretka");
    Aho.add_pattern("a");

    std::unordered_map<std::string, std::vector<std::pair<int, int>>>  M;
    M = Aho.search("alakotalaretka");
    for(auto [u, v] : M){
        std::cout << u << "\n";
        for(auto [a, b] : v){
            std::cout << "(" << a << "," << b << ") ";
        }
        std::cout << "\n";
    }
}