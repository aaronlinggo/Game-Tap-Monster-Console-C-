#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <mmsystem.h>
#include <string>

using namespace std;

void gotoxy(int x, int y){
   COORD k = {x,y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), k);
}

void changeColor(int desiredColor){
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

void cetakMap(char arena[24][61], int x, int y, int xbatu[100], int ybatu[100], int jumlahbatu, int xtower[100], int ytower[100], int jumlahtower, int ypeluru[100], int xpeluru[100], char player, int xM[100], int yM[100], int jumlahmusuh, int nyawa, int xHealth[100], int yHealth[100], int jumlahhealth, int xM1[100], int yM1[100], int jumlahM, int xCP[100], int yCP[100], int jumlahCP, int xtangga, int ytangga, string Nama){
    ifstream myfile("map.txt");
    int line = 0;
    string temp;
    if(myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile,temp);
            for(int i = 0 ; i < 60 ; i++){
                arena[line][i] = temp[i];
            }
            line++;
        }
    }
    char tembok = 219;
    for(int i=0; i<24; i++){
        for(int j=0; j<60; j++){
            if(arena[i][j] == '#'){
                arena[i][j] = tembok;
            }
        }
    }
    for(int i=0; i<jumlahCP; i++){
        arena[yCP[i]][xCP[i]] = 128;
    }
    arena[ytangga][xtangga] = 177;
    arena[y][x] = player;
    for(int i=0; i<jumlahtower; i++){
        arena[ypeluru[i]][xpeluru[i]] = '*';
        arena[ytower[i]][xtower[i]] = 216;
    }
    for(int i=0; i<jumlahbatu; i++){
        arena[ybatu[i]][xbatu[i]] = '@';
    }
    for(int i=0; i<jumlahmusuh; i++){
        arena[yM[i]][xM[i]] = 237;
    }
    for(int i=0; i<jumlahhealth; i++){
        arena[yHealth[i]][xHealth[i]] = 3;
    }
    for(int i=0; i<jumlahM; i++){
        arena[yM1[i]][xM1[i]] = 254;
    }

    char a=237;
    char b=254;
    char c=128;
    char d=177;
    gotoxy(0,0);
    for(int i=0; i<24; i++){
        for(int j=0; j<60; j++){
            if(arena[i][j] == '@'){
                changeColor(3);
            } else if(arena[i][j] == '*'){
                changeColor(4);
            } else if(arena[i][j] == player){
                changeColor(30);
            } else if(arena[i][j] == a){
                changeColor(11);
            } else if(arena[i][j] == 3){
                changeColor(4);
            } else if(arena[i][j] == b){
                changeColor(6);
            } else if(arena[i][j] == c){
                changeColor(6);
            } else if(arena[i][j] == d){
                changeColor(4);
            } else{
                changeColor(14);
            }
            cout<<arena[i][j];
        }
        cout<<endl;
    }
    gotoxy(0,24); cout<<tembok<<"                                                          "<<tembok<<endl;
    gotoxy(0,25);
    for(int i=0; i<60; i++){
        cout<<tembok;
    }
    cout<<endl;
    char hati=3;
    gotoxy(3,24); changeColor(6); cout<<"Name : "<<Nama;
    gotoxy(27,24); changeColor(4); cout<<hati<<" : "<<nyawa;
    changeColor(14);
    gotoxy(62,0); cout<<"W : MAJU";
    gotoxy(62,1); cout<<"A : KIRI";
    gotoxy(62,2); cout<<"S : BAWAH";
    gotoxy(62,3); cout<<"D : KANAN";
    gotoxy(62,4); changeColor(6); cout<<c<<" : CHECKPOINT";
    gotoxy(62,5); changeColor(4); cout<<hati<<" : HEALTH";
    gotoxy(62,6); changeColor(4); cout<<d<<" : FINISH";
    gotoxy(62,7); changeColor(3); cout<<"@ : STONE";
    gotoxy(62,8); changeColor(11); cout<<a<<" : ENEMY";
}

