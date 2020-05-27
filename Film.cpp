//
//  Film.cpp
//  lab6_oop
//
//  Created by Ghirisan Sebastian on 24/05/2020.
//  Copyright © 2020 Ghirisan Sebastian. All rights reserved.
//

#include "Film.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <exception>
#include <assert.h>
//#define assert(exp) ((void) 0)
using namespace std;
//constructoru default
Film::Film()
{
    titel = "";
    genre = "";
    aparitie_an = 0;
    nr_likes = 0;
    trailer = "";
}
//adaugarea unui film,la inceputul programului,creand astfel o lista implicita
//inserarea unui film nou,in modul administratoului
void Film::inserare_film()
{
    Valid v;
    string titel, genre, trailer;
    int aparitie_an, nr_likes;
    Film f;
    cout << "Ce nume are filmul?";
    cin >> titel;
    if (v.validare_film(titel) == 1)
    {
        cout << "Ce gen este filmul?";
        cin >> genre;
        cout << "In ce an a aparut filmul?";
        while (!(cin >> aparitie_an))
        {
            cout << "Eroare:Reintroduceti data! ";
            cin.clear();
            cin.ignore(123, '\n');

        }
        cout << "Care este numarul de like-uri?";
        while (!(cin >> nr_likes))
        {
            cout << "Eroare:Reintroduceti numarul de like-uri! ";
            cin.clear();
            cin.ignore(123, '\n');

        }
        cout << "Care este linkul trailerului?";
        cin >> trailer;
        ofstream out("filme.txt", ios::app);
        out << titel << ' ' << genre << ' ' << aparitie_an << ' ' << nr_likes << ' ' << trailer << endl;
        cout << "Filmul a fost adaugat cu succes";
        out.close();
    }
    else
        cout << "Numele exista deja";
}
void Film::afisare_filme()
{
    string titel, genre, trailer;
    int aparitie_an, nr_likes;
    ifstream in("filme.txt", ios::in);
    while (in >> titel >> genre >>aparitie_an >> nr_likes >> trailer)
        cout << titel << " " << genre << " " << aparitie_an << " " << nr_likes << " " << trailer<<endl;
}
//stergerea unui film
void Film::stergere_film()
{
    Valid v;
    vector<Film> aux;
    string titel, genre, trailer;
    int aparitie_an, nr_likes;
    Film f;
    string nume;
    cout << "Ce filme doriti sa stergeti?";
    cin >> nume;
    ifstream in("filme.txt", ios::in);
    //daca exista numele putem sa il stergem
    if (v.validare_film(nume) == 0)
    {
        while (in >> titel >> genre >> aparitie_an >> nr_likes >> trailer)
            if (titel != nume)
            {
                f.titel = titel;
                f.genre = genre;
                f.aparitie_an = aparitie_an;
                f.nr_likes = nr_likes;
                f.trailer = trailer;
                aux.push_back(f);//creaza un nou vector,fara filmul pe care dorim sa l stergem
            }
        vector_filme = aux;//se pune aux in vectoru v
        ofstream out("filme.txt", ios::out);
        for (const auto& film : vector_filme)
            out << film.titel << " " << film.genre << " " << film.aparitie_an << " " << film.nr_likes << " " << film.trailer << endl;
        cout << "Filmul a fost sters cu succes";
        in.close();
        out.close();
    }
    else
        cout << "Filmul pe care doriti sa-l stergeti nu exista";
}

void Film::modificare_film()
{
    vector<Film> aux;
    Film f;
    Valid v;
    string titel, genre, trailer, nume, tr, gen, t;
    int aparitie_an, nr_likes, like, an;
    string titlu;
    int m;
    cout << "Ce film doriti sa modificati?" << endl;
    cin >> nume;
    if (v.validare_film(nume) == 0)
    {
        cout << "Alegeti ce doriti sa modificati la acest film:" << endl;
        cout << "1.Titlu" << endl;
        cout << "2.Genul" << endl;
        cout << "3.Anul" << endl;
        cout << "4.Nr Likes" << endl;
        cout << "5.Link trailer" << endl;
        cin >> m;
        ifstream in1("filme.txt", ios::in);
        while (in1 >> titel >> genre >>aparitie_an >> nr_likes >> trailer)
            if (titel != nume)
            {
                f.titel = titel;
                f.genre = genre;
                f.aparitie_an = aparitie_an;
                f.nr_likes = like;
                f.trailer = trailer;
                aux.push_back(f);//creaza un nou vector,fara filmul pe care dorim sa l stergem
            }
            else
            {
                t = titel;
                gen = genre;
                an = aparitie_an;
                nr_likes = like;
                tr = trailer;
            }
        in1.close();
        ofstream out("filme.txt", ios::out);
        for (const auto& film : aux)
            out << film.titel << " " << film.genre << " " << film.aparitie_an << " " << film.nr_likes << " " << film.trailer << endl;
        out.close();
        ofstream out1("filme.txt", ios::app);
        if (m == 1)
        {
            cout << "Titlu nou:";
            cin >> titlu;
            out1 << titlu << " " << gen << " " << like << " " << tr;
            cout << "Titlul a fost schimbat!" << endl;

        }
        if (m == 2)
        {
            cout << "Gen nou:";
            cin >> genre;
            out1 << t << " " << genre << " " << nr_likes << " " << tr;
            cout << "Genul a fost schimbat!";
        }
        if (m == 3)
        {
            cout << "An nou:";
            while (!(cin >> aparitie_an))
            {
                cout << "Eroare:Reintroduceti data! ";
                cin.clear();
                cin.ignore(123, '\n');

            }
            out1 << t << " " << gen << " " << aparitie_an << " " << nr_likes << " " << tr;
            cout << "Anul a fost schimbat!";
        }
        if (m == 4)
        {
            cout << "Numar de like-uri nou:";
            while (!(cin >> nr_likes))
            {
                cout << "Eroare:Reintroduceti data! ";
                cin.clear();
                cin.ignore(123, '\n');

            }
            out1 << t << " " << gen << " " << nr_likes << " " << tr;
            cout << "Numarul de like-uri a fost schimbat";
        }
        if (m == 5)
        {
            cout << "Trailer nou:";
            cin >> trailer;
            out1 << t << " " << gen << " "<< nr_likes << " " << trailer;
            cout << "Trailer-ul a fost schimbat";
        }
        out1.close();

    }
    else
        cout << "Filmul pe care doriti sa-l modificati,nu exista!";
}

