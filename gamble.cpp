#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const string symbols[] = {"\033[0;31m♥\033[0;0m","♠","♣","\033[0;31m♦\033[0;0m","❼"};


void printMsg(string s1, string s2, string s3){

    if(s1 == s2 && s2 == s3 && s1 == "❼"){
        cout << "\033[5;0m\n777 777 777 777\nPREMIO PREMIO PREMIO PREMIO\nAFIRMAR AFIRMAR AFIRMAR AFIRMAR\n🤑 🤑 🤑 🤑";
    }else if(s1 == s2 && s2 == s3){
        cout << "\033[5;0m\nPREMIO PREMIO PREMIO PREMIO";
    }else if(s1 == s2 || s1 == s3 || s2 == s3){
        cout << "\ncasi, pero no...";
    }else{
        cout << "\nX X X oh dang it";
    }


}

int main(){
  
    struct timespec t= { 0, 90000000 };

    srand(time(NULL));

    string s1,s2,s3;
    int i1,i2,i3;
    i1 = rand()%5;
    i2 = rand()%5;
    i3 = rand()%5;
    for(int i = 0; i < 10; i++){
        s1 = symbols[i1++%5];
        s2 = symbols[i2++%5];
        s3 = symbols[i3++%5];

        cout << "| [" + s1 + "][" + s2 + "][" + s3 + "] |"  ;
        flush(cout);
        cout << "\r";

        nanosleep(&t,NULL);
    }
    
    for(int i = 0; i < 7; i++){
        s2 = symbols[i2++%5];
        s3 = symbols[i3++%5];

        cout << "| [" + s1 + "][" + s2 + "][" + s3 + "] |"  ;
        flush(cout);
        cout << "\r";

        nanosleep(&t,NULL);
    }

    for(int i = 0; i < 7; i++){
        s3 = symbols[i3++%5];

        cout << "| [" + s1 + "][" + s2 + "][" + s3 + "] |"  ;
        flush(cout);
        cout << "\r";

        nanosleep(&t,NULL);
    }

    printMsg(s1,s2,s3); 
    flush(cout);

    cout << "\n\033[0;0m";
}


