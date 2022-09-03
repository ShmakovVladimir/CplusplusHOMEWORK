#include <iostream>

void swap(int* a,int* b){
    *a*=(*b); //теперь a = a_{0}*b_{0}
    *b = (*a)/(*b); //a_{0}*b_{0}/b_{0} = a_{0} - тоесть b теперб a_{0}
    //поделим a на a_{0}=b и получим b_{0}
    *a/=(*b);
}

int main(){
    setlocale(LC_ALL,"RUSSIAN");
    int a = (int)rand()%100;
    int b = (int)rand()%100;
    std::cout<<"Перед заменой: "<<"a: "<<a<<" b: "<<b<<std::endl;
    swap(&a,&b);
    std::cout<<"После замены: "<<"a: "<<a<<" b: "<<b<<std::endl;
    return 0;
}