void cekpeluru(char arena[24][61], int ypeluru[100], int xpeluru[100], int x, int y){
    char tembok = 219;
    if(arena[ypeluru[0]-1][xpeluru[0]] == ' '){
        ypeluru[0]--;
    } else if(arena[ypeluru[0]-1][xpeluru[0]] == '@'){
        ypeluru[0] = 22;
    } else if(arena[ypeluru[0]-1][xpeluru[0]] == tembok){
        ypeluru[0] = 22;
    } else if(arena[ypeluru[0]-1][xpeluru[0]] == arena[y][x]){
        ypeluru[0]--;
        ypeluru[0] = 22;
    }
    if(arena[ypeluru[1]][xpeluru[1]+1] == ' '){
        xpeluru[1]++;
    } else if(arena[ypeluru[1]][xpeluru[1]+1] == '@'){
        xpeluru[1] = 1;
    } else if(arena[ypeluru[1]][xpeluru[1]+1] == tembok){
        xpeluru[1] = 1;
    } else if(arena[ypeluru[1]][xpeluru[1]+1] == arena[y][x]){
        xpeluru[1]++;
        xpeluru[1] = 1;
    }
    if(arena[ypeluru[2]][xpeluru[2]-1] == ' '){
        xpeluru[2]--;
    } else if(arena[ypeluru[2]][xpeluru[2]-1] == '@'){
        xpeluru[2] = 17;
    } else if(arena[ypeluru[2]][xpeluru[2]-1] == tembok){
        xpeluru[2] = 17;
    } else if(arena[ypeluru[2]][xpeluru[2]-1] == arena[y][x]){
        xpeluru[2]--;
        xpeluru[2] = 17;
    }
    if(arena[ypeluru[3]][xpeluru[3]+1] == ' '){
        xpeluru[3]++;
    } else if(arena[ypeluru[3]][xpeluru[3]+1] == '@'){
        xpeluru[3] = 19;
    } else if(arena[ypeluru[3]][xpeluru[3]+1] == tembok){
        xpeluru[3] = 19;
    } else if(arena[ypeluru[3]][xpeluru[3]+1] == arena[y][x]){
        xpeluru[3]++;
        xpeluru[3] = 19;
    }
    if(arena[ypeluru[4]][xpeluru[4]+1] == ' '){
        xpeluru[4]++;
    } else if(arena[ypeluru[4]][xpeluru[4]+1] == '@'){
        xpeluru[4] = 1;
    } else if(arena[ypeluru[4]][xpeluru[4]+1] == tembok){
        xpeluru[4] = 1;
    } else if(arena[ypeluru[4]][xpeluru[4]+1] == arena[y][x]){
        xpeluru[4]++;
        xpeluru[4] = 1;
    }
    if(arena[ypeluru[5]][xpeluru[5]+1] == ' '){
        xpeluru[5]++;
    } else if(arena[ypeluru[5]][xpeluru[5]+1] == '@'){
        xpeluru[5] = 1;
    } else if(arena[ypeluru[5]][xpeluru[5]+1] == tembok){
        xpeluru[5] = 1;
    } else if(arena[ypeluru[5]][xpeluru[5]+1] == arena[y][x]){
        xpeluru[5]++;
        xpeluru[5] = 1;
    }
    if(arena[ypeluru[6]+1][xpeluru[6]] == ' '){
        ypeluru[6]++;
    } else if(arena[ypeluru[6]+1][xpeluru[6]] == '@'){
        ypeluru[6] = 16;
    } else if(arena[ypeluru[6]+1][xpeluru[6]] == tembok){
        ypeluru[6] = 16;
    } else if(arena[ypeluru[6]+1][xpeluru[6]] == arena[y][x]){
        ypeluru[6]++;
        ypeluru[6] = 16;
    }
    if(arena[ypeluru[7]+1][xpeluru[7]] == ' '){
        ypeluru[7]++;
    } else if(arena[ypeluru[7]+1][xpeluru[7]] == '@'){
        ypeluru[7] = 16;
    } else if(arena[ypeluru[7]+1][xpeluru[7]] == tembok){
        ypeluru[7] = 16;
    } else if(arena[ypeluru[7]+1][xpeluru[7]] == arena[y][x]){
        ypeluru[7]++;
        ypeluru[7] = 16;
    }
    if(arena[ypeluru[8]+1][xpeluru[8]] == ' '){
        ypeluru[8]++;
    } else if(arena[ypeluru[8]+1][xpeluru[8]] == '@'){
        ypeluru[8] = 16;
    } else if(arena[ypeluru[8]+1][xpeluru[8]] == tembok){
        ypeluru[8] = 16;
    } else if(arena[ypeluru[8]+1][xpeluru[8]] == arena[y][x]){
        ypeluru[8]++;
        ypeluru[8] = 16;
    }
    if(arena[ypeluru[9]][xpeluru[9]+1] == ' '){
        xpeluru[9]++;
    } else if(arena[ypeluru[9]][xpeluru[9]+1] == '@'){
        xpeluru[9] = 1;
    } else if(arena[ypeluru[9]][xpeluru[9]+1] == tembok){
        xpeluru[9] = 1;
    } else if(arena[ypeluru[9]][xpeluru[9]+1] == arena[y][x]){
        xpeluru[9]++;
        xpeluru[9] = 1;
    }
    if(arena[ypeluru[10]][xpeluru[10]+1] == ' '){
        xpeluru[10]++;
    } else if(arena[ypeluru[10]][xpeluru[10]+1] == '@'){
        xpeluru[10] = 1;
    } else if(arena[ypeluru[10]][xpeluru[10]+1] == tembok){
        xpeluru[10] = 1;
    } else if(arena[ypeluru[10]][xpeluru[10]+1] == arena[y][x]){
        xpeluru[10]++;
        xpeluru[10] = 1;
    }
    if(arena[ypeluru[11]][xpeluru[11]+1] == ' '){
        xpeluru[11]++;
    } else if(arena[ypeluru[11]][xpeluru[11]+1] == '@'){
        xpeluru[11] = 1;
    } else if(arena[ypeluru[11]][xpeluru[11]+1] == tembok){
        xpeluru[11] = 1;
    } else if(arena[ypeluru[11]][xpeluru[11]+1] == arena[y][x]){
        xpeluru[11]++;
        xpeluru[11] = 1;
    }
    if(arena[ypeluru[12]][xpeluru[12]+1] == ' '){
        xpeluru[12]++;
    } else if(arena[ypeluru[12]][xpeluru[12]+1] == '@'){
        xpeluru[12] = 1;
    } else if(arena[ypeluru[12]][xpeluru[12]+1] == tembok){
        xpeluru[12] = 1;
    } else if(arena[ypeluru[12]][xpeluru[12]+1] == arena[y][x]){
        xpeluru[12]++;
        xpeluru[12] = 1;
    }
}
void randomPosisiton(char arena[24][61], int xM[100], int yM[100], int jumlahmusuh, int x, int y){
    int random;
    for(int i=0; i<jumlahmusuh; i++){
        random = rand()%4;
        if(random == 0){
            if(arena[yM[i]-1][xM[i]] == ' '){
                yM[i]--;
            } else if(arena[yM[i]-1][xM[i]] == arena[y][x]){
                yM[i]--;
            }
        } else if(random == 1){
            if(arena[yM[i]+1][xM[i]] == ' '){
                yM[i]++;
            } else if(arena[yM[i]+1][xM[i]] == arena[y][x]){
                yM[i]++;
            }
        } else if(random == 2){
            if(arena[yM[i]][xM[i]-1] == ' '){
                xM[i]--;
            } else if(arena[yM[i]][xM[i]-1] == arena[y][x]){
                xM[i]--;
            }
        } else if(random == 3){
            if(arena[yM[i]][xM[i]+1] == ' '){
                xM[i]++;
            } else if(arena[yM[i]][xM[i]+1] == arena[y][x]){
                xM[i]++;
            }
        }
    }

}

