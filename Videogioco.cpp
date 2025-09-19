#include <iostream>
#include <iomanip>
#include <random>
#include <conio.h>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

//function that makes change color of the words
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}


class classe {
    public:
    virtual int attacco()=0;
    virtual int deff()=0;
    virtual bool speciale()=0;
    virtual bool parry()=0;
    virtual int vita()=0;
    virtual string name()=0;
    virtual void danno(int damage)=0;
    virtual int ulti()=0;
};
class Stregone : public classe
{
private:
    random_device rd;
    mt19937 gen1;
public:
    int healt = 300;
    int color = 3;
    double G = 7;
    string N_classe = "Stregone";
    string name() override {
        return this->N_classe;
    }
    int attacco() override {
        uniform_int_distribution<int> dist(60,150);
        return dist(this->gen1);
    }

    int deff() override {
        uniform_int_distribution<int> dist(20, 200);
        return dist(this->gen1);
    }

    bool speciale() override {
        discrete_distribution <bool> ciccio ({G,3});
        return ciccio(gen1);
    }

    bool parry() override {
        discrete_distribution <bool> sabaku ({5,5});
        return sabaku(gen1);
    }

    int vita() override {
            return this->healt;
    }
    void danno(int damage) override {
        this->healt -= damage;
    }

    int ulti() override {
        setColor(3);
        std::cout << "per questo turno sei immune ai danni e infliggi 70 al nemico" << endl;
        setColor(15); 
        return 5000;
    }

};

class Cavaliere : public classe {
    private:
    random_device Cd;
    mt19937 gen2;
    public:
        int healt = 600;
        string N_classe = "Cavaliere";
        double S = 7;
        string name() override {
            return this->N_classe;
        }
        int attacco() {
            uniform_int_distribution <int> ATT(40,160);
            return ATT(gen2);
        }

        int deff() override  {
            uniform_int_distribution <int> DIFF(80,200);
            return DIFF(gen2);
        }

        bool speciale() {
            discrete_distribution <bool> ciccio ({S,3});
            return ciccio(gen2);
        }

        bool parry() {
            discrete_distribution <bool> sabaku ({5,5});
            return sabaku(gen2);
        }

        int vita() override {
            return this->healt;
        }
        void danno(int damage) override {
        this->healt -= damage;
        }
        int ulti() override {
            setColor(2);
            std::cout << "hai tirato un colpo potentissimo da 250 danni" << endl;
            setColor(15);
            return 250;
        }
};

class Assassino : public classe  {
    private:
    random_device SD;
    mt19937 gen3;
    public:
        int healt = 400;
        string N_classe = "Assassino";
        double S = 7;
        string name() override {
            return this->N_classe;
        }
        int vita() override {
                return this->healt;
            }
        int attacco() override {
            uniform_int_distribution <int> ATT(80,120);
            return ATT(gen3);
        }

        int deff() override {
            uniform_int_distribution <int> DIFF(40,80);
            return DIFF(gen3);
        }

        bool speciale() override {
            discrete_distribution <bool> ciccio ({S,5});
            return ciccio(gen3);
        }

        bool parry() override {
            discrete_distribution <bool> sabaku ({5,5});
            return sabaku(gen3);
        }
        void danno(int damage) override {
            this->healt -= damage;
        }

        int ulti() override {
            setColor(4);
            bool critico;
            int Io;
            int end = 0;
            int c;
            end = 0;
            for (Io = 0;Io < 10; Io++) {
                critico = parry();
                if (critico) {
                    std::cout << "Critico!" << endl;
                    std::cout << " -30HP" << endl << endl;
                    c = 30;
                    Sleep(500);
                }
                else {
                    c = 10;
                    std::cout << " -10HP" << endl;
                    
                }
                if (Io % 2 == 0) {
                    std::cout << "TSA " << endl;
                    end += c;
                    Sleep(500);
                }
                else {
                    std::cout << "BEAM" << endl;
                    end +=c;
                    Sleep(500);
                }
                
            }
            setColor(15);
            std::cout << endl << "totale; " << end << endl;
            return end;
        }
};

class Angelo : public classe {
    private:
        random_device AD;
        mt19937 gen4;
    public:
        int healt = 500;
        string N_classe = "Angelo";
        double S = 7;
        string name() override {
            return this->N_classe;
        }
        int vita() override {
            return this->healt;
        }

        int attacco() override {
            uniform_int_distribution <int> ATT(60,140);
            return ATT(gen4);
        }

        int deff() override {
            uniform_int_distribution <int> DIFF(45,100);
            return DIFF(gen4);
        }

        bool speciale() override {
            discrete_distribution <bool> ciccio ({S,5});
            return ciccio(gen4);
        }

