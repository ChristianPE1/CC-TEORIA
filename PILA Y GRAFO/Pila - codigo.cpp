#include<iostream>
#include<string>
#include<conio.h>
 
using namespace std;

#define SIZE 5
 
template <class T>
class Stack{
	private:
	    int top;
	    T st[SIZE];
	public:
	    Stack();
	    //agrega el elemento k al stack
	    void push(T k);
	    T pop();
	    //imprime el elemento superior con el metodo peek()
	    T topElement();
	    bool isFull();
	    bool isEmpty();
};
 
//inicializa el constructor con top=-1
template <class T>
Stack<T>::Stack(){top=-1;}
 
// Para anadir el elemento k al stack
template <class T>
void Stack<T>::push(T k){
    if (isFull()){
        cout<<"El Stack esta lleno\n";
    }
    // Insertando
    cout<<"Elemento insertado: "<<k<<endl;
 
    //incrementamos el uno top para agregar k
    top=top+1;
 
    st[top]=k;
}
 
//metodo para saber si el stack esta vacio
template <class T>
bool Stack<T>::isEmpty(){
    if(top == -1)
        return 1;
    else
        return 0;
}
 
//metodo para saber si el stack esta lleno
template <class T>
bool Stack<T>::isFull(){
    //va hasta la parte superior del stack
    if(top==(SIZE - 1))
        return 1;
    else 
        return 0;
}
 
template <class T>
T Stack<T>::pop(){
    //Inicia la variable popped que guarda el elemento superior
    T popped_element = st[top];
 
    //mientras el elemento sale del stack decrecre top
    top--;
    //Regresamos la variable popped
    return popped_element;
}

template <class T>
T Stack<T>::topElement(){
    //Guardamos el elemento superior en una variable
    T top_element=st[top];
 
    return top_element;
}
 
int main(){

	cout<<"Christian Pardave Espinoza:\n"<<endl;

    Stack<int> int_stack;
    Stack<string> string_stack;
 
    int_stack.push(2);
    int_stack.push(54);
    int_stack.push(255);

    string_stack.push("Hola");
    string_stack.push("a");
    string_stack.push("Todos");
 	
 	cout<<endl;
    //retiramos el elemento superior
    cout<<int_stack.pop()<<" es retirado de la pila"<<endl;
 
    cout<<string_stack.pop()<<" es retirado de la pila\n"<<endl;
 
    //Imprimimos el elemento superior
    cout<<"El elemento superior es: "<<int_stack.topElement()<< endl;
    cout<<"El elemento superior es: "<<string_stack.topElement()<< endl;
 
 	getch();
    return 0;
}