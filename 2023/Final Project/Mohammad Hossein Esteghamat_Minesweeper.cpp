#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
class minesweeper {
	private:
		short int min[18][18] = {};
		char min_map[16][16];
		short int xmin[40];
		short int ymin[40];
		void Find_the_zeros(int x,int y);
		void Print_the_playground();
		void Find_the_bombs();
	public:
		minesweeper();
		bool game();  
};
minesweeper::minesweeper(){
	int i{};
    srand(time(0));
   	while(i<40){
       xmin[i]=rand() % 16+1;
       ymin[i]=rand() % 16+1;
       if(min[xmin[i]][ymin[i]] == 0){
           min[xmin[i]][ymin[i]] = -10;
       	   i++;
	   }			
	}
	//-----------
	for(i={};i<40;i++){
		min[xmin[i]-1][ymin[i]-1]++;
		min[xmin[i]-1][ymin[i]]++;
		min[xmin[i]-1][ymin[i]+1]++;
		min[xmin[i]][ymin[i]-1]++;
		min[xmin[i]][ymin[i]+1]++;
		min[xmin[i]+1][ymin[i]-1]++;
		min[xmin[i]+1][ymin[i]]++;
		min[xmin[i]+1][ymin[i]+1]++;
	}
	//-----------
	for(i={};i<18;i++){
		min[0][i]=10;
		min[17][i]=10;
		min[i][0]=10;
		min[i][17]=10;	
	}
	//-----------
	for(i={};i<16;i++){
		for(int c={};c<16;c++)
			min_map[i][c]=char(510);	
	}
	//----------	
}
void minesweeper::Print_the_playground(){
	int i{},c{};
	cout<<' '<<char(713);
	for(i={};i<33;i++)
		cout<<char(717);
	cout<<char(699)<<endl;
	
	for(i={};i<16;i++){
		cout<<char(i+65)<<char(698);
		for(c={};c<16;c++)
			cout<<' '<<min_map[i][c];
		cout<<' '<<char(698)<<endl;
	}
	cout<<' '<<char(712);
	for(i={};i<33;i++)
		cout<<char(717);
	cout<<char(700)<<endl<<"  ";
	for(i={};i<16;i++)
		cout<<' '<<char(i+65);
}
void minesweeper::Find_the_zeros(int x,int y){
    for(int i={-1};i<2;i++){
    	for(int c={-1};c<2;c++){
    		if(i==0&&c==0){
    		min_map[x-1][y-1]=' ';
    		min[x][y]=-16;	
			}else if(min[x+i][y+c]==0){
				Find_the_zeros(x+i,y+c);
			}else if(min[x+i][y+c]!=10){
				min_map[x+i-1][y+c-1]=char(min[x+i][y+c]+48);
			}
		}
	}	
}
void minesweeper::Find_the_bombs(){
	for(int i{};i<40;i++){
		min_map[xmin[i]-1][ymin[i]-1]='*';
	}	
}
bool minesweeper::game(){
	int x{},y{};
	char a[2];
	bool mode{};
	Print_the_playground();
	cout<<"\nEnter mode{mode(0)=home,mode(1)=bomb}:";
	cin>>mode;
	cout<<"\nenter x,y:";
	cin>>a[0]>>a[1];
	x=int(a[0]-64);
	y=int(a[1]-64);
	system("CLS");
	if(!mode){
		if(min[x][y] < 0 && min[x][y] > -11){
			min_map[x-1][y-1]='*';
			Find_the_bombs();
			Print_the_playground();
			cout<<"\n-----------------------Game over----------------------";
			return 1;
		}else if(min[x][y]>0){
			min_map[x-1][y-1]=char(min[x][y]+48);
			return 0;
		}else{
			Find_the_zeros(x,y);
		}
    }else{
    	if(min[x][y] < 0 && min[x][y] > -11){
    		min_map[x-1][y-1]='*';
			return 0;	
		}else{
			min_map[x-1][y-1]=char(min[x][y]+48);
			Find_the_bombs();
			Print_the_playground();
			cout<<"\n-----------------------Game over----------------------";
			return 1;
		}
	}
}
int main(){
	minesweeper mapp;
	while(!mapp.game()){}
}
