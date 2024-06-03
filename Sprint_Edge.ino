#include <DHT.h>
#include <LiquidCrystal.h>

// Define os pinos dos sensores e componentes
#define PINO_DHT 2  // Pino do sensor DHT11
#define TIPO_DHT DHT11
#define PINO_POTENCIOMETRO A0  // Pino do potenciômetro
#define PINO_TRIGGER 12 // Pino do sensor de proximidade HC-SR04
#define PINO_ECHO 11 // Pino do sensor de proximidade HC-SR04
#define PINO_BUZINA 8  // Pino da buzina
#define PINO_VERMELHO 10 // Pino do LED vermelho
#define PINO_VERDE 9 // Pino do LED verde
#define PINO_AZUL 6 // Pino do LED azul
#define LCD_RS 12  // Pino RS do display LCD
#define LCD_EN 11  // Pino EN do display LCD
#define LCD_D4 5   // Pino D4 do display LCD
#define LCD_D5 4   // Pino D5 do display LCD
#define LCD_D6 3   // Pino D6 do display LCD
#define LCD_D7 2   // Pino D7 do display LCD

// Define os limites críticos dos sensores
#define TEMPERATURA_MAX 30 // Limite máximo de temperatura (Celsius)
#define TEMPERATURA_MIN 10 // Limite mínimo de temperatura (Celsius)
#define UMIDADE_MAX 80 // Limite máximo de umidade (%)
#define UMIDADE_MIN 40 // Limite mínimo de umidade (%)
#define PH_MAX 8.5 // Limite máximo de pH
#define PH_MIN 7.5 // Limite mínimo de pH
#define DISTANCIA_MAX 50 // Limite máximo de distância (cm)

// Cria um objeto DHT para o sensor DHT11
DHT dht(PINO_DHT, TIPO_DHT);
// Cria um objeto LiquidCrystal para o display LCD
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

void setup() {
  // Inicializa o serial para comunicação com o computador
  Serial.begin(9600);
  // Inicializa o sensor DHT11
  dht.begin();
  // Inicializa o display LCD
  lcd.begin(16, 2);
  // Inicializa os pinos do LED RGB e da buzina
  pinMode(PINO_VERMELHO, OUTPUT);
  pinMode(PINO_VERDE, OUTPUT);
  pinMode(PINO_AZUL, OUTPUT);
  pinMode(PINO_BUZINA, OUTPUT);
}

void loop() {
  // Lê os dados dos sensores
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();
  float ph = obterValorPH();
  int distancia = obterDistancia();

  // Exibe os dados no display LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatura);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(umidade);
  lcd.print("%");

  // Verifica os níveis críticos dos sensores
  verificarLimites(temperatura, umidade, ph, distancia);

  // Aguarda 1 segundo antes de atualizar os dados
  delay(1000);
}

float obterValorPH() {
  // Lê o valor do potenciômetro e converte para unidades de pH
  int valorSensor = analogRead(PINO_POTENCIOMETRO);
  float valorPH = map(valorSensor, 0, 1023, PH_MIN, PH_MAX);
  return valorPH;
}

int obterDistancia() {
  // Lê a distância do sensor de proximidade
  digitalWrite(PINO_TRIGGER, LOW); 
  delayMicroseconds(2);
  digitalWrite(PINO_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PINO_TRIGGER, LOW);

  long duracao = pulseIn(PINO_ECHO, HIGH);
  int distancia = duracao * 0.034 / 2;
  return distancia;
}

void verificarLimites(float temperatura, float umidade, float ph, int distancia) {
  // Verifica os limites da temperatura
  if (temperatura > TEMPERATURA_MAX) {
    // Alerta de temperatura alta
    digitalWrite(PINO_VERMELHO, HIGH);
    digitalWrite(PINO_VERDE, LOW);
    digitalWrite(PINO_AZUL, LOW);
    tone(PINO_BUZINA, 440);
  } else if (temperatura < TEMPERATURA_MIN) {
    // Alerta de temperatura baixa
    digitalWrite(PINO_VERMELHO, LOW);
    digitalWrite(PINO_VERDE, LOW);
    digitalWrite(PINO_AZUL, HIGH);
    tone(PINO_BUZINA, 440);
  } else {
    // Temperatura dentro dos limites
    digitalWrite(PINO_VERMELHO, LOW);
    digitalWrite(PINO_VERDE, HIGH);
    digitalWrite(PINO_AZUL, LOW);
    noTone(PINO_BUZINA);
  }

  // Verifica os limites da umidade
  if (umidade > UMIDADE_MAX) {
    // Alerta de umidade alta
    digitalWrite(PINO_VERMELHO, HIGH);
    digitalWrite(PINO_VERDE, LOW);
    digitalWrite(PINO_AZUL, LOW);
    tone(PINO_BUZINA, 440);
  } else if (umidade < UMIDADE_MIN) {
    // Alerta de umidade baixa
    digitalWrite(PINO_VERMELHO, LOW);
    digitalWrite(PINO_VERDE, LOW);
    digitalWrite(PINO_AZUL, HIGH);
    tone(PINO_BUZINA, 440);
  } else {
    // Umidade dentro dos limites
    digitalWrite(PINO_VERMELHO, LOW);
    digitalWrite(PINO_VERDE, HIGH);
    digitalWrite(PINO_AZUL, LOW);
    noTone(PINO_BUZINA);
  }

  // Verifica os limites do pH
  if (ph > PH_MAX || ph < PH_MIN) {
    // Alerta de pH fora dos limites
    digitalWrite(PINO_VERMELHO, HIGH);
    digitalWrite(PINO_VERDE, LOW);
    digitalWrite(PINO_AZUL, LOW);
    tone(PINO_BUZINA, 440);
  } else {
    // pH dentro dos limites
    digitalWrite(PINO_VERMELHO, LOW);
    digitalWrite(PINO_VERDE, HIGH);
    digitalWrite(PINO_AZUL, LOW);
    noTone(PINO_BUZINA);
  }

  // Verifica os limites da distância
  if (distancia < DISTANCIA_MAX) {
    // Alerta de proximidade
    digitalWrite(PINO_VERMELHO, HIGH);
    digitalWrite(PINO_VERDE, LOW);
    digitalWrite(PINO_AZUL, LOW);
    tone(PINO_BUZINA, 440);
  } else {
    // Distância dentro dos limites
    digitalWrite(PINO_VERMELHO, LOW);
    digitalWrite(PINO_VERDE, HIGH);
    digitalWrite(PINO_AZUL, LOW);
    noTone(PINO_BUZINA);
  }
}
