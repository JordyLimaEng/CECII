#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> Concat (vector<string> v){

	vector<string> v_concatenado;

	string r1="", r2="", r3="", r4="", r5="";//auxiliares para concatenação
    bool fg1=false, fg2=false, fg3=false, fg4=false, fg5=false;//flags para parada e inserção

	//concatena os bits...
    for(int x=0; x<v.size(); x++){
        if(!fg1) {r1 = v[x]; fg1=true; }
        else if(!fg2){ r2 = v[x]; fg2=true;}
        else if(!fg3) {r3 = v[x]; fg3=true;}
        else if(!fg4) {r4 = v[x]; fg4=true; fg5=true; }

            r5 = r1 + r2 + r3 + r4;
            if(r5.size()==4){
            v_concatenado.push_back(r5);
            }

        if(fg5){
            r1="";r2="";r3="";r4="";r5="";
            fg1=false;fg2=false;fg3=false;fg4=false;fg5=false;
        }
    }

	return v_concatenado;

}

void Inv(vector <int> Numeros){

vector<string> Entrada_inversor;
vector<string> bits_invertidos;
vector<string> bits_normais;
vector<string> Invertidos;


	//de acordo com o valor inteiro, inverte os bits e devolve como string representando binário
    for(int x=0; x<Numeros.size(); x++){
    if(Numeros[x] == 0){
        Invertidos.push_back("1");//em ordem invertida
        Entrada_inversor.push_back("0");//em ordem não invertida
    }else{
        Invertidos.push_back("0");//em ordem invertida
        Entrada_inversor.push_back("1");//em ordem não invertida
     }
    }

	bits_invertidos = Concat(Invertidos);
	bits_normais = Concat(Entrada_inversor);

    ofstream Inversor ("inv_tb.sv", ofstream::out);
    //Primeira e última combinações
    Inversor << bits_normais[0] <<"_"<< bits_invertidos[0] << endl;
    Inversor << bits_normais[bits_normais.size()-1] <<"_"<< bits_invertidos[bits_normais.size()-1] << endl;
    Inversor.close();

}

int main()
 {

 vector<int> Numeros{0,0,0,0,1,1,1,1};

 Inv(Numeros);

 return 0;
}
