#include <LiquidCrystal.h>
#define NOTE_REST 0

LiquidCrystal lcd(9, 8, 7, 6, 5, 4);

int iniciarDesistir = 0;
int iniciar = 0;
int nivel = 0;
int jaFoi[24] = {-1, -1, -1, -1, -1, -1, -1, -1,
                -1, -1, -1, -1, -1, -1, -1, -1,
                -1, -1, -1, -1, -1, -1 -1, -1};
int botaoDesistir = 0;
int contAcertosGeral = 0;
int contPulo = 0;
int score = 0;

const char* questoes[24] = { "2+3 = 6?", "2^4 = 16?",
                         "2*2 = 4?", "2^3 = 6?",
                         "4-2 = 2?", "1+2+3 = 6?",
                            "7+7 = 15?", "24/3 = 6?",
                           "2-9 = -7?", "7*8 = 56?",
                          "5*2+10 = 100?", "5*2*10/10 = 10?",
                          "81/9+81 = 100-10?", "2^0 = 0?",
                            "2*5-9 = -1?", "2^3-2 = 4?",
                           "2*2+3*2 = 24?", "5/5*3/3 = 1?",
                           "6/6*6 = 6?", "4*5/5*4 = 1?",
                           "8*7/7*14/7 = 16?", "2^0+2*2 = 4?",
                           "5^2*4-50 = 50?", "4^4+4-10 = 10?"};
const char* resultados[24] = { "nao", "sim", "sim", "nao",
                              "sim", "sim", "nao", "nao",
                            "sim", "sim", "nao", "sim",
                              "sim", "nao", "nao", "nao",
                             "nao", "sim", "sim", "nao",
                              "sim", "nao", "sim", "nao"};

void botaoIniciarDesistir(){
  if(iniciarDesistir == 0){
    iniciar = 1;
    iniciarDesistir = 1;
  }else{
    botaoDesistir = 1;
    iniciarDesistir = 0;
  }
}

//void botaoPular(){
  
//}

void play(int min, int max){
  lcd.setCursor(0, 0);
  lcd.print("Nivel: " + String(nivel));
  delay(2000);
  lcd.clear();
  for(int i = 3; i > 0; i--){
    lcd.setCursor(0, 0);
    lcd.print(String(i));
    delay(1000);
    lcd.clear();
  }
  int numero;
  int contAcertos = 0;
  int botaoSim = digitalRead(11);
  int botaoNao = digitalRead(10);
  int botaoPular = digitalRead(3);
  while(contAcertos < 5 && botaoDesistir != 1){
    numero = random(min, max);
    if(numero != jaFoi[numero]){
      lcd.setCursor(0, 0);
      lcd.print(questoes[numero]);
      lcd.setCursor(0, 1);
      lcd.print("sim ou nao?");
      for(int i = 0; i < 24; i++){
        botaoSim = digitalRead(11);
        botaoNao = digitalRead(10);
        botaoPular = digitalRead(3);
        delay(250);
        if(botaoSim == 0 || botaoNao == 0 || botaoPular == 0 || botaoDesistir == 1){
          break;
        }
        if(i >= 12 && i < 14 || i >= 16 && i < 18 || i >= 20 && i < 22){
          digitalWrite(13, HIGH);
        }else if(i >= 14 && i < 16 || i >= 18 && i < 20 || i >= 22){
          digitalWrite(13, LOW);
        }
      }
      digitalWrite(13, LOW);
      lcd.clear();
      if(botaoSim == 0){
        if(strcmp(resultados[numero], "sim") == 0){
          if(nivel == 1){
            score++;
          }else if(nivel == 2){
            score = score + 2;
          }else if(nivel == 3){
            score = score + 3;
          }
          lcd.setCursor(0, 0);
          lcd.print("Boa!");
          lcd.setCursor(0, 1);
          lcd.print("Score: " + String(score));
          jaFoi[numero] = numero;
          contAcertosGeral++;
          contAcertos++;
          somAcertou();
          delay(2000);
        }else{
          lcd.setCursor(0, 0);
          lcd.print("Errou!");
          somErrou();
          delay(2000);
          return;
        }
      }else if(botaoNao == 0){
        if(strcmp(resultados[numero], "nao") == 0){
          if(nivel == 1){
            score++;
          }else if(nivel == 2){
            score = score + 2;
          }else if(nivel == 3){
            score = score + 3;
          }
          lcd.setCursor(0, 0);
          lcd.print("Boa!");
          lcd.setCursor(0, 1);
          lcd.print("Score: " + String(score));
          jaFoi[numero] = numero;
          contAcertosGeral++;
          contAcertos++;
          somAcertou();
          delay(2000);
        }else{
          lcd.setCursor(0, 0);
          lcd.print("Errou!");
          somErrou();
          delay(2000);
          return;
        }
      }else if(botaoPular == 0){
        contPulo++;
        if(contPulo > 3){
          lcd.setCursor(0, 0);
          lcd.print("Chega!");
          somErrou();
          delay(2000);
          return;
        }else{
          jaFoi[numero] = numero;
          lcd.setCursor(0, 0);
          lcd.print("Pulos: " + String(contPulo));
          lcd.setCursor(0, 1);
          lcd.print("Restam: " + String(3 - contPulo));
          somPulou();
          delay(2000);
        }
      }else if(botaoDesistir == 1){
        return;
      }else{
        lcd.setCursor(0, 0);
        lcd.print("Perdeu tentativa");
        delay(2000);
        lcd.clear();
        contPulo++;
        if(contPulo > 3){
          lcd.setCursor(0, 0);
          lcd.print("Chega!");
          somErrou();
          delay(2000);
          return;
        }else{
          jaFoi[numero] = numero;
          lcd.setCursor(0, 0);
          lcd.print("Pulos: " + String(contPulo));
          lcd.setCursor(0, 1);
          lcd.print("Restam: " + String(3 - contPulo));
          somPulou();
          delay(2000);
        }
      }
      lcd.clear();
    }
  }
}

