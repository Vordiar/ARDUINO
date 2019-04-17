//Program zostal napisany dla diody o wspolnej anodzie; dla wspolnej katody nalezy zamienic podlaczenie nozki do masy zamiast do napiecia
//przy wspolnej katodzie nalezy rowniez zamienic 255 na 0
//moja dioda (nozki od lewej) -> czerwony, wspolna anoda, niebieski, zielony

const int czerwony = 11;
const int zielony = 6;
const int niebieski = 3; //podpiecie stykow paska LED pod piny PWM
const int przycisk = 2; // pin podpiecia przycisku, przerwanie pod 2; pozwala na zmiane koloru swiecenia
int potencjometr = A0; //Pin podpiecia potencjometru; podlaczam pod ANALOG IN A0
int potencjometr2 = A1; //Drugi potencjometr podpinam pod ANALOG IN A1

int stanPrzycisku = 0; //* ZMIENNA POMOCNICZA
int poprzedniStan = 0;
int aktualnyPomiar = 0; 
double skala;
double skala2;
double napiecie; 
int i = 0; //ZMIENNA POMOCNICZA */


void setup() {
pinMode(czerwony, OUTPUT);  
pinMode(zielony, OUTPUT);
pinMode(niebieski, OUTPUT);
pinMode(potencjometr, INPUT);
pinMode(przycisk, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(przycisk), zmianakoloru, CHANGE);
Serial.begin(9600);
}

void loop() {
  if (aktualnyPomiar == 0)
  {
    red();
  }
  else if (aktualnyPomiar == 1)
  {
    green();
  }
  else if (aktualnyPomiar == 2)
  {
    blue();
  }
  else if (aktualnyPomiar == 3)
  {
    white();
  }
  else if (aktualnyPomiar == 4)
  {
    mrugacz();
  }
  else if (aktualnyPomiar > 4)
  {
    aktualnyPomiar = 0;
  }
 }

void zmianakoloru() {
  stanPrzycisku = digitalRead(przycisk);
  if (stanPrzycisku != poprzedniStan)
  {
    if (stanPrzycisku == HIGH) 
    {
      aktualnyPomiar++;
    }
    delay(50);
  }
  poprzedniStan = stanPrzycisku;
}

void red()
{
  skala = analogRead(potencjometr)/4;
  napiecie = 5 - skala / 51;
  analogWrite (czerwony, skala);
  analogWrite (zielony, 255);
  analogWrite (niebieski, 255);
  Serial.print("Napiecie zasilania diody czerwonej [V] = ");
  Serial.println(napiecie);

}

void green()
{
  skala = analogRead(potencjometr) /4;
  napiecie = 5 - skala / 51;
  analogWrite (czerwony, 255);
  analogWrite (zielony, skala);
  analogWrite (niebieski, 255);
  Serial.print("Napiecie zasilania diody zielonej [V] = ");
  Serial.println(napiecie);
}

void blue()
{
  skala = analogRead(potencjometr) /4;
  napiecie = 5 - skala / 51;
  analogWrite (czerwony, 255);
  analogWrite (zielony, 255);
  analogWrite (niebieski, skala);
  Serial.print("Napiecie zasilania diody niebieskiej [V] = ");
  Serial.println(napiecie);
}

void white()
{
  skala = analogRead(potencjometr) /4;
  napiecie = 5 - skala / 51;
  analogWrite (czerwony, skala);
  analogWrite (zielony, skala);
  analogWrite (niebieski, skala);
  Serial.print("Napiecie zasilania diody bialej [V] = ");
  Serial.println(napiecie);
}

void mrugacz()
{
  skala = analogRead(potencjometr);
  skala2 = analogRead(potencjometr2) / 4;
  napiecie = skala * skala2; //nie chcialem dodawac nowej zmiennej skoro mam juz taka w pamieci
  Serial.print("Odstep wynosi [ms] = ");
  Serial.println(napiecie);
  Serial.print("Wartosc potencjometru 1 = ");
  Serial.println(skala);
  Serial.print("Wartosc potencjometru 2 = ");
  Serial.println(skala2);
  analogWrite (czerwony, 0);
  analogWrite (zielony, 255);
  analogWrite (niebieski, 255);
  delay(napiecie); //na ten moment czestotliwosc mrugania zalezy od wychylenia potencjometrow, mozna jednak z tego zrezygnowac i wpisac na sztywno wartosc (w milisekundach) w nawiasie
  analogWrite (czerwony, 255);
  delay(napiecie);
}
