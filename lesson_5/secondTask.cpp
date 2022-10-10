#include <iostream>
#include <cmath>

class Force
{
    public:
        Force();
        Force(double force);
        double getForceInNewton() const;
        double getForceInSGS() const;
        void setForceInNewton(double force);
        void setForceInSGS(double force);
        void printForce() const;
    private:
        inline double SGSToNewton(double force) const;
        inline double NewtonToSGS(double force) const;
        double forceInNewton;
        static const double dinInNewton;
};
const double Force::dinInNewton = std::pow(10,-5);

inline double Force::NewtonToSGS(double force) const
{
    return force/dinInNewton;
}
inline double Force::SGSToNewton(double force) const
{
    return force*dinInNewton; 
}
Force::Force()
{

}
Force::Force(double force): forceInNewton{force}
{

}

double Force::getForceInNewton() const
{
    return forceInNewton;
}
double Force::getForceInSGS() const
{
    return NewtonToSGS(forceInNewton);
}

void Force::setForceInNewton(double force)
{
    forceInNewton = force;
}

void Force::setForceInSGS(double force)
{
    forceInNewton = SGSToNewton(force);
}

void Force::printForce() const
{
    std::cout<<std::endl<<"Force In Newton: "<<forceInNewton;
    std::cout<<std::endl<<"Force In SGS: "<<NewtonToSGS(forceInNewton);
}

int main()
{
    Force alpha(100);
    alpha.printForce();
    alpha.setForceInSGS(20);
    alpha.printForce();
    return 0;
}