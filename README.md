# EDGE COMPUTING GLOBAL SOLUTION

🔅 Sistema de Monitoramento de Precipitação, Umidade e Temperatura

## ♦ Descrição do Projeto

O aumento do nível de enchentes em áreas urbanas pode causar sérios transtornos e riscos à população. Pensando nisso, este sistema foi desenvolvido para monitorar de forma automática o acúmulo de água em determinado local. A solução utiliza uma balança (célula de carga com módulo HX711) para medir o peso da água acumulada durante períodos de chuva. Quando a precipitação ultrapassa um limite pré-definido, o sistema acende um LED vermelho e ativa um buzzer, alertando para risco iminente de enchente. Se o nível estiver abaixo desse limite, um LED verde permanece ligado, indicando situação segura. O objetivo é fornecer um alerta rápido e confiável, permitindo ação preventiva e maior segurança para todos. Além disso, o sistema monitora a umidade e temperatura do ambiente utilizando um sensor DHT22 e exibe informações em um display LCD.

## ♦ Funcionalidade

•
O sistema utiliza uma célula de carga e um módulo HX711 para medir o peso da água acumulada.

•
Com base no peso da água, um sistema de alarme visual e sonoro é acionado:

•
LED verde: precipitação abaixo do limite de alerta (OK).

•
LED vermelho: precipitação acima do limite de alerta (risco de enchente).

•
Buzzer: ativado quando a precipitação atinge o nível de alerta.



•
O sistema utiliza um sensor DHT22 para capturar dados de temperatura e umidade do ambiente.

•
As informações de temperatura, umidade e status da precipitação são exibidas em um display LCD 16x2 I2C.

•
Mensagens no LCD podem incluir: "Precip. OK", "Risco Enchente", "Temp: XX.X C", "Umidade: XX.X %", entre outras.



## ♦ Dependências

Este projeto utiliza os seguintes componentes e bibliotecas:

 •
 Arduino Uno ou qualquer outro modelo de Arduino compatível.

 •
 Célula de Carga (Load Cell) para medição de peso.

 •
 Módulo HX711 (Load Cell Amplifier) para interface com a célula de carga.

 •
 Sensor DHT22 para medição de temperatura e umidade.

 •
 Display LCD 16x2 I2C para exibição de informações.

 •
 LEDs (verde e vermelho) para sinalização do status da precipitação.

 •
 Buzzer para alerta sonoro.

 •
 Resistores (para LEDs e pull-up do DHT22).

 •
 Biblioteca Arduino IDE para programação e upload do código no Arduino.

 •
 HX711 Library para interface com o módulo HX711.

 •
 DHT sensor library para leitura dos dados de temperatura e umidade do sensor DHT22.

 •
 LiquidCrystal I2C para simplificar a comunicação com o display LCD I2C.

## ♦ Como Reproduzir o Projeto

 1. Materiais Necessários:

 - 1x Arduino Uno

 - 1x Protoboard

 - 20x Jumpers

 - 1x Célula de Carga (Load Cell)

 - 1x Módulo HX711 (Load Cell Amplifier)

 - 1x Sensor DHT22

 - 1x Display LCD 16x2 I2C

 - 2x LEDs (verde e vermelho)

 - 1x Buzzer

 - 2x Resistor de 220Ω (para LEDs)

 - 1x Resistor de 10kΩ (para pull-up do DHT22)

 ## 2. Montagem do Circuito:

1. Conecte o barramento positivo da protoboard ao 5V do Arduino.

2. Conecte o barramento negativo da protoboard ao GND do Arduino.

3. Conecte o LED vermelho no pino digital 8 do Arduino (conforme imagem).

4. Conecte o LED verde no pino digital 9 do Arduino (conforme imagem).

5. Coloque um resistor de 220Ω entre o terminal positivo de cada LED e o fio que vai para o pino do Arduino.

6. Ligue o terminal positivo do buzzer no pino digital 10 do Arduino (conforme imagem) e o terminal negativo no GND.

7. Conexão do Módulo HX711 e Célula de Carga:

  - Conecte o pino VCC do HX711 ao 5V do Arduino.

  - Conecte o pino GND do HX711 ao GND do Arduino.

  - Conecte o pino DT do HX711 ao pino digital 3 do Arduino.

  - Conecte o pino SCK do HX711 ao pino digital 2 do Arduino.

  - Conecte a célula de carga ao módulo HX711 (geralmente, fios vermelho ao E+, preto ao E-, branco ao A- e verde ao A+).



 8.Conexão do Display LCD 16x2 I2C:

 - Conecte o pino VCC do módulo I2C do display LCD ao 5V do Arduino.

 - Conecte o pino GND do módulo I2C ao GND do Arduino.

 - Conecte o pino SDA do módulo I2C ao pino analógico A4 do Arduino.

 - Conecte o pino SCL do módulo I2C ao pino analógico A5 do Arduino.



 9.Conexão do Sensor DHT22:

 - Conecte o pino VCC do sensor DHT22 ao 5V do Arduino.

 - Conecte o pino GND do sensor DHT22 ao GND do Arduino.

 - Conecte o pino de sinal (DATA) do DHT22 ao pino digital 7 do Arduino.

 - Coloque um resistor de 10kΩ entre o pino de sinal do DHT22 e o 5V (pull-up).



10.Verifique se todas as conexões estão firmes e corretas.

11.Conecte o Arduino ao computador via cabo USB para alimentar o circuito e realizar o upload do código.

## 3. Como Rodar o Código:

- 1.Conecte o Arduino ao computador e abra a IDE do Arduino.

- 2.Selecione o modelo correto do Arduino na IDE e a porta COM.

- 3.Instale as bibliotecas necessárias para o funcionamento do programa (HX711 Library, DHT sensor library, LiquidCrystal I2C).

- 4.Insira o código para a IDE e faça o upload para o seu Arduino.

- 5.Observe o comportamento dos LEDs, do buzzer e do display LCD conforme a precipitação, temperatura e umidade medidas pelos sensores.

## ♦ Representação do projeto

<img 
    align="center" 
    alt="Sistema de Monitoramento" 
    title="Sistema de Monitoramento"
    width="600px" 
    style="padding-right: 10px;" 
    src="https://github.com/user-attachments/assets/dbd6f326-8da8-4152-88ba-b9afe8631b0f"
/>


## Nome Integrantes e RM

Guilherme de Araújo Moreira - RM: 561848

Camila de Mendonça da Silva - RM: 565491

Yan Breno Barutti Conceição - RM: 566412

### 💻 Tecnologias utilizadas

<img 
    align="left" 
    alt="C++"
    title="C++" 
    width="30px" 
    style="padding-right: 10px;" 
    src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/cplusplus/cplusplus-original.svg" 
/>
<img 
    align="left" 
    alt="ARDUINO IDE" 
    title="ARDUINO IDE"
    width="30px" 
    style="padding-right: 10px;" 
    src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/arduino/arduino-original-wordmark.svg" 
/>
<img 
    align="left" 
    alt="GIT" 
    title="GIT"
    width="30px" 
    style="padding-right: 10px;" 
    src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/git/git-original.svg" 
/>
<img 
    align="left" 
    alt="GITHUB" 
    title="GITHUB"
    width="30px" 
    style="padding-right: 10px;" 
    src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/github/github-original-wordmark.svg" 
/>

<br>

## ♦ Links do projeto:

- 🔗 **[Simulação no Wokwi](https://wokwi.com/projects/432296481161447425)**
- 🎥 **[Vídeo explicativo](https://youtu.be/xGguRr7WC-M)**
