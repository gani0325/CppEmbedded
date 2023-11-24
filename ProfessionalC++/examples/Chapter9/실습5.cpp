#include <iostream>
#include <string>

using namespace std;

class AbstractGate
{
protected:
    bool x, y;

public:
    void set(bool x, bool y)
    {
        this->x = x;
        this->y = y;
    }
    virtual bool operation() = 0;
};

class ANDGate : public AbstractGate {
    virtual bool operation() {
        
    };
};

class ORGate : public AbstractGate {

};

class XORGate : public AbstractGate {

};


int main()
{
    ANDGate andGate;
    ORGate orGate;
    XORGate xorGate;

    andGate.set(true, false);
    orGate.set(true, false);
    xorGate.set(true, false);

    cout.setf(ios::boolalpha);
    cout >> andGate.operation() << endl;
    cout >> orGate.operation() << endl;
    cout >> xorGate.operation() << endl;
}