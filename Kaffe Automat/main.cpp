//
//  main.cpp
//  Kaffe Automat
//
//  Created by Juan Isaza on 12.01.22.
//

#include<iostream>
//#include<conio.h>
#include<string.h>
#include<vector>



//firma: Firma Risto SA
//produkte: Kaffe
//anfangs angeboten 6, spaeter 10
//mit Code Nummer bestellen, -> falsche eingaben, dann wieder fragen.
//auch nach Zuckerfragen -> (ja soll antwort mit 1, nein soll 0 sein) auch nach Menge fragen, mit Nummer antwort eingeben.
//zucker ist nicht gratis- zus‰tzliche kosten von 0.20 CHF
// Der Preis der Kunde Zeigen und anfordern zu zahlen
// Der kunde kann mit Geldmuenz zahlen
// Muenzpruefung machen - zuviel oder zuwenig der kunde zurueckgeben oder nach fragen.
// wenn der betrag eingegeben ist kann nicht mehr aufhoeren oder stournieren.
//der Kunde immer ueber den aktuellen Arbeitsprozess informiert ist
// formatier und mit waerung gezeigt werden
//Taste C abbrechen



using namespace std;

// Model für zukünftige Kaffe sorten
struct KaffeProdukt {
    string name;
    int code =  0;
    float preis = 0;
    
};

void begruessung();

void instructions();

// abstand für der layout.
string abstandGeber(string &, vector<KaffeProdukt> &);

string abstandGeberPlus(int, int);

void linieLayout();

void rowLayout(vector<KaffeProdukt> &);

void eingabeZuckerOptionen(char &);

void infoUndZahlungAnfondern(vector<KaffeProdukt> &, int, char &);

void kaffeWahlOption(int &);

void vorbereitundInfo();

void verabschiedung();

void muenzZahlungsProzessMitZucker(vector<KaffeProdukt> &, int, float &, float &, float &);

void muenzZahlungsProzessOhneZucker(vector<KaffeProdukt> &, int, float &, float &, float &);

void abbrechung();

int elementeZumZeigen(int &); // toma el codigo de los Kaffes y los transforma en un indice aptop para usar con el vector de elementos de cafe.

void ablaufSection(vector<KaffeProdukt> &, char &, int &, bool &, float &, float &);
    
    



int main() {
    
    
    vector<KaffeProdukt> auswahlKollection = {
        {"Kaffee schwarz", 10, 1.50},
        {"Kaffe Macchiato", 11, 2.00},
        {"Latte Macchiato", 12, 3.00},
        {"Espresso schwarz", 13, 2.00},
        {"Espresso Macchiato", 14, 3.00},
        {"Latte Macchiato intenso", 15, 3.00}
    };
    
    
    
    float zuckerPrise = 0.20;
    char mitZucker = '0';
    int gewaehlt = 0 ;
    bool erfolg = false;
    float zahlung = 0;
    
    begruessung();
    rowLayout(auswahlKollection);
    cout << endl;
    kaffeWahlOption( gewaehlt);
    cout << endl;
    ablaufSection(auswahlKollection, mitZucker, gewaehlt, erfolg, zuckerPrise, zahlung);
    cout << "\tAuf wiedersehen!!" << endl;
    cout << endl << endl;
    system("pause");
    return 0;
}



void begruessung() {
    cout << endl;
    cout << "\t\t\t\tKaffe al gusto!\n \t\t\t\t   Risto SA." << endl;
    cout << endl;
    cout << endl;
}

void linieLayout() {
    cout << "--------------------------" ;
}


