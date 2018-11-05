#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>
#include <iomanip>
using namespace std;

class RPQ
{
	int cmax, Size;
	int *R, *P, *Q, *N;
	
	void wyswietl(){
		cout<<endl;
		for (int i=0;i<Size;i++){
			cout<<setw(2)<<N[i]<<". "<<setw(5)<<R[i]<<setw(5)<<P[i]<<setw(6)<<Q[i]<<endl;
		}
	}

	void load(char *name)
	{
		ifstream file;
		file.open(name);

		file>>Size;
		cout<<" \n Size = "<<Size<<endl;
		
		R = new int [Size];
		P = new int [Size];
		Q = new int [Size];
		N = new int [Size];
			
		for (int i=0; i<Size; i++)
		{
			file>>R[i]>>P[i]>>Q[i]; 
			N[i]=i+1;  
			
			cout<<setw(2)<<N[i]<<". "<<setw(5)<<R[i]<<setw(5)<<P[i]<<setw(6)<<Q[i]<<endl;
		}
		file.close();
	}
		
	int CCmax(int size)
	{
		int Qend[size];
		cmax = 0;		
				
		for(int i=0;i<size;i++)
		{
			if(R[i]>cmax) cmax+=R[i]-cmax;
			cmax+=P[i];
			Qend[i] = cmax +Q[i]; 
		}
			
		for (int i=0;i<size;i++)
		{
			if (Qend[i]>cmax) cmax = Qend[i];
		}
			
		cout<<"\n Cmax = "<<cmax<<endl;
		return cmax;
	}
		
	void menu()
	{
		char cc;
		do
		{
			cout<<"\n Problem jednomaszynowy RPQ"<<endl;
			cout<<" 1. Wczytaj dane"<<endl;
			cout<<" 2. Oblicz Cmax"<<endl;
			cout<<" 3. Sortuj zadania"<<endl;
			cout<<" 4. Wyswietl"<<endl;
			cout<<" 0. Zakoncz"<<endl;
			cc=getch();
			switch(cc)
			{
				case '1': 					
					cout<<"\n Wczytaj dane:"<<endl;
					cout<<" 1. data1 (4)"<<endl;
					cout<<" 2. data2 (24) "<<endl;
					cout<<" 3. data3 (24)"<<endl;
					cout<<" 4. data4 (48)"<<endl;
					cout<<" 5. data5 (48)"<<endl;
					cout<<" 6. data6 (50)"<<endl;
					cout<<" 7. data7 (50)"<<endl;
					cout<<" 8. data8 (50)"<<endl;
					cc=getch();
					
					switch(cc){
						case '1':
							load("d1.txt");
							break;
						case '2':
							load("d2.txt");
							break;
						case '3':
							load("d3.txt");
							break;
						case '4':
							load("d4.txt");
							break;
						case '5':
							load("d5.txt");
							break;
						case '6':
							load("d6.txt");
							break;
						case '7':
							load("d7.txt");
							break;
						case '8':
							load("d8.txt");
							break;
					}
					break;
				
				case '2': 
					CCmax(Size);
					break;
					
				case '3':
					cout<<"\n Sortuj zadania:"<<endl;
					cout<<" 1. Schrage Sort"<<endl;
					cout<<" 2. Sort by R "<<endl;	
					cout<<" 3. Sort by Q "<<endl;
					
					cc=getch();
					int a,b;
					switch(cc){
						case '1':
							schrage();
							wyswietl();
							CCmax(Size);
							break;
						case '2':
							cout<<"\n Przedzial A->B: ";
							cin>>a>>b;
							sortR(a, b);
							wyswietl();
							CCmax(Size);
							break;
						case '3':
							cout<<"\n Przedzial A->B: ";
							cin>>a>>b;
							sortQ(a, b);
							wyswietl();
							CCmax(Size);
						break;
						}
					break;
					
				case '4':
					wyswietl();
					break;
					
					
				case '0':
					cout<<" Shutdown.."<<endl;
					break;
				
				default :
					cout<<cc<<" - not defined"<<endl;
					break;
				
			}
		}while(cc!='0');
	}
	
	int CmaxbezQ(int R[], int P[], int Q[],int size){
		int Cmax=0;	
		for(int i=0;i<size;i++){
			Cmax=max(Cmax,R[i]);
			Cmax+=P[i];
		}
		return Cmax;
	}

	void sortQ(int p,int k)
	{
    	for( int i = p; i < k; i++ )
    	{
        	for( int j = p; j < k - 1; j++ )
        	{
        		if( Q[ j ] < Q[ j + 1 ] )
				{
            		swap(P[j], P[j+1]);
                	swap(R[j], R[j+1]);
                	swap(Q[j], Q[j+1]);
                	swap(N[j], N[j+1]);
      			}
        	}
    	}
	}

	void sortR(int p, int k)
	{
    	for( int i = 0; i < Size; i++ )
    	{
        	for( int j = 0; j < Size - 1; j++ )
        	{
        		if( R[ j ] > R[ j + 1 ] )
				{
                	swap(P[j], P[j+1]);
                 	swap(R[j], R[j+1]);
                 	swap(Q[j], Q[j+1]);
                 	swap(N[j], N[j+1]);
      			}
        	}
    	}	
	}

	void schrage()
	{
		int tp;
		sortR(0,Size);
		int ile,koniec;
		for(int i=1;i<Size;i++)
		{
			tp=CmaxbezQ(R,P,Q,Size);
			ile=0;
			for(int j=i;j<Size;j++) if(tp>=R[j]) ile++;
			koniec=ile+i;
			sortQ(i,koniec);
		}
	}

	public:

	RPQ()
	{
	menu();		
	}
		
	~RPQ()
	{
		delete[] R,P,Q,N;
	}
		
};



int main(){
	
RPQ rpq;
return 0;

}

