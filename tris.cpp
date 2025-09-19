#include <iostream>
#include <vector> 
#include <iomanip> //libreria per realizzare meglio l'output (setw)
#include <windows.h>
using namespace std;

//dati che ci servono per tutta l'esecuzione del programma
struct Dati
{
    char punti_normie[9] = {'1','2','3','4','5','6','7','8','9'}; //numeri che vengono messi a schermo (poi verranno sostituiti dalle X e O a messe dal giocatore)
    vector <int> P1;
    vector <int> P2;
};

//funzione che mostra la tabella,viene chiamata ad ogni turno
void show(Dati &Dt) {
    int cc = 0; //variabile che serve a mettere i valori dell'array
    for (int I = 0; I <3; I++) { //per stampare la tabella a schermo ho diviso la tabella in 3 parti
        for (int G = 0; G < 7; G++)
        {
            if (G == 4) {
                for (int cont = 0,SPACE = 12;cont<3;cc++,cont++,SPACE -= 7) {
                    cout << setw(SPACE) <<Dt.punti_normie[cc];
                    if (cont==0) {
                        cout << setw(8) << "|";
                    }
                    else if (cont == 1) {
                        cout <<setw(5) <<"|";
                        SPACE += 7;
                    }
                    else {
                        cout << endl;
                    }
                }
            }
            else {
                cout << setw(20) << "|" << setw(10) << "|" << endl;
            }
        }
        if (I < 2) { //if che non mette la linea di -------- all'ultima parte della tabella
            cout << setw(8);
            for ( int A = 0; A < 40; A++)
            {
                cout << "-";
            }
            cout << endl;
        }
        
        
        
    }
}
// funzione che controlla se un player ha vinto
bool checkwin(Dati &Dt,bool playa) {
    vector<int> controllo; // vettore per controllare le combinazioni
    if (playa) {
        for (int W = 0; W < Dt.P1.size(); W++) {
            controllo.push_back(Dt.P1.at(W));
        }
    }
    else {
        for (int i = 0; i < Dt.P2.size(); i++) 
        {
            controllo.push_back(Dt.P2.at(i));
        }
        
    }
    int L1=0,L2=0,L3=0; // variabili per controllare se 3 caselle sono il linea
    if(Dt.P1.size() < 3 && Dt.P2.size() < 3) {
        return false;
    }
    else 
    {   
        for (int Q = 0; Q < controllo.size(); Q++) {
            if (controllo.at(Q) == 1) {
                L1 = 1;
            }
            else if (controllo.at(Q) == 2) {
                L2 = 2;
            }
            else if (controllo.at(Q) == 3) {
                L3 = 3;
            }
            if (L1 == 1 && L2 == 2 && L3 == 3){
                cout << "TRIS" << endl;
                
                return true; 
            }
        }
        for (int W = 0; W < controllo.size(); W++) {
            if (controllo.at(W) == 4) {
                L1 = 4;
            }
            else if (controllo.at(W) == 5) {
                L2 = 5;
            }
            else if (controllo.at(W) == 6) {
                L3 = 6;
            }
            if (L1 == 4 && L2 == 5 && L3 == 6) {
                cout << "TRIS" << endl;
                Sleep(1000);
                return true;
            }
        }
        for (int W = 0; W < controllo.size(); W++) {
            if (controllo.at(W) == 7) {
                L1 = 7;
            }
            else if (controllo.at(W) == 8) {
                L2 = 8;
            }
            else if (controllo.at(W) == 9) {
                L3 = 9;
            }
            if (L1 == 7 && L2 == 8 && L3 == 9) {
                cout << "TRIS" << endl;
                Sleep(1000);
                return true;
            }
        }
        for (int W = 0; W < controllo.size(); W++) {
            if (controllo.at(W) == 1) {
                L1 = 1;
            }
            else if (controllo.at(W) == 4) {
                L2 = 4;
            }
            else if (controllo.at(W) == 7) {
                L3 = 7;
            }
            if (L1 == 1 && L2 == 4 && L3 == 7) {
                cout << "TRIS" << endl;
                Sleep(1000);
                return true;
            }
        }
        for (int W = 0; W < controllo.size(); W++) {
            if (controllo.at(W) == 2) {
                L1 = 2;
            }
            else if (controllo.at(W) == 5) {
                L2 = 5;
            }
            else if (controllo.at(W) == 8) {
                L3 = 8;
            }
            if (L1 == 2 && L2 == 5 && L3 == 8) {
                cout << "TRIS" << endl;
                Sleep(1000);
                return true;
            }
        }

        for (int W = 0; W < controllo.size(); W++) {
            if (controllo.at(W) == 3) {
                L1 = 3;
            }
            else if (controllo.at(W) == 6) {
                L2 = 6;
            }
            else if (controllo.at(W) == 9) {
                L3 = 9;
            }
            if (L1 == 3 && L2 == 6 && L3 == 9) {
                cout << "TRIS" << endl;
                Sleep(1000);
                return true;
            }
        }

        for (int W = 0; W < controllo.size(); W++) {
            if (controllo.at(W) == 1) {
                L1 = 1;
            }
            else if (controllo.at(W) == 5) {
                L2 = 5;
            }
            else if (controllo.at(W) == 9) {
                L3 = 9;
            }
            if (L1 == 1 && L2 == 5 && L3 == 9) {
                cout << "TRIS" << endl;
                Sleep(1000);
                return true;
            }
        }
        for (int W = 0; W < controllo.size(); W++) {
            if (controllo.at(W) == 3) {
                L1 = 3;
            }
            else if (controllo.at(W) == 5) {
                L2 = 5;
            }
            else if (controllo.at(W) == 7) {
                L3 = 7;
            }
            if (L1 == 3 && L2 == 5 && L3 == 7) {
                cout << "TRIS" << endl;
                Sleep(1000);
                return true;
            }
        }
    }
    return false;
}
//funzione che prende cosa ha selezionato un giocatore e lo salva nel vettore e controlla che il giocatore non faccia errori
//true == errore false == non errore
bool assign_button(Dati &Dt,bool player) {
    short int move;
    cin >> move;
    if (move > 9 || 0 > move) {
        cout << "mossa fuori dal limite 1-9" << endl;
        return true;
    }
    bool numero_inserito_due_volte = false;
    move = '0'+move;
    for (int X = 0; X < 9; X++) {
        if (move == Dt.punti_normie[X]) 
            break;
        
         
        if (X==8) {
            cout << "casella gia occupata" << endl;
            return true;
        } 
    }
    move = move -'0';
    if (player) {
        Dt.P1.push_back(move);
        Dt.punti_normie[move-1] = 'X';
    }
    else {
        Dt.P2.push_back(move);
        Dt.punti_normie[move-1] = 'O';
    }
    return false;
}


int main() {
    Dati Dt;
    bool P1 = true;//con questa variabile capiamo subito se è il turno di P1 o P2 (P1 -> true , P2 -> false)
    while (true)
    {
        show(Dt);
        if (P1) {
            cout << "P1 è il tuo turno" << endl;
        }
        else {
            cout << "P2 è il tuo turno" << endl;
        }
        if (assign_button(Dt,P1)) {
            continue;
        }
        else
        if (checkwin(Dt,P1)) {
            system("cls");
            show(Dt);
            Sleep(5000);
            return 0;
        }
        P1 = !P1;
        
        system("cls");
    }
    
    
    
}