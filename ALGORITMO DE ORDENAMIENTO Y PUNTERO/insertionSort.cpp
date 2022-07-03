#include<iostream>
#include<conio.h>

using namespace std;

//Declaramos  una funcion para mostrar el array

template<class T>
void mostrarArray(T* array,int n){
  for (int i=0;i<n;i++){
    cout<<*(array+i)<<" - ";
  }
  cout<<endl;
}

//Aqui definimos la funciones a la cual le asignaremos un puntero
//para el criterio de comparación
template<class T>
bool compare1(T x, T y){
    return x <= y;
}
template<class T>
bool compare2(T x,T y){
    return x > y;
}

//Creamos nuestro algortimo de ordenamiento tal cual lo conocemos
template<class T>
void insertionsort(T* arreglo,int size, bool (*p)(T , T)){
    for(int k=1;k<size; k++){
        T temp=arreglo[k]; 
        int j=k-1;
        //Aqui es donde pasamos el puntero a funcion para comparar
        while(j>=0 && p(temp,arreglo[j])){ 
            arreglo[j+1]=arreglo[j]; 
            j--;
        } 
        arreglo[j+1]=temp;
    } 
}

int main(){
	
	cout<<"Christian Pardave Espinoza:\n"<<endl;
	
    int arreglo[10] = {5,2,2,7,1,3,5,2,10,1};
    float arre[]={5.3,6.2,1.6,2.3,9.2,4.3};
    cout<<"Array de enteros:"<<endl;
    mostrarArray(arreglo,10);
    insertionsort(arreglo,10, compare2);
    cout<<"Ordenado:"<<endl;
    mostrarArray(arreglo,10);
	cout<<"Array de flotantes:"<<endl;
	mostrarArray(arre,6);
    insertionsort(arre,6,compare1);
    cout<<"Ordenado:"<<endl;
	mostrarArray(arre,6);

	getch();
    return 0;
}
