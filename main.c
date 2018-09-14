#include <iostream>
#include <fstream>
#include <iomanip>;
#include <cstring>

struct robos{
	char nom[30];
	int RoAn;
	int RoAct;
};

using namespace std;

int main(){
	fstream archivo;
	robos r, *vec;
	
	int i=-1;
	archivo.open("robos.txt",ios::in);
	archivo.clear();
	archivo.seekg(0);
	while(archivo>>r.nom>>r.RoAn>>r.RoAct){
		i++;
	}
	vec=new robos[i];
	int k=i;
	char Corre[10];
	i=0;
	archivo.clear();
	archivo.seekg(0);
	while(archivo>>r.nom>>r.RoAn>>r.RoAct){
		strcpy(vec[i].nom,r.nom);
		vec[i].RoAn=r.RoAn;
		vec[i].RoAct=r.RoAct;
		i++;
	}
	
	cout<<right<<setw(15)<<"\tCiudad\t"<<right<<setw(15)<<"\tAnteror\t"<<right<<setw(15)<<"\tActual\t"<<right<<setw(15)<<"\tCorrelacion\t"<<right<<setw(15)<<"\thistograma\t";
	cout<<endl;
	for(i=0;i<k;i++){
		if(vec[i].RoAn>vec[i].RoAct)
			strcpy(Corre,"Bajo");
		else if(vec[i].RoAn<vec[i].RoAct)
				strcpy(Corre,"Subio");
			  else
			  	strcpy(Corre,"Igual");
		cout<<right<<setw(10)<<vec[i].nom<<right<<setw(17)<<vec[i].RoAn<<right<<setw(16)<<vec[i].RoAct<<right<<setw(20)<<Corre<<right<<setw(10)<<"\t";
		for(int j=0;j<vec[i].RoAct;j++){
			cout<<"*";
		}
		cout<<endl;
	}
}
