#include<iostream>
#include<vector>
#include<conio.h>

using namespace std;
 
struct Edge{
    int src, dest;
};
class Grafo{
	public:
   		vector<vector<int>>adjList;
	    Grafo(vector<Edge> const &edges, int n){
	        adjList.resize(n);
	        for(auto &edge:edges){
	            adjList[edge.src].push_back(edge.dest);
	        }
	    }
};

void imprimir(Grafo const &grafo, int n){
    for (int i=0;i<n;i++){
        cout<<i<<"->";
        //imprime todos los vecinos de i
        for(int v: grafo.adjList[i]){
            cout<<v<<" ";
        }
        cout<<endl;
    }
}

int main(){
	
	cout<<"Christian Pardave Espinoza:\n"<<endl;
    vector<Edge>edges={{0, 1},{1, 2},{2, 0},{2, 1},{3,2},{4, 5},{5, 4}};
    int n=6;

    Grafo grafo(edges, n);
    imprimir(grafo, n);
 
 	getch();
    return 0;
}