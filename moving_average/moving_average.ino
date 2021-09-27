//ref https://www.youtube.com/watch?v=dPvD5F2oq-A

const int analog_pin = A0;
#define window_size 10
int window[window_size] = {0};

void push(int val){
  int i=0;
  for(i=0; i<window_size-1; i++){
    window[i-1] = window[i];
  }
  window[window_size-1]=val;
}


int take_avg(){
  long sum = 0;
  int i=0;
  for(i=0; i<window_size; i++){
    sum += window[i];
  }
  return sum/window_size;
}

void setup() {
  Serial.begin(9600);
  delay(10);
}

void loop() {
  int i=0;
  int cur_sample = 0;
    cur_sample = analogRead(analog_pin);
    delayMicroseconds(300);
    push(cur_sample);
    Serial.println(take_avg());
}