void Film::Cautare(int option)
{
    vector<Film> aux;
    string titel, genre, trailer;
    int erscheinungsjahr, anzahl_likes;
    Film f;
    string gen;
    cout << "Genul este: ";
    cin >> gen;
    int ok = 0;
    int k = 1;
    ifstream in1("filme.txt", ios::in);
    while (in1 >> titel >> genre >> erscheinungsjahr >> anzahl_likes >> trailer)
    {
        f.titel = titel;
        f.genre = genre;
        f.aparitie_an = aparitie_an;
        f.nr_likes = nr_likes;
        f.trailer = trailer;
        aux.push_back(f);//creaza un nou vector
    }
    for (auto it : aux) /// Cautam in lista de filme
    {
        if (gen == it.genre && k == 1) /// afisam primul gen
        {
            cout << it.titel << " " << it.genre << " " << it.aparitie_an << " " << it.nr_likes << " " << it.trailer << endl;
            string From = string(it.trailer);
            wstring To(From.begin(), From.end()); ///am transformat din string in wstring
           // LPCWSTR Last = To.c_str(); /// din wstring in LPCWSTR
           // LPCWSTR C = TEXT("open");
           // ShellExecute(NULL, C, Last, NULL, NULL, SW_SHOWNORMAL); ///aceseaza browserul
            ok = 1;
            int m;
            do
            {
                ///Meniul pentru problema 3 care contine problema 2 incorporata
                cout << "1.Continuati / Adaugati" << endl;
                cout << "2.Nu Adaugati / Continuati" << endl;
                cout << "0.Iesiti " << endl;
                cout << "Alegeti ce doriti sa faceti apasand tasta de tip numar,din stanga celor de mai sus: ";
                cin >> m;
                //optiune continuare si adaugare
                if (m == 1)
                {
                    addToListaFilme(it);
                    break;
                }
                else
                    //optiune continuare
                    if (m == 2)
                        break;
                    else
                        if (m == 0)
                        {
                            cout << "Ati iesit din modul cautare";
                            k = 0;
                            break;
                        }
                //Sleep(3000);
                //system("CLS");
            } while (m != 0);
        }
    }
    addToListaFilme2(option);
    if (ok == 0) ///daca nu a gasit genul afisam toate filmele
    {
        cout << "Nu s-a gasit film, va atasam lista de filme pentru o noua cautare";
        string topicName = "filme";
        topicName = "notepad \"" + topicName + "\"";  /// deschiderea fisierului txt;

        system(topicName.c_str());
    }
}

// adaugam in lista de filme

void Film::addToListaFilme(Film it) {
    int ok = 1;
    // veerificam daca filmul nu este deja in watchlist
    for (auto i : ListaFilme) {
        if (i.titel == it.titel) {
            cout << "\nFilm se afla in Lista!\n";
            ok = 0;
        }
    }
    if (ok == 1) {
        ListaFilme.push_back(it);
        cout << "\nFilm Adaugat cu succes.\n";
    }

}

