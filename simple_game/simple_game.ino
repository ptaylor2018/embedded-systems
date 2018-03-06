int correctValue =0;
int acceptableRange = 50;
int turnLimit = 350;
boolean unlockable = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
  correctValue =  random(50, 900);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  int lockpickValue = analogRead(1);
  int wrenchValue = analogRead(3); //unbent 300, 130 all  the way back 
  int tempValue = correctValue - lockpickValue;
  int correctnessValue = abs(tempValue);
  if(correctnessValue <= acceptableRange){
    turnLimit = 130;
    unlockable = true;
  } else {
    int howOff = correctnessValue - acceptableRange;
    turnLimit = map(howOff, 1, 900, 150, 300);
  }
  if(wrenchValue < turnLimit){
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }
  Serial.print(lockpickValue);
  Serial.print("\r\n");
}