int main()
{
    PlaySound(TEXT("menu.wav"),NULL,SND_LOOP|SND_ASYNC);
    srand(time(0));
    string Nama;
    int Level = 1, Gold = 0, Damage = 1, DamageTrops = 0, totalTrops = 0, Levelctr = 5;
    int Soft=0, Medium=0, Hard=0;
    int HPmusuh = 10, tampungHP = HPmusuh, HPsebelum;
    int TropAtk = 0, xMusuh=10;
    int timer=0, second=30;
    bool quit=false, gerak=true, play=false, sound=false, hit=false;
    char key;
    char menu, menuplay;
    char ujungataskiri = 201;
    char ujungbawahkiri = 200;
    char ujungataskanan = 187;
    char ujungbawahkanan = 188;
    char lurustidur = 205;
    char lurusberdiri = 186;
    do{
        if(sound==true){
            PlaySound(TEXT("menu.wav"),NULL,SND_LOOP|SND_ASYNC);
            sound = false;
        }
        system("color 0B");
        system("cls"); quit = false; play=false; hit=false;
        Level = 1; Gold = 0; Damage = 1; DamageTrops = 0; totalTrops = 0; Levelctr = 5;
        Soft=0; Medium=0; Hard=0;
        HPmusuh = 10; tampungHP = HPmusuh;
        TropAtk = 0; xMusuh=10;
        timer=0; second=30;
        gotoxy(0,0); cout<<"========================="<<endl;
        gotoxy(0,1); cout<<"|      TAP MONSTER      |"<<endl;
        gotoxy(0,2); cout<<"========================="<<endl;
        gotoxy(0,3); cout<<"|      1. PLAY          |"<<endl;
        gotoxy(0,4); cout<<"|      2. HOW TO PLAY   |"<<endl;
        gotoxy(0,5); cout<<"|      0. EXIT          |"<<endl;
        gotoxy(0,6); cout<<"========================="<<endl;
        gotoxy(0,7); cout<<"|                       |"<<endl;
        gotoxy(0,8); cout<<"========================="<<endl;
        gotoxy(7,7); cout<<"Choose : "; cin>>menu;
        if(menu == '1'){
            do{
                gotoxy(0,0); cout<<"========================="<<endl;
                gotoxy(0,1); cout<<"|      TAP MONSTER      |"<<endl;
                gotoxy(0,2); cout<<"========================="<<endl;
                gotoxy(0,3); cout<<"|      1. NEW GAME      |"<<endl;
                gotoxy(0,4); cout<<"|      2. LOAD GAME     |"<<endl;
                gotoxy(0,5); cout<<"|      0. BACK          |"<<endl;
                gotoxy(0,6); cout<<"========================="<<endl;
                gotoxy(0,7); cout<<"|                       |"<<endl;
                gotoxy(0,8); cout<<"========================="<<endl;
                gotoxy(7,7); cout<<"Choose : "; cin>>menuplay; cin.ignore();
                if(menuplay == '1'){
                    gotoxy(0,0); cout<<"========================="<<endl;
                    gotoxy(0,1); cout<<"|      TAP MONSTER      |"<<endl;
                    gotoxy(0,2); cout<<"========================="<<endl;
                    gotoxy(0,3); cout<<"|        NEW GAME       |"<<endl;
                    gotoxy(0,4); cout<<"|                       |"<<endl;
                    gotoxy(0,5); cout<<"|    ENTER YOUR NAME    |"<<endl;
                    gotoxy(0,6); cout<<"========================="<<endl;
                    gotoxy(0,7); cout<<"|                       |"<<endl;
                    gotoxy(0,8); cout<<"========================="<<endl;
                    gotoxy(5,7); getline(cin, Nama);
                    system("cls");
                    play=true;
                } else if(menuplay == '2'){
                    string data[100]; int counter1=0;
                    ifstream load("save.txt");
                    if(load.is_open()){
                        while(getline(load, data[counter1])){
                            counter1++;
                        }
                    }
                    load.close();
                    Nama = data[0];
                    Gold = stoi(data[1]);
                    Level = stoi(data[2]);
                    Damage = stoi(data[3]);
                    DamageTrops = stoi(data[4]);
                    totalTrops = stoi(data[5]);
                    HPmusuh = stoi(data[6]);
                    tampungHP = stoi(data[7]);
                    HPsebelum = stoi(data[8]);
                    Soft = stoi(data[9]);
                    Medium = stoi(data[10]);
                    Hard = stoi(data[11]);
                    play=true;
                    getch();
                }
                if(play==true){
                    PlaySound(TEXT("tap.wav"),NULL,SND_LOOP|SND_ASYNC);
                    while(quit == false){
                        gotoxy(0,0);  cout<<"========================="<<endl; gotoxy(26,0);  cout<<"==============="<<endl;
                        gotoxy(0,1);  cout<<"|      TAP MONSTER      |"<<endl; gotoxy(26,1);  cout<<"| INFORMATION |"<<endl;
                        gotoxy(0,2);  cout<<"========================="<<endl; gotoxy(26,2);  cout<<"==============="<<endl;
                        gotoxy(0,3);  cout<<"|                       |"<<endl; gotoxy(26,3);  cout<<"| TAP ANY KEY |"<<endl;
                        gotoxy(1,3);  cout<<"Name    : "<<Nama;
                        gotoxy(0,4);  cout<<"|                       |"<<endl; gotoxy(26,4);  cout<<"|    TO HIT   |"<<endl;
                        gotoxy(1,4);  cout<<"Gold    : "<<Gold;
                        gotoxy(0,5);  cout<<"|                       |"<<endl; gotoxy(26,5);  cout<<"|  THE ENEMY  |"<<endl;
                        gotoxy(1,5);  cout<<"Level   : "<<Level;
                        gotoxy(0,6);  cout<<"========================="<<endl; gotoxy(26,6);  cout<<"==============="<<endl;
                        gotoxy(0,7);  cout<<"|                       |"<<endl; gotoxy(26,7);  cout<<"| PRESS       |"<<endl;
                        gotoxy(xMusuh,7);
                        if(Level == 5){
                            system("Color 4");
                            cout<<"BOSS";
                        } else{
                            changeColor(4);
                            cout<<"MINI";
                            system("Color 0A");
                        }
                        if(xMusuh > 1 && gerak == true){
                            xMusuh--;
                        } else{
                            gerak = false;
                            if(xMusuh < 19 && gerak == false){
                                xMusuh++;
                            } else{
                                gerak = true;
                            }
                        }
                        gotoxy(0,8);   cout<<"|                       |"<<endl;   gotoxy(26,8);  cout<<"| S : SAVE    |"<<endl;
                        gotoxy(0,9);   cout<<"|                       |"<<endl;   gotoxy(26,9);  cout<<"| U : UPGRADE |"<<endl;
                        gotoxy(0,10);  cout<<"|                       |"<<endl;   gotoxy(26,10); cout<<"| P : SHOP    |"<<endl;
                        gotoxy(0,11);  cout<<"|                       |"<<endl;   gotoxy(26,11); cout<<"| Q : QUIT    |"<<endl;
                        gotoxy(12,11); cout<<"P";
                        if(totalTrops == 1){
                            gotoxy(1,11); cout<<"1";
                        } else if(totalTrops == 2){
                            gotoxy(1,11); cout<<"1"; gotoxy(4,11); cout<<"2";
                        } else if(totalTrops == 3){
                            gotoxy(1,11); cout<<"1"; gotoxy(4,11); cout<<"2"; gotoxy(8,11); cout<<"3";
                        } else if(totalTrops == 4){
                            gotoxy(1,11); cout<<"1"; gotoxy(4,11); cout<<"2"; gotoxy(8,11); cout<<"3"; gotoxy(15,11); cout<<"4";
                        } else if(totalTrops == 5){
                            gotoxy(1,11); cout<<"1"; gotoxy(4,11); cout<<"2"; gotoxy(8,11); cout<<"3"; gotoxy(15,11); cout<<"4"; gotoxy(19,11); cout<<"5";
                        } else if(totalTrops == 6){
                            gotoxy(1,11); cout<<"1"; gotoxy(4,11); cout<<"2"; gotoxy(8,11); cout<<"3"; gotoxy(15,11); cout<<"4"; gotoxy(19,11); cout<<"5"; gotoxy(23,11); cout<<"6";
                        }
                        gotoxy(0,12);  cout<<"========================="<<endl;   gotoxy(26,12); cout<<"==============="<<endl;
                        gotoxy(0,13);  cout<<"|                       |"<<endl;   gotoxy(26,13); cout<<"| Enemy HP    |"<<endl;
                        gotoxy(1,13);  cout<<"Damage Hero  : "<<Damage;
                        gotoxy(0,14);  cout<<"|                       |"<<endl;   gotoxy(26,14); cout<<"|             |"<<endl;
                        gotoxy(1,14);  cout<<"Damage Troops : "<<DamageTrops;
                        gotoxy(0,15);  cout<<"========================="<<endl;   gotoxy(28,14); cout<<HPmusuh<<" / "<<tampungHP<<endl;
                                                                                  gotoxy(26,15); cout<<"==============="<<endl;
                        TropAtk += 100;
                        if(TropAtk == 1000){
                            if(totalTrops == 1){
                                gotoxy(1,11); cout<<"1";
                                gotoxy(1,10); cout<<"."; gotoxy(1,9); cout<<"."; gotoxy(1,8); cout<<".";
                            } else if(totalTrops == 2){
                                gotoxy(1,11); cout<<"1";
                                gotoxy(1,10); cout<<"."; gotoxy(1,9); cout<<"."; gotoxy(1,8); cout<<".";
                                gotoxy(4,11); cout<<"2";
                                gotoxy(4,10); cout<<"."; gotoxy(4,9); cout<<"."; gotoxy(4,8); cout<<".";
                            } else if(totalTrops == 3){
                                gotoxy(1,11); cout<<"1";
                                gotoxy(1,10); cout<<"."; gotoxy(1,9); cout<<"."; gotoxy(1,8); cout<<".";
                                gotoxy(4,11); cout<<"2";
                                gotoxy(4,10); cout<<"."; gotoxy(4,9); cout<<"."; gotoxy(4,8); cout<<".";
                                gotoxy(8,11); cout<<"3";
                                gotoxy(8,10); cout<<"."; gotoxy(8,9); cout<<"."; gotoxy(8,8); cout<<".";
                            } else if(totalTrops == 4){
                                gotoxy(1,11); cout<<"1";
                                gotoxy(1,10); cout<<"."; gotoxy(1,9); cout<<"."; gotoxy(1,8); cout<<".";
                                gotoxy(4,11); cout<<"2";
                                gotoxy(4,10); cout<<"."; gotoxy(4,9); cout<<"."; gotoxy(4,8); cout<<".";
                                gotoxy(8,11); cout<<"3";
                                gotoxy(8,10); cout<<"."; gotoxy(8,9); cout<<"."; gotoxy(8,8); cout<<".";
                                gotoxy(15,11); cout<<"4";
                                gotoxy(15,10); cout<<"."; gotoxy(15,9); cout<<"."; gotoxy(15,8); cout<<".";
                            } else if(totalTrops == 5){
                                gotoxy(1,11); cout<<"1";
                                gotoxy(1,10); cout<<"."; gotoxy(1,9); cout<<"."; gotoxy(1,8); cout<<".";
                                gotoxy(4,11); cout<<"2";
                                gotoxy(4,10); cout<<"."; gotoxy(4,9); cout<<"."; gotoxy(4,8); cout<<".";
                                gotoxy(8,11); cout<<"3";
                                gotoxy(8,10); cout<<"."; gotoxy(8,9); cout<<"."; gotoxy(8,8); cout<<".";
                                gotoxy(15,11); cout<<"4";
                                gotoxy(15,10); cout<<"."; gotoxy(15,9); cout<<"."; gotoxy(15,8); cout<<".";
                                gotoxy(19,11); cout<<"5";
                                gotoxy(19,10); cout<<"."; gotoxy(19,9); cout<<"."; gotoxy(19,8); cout<<".";
                            } else if(totalTrops == 6){
                                gotoxy(1,11); cout<<"1";
                                gotoxy(1,10); cout<<"."; gotoxy(1,9); cout<<"."; gotoxy(1,8); cout<<".";
                                gotoxy(4,11); cout<<"2";
                                gotoxy(4,10); cout<<"."; gotoxy(4,9); cout<<"."; gotoxy(4,8); cout<<".";
                                gotoxy(8,11); cout<<"3";
                                gotoxy(8,10); cout<<"."; gotoxy(8,9); cout<<"."; gotoxy(8,8); cout<<".";
                                gotoxy(15,11); cout<<"4";
                                gotoxy(15,10); cout<<"."; gotoxy(15,9); cout<<"."; gotoxy(15,8); cout<<".";
                                gotoxy(19,11); cout<<"5";
                                gotoxy(19,10); cout<<"."; gotoxy(19,9); cout<<"."; gotoxy(19,8); cout<<".";
                                gotoxy(23,11); cout<<"6";
                                gotoxy(23,10); cout<<"."; gotoxy(23,9); cout<<"."; gotoxy(23,8); cout<<".";
                            }
                            HPmusuh -= DamageTrops;
                            if(DamageTrops > 0){
                                Gold += rand()%(Level+DamageTrops)+1;
                            }
                            TropAtk = 0;
                        }
                        if(Level == Levelctr){
                            timer += 100;
                            if(timer == 1000){
                                second--;
                                timer=0;
                            }
                            gotoxy(0,16);  cout<<"========================="<<endl;
                            gotoxy(0,17);  cout<<"|                       |"<<endl;
                            gotoxy(2,17);  cout<<second<<" second Remaining"<<endl;
                            gotoxy(0,18);  cout<<"========================="<<endl;
                            if(second == 0){
                                if(HPmusuh > 0){
                                    Level--;
                                    HPmusuh = HPsebelum;
                                    tampungHP = HPmusuh;
                                    gotoxy(0,19);  cout<<"========================="<<endl;
                                    gotoxy(0,20);  cout<<"|                       |"<<endl;
                                    gotoxy(1,20);  cout<<"Gagal mengalahkan boss"<<endl;
                                    gotoxy(0,21);  cout<<"========================="<<endl;
                                    getch();
                                }
                            }
                        }
                        if(kbhit()){
                            key = getch();
                            if(key == 'q' || key == 'Q'){
                                quit = true;
                                menuplay = '0';
                            } else if(key == 's' || key == 'S'){
                                ofstream save("save.txt");
                                if(save.is_open()){
                                    cout<<"Save berhasil"<<endl;
                                    system("pause");
                                    save<<Nama<<endl;
                                    save<<Gold<<endl;
                                    save<<Level<<endl;
                                    save<<Damage<<endl;
                                    save<<DamageTrops<<endl;
                                    save<<totalTrops<<endl;
                                    save<<HPmusuh<<endl;
                                    save<<tampungHP<<endl;
                                    save<<HPsebelum<<endl;
                                    save<<Soft<<endl;
                                    save<<Medium<<endl;
                                    save<<Hard;
                                }
                                save.close();
                            } else if(key == 'u' || key == 'U'){
                                char menuUpgrade;
                                do{
                                    system("cls");
                                    gotoxy(0,0); cout<<"========================="<<endl; gotoxy(26,0);  cout<<"==============="<<endl;
                                    gotoxy(0,1); cout<<"|        UPGRADE        |"<<endl; gotoxy(26,1);  cout<<"| INFORMATION |"<<endl;
                                    gotoxy(0,2); cout<<"========================="<<endl; gotoxy(26,2);  cout<<"==============="<<endl;
                                    gotoxy(0,3); cout<<"|1. Damage(+10%)        |"<<endl; gotoxy(26,3);  cout<<"| 1x Upgrade  |"<<endl;
                                    gotoxy(0,4); cout<<"|2. Up. Dmg Troops(+10%)|"<<endl; gotoxy(26,4);  cout<<"|    Damage   |"<<endl;
                                    gotoxy(0,5); cout<<"|0. BACK                |"<<endl; gotoxy(26,5);  cout<<"|             |"<<endl;
                                    gotoxy(0,6); cout<<"|                       |"<<endl; gotoxy(28,5);  cout<<"Cost "<<Damage*Level<<" G.";
                                    gotoxy(1,6);  cout<<"Gold    : "<<Gold;
                                    gotoxy(0,7); cout<<"========================="<<endl; gotoxy(26,6);  cout<<"| 1x Upgrade  |"<<endl;
                                    gotoxy(0,8); cout<<"|                       |"<<endl; gotoxy(26,7);  cout<<"|Damage Troops|"<<endl;
                                    gotoxy(0,9); cout<<"========================="<<endl; gotoxy(26,8);  cout<<"|             |"<<endl;
                                                                                          gotoxy(28,8);  cout<<"Cost "<<DamageTrops*totalTrops*Level<<" G.";
                                                                                          gotoxy(26,9);  cout<<"==============="<<endl;
                                    gotoxy(6,8); cout<<"Choose : "; cin>>menuUpgrade;
                                    if(menuUpgrade == '1'){
                                        if(Gold>=(Damage*Level)){
                                            Gold -= (Damage*Level);
                                            if(Damage<10){
                                                Damage += 1;
                                            } else{
                                                Damage += (Damage*1/10);
                                            }
                                        }
                                    } else if(menuUpgrade == '2'){
                                        if(Gold>=(DamageTrops*totalTrops*Level)){
                                            Gold -= (DamageTrops*totalTrops*Level);
                                            if(DamageTrops<10){
                                                DamageTrops += 1;
                                            } else{
                                                DamageTrops += (DamageTrops*1/10);
                                            }
                                        }
                                    }
                                } while(menuUpgrade != '0');
                            } else if(key == 'p' || key == 'P'){
                                system("cls");
                                char menuShop;
                                do{
                                    gotoxy(0,0);  cout<<"========================="<<endl; gotoxy(26,0);  cout<<"==============="<<endl;
                                    gotoxy(0,1);  cout<<"|          SHOP         |"<<endl; gotoxy(26,1);  cout<<"| INFORMATION |"<<endl;
                                    gotoxy(0,2);  cout<<"========================="<<endl; gotoxy(26,2);  cout<<"==============="<<endl;
                                    gotoxy(0,3);  cout<<"|   1. Buy 1 Troops     |"<<endl; gotoxy(26,3);  cout<<"|  1 Troops   |"<<endl;
                                    gotoxy(0,4);  cout<<"|   2. Buy Weapon Hero  |"<<endl; gotoxy(26,4);  cout<<"|  Cost 30G   |"<<endl;
                                    gotoxy(0,5);  cout<<"|   0. BACK             |"<<endl; gotoxy(26,5);  cout<<"|             |"<<endl;
                                    gotoxy(0,6);  cout<<"========================="<<endl; gotoxy(26,6);  cout<<"|3 Tipe Weapon|"<<endl;
                                    gotoxy(0,7);  cout<<"|                       |"<<endl; gotoxy(26,7);  cout<<"==============="<<endl;
                                    gotoxy(0,8);  cout<<"========================="<<endl;
                                    gotoxy(6,7); cout<<"Choose : "; cin>>menuShop;
                                    if(menuShop == '1'){
                                        if(totalTrops < 6){
                                            if(Gold>=30){
                                                totalTrops++;
                                                DamageTrops++;
                                                Gold -= 30;
                                            }
                                        }
                                    } else if(menuShop == '2'){
                                        char menuweapon;
                                        do{
                                            gotoxy(0,0);  cout<<"========================="<<endl; gotoxy(26,0);  cout<<"======================="<<endl;
                                            gotoxy(0,1);  cout<<"|         WEAPON        |"<<endl; gotoxy(26,1);  cout<<"|     INFORMATION     |"<<endl;
                                            gotoxy(0,2);  cout<<"========================="<<endl; gotoxy(26,2);  cout<<"======================="<<endl;
                                            gotoxy(0,3);  cout<<"|   1. Weapon Soft      |"<<endl; gotoxy(26,3);  cout<<"|        Soft         |"<<endl;
                                            gotoxy(0,4);  cout<<"|   2. Weapon Medium    |"<<endl; gotoxy(26,4);  cout<<"|      Cost 10G       |"<<endl;
                                            gotoxy(0,5);  cout<<"|   3. Weapon Hard      |"<<endl; gotoxy(26,5);  cout<<"|       Medium        |"<<endl;
                                            gotoxy(0,6);  cout<<"|   0. BACK             |"<<endl; gotoxy(26,6);  cout<<"|      Cost 50G       |"<<endl;
                                                                                                   gotoxy(26,7);  cout<<"|        Hard         |"<<endl;
                                            gotoxy(0,7);  cout<<"========================="<<endl; gotoxy(26,8);  cout<<"|      Cost 100G      |"<<endl;
                                            gotoxy(0,8);  cout<<"|                       |"<<endl; gotoxy(26,9);  cout<<"| Soft +10 Damage     |"<<endl;
                                            gotoxy(0,9);  cout<<"========================="<<endl; gotoxy(26,10); cout<<"| Medium +50 Damage   |"<<endl;
                                                                                                   gotoxy(26,11); cout<<"| Hard +100 Damage    |"<<endl;
                                                                                                   gotoxy(26,12); cout<<"======================="<<endl;
                                            gotoxy(6,8); cout<<"Choose : "; cin>>menuweapon;
                                            if(menuweapon == '1'){
                                                if(Soft == 0){
                                                    if(Gold >= 10){
                                                        Gold -= 10;
                                                        Soft = 1;
                                                        Damage += 10;
                                                    }
                                                } else{
                                                    gotoxy(0,10); cout<<"========================="<<endl;
                                                    gotoxy(0,11); cout<<"|                       |"<<endl;
                                                    gotoxy(2,11); cout<<"Sudah pernah dibeli"<<endl;
                                                    gotoxy(0,12); cout<<"========================="<<endl;
                                                    getch();
                                                }
                                            } else if(menuweapon == '2'){
                                                if(Medium == 0){
                                                    if(Gold >= 50){
                                                        Gold -= 50;
                                                        Medium = 1;
                                                        Damage += 50;
                                                    }
                                                } else{
                                                    gotoxy(0,10); cout<<"========================="<<endl;
                                                    gotoxy(0,11); cout<<"|                       |"<<endl;
                                                    gotoxy(2,11); cout<<"Sudah pernah dibeli"<<endl;
                                                    gotoxy(0,12); cout<<"========================="<<endl;
                                                    getch();
                                                }
                                            } else if(menuweapon == '3'){
                                                if(Hard == 0){
                                                    if(Gold >= 100){
                                                        Gold -= 100;
                                                        Hard = 1;
                                                        Damage += 100;
                                                    }
                                                } else{
                                                    gotoxy(0,10); cout<<"========================="<<endl;
                                                    gotoxy(0,11); cout<<"|                       |"<<endl;
                                                    gotoxy(2,11); cout<<"Sudah pernah dibeli"<<endl;
                                                    gotoxy(0,12); cout<<"========================="<<endl;
                                                    getch();
                                                }
                                            }
                                            Sleep(100); system("cls");
                                        } while(menuweapon != '0');
                                    }
                                    Sleep(100); system("cls");
                                }while(menuShop != '0');
                            } else{
                                hit=true;
                                gotoxy(12,10); cout<<"*"; gotoxy(12,9); cout<<"*"; gotoxy(12,8); cout<<"*";
                            }
                        }
                        if(hit==true){
                            HPmusuh -= Damage;
                            Gold += rand()%(Level+Damage)+1;
                            hit=false;
                        }
                        if(HPmusuh <= 0){
                            if(Level == Levelctr){
                                gotoxy(26,12); cout<<"==============="<<endl;
                                gotoxy(26,13); cout<<"| Enemy HP    |"<<endl;
                                gotoxy(26,14); cout<<"|             |"<<endl;
                                gotoxy(28,14); cout<<HPmusuh<<" / "<<tampungHP<<endl;
                                gotoxy(26,15); cout<<"==============="<<endl;
                                system("Color 0A");
                                PlaySound(TEXT("victory.wav"),NULL,SND_LOOP|SND_ASYNC);
                                gotoxy(0,16);  cout<<"========================="<<endl;
                                gotoxy(0,17);  cout<<"|                       |"<<endl;
                                gotoxy(2,17);  cout<<"berhasil mengalahkan";
                                gotoxy(0,18);  cout<<"|                       |"<<endl;
                                gotoxy(9,18);  cout<<"BOSS"<<endl;
                                gotoxy(0,19);  cout<<"|                       |"<<endl;
                                gotoxy(6,19);  cout<<"BABAK BONUS"<<endl;
                                gotoxy(0,20);  cout<<"|                       |"<<endl;
                                gotoxy(5,20);  cout<<"MAP CHALLENGE!!!";
                                gotoxy(0,21);  cout<<"========================="<<endl;
                                if(kbhit()){
                                    PlaySound(NULL, NULL, 0);
                                }
                                system("pause");
                                system("cls");

                                char arena[24][61];
                                int x=1, y=22;
                                int jumlahbatu=44;
                                int jumlahtower=13;
                                char player = '^';
                                int xbatu[100] = {4,9,11,13,5,3,15,26,31,43,58,47,15,13,13,12,27,12,16,16,16,16,16,16,18,21,23,25,19,43,48,50,52,54,21,20,24,26,2,3,4,5,6,37};
                                int xbatu1[100] = {4,9,11,13,5,3,15,26,31,43,58,47,15,13,13,12,27,12,16,16,16,16,16,16,18,21,23,25,19,43,48,50,52,54,21,20,24,26,2,3,4,5,6,37};
                                int ybatu[100] = {20,17,17,17,17,17,17,22,21,21,19,22,12,11,12,10,6,6,6,5,4,3,2,1,5,3,5,3,1,17,17,17,17,17,19,19,11,11,12,12,12,12,12,17};
                                int ybatu1[100] = {20,17,17,17,17,17,17,22,21,21,19,22,12,11,12,10,6,6,6,5,4,3,2,1,5,3,5,3,1,17,17,17,17,17,19,19,11,11,12,12,12,12,12,17};
                                int xtower[100] = {5,1,17,19,1,1,40,45,34,1,1,1,1}, ytower[100] = {22,16,15,12,7,1,16,16,16,3,5,9,11};
                                int xtower1[100] = {5,1,17,19,1,1,40,45,34,1,1,1,1}, ytower1[100] = {22,16,15,12,7,1,16,16,16,3,5,9,11};
                                int xpeluru[100] = {5,1,17,19,1,1,40,45,34,1,1,1,1}, ypeluru[100] = {22,16,15,12,7,1,16,16,16,3,5,9,11};
                                int xpeluru1[100] = {5,1,17,19,1,1,40,45,34,1,1,1,1}, ypeluru1[100] = {22,16,15,12,7,1,16,16,16,3,5,9,11};
                                int jumlahmusuh=15;
                                int xM[100] = {17,8,41,46,41,33,55,49,30,32,20,21,11,24,22}, yM[100] = {19,21,7,5,12,3,13,2,13,5,8,4,19,1,2};
                                int xM_1[100] = {17,8,41,46,41,33,55,49,30,32,20,21,11,24,22}, yM_1[100] = {19,21,7,5,12,3,13,2,13,5,8,4,19,1,2};
                                int jumlahM=3;
                                int xM1[100] = {37,44,51}, yM1[100] = {20,20,22};
                                int xM1_1[100] = {37,44,51}, yM1_1[100] = {20,20,22};
                                int nyawa=5;
                                int jumlahhealth=7;
                                int xHealth[100] = {7,23,22,1,26,58,28}, yHealth[100] = {22,19,15,13,1,1,1};
                                int jumlahCP = 4;
                                int xCP[100] = {23,26,11,28}, yCP[100] = {18,15,4,8};
                                int xCekP = 1, yCekP = 22;
                                bool game = true, dead = false, jalan[100] = {true};
                                char gerak;
                                char pantul=254;
                                char cekpoint=128;
                                char tangga=177;
                                bool music=false;
                                int xtangga=54, ytangga=14;
                                PlaySound(TEXT("bg.wav"),NULL,SND_LOOP|SND_ASYNC);
                                while(game == true){
                                    cetakMap(arena, x, y, xbatu, ybatu, jumlahbatu, xtower, ytower, jumlahtower, ypeluru, xpeluru, player, xM, yM, jumlahmusuh, nyawa, xHealth, yHealth, jumlahhealth, xM1, yM1, jumlahM, xCP, yCP, jumlahCP, xtangga, ytangga, Nama);
                                    if(arena[ypeluru[0]-1][xpeluru[0]] == arena[y][x]){
                                        nyawa--;
                                        dead=true; music=true;
                                    }
                                    if(arena[ypeluru[1]][xpeluru[1]+1] == arena[y][x]){
                                        nyawa--;
                                        dead=true; music=true;
                                    }
                                    if(arena[ypeluru[2]][xpeluru[2]-1] == arena[y][x]){
                                        nyawa--;
                                        dead=true; music=true;
                                    }
                                    if(arena[ypeluru[3]][xpeluru[3]+1] == arena[y][x]){
                                        nyawa--;
                                        dead=true; music=true;
                                    }
                                    if(arena[ypeluru[4]][xpeluru[4]+1] == arena[y][x]){
                                        nyawa--;
                                        dead=true; music=true;
                                    }
                                    if(arena[ypeluru[5]][xpeluru[5]+1] == arena[y][x]){
                                        nyawa--;
                                        dead=true; music=true;
                                    }
                                    if(arena[ypeluru[6]+1][xpeluru[6]] == arena[y][x]){
                                        nyawa--;
                                        dead=true; music=true;
                                    }
                                    if(arena[ypeluru[7]+1][xpeluru[7]] == arena[y][x]){
                                        nyawa--;
                                        dead=true; music=true;
                                    }
                                    if(arena[ypeluru[8]+1][xpeluru[8]] == arena[y][x]){
                                        nyawa--;
                                        dead=true; music=true;
                                    }
                                    if(arena[ypeluru[9]][xpeluru[9]+1] == arena[y][x]){
                                        nyawa--;
                                        dead=true; music=true;
                                    }
                                    if(arena[ypeluru[10]][xpeluru[10]+1] == arena[y][x]){
                                        nyawa--;
                                        dead=true; music=true;
                                    }
                                    if(arena[ypeluru[11]][xpeluru[11]+1] == arena[y][x]){
                                        nyawa--;
                                        dead=true; music=true;
                                    }
                                    if(arena[ypeluru[12]][xpeluru[12]+1] == arena[y][x]){
                                        nyawa--;
                                        dead=true; music=true;
                                    }
                                    for(int i=0; i<jumlahM; i++){
                                        if(arena[y][x] == arena[yM1[i]][xM1[i]]){
                                            nyawa--;
                                            music=true; dead=true;
                                            i=jumlahM;
                                        }
                                    }
                                    for(int i=0; i<jumlahmusuh; i++){
                                        if(arena[y][x] == arena[yM[i]][xM[i]]){
                                            nyawa--;
                                            music=true; dead=true;
                                            i=jumlahmusuh;
                                        }
                                    }
                                    cekpeluru(arena, ypeluru, xpeluru, x, y);
                                    randomPosisiton(arena, xM, yM, jumlahmusuh, x, y);
                                    for(int i=0; i<jumlahM; i++){
                                        if(yM1[i] ==  20){
                                            jalan[i]=true;
                                        } else if(yM1[i] == 22){
                                            jalan[i]=false;
                                        }
                                    }
                                    for(int i=0; i<jumlahM; i++){
                                        if(jalan[i] == true){
                                            if(arena[yM1[i]+1][xM1[i]] == ' '){
                                                yM1[i]++;
                                            } else if(arena[yM1[i]+1][xM1[i]] == arena[y][x]){
                                                yM1[i]++;
                                            } else{
                                                jalan[i]=false;
                                            }
                                        } else{
                                            if(arena[yM1[i]-1][xM1[i]] == ' '){
                                                yM1[i]--;
                                            } else if(arena[yM1[i]-1][xM1[i]] == arena[y][x]){
                                                yM1[i]--;
                                            } else{
                                                jalan[i]=true;
                                            }
                                        }
                                    }
                                    if(dead==true){
                                        PlaySound(TEXT("deadsfx.wav"),NULL,SND_SYNC);
                                        if(music==true){
                                            music=false;
                                            PlaySound(TEXT("bg.wav"),NULL,SND_LOOP|SND_ASYNC);
                                        }
                                        x = xCekP;
                                        y = yCekP;
                                        for(int i=0; i<jumlahbatu; i++){
                                            xbatu[i] = xbatu1[i];
                                            ybatu[i] = ybatu1[i];
                                        }
                                        for(int i=0; i<jumlahtower; i++){
                                            xtower[i] = xtower1[i];
                                            ytower[i] = ytower1[i];
                                            xpeluru[i] = xpeluru1[i];
                                            ypeluru[i] = ypeluru1[i];
                                        }
                                        for(int i=0; i<jumlahmusuh; i++){
                                            xM[i] = xM_1[i];
                                            yM[i] = yM_1[i];
                                        }
                                        for(int i = 0; i<jumlahM; i++){
                                            xM1[i] = xM1_1[i];
                                            yM1[i] = yM1_1[i];
                                            jalan[i] = true;
                                        }
                                        dead = false;
                                    }
                                    if(nyawa == 0){
                                        game = false;
                                    }
                                    if(kbhit()){
                                        gerak = getch();
                                        if(gerak == 'w' || gerak == 'W'){
                                            if(arena[y-1][x] == ' '){
                                                y--;
                                            } else if(arena[y-1][x] == '@'){
                                                for(int i=0; i<jumlahbatu; i++){
                                                    if((y-1) == ybatu[i] && (x==xbatu[i])){
                                                        if(arena[ybatu[i]-1][xbatu[i]] == ' '){
                                                            ybatu[i]--;
                                                            y--;
                                                        }
                                                        i=jumlahbatu;
                                                    }
                                                }
                                            } else if(arena[y-1][x] == 3){
                                                int ctr;
                                                for(int i=0; i<jumlahhealth; i++){
                                                    if((y-1) == yHealth[i] && x == xHealth[i]){
                                                        ctr = i;
                                                        i=jumlahhealth;
                                                    }
                                                }
                                                for(int i=ctr; i<jumlahhealth; i++){
                                                    yHealth[i] = yHealth[i+1];
                                                    xHealth[i] = xHealth[i+1];
                                                }
                                                y--;
                                                jumlahhealth--;
                                                nyawa++;
                                            } else if(arena[y-1][x] == cekpoint){
                                                xCekP = x;
                                                yCekP = y-1;
                                                y--;
                                                gotoxy(4,24); changeColor(11); cout<<"Checkpoint Success ";
                                                system("pause");
                                            } else if(arena[y-1][x] == tangga){
                                                y--;
                                                game = false;
                                            }
                                            player = '^';
                                        } else if(gerak == 's' || gerak == 'S'){
                                            if(arena[y+1][x] == ' '){
                                                y++;
                                            } else if(arena[y+1][x] == '@'){
                                                for(int i=0; i<jumlahbatu; i++){
                                                    if((y+1) == ybatu[i] && (x==xbatu[i])){
                                                        if(arena[ybatu[i]+1][xbatu[i]] == ' '){
                                                            ybatu[i]++;
                                                            y++;
                                                        }
                                                        i=jumlahbatu;
                                                    }
                                                }
                                            } else if(arena[y+1][x] == 3){
                                                int ctr;
                                                for(int i=0; i<jumlahhealth; i++){
                                                    if((y+1) == yHealth[i] && x == xHealth[i]){
                                                        ctr = i;
                                                        i=jumlahhealth;
                                                    }
                                                }
                                                for(int i=ctr; i<jumlahhealth; i++){
                                                    yHealth[i] = yHealth[i+1];
                                                    xHealth[i] = xHealth[i+1];
                                                }
                                                y++;
                                                jumlahhealth--;
                                                nyawa++;
                                            } else if(arena[y+1][x] == cekpoint){
                                                xCekP = x;
                                                yCekP = y+1;
                                                y++;
                                                gotoxy(4,24); changeColor(11); cout<<"Checkpoint Success ";
                                                system("pause");
                                            } else if(arena[y+1][x] == tangga){
                                                y++;
                                                game = false;
                                            }
                                            player = 'v';
                                        } else if(gerak == 'a' || gerak == 'A'){
                                            if(arena[y][x-1] == ' '){
                                                x--;
                                            } else if(arena[y][x-1] == '@'){
                                                for(int i=0; i<jumlahbatu; i++){
                                                    if((y == ybatu[i]) && ((x-1)==xbatu[i])){
                                                        if(arena[ybatu[i]][xbatu[i]-1] == ' '){
                                                            xbatu[i]--;
                                                            x--;
                                                        }
                                                        i=jumlahbatu;
                                                    }
                                                }
                                            } else if(arena[y][x-1] == 3){
                                                int ctr;
                                                for(int i=0; i<jumlahhealth; i++){
                                                    if(y == yHealth[i] && (x-1) == xHealth[i]){
                                                        ctr = i;
                                                        i=jumlahhealth;
                                                    }
                                                }
                                                for(int i=ctr; i<jumlahhealth; i++){
                                                    yHealth[i] = yHealth[i+1];
                                                    xHealth[i] = xHealth[i+1];
                                                }
                                                x--;
                                                jumlahhealth--;
                                                nyawa++;
                                            } else if(arena[y][x-1] == cekpoint){
                                                xCekP = x-1;
                                                yCekP = y;
                                                x--;
                                                gotoxy(4,24); changeColor(11); cout<<"Checkpoint Success ";
                                                system("pause");
                                            } else if(arena[y][x-1] == tangga){
                                                x--;
                                                game = false;
                                            }
                                            player = '<';
                                        } else if(gerak == 'd' || gerak == 'D'){
                                            if(arena[y][x+1] == ' '){
                                                x++;
                                            } else if(arena[y][x+1] == '@'){
                                                for(int i=0; i<jumlahbatu; i++){
                                                    if((y == ybatu[i]) && ((x+1)==xbatu[i])){
                                                        if(arena[ybatu[i]][xbatu[i]+1] == ' '){
                                                            xbatu[i]++;
                                                            x++;
                                                        }
                                                        i=jumlahbatu;
                                                    }
                                                }
                                            } else if(arena[y][x+1] == 3){
                                                int ctr;
                                                for(int i=0; i<jumlahhealth; i++){
                                                    if(y == yHealth[i] && (x+1) == xHealth[i]){
                                                        ctr = i;
                                                        i=jumlahhealth;
                                                    }
                                                }
                                                for(int i=ctr; i<jumlahhealth; i++){
                                                    yHealth[i] = yHealth[i+1];
                                                    xHealth[i] = xHealth[i+1];
                                                }
                                                x++;
                                                jumlahhealth--;
                                                nyawa++;
                                            } else if(arena[y][x+1] == cekpoint){
                                                xCekP = x+1;
                                                yCekP = y;
                                                x++;
                                                gotoxy(4,24); changeColor(11); cout<<"Checkpoint Success ";
                                                system("pause");
                                            } else if(arena[y][x+1] == tangga){
                                                x++;
                                                game = false;
                                            }
                                            player = '>';
                                        }
                                    }
                                    Sleep(10);
                                }
                                quit=true;
                                menuplay = '0';
                            } else{
                                HPsebelum = tampungHP;
                            }
                            Level++;
                            HPmusuh = tampungHP*Level;
                            tampungHP = HPmusuh;
                            second = 30;
                        }
                    }
                    PlaySound(TEXT("gameoversfx.wav"),NULL,SND_LOOP|SND_ASYNC);
                    system("cls");
                    changeColor(112);
                    gotoxy(0,0);
                    for(int i=0; i<62; i++){
                        if(i==0){
                            cout<<ujungataskiri;
                        } else if(i==61){
                            cout<<ujungataskanan;
                        } else{
                            cout<<lurustidur;
                        }
                    }
                    gotoxy(0,1); cout<<lurusberdiri<<"                                                            "<<lurusberdiri<<endl;
                    gotoxy(0,2); cout<<lurusberdiri<<" ######   ###     #   #   #####      ###  #    # ##### ###  "<<lurusberdiri<<endl;
                    gotoxy(0,3); cout<<lurusberdiri<<" #       #   #   # # # #  #         #   # #    # #     #  # "<<lurusberdiri<<endl;
                    gotoxy(0,4); cout<<lurusberdiri<<" #  ###  #####   #  #  #  #####     #   # #    # ##### ###  "<<lurusberdiri<<endl;
                    gotoxy(0,5); cout<<lurusberdiri<<" #    # #     # #       # #         #   #  #  #  #     # #  "<<lurusberdiri<<endl;
                    gotoxy(0,6); cout<<lurusberdiri<<" ###### #     # #       # #####      ###    ##   ##### #  # "<<lurusberdiri<<endl;
                    gotoxy(0,7); cout<<lurusberdiri<<"                                                            "<<lurusberdiri<<endl;
                    gotoxy(0,8);
                    for(int i=0; i<62; i++){
                        if(i==0){
                            cout<<ujungbawahkiri;
                        } else if(i==61){
                            cout<<ujungbawahkanan;
                        } else{
                            cout<<lurustidur;
                        }
                    }
                    cout<<endl;
                    getch();
                    sound = true;
                }
            } while(menuplay != '0');
        } else if(menu == '2'){
            system("cls");
            changeColor(112);
            gotoxy(0,0);
            for(int i=0; i<62; i++){
                if(i==0){
                    cout<<ujungataskiri;
                } else if(i==61){
                    cout<<ujungataskanan;
                } else{
                    cout<<lurustidur;
                }
            }
            gotoxy(0,1); cout<<lurusberdiri<<"                                                            "<<lurusberdiri<<endl;
            gotoxy(0,2); cout<<lurusberdiri<<"                                                            "<<lurusberdiri<<endl;
            gotoxy(0,3); cout<<lurusberdiri<<"                         HOW TO PLAY                        "<<lurusberdiri<<endl;
            gotoxy(0,4); cout<<lurusberdiri<<"                                                            "<<lurusberdiri<<endl;
            gotoxy(0,5); cout<<lurusberdiri<<"                                                            "<<lurusberdiri<<endl;
            gotoxy(0,6);
            for(int i=0; i<62; i++){
                if(i==0){
                    cout<<ujungbawahkiri;
                } else if(i==61){
                    cout<<ujungbawahkanan;
                } else{
                    cout<<lurustidur;
                }
            }
            getch();
            gotoxy(0,0);
            for(int i=0; i<62; i++){
                if(i==0){
                    cout<<ujungataskiri;
                } else if(i==61){
                    cout<<ujungataskanan;
                } else{
                    cout<<lurustidur;
                }
            }
            gotoxy(0,1); cout<<lurusberdiri<<"                        TAP MONSTER                         "<<lurusberdiri<<endl;
            gotoxy(0,2); cout<<lurusberdiri<<"      S: SAVE                         other key             "<<lurusberdiri<<endl;
            gotoxy(0,3); cout<<lurusberdiri<<"      Q: QUIT                         for attack            "<<lurusberdiri<<endl;
            gotoxy(0,4); cout<<lurusberdiri<<"      P: SHOP                                               "<<lurusberdiri<<endl;
            gotoxy(0,5); cout<<lurusberdiri<<"      U: UPGRADE                                            "<<lurusberdiri<<endl;
            gotoxy(0,6);
            for(int i=0; i<62; i++){
                if(i==0){
                    cout<<ujungbawahkiri;
                } else if(i==61){
                    cout<<ujungbawahkanan;
                } else{
                    cout<<lurustidur;
                }
            }
            getch();
            gotoxy(0,0);
            for(int i=0; i<62; i++){
                if(i==0){
                    cout<<ujungataskiri;
                } else if(i==61){
                    cout<<ujungataskanan;
                } else{
                    cout<<lurustidur;
                }
            }
            gotoxy(0,1); cout<<lurusberdiri<<"                        TAP MONSTER                         "<<lurusberdiri<<endl;
            gotoxy(0,2); cout<<lurusberdiri<<"      SHOP                                                  "<<lurusberdiri<<endl;
            gotoxy(0,3); cout<<lurusberdiri<<"      BUY TROOPS AND WEAPON                                 "<<lurusberdiri<<endl;
            gotoxy(0,4); cout<<lurusberdiri<<"                                                            "<<lurusberdiri<<endl;
            gotoxy(0,5); cout<<lurusberdiri<<"      FOR UPGRDE IN MENU UPGRADE                            "<<lurusberdiri<<endl;
            gotoxy(0,6);
            for(int i=0; i<62; i++){
                if(i==0){
                    cout<<ujungbawahkiri;
                } else if(i==61){
                    cout<<ujungbawahkanan;
                } else{
                    cout<<lurustidur;
                }
            }
            getch();
            gotoxy(0,0);
            for(int i=0; i<62; i++){
                if(i==0){
                    cout<<ujungataskiri;
                } else if(i==61){
                    cout<<ujungataskanan;
                } else{
                    cout<<lurustidur;
                }
            }
            gotoxy(0,1); cout<<lurusberdiri<<"                        TAP MONSTER                         "<<lurusberdiri<<endl;
            gotoxy(0,2); cout<<lurusberdiri<<"      UPGRADE                                               "<<lurusberdiri<<endl;
            gotoxy(0,3); cout<<lurusberdiri<<"      UPGRADE DAMAGE TROOPS FOR DPS ALL TROOPS              "<<lurusberdiri<<endl;
            gotoxy(0,4); cout<<lurusberdiri<<"                                                            "<<lurusberdiri<<endl;
            gotoxy(0,5); cout<<lurusberdiri<<"      UPGRADE DAMAGE HERO +10% FROM YOUR DAMAGE             "<<lurusberdiri<<endl;
            gotoxy(0,6);
            for(int i=0; i<62; i++){
                if(i==0){
                    cout<<ujungbawahkiri;
                } else if(i==61){
                    cout<<ujungbawahkanan;
                } else{
                    cout<<lurustidur;
                }
            }
            getch();
            gotoxy(0,0);
            for(int i=0; i<62; i++){
                if(i==0){
                    cout<<ujungataskiri;
                } else if(i==61){
                    cout<<ujungataskanan;
                } else{
                    cout<<lurustidur;
                }
            }
            gotoxy(0,1); cout<<lurusberdiri<<"                        TAP MONSTER                         "<<lurusberdiri<<endl;
            gotoxy(0,2); cout<<lurusberdiri<<"      THERE ARE 5 LEVELS                                    "<<lurusberdiri<<endl;
            gotoxy(0,3); cout<<lurusberdiri<<"      LEVEL 1-4 : MINI BOSS                                 "<<lurusberdiri<<endl;
            gotoxy(0,4); cout<<lurusberdiri<<"      LEVEL 5   : BOSS (YOU HAVE TO KILL THE BOSS IN 30Sec) "<<lurusberdiri<<endl;
            gotoxy(0,5); cout<<lurusberdiri<<"      IF YOU CAN KILL THE BOSS, YOU GO TO THE MAP CHALLENGE "<<lurusberdiri<<endl;
            gotoxy(0,6);
            for(int i=0; i<62; i++){
                if(i==0){
                    cout<<ujungbawahkiri;
                } else if(i==61){
                    cout<<ujungbawahkanan;
                } else{
                    cout<<lurustidur;
                }
            }
            getch();
            gotoxy(0,0);
            for(int i=0; i<62; i++){
                if(i==0){
                    cout<<ujungataskiri;
                } else if(i==61){
                    cout<<ujungataskanan;
                } else{
                    cout<<lurustidur;
                }
            }
            gotoxy(0,1); cout<<lurusberdiri<<"                       MAP CHALLENGE                        "<<lurusberdiri<<endl;
            gotoxy(0,2); cout<<lurusberdiri<<"                                                            "<<lurusberdiri<<endl;
            gotoxy(0,3); cout<<lurusberdiri<<"   IN THIS MAP, YOU MUST GO TO THE FINISH TAG               "<<lurusberdiri<<endl;
            gotoxy(0,4); cout<<lurusberdiri<<"   W: UP   A: LEFT   S: DOWN    D: RIGHT                    "<<lurusberdiri<<endl;
            gotoxy(0,5); cout<<lurusberdiri<<"                                                            "<<lurusberdiri<<endl;
            gotoxy(0,6);
            for(int i=0; i<62; i++){
                if(i==0){
                    cout<<ujungbawahkiri;
                } else if(i==61){
                    cout<<ujungbawahkanan;
                } else{
                    cout<<lurustidur;
                }
            }
            getch();
            changeColor(11);
        }
    } while(menu != '0');
    return 0;
}