void rowLayout(vector<KaffeProdukt> &produktToDisplay) {

    string space = abstandGeberPlus(7,23);

    linieLayout(); linieLayout(); linieLayout(); cout << endl; // dibuja tres lineas horizontales
    cout << "| " << space << "Nr. "<< produktToDisplay[0].code << " | "
    << space << "Nr. " << produktToDisplay[1].code << " | "
    << space << "Nr. " << produktToDisplay[2].code << " |" << endl;
    
    cout << "| " << produktToDisplay[0].name << abstandGeber(produktToDisplay[0].name, produktToDisplay) <<" | "
     << produktToDisplay[1].name << abstandGeber(produktToDisplay[1].name, produktToDisplay) <<" | "
     << produktToDisplay[2].name << abstandGeber(produktToDisplay[2].name, produktToDisplay) <<" |"
     << endl;
     
     
    cout << "| " << "CHF " << produktToDisplay[0].preis << abstandGeberPlus(8, 23) <<" | "
    << "CHF " << produktToDisplay[1].preis << abstandGeberPlus(6, 23) <<" | "
    << "CHF " << produktToDisplay[2].preis << abstandGeberPlus(6, 23) <<" |"
    
    
    << endl;
        linieLayout(); linieLayout(); linieLayout(); cout << endl;
        
        cout << "| " << space << "Nr. "<< produktToDisplay[3].code << " | "
    << space << "Nr. " << produktToDisplay[4].code << " | "
    << space << "Nr. " << produktToDisplay[5].code << " |" << endl;
    
    cout << "| " << produktToDisplay[3].name << abstandGeber(produktToDisplay[3].name, produktToDisplay) <<" | "
     << produktToDisplay[4].name << abstandGeber(produktToDisplay[4].name, produktToDisplay) <<" | "
     << produktToDisplay[5].name << abstandGeber(produktToDisplay[5].name, produktToDisplay) <<" |"
     << endl;
     
     
    cout << "| " << "CHF " << produktToDisplay[3].preis << abstandGeberPlus(6, 23) << " | "
    << "CHF " << produktToDisplay[4].preis << abstandGeberPlus(6, 23) << " | "
    << "CHF " << produktToDisplay[5].preis << abstandGeberPlus(6, 23) << " |"
    
    
    << endl;
        linieLayout(); linieLayout(); linieLayout(); cout << endl;
    

    
};

void instructions() {
    
    cout << "Bitte waehlen sie die Kaffe die sie haben moechten" << endl;
   
    
}

void kaffeWahlOption(int &gewaehlt) {
    
    bool eingabeIstRichtig = false;
    
    do {
        
            system("cls");
            cout << "Bitte waehlen der Kaffe die sie haben moechten und geben der Nr. ein: ";
            cin >> gewaehlt;

        if ( gewaehlt >= 10 && gewaehlt <= 15 ) {
            
            eingabeIstRichtig = true;
            system("cls");
        } else {
           
            cout << "*Falsche Eingabe, bitte pruefen sie richtig!" << endl;
            cout << endl;
            eingabeIstRichtig = false;
            
        }
        
    } while (eingabeIstRichtig == false);
    
    
}

void ablaufSection(vector<KaffeProdukt> &auswahlKollection, char &mitZucker, int &gewaehlt, bool &erfolg, float &zuckerPrise, float &payment) {
    
    
    float geldEingabe = 0.0;
    
    
        switch (gewaehlt) {
            case 10 : infoUndZahlungAnfondern(auswahlKollection, 0, mitZucker); break;
            case 11 : infoUndZahlungAnfondern(auswahlKollection, 1, mitZucker); break;
            case 12 : infoUndZahlungAnfondern(auswahlKollection, 2, mitZucker); break;
            case 13 : infoUndZahlungAnfondern(auswahlKollection, 3, mitZucker); break;
            case 14 : infoUndZahlungAnfondern(auswahlKollection, 4, mitZucker); break;
            case 15 : infoUndZahlungAnfondern(auswahlKollection, 5, mitZucker); break;
        };
    
    
    while ( erfolg == false ) {
        
        switch ( mitZucker) {
            case 'c' :
                system("cls");
                abbrechung();
                erfolg = true;
                break;
                
            case 'C' :
                system("cls");
                abbrechung();
                erfolg = true;
                break;
            case '0' :
                system("cls");
                muenzZahlungsProzessOhneZucker(auswahlKollection, elementeZumZeigen(gewaehlt), zuckerPrise, payment, geldEingabe);
                erfolg = true;
                break;
            case '1' :
                system("cls");
                muenzZahlungsProzessMitZucker(auswahlKollection, elementeZumZeigen(gewaehlt), zuckerPrise, payment, geldEingabe);
                erfolg = true;
                break;
                
                
            default:
                cout << "Falsche eingabe!!" << endl;
                eingabeZuckerOptionen(mitZucker);
                cout << endl;
                
                break;
        }
       
    } ;
    
    
    
}

