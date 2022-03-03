#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
struct Players
{
    string pos;
    string name;
    int birth;
    string country;
    string club;
};
void ReadFile(char *input, Players players[], int& n)
{
    ifstream in;
    in.open(input);

    int i = 0;
    while (!in.eof()){
        getline(in, players[++i].pos, '/');
        getline(in, players[i].name, '/');
        in >> players[i].birth;
        in.get();
        getline(in, players[i].country, '/');
        getline(in, players[i].club, '\n');
    }
    n = i;
    in.close();
}
void Output(Players players[], int n)
{
    for (int i=1;i<=n;i++){
        cout<<players[i].pos<<'/';
        cout<<players[i].name<<'/';
        cout<<players[i].birth<<'/';
        cout<<players[i].country<<'/';
        cout<<players[i].club<<'/';
        cout<<'\n';
    }
}
void findAllPlayersBorn1994(Players players[], int n)
{
    cout<<"All players born in 1994 are: ";
    for (int i=1;i<=n;i++)
        if (players[i].birth==1994)
            cout<<players[i].name<<' ';
    cout<<'\n';
}
void findAllPlayersMUClub(Players players[], int n)
{
    cout<<"All players play for Manchester United club: ";
    for (int i=1;i<=n;i++)
        if (players[i].club=="Manchester United")
            cout<<players[i].name<<' ';
    cout<<'\n';
}
void findAllPlayersFWAndMC(Players players[], int n)
{
    cout<<"All FWs play for Manchester City: ";
    for (int i=1;i<=n;i++)
        if (players[i].pos == "FW" && players[i].club == "Manchester City")
            cout<<players[i].name<<' ';
    cout<<'\n';
}
void sortPlayers(Players players[],int n)
{
    int id;
//    for (int i=1;i<=n;i++){
//        id=i;
//        for (int j=i+1;j<=n;j++)
//            if (players[j].birth<players[id].birth)
//                id = j;
//        swap(players[id], players[i]);
//    }
    string lastName = "";
    for (int i=1;i<=n;i++){
        id=i;

        stringstream ss;
        ss<<players[i].name;
        while (ss>>lastName);

        for (int j=i+1;j<=n;j++){
            string tmpLastName;
            stringstream ss;
            ss<<players[j].name;
            while (ss>>tmpLastName);

            if (players[j].birth<players[id].birth){
                id = j;
                lastName=tmpLastName;
            }
            else if (players[j].birth==players[id].birth && tmpLastName<lastName){
                id = j;
                lastName=tmpLastName;
            }
        }
        swap(players[id], players[i]);
    }
}
int main()
{
    char input[] = "Players.txt";
    int n=0;
    Players players[100];
    ReadFile(input,players,n);
    sortPlayers(players,n);
    Output(players,n);
    return 0;
}
