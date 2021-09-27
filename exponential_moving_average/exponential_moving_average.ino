//ref https://www.youtube.com/watch?v=r1PSSjDa7Eo

/*
 Exponential: moving average
 last previous avg
 alpha: 0-1
 IIR 
 AVG[n] = ((NEW_SAMPLE*ALPHA) + AVG[n-1] * (1-ALPHA));
  
 */

const int analog_pin = A0;

const float alpha = 0.1;
double lastAvg = 0.0;

void setup() {
  Serial.begin(9600);
  delay(10);
}

void loop() {
  int i=0;
  int cur_sample = 0;
  double cur_avg = 0.0;
  //cur_sample = analogRead(analog_pin);
  cur_sample = random(0,9);
  cur_avg = (cur_sample*alpha) + ((lastAvg)*(1-alpha));
  Serial.print(cur_avg);
  Serial.print(",");
  Serial.println(cur_sample);
  lastAvg = cur_avg;
  //delayMicroseconds(300);
  delay(500);
}
