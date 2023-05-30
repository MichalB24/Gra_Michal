#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include <fstream>


using namespace std;

struct Character
{
    string name;
    int strength;
    int speed;
    int agility;
    int health;
    int experience;
    int level;
    int pojedynkiW;
    int pojedynkiF;
};
vector<Character> characters;



void createCharacter(Character* character, int punkty)
{
    cout<<"Wpisz imie swojego bohatera: ";
    cin>>character->name;


        string filename="postacie/"+character->name+".txt";
             ifstream file(filename);

            if (file.is_open())
            {
               cout<<"Postac o podanej nazwie juz istnieje! Prosze wybrac inna nazwe."<<endl<<endl;
                createCharacter(character, punkty); // Rekurencja
                 file.close();
                return;

            }



    do
        {
        cout<<"Punkty do rozdysponowania: "<<punkty<<endl;
        cout<<"Ilosc punktow sily: ";
        cin>>character->strength;

        cout<<"Punkty do rozdysponowania: "<<punkty-character->strength<<endl;
        cout<<"Ilosc punktow szybkosci: ";
        cin>>character->speed;

        cout<<"Punkty do rozdysponowania: "<<punkty-character->strength-character->speed<<endl;
        cout<<"Ilosc punktow zwinnosci: ";
        cin>>character->agility;
        cout<<endl;

        if (punkty-character->strength-character->speed-character->agility<0)
        {
            cout<<"Blad wprowadzania danych!!"<<endl<<"Rozdysponowano zbyt duzo punktow. Wymisz punkty jeszcze raz."<<endl;
        }
        if (0>character->strength||0>character->speed||0>character->agility)
        {
            cout<<"Blad wprowadzania danych!!"<<endl<<"Niektore dane sa ujemne."<<endl<<endl;
        }

    } while (punkty-character->strength-character->speed-character->agility<0||0>character->strength||0>character->speed||0>character->agility);

    character->health=100;
    character->experience=0;
    character->level=1;
    character->pojedynkiW=0;
    character->pojedynkiF=0;

    cout<<endl<<endl<<"Oto twoj bohater!"<<endl;
    cout<<"Imie: "<<character->name<<endl;
    cout<<"Sila: "<<character->strength<<endl;
    cout<<"Szybkosc: "<<character->speed<<endl;
    cout<<"Zwinnosc: "<<character->agility<<endl;
    cout<<"Zdrowie: "<<character->health<<endl;
    cout<<"Doswiadczenie: "<<character->experience<<endl;
    cout<<"Poziom: "<<character->level<<endl;
}

void generateEnemy(Character* enemy, int n,int poziom)
{
    string names[]={"Miecznik","Siatkasz","Kosownik","Nozownik","Lucznik"};
    int count=sizeof(names)/sizeof(names[0]);
    int punkciki=30+20*(poziom-1);
    int ID=rand()%count;
    enemy->name =names[ID];
    enemy->strength=rand()%(punkciki*n)+n;
    punkciki=punkciki-enemy->strength;
    enemy->speed=+(rand()%(punkciki*n)+n);
    punkciki=punkciki-enemy->speed;
    enemy->agility=(punkciki);
    enemy->health=100;

    cout<<"Napotkales przeciwnika o nastepujacych statystykach:"<<endl;
    cout<<"Nazwa: "<<enemy->name<<endl;
    cout<<"Sila: "<<enemy->strength<<endl;
    cout<<"Szybkosc: "<<enemy->speed<<endl;
    cout<<"Zwinnosc: "<<enemy->agility<<endl;
}


