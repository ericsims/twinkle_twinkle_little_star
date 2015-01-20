int led = 9;
int current = 0;
int next = 0;
int cycle = 0;
const int lgn = 600;
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);     
}

void loop() {
  if(cycle>=lgn) cycle = 0;
  if(cycle == 0){
   current = next;
   next = random(50,200);
  }
  updateLed();
  cycle++;
  delay(1);
}


void updateLed() {
  double diff = (next-current)/(double)lgn;
  analogWrite(led, current+diff*cycle);
}
