#include <iostream>

#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#include<windows.h>

using namespace std;

bool gameover;

const int width = 30;

const int height = 30;

int x, y, fruitX, fruitY, score;

int tailX[100], tailY[100]; //snake coordinates

int nTail;

enum eDirecton {STOP = 0, LEFT,RIGHT, UP, DOWN}; // Controls

eDirecton dir;

void Setup() {
gameover = false;

dir = STOP;

x = width / 2;

y = height / 2;

fruitX = rand()%width; //display fruit in a random place

fruitY = rand()%height; 
score = 0;

}

void Draw() {

system("cls");

for(int i = 0; i < width+2; i++)

cout << "#";

cout << endl ;

for (int i = 0; i < height ; i++) {

for (int j = 0; j < width; j++) {

if (j == 0)

cout << "#"; //walls

if (i == y && j == x)

cout << "O"; // snake tale

else if (i == fruitY && j == fruitX )

cout << "*"; // change it to change the fruit

else {

bool print = false;

for (int k = 0; k< nTail ; k++) {

if (tailX [k] == j && tailY [k] == i) {

cout << "o"; print = true;

}

}

if (!print) cout << " ";

}

if (j == width -1)

cout << "#";

}

cout << endl;

}

for (int i = 0; i< width+2; i++)

cout << "#";

cout << endl;

cout << "Score:" << score << endl ;


}

void Input ()
{

if (_kbhit ()) {
	

switch (_getch ()) {
	

case 'a':

dir = LEFT;

break;

case 'd':

dir = RIGHT;

break;

case 'w':

dir = UP;

break;

case 's':

dir = DOWN ;

break;

case 'x':

gameover = true;

break;

}

}

}

void algorithm()
{

int prevX = tailX [0];

int prevY = tailY [0];

int prev2X, prev2Y;

tailX[0] = x;

tailY[0] = y;

for(int i = 1;i < nTail ; i++) {

prev2X = tailX[i];

prev2Y = tailY[i];

tailX[i] = prevX;

tailY[i] = prevY;

prevX = prev2X;

prevY = prev2Y ;

}

switch (dir) {

case LEFT:

x--;

break;

case RIGHT:

x++;

break;

case UP:

y--;

break;

case DOWN:

y++;

break;

default:

break;

}

if (x >= width) x =0;else if (x <0) x = width -1;

if (y >= height) y = 0; else if (y < 0) y = height - 1;

for (int i =0; i< nTail ;i++)

if (tailX[i] == x && tailY[i] == y)
gameover = true;

if (x == fruitX && y == fruitY) {

score +=10;

fruitX = rand() % width;

fruitY = rand() % height;

nTail ++;

}

}

int main()
{
	
	
	int v;
	system("color B1");
	cout<<endl<<endl;
	cout<<"                ###############   #######               #####             #####               ####             ####  #### #################   "<<endl;
	cout<<"                ###############   ##### ####            #####             ## ##               ####             ###   #### #################   "<<endl;
	cout<<"                ###############   ##### ####            #####            ### ###              ####           ###     #### #################   "<<endl;
	cout<<"                ###############   #####   ####          #####            ### ###              ####          ###      ####                     "<<endl;
	cout<<"                ####              #####   ####          #####           ###   ###             ####         ###       ####                     "<<endl;
	cout<<"                ####              #####     ####        #####           ###   ###             ####        ###        ####                     "<<endl;
	cout<<"                ####              #####     ####        #####          ###      ###           ####       ###         ####                     "<<endl;
	cout<<"                ####              #####      ####       #####          ###      ###           ####      ###          ####                     "<<endl;
	cout<<"                ###############   #####      ####       #####         ###        ###          ####    ###            ####                     "<<endl;
	cout<<"                ###############   #####       ####      #####         ###        ###          ####   ###             #### ###########         "<<endl;
	cout<<"                ###############   #####       ####      #####        ####         ####        #######                #### ###########         "<<endl;
	cout<<"                ###############   #####        ####     #####        ####         ####        ####   ###             ####                     "<<endl;
	cout<<"                           ####   #####        ####     #####       ##################        ####    ###            ####                     "<<endl;
	cout<<"                           ####   #####         ####    #####       ####           ####       ####     ###           ####                     "<<endl;
	cout<<"                           ####   #####         ####    #####      ####             ####      ####      ###          ####                     "<<endl;
	cout<<"                           ####   #####          ###    #####      ####             ####      ####       ###         ####                     "<<endl;
	cout<<"                ###############   #####          ####   #####     ####               ####     ####        ###        ####                     "<<endl;
	cout<<"                ###############   #####           ####  #####     ####               ####     ####          ###      #### #################   "<<endl;
	cout<<"                ###############   #####            #### #####    ####                 ####    ####           ###     #### #################   "<<endl;
	cout<<"                ###############   #####               #######    ####                 ####    ####            ####   #### #################   "<<endl;
	cout<<"\n\n";
	cout<<"\t\t                #############           ###          ####             ####   ### ########    "<<endl;
	cout<<"\t\t                #############         ##   ##        ### ###       ### ###   ### ########    "<<endl;
	cout<<"\t\t                ###                  ###   ###       ###  ###     ###  ###   ###             "<<endl;
	cout<<"\t\t                ###                 ###     ###      ###    ### ###    ###   ###             "<<endl;
	cout<<"\t\t                ###    ######      ###       ###     ###     ####      ###   ### #####       "<<endl;
	cout<<"\t\t                ###    ######      #############     ###               ###   ### #####       "<<endl;
	cout<<"\t\t                ###       ###     ###         ###    ###               ###   ###             "<<endl;
	cout<<"\t\t                ###       ###     ###         ###    ###               ###   ###             "<<endl;
	cout<<"\t\t                #############    ###           ###   ###               ###   ### ########    "<<endl;
	cout<<"\t\t                #############    ###           ###   ###               ###   ### ########    "<<endl<<endl;
	
	system("pause");
	
	system("cls");
	cout<<"\t\t\t\t\t\t\t\t\t\tMain Menu"<<endl;
	cout<<"________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________"<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\tStart Game"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\tLevel"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\tGame Type"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\tInstructions"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\tHigh Scores"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\tExit"<<endl;
	cin>>v;
	
	
	
	Setup();
	
	switch(v){
	case 1:
	
	
	while (!gameover) {
	
	Draw ();
	
	Input ();
	
	algorithm ();
	Sleep(20);
	

}

}

return 0;

}
