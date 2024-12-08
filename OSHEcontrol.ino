#define pulse_ip 32 // Signal in pin
int outHigh = 33; // Output led pin# at full throttle
int outMid = 25; // Output led pin# at no throttle
int outLow = 26; // Output led pin# at full break
// Variable declaration
int ontime, offtime, dutyNew;
float freq, period, dutyOut, dutyAvg;

void setup()
{
  // Declares input or output for each pin
  pinMode(pulse_ip,INPUT);
  pinMode(outHigh,OUTPUT);
  pinMode(outMid,OUTPUT);
  pinMode(outLow,OUTPUT);
  // Sets serial
  Serial.begin(9600);
}
void loop()
{

  ontime = pulseIn(pulse_ip,HIGH); // Collects ontime from reciever
  offtime = pulseIn(pulse_ip,LOW); // Collects offtime from reciever
  period = ontime + offtime; // Calculates signal period
  freq =   1000000.0 / period; // Calculates signal frequency
  dutyNew = (ontime / period) * 100; // Calculates signal duty cycle
  dutyAvg = dutyNew; // Initilizes dutyAvg
  dutyOut = 0; // Initilizes dutyOut

  // Loops 10 times to create a good average of duty cycles
  for (int i = 0; i < 9; i++ ) {
  ontime = pulseIn(pulse_ip,HIGH); // Collects ontime from reciever
  offtime = pulseIn(pulse_ip,LOW); // Collects offtime from reciever
  period = ontime + offtime; // Calculates signal period
  freq =   1000000.0 / period; // Calculates signal frequency
  dutyNew = (ontime / period) * 100; // Calculates signal duty cycle
  dutyAvg = (dutyAvg + dutyNew) / 2; // Calculates the average of the two duty cycles
  }

    dutyOut = dutyAvg; // Sets duty out

  // Checks the value of duty out and turns on the corresponding LED
  if (dutyOut == 11){ 
    digitalWrite(outHigh, HIGH);
    digitalWrite(outMid, LOW);
    digitalWrite(outLow, LOW);
  }
  if else (dutyOut <= 8.4 && dutyOut >= 8.1){
    digitalWrite(outHigh, LOW);
    digitalWrite(outMid, HIGH);
    digitalWrite(outLow, LOW);

  }
    if else (dutyOut <= 5.5 && dutyOut >= 5){
    digitalWrite(outHigh, LOW);
    digitalWrite(outMid, LOW);
    digitalWrite(outLow, HIGH);

  }


}