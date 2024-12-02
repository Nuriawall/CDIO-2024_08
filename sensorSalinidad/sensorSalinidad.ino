#define power_pin 5 // Pin para alimentar el sensor de salinidad

void setup() {
  pinMode(power_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int16_t adc0;
  float salinidad;
  
  // Alimentamos la sonda con un tren de pulsos
  digitalWrite(power_pin, HIGH);
  delay(100);

  // leemos cuando hay un nivel alto
  adc0 = analogRead(A0);
  digitalWrite(power_pin, LOW);
  delay(100);

  // Realizamos el cálculo de la salinidad
  int x[6] = {1, 765, 5, 818, 20, 857}; //grams-digital reading
  int Ai0 = 1;
  int Bi0 = x[3]+x[5];
  int Ci0 = x[3]*x[5];
  int den0 = (x[1]-x[3])*(x[1]-x[5]);
  int Ai1 = 1;
  int Bi1 = x[1]+x[5];
  int Ci1 = x[1]*x[5];
  int den1 = (x[3]-x[1])*(x[3]-x[5]);
  int Ai2 = 1;
  int Bi2 = x[1]+x[3];
  int Ci2 = x[1]*x[3];
  int den2 = (x[5]-x[1])*(x[5]-x[3]);
  salinidad = (x[0]*(Ai0*adc0^2-Bi0*adc0+Ci0)/den0)+(x[2]*(Ai1*adc0^2-Bi1*adc0+Ci1)/den1)+(x[4]*(Ai2*adc0^2-Bi2*adc0+Ci2)/den2); // Ajustar rango de mapeo

  // presentamos lectura
  Serial.print("Lectura digital = ");
  Serial.println(adc0, DEC);
  Serial.print("Salinidad = ");
  Serial.println(salinidad, 2); // Ajusta el número de decimales según tus necesidades
  delay(1000); // Puedes ajustar el tiempo de espera entre lecturas
}
