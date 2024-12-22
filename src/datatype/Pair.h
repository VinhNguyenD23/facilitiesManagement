#ifndef PAIR_H
#define PAIR_H

template<typename T, typename K>
class Pair
{
private:
    T first;
    K second;
public:
    Pair(){}
    Pair(T first, K second) {
        this->first = first;
        this->second = second;
    }

    T getFirst()
    {
        return this->first;
    }

    K getSecond()
    {
        return this->second;
    }

    void setFirst(T first)
    {
        this->first = first;
    }

    void setSecond(K second)
    {
        this->second = second;
    }
};

#endif // PAIR_H
