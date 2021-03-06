// Na podstawie:
// Haszowanie z pr?bkowaniem liniowym
// (C)2013 mgr Jerzy Wa?aszek
//-----------------------------------

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Funkcja haszuj?ca
//------------------
int hf(string s)
{
    unsigned int h, i;

    h = 0;
    for (i = 0; i < s.length(); i++)
        h = 2 * h + 1 - (s[i] & 1);
    return h % 10;
}

//**********************
//*** PROGRAM G??WNY ***
//**********************
int main()
{
    string T[10], s;
    int i, j, h, c, p;

    srand(time(NULL));

    // Zerujemy tablic? haszowan?
    for (i = 0; i < 10; i++) T[i] = "";

    // Tablic? wype?niamy ?a?cuchami
    for (i = 0; i < 10; i++)
    {
        // Generujemy losowy ?a?cuch z 4 znak?w A, B
        s = s4(rand() % 16);

        // ?a?cuch umieszczamy w tablicy haszowanej
        h = hf(s);
        j = h;
        while (true)
        {
            if (T[j] == "")
            {
                T[j] = s;
                break;
            }
            if (T[j] == s) break;
            j = (j + 1) % 10;
            if (j == h) break;
        }
    }

    T[0] = "sto";
    T[1] = "stomatologia";
    T[2] = "stopa";
    T[3] = "stowa";
    T[4] = "stomatolog";
    T[5] = "strach";
    T[6] = "strych";
    T[7] = "trzymaj";
    T[8] = "trzy";
    T[9] = "trzech";

    // Wy?wietlamy zawarto?? tablicy wraz z warto?ci? funkcji haszuj?cej
    for (i = 0; i < 10; i++)
    {
        cout << "T [ " << i << " ] = ";
        if (T[i] != "") cout << T[i] << " hf( ) = " << hf(T[i]);
        else           cout << "-";
        cout << endl;
    }

    cout << endl;

    // Sprawdzamy obecno?? ?a?cuch?w w tablicy haszowanej
    for (i = 0; i < 10; i++)
    {
        s = T[i];  // ?a?cuch
        h = hf(s);  // Hasz ?a?cucha
        c = 0;      // Licznik obieg?w
        j = h;
        p = -1;
        while (true)
        {
            if (T[j] == "") break;
            if (T[j] == s)
            {
                p = j; break;
            };
            j = (j + 1) % 10;
            if (j == h) break;
            c++;
        }

        // Wy?wietlamy wyniki
        cout << s << " hf( ) = " << h << " c = " << c << " ";
        if (p > -1) cout << "is in T [ " << p << " ] ";
        else       cout << "-";
        cout << endl;
    }

    cout << endl;

    return 0;
}