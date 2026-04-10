#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int chanch_one_cart(){ // Функція вибору карти
    
    int a;
    a=rand() % 13;
    
    return a;
};

int main(){
    
    srand(static_cast<unsigned int>(time(0)));
    
    string cart_name[13]={ "Два","Три","Чотири","Пʼять","Шість","Сім","Вісім","Девʼять","Десять","Валет","Дама","Король","Туз"};
    int cart[13]={2, 3, 4, 5, 6, 7, 8, 9, 10, 2, 3, 4, 1};
    int number_game=2;
    int player=0;
    int diller=0;
    string tus;
    int score[2]={0,0};
    
    cout<<"Гра в <Очко>"<<endl;
    cout<<"Правила: Гравець має набрати більше очків ніж диллер. Якщо в гравця або диллера більше 21 очка то автоматично зараховується перебор карт. Очки розцінюються як: король - 4 очка, дама - 3 очка, валет - 2 очка, туз - 1 очко або 11 очок (вирішується між гравцями до початку гри), інші карти по номеру."<<endl;
    
    cout<<"Виберіть якому значенню дорівнює туз <1> чи <11>"<<endl;
    
    while(true){
        cin>>tus;
        if(tus=="1"){
            cart[12]=1;
            break;
            
        }else if(tus=="11"){
            cart[12]=11;
            break;
            
        }else{cout<<"Помилка, повторіть спробу"<<endl;};
    };
    
    
    while(true){ //безконечна гра
        
        while(true){
            string yes_not;
            cout<<"Взяти карти <yes> чи <not>"<<endl;
            cin>>yes_not;
            
            if(yes_not=="yes"){
                int ID=0;
                ID=chanch_one_cart();
                player+=cart[ID];
                cout<<"Ви витягнули \t"<< cart_name[ID] <<endl;
                
            }else if(yes_not=="not"){
                break;
            }else {cout<<"Помилка, повторіть спробу"<<endl;}
        };
         
        while(true){ // алгоритм набору карт диллера
            if(diller<=15){ diller+=cart[chanch_one_cart()];
            }else if(diller>15){ break; };
    }
    
    if(player>21 && diller>21){
        cout<<"У вас із диллером перебор, спорбуйте ще)"<<endl;
    }
    else if(player>21){
        cout<<"У вас перебор, не засмучуйтесь спробуйте ще)"<<endl;
        score[1]++;
    }
    else if(diller>21){
        cout<<"У диллера перебор, ви виграли"<<endl;
        score[0]++;
    }
    else if(player>diller){
        cout<<"Диллер має "<<diller<<" очків Ви виграли!!!"<<endl;
        score[0]++;
        
    }else if(diller>player){
        cout<<"Диллер має "<<diller<<" очків Ви приграли, не засмучуйтесь спробуйте ще)"<<endl;
        score[1]++;
        
    }else if(player==diller){
        cout<<"Диллер має "<<diller<<" очків У вас нічия, спробуйте ще)"<<endl;
        
    };
        
        string exit_game;
        cout<<"Якщо ви бажаєте покинути гру напишіть <exit>, якщо продожити напишіть <continue>"<<endl;
        while(true){
            cin>>exit_game;
            if(exit_game=="exit"){
                cout<<"Рахунок: "<<"Гравець "<<score[0]<<endl<<"         Диллер  "<<score[1]<<endl;
                exit(0);
            }else if(exit_game=="continue"){
                player=0;
                diller=0;
                cout<<"Game "<<number_game<<endl;
                cout<<"Рахунок: "<<"Гравець "<<score[0]<<endl<<"         Диллер  "<<score[1]<<endl;
                number_game++;
                break;
            }else{cout<<"Помилка, повторіть спробу"<<endl;};
        };
    };
        
};