void eingabeZuckerOptionen(char &mitZucker) {
    
    bool eingabeIstRichtig = false;
    
    do {
        cout << "---Moechten sie noch Zucker dazu fuer CHF 0.20 haben?\n---Ja, geben sie 1 ein, Nein, geben sie: 0 ein, oder geben sie 'c' zum Abbrechen ein: ";
        cin >> mitZucker;
        
        if ( mitZucker == '1' || mitZucker == '0' || mitZucker == 'c' || mitZucker == 'C' ) {
            
            eingabeIstRichtig = true;
            
        } else {
           
            cout << "*Falsche Eingabe, bitte pruefen sie richtig!" << endl;
            cout << endl;
            eingabeIstRichtig = false;
        }
        
    } while (eingabeIstRichtig == false);
}

int elementeZumZeigen(int &gewaehlt) {
    int vToReturn = 0;
    
    switch (gewaehlt) {
        case 10 : vToReturn = 0; break;
        case 11 : vToReturn = 1; break;
        case 12 : vToReturn = 2; break;
        case 13 : vToReturn = 3; break;
        case 14 : vToReturn = 4; break;
        case 15 : vToReturn = 5; break;
            
        default:
            break;
    }
    
    return vToReturn;
}

void infoUndZahlungAnfondern(vector<KaffeProdukt> &auswahlKollection, int item, char &mitZucker) {
    
    cout << "Sie haben: " << "*** " << auswahlKollection[item].name << " ***" << " gewaehlt!" << endl;
    cout << "---Kostet: CHF " << auswahlKollection[item].preis <<endl;
    eingabeZuckerOptionen(mitZucker);
    cout << endl;
    
}

void vorbereitundInfo() {
    cout << endl;
    cout << "Wir vorbereiten ihre Kaffe gerade..." << endl;
    cout << "Ihre Kaffe ist bereit, nehmen sie sie!" << endl;
}

void verabschiedung() {
    cout << endl;
    cout << "\tGenissen sie sie!!" << endl;
    cout << "\t *** _(°-°)_ ***" << endl;
}

void muenzZahlungsProzessMitZucker(vector<KaffeProdukt> &auswahlKollection, int item, float &zuckerPrise, float &payment, float &geldEingabe) {
    
    cout << "\t*** " << auswahlKollection[item].name << " mit Zucker ***" << endl;
    cout << "Kaffe Preis: CHF " << auswahlKollection[item].preis << ", Zucker Preis: CHF " << zuckerPrise << endl;
    cout << "Geben sie " << "CHF " << auswahlKollection[item].preis + zuckerPrise << " ein: ";
    cin >> payment;
    
    if (payment == (auswahlKollection[item].preis + zuckerPrise) ) {
        vorbereitundInfo();
        cout << "Rueckgeld: CHF " << "0.00" << endl;
        verabschiedung();
        
        
    } else if ( payment > (auswahlKollection[item].preis + zuckerPrise)) {
        vorbereitundInfo();
        cout << "Nehmen sie ihre Rueckgeld: CHF " << (payment - (auswahlKollection[item].preis + zuckerPrise)) << endl;
        verabschiedung();
        
    } else if (payment < (auswahlKollection[item].preis + zuckerPrise)) {
        
        float bezahlt = 0;
            //AQUI IMPLEMETAR FUNCION QUE CONTROLE EL GELDEINGABE, SI ES MUCHO DEVOLVER, SI ES POCO PEDIR...
        do {
            cout << "Bitte pruefen sie der Betrag noch mals, faehlen noch: CHF: " << (auswahlKollection[item].preis + zuckerPrise) - payment << endl;
            cout << "Fehlende Betrag eingeben: ";
            cin >> geldEingabe;
            cout << endl;
            bezahlt += geldEingabe;
            if ( (bezahlt + payment) == (auswahlKollection[item].preis + zuckerPrise) ) {
                vorbereitundInfo();
                cout << "Rueckgeld: CHF 0.00" << endl;
                verabschiedung();
                payment += bezahlt;
            } else if ( (bezahlt + payment) > (auswahlKollection[item].preis + zuckerPrise) ) {
                payment += bezahlt;
                vorbereitundInfo();
                cout << "Nehmen sie ihre Rueckgeld: CHF " << (payment - (auswahlKollection[item].preis + zuckerPrise)) << endl;
                verabschiedung();
            } else {
                payment += bezahlt;
            }
            
        } while ( payment < (auswahlKollection[item].preis + zuckerPrise));
  
    }
}