        bool parry() override {
            discrete_distribution <bool> sabaku ({5,5});
            return sabaku(gen4);
        }
        void danno(int damage) override {
            healt = healt - (damage);
        }

        int ulti() override {
            setColor(14);
            std::cout << "ti sei curato, +200 HP" << endl;
            setColor(15);
            return 200;
        }
};

class bot : public classe {
    private:
    random_device BD;
    mt19937 gen5;
    public:
    int healt = 500;
    string N_classe = "Bot";
    double S = 7; //prob speciale
    string name() override {
        return this->N_classe;
    }
    int vita() override {
        return this->healt;
    }

    int attacco() override {
        uniform_int_distribution <int> ATT(60,145);
        return ATT(gen5);
    }

    int deff() override {
        uniform_int_distribution <int> DIFF(50,100);
        return DIFF(gen5);
    }

    bool speciale() override {
        discrete_distribution <bool> ciccio ({S,5});
        return ciccio(gen5);
    }

    bool parry() override {
        discrete_distribution <bool> sabaku ({5,5});
        return sabaku(gen5);
    }

    int scelta() {
        uniform_int_distribution <int> decisione (1,4);
        return  decisione(gen5);
    }
    void danno(int damage) override {
        this->healt -= damage;
    }
    int ulti() override {
        std::cout << "L'avversario ti ha tirato una bella botta da 150 HP" << endl;
        return 150;
    }
    

};

//global variable
string nome;


void campo_battaglia(classe &PP) {
    setColor(15);
    string mosse[4] = {"attaccare","difendersi","usare la special","parryare"};
    bot b;
    bool morto_P = false,morto_B = false,skip = false; //bool variables to check if the bot or the player has finished the healt;
    std::cout << "Inizio Scontro!" << endl;
    while (morto_B == false && morto_P == false) {
        if (PP.vita() <= 0) {
        setColor(4);
        std::cout << "GAME OVER" << endl;
        setColor(15);
        std::cout << "il nemico ti ha sconfitto" << endl;
        morto_P = true;
        continue;
        }
    else if (b.vita() <= 0) {
        setColor(3);
        std::cout << "VITTORIA!" << endl;
        setColor(15);
        std::cout << "Hai sconfitto il nemico" << endl;
        morto_B = true;
        continue;
    }
        char P_com;
        int B_com;
        std::cout << endl << endl;
        std::cout << " E' il tuo turno " << nome << " scegli una tra queste 4 mosse! " << endl;
        std::cout << PP.name() << "    HP: " << PP.vita() << endl;
        setColor(4);
        std::cout << setw(15) <<"1. Attacco";  
        setColor(3);
        std::cout << setw(5) <<" 2. Difesa " << endl;
        setColor(6);
        std::cout << setw(15) <<"3. Special";
        setColor(13);
        std::cout << setw(5) <<" 4. Parry" << endl;
        setColor(15);
        std::cout << "nemico;" << b.N_classe << setw(10) << b.vita() << endl;

        kbhit();

        do
        {   
            P_com = getch();
        } while (P_com != '1' && P_com != '2'  && P_com != '3'  &&  P_com != '4' );
        
        
        B_com = b.scelta();
        std::cout << "il tuo nemico ha scelto di " << mosse[B_com-1] << endl;
        int defense=0;
        switch (P_com)
        {
        case '1':
            if (B_com == 2) {
                defense = b.deff();
                int attack = PP.attacco() - defense ;
                if (attack > 0) {
                    b.danno(attack);
                    std::cout << "il tuo attacco di " << attack + defense << " ha causato " << attack << " di danni contro la difesa del nemico di " << defense << endl;
                }
                else
                std::cout << "il tuo attacco di " << attack + defense << "è stato annulato dalla difesa del nemico di " << defense << endl; 
            }
            else if (B_com == 4) {
                bool check = b.parry();
                int attack = PP.attacco();
                if (check == true) {
                    std::cout << "il tuo colpo e' stato parryato! -" << attack << " HP" << endl;
                    PP.danno(attack);
                }
                else {
                    std::cout << "l'avversario ha fallito a fare il parry" << endl;
                    std::cout << "il tuo attacco ha fatto " << attack << " danni" << endl;
                    b.danno(attack);
                }
            }
            else {
                int attack = PP.attacco();
                std::cout << "il tuo attacco ha causato " << attack << " danni" << endl;
                b.danno(attack);
            }
            break;
        case '2':
            defense = PP.deff();
            std::cout << "hai una difesa di " << defense << " HP" << endl;
            break;
        case '3':
            bool spicial;
            int dann;
            spicial = PP.speciale();
            if (spicial == true) {
                std::cout << "la tua special ha avuto successo! " << endl;
                dann = PP.ulti();
                if (PP.name() == "Stregone") {
                    b.healt-=70; 
                    continue;
                } 
                else if (PP.name() == "Cavaliere") {
                    b.healt-=dann;
                }
                else if (PP.name()=="Assassino") {
                    b.healt-=dann;
                    continue;
                }
                else if(PP.name() == "Angelo") {
                    PP.danno(-200);
                }
                else;
            } 
            else {
                setColor(4);
                std::cout << " X X ";
                setColor(15);
                std::cout << "special fallita ";
                setColor(4);
                std::cout << " X X " << endl;
                setColor(15);
            }
            break;

        case '4':
            bool parrio;
            parrio = PP.parry();
            if (parrio) {
                if (B_com == 1) {
                    skip = true;
                    int back; 
                    back = b.attacco();
                    std::cout << "hai parriato il colpo al nemico! -" << back << "HP" << endl;
                    b.danno(back);
                }
                else if (B_com == 3) {
                    bool check;
                    skip = true;
                    check = b.speciale();
                    if (check) {
                        int dannoi;
                        dannoi = b.ulti();
                        std::cout << "hai parriato il colpo al nemico! -" << dannoi << "HP" << endl;
                        b.danno(dannoi);
                    }
                    else std::cout << "l'avversario non ha attaccato e sei rimasto li come uno scemo mentre che aspettavi il suo attacco " << endl;
                }
            }
            else {
                std::cout << "parry fallito!" << endl;
            }
            break;
        default:
            std::cout << "messaggio che non sara mai mostrato" << endl;
            break;
        }
        if (B_com == 1 && skip == false) {
            int attacko;
            attacko = b.attacco() - defense;
            if (attacko > 0) {
                std::cout << "il nemico ha inflitto -" << attacko << "HP" << endl;
                PP.danno(attacko);
            }
            else {
                std::cout << "l'attacco del nemico è stato annullato dalla tua difesa" << endl;
            }
        }
        if (B_com == 3 && skip == false) {
            bool special;
            special = b.speciale();
            if (special == true) {
                std::cout << "l'avversario ha usato la sua special!" << endl;
                int danno = b.ulti();
                PP.danno(danno);
            }
            else {
                std::cout << "l'avversario ha fallito la sua special" << endl;
            }
        }
        if (PP.vita() <= 0) {
        setColor(4);
        std::cout << "GAME OVER" << endl;
        setColor(15);
        std::cout << "il nemico ti ha sconfitto" << endl;
        Sleep(5000);
        morto_P = true;
        break;
        }
    else if (b.vita() <= 0) {
        setColor(3);
        std::cout << "VITTORIA!" << endl;
        setColor(15);
        std::cout << "Hai sconfitto il nemico" << endl;
        Sleep(5000);
        morto_B = true;
        break;
    }
    skip = false;
    Sleep(3000); // Sleep for 3 seconds (3000 milliseconds) on Windows
    system("cls");
    } 
    
}

