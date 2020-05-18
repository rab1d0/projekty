#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

struct element {
    char character;
    element * next;
};
struct kolejka {
    element * head;
    element * tail;
};

void isEmpty(kolejka q);
void push(kolejka &q, char value);
void pop(kolejka &q);
void first(kolejka q);
void pop_all(kolejka &q);
void wczytaj(kolejka &q);
void wyswietl(kolejka &q);



int main()
{
    srand(time(NULL));
    kolejka q;
    q.head=NULL;
    q.tail=NULL;
    int zadanie, value;
    while(zadanie!=8)
    {
        cout<<"Menu:"<<endl;
        cout<<"1) sprawdzenie czy kolejka jest pusta"<<endl;
        cout<<"2) dodanie elementu do kolejki"<<endl;
        cout<<"3) usuniecie elementu z kolejki"<<endl;
        cout<<"4) pobranie elementu z kolejki"<<endl;
        cout<<"5) usuniecie wszystkich elementów z kolejki"<<endl;
        cout<<"6) wczytanie do kolejki duzych liter alfabetu lacinskiego z pliku"<<endl;
        cout<<"7) wyswietlenie kolejki"<<endl;
        cout<<"8) zakonczenie programu"<<endl;
        cout<<"Wybierz zadanie"<<endl;
        cin>>zadanie;
        switch(zadanie)
        {
        case 1:
            isEmpty(q);
            break;
        case 2:
            value=97+rand()%25;
            cout<<"Wylosowana wartosc: "<<value<<endl;
            push(q, value);
            break;
        case 3:
            if(q.head==NULL)
            {
                cout<<"Brak elementow do usuniecia"<<endl;
            }
            else
            {
                cout<<"Usuwamy element: "<<q.head->character<<endl;
                pop(q);
            }
            cout<<endl;
            break;
        case 4:
            if(q.head==NULL) cout<<"Kolejka jest pusta"<<endl;
            else first(q);
            break;
        case 5:
            if(q.head==NULL) cout<<"Brak elementow do usuniecia"<<endl;
            else pop_all(q);
            break;
        case 6:
            wczytaj(q);
            break;
        case 7:
            wyswietl(q);
            break;
        }
        cout<<endl;
    }
    return 0;

}
void isEmpty(kolejka q)
{
    if (q.head==NULL) cout<<"Kolejka jest pusta";
    else cout<<"Kolejka nie jest pusta";
    cout<<endl;
}

void push(kolejka &q, char value)
{
    element * el=new element;
    el->character=value;
    el->next=NULL;
    if(q.tail!=NULL)
    {
        q.tail->next=el;
    }
    else
    {
        q.head=el;
    }
    q.tail=el;
}
void pop(kolejka &q)
{
    element *temp=new element;
    temp=q.head;
    q.head=q.head->next;
    delete temp;
    if(q.head==NULL) q.tail=NULL;
}
void first (kolejka q)
{
    cout<<"Element: "<<q.head->character<<endl;
}
void pop_all(kolejka &q)
{
    while(q.head!=NULL)
    {
        pop(q);
    }
    cout<<"Usunieto wszystkie elementy"<<endl;
}
void wczytaj(kolejka &q)
{
    string linia;
    fstream plik;
    int dl;
    plik.open("tekst.txt");
    while(!plik.eof())
    {
        getline(plik, linia);
        dl=linia.length();
        for(int i=0; i<dl; i++)
        {
            if(linia[i]>=65 && linia[i]<=90) push(q, linia[i]);
        }

    }
    plik.close();
}
void wyswietl(kolejka &q)
{
    kolejka pom;
    pom.head=NULL;
    pom.tail=NULL;
    while(q.head!=NULL)
    {
        first(q);
        push(pom, q.head->character);
        pop(q);
    }
    while(pom.head!=NULL)
    {
        push(q, pom.head->character);
        pop(pom);;
    }
}
