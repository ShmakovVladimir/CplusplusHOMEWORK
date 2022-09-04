#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    const int MaxNameLen = 50;
    const int consoleLength = 25;
    const int hexNumwidth = 8;
    char productName[MaxNameLen];
    int price,temp;
    char cashBack[10];
    cout<<"Product's name: ";
    cin>>productName;
    cout<<"Product's price: ";
    cin>>price;
    cout<<"Is cash-back available for this product? (true/false): ";
    cin>>cashBack;
    cout<<"Maximum storing temperature: ";
    cin>>temp;
    cout<<endl<<endl<<"Result: "<<endl<<endl;
    cout<<productName<<endl;
    cout.fill('.');
    cout.width(consoleLength);
    cout<<left<<"Price:"<<right<<setw(hexNumwidth)<<setfill('0')<<hex<<noshowbase<<uppercase<<price;
    cout.fill('.');
    cout.width(consoleLength);
    cout<<endl<<left<<"Has cash back:"<<right<<boolalpha<<cashBack;
    cout.fill('.');
    cout.width(consoleLength);
    cout<<endl<<left<<"Max Tempeature:"<<right<<showpos<<dec<<temp;


    return 0;
}