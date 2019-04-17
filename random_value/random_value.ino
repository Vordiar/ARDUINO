long randNumber;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
    for (int i=0;i<1;i++)
  {
  Serial.print("Jaki masz dzisiaj humor? ");
  randNumber=random(1,5);
  if (randNumber==1) {Serial.println("Wesoly");}
  if (randNumber==2) {Serial.println("Zly");}
  if (randNumber==3) {Serial.println("Zadowolony");}
  if (randNumber==4) {Serial.println("Zmeczony");}
  if (randNumber==5) {Serial.println("Lepiej nie podchodz");}
  delay(10000);
  }
}
