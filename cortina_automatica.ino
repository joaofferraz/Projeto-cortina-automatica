int abrir = 0;
int fechar = 0;
int parar = 0;
int sensor = 0;
int fc_aberta = 0;
int fc_fechada = 0;
int transistor = 0;

void setup()
{
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  abrir = digitalRead(2);
  parar = digitalRead(3);
  fechar = digitalRead(4);
  fc_aberta = digitalRead(5);
  fc_fechada = digitalRead(6);
  sensor = digitalRead(7);
  transistor = digitalRead(8);
  if (sensor == LOW) {
    if (fc_aberta == LOW && fc_fechada == LOW) {
      if (abrir == HIGH) {
        digitalWrite(12, HIGH);
        while (!(fc_aberta == HIGH || parar == HIGH)) {
          fc_aberta = digitalRead(5);
          parar = digitalRead(3);
        }
        digitalWrite(12, LOW);
      }
      if (fechar == HIGH) {
        digitalWrite(13, HIGH);
        while (!(fc_fechada == HIGH || parar == HIGH)) {
          fc_fechada = digitalRead(6);
          parar = digitalRead(3);
        }
        digitalWrite(13, LOW);
      }
    }
    if (fc_aberta == HIGH && fc_fechada == LOW) {
      if (fechar == HIGH) {
        digitalWrite(13, HIGH);
        while (!(fc_fechada == HIGH || parar == HIGH)) {
          fc_fechada = digitalRead(6);
          parar = digitalRead(3);
        }
        digitalWrite(13, LOW);
      }
    }
    if (fc_fechada == HIGH && fc_aberta == LOW) {
      if (abrir == HIGH) {
        digitalWrite(12, HIGH);
        while (!(fc_aberta == HIGH || parar == HIGH)) {
          fc_aberta = digitalRead(5);
          parar = digitalRead(3);
        }
        digitalWrite(12, LOW);
      }
    }
  }
  if (sensor == HIGH) {
    if (transistor == HIGH && fc_aberta == LOW) {
      digitalWrite(12, HIGH);
      while (!(fc_aberta == HIGH)) {
        fc_aberta = digitalRead(5);
      }
      digitalWrite(12, LOW);
    }
    if (transistor == LOW && fc_fechada == LOW) {
      digitalWrite(13, HIGH);
      while (!(fc_fechada == HIGH)) {
        fc_fechada = digitalRead(6);
      }
      digitalWrite(13, LOW);
    }
  }
  delay(10); // Delay a little bit to improve simulation performance
}
