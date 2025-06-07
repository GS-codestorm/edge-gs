// === BIBLIOTECAS NECESSÁRIAS ===
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include "HX711.h"

// === DEFINIÇÃO DE PINOS ===
#define DHTPIN 2
#define DHTTYPE DHT22
#define verde 12
#define vermelho 13
#define BUZZER 9
#define DT 4
#define SCK 5

// === OBJETOS DOS COMPONENTES ===
DHT_Unified dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
HX711 balanca;

// === VARIÁVEIS DE CONFIGURAÇÃO E CONTROLE ===
float peso_conhecido = 2.5;
float fator_calibracao = -7050.0;
int leituraContador = 0;
float somaTemp = 0, somaUmid = 0;

// === CONFIGURAÇÃO DO COLETOR DE ÁGUA ===
float diametro_cm = 20.0;
float limite_chuva_mm = 25.0;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(verde, OUTPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Calibrando...");

  balanca.begin(DT, SCK);
  Serial.println("Remova qualquer peso da balança...");
  delay(5000);
  balanca.set_scale();
  balanca.tare();
  Serial.println("Balança zerada.");

  Serial.println("Coloque o peso conhecido (2.5kg)...");
  delay(10000);
  float leitura = balanca.get_units(10);
  fator_calibracao = leitura / peso_conhecido;
  balanca.set_scale(fator_calibracao);

  Serial.print("Fator de calibracao: ");
  Serial.println(fator_calibracao);
  Serial.println("-------------------------");

  lcd.clear();
  lcd.print("Sistema Iniciado");
  delay(2000);
}

void loop() {
  sensors_event_t tempEvent, umidEvent;
  dht.temperature().getEvent(&tempEvent);
  dht.humidity().getEvent(&umidEvent);

  float temp = tempEvent.temperature;
  float umid = umidEvent.relative_humidity;

  if (!isnan(temp) && !isnan(umid)) {
    somaTemp += temp;
    somaUmid += umid;
    leituraContador++;

    Serial.println("Leitura feita");
    Serial.print(leituraContador);
    Serial.println("° Contagem");
    Serial.print("Temp: ");
    Serial.println(temp);
    Serial.print("Umid: ");
    Serial.println(umid);
  } else {
    Serial.println("Erro ao ler sensor DHT.");
    return;
  }

  if (leituraContador >= 5) {
    float tempMedia = somaTemp / leituraContador;
    float umidMedia = somaUmid / leituraContador;
    float pesoLido = balanca.get_units(10);

    float raio_m = (diametro_cm / 100.0) / 2.0;
    float area_m2 = 3.1416 * raio_m * raio_m;
    float chuva_mm = pesoLido / area_m2;

    Serial.println("==== MÉDIAS CALCULADAS ====");
    Serial.print("Temp Média: ");
    Serial.println(tempMedia);
    Serial.print("Umid Média: ");
    Serial.println(umidMedia);
    Serial.print("Peso Lido: ");
    Serial.print(pesoLido);
    Serial.println(" kg");
    Serial.print("Precipitacao: ");
    Serial.print(chuva_mm);
    Serial.println(" mm");
    Serial.println("-------------------------");

    leituraContador = 0;
    somaTemp = somaUmid = 0;

    bool tempOK = (tempMedia >= 18 && tempMedia <= 30);
    bool umidOK = (umidMedia >= 40 && umidMedia <= 70);
    bool chuvaOK = (chuva_mm < limite_chuva_mm);

    digitalWrite(verde, LOW);
    digitalWrite(vermelho, LOW);
    noTone(BUZZER);

    if (tempOK && umidOK && chuvaOK) {
      digitalWrite(verde, HIGH);
    } else {
      digitalWrite(vermelho, HIGH);
    }

    // === TEMPERATURA ===
    lcd.clear();
    lcd.setCursor(0, 0);
    if (tempMedia > 30) {
      tone(BUZZER, 1000);
      lcd.print("Temp. Alta");
    } else if (tempMedia < 18) {
      tone(BUZZER, 1000);
      lcd.print("Temp. Baixa");
    } else {
      lcd.print("Temp. OK");
    }
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(tempMedia, 1);
    lcd.print(" C");
    delay(1500);
    noTone(BUZZER);

    // === UMIDADE ===
    lcd.clear();
    lcd.setCursor(0, 0);
    if (umidMedia < 40) {
      tone(BUZZER, 1000);
      lcd.print("Solo seco");
    } else if (umidMedia > 70) {
      tone(BUZZER, 1000);
      lcd.print("Solo umido");
    } else {
      lcd.print("Solo bom");
    }
    lcd.setCursor(0, 1);
    lcd.print("Umid: ");
    lcd.print(umidMedia, 1);
    lcd.print(" %");
    delay(1500);
    noTone(BUZZER);

    // === PRECIPITAÇÃO ===
    lcd.clear();
    lcd.setCursor(0, 0);
    if (chuva_mm >= limite_chuva_mm) {
      tone(BUZZER, 2000);
      lcd.print("Risco Enchente!");
    } else {
      lcd.print("Chuva OK");
    }
    lcd.setCursor(0, 1);
    lcd.print("Chuva: ");
    lcd.print(chuva_mm, 1);
    lcd.print(" mm");
    delay(1500);
    noTone(BUZZER);
  }

  delay(1000);
}
