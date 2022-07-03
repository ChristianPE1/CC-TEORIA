#include<iostream>
#include<conio.h>

using namespace std;

template<class T>
bool compare1(T x, T y){
    return x <= y;
}
template<class T>
bool compare2(T x,T y){
    return x > y;
}

//declaramos la funcion particion para ordenar el array dividiendlo en dos
template<class T>
T partition(T arr[],int inicio,int final,bool (*p)(T , T)){
	int pivote = arr[inicio];
    int cont = 0;
    for(int i=inicio+1; i<=final;i++){
        if(arr[i]<=pivote)
            cont++;
    }
 	//mandamos la ubicacion al pivote
    int pivoteI = inicio + cont;
    swap(arr[pivoteI],arr[inicio]);
    //ordenamos los elementos de la derecha e izquierda del pivote
    int i=inicio,j=final;
 
    while(i<pivoteI && j>pivoteI){
	//while(p(pivoteI,pivoteI)){
        while(arr[i]<=pivote){
        //while(p(arr[i],pivote)){
			i++;
        }
        while(arr[j]>pivote){
        //while(p(arr[j],pivote)){
            j--;
        }
        //if(i<pivoteI&&j>pivoteI){
       	if(i<pivoteI && p(j,pivoteI)){
            swap(arr[i++],arr[j--]);
        }
        else if(p(i,pivoteI)&& j>pivoteI){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivoteI;
}

//Declaramos la funcion quicksort con el caso base y la recursividad
template<class T>
void quickSort(T arr[],int inicio, int final, int orden){
    if(inicio>=final){
    	return;
    }
	if(orden==0){
	    //dividimos el array
	  	int aux=partition(arr,inicio,final,compare1);
	    //Ordenamos la izquierda y derecha
	    quickSort(arr,inicio,aux-1,0);
	    quickSort(arr,aux+1,final,0);
	}
 	else{
	    //dividimos el array
	  	int aux=partition(arr,inicio,final,compare2);
	    //Ordenamos la izquierda y derecha
	    quickSort(arr,inicio,aux-1,1);
	    quickSort(arr,aux+1,final,1);
	}
}

//Funciona para mostrar el array
template<class T>
void mostrarArray(T* array,int n){
  for (int i=0;i<n;i++){
    cout<<*(array+i)<<" - ";
  }
  cout<<endl;
}
 
int main(){
	
	cout<<"Christian Pardave Espinoza:\n"<<endl;
	
    int array[]={15,13,26,52,41,51,23};
    float arre[]={5.3,6.2,1.6,2.3,9.2,4.3};
 
    cout<<"Array de enteros:"<<endl;
    mostrarArray(array,7);
    quickSort(array,0,6,0);
    cout<<"Ordenado:"<<endl;
    mostrarArray(array,7);

    cout<<"Array de flotantes:"<<endl;
    mostrarArray(arre,6);
    quickSort(arre,0,5,1);
    cout<<"Ordenado:"<<endl;
    mostrarArray(arre,6);
 
 	getch();
    return 0;
}