void muenzZahlungsProzessOhneZucker(vector<KaffeProdukt> &auswahlKollection, int item, float &zuckerPrise, float &payment, float &geldEingabe) {
    cout << "\t*** " << auswahlKollection[item].name << " ohne Zucker ***" << endl;
    cout << "Kaffe Preis: CHF " << auswahlKollection[item].preis << endl;
    cout << "Geben sie " << "CHF " << auswahlKollection[item].preis << " ein: ";
    cin >> payment;
    
    if (payment == auswahlKollection[item].preis ) {
        vorbereitundInfo();
        cout << "Rueckgeld: CHF " << "0.00" << endl;
        verabschiedung();
        
    } else if ( payment > (auswahlKollection[item].preis )) {
        vorbereitundInfo();
        cout << "Nehmen sie ihre Rueckgeld: CHF " << (payment - auswahlKollection[item].preis) << endl;
        verabschiedung();
        
    } else if (payment < auswahlKollection[item].preis) {
        
        float bezahlt = 0;
            //AQUI IMPLEMETAR FUNCION QUE CONTROLE EL GELDEINGABE, SI ES MUCHO DEVOLVER, SI ES POCO PEDIR...
        do {
            cout << "Bitte pruefen sie der Betrag noch mals, faehlen noch: CHF: " << auswahlKollection[item].preis - payment << endl;
            cout << "Fehlende Betrag eingeben: ";
            cin >> geldEingabe;
            cout << endl;
            bezahlt += geldEingabe;
            if ( (bezahlt + payment) == auswahlKollection[item].preis ) {
                vorbereitundInfo();
                cout << "Rueckgeld: CHF 0.00" << endl;
                verabschiedung();
                payment += bezahlt;
            } else if ( (bezahlt + payment) > auswahlKollection[item].preis ) {
                payment += bezahlt;
                vorbereitundInfo();
                cout << "Nehmen sie ihre Rueckgeld: CHF " << (payment - auswahlKollection[item].preis) << endl;
                verabschiedung();
            } else {
                payment += bezahlt;
            }
            
        } while ( payment < auswahlKollection[item].preis);
    }
}

void abbrechung() {
    cout << "Operation abgebrochen, danke und schoenen Tag!" << endl;
    linieLayout(); linieLayout(); linieLayout();
    cout << endl << endl;
}


string abstandGeber(string &toCheck, vector<KaffeProdukt> &produktKatallog) {
    
    unsigned long counter = 0;
    unsigned long value = 0;
    string vToReturn = "";
    
    for(int i = 0; i < produktKatallog.size(); i++) {
        if (produktKatallog[i].name.size() > counter) {
            counter = produktKatallog[i].name.length();
        }
    
    };
    
    
    value = counter -= toCheck.size();
    
    for(int i = 0; i < value; i++) {
        vToReturn.append(" ");
    };
    
    return vToReturn;
}


string abstandGeberPlus(int sizeElemento, int sizeToRich) {
    string vToReturn = "";
    
    for (int i = 0; i <= (sizeToRich - sizeElemento); i++) {
        vToReturn.append(" ");
    }
    return vToReturn;
}
