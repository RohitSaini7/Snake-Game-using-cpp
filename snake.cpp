#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
using namespace std;

bool game;
const int w =76;
const int h =15;
int x, y, o, fx, fy, scr;
int tx[100], ty[100] ;
char p[100];
int nt;
enum eDir {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDir dir;

void setup()
{
	game = false;
	dir = STOP;
	//initial smake psoition
	x = w/2;
	y = h/2;
	//random fruit position
	fx = rand() % w;
	fy = rand() % h;
	scr = 0;
}

void border()
{
	system("cls");
	cout<<"\t\t\t   --------Snake & Fruit--------\n\n";
	for(int i = 0;i < w+2; i++)
	cout<<"#";
	cout<<endl;
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			if (j == 0)
				cout<<"#";
			if(i == y && j == x)
				cout << "O";
			else if(i == fy && j == fx)
				cout << "@";
			else
			{
				bool p=false;
				for(int k = 0;k < nt; k++)
				{
					if(tx[k] == j  && ty[k] == i)
					{
						cout<<"O";
						p = true;
					}
				}
				if(!p)
					cout<<" ";
			}
			if(j == w-1)
			cout<<"#";
		}
		cout<<endl;
	}
	for(int i=0; i<w+2; i++)
	cout<<"#";
	cout<<"\n\n\t\t\t\t>>>>> Score:  "<< scr <<" <<<<<";
	cout<<"\n\t\t       **************************************\n";
	cout<<"\t\t\t  Use 'w s a d' T Control Snake(O)\n\t\t\t\t    'x' To Exit\n";
	cout<<"\tPress 'p' To Pause and Press 'p' Followed By 'ENTER' To Resume Game";
}

void in()
{
	if(_kbhit())
	{
		switch(_getch())
		{
			case 'a':
			case 'A':
			dir =LEFT;
			break;
			
			case 'd':
			case 'D':
			dir =RIGHT;
			break;
			
			case 's':
			case 'S':
			dir =DOWN;
			break;
			
			case 'w':
			case 'W':
			dir =UP;
			break;
			
			case 'x':
			case 'X':
			game=true;
			break;
			
			case 'p':
			case 'P':
			cin>>p[o];
			o++;			
			
			break;
		}
	}
}

void algo1()
{
	int px = tx[0], py = ty[0], p2x, p2y;
	tx[0] = x;
	ty[0] = y;
	
	for(int i=1; i< nt; i++)
	{
		p2x = tx[i];
		p2y = ty[i];
		tx[i] = px;
		ty[i] = py;
		px = p2x;
		py = p2y;
	}
	
	switch (dir)
	{
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
	
	if(x>=w) x= 0;
	else if(x < 0) x=w-1;
	
	if(y>=h) y= 0;
	else if(y < 0) y=h-1;
	
	for(int i = 0; i<nt; i++)
		if(tx[i] == x && ty[i] == y)
			game = true;
			
	if(x ==fx && y == fy)
	{
		scr+=10;
		fx = rand() % w;
		fy = rand() % h;
		nt++;
	}
}

void algo2()
{
	int px = tx[0], py = ty[0], p2x, p2y;
	tx[0] = x;
	ty[0] = y;
	
	for(int i=1; i< nt; i++)
	{
		p2x = tx[i];
		p2y = ty[i];
		tx[i] = px;
		ty[i] = py;
		px = p2x;
		py = p2y;
	}
	
	switch (dir)
	{
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
	
	if(x>=w) 
	game = true;
	else if( x < 0)
	game = true;
	
	if( y>=h)game = true;
	else if(y < 0)game = true;
		
	for(int i = 0; i<nt; i++)
		if(tx[i] == x && ty[i] == y)
			game = true;
			
	if(x ==fx && y == fy)
	{
		scr+=10;
		fx = rand() % w;
		fy = rand() % h;
		nt++;
	}
}

int main()
{
	cout<<"\t\t\t   --------Snake & Fruit--------\n\n";
	cout<<"\n\t\t       **************************************\n";
	cout<<"\n\t\t\t\t       RULES\n\n";
	cout<<"\t\t\t  Use 'w s a d' T Control Snake(O)\n\t\t\t\t    'x' To Exit\n";
	cout<<"\tPress 'p' To Pause and Press 'p' Followed By 'ENTER' To Resume Game\n\n\n";
	cout<<"\t\t\t   Which Mode Do U Want To Play:\n";
	cout<<"\t\t\t 1). EASY -> U Can Pass Through Wall\n";
	cout<<"\t\t\t2). HARD -> U Can't Pass Through Wall\n";
	cout<<"\t\t\t\t   Enter Choice:";
	int choice;
	cin>>choice;
	
	setup();
	if(choice == 1)
	{
		while(!game)
		{
			border();
			in();
			algo1();
			Sleep(50);
		}
	}
	
	else if(choice == 2)
	{
		while(!game)
		{
		border();
			in();
			algo2();
			Sleep(50);
		}
	}
	
	else
	{
		cout<<"Enter Valid Choice";
	}
return 0;
}
