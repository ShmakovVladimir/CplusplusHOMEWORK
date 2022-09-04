#include <iostream>
#include <math.h>


int main(){
    setlocale(LC_ALL,"RUSSIAN");
    std::cout<<"Какие единицы измерения необходимо перименовать? Выберите из списка: "<<std::endl;
    std::cout<<"1. Ньютон->Дин\n";
    std::cout<<"2. м->см\n";
    std::cout<<"3. Кулон->Единицы СГСЭ\n";
    std::cout<<"4. Фарад->Единцы измерения емкости\n";
    int num = 0;
    float x = 0;
    const float faradToSGSConst = 8.98*pow(10,11);
    std::cout<<"Выберите номер: ";
    std::cin>>num;
    while(num>0 && num>4){
        std::cout<<"Выберите номер из списка: ";
        std::cin>>num;
    }
    std::cout<<"Введите число: ";
    std::cin>>x;
    switch(num){
        case 1:
            std::cout<<std::endl<<x<<" Ньютон = "<<x*pow(10,5)<<" дин ";
            break;
        case 2:
            std::cout<<std::endl<<x<<" Меторов = "<<x*pow(10,2)<<" сантиметров ";
            break;
        case 3:
            std::cout<<std::endl<<x<<" Кулон = "<<3*x*pow(10,9)<<" едениц СГСЭ";
            break;
        case 4:
            std::cout<<std::endl<<x<<" Фарад = "<<faradToSGSConst*x<<" едениц СГСЭ";
            break;
    };

    return 0;
}