#include <iostream>
#include <unordered_map>
#include <list>


struct node {
    int key;
    int value;
    node(int k , int v):key(k),value(v){}
};

class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->data.clear();
        this->data_list.clear();
    }
    
    int get(int key) {
        if(this->data.find(key) != this->data.end()){
            this->data_list.splice( this->data_list.begin() , this->data_list ,  this->data[key]);
            return this->data_list.front()->value;
        }
        return -1;
    }
    
    void set(int key, int value) {
        if(this->data.find(key) != this->data.end()){
            this->data_list.splice(this->data_list.begin() , this->data_list , this->data[key]);
            this->data_list.front()->value = value;
        }else {
            if(this->capacity == this->data.size()){
                int key =  this->data_list.back()->key;
                this->data.erase(key);
                this->data_list.pop_back();
            }
            this->data_list.push_front(new node(key , value));
            this->data[key] = this->data_list.begin();
        }
    }

    void print_data()
    {
        for(auto it:this->data_list){
            std::cout<<it->key<<"  =>  "<<it->value<<std::endl;
        }
        std::cout<<std::endl;
    }

private:
    std::unordered_map<int , std::list<node*>::iterator > data;
    std::list<node*> data_list;
    int capacity;
};

int main()
{
    LRUCache *cache = new LRUCache(3);
    cache->set(1,11);
    cache->set(2,22);
    cache->set(3,33);
    cache->print_data();
    cache->get(1);
    cache->print_data();
    cache->set(4,44);
    cache->print_data();
    return 0;
}
