//Signalpin des Sensors
#define SIGNAL_PIN 2

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  long c = readQTR1RC();
  Serial.println(c);
}

long readQTR1RC()
{
    long c = 0;//Zählvariable

    //Kondensator entladen:
    
    //Pin als Ausgang nutzen
    pinMode(SIGNAL_PIN, OUTPUT);
    //und 5V anlegen
    digitalWrite(SIGNAL_PIN, HIGH);
    //abwarten, um den Kondensator zu entladen  
    delay(1);
    
    //Zeit messen, bis Kondensator 
    //vom Phototransistor geladen wurde:

    //Pin als Eingang nutzen
    pinMode(SIGNAL_PIN, INPUT);
    
    //und abwarten, solange 5V anliegen
    while(digitalRead(SIGNAL_PIN) == HIGH)
    {
        c++;
    }
    return c;
}

