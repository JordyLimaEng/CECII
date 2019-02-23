#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void Trist(vector<string> In_Tris, vector<string> Sel){
    vector<string> saida;
        
    for(int x=0; x<In_Tris.size(); x++){
        if(Sel[x] == "0"){
            saida.push_back("Z");
        }else{
           saida.push_back(In_Tris[x]);
        }
    }	

    ofstream Tristate ("tris_tb.sv", ofstream::out);
    
    //Tristate << "SEL" << "_"<< "IN" <<"_"<< "OUT" << endl;
    for(int x=0; x<In_Tris.size(); x++){
    Tristate << Sel[x] << "_"<< In_Tris[x] <<"_"<< saida[x] << endl;
    }

    Tristate.close();
}

int main()
 {
 vector<string> InTris{"0000","1111","0000","1111"};
 vector<string> Sel{"0","0","1","1"};

 Trist(InTris,Sel);


 return 0;
}