void levelUp(Character* character)
{

if(character->experience%100==0&&character->experience!=0)
{
        cout<<endl;

    //lewel 2=100    lewel 3=200  lewel 4=300
    character->level++; // Zwiêkszanie poziomu postaci


    int punkty= 20; // Dodatkowe punkty umiejêtnoœci

    cout<<"Gratulacje! Twoja postac ("<<character->name<<") awansowala na poziom "<<character->level<<"!"<<endl<<endl;
    cout<<"Masz do rozdysponowania "<<punkty<<" punktow umiejetnosci."<<endl;

    while (punkty> 0)
    {
        int a=0;int b=0; int c=0;
        cout << "Ilosc punktow sily: ";
        cin >> a;

        cout << "Ilosc punktow szybkosci: ";
        cin >> b;

        cout << "Ilosc punktow zwinnosci: ";
        cin >>c;

        int n=a+b+c;

        if (n<= punkty)
        {
            punkty=punkty-n;
            character->strength=character->strength+a;
            character->speed=character->speed+b;
            character->agility=character->agility+c;
            break;
        }
        else
        {
             cout<<"Blad wprowadzania danych!!"<<endl<<"Rozdysponowano zbyt duzo punktow. Wymisz punkty jeszcze raz."<<endl;
        }
    }

    cout<<"Postac ("<<character->name<< ") poleprzyla swoje statystyki!"<<endl;
    cout<<"Imie: "<<character->name<<endl;
    cout<<"Sila: "<<character->strength<<endl;
    cout<<"Szybkosc: "<<character->speed<<endl;
    cout<<"Zwinnosc: "<<character->agility<<endl;
}
}




void fight(Character& player, const Character& enemy)
{
cout<<"WALKA ROZPOCZETA"<<endl<<"*******************************************************************"<<endl;
cout<<"Statystyki gracza:"<<endl;
cout<<"Imie: "<<player.name<<endl;
cout<<"Sila: "<<player.strength<<endl;
cout<<"Szybkosc: "<<player.speed<<endl;
cout<<"Zwinnosc: "<<player.agility<<endl;
cout<<"Zdrowie: "<<player.health<<endl;
cout<<"Doswiadczenie: "<<player.experience<<endl;
cout<<"Poziom: "<<player.level<<endl;
cout<<endl<<"VS"<<endl<<endl;

cout<<"Statystyki wroga"<<endl;
cout<<"Nazwa: "<<enemy.name<<endl;
cout<<"Sila: "<<enemy.strength<<endl;
cout<<"Szybkosc: "<<enemy.speed<<endl;
cout<<"Zwinnosc: "<<enemy.agility<<endl;
cout<<"Zdrowie: "<<enemy.health<<endl;

int playerHealth=100;
int enemyHealth=enemy.health;


while (playerHealth>0&&enemyHealth>0)
{
    // Gracz atakuje przeciwnika
    int playerDamage=player.strength;
    bool hitEnemy=(rand()%100)<(player.speed*10)-(enemy.agility*5);
        bool hitChance = rand()%100<70;//[dodatkowa bariera

        //80/100+30/100
    if (hitEnemy==1&&hitChance==1)
    {
        enemyHealth= enemyHealth-playerDamage;
        cout<<"Gracz ("<<player.name<<") zadal przeciwnikowi ("<<enemy.name<<") "<<playerDamage<<" punktow obrazen!"<<endl<<endl;
    }
    else {
        cout<<"Gracz ("<<player.name<<") spudlowal!"<<endl<<endl;
    }

    if (enemyHealth<=0)
    {
        cout<<"Gracz ("<<player.name<<") zwyciezyl!"<<endl;
        player.experience=player.experience+50;
        player.pojedynkiW++;
        break;
    }

    // Przeciwnik atakuje gracza
    int enemyDamage = enemy.strength;
    bool hitPlayer = (rand() % 100)<(enemy.speed*10)-(enemy.agility*5);
        bool hitChance2 = rand()%100<70;//[dodatkowa bariera
    if (hitPlayer&&hitChance2==1)
    {
        playerHealth=playerHealth-enemyDamage;
        cout<<"Przeciwnik ("<<enemy.name<<") zadal graczowi ("<<player.name<<") "<<enemyDamage<<" punktow obrazen!"<<endl<<endl;
    }
    else
    {
        cout<<"Przeciwnik ("<<enemy.name<<") spudlowal!"<<endl;
    }

    if (playerHealth<=0)
    {
        cout<<"Przeciwnik ("<<enemy.name<<") zwyciezyl!"<<endl;
        player.pojedynkiF++;
        break;
    }

    cout<<endl;
}
levelUp(&player);
}

