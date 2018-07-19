#include <iostream>                                  //five in a row game
using namespace std;
void display();
int check(int x,int y,int t);
void step(int x,int y,int t);
int chessboard[15][15]=
{
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};                                       //create an 2d array as a chessboard(size:15x15)
int main()
{
	int winner=0;
	int turn=1;
	int x;
	char y;
	cout<<"Five in a row:\nHere are the rules:\nPlayer.1's symbol:X\nPlayer.2's symbol:O\nPlease input Number+Letter\nExample:10 A(Then click Enter)\nWarning: Inputing illegal characters may cause error!\n";
	system("pause");
	display();
	while(winner==0)
	{
		if(turn==1)
		{
			cout<<"Plyaer."<<turn<<"'s turn:";
			cin>>x>>y;
			int p=(int)y-64;
			cout<<"\n\n";
			step(x,p,turn);
			winner=check(x,p,turn);
			turn=2;
		}
		else
		{
			cout<<"Player."<<turn<<"'s turn:";
			cin>>x>>y;
			int p=(int)y-64;
			cout<<"\n\n";
			step(x,p,turn);
			winner=check(x,p,turn);
			turn=1;
		}
		display();
		if(winner!=0)
		{
			cout<<"the winner now is Player."<<winner<<" ,congratulations!!";
		}
	};
	system("pause");
	return 0;
}
void display()
{
	cout<<"   ";
	for(int i=65;i<80;i++)
	{
		cout<<(char)i<<" ";
	}
	cout<<endl;
	for(int i=1;i<=15;i++)
	{
		if(i<10)
		{
			cout<<i<<"  ";
		}
		else
		{
			cout<<i<<" ";
		}
		for(int t=1;t<=15;t++)
		{
			if(0==chessboard[i-1][t-1])
			{
				cout<<"+";
			}
			else if(1==chessboard[i-1][t-1])
			{
				cout<<"X";
			}
			if(2==chessboard[i-1][t-1])
			{
				cout<<"O";
			}
			cout<<" ";
		};
		cout<<endl;
	};
	cout<<endl<<endl;
 }                                                       //display the chessboard after every step(symbol can be replaced by other char)
int check(int x,int y,int t)                            //victory conditions 
{
	int winner=0;
	int count=1;
	bool check46=1,check28=1,check19=1,check37=1;           //number means direction (eg. 46 means left and right)
	if((winner==0)&&(check46))                      //46
	{
		int p=1;
		while(count<5)
		{
			if(chessboard[x-1][y-p-1]==chessboard[x-1][y-1])
			{
				count++;
				p++;
			}
			else break;
		};
		p=1;
		while(count<5)
		{
			if(chessboard[x-1][y+p-1]==chessboard[x-1][y-1])
			{
				count++;
				p++;
			}
			else break;
		}
		if (count>=5)
		{
			winner=t;
		}
		else count=1;
	}
	if((winner==0)&&(check28))                     //28
	{
		int p=1;
		while(count<5)
		{
			if(chessboard[x-p-1][y-1]==chessboard[x-1][y-1])
			{
				count++;
				p++;
			}
			else break;
		};
		p=1;
		while(count<5)
		{
			if(chessboard[x+p-1][y-1]==chessboard[x-1][y-1])
			{
				count++;
				p++;
			}
			else break;
		}
		if(count>=5)
		{
			winner=t;
		}
		else count=1;
	}
	if((winner==0)&&(check37))                  //37
	{
		int p=1;
		while(count<5)
		{
			if(chessboard[x-p-1][y-p-1]==chessboard[x-1][y-1])
			{
				count++;
				p++;
			}
			else break;
		}
		p=1;
		while(count<5)
		{
			if(chessboard[x+p-1][y+p-1]==chessboard[x-1][y-1])
			{
				count++;
				p++;
			}
			else break;
		}
		if(count>=5)
		{
			winner=t;
		}
		else count=1;
	}
	if((winner==0)&&(check19))              //19
	{
		int p=1;
		while(count<5)
		{
			if(chessboard[x+p-1][y-p-1]==chessboard[x-1][y-1])
			{
				count++;
				p++;
			}
			else break;
		}
		p=1;
		while(count<5)
		{
			if(chessboard[x-p-1][y+p-1]==chessboard[x-1][y-1])
			{
				count++;
				p++; 
			}
			else break;
		}
		if(count>=5)
		{
			winner=t;
		}
		else count=1;
	}
	return winner;
}
void step(int x,int y,int t)
{
	chessboard[x-1][y-1]=t;
}
