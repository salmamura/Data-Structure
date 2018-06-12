#include <stdio.h>
#include "TP_ADT2.c"

int main(){
    Pkm p1,p2,p3,p4,p5;

    p1 = pokemonBaru("Arceus",9999,9998);
    p2 = pokemonBaru("Abra",2200,1000);
    p3 = pokemonBaru("Tyranitar",5600,5600);
    p4 = pokemonBaru("Golem",3500,5500);
    p5 = pokemonBaru("Steelix",4000,5000);

    cetakInfo(p1);
    cetakInfo(p2);
    cetakInfo(p3);
    cetakInfo(p4);
    cetakInfo(p5);

    aduPokemon(p3,p5);
    aduPokemon(p5,p4);

    return 0;
}
