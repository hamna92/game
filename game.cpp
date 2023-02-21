#include <iostream>
#include <windows.h>
using namespace std;
void printMaze();
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void printFireboy();
void eraseFireboy();
void moveFireboyRight();
void moveFireboyLeft();
void moveFireboyUp();
void moveFireboyDown();
void printGhost();
void eraseGhost();
void moveGhostHorizontal();
void moveGhostVertical();
void printGhost2();
void eraseGhost2();
void generateBullet();
void moveBullet();
void printBullet(int x, int y);
void eraseBullet(int x, int y);
void makeBulletInactive(int idx);
void bulletCollionWithGhost();
void bulletCollionWithGhost2();
void addScore();
void printScore();
int bulletX[100];
int bulletY[100];
bool isBulletActive[100];

    char l = 1;
    char m = 178;
    char z = 16;
    char a = 17;
    char b = 193;
    char player1[3] = {' ', l, ' '};
    char player2[3] = {a, m, z};
    char player3[3] = {' ', b, ' '};

    char i = 2;
    char j = 176;
    char o = 247;
    char t = 247;
    char enemy1[5] = {' ', ' ', i, ' ', ' '};
    char enemy2[5] = {o, j, j, j, o};
    char enemy3[5] = {' ', o, ' ', t, ' '};

int bulletCount = 0;
int score=0;
int timer = 0;
int Fx = 12;
int Fy = 42;
int Gx = 130;
int Gy = 17;
int gx = 110;
int gy = 25;
string enemy1dir = "left";
string enemy2dir = "Down";