void createNewCharacter(Character* character, int punkty)
{
        cout<<"Stworz nowa postac"<<endl;

            // Wprowadzenie nazwy postaci
            cout<<"Wpisz imie nowego bohatera: "<<endl;
            cin>>character->name;

            bool uniqueName=1;
            vector<Character> characters;


            string filename="postacie/"+character->name+".txt";
             ifstream file(filename);

            if (file.is_open())
            {
               cout<<"Postac o podanej nazwie juz istnieje! Prosze wybrac inna nazwe."<<endl<<endl;
                createNewCharacter(character, punkty); // Rekurencja
                 file.close();
                return;

            }





        // Wprowadzenie atrybutów postaci
        do
        {
            cout<<"Punkty do rozdysponowania: "<<punkty<<endl;
            cout<<"Ilosc punktow sily: ";
            cin>>character->strength;

            cout<<"Punkty do rozdysponowania: "<<punkty-character->strength<<endl;
            cout<<"Ilosc punktow szybkosci: ";
            cin>>character->speed;

            cout << "Punkty do rozdysponowania: "<<punkty-character->strength-character->speed<<endl;
            cout << "Ilosc punktow zwinnosci: ";
            cin >> character->agility;

            if (punkty-character->strength-character->speed-character->agility<0)
            {
                cout<<"Blad wprowadzania danych!!"<<endl<<"Rozdysponowano zbyt duzo punktow. Wymisz punkty jeszcze raz."<<endl;
            }

        } while (punkty-character->strength-character->speed-character->agility<0);


character->health=100;
character->experience=0;
character->level=1;

cout<<endl<< endl<<"Postac zostala stworzona!"<<endl;
cout<<"Imie: "<<character->name<<endl;
cout<<"Sila: "<<character->strength<<endl;
cout<<"Szybkosc: "<<character->speed<<endl;
cout<<"Zwinnosc: "<<character->agility<<endl;
cout<<"Zdrowie: "<<character->health<<endl;
cout<<"Doswiadczenie: "<<character->experience<<endl;
cout<<"Poziom: "<<character->level<<endl;
}


/*
void loadCharacter(Character* character, const string& name)
{


bool foundCharacter=false;

for (const auto& existingCharacter:characters)
{
    if (existingCharacter.name==name)
    {
        *character=existingCharacter;
        foundCharacter=true;
        break;
    }
}

if (foundCharacter)
{
    cout<<"Postac "<<name<<" zostala wczytana!"<<endl;
    cout<<"Imie: "<<character->name<<endl;
    cout<<"Sila: "<<character->strength<<endl;
    cout<<"Szybkosc: "<<character->speed<<endl;
    cout<<"Zwinnosc: "<<character->agility<<endl;
    cout<<"Zdrowie: "<<character->health<<endl;
cout<<"Doswiadczenie: "<<character->experience<<endl;
cout<<"Poziom: "<<character->level<<endl;
}
else
{
cout<<"Postac o nazwie "<<name<<" nie istnieje!"<<endl;
}
}
*/
void saveCharacterStats(const Character& character)
{
    string filename="postacie/"+character.name+".txt"; // Tworzenie nazwy pliku na podstawie imienia postaci

    ofstream file(filename);

    if (file.is_open())
    {
        file<<"Imie: "<<character.name<<endl;
        file<<"Sila: "<<character.strength<<endl;
        file<<"Szybkosc: "<<character.speed<<endl;
        file<<"Zwinnosc: "<<character.agility<<endl;
        file<<"Zdrowie: "<<character.health<<endl;
        file<<"Doswiadczenie: "<<character.experience<<endl;
        file<<"Poziom: "<<character.level<<endl;
        file<<"Wygrane: "<<character.pojedynkiW<<endl;
        file<<"Przegrane: "<<character.pojedynkiF<<endl;

        file.close();

        cout<<"Postac "<<character.name<<" zostala zapisana!"<<endl;
    }
    else
    {
        cout<<"Nie mozna zapisac postaci "<<character.name<<" do pliku."<<endl;
    }
}

