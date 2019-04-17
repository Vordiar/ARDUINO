//Kod do pozytywki
//Założenia: Odpala się muzyka + LCD -->  Rusza silnik --> Rusza pomiar temperatury i wilgotnosci --> Wynik pomiarow wyswietla sie na LCD
//Silnik podlaczyc do PWM by regulowac rozpedzanie sie silnika

//Sekcja muzyczna
#include "pitches.h" // podpiecie biblioteki z muzyka
const int Glosnik = 5; // pin, pod ktory podepniemy glosnik; buzzer tone
//melodia, ktora ma odtworzyc
int melody[] = {
  NOTE_C4, NOTE_G4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, 0, NOTE_C5, NOTE_G5, NOTE_C6, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_D5, NOTE_D5,
  NOTE_G4, NOTE_C4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_C4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_D4, NOTE_G4, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_C5, 
  NOTE_D5, NOTE_D4, NOTE_G4, NOTE_D4, NOTE_G4, NOTE_C5, NOTE_A4, NOTE_D5, NOTE_G5, NOTE_C5, NOTE_F4, NOTE_B4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_B4, NOTE_C5,
  NOTE_D5, NOTE_C5, NOTE_G4, NOTE_C5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_G5, NOTE_F5, NOTE_E5,
  NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_F4, NOTE_C2, NOTE_D2, NOTE_C4, NOTE_D2, NOTE_C2, NOTE_D2, NOTE_B1, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_D2, 
  NOTE_C4, NOTE_A1, NOTE_F4, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B5, NOTE_A5,
  NOTE_A5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_D5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_E5, NOTE_F5, NOTE_G5,
  NOTE_A5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_A5, NOTE_B5, NOTE_C6, NOTE_D6, NOTE_B5, NOTE_C6, NOTE_D6, NOTE_D5, NOTE_D5
};

// czas trawania kazdego tonu; dla mnie - cala nuta - 1, polnuta - 2, cwiercnuta - 4, osemka - 8, szesnastka - 16 itd.
int noteDurations[] = {
  2,3,8,3,16,16,4,4,4,1,4,4,3,8,3,16,16,4,4,1,1,2,2,2,3,16,16,4,4,4,3,32,32,4,4,4,4,2,3,16,16,1,8,8,8,8,8,8,8,8,2,2,2,3,32,32,4,4,4,3,32,32,4,4,4,4,2,3,16,16,1,3,16,16,4,4,4,1,4,3,16,16,4,4,4,
  8,4,16,16,4,4,4,3,16,16,4,4,4,3,16,16,4,4,4,3,16,16,4,4,4,3,16,16,2,2,2,3,16,16,2,1,3,16,16,2,4,4,4,4,4,4,16,16,16,16,16,16,61,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
  16,16,16,16,16,1,1
};

int MelodiaGOT[] = {
  NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4, 
  NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_C4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4,
  NOTE_D4, NOTE_G2, NOTE_B2, NOTE_C4, NOTE_D4, NOTE_G2, NOTE_B2, NOTE_C4, NOTE_D4, NOTE_G2, NOTE_B2, NOTE_C2, NOTE_D4, NOTE_G2, NOTE_B2, NOTE_F4, NOTE_B2, NOTE_E4, NOTE_D4, NOTE_F4,
  NOTE_B2, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_F2, NOTE_A2, NOTE_B2, NOTE_C4, NOTE_F2, NOTE_A2, NOTE_B2, NOTE_C4, NOTE_F2, NOTE_A2, NOTE_B2, NOTE_C4, NOTE_F2, NOTE_A2, NOTE_G4, NOTE_C4, 
  NOTE_C4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_D4, NOTE_G2, NOTE_B2, NOTE_C4, NOTE_D4, NOTE_G2, NOTE_B2, NOTE_C4, NOTE_D4, NOTE_G2, NOTE_B2, NOTE_C2, NOTE_D4, NOTE_G2, 
  NOTE_B2, NOTE_F4, NOTE_B2, NOTE_E4, NOTE_D4, NOTE_F4, NOTE_B2, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_G2, NOTE_A2, NOTE_B2, NOTE_C4, NOTE_G2, NOTE_A2, NOTE_B2, NOTE_C4, NOTE_G2, NOTE_A2,
  NOTE_B2, NOTE_C4, NOTE_G4, NOTE_C4
};

