void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int temp = analogRead(A0);
  analogWrite(6,map(temp,0, 1023, 0, 255)); 
 Serial.println(temp);
  
}
