#include<iostream>

template <class node>
class linklist{
    private:
        node *next;
        data DT;
    public:
        linklist();
        ~linklist();        
        void add(T *data)
        bool isEmpty() const;
        bool isFull() const;
        void clear() noexcept;  
};