void perguntaFinal(){
  lcd.setCursor(0, 0);
  lcd.print("Pergunta final!");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("4*0+(4+4)/4+8/8 = 4?");
  lcd.setCursor(0, 1);
  lcd.print("sim ou nao?");
  delay(250);
  int botaoSim = digitalRead(11);
  int botaoNao = digitalRead(10);
  int botaoPular = digitalRead(3);
  for(int i = 0; i < 72; i++){
    botaoSim = digitalRead(11);
    botaoNao = digitalRead(10);
    botaoPular = digitalRead(3);
    delay(250);
    if(botaoSim == 0 || botaoNao == 0 || botaoPular == 0 || botaoDesistir == 1){
      break;
    }
    if(i >= 60 && i < 62 || i >= 64 && i < 66 || i >= 68 && i < 70){
      digitalWrite(13, HIGH);
    }else if(i >= 62 && i < 64 || i >= 66 && i < 68 || i >= 70){
      digitalWrite(13, LOW);
    }
    lcd.scrollDisplayLeft();
  }
  digitalWrite(13, LOW);
  lcd.clear();
  if(botaoSim == 0){
    lcd.setCursor(0, 0);
    lcd.print("Errou!");
    somErrou();
    delay(2000);
    return;
  }else if(botaoNao == 0){
    score = score + 20;
    lcd.setCursor(0, 0);
    lcd.print("Venceuuuuuu!");
    lcd.setCursor(0, 1);
    lcd.print("Score: " + String(score));
    contAcertosGeral++;
    somVenceu();
    delay(2000);
  }else if(botaoPular == 0){
    lcd.setCursor(0, 0);
    lcd.print("Serio?!");
    somErrou();
    delay(2000);
    return;
  }else{
    lcd.setCursor(0, 0);
    lcd.print("Demorou...");
    somErrou();
    delay(2000);
    return;
  }
  lcd.clear();
}

void verificacaoNoob(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Noob!");
  somDesistiu();
  delay(2000);
  lcd.clear();
  botaoDesistir = 0;
}

void verificacaoBoa(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Boaaaaaa!");
  lcd.setCursor(0, 1);
  lcd.print("Nivel: " + String(nivel) + " OK!");
  delay(2000);
  lcd.clear();
  nivel++;
}

void playNote(int noteFrequency, int noteDuration) {
  if (noteFrequency == NOTE_REST) {
    delay(noteDuration);
  } 
  else {
    tone(12, noteFrequency, noteDuration);
    delay(noteDuration + 200);
  }
}

void somAcertou(){
  tone(12, 666, 500);
  delay(500);
  noTone(12);
}

void somErrou(){
  tone(12, 400, 150);
  delay(200);
  tone(12, 300, 150);
  delay(200);
  tone(12, 200, 150);
  delay(200);
}

void somPulou(){
  tone(12, 262, 500); // C4
  delay(250);
  tone(12, 196, 500); // G3
  delay(250);
  tone(12, 220, 500); // A3
  delay(250);
  tone(12, 196, 500); // G3
  delay(250);
  tone(12, 220, 500); // A3
  delay(250);
}

void somDesistiu(){
  playNote(330, 500);
  playNote(392, 500);
  playNote(440, 500);
  playNote(330, 500);
  playNote(294, 500);
  playNote(262, 500);
  playNote(294, 500);
}

void somVenceu(){
  playNote(880, 250);
  playNote(784, 250);
  playNote(659, 250);
  playNote(698, 250);
  playNote(784, 250);
  playNote(659, 250);
  playNote(698, 250);
  playNote(659, 250);
  playNote(784, 250);
  playNote(880, 250);
  playNote(784, 250);
  playNote(698, 250);
  playNote(659, 250);
  playNote(698, 250);
  playNote(784, 250);
  playNote(880, 250);
  playNote(784, 500);
}

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  //attachInterrupt(digitalPinToInterrupt(3), botaoPular, FALLING);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), botaoIniciarDesistir, FALLING);
  lcd.begin(16, 2);
  randomSeed(analogRead(0));
}

void loop() {
  if(iniciar == 1){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Game ON!");
    delay(2000);
    lcd.clear();
    nivel = 1;
    play(0, 8);
    if(botaoDesistir == 1){
      verificacaoNoob();
    }else if(contAcertosGeral >= 5){
      verificacaoBoa();
      play(8, 16);
      if(botaoDesistir == 1){
      	verificacaoNoob();
      }else if(contAcertosGeral >= 10){
      	verificacaoBoa();
      	play(16, 24);
        if(botaoDesistir == 1){
          verificacaoNoob();
      	}else if(contAcertosGeral >= 15){
          verificacaoBoa();
          perguntaFinal();
      	}
      }
    }
    lcd.clear();
    iniciar = 0;
  	nivel = 0;
    iniciarDesistir = 0;
    contAcertosGeral = 0;
    contPulo = 0;
    score = 0;
    for(int i = 0; i < 24; i++){
      jaFoi[i] = -1;
    }
  }
}
