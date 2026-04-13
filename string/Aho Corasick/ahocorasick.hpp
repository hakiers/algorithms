#ifndef AHOCORASICK_HPP
#define AHOCORASICK_HPP
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>

namespace ahocorasick{

struct Node{
    std::unordered_map<char, Node*> transition;
    Node *fail_link;
    std::vector<int> out;
    bool terminal;

    Node(){
        terminal = 0;
        fail_link = nullptr;
    }
};

class AhoCorasick{
    Node *root;
    std::vector<std::string> patterns;
    bool prepared;
public:
    AhoCorasick(){
        root = new Node();
        prepared = 0;
    }
    ~AhoCorasick(){
        delete_tree(root);
    }

    void add_pattern(std::string pattern){
        Node *current = root;
        for(auto &u : pattern){
            if(!current->transition.count(u)){
                current->transition[u] = new Node();
            }
            current = current->transition[u];
        }
        current->out.push_back(patterns.size());
        current->terminal = 1;
        patterns.push_back(pattern);
    }
    
    std::unordered_map<std::string, std::vector<std::pair<int, int>>> search(std::string_view text){
        if(!prepared){
            prepare();
            prepared = 1;
        }
        std::vector<std::vector<std::pair<int, int>>> intervals(patterns.size());

        Node *current = root;
        for(int i = 0; i < text.size(); i++){
            char c = text[i];
            while(current != root && current->transition.count(c) == 0){
                current = current->fail_link;
            }
            
            if(current->transition.count(c)){
                current = current->transition[c];
            }

            patterns_lookup(current, i, intervals);
        }

        
        std::unordered_map<std::string, std::vector<std::pair<int, int>>> M;
        for(int i = 0; i < patterns.size(); i++){
            M[patterns[i]] = intervals[i];
        }
        return M;
    }

private:
    void delete_tree(Node *node){
        if(node == nullptr) return;
        for(auto &u : node->transition){
            delete_tree(u.second);
        }
        delete node;
    }

    void prepare(){
        std::queue<Node*> Q;
        root->fail_link = root;

        for(auto [c, u] : root->transition){
            u->fail_link = root;
            Q.push(u);
        }

        while(Q.size()){
            auto v = Q.front(); Q.pop();

            for(auto [c, u] : v->transition){

                auto fl = v->fail_link;

                while(fl != root && fl->transition.count(c) == 0){
                    fl = fl->fail_link;
                }
                
                if(fl->transition.count(c) && fl->transition[c] != u){
                    u->fail_link = fl->transition[c];
                }
                else{
                    u->fail_link = root;
                }

                if(u->fail_link->terminal){
                    u->terminal = 1;
                }

                Q.push(u);
            }
        }
    }

    void patterns_lookup(Node *node, int index, std::vector<std::vector<std::pair<int, int>>> &intervals){
        while(node != root && node->terminal){
            for(auto u : node->out){
                intervals[u].push_back({index-patterns[u].size()+1, index});
            }
            node = node->fail_link;
        }
    }
};
    
}


#endif