int brzeczek = 4; //deklaracja portu do ktorego podlaczamy brzeczek
int przyciskS = 10; // port, do ktorego podlaczamy przycisk odpowiedzialny za start
int przyciskA = 9; //port, pod ktory podlaczamy przycisk odpowiadzi A
int przyciskB = 8; //port, pod ktory podlaczamy przycisk odpowiedzi B
int diodaG = 3; // port, pod ktory podlaczamy diode zielona
int diodaR = 2; // port, pod ktory podlaczamy diode czerowno
int wynik = 0; // zmienna odpowiedzialna za gromadzenie zdobytych punktów

/* INFO o REZYSTORACH w układzie
 *  Dla diod - rezystory 1 kilo ohm
 *  Dla przyciskow - rezystory 10 kilo ohm
 *  Dla brzeczka - rezystor 330 ohm
 */

void setup() {
  // put your setup code here, to run once:
  pinMode(brzeczek,OUTPUT); //zdefiniowanie portu 3 jako wyjscie  
  pinMode(przyciskS,INPUT); //przycisk jako sygnal wejsciowy
  pinMode(przyciskA,INPUT); //przycisk A jako wejscie
  pinMode(przyciskB, INPUT); //przyciks B rowniez jako wejscie
  pinMode(diodaG, OUTPUT); //zielona dioda jako wyjscie
  pinMode(diodaR, OUTPUT); //czerwona dioda jako wyjscie
  Serial.begin(9600); //odpalam nasluchiwanie z portu szeregowego

  //Opis konkursu
  Serial.println("Witamy w konkursie!");
    delay(5000);
    Serial.println("Autorem konkursu jest Łukasz");
    delay(3000);
    Serial.println("Zasady udzielania odpowiedzi");
    delay(3000);
    Serial.println("Po pojawieniu sie pytania musisz zaznaczyc odpowiedz A lub B i trzymac przycisk");
    delay(3000);
    Serial.println("Odpowiedz A to przycisk po lewej");
    delay(3000);
    Serial.println("Odpowiedz B to przycisk po prawej");
    delay(3000);
    Serial.println("Gdy udzielisz odpowiedzi poprawnej zapali sie zielona dioda");
    digitalWrite(diodaG, HIGH);
    delay(3000);
    digitalWrite(diodaG, LOW);
    Serial.println("W przypadku odpowiedzi złej zapali sie czerwona dioda i uslyszysz sygnal dzwiekowy");
    digitalWrite(diodaR, HIGH);
    digitalWrite(brzeczek, HIGH);
    delay(3000);
    digitalWrite(diodaR, LOW);
    digitalWrite(brzeczek, LOW);
    Serial.println("Aby rozpoczac konkurs nacisnij przycisk START");
    Serial.println("POWODZENIA!");
}

