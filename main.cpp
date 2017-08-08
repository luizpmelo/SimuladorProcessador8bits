//
// Created by luiz on 08/08/17.
//
#include <iostream>
#include <string>
#include <map>
#include <bitset>

std::map<size_t,std::string > bits;

int processador(std::map<size_t,std::string > x);

using namespace std;

int main()
{

    int i;


    bits[0]= "10110000"; // ld_cte_L = 0 ; Acumulador parte baixa
    bits[1]= "11000101"; // ld_cte H = 5 ; Acumulador parte alta
    bits[2]= "00000001"; // add no acc o valor 1;
    bits[3]= "00000011"; // add no acc o valor 3;
    bits[4]= "00010010"; // sub no acc o valor 2;
    bits[5]= "11111111"; // Final do programa
    // Acc = 1+3-2 = 2;

    //cout <<" "<<x[0]<<" "<< x[1] << " " <<x[2]<<" "<<x[3]<<" " <<x[4];
    i = processador(bits);//chama a funcao processador
    cout << i << endl;
    return 0;
}







int processador(std::map<size_t,std::string > x)
{


    int Reg[8];
    int IR;
    int PC=0;
    int Acc=0;
    int regEspecial;
    int z = 0;

    while(PC<x.size ()) //realiza as instrucoes enquanto for menor que o tamanho do vetor de instrucoes
    {
        auto it = x.find(z);
        std::string str1 = it->second.substr (0,4);
        std::string str2 = it->second.substr (4,4);

        // cout << it-> second << endl;
        // cout << str1 << endl;

        std::bitset<4> baz (str1);
        auto i = baz.to_ulong();

        std::bitset<4> maz (str2);
        auto j = maz.to_ulong();

        // cout << i <<endl;
        // cout << j <<endl;

        IR = i;

        switch (IR)
        {
            case 0 :
                Acc += j;
                break;
            case 1 :
                Acc -= j;
                break;

            case 2 :
                Acc *= j;
                break;
            case 3 :
                Acc /= j;
                break;

            case 4 :
                IR = Reg[7];  //desvio para o endereco 150 do arranjo que faz o papel de registrador;
                break;
            case 5 :
                IR = Reg[7];  //desvio para o endereco 150 do arranjo que faz o papel de registrador;
                break;

            case 6 :          //NAO ENTENDI O JUMP AINDA --- FALTA FAZER...
                IR = Reg[7];
                break;


            case 7 :
                Acc = Reg[7];
                break;
            case 8 :
                Reg[7] = Acc;
                break;


            case 9 :
                Reg[j] = Acc;
                break;
            case 10 :
                Acc = Reg[j];
                break;


            case 11 : //ESTÁ ERRADO
                //  Acc = Reg[IR&3];
                break;
            case 12 : //ESTÁ ERRADO
                // Acc = (IR<<4)<<4<<&0xF
                break;

            case 13 : //NÂO ESTÁ 100%
                regEspecial = Acc;
                break;

            case 14 : //NÂO ESTÁ 100%
                Acc = regEspecial;
                break;

            case 15 :
                PC = x.size ()+ 1;

                break;



        }


        z++;
        PC++;
    }

    return Acc;

}
