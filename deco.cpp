#include <iostream>
#include<string.h>
#include <stdio.h>
using namespace std;

/* john llanes en mascarado y decodificador  */
class Codificar
{
	char palabra[100];
	unsigned long int vec[10];
	public:
		Codificar();
		void Cod(char palabra[]);
		void mostrarDato();
		void mostrarLetra();
		void newCodigo(char palabra[]);
		void newMascara();
		void menu();
		~Codificar();
		
	protected:
};

Codificar::Codificar()
{
	strcpy(palabra," ");
	for(int i=0;i<10;i++){vec[i]=0;}
}
void Codificar::Cod(char palabra[]){
	
	char a[100];int aux=0,aux2=24,t=0,total=0;strcpy(a,palabra);
	for(int i=0;i<10;i++){vec[i]=0;}
	int vector[strlen(a)];
	unsigned long int numero[10];
	
	for(int i=0;i<10;i++){numero[i]=0;}
	for(int i=0;i<strlen(a);i++){
		if(a[i]!=NULL){
//			cout<<a[i]<<endl;
			aux=int(a[i]);
			vector[i]=aux;
//			cout<<aux<<endl;
			
		}else{
			i=strlen(a)+1;
		}
	}
	for(int i=0;i<strlen(a);i++){
			if(aux2!=-8&&i<strlen(a)){
//			cout<<vector[i]<<" "<<i<<endl;
			numero[t]=numero[t]|(vector[i]<<aux2);
			aux2-=8;
//			cout<<"numero :"<<numero[t]<<"-aux"<<aux2<<endl;
			}else{
			t++;aux2=24;
//			cout<<vector[i]<<" "<<i<<endl;
			numero[t]=numero[t]|(vector[i]<<aux2);
			aux2-=8;
//			cout<<"numero :"<<numero[t]<<"-aux"<<aux2<<endl;
			}
	}
	for(int i=0;i<10;i++){
		if(numero[i]!=0){
//			cout<<numero[i]<<" "<<i<<" "<<endl;
			vec[i]=numero[i];
		}
	}
}
void Codificar::mostrarLetra(){
	
	unsigned long int au,u=0;int ac=24,ab=0;char l;
	for(int i=0;i<10;i++){
		if(vec[i]!=0){
			au=vec[i];
			for(int j=0;j<4;j++){
				u=(au>>ac)&255;l=u;
			cout<<l;
				ac-=8; 
			}
		}
	}
	
	system("pause");
}
void Codificar::mostrarDato(){
	for(int i=0;i<10;i++){
		if(vec[i]!=0){
			cout<<vec[i]<<endl;
		}
	}
	system("pause");
}

void Codificar::newCodigo(char palabra[]){
	char a[100];int aux=0,aux2=24,t=0,total=0;strcpy(a,palabra);
	for(int i=0;i<10;i++){vec[i]=0;}
//	strlen(a) da el tamaño de la cadena
	int vector[strlen(a)];
	unsigned long int numero[10];
	
	for(int i=0;i<10;i++){numero[i]=0;}
	cout<<strlen(a)<<endl;
	for(int i=0;i<strlen(a);i++){
		if(a[i]!=NULL){
//			ojo pasa de un char a un entero 
			aux=int(a[i]);
			vector[i]=aux;
			
		}else{
			i=strlen(a)+1;
		}
	}
	for(int i=0;i<strlen(a);i++){
			if(aux2!=-8&&i<strlen(a)){
			numero[t]=numero[t]|(vector[i]<<aux2);
			aux2-=8;
			}else{
				t++;aux2=24;
			numero[t]=numero[t]|(vector[i]<<aux2);
			aux2-=8;
			}
	}
	for(int i=0;i<10;i++){
		if(numero[i]!=0){
			vec[i]=numero[i];
		}
	}
}

void Codificar::newMascara(){
	for(int i=0;i<10;i++){vec[i]=0;}
    int c;int j=0,r=0,rt=0;
	unsigned long int as=0;
		system("cls");
	    cout<<"Nueva mascara"<<endl;
	    cout<<" menu "<<endl;
	    cout<<" 1)Ingresar nueva mascara"<<endl;
	    cout<<" 2)Cargar mascara predeterminada"<<endl;
	    cout<<" 3)salir "<<endl;
	    cin.sync();cin>>r;
		switch(r){
		  case 1:do{
		  cout<<"Ingrese numero"<<endl;
		  cin.sync();cin>>as;vec[j]=as;
		  cout<<"Desea ingresear otro numero?¿ "<<"si 2-no 1"<<endl;cin.sync();cin>>c;j++;
	      }while(c!=1);break;
	      case 2:
	      	cout<<"1) Numero de suerte"<<endl;
	      	cout<<"2) tu mayor miedo"<<endl;
	      	cout<<"3) no dormiras "<<endl;
	      	cout<<"4) salir"<<endl;
	      	cin.sync();cin>>rt;
	        switch(rt){
	        	case 1:
	        		vec[0]=1903519008;   		
                    vec[1]=1701604449;
                    vec[2]=544108320;
                    vec[3]=1952784481;
                    vec[4]=1835343930;
                    vec[5]=1444937728;break;
                case 2:
                    vec[0]=1835099253;
		    vec[1]=1919885409;
		    vec[2]=1937006880;
		    vec[3]=1701584946;
		    vec[4]=808792064;break;
				case 3:
		    vec[0]=1886745711;
		    vec[1]=543517728;
		    vec[2]=1903519008;
		    vec[3]=1819222124;
		    vec[4]=1700864120;
		    vec[5]=1142947840;break;
		case 4:break;
			}break;
	        case 3:break;
		}
	
}


void Codificar::menu(){
	int t;char let[100];strcpy(let," ");
	do{
		system("cls");
		cout<<"  Que desea hacer "<<endl;
		cout<<"   1)mostrar datos con mascara "<<endl;
		cout<<"   2)mostrar datos sin mascara "<<endl;
		cout<<"   3)nueva palabras"<<endl;
		cout<<"   4)Ingrese mascara"<<endl;
		cout<<"   5)salir "<<endl;
		cin.sync();cin>>t;
		switch(t){
			case 1:mostrarDato(); break;
			case 2:mostrarLetra(); break;
			case 3:
			system("cls");
            cout<<"Ingrese palabras"<<endl;
	        cin.sync();cin.getline(let,99);newCodigo(let);break;
			case 4:newMascara();break;
			case 5:t=0;break;
		}
	}while(t!=0);
}

Codificar::~Codificar()
{
}


int main(int argc, char** argv) {
	
    char letra[100];
    cout<<"Ingrese palabras que quiere en mascarar "<<endl;
	cin.sync();cin.getline(letra,99);
	Codificar au;
	au.Cod(letra);
    au.menu();

	return 0;
	
}
