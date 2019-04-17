int Dioda1 = 2; //definiuje po kolei kazda diode by potem wykorzystac to w petli do gaszenia i zapalania diod
int Dioda2 = 3;
int Dioda3 = 4;
int Dioda4 = 5;
int Dioda5 = 6;
int Dioda6 = 7;


void setup() {
  // put your setup code here, to run once:
  pinMode(Dioda1,OUTPUT); //definiuje diody jako wyjscia z ukladu
  pinMode(Dioda2,OUTPUT);
  pinMode(Dioda3,OUTPUT);
  pinMode(Dioda4,OUTPUT);
  pinMode(Dioda5,OUTPUT);
  pinMode(Dioda6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 2; i<=7; i++) //forward loop
  {
    digitalWrite(i,HIGH);
    delay(100);
    digitalWrite(i,LOW);
  }

  for (int j =6; j>2; j--) //backward loop
  {
    digitalWrite(j,HIGH);
    delay(100);
    digitalWrite(j,LOW);
  }

}
