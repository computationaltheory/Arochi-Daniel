//Definicion de librerias utilizadas por el juego

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

//definicion de variables utilizadas en la funcion
void gotoxy(int, int); //funcion que acomoda en las coordenasas los caracteres
void printTable(); //funcion que imprime la matriz de 3x3
void inicializarArray(char array[3][3]); //funcion que inicia el arreglo utilizado en el juego
bool libre(char arrar[3][3], int x, int y, char valor); //funcion que verifica si un lugar esta disponible o no
bool evaluarGanador(char array[3][3]); //funcion que verifica quien es el ganador de acuerdo a la posicion de sus caracteres
void imprimirCaracteres(char array[3][3]); //funcion que imprime los caracteres del jugador en la posicion deseada


//funcion principal del juego, aqui se llaman todas las funciones
int main(){
	char array[3][3];
	cout<<"Tic Tac Toe"<<endl;
	printTable();
	inicializarArray(array); //se inicializa el arreglo utilizado para almacenar la informacion
	bool bandera=true;
	int x, y, contador=0;
	char v;
	bool correcto=true; //en caso de que todo este bien, se procede a iniciar la jugabilidad
	

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
			//obtencion de los valores de las coordenadas para pintar el simobolo del ususario en la matriz
			cout<<"\nDame las coordenadas en x: ";
			cin>>x;
			cout<<"\nDame las coordenadas en y: ";
			cin>>y;
			correcto=libre(array, x, y, v);
			//En caso de que la posicion sea correcta o este utilizada, se llama a este condicional para lograr que el usuario no coloque su forma
			//en lugares utilizados ya en la matriz 
			if(correcto){
				if(bandera){
					bandera=false;
				}else{
					bandera=true;
				}
			}
		}while(!correcto);
		contador++;
		
		 system("cls");
		 printTable();
		 imprimirCaracteres(array); //una vez ingresadas las coordenadas se procede a pintarlo en la consola
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
 
 //funcion que imprime la matriz de 3x3 en la consola
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
 
 
 //funcion utilizada para imprimir en consola que el valor ingresado de coordenadas esta ocupado
bool libre(char array[3][3], int x, int y, char valor){
	cout<<"Recibo: "<<x<<", "<<y<<", y tambien, "<<valor<<endl;
	if(array[y-1][x-1]=='0'){
		array[y-1][x-1]=valor;
		return true;
		
	}else{
		return false;
	}
}

//funcion que define al ganador del juego en base al puntaje obtenido
bool evaluarGanador(char array[3][3]){
	int contador1=0;
	int contador2=0;
	int contador3=0;
	int contador4=0;
	int contador5=0;
	
	//en estas funciones se evaluan los valores insterdados en la matriz
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
	
	//Evaluacion Diagonal de los simbolos insertados por el usuario
	int j=0;
	for(int i=0; i<2; i++){
		
		if(array[j][i]==array[j+1][i+1] && array[0][0]!='0'){
			contador4++; //se usa un contador para mover el puntero de la funcion
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

//funcion utilizada para mover los punteros de la impresion, y colocarlo en donde se desea colocar de acuerfo a lo ingresado
//por el usuario
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
