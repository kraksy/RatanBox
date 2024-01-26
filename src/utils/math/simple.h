
#ifndef SIMPLE_H
#define SIMPLE_H

class simple
{
private:
    /* data */
public:
    simple();
    ~simple();

    int add(int, int);
    int deduct(int, int);
    int times(int, int);
    int devide(int, int);

    int sum(int list[]);
    int lowestNum(int list[]);
    int biggestNum(int list[]);

    float sqr(float);
    float sqrt(float);

    float sqr(int);
    float sqrt(int);

    float cos(float);  
    float sin(float);   
    float tan(float);     
    float log(float);  
};

#endif // SIMPLE_H