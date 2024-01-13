
#ifndef SIMPLE_H
#define SIMPLE_H

class simple()
{
    public:
        simple();
        ~simple();

        int sum();
        int lowestNum();
        int biggestNum();

        float sqr(float x);
        float sqrt(float x);

        float cos();
        float sin();
        float tan();
        float log();

}

simple::simple()
{
}

simple::~simple()
{
}

int simple::sum()
{
    int a = 0;
    for (i = 0; i < x; i++)
    {
        a = a + number;
    }

    return a;
}

int simple::lowestNum()
{
    int a = 0;
    for (i = 0; i < x; i++)
    {
        if (a > number)
        {
            a = number;
        }
    }

    return a;
}

int simple::biggestNum()
{
    int a = 0;
    for (i = 0; i < x; i++)
    {
        if (a < number)
        {
            a = number;
        }
    }

    return a;
}

float simple::sqr(float x)
{
    float a = 0.0f;
    
    for (i = 0; i < x; i++)
    {
        a = a + number;
    }

    return a;
}

float simple::sqrt(float x)
{
    float a = 0.0f;
    
    for (i = 0; i < x; i++)
    {
        a = a + number;
    }

    return a;
}

float simple::cos()
{
    float a = 0.0f;
    
    for (i = 0; i < x; i++)
    {
        a = a + number;
    }

    return a;
}

float simple::sin()
{
    float a = 0.0f;
    
    for (i = 0; i < x; i++)
    {
        a = a + number;
    }

    return a;
}

float simple::tan()
{
    float a = 0.0f;
    
    for (i = 0; i < x; i++)
    {
        a = a + number;
    }

    return a;
}

float simple::log()
{
    float a = 0.0f;
    
    for (i = 0; i < x; i++)
    {
        a = a + number;
    }

    return a;
}

#endif // SIMPLE_H