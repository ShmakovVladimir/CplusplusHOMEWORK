#include <iostream>
#include <cmath>
enum class Systems
{
    si,
    sgs,
    other
};
class Force
{
    public:
        Force();
        Force(float force);
        Force(float force,Systems system);
        float getForceInNewton() const;
        float getForceInSGS() const;
        float getForce(Systems system) const;
        float setForceInNewton();
    private:
        float SGSToNewton(float force) const;
        float NewtonToSGS(float force) const;
        float forceInNewton;
        static const float dinInNewton;
};
const float Force::dinInNewton = pow(10,-5);

float Force::NewtonToSGS(float force) const
{
    return force/dinInNewton;
}
float Force::SGSToNewton(float force) const
{
    return force*dinInNewton; 
}
Force::Force()
{

}
Force::Force(float force): forceInNewton{force}
{

}
Force::Force(float force,Systems system)
{
    switch(system)
    {
        case Systems::sgs:
            forceInNewton = SGSToNewton(force);
        case Systems::si:
            forceInNewton = force;
        default:
            forceInNewton = force;
    }
}
float Force::getForceInNewton() const
{
    return forceInNewton;
}
float Force::getForceInSGS() const
{
    return NewtonToSGS(forceInNewton);
}

float Force::getForce(Systems system) const
{
    switch (system)
    {
    case Systems::si:
       return getForceInNewton();
    case Systems::sgs:
        return getForceInSGS();
    default:
        return getForceInNewton();
    }
}


int main()
{

    return 0;
}