main()
{

    system("cls");
    printMaze();
    printFireboy();
    printGhost();
    printGhost2();
    while (true)
    {
        printScore();
        
        if (GetAsyncKeyState(VK_RIGHT))
        {
            moveFireboyRight();
        }

        if (GetAsyncKeyState(VK_LEFT))
        {
            moveFireboyLeft();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            moveFireboyUp();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            moveFireboyDown();
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            generateBullet();
        }
        if(timer==3)
           {
            moveGhostHorizontal();
            moveGhostVertical();
            timer = 0;
           }
           moveBullet();
           bulletCollionWithGhost();
           bulletCollionWithGhost2();


          timer ++ ;
          Sleep(30);
        
    }
}
void printFireboy()
{
    gotoxy(Fx, Fy);
    for (int x = 0; x < 3; x++)
    {
        cout << player1[x];
    }

    gotoxy(Fx, Fy + 1);
    for (int x = 0; x < 3; x++)
    {
        cout << player2[x];
    }

    gotoxy(Fx, Fy + 2);
    for (int x = 0; x < 3; x++)
    {
        cout << player3[x];
    }
}
void eraseFireboy()
{
    gotoxy(Fx, Fy);
    for (int x = 0; x < 3; x++)
    {
        cout << " ";
    }
    gotoxy(Fx, Fy + 1);
    for (int x = 0; x < 3; x++)
    {
        cout << " ";
    }
    gotoxy(Fx, Fy + 2);
    for (int x = 0; x < 3; x++)
    {
        cout << " ";
    }
}
void moveFireboyRight()
{
    char next1 = getCharAtxy(Fx + 3, Fy);
    char next2 = getCharAtxy(Fx + 3, Fy + 1);
    char next3 = getCharAtxy(Fx + 3, Fy + 2);

    if (next1 == ' ' && next2 == ' ' && next3 == ' ') //  || next1==' ' && next2==' ' && next3==' ')
    {
        eraseFireboy();
        Fx = Fx + 1;
        printFireboy();
    }
}
void moveFireboyLeft()
{
    char next1 = getCharAtxy(Fx - 1, Fy);
    char next2 = getCharAtxy(Fx - 1, Fy + 1);
    char next3 = getCharAtxy(Fx - 1, Fy + 2);
    if (next1 == ' ' && next2 == ' ' && next3 == ' ') // ||next1==' ' && next2==' ' && next3==' ')
    {
        eraseFireboy();
        Fx = Fx - 1;
        printFireboy();
    }
}
void moveFireboyUp()
{
    char next1 = getCharAtxy(Fx, Fy - 1);
    char next2 = getCharAtxy(Fx + 1, Fy - 1);
    char next3 = getCharAtxy(Fx + 2, Fy - 1);
    if (next1 == ' ' && next2 == ' ' && next3 == ' ') //|| next1==' ' && next2==' ' && next3==' ')
    {
        eraseFireboy();
        Fy = Fy - 1;
        printFireboy();
    }
}
void moveFireboyDown()
{
    char next1 = getCharAtxy(Fx, Fy + 3);
    char next2 = getCharAtxy(Fx + 1, Fy + 3);
    char next3 = getCharAtxy(Fx + 2, Fy + 3);
    if (next1 == ' ' && next2 == ' ' && next3 == ' ') //|| next1==' ' && next2==' ' && next3==' ' )
    {
        eraseFireboy();
        Fx = Fy + 1;
        printFireboy();
    }
}
void printGhost()
{
    char i = 2;
    char j = 176;
    char o = 247;
    char t = 247;
    char enemy1[5] = {' ', ' ', i, ' ', ' '};
    char enemy2[5] = {o, j, j, j, o};
    char enemy3[5] = {' ', o, ' ', t, ' '};
    gotoxy(Gx, Gy);
    for (int x = 0; x < 5; x++)
    {
        cout << enemy1[x];
    }

    gotoxy(Gx, Gy + 1);
    for (int x = 0; x < 5; x++)
    {
        cout << enemy2[x];
    }

    gotoxy(Gx, Gy + 2);
    for (int x = 0; x < 5; x++)
    {
        cout << enemy3[x];
    }
}
void eraseGhost()
{
    gotoxy(Gx, Gy);
    for (int x = 0; x < 5; x++)
    {
        cout << " ";
    }
    gotoxy(Gx, Gy + 1);
    for (int x = 0; x < 5; x++)
    {
        cout << " ";
    }
    gotoxy(Gx, Gy + 2);
    for (int x = 0; x < 5; x++)
    {
        cout << " ";
    }
}
void moveGhostHorizontal()
{
    if (enemy1dir == "right")
    {

        char next1 = getCharAtxy(Gx + 5, Gy);
        char next2 = getCharAtxy(Gx + 5, Gy + 1);
        char next3 = getCharAtxy(Gx + 5, Gy + 2);
        if (next1 == ' ' && next2 == ' ' && next3 == ' ')
        {
            eraseGhost();
            Gx++;
            printGhost();
        }
        if (next1 == '#' && next2 == '#' && next3 == '#')
        {
            enemy1dir = "left";
        }
    }
    if (enemy1dir == "left")
    {
        char next1 = getCharAtxy(Gx - 3, Gy);
        char next2 = getCharAtxy(Gx - 3, Gy + 1);
        char next3 = getCharAtxy(Gx - 3, Gy + 2);

        if (next1 == ' ' && next2 == ' ' && next3 == ' ')
        {
            eraseGhost();
            Gx = Gx-1;
            printGhost();
        }
        if (next1 == '#' && next2 == '#' && next3 == '#')
        {
            enemy1dir = "right";
        }
    }
}
void printGhost2()
{
    
    gotoxy(gx, gy);
    for (int x = 0; x < 5; x++)
    {
        cout << enemy1[x];
    }

    gotoxy(gx, gy + 1);
    for (int x = 0; x < 5; x++)
    {
        cout << enemy2[x];
    }

    gotoxy(gx, gy + 2);
    for (int x = 0; x < 5; x++)
    {
        cout << enemy3[x];
    }
}
void eraseGhost2()
{
    gotoxy(gx, gy);
    for (int x = 0; x < 5; x++)
    {
        cout << " ";
    }
    gotoxy(gx, gy + 1);
    for (int x = 0; x < 5; x++)
    {
        cout << " ";
    }
    gotoxy(gx, gy + 2);
    for (int x = 0; x < 5; x++)
    {
        cout << " ";
    }
}
void moveGhostVertical()
{
    if (enemy2dir == "Up")
    {
        char next = getCharAtxy(gx, gy - 1);
        if (next == ' ')
        {
            eraseGhost2();
            gy--;
            printGhost2();
        }
        else if (next == '#')
        {
            enemy2dir = "Down";
        }
    }
    if (enemy2dir == "Down")
    {
        char next = getCharAtxy(gx, gy + 3);
        if (next == ' ')
        {
            eraseGhost2();
            gy++;
            printGhost2(); 
        }
        if (next == '#')
        {
            enemy2dir = "Up";
        }
    }
}
void generateBullet()
{
    bulletX[bulletCount] = Fx + 6;
    bulletY[bulletCount] = Fy;
    isBulletActive[bulletCount] = true;
    gotoxy(Fx + 6, Fy);
    cout << ".";
    bulletCount++;
    

}
void moveBullet()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (isBulletActive[x] == true)
        {
            char next = getCharAtxy(bulletX[x] + 1, bulletY[x]);
            char next1= getCharAtxy(bulletX[x] + 1, bulletY[x]+1);
            char next2 = getCharAtxy(bulletX[x] + 1, bulletY[x]+2);
            if (next != ' ' && next1 != ' ' && next2 != ' ' )
            {
                eraseBullet(bulletX[x], bulletY[x]);
                makeBulletInactive(x);
            }
            else
            {
                eraseBullet(bulletX[x], bulletY[x]);
                bulletX[x] = bulletX[x] + 1;
                printBullet(bulletX[x], bulletY[x]);
            }
        }
    }
}
void printBullet(int x, int y)
{
    gotoxy(x, y);
    cout << ".";
}
void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void makeBulletInactive(int idx)
{
    isBulletActive[idx] = false;
}
void bulletCollionWithGhost()
{
    for(int x=0 ; x < bulletCount; x++)
    {
        if(isBulletActive[x]==true)
        {
        
            if(bulletX[x]+1==Gx && (bulletY[x]==Gy|| bulletY[x]==Gy+2 || bulletY[x]==Gy+3))
            {
                addScore();
            }
            if(Gx-1 == bulletX[x]&& Gy+1==bulletY[x])
            {
                addScore();
            }
            if(bulletX[x]+5==gx&&(bulletY[x]==Gy|| bulletY[x]==Gy+2 || bulletY[x]==Gy+3))
            {
                addScore();
            }
        }
       
    }
}
void bulletCollionWithGhost2()

{
    for(int x=0 ; x < bulletCount; x++)
    {
        if(isBulletActive[x]==true)
        {
        
            if(bulletX[x]+1==gx && (bulletY[x]==gy|| bulletY[x]==gy+2 || bulletY[x]==gy+3))
            {
                addScore();
                
            }
            if(gx-1 == bulletX[x]&& gy+1==bulletY[x])
            {
                addScore();
            }
            if(bulletX[x]+5==gx&&(bulletY[x]==gy|| bulletY[x]==gy+2 || bulletY[x]==gy+3))
            {
                addScore();
                
            }
        }
       
    }
}
void addScore()
{
    score++;
}
void printScore()
{
    gotoxy(185,11);
    cout<<"score : " <<score;
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void printMaze()
{
    cout << "############################################################################################################################################################" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#                                                                                 %                                                                        #" << endl;
    cout << "#    ################                         ##############               ###############                                                                 #" << endl;
    cout << "#                                             ##############               ###############                                                __________       #" << endl;
    cout << "#                                                                                                                                         |         |      #" << endl;
    cout << "#                                                                                                                                         |    %    |      #" << endl;
    cout << "#                                                                                                                                         |         |      #" << endl;
    cout << "#                                ##############------------------------------###############################################################################" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#                  ###################################################################---------------##################################################### #" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "####################################################---------------###################################                   ###################               #" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#                     ###########################---------------########################################                 ###################################" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "##################################################################---------------#######################                 ##############                    #" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#               ###########---------------###########################---------------####################                 ###################################" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "#                                                                                                                                                          #" << endl;
    cout << "####################################---------------#####################################################                 ######################            #" << endl;
    cout << "# _________                                                                                                                                                #" << endl;
    cout << "# |       |                                                                                                                                                #" << endl;
    cout << "# |   %   |                                                                                                                                                #" << endl;
    cout << "# |       |                                                                                                                                                #" << endl;
    cout << "#######################################################################---------------######################################################################" << endl;
}