void scelta() {
    char coms;
    classe* PP;
    linux:
    setColor(15);
    coms = getch();
    switch (coms) {
        case '1': {;
            setColor(3);
            std::cout << "Hai scelto la Class Stregone" << endl;
            PP = new Stregone();
            break;
        }
        case '2': {
            PP = new Cavaliere();
            setColor(2);
            std::cout << "Hai scelto la Class Cavaliere" << endl;
            break;
        }

        case '3': {
            setColor(4);
            PP = new Assassino();
            std::cout << "Hai scelto la Class Assassino" << endl;
            break;
        }
        case '4': {
            setColor(14);
            PP = new Angelo();
            std::cout << "Hai scelto la Class Angelo" << endl;
            break;
        }
        default:
        std::cout << "non esistente,premi un carattere tra 1-4" << endl;
        goto linux;
    }
    campo_battaglia(*PP);
    delete PP;

    exit(0);
}


int main() {
    setColor(15);
    std::cout << "Salve player! inserisci il tuo nome da giocatore" << endl;
    getline(cin,nome);
    std::cout << "(premi un altra volta invio)" << endl;
    cin.ignore();
    std::cout << "perfetto, adesso scegli 1 tra queste 4 classi, ti bastera premere un numero tra 1 e 4" << endl;
    std::cout << endl;
    setColor(3);
    std::cout << "1. Stregone" << endl; 
    setColor(2);
    std::cout << "2. Cavaliere" << endl;
    setColor(4);
    std::cout << "3. Assassino" << endl;
    setColor(14);
    std::cout << "4. Angelo" << endl;
    scelta();
}

 
