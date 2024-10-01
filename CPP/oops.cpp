#include <iostream>
using namespace std;

class car
{
    char col[10];

public:
    int speed;
    void get(int distance, int fuel)
    {
        cout << "the car has DISTANCE :" << distance << "FUEL :" << fuel << endl;
    }
    void milage(float distance, float fuel);

    void carspeed()
    {
        cout << "SPEED " << speed;
    }

} audi;

void car ::milage(float d, float f)
{
    float carmil = d / f;
    cout << "MILAGE IS :" << carmil << endl;
}

int main()
{
    car swift;
    swift.get(10, 10);
    audi.get(19, 20);
    audi.milage(1900, 20);
    swift.speed = 10;
    swift.carspeed();
    return 0;
}