void loop() {
  if (digitalRead(przyciskS) == HIGH)
  {
    Serial.println("");
    Serial.println("");
    delay(3000);
    Serial.println("Pytanie 1");
    Serial.println("2 + 2 = ");
    delay(2000);
    Serial.println("A - 4 czy B - 6");
    Serial.println("5");
    delay(1000);
    Serial.println("4");
    delay(1000);
    Serial.println("3");
    delay(1000);
    Serial.println("2");
    delay(1000);
    Serial.println("1");
    delay(1000);
    Serial.println("0");
    
    if (digitalRead(przyciskA) == HIGH) // udzielenie poprawnej odpowiedzi
      {
      digitalWrite(diodaG,HIGH);
      Serial.println("Bardzo dobrze! To jest poprawna odpowiedz");
      delay(3000);
      digitalWrite(diodaG,LOW);
      wynik = wynik + 1;
      Serial.print("Twoj wynik to: ");
      Serial.println(wynik);
      Serial.println("");
      Serial.println("");
      delay(2000);
      }
    else if (digitalRead(przyciskB) == HIGH) // udzielenie błędnej odpowiedzi
    {
      digitalWrite(diodaR,HIGH);
      digitalWrite(brzeczek, HIGH);
      Serial.println("O nie! Udzieliles blednej odpowiedzi!");
      delay(3000);
      digitalWrite(diodaR,LOW);
      digitalWrite(brzeczek, LOW);
      Serial.println("");
      Serial.println("");
      Serial.println("GAME OVER");
    }
        else // nieudzielenie odpowiedzi
    {
      Serial.println("ZA POZNO NIE UDZIELILES POPRAWNEJ ODPOWIEDZI!");
      digitalWrite(diodaR,HIGH);
      digitalWrite(brzeczek, HIGH);
      delay(3000);
      digitalWrite(diodaR,LOW);
      digitalWrite(brzeczek, LOW);
      Serial.println("");
      Serial.println("");
      Serial.println("GAME OVER");
    }
    if (wynik ==1) //jezeli zdobylismy punkt to przechodzimy do drugiego pytania
    {
      Serial.println("Pytanie 2");
      Serial.println("9 - 5 = ");
      delay(2000);
      Serial.println("A - 5 czy B - 4");
      Serial.println("5");
      delay(1000);
      Serial.println("4");
      delay(1000);
      Serial.println("3");
      delay(1000);
      Serial.println("2");
      delay(1000);
      Serial.println("1");
      delay(1000);
      Serial.println("0");
        if (digitalRead(przyciskB) == HIGH) // udzielenie poprawnej odpowiedzi; zmieniłem kolejność
        {
        digitalWrite(diodaG,HIGH);
        Serial.println("Bardzo dobrze! To jest poprawna odpowiedz");
        delay(3000);
        digitalWrite(diodaG,LOW);
        wynik = wynik + 1; //podwyzszenie wyniku jezeli udzielilo sie poprawnej odpowiedzi
        Serial.print("Twoj wynik to: ");
        Serial.println(wynik);
        delay(2000);
        Serial.println("");
        Serial.println("");
        }
        else if (digitalRead(przyciskA) == HIGH) // udzielenie błędnej odpowiedzi
        {
        digitalWrite(diodaR,HIGH);
        digitalWrite(brzeczek, HIGH);
        Serial.println("O nie! Udzieliles blednej odpowiedzi!");
        delay(3000);
        digitalWrite(diodaR,LOW);
        digitalWrite(brzeczek, LOW);
        Serial.println("");
        Serial.println("");
        Serial.print("Udalo Ci sie zdobyc tyle punktow: ");
        Serial.println(wynik);
        Serial.println("GAME OVER");
        }
        else
        {
        Serial.println("ZA POZNO NIE UDZIELILES POPRAWNEJ ODPOWIEDZI!");
        digitalWrite(diodaR,HIGH);
        digitalWrite(brzeczek, HIGH);
        delay(3000);
        digitalWrite(diodaR,LOW);
        digitalWrite(brzeczek, LOW);
        Serial.println("");
        Serial.println("");
        Serial.println("Zdobyles tyle punktów: ");
        Serial.println(wynik);
        Serial.println("GAME OVER");
        }
    }
    if (wynik ==2) //jeżeli zdobyliśmy kolejny punkt to przechodzimy do trzeciego pytania
    {
      Serial.println("Pytanie 3");
      Serial.println("Ile razy zamrugala dioda zielona?");
      delay(3000);
      Serial.println("Skup sie i patrz na diody!");
      delay(3000);
      for (int j = 0; j<5; j++)
      {
        digitalWrite(diodaG, HIGH);
        delay(100);
        digitalWrite(diodaG, LOW);
        j=j;
        delay(100);
      }
      Serial.println("A - 4 czy B - 5");
      Serial.println("5");
      delay(1000);
      Serial.println("4");
      delay(1000);
      Serial.println("3");
      delay(1000);
      Serial.println("2");
      delay(1000);
      Serial.println("1");
      delay(1000);
      Serial.println("0");
        if (digitalRead(przyciskA) == HIGH) // udzielenie poprawnej odpowiedzi
        {
        digitalWrite(diodaG,HIGH);
        Serial.println("Bardzo dobrze! To jest poprawna odpowiedz");
        delay(3000);
        digitalWrite(diodaG,LOW);
        wynik = wynik + 1; //podwyzszenie wyniku jezeli udzielilo sie poprawnej odpowiedzi
        Serial.print("Twoj wynik to");
        Serial.println(wynik);
        delay(2000);
        }
        else if (digitalRead(przyciskB) == HIGH) // udzielenie błędnej odpowiedzi
        {
        digitalWrite(diodaR,HIGH);
        digitalWrite(brzeczek, HIGH);
        Serial.println("O nie! Udzieliles blednej odpowiedzi!");
        delay(3000);
        digitalWrite(diodaR,LOW);
        digitalWrite(brzeczek, LOW);
        Serial.println("");
        Serial.println("");
        Serial.print("Udalo Ci sie zdobyc tyle punktow: ");
        Serial.println(wynik);
        Serial.println("GAME OVER");
        }
        else //nie udzielenie odpowiedzi w ogole
        {
        Serial.println("ZA POZNO NIE UDZIELILES POPRAWNEJ ODPOWIEDZI!");
        digitalWrite(diodaR,HIGH);
        digitalWrite(brzeczek, HIGH);
        delay(3000);
        digitalWrite(diodaR,LOW);
        digitalWrite(brzeczek, LOW);
        Serial.println("");
        Serial.println("");
        Serial.print("Zdobyles tyle punktów: ");
        Serial.println(wynik);
        Serial.println("GAME OVER");
        }
    }
    if (wynik == 3)
    {
      Serial.println("BRAWO UDZIELILES POPRAWNEJ ODPOWIEDZI NA WSZYSTKIE PYTANIA!");
      Serial.println("");
      Serial.println("");
      Serial.println("");
      Serial.println("");
      Serial.print("Tyle punktow zdobyles: ");
      Serial.println(wynik);
      Serial.println("GAME OVER");
    }
  }
}