void Film::addToListaFilme2(int optiune)
{
    /// adaugarea in cele 2 optiuni html / csv
    if (optiune == 1)
    {
        ofstream myfile;
        myfile.open("filme.csv");    //deschidere csv
        myfile << "Lista de filme.\n";
        for (auto i : ListaFilme)
        {
            // scriere in fisier csv
            myfile << i.titel << "," << i.genre << "," << i.aparitie_an << "," << i.nr_likes << "," << i.trailer << "\n";
            
        }
        myfile.close();
    }
    else
        if (optiune == 2)
        {
            //scrierea in html
            ofstream myfile;
            myfile.open("Watchliste.html"); //deschidere html
            myfile << "<!doctype html>\n";
            myfile << "<html>\n";
            myfile << "<head><title> Watchliste </title></head>\n";
            myfile << "<body>\n";
            myfile << "<table border=1>\n"; ///bordura
            myfile << "<tr>\n";
            myfile << "<td> Titel </td>\n";    ///coloanele
            myfile << "<td> Genre </td>\n";
            myfile << "<td> Jahr </td>\n";
            myfile << "<td> Likes </td>\n";
            myfile << "<td> Trailer link </td>\n";
            myfile << "</tr>\n";
            for (auto it : ListaFilme)
            {
                myfile << "<tr>\n";
                myfile << "<td>" <<it.titel<< "</td>\n";
                myfile << "<td>" << it.genre << "</td>\n";
                myfile << "<td>" << it.aparitie_an << "</td>\n";
                myfile << "<td>" << it.nr_likes << "</td>\n";
                myfile << "<td><a href =" << it.trailer << ">link</a></td>\n";
                myfile << "</tr>\n";
            }
            myfile << "</table>\n";
            myfile << "</body>\n";
            myfile << "</html>\n";

        }
}
void Film::stergere(int option)
{
    vector<Film> ax;
    string titel, genre, trailer;
    int erscheinungsjahr, anzahl_likes;
    Film f;
    ifstream in1("filme.txt", ios::in);
    while (in1 >> titel >> genre >> erscheinungsjahr >> anzahl_likes >> trailer)
    {
        f.titel = titel;
        f.genre = genre;
        f.aparitie_an = aparitie_an;
        f.nr_likes = nr_likes;
        f.trailer = trailer;
        ax.push_back(f);//creaza un nou vector
    }
    vector<Film> aux;
    vector<Film> aux1;
    int ok = 0;
    string titlu;
    cout << "Dati titlul: ";
    cin >> titlu;
    for (auto it : ListaFilme) ///Parcurgem lista de vizionari
    {
        if (it.titel == titlu) ///Cautam titlul
        {
            ok = 1;
            cout << "Doriti sa dati un like la aceast film\n";
            cout << "Tasta 1 = Da\n";
            cout << "Tasta 2 = Nu\n";
            cout << "Apasati Tasta = ";
            int n;
            cin >> n;
            if (n == 1) ///Partea de modificare a like-ului in lista de filme si stergerea filmului in lista de vizionari
            {
                for (const auto& film : ax) /// parcurgem pentru lista de filme
                    if (film.titel == titlu)
                    {
                        f.titel = film.titel;
                        f.genre = film.genre;
                        f.aparitie_an = film.aparitie_an;
                        f.nr_likes = film.nr_likes + 1; ///Cand gasim filmul modificam pretul
                        f.trailer = film.trailer;
                        aux.push_back(f);
                    }
                    else
                    {
                        f.titel = film.titel;
                        f.genre = film.genre;
                        f.aparitie_an = film.aparitie_an;
                        f.nr_likes = film.nr_likes;
                        f.trailer = film.trailer;
                        aux.push_back(f);
                    }
                ax = aux;//se pune aux in vectoru ax
                ofstream out("filme.txt", ios::out);
                for (const auto& film : aux) /// adaugam in fisier schimbarea
                    out << film.titel << " " << film.genre << " " << film.aparitie_an << " " << film.nr_likes << " " << film.trailer << endl;
                out.close();
                for (const auto& film : ListaFilme)
                    if (film.titel != titlu)   ///Stergem filmul din lista de Vizionare
                    {
                        f.titel = film.titel;
                        f.genre = film.genre;
                        f.aparitie_an = film.aparitie_an;
                        f.nr_likes = film.nr_likes;
                        f.trailer = film.trailer;
                        aux1.push_back(f);//creaza un nou vector,fara filmul pe care dorim sa l stergem
                    }
                ListaFilme = aux1;//se pune aux in vectoru ListaFilme
                cout << "Filmul a fost sters cu succes";
            }

            else
                if (n == 2)
                {
                    for (const auto& film : ListaFilme)
                        if (film.titel != titlu)    ///Stergem filmul din lista de Vizionare
                        {
                            f.titel = film.titel;
                            f.genre = film.genre;
                            f.aparitie_an = film.aparitie_an;
                            f.nr_likes = film.nr_likes;
                            f.trailer = film.trailer;
                            aux.push_back(f);//creaza un nou vector,fara filmul pe care dorim sa l stergem
                        }
                    ListaFilme = aux1;//se pune aux in vectoru v
                    cout << "Filmul a fost sters cu succes";

                }
                else
                    if (n != 1 && n != 2)
                        cout << "Tasta incorecta";
        }


    }
    addToListaFilme2(option);
    if (ok == 0)
        cout << "Nu exista filmul";
    
}
void Film::Afisare(int optiune)
{/// Afisam lista de vizionare
    if (optiune == 1)
    {
        string topicName = "example.csv";
        system(topicName.c_str());  /// afisare lista csv
    }
    else
        if (optiune == 2)
        {
            string topicName = "webex.html"; /// afisare lista html;
            system(topicName.c_str());
        }
}