void loadCharacterStats(Character* character, const string& name)
{
    string filename="postacie/"+name+".txt";

    ifstream file(filename);

    if (file.is_open())
    {
        string line;

        while (getline(file, line))
        {

            if (line.find("Imie: ")!=string::npos)
            {
                character->name=line.substr(6);
            }
            else if (line.find("Sila: ")!=string::npos)
            {
                character->strength = stoi(line.substr(6));
            }
            else if (line.find("Szybkosc: ")!=string::npos)
            {
                character->speed = stoi(line.substr(10));
            }
            else if (line.find("Zwinnosc: ")!=string::npos)
            {
                character->agility = stoi(line.substr(10));
            }
            else if (line.find("Zdrowie: ")!=string::npos)
            {
                character->health = stoi(line.substr(9));
            }
            else if (line.find("Doswiadczenie: ")!=string::npos)
            {
                character->experience=stoi(line.substr(15));
            }
            else if (line.find("Poziom: ")!=string::npos)
            {
                character->level = stoi(line.substr(8));
            }
            else if (line.find("Wygrane: ")!=string::npos)
            {
                character->pojedynkiW=stoi(line.substr(9));
            }
            else if (line.find("Przegrane: ")!=string::npos)
            {
                character->pojedynkiF=stoi(line.substr(11));
            }

        }

        file.close();

        cout<<"Statystyki postaci "<<name<<" zostaly wczytane!"<<endl;
    }
    else
    {
        cout<<"Postac "<<name<<" nie zostala wczytana."<<endl;
    }
}

vector<Character> tablica_wynikow;
void saveBoard(const Character& character)
{
    // Tworzenie nazwy pliku na podstawie imienia postaci

    ofstream file("Tablica_wynikow.txt",ios::app);


    if (file.is_open())
    {
        /*
         string line;


                ifstream checkFile("Tablica_wynikow.txt");

            bool nameExists=false;

            while (getline(checkFile, line))
            {
                if (line.find("Imiê: "+character.name)!=string::npos)
                {
                    nameExists = true;
                    break;
                }
            }

            if (nameExists)
            {

                cout << "Gracz " << character.name << " ju¿ istnieje w pliku. Czy chcesz nadpisaæ jego wynik? (T/N): ";
                char a;
                cin >> a;

                if (a != 'T' && a != 't')
                {
                    //continue;//pomin wynik
                }
            }

            */

            file<<"Imie: "<<character.name << endl;
            file<<"Poziom: "<<character.level<<endl;
            file<<"Zwyciestwa: "<<character.pojedynkiW<<endl;
            file<<"Porazki: "<<character.pojedynkiF<<endl;
            file<<"-----------------------------------"<<endl;


        file.close();

        cout << "Wyniki zostaly zapisane!" << endl;
    }
    else
    {
        cout << "Nie mozna zapisaæ wynikow do pliku." << endl;
    }


}


void DispTab()
{
   ifstream file("Tablica_wynikow.txt");
    if (file.is_open())
    {
        string line;
        while(getline(file, line))
        {
            cout<<line<<endl;
        }
        file.close();
    }
    else
    {
        cout<<"Nie znaleziono tablicy wynikow."<<endl;
    }
}


int main()
{
srand(time(NULL)); // Inicjalizacja generatora liczb losowych
cout<<"Witamy w grze: "<<endl<<endl<<"Walki Gladiatorow"<<endl<<endl;
Character player;
bool w=0;


while(w==0)
{
cout<<"Wybierz aktywnosc:"<<endl;
cout<<"1.Stworz swojego bohatera"<<endl<<"2.Wczytaj postac"<<endl<<"3.Walcz na arenie"<<endl<<"4.Zapisz swoj postep"<<endl<<"5.zapisz bohatera na tablicy wynikow"<<endl<<"6.Wyswietl tablice wynikow"<<endl<<"7.wyjdz"<<endl;
int a;
cin>>a;







switch(a)
{
case 1:
    {
    createCharacter(&player, 30);
    break;
    }


case 2:
    {
    string names;
    cout<<"Podaj imie bohatera jakiego chcesz wczytac: "<<endl;
    cin>>names;
    loadCharacterStats(&player, names);
    break;
    }



case 3:
    {
    Character enemy;
generateEnemy(&enemy, 1,player.level);
fight(player, enemy);
    break;
    }


case 4:
    {
    saveCharacterStats(player);
    }
    break;



case 5:
    saveBoard(player);
    break;

case 6:
    DispTab();
    break;

   case 7:
        w=1;
    break;


default:
    {

    cout<<"Wybrano zla akcje. Wprowadz poprawna liczbe"<<endl;
    break;
    }

}
 cout<<endl;


//createCharacter(&player, 30);
   // loadCharacterStats(&player, "john");


//cout<<endl<<endl;
//fight(player, enemy);
//
//fight(player, enemy);


}
return 0;

}


