//temperature converter from celsius to fahrenheit

#include <stdio.h>

int main()
{
    float fahrenheit, celsius;
    celsius = 24;
    fahrenheit = ((celsius * 9) / 5) + 32;
    printf("Temperature in fahrenheit is:  %f", fahrenheit);
    return (0);
}
