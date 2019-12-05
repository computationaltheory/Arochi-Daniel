#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<windows.h>

using namespace std;


/***


LUIS DANIEL AROCHI RINCÓN



**/
//X VA DE 3 EN 3 Y "Y" VA DE 2 EN 2

void gotoxy(int, int);
void printTable();
void inicializarArray(char array[3][3]);
bool libre(char arrar[3][3], int x, int y, char valor);
bool evaluarGanador(char array[3][3]);
void imprimirCaracteres(char array[3][3]);



int main(){
	char array[3][3];
	cout<<"Tic Tac Toe"<<endl;
	printTable();
	inicializarArray(array);
	bool bandera=true;
	int x, y, contador=0;
	char v;
	bool correcto=true;
	/*
	gotoxy(8,4);
	printf("x");
	*/

	do{
		do{
			if(bandera){
				v='x';
			}else{
				v='o';
			}
			gotoxy(10, 10);
			if(bandera){
				cout<<"Jugador 1: "<<endl;
			}else{
				cout<<"Jugador 2: "<<endl;
			}
			cout<<"\nDame las coordenadas en x: ";
			cin>>x;
			cout<<"\nDame las coordenadas en y: ";
			cin>>y;
			correcto=libre(array, x, y, v);
			//cout<<"El correcto da; "<<correcto;
			if(correcto){
				if(bandera){
					bandera=false;
				}else{
					bandera=true;
				}
			}
		}while(!correcto);
		contador++;
		//cout<<"VAN "<<contador<<endl;
		/*
		cout<<endl;
		for(int i=0; i<3; i++){
	 		for (int j=0; j<3; j++){
	 			cout<<array[i][j];
			 }
			 cout<<endl;
		 }*/
		 system("cls");
		 printTable();
		 imprimirCaracteres(array);
	}while(!evaluarGanador(array));
	system("cls");
	cout<<"El ganador es ";
	if(bandera){
		cout<<"el jugador 2"<<endl;
	}else{
		cout<<"el jugador 1"<<endl;
	}
	gotoxy(20,20);
	return 0;
}

//Función GOTOXY conocida por ser aquella utilizada para dibujar lineas y posicionar
void gotoxy(int x,int y){  
	HANDLE hcon;  
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
	COORD dwPos;  
	dwPos.X = x;  
	dwPos.Y= y;  
	SetConsoleCursorPosition(hcon,dwPos);  
 }
 
 void printTable(){
 	for(int i=0; i<3;  i++){
		printf(" ");
	}
	printf("%c", 186);
	for(int i=0; i<3;  i++){
		printf(" ");
	}
	printf("%c", 186);
	cout<<endl;
	for(int i=0; i<3;  i++){
		printf(" ");
	}
	printf("%c", 186);
	for(int i=0; i<3;  i++){
		printf(" ");
	}
	printf("%c", 186);
	cout<<endl;
 	//
	for(int i=0; i<3;  i++){
		printf("%c", 205);	
	}
	printf("%c", 206);
	for(int i=0; i<3;  i++){
		printf("%c", 205);	
	}
	
	printf("%c", 206);
	for(int i=0; i<3;  i++){
		printf("%c", 205);	
	}
	
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	cout<<endl;
	for(int i=0; i<3;  i++){
		printf(" ");
	}
	printf("%c", 186);
	for(int i=0; i<3;  i++){
		printf(" ");
	}
	printf("%c", 186);
	cout<<endl;
	
	
	
	for(int i=0; i<3;  i++){
		printf("%c", 205);	
	}
	printf("%c", 206);
	for(int i=0; i<3;  i++){
		printf("%c", 205);	
	}
	printf("%c", 206);
	for(int i=0; i<3;  i++){
		printf("%c", 205);	
	}
	cout<<endl;
		for(int i=0; i<3;  i++){
		printf(" ");
	}
	printf("%c", 186);
	for(int i=0; i<3;  i++){
		printf(" ");
	}
	printf("%c", 186);
	cout<<endl;
	
	for(int i=0; i<3;  i++){
		printf(" ");
	}
	printf("%c", 186);
	for(int i=0; i<3;  i++){
		printf(" ");
	}
	printf("%c", 186);
	cout<<endl;
	//printf("%c", 201);
 }
 
 //INICIALIZAMOS LA CUADRÍCULA EN NULO
 void inicializarArray(char array[3][3]){
 	for(int i=0; i<3; i++){
 		for (int j=0; j<3; j++){
 			array[i][j]='0';
		 }
	 }
 }
 
bool libre(char array[3][3], int x, int y, char valor){
	cout<<"Recibo: "<<x<<", "<<y<<", y tambien, "<<valor<<endl;
	if(array[y-1][x-1]=='0'){
		array[y-1][x-1]=valor;
		return true;
		
	}else{
		return false;
	}
}

bool evaluarGanador(char array[3][3]){
	int contador1=0;
	int contador2=0;
	int contador3=0;
	int contador4=0;
	int contador5=0;
	
	for(int i=0; i<2; i++){
		if(array[0][i]==array[0][i+1] && array[0][i]!='0'){
			contador1++;
		}
	}
	for(int i=0; i<2; i++){
		if(array[1][i]==array[1][i+1] && array[1][i]!='0'){
			contador2++;
		}
	}
	for(int i=0; i<2; i++){
		if(array[2][i]==array[2][i+1] && array[2][i]!='0'){
			contador3++;
		}
	}
	
	//Evaluacion Diagonal
	int j=0;
	for(int i=0; i<2; i++){
		
		if(array[j][i]==array[j+1][i+1] && array[0][0]!='0'){
			contador4++;
		}
		j++;
	}
	if(array[2][0]!='0' &&  array[2][0]==array[1][1] && array[1][1]==array[2][0] ){
		contador5=2;
	}
	
	if(contador1==2 || contador2==2 ||contador3==2 || contador4==2 || contador5==2 ){
		return true;
	}else{
		return false;
	}
}

void imprimirCaracteres(char array[3][3]){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			
			if(array[i][j]!='0'){
				gotoxy(((i+1)*3)-1, ((j+1)*2)-1);
				cout<<array[i][j];
			}
				
		}
	}
}
