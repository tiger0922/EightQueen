//  2016/05/02

#include <iostream>
#include <stack>
#include <cstdio>
using namespace std ;

int Ans=0 ;
int Board[8][8] ;

void Go(int **Eq , int now)
{
	//cout << endl ; 
	if(now>=8) 
	{
		int temp=0 ;
		//cout << "OHOHOHOHOHOHOH~~~~" << endl ;
		for(int i=0; i<8; i++)
		{
		 	for(int j=0; j<8; j++)
			{
				//cout << Eq[i][j] ;
				if(Eq[i][j]==9)
				{
					temp+=Board[i][j] ;
				}
			}
			//cout << endl ;
		}
		if(temp>Ans) Ans = temp ;
		//cout << endl ;
		return ; 
	}
	for(int i=0; i<8; i++)
	{
		if(Eq[now][i]==0)
		{
			Eq[now][i]=9 ;
			
			for(int j=1; now+j<8; j++)				//Vertical
				Eq[now+j][i]++ ;
			for(int j=1; now+j<8 && i+j<8; j++)		//Bottom right
				Eq[now+j][i+j]++ ;
			for(int j=1; now+j<8 && i-j>=0; j++)	//Bottom left
				Eq[now+j][i-j]++ ;
			/*
			for(int k=0; k<8; k++)
			{
				for(int s=0; s<8; s++)
					cout << Eq[k][s] ;
				cout << endl ;
			}
			*/
			Go(Eq , now+1) ;
			
			// reset
			Eq[now][i]=0 ;

			for(int j=1; now+j<8; j++)				//Vertical
				Eq[now+j][i]-- ;
			for(int j=1; now+j<8 && i+j<8; j++)		//Bottom right
				Eq[now+j][i+j]-- ;
			for(int j=1; now+j<8 && i-j>=0; j++)	//Bottom left
		 		Eq[now+j][i-j]-- ;
			
			
		} 
	}
	return  ;
}

int main()
{
	int n , times=0 ;
	int **Eq ;
	Eq = new int*[8] ;
	for(int i=0; i<8; i++)
		Eq[i] = new int[8] ;
	for(int i=0; i<8; i++)
 		for(int j=0; j<8; j++)
			Eq[i][j] = 0;
	/*
	for(int i=0; i<8; i++)
	{
 		for(int j=0; j<8; j++)
			cout << Eq[i][j] ;
		cout << endl ;
	}	
	*/
	//int Board[8][8] ;
	cin >> n ;
	while(times<n)
	{
		for(int i=0; i<8; i++)
			for(int j=0; j<8; j++)
				cin >> Board[i][j] ;
		/*
		for(int i=0; i<8; i++)
		{
		 	for(int j=0; j<8; j++)
				cout << Board[i][j] ;
			cout << endl ;
		}
		*/
		Go(Eq,0) ;
		printf("%5d\n" , Ans) ;
		Ans=0 ;
		times++ ;
	}
  	return 0 ;
}
