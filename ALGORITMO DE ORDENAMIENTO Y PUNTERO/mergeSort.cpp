#include<iostream>
#include<conio.h>

using namespace std;

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


/*En esta funcion llamada merge sera donde vamos a desarrollar el ordenamiento, a la
vez que estamos usando un puntero a funcion para declarar el criterio de ordenamiento,
una vez terminada la ejecucion los elementos ordenados seran devueltos al array original*/
template<class T>
void merge(T arreglo[], int inicio, T mitad, int final,bool (*p)(T , T)){
    T aux[final - inicio+1];
    int i=inicio,j=mitad+1,k=0;
    while(i<=mitad && j<=final){
        if(p(arreglo[i],arreglo[j])){
            aux[k]=arreglo[i];
            k+=1;i+=1;
        }
        else{
            aux[k]=arreglo[j];
            k+=1;j+=1;
        }
    }
    //elementos que quedaban del array
    while(i<=mitad){
        aux[k]=arreglo[i];
        k+=1;i+=1;
    }
    while(j<=final){
        aux[k]=arreglo[j];
        k+=1;j+=1;
    }
    //devuelve los elementos al array inicial
    for(i=inicio;i<=final;i+=1) {
        arreglo[i]=aux[i-inicio];
    }
}

/*Desarrollamos la funcion mergeSort que recibira un inicio, final y un entero
auxiliar para el ordenamiento, ascendente o descente segun se indique*/
template<class T>
void mergeSort(T arreglo[], int inicio, int final, int orden){
    if(inicio<final) {
        if(orden==0){
	        T mitad=(inicio+final)/2;
	        mergeSort(arreglo,inicio,mitad,0);
	        mergeSort(arreglo,mitad+ 1,final,0); 
        	merge(arreglo,inicio,mitad,final,compare1);
        }
        else{
           	T mitad=(inicio+final)/2;
	        mergeSort(arreglo,inicio,mitad,1);
	        mergeSort(arreglo,mitad+ 1,final,1); 
        	merge(arreglo,inicio,mitad,final,compare2);
        }
    }
}

//Declaramos una funcion para mostrar el array
template<class T>
void mostrarArray(T* array, int n){
  for(int i=0; i<n; i++){
    cout<<*(array+i)<<" - ";
  }
  cout<<endl;
}

int main(){
	
	cout<<"Christian Pardave Espinoza:\n"<<endl;
	
    int array[]={15,13,26,52,41,51,23};
    float arre[]={5.3,6.2,1.6,2.3,9.2,4.3};
    
    //el cuarto parametro es el orden, si es 0 es ascendente, si es 1 descendente

    cout<<"Array de enteros:"<<endl;
    mostrarArray(array,7);
    mergeSort(array,0,6,1);
    cout<<"Ordenado:"<<endl;
    mostrarArray(array,7);

    cout<<"Array de flotantes:"<<endl;
    mostrarArray(arre,6);
    mergeSort(arre,0,5,0);
    cout<<"Ordenado:"<<endl;
    mostrarArray(arre,6);
    
    getch();
    return 0;
}