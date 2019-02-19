#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
 {
    unsigned char bits_entrada;
    vector<unsigned char> Tabela;
    vector<string> Entrada_inversor;
    vector<string> bits_invertidos;
    vector<string> bits_normais;
    vector<int> Numeros;
    vector<string> Invertidos;
    
    string r1="", r2="", r3="", r4="", r5="";//auxiliares para concatenação
    bool fg1=false, fg2=false, fg3=false, fg4=false, fg5=false;//flags para parada e inserção

    //lê o arquivo de entrada char por char, inverte e converte para int
    fstream arq("in.inv", ifstream::in);
    int x=0;
    while(!arq.eof()){
    	arq >> bits_entrada;
        Tabela.push_back(bits_entrada); 
        Numeros.push_back(Tabela[x]);       
        x++;
    }
    int i=0;
    Tabela.pop_back(); 
    Numeros.pop_back(); 

     
    //de acordo com a tabela ascii, inverte os bits e devolve como string representando binário
    for(int x=0; x<Numeros.size(); x++){
    if(Numeros[x] == 48){
        Invertidos.push_back("1");//em ordem invertida
        Entrada_inversor.push_back("0");//em ordem não invertida
    }else{
        Invertidos.push_back("0");//em ordem invertida
        Entrada_inversor.push_back("1");//em ordem não invertida
     }
    }

    //concatena os bits que são de ordem invertida...    
    for(int x=0; x<Invertidos.size(); x++){
        if(!fg1) {r1 = Invertidos[x]; fg1=true; }
        else if(!fg2){ r2 = Invertidos[x]; fg2=true;}
        else if(!fg3) {r3 = Invertidos[x]; fg3=true;}
        else if(!fg4) {r4 = Invertidos[x]; fg4=true; fg5=true; }
        
            r5 = r1 + r2 + r3 + r4; 
            if(r5.size()==4){
            bits_invertidos.push_back(r5);
            }
        
        if(fg5){
            r1="";r2="";r3="";r4="";r5="";
            fg1=false;fg2=false;fg3=false;fg4=false;fg5=false;
        }

    }
        //concatena os bits que são de ordem normal...
        for(int x=0; x<Entrada_inversor.size(); x++){
        if(!fg1) {r1 = Entrada_inversor[x]; fg1=true; }
        else if(!fg2){ r2 = Entrada_inversor[x]; fg2=true;}
        else if(!fg3) {r3 = Entrada_inversor[x]; fg3=true; }
        else if(!fg4) {r4 = Entrada_inversor[x]; fg4=true; fg5=true;}
            r5 = r1 + r2 + r3 + r4; 
            if(r5.size()==4){
            bits_normais.push_back(r5);
            }
        
        if(fg5){
            r1="";r2="";r3="";r4="";r5="";
            fg1=false;fg2=false;fg3=false;fg4=false;fg5=false;
        }

    }

    //for(int x=0; x<bits_invertidos.size(); x++)
    //cout <<bits_normais[x] << "_" <<bits_invertidos[x]<< endl;

    ofstream Inversor ("inv.tv", ofstream::out);
    
    ///Todas combinações
    //for(int x=0; x<Invertidos.size(); x++)
    //Inversor << bits_normais[x] <<"_"<< bits_invertidos[x] << endl;
    Inversor << bits_normais[0] <<"_"<< bits_invertidos[0] << endl;
    Inversor << bits_normais[Invertidos.size()] <<"_"<< bits_invertidos[Invertidos.size()] << endl;

   Inversor.close();

 return 0; 
}
