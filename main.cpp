#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int widmo[256], t=0;
    for(int i = 0; i < 256; ++i)
        {
            widmo[i]=0;
        }
    double wynik=0.0;
    ifstream plik("feep.pgm"); // Otwarcie pliku do odczytu

    if (!plik) {
        cerr << "Nie mo�na otworzy� pliku." << endl;
        return 1;
    }

    string magic_number;
    int width, height, scale;

    plik >> magic_number >> width >> height >> scale; // Odczytanie magicznej liczby, szeroko�ci, wysoko�ci i skali szaro�ci

    if (magic_number != "P2") {
        cerr << "To nie jest plik PGM w formacie P2." << endl;
        return 1;
    }

    cout << "Szerokosc obrazu: " << width << endl;
    cout << "Wysokosc obrazu: " << height << endl;
    cout << "Skala szarosci: " << scale << endl;

    // Tablica dwuwymiarowa do przechowywania warto�ci szaro�ci
    vector<vector<int>> szarosci(height, vector<int>(width));

    // Odczytanie i zapisanie warto�ci szaro�ci do tablicy
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            plik >> szarosci[i][j];
            t=szarosci[i][j];
            widmo[t]=widmo[t]+1;
        }
    }

    // Wy�wietlenie warto�ci szaro�ci
    //cout << "Wartosci szarosci:" << endl;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j)
        {
        //---------------------------------------------

            if(szarosci[i][j]<180)
                {
                    if(szarosci[i][j]<160 ){wynik=wynik+1.0;}
                    else {wynik=wynik+0.5;}

                }

        //-------------------------------------------
            //cout << szarosci[i][j] << " ";
        }
        //cout << endl;
    }

    wynik=wynik/(height*width);
    printf("\nUdzial perlitu ");
    printf("%f",wynik);
    cout<<"%C"<<endl;
    cout<<endl;
    cout<<"Widmo:"<<endl;
    for(int i = 0; i < 256; ++i)
        {
            cout<<i<<"   "<<widmo[i]<<endl;
        }
    cout<<endl;
    plik.close(); // Zamkni�cie pliku

    return 0;
}
