/*
 * Predict next state
 * x(t) = F*x(t-1) + B*u
 * Predict next covariance
 * P(t) = F*P(t-1) * Ft + Q
 * Compute the Kalman gain
 * K = P(t) * HT / (H * P(t) * Ht + R)
 * Update the state estimate
 * X(t) = x(t)+K * (measurement(t) * H * x(t))
 * Update covariance estimation
 * P(t) = (I - K * H) * P(t)
 * 
 * x(t) = [sensor output voltage]
 * F = 1
 * B = 0
 * H = 1
 * Q = 1e9
 */

const int sensorPin = A0;

//Kalman variables
float varVolt = 1;
float varProcess = 1e-9;
float Pc = 0.0;
float G = 0.0;
float P = 1.0l;
float Xp = 0.0;
float Zp = 0.0;
float Xe = 0.0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  int sensorVal = analogRead(sensorPin);  // read value Analog pin 0
  float voltage = sensorVal * 5.0 / 1023.0; //convert ADC reading to voltage

  // Kalman process
  Pc = P + varProcess;
  G = Pc/(Pc+varVolt);  // Kalman gain
  P = (1-G)*Pc;
  Xp = Xe;
  Zp = Xp;
  Xe = G*(voltage-Zp)+Xp; // kalman estimate of sensor voltage

  Serial.print(voltage);
  Serial.print(',');
  Serial.print(Xe);
  Serial.print(',');
  Serial.println();
  delay(20);
}
