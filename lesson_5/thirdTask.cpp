#include <iostream>

class intermediateClass;
class Class2;

class Class1
{
    public:
    Class1(int a,int b): alpha{a},betta {b}
    {

    }
    private:
        int alpha;
        int betta;
        friend intermediateClass;
};

class intermediateClass
{
    private:
        int getAlpha(Class1 obj) const
        {
            return obj.alpha;
        }
        friend Class2;
};
//класс 2 имеет доступ только к полю alpha, но не к полю betta
class Class2
{
    public:
        int getAlpha(Class1 object) const
        {
            return obj.getAlpha(object);
        }
    private:
        intermediateClass obj;
};



int main()
{
    Class1 a(2,5);
    Class2 b;
    std::cout<<b.getAlpha(a);
    return 0;
}