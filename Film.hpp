//
//  Film.hpp
//  lab6_oop
//
//  Created by Ghirisan Sebastian on 24/05/2020.
//  Copyright © 2020 Ghirisan Sebastian. All rights reserved.
//

#ifndef Film_hpp
#define Film_hpp

#include <stdio.h>
#pragma once
#include "Valid.hpp"
#include <string>
#include <vector>
//#include <windows.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;
class Film : public Valid
{
public:
    Valid v;
    string titel;
    string genre;
    int aparitie_an;
    int nr_likes;
    string trailer;
    vector<Film> vector_filme;
    vector<Film> ListaFilme;
    Film();
    void inserare_film();
    void stergere_film();
    void afisare_filme();
    void modificare_film();
    void Cautare(int option);
    //void openTrailer(string trailer);
    void addToListaFilme(Film it);
    void addToListaFilme2(int option);
    void stergere(int option);
    void Afisare(int option);

};

#endif /* Film_hpp */
