double tiempo;
double wave;

double sinMin;
double sinMax;

double freqMin;
double freqMax;
double output;

void setup()
{
  //inicializamos el led
  bool flag = 0;  
  pinMode(13, OUTPUT);
  wave =0;
  sinMin = -1;
  sinMax  = 1;
  freqMin = 1.0/100.0;
  freqMax = 1.0/1000.0;
  Serial.begin(6900);
 
}

void loop()
{
  double time = getTickTime();
  digitalWrite(13,HIGH);
  delay(time);
  digitalWrite(13,LOW);
  delay(time);
}

double getTickTime() {
   
  double input = sin(0.2*wave++); 
  //Serial.println((String)"esto es el seno: " + input);
  double slope = 1.0 * (freqMin - freqMax) / (sinMax - sinMin);
  output = freqMax + slope * (input - sinMin);
  double tickTime = 1./output;
  //Serial.println((String)"esto es el tiempo de delay: " + tickTime);
  return tickTime;
}