int TempoGOT[] = {
  4,4,8,8,4,4,4,4,4,4,8,8,4,4,8,8,4,4,8,8,4,4,8,8,4,4,8,8,4,4,8,8,1,1,8,8,2,2,8,8,4,4,8,8,4,4,8,8,4,4,8,8,4,4,4,1,1,8,8,2,2,8,8,4,4,8,8,4,4,8,8,4,4,8,8,4,3,3,1,1,8,8,2,2,8,8,4,4,
  8,8,4,4,8,8,4,4,8,8,4,4,4
};


//Sekcja LCD -> używam rezystora 220 ohm
#include <LiquidCrystal.h> //biblioteka LCD
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8; //Gdzie podlaczamy piny
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Sekcja silnika
const int Silnik = 6; //Pamietac by silnik podlaczyc do pinu PWM

//Sekcja temperatury --> Uzywam rezystora 4,7 k ohm
#include "dht.h"
#define dhtPin 7 //podlaczenie pinu Temperatury, nie musi byc PWM
dht DHT;

void setup() {
  for (int Nuta = 0; Nuta < 124; Nuta++) {
  int CzasNuty = 1000 / TempoGOT[Nuta];
  tone(Glosnik, MelodiaGOT[Nuta], CzasNuty); //
  int Przerwa = CzasNuty * 1.40; //przerwa miedzy nutami, pierwotny autor zalecal 1.3
  delay(Przerwa);
  noTone(Glosnik);
  }
  pinMode(Silnik, OUTPUT); //Zdefiniowanie silnika jako wyjscie
  lcd.begin(16,2); //zainicjowanie wyswietlacza lcd 16x2
  lcd.setCursor(5,0);
  lcd.print("Witaj"); // ta wiadomosc wyswietli sie w gornej linijce od lewej.
  lcd.setCursor(2, 1);
  lcd.print("Podrozniku!"); // Ta wiadomosc wyswietli sie w drugiej linijce od lewej.
  delay(1500); // czekaj 1,5 sekundy
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Czas wrocic do");
  lcd.setCursor(4,1);
  lcd.print("PRZYSZLOSCI!");
  delay(1500);
  //petla muzyczna na start
  for (int thisNote = 0; thisNote < 159; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(Glosnik, melody[thisNote], noteDuration); //
    int pauseBetweenNotes = noteDuration * 1.40; //przerwa miedzy nutami, pierwotny autor zalecal 1.3
    delay(pauseBetweenNotes);
    noTone(Glosnik);
    if (thisNote == 10)
    {
    digitalWrite(Silnik,64); //silnik zasilony w 25%
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Przyspieszasz!"); // ta wiadomosc wyswietli sie w gornej linijce od lewej.
    lcd.setCursor(0, 1);
    lcd.print("Predkosc 20 MPH!"); // Ta wiadomosc wyswietli sie w drugiej linijce od lewej. 
    }
    if (thisNote == 28)
    {
    digitalWrite(Silnik,127); //silnik zasilony w 50%
    lcd.setCursor(0, 1);
    lcd.print("Predkosc 44 MPH!"); // Ta wiadomosc wyswietli sie w drugiej linijce od lewej.
    }
    if (thisNote == 51)
    {
    digitalWrite(Silnik,255); //silnik zasilony w 100%
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Udalo sie!"); // ta wiadomosc wyswietli sie w gornej linijce od lewej.
    lcd.setCursor(0, 1);
    lcd.print("Predkosc 88 MPH!"); // Ta wiadomosc wyswietli sie w drugiej linijce od lewej.
    }
    if (thisNote == 70)
    {
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("Skok udany!");
    lcd.setCursor(2,1);
    lcd.print("Parametry OK");
    }
    if (thisNote == 100)
    {
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Rozpocznij");
    lcd.setCursor(4,1);
    lcd.print("Pomiary!");
    delay(1000);
    }
  }
}

void loop() {
  int chk = DHT.read11(dhtPin);
  digitalWrite(Silnik,0);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp. silnika:");
  lcd.setCursor(0,1);
  lcd.print("T = " + String(DHT.temperature) + "C");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Woda w Mr.Fusion");
  lcd.setCursor(0,1);
  lcd.print("H = " + String(DHT.humidity) + "%");
  delay(1000);

  /*for (int Nuta = 0; Nuta < 124; Nuta++) {
  int CzasNuty = 1000 / TempoGOT[Nuta];
  tone(Glosnik, MelodiaGOT[Nuta], CzasNuty); //
  int Przerwa = CzasNuty * 1.40; //przerwa miedzy nutami, pierwotny autor zalecal 1.3
  delay(Przerwa);
  noTone(Glosnik);
  }*/
}
