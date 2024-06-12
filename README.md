# Jogo Display

> Status do projeto: Finalizado

### Tópicos

## Descrição do Projeto

## Funcionalidade

## Linguagens, Dependências e libs

## Desenvolvedores

## INTRODUÇÃO

 Nesse projeto nos foi proposto fazer um jogo de perguntas e respostas, onde elas aparecem em um display e o usuário aperta os botões de "sim" ou "não" para responder as perguntas. Além disso, o jogo emite sons em diversas situações.

 O jogo deveria possuir 3 níveis de perguntas, ou seja, fácil, médio e difícil e o jogador deverá acertar 5 perguntas de cada nível. Mas, para ganhar o jogo precisaria acertar uma pergunta final.

 O jogo utiliza 5 sons diferentes para 5 situações diferentes. Os casos são: quando acerta a questão, pula a questão, errou a questão, desistiu do jogo e venceu o jogo.
 
## METODOLOGIA

 Os materiais que utilizamos foi:
- Arduino UNO
- 1 LED vermelho
- 4 botões
- Buzzer
- Display LCD 16x2
- Placa de ensaio
- 2 resistores
- 1 potenciômetro

 Com os materiais que iriamos utilizar em mente e com as perguntas feitas, dessa forma, começamos a desenvolver o projeto. Assim, fizemos o circuito no tinkercad, em seguida, desenvolvemos o código para realizar todas as funções do jogo e por último montamos o circuito no dia de sua entrega na aula.

## Código Comentado

```javascript
#include <LiquidCrystal.h>
#define NOTE_REST 0

// Definindo os pinos para o Display.
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);

// Definindo algumas variaveis que vamos usar no programa. 
//(maioria das variaveis como contadores e variaveis de controle).
int iniciarDesistir = 0;
int iniciar = 0;
int nivel = 0;
// Array para indentificar as questoes que ja foram tanto no caso de
//acerto quanto no caso de pulo.
int jaFoi[24] = {-1, -1, -1, -1, -1, -1, -1, -1,
                -1, -1, -1, -1, -1, -1, -1, -1,
                -1, -1, -1, -1, -1, -1 -1, -1};
int botaoDesistir = 0;
int contAcertosGeral = 0;
int contPulo = 0;
int score = 0;

// Arrays com as perguntas e as respostas do programa.
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

// Funcao de interrupcao para iniciar ou desistir.
void botaoIniciarDesistir(){
  if(iniciarDesistir == 0){
    iniciar = 1;
    iniciarDesistir = 1;
  }else{
    botaoDesistir = 1;
    iniciarDesistir = 0;
  }
}

// Funcao para rodar o jogo, recebendo o intervalo do nivel especifico.
void play(int min, int max){
  lcd.setCursor(0, 0);
  lcd.print("Nivel: " + String(nivel));
  delay(2000);
  lcd.clear();
  // Laço para contar 3 seg antes do inicio dos niveis.
  for(int i = 3; i > 0; i--){
    lcd.setCursor(0, 0);
    lcd.print(String(i));
    delay(1000);
    lcd.clear();
  }
  // Definindo algumas variaveis, incluse que recebem o estado dos botoes.
  int numero;
  int contAcertos = 0;
  int botaoSim = digitalRead(11);
  int botaoNao = digitalRead(10);
  int botaoPular = digitalRead(3);
  // Laço para rodar as perguntas e verificar as respostas, ou certas
  //condicoes do jogo.
  while(contAcertos < 5 && botaoDesistir != 1){
    // Variavel que recebe um numero aleatorio de acorodo com o intervalo
    //do nivel especifico.
    numero = random(min, max);
    // Verificando se o numero sorteado ja foi usado.
    if(numero != jaFoi[numero]){
      lcd.setCursor(0, 0);
      lcd.print(questoes[numero]);
      lcd.setCursor(0, 1);
      lcd.print("sim ou nao?");
      // Laço para verificar os estados dos botoes enquanto a pergunta
      //esta sendo reproduzida.
      for(int i = 0; i < 24; i++){
        botaoSim = digitalRead(11);
        botaoNao = digitalRead(10);
        botaoPular = digitalRead(3);
        delay(250);
        if(botaoSim == 0 || botaoNao == 0 || botaoPular == 0 || botaoDesistir == 1){
          break;
        }
        // Estrutura conticional para piscar o led quando o tempo esta acabando.
        if(i >= 12 && i < 14 || i >= 16 && i < 18 || i >= 20 && i < 22){
          digitalWrite(13, HIGH);
        }else if(i >= 14 && i < 16 || i >= 18 && i < 20 || i >= 22){
          digitalWrite(13, LOW);
        }
      }
      digitalWrite(13, LOW);
      lcd.clear();
      // Estrutura condicional caso o botao do "sim" seja apertado.
      if(botaoSim == 0){
        // Caso que a resposta esteja certa.
        if(strcmp(resultados[numero], "sim") == 0){
          // Condicional para decidir os pontos com base do nivel.
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
          // Caso que a resposta esteja errada.
        }else{
          lcd.setCursor(0, 0);
          lcd.print("Errou!");
          somErrou();
          delay(2000);
          return;
        }
        // Estrutura condicional caso o botao do "nao" seja apertado.
      }else if(botaoNao == 0){
        // Caso que a resposta esteja certa.
        if(strcmp(resultados[numero], "nao") == 0){
          // Condicional para decidir os pontos com base do nivel.
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
          // Caso que a resposta esteja errada.
        }else{
          lcd.setCursor(0, 0);
          lcd.print("Errou!");
          somErrou();
          delay(2000);
          return;
        }
        // Estrutura condicional caso o botao do "pular" seja apertado.
      }else if(botaoPular == 0){
        contPulo++
          // Verificando a quantidade de pulos, caso > 3 perde.
        if(contPulo > 3){
          lcd.setCursor(0, 0);
          lcd.print("Chega!");
          somErrou();
          delay(2000);
          return;
          // Caso não, atualizando a quantidade de pulos.
        }else{
          jaFoi[numero] = numero;
          lcd.setCursor(0, 0);
          lcd.print("Pulos: " + String(contPulo));
          lcd.setCursor(0, 1);
          lcd.print("Restam: " + String(3 - contPulo));
          somPulou();
          delay(2000);
        }
        // Estrutura condicional caso o botao do "desistir" seja apertado.
      }else if(botaoDesistir == 1){
        return;
        // Else para o caso do usuario nao apertar nada e o tempo acabar.
      }else{
        lcd.setCursor(0, 0);
        lcd.print("Perdeu tentativa");
        delay(2000);
        lcd.clear();
        contPulo++;
        // Atualizando os pulos do mesmo jeito que se tivesse pulado a questão.
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

// Funcao para a pergunta final.
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
  // Tempo maior para pergunta final já que ela é maior.
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
    // Funcao para rodar o display, já que a pergunta é muito grande.
    lcd.scrollDisplayLeft();
  }
  digitalWrite(13, LOW);
  lcd.clear();
  // Verificando os botoes ou a perca do tempo do mesmo jeito que a funcao play
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

// Funcao auxiliar caso o usuario desista.
void verificacaoNoob(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Noob!");
  somDesistiu();
  delay(2000);
  lcd.clear();
  botaoDesistir = 0;
}

// Funcao auxiliar caso o usuario complete um nivel.
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

// Funcao de controle de tempo e frequencia para algumas musicas.
void playNote(int noteFrequency, int noteDuration) {
  if (noteFrequency == NOTE_REST) {
    delay(noteDuration);
  } 
  else {
    tone(12, noteFrequency, noteDuration);
    delay(noteDuration + 200);
  }
}

// Som caso o usuario acerte a questao.
void somAcertou(){
  tone(12, 666, 500);
  delay(500);
  noTone(12);
}

// Som caso o usuario erre a questao.
void somErrou(){
  tone(12, 400, 150);
  delay(200);
  tone(12, 300, 150);
  delay(200);
  tone(12, 200, 150);
  delay(200);
}

// Som caso o usuario pule a questao.
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

// Som caso o usuario desista do jogo.
void somDesistiu(){
  playNote(330, 500);
  playNote(392, 500);
  playNote(440, 500);
  playNote(330, 500);
  playNote(294, 500);
  playNote(262, 500);
  playNote(294, 500);
}

// Musiquinha da vitoria.
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

// Declarando as entradas e saidas do arduino.
void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  // Declarando chamada para funcao de interrupcao.
  attachInterrupt(digitalPinToInterrupt(2), botaoIniciarDesistir, FALLING);
  lcd.begin(16, 2);
  randomSeed(analogRead(0));
}

void loop() {
  // Iniciar jogo.
  if(iniciar == 1){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Game ON!");
    delay(2000);
    lcd.clear();
    nivel = 1;
    // Intervalo para nivel facil.
    play(0, 8);
    // Verificacoes de conclusao ou desistencia do nivel.
    if(botaoDesistir == 1){
      verificacaoNoob();
    }else if(contAcertosGeral >= 5){
      verificacaoBoa();
      // Intervalo para nivel medio.
      play(8, 16);
      // Verificacoes de conclusao ou desistencia do nivel.
      if(botaoDesistir == 1){
      	verificacaoNoob();
      }else if(contAcertosGeral >= 10){
      	verificacaoBoa();
        // Intervalo para nivel dificil.
      	play(16, 24);
        // Verificacoes de conclusao ou desistencia do nivel.
        if(botaoDesistir == 1){
          verificacaoNoob();
      	}else if(contAcertosGeral >= 15){
          verificacaoBoa();
          // Chamando funcao da pergunta final.
          perguntaFinal();
      	}
      }
    }
    // Resetando variaveis caso comecem outro jogo.
    lcd.clear();
    iniciar = 0;
  	nivel = 0;
    iniciarDesistir = 0;
    contAcertosGeral = 0;
    contPulo = 0;
    score = 0;
    // Resetando array "jaFoi" caso comecem outro jogo.
    for(int i = 0; i < 24; i++){
      jaFoi[i] = -1;
    }
  }
}
```

Circuito que montamos no Tinkercad

![Circuito Tinkercad](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/ceec4e8e-82c0-47da-bf58-ef968e7b7ce5)

Circuito montado na aula

![Circuito montado na aula](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/104e619f-c209-40fc-8598-2e0f96620624)

## EXPERIMENTOS

 O jogo possui 4 botões, inclusive, um deles quando apertamos inícia o jogo. E aparece uma frase no display e o jogo começa a rodar.

![Iniciando o jogo](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/11f4bff3-5913-44e1-9e97-1c6a3d78c1b7)

Em seguida, o jogo começa a rodar perguntas do nível 1, a saber, que o jogo possui três níveis, ou seja, fácil, médio e díficil. Por isso, o usuário começa a responder as perguntas do nível 1 que seria o fácil e após ele responder e acertar 5 questões desse nível ele sobre o nível.

![Tela de níveis](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/ee49d95d-3e8c-4e69-aebe-7393da3c6b57)

A proxíma tela já começa a mostrar as perguntas, em suma, aparece a pergunta e o usuário tem um tempo para responder "sim" ou "não". Porventura, o usuário demorar para responder o LED vermelho vai começar a piscar e se o usuário não responder no tempo certo pula a pergunta e ele perde 1 pulo.

![Tela com a pergunta](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/62b28fc4-8ade-449d-8470-1d4f42560e0f)

![LED piscando quando o tempo está acabando](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/5cf877cf-1faa-4f71-94a5-70f027df8bac)

![Mensagem quando o tempo acaba](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/fa50e496-e3d9-40b3-b85d-67515d0ceb04)

![Mostra quantos pulos o usuário utilizou e ainda tem](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/4f65719e-6474-4f87-a6d7-7f17ffbf9139)

Quando o usuário acerta a questão, aparece uma mensagem na tela incentivando e mostrando a sua pontuação, além disso, toca uma música rápida de comemoração.

![Mensagem de acerto de questão](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/d578f306-bcd3-4061-9d52-b99b2177c3d5)

Se o usuário acertar as 5 perguntas do nível fácil, aparece uma mensagem na tela e conta um tempo para o usuário se preparar para o próximo nível que é mais díficil que o atual.

![Mensagem de comemoração](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/453f45a2-4e98-4efa-af2e-f5dc7b58f1ee)

Caso o usuário erre alguma pergunta do jogo ele perde. Portanto, o jogo reinicia e o usuário terá que iniciar o jogo novamente caso queria tentar ganhar. Além disso, toca uma música de derrota quando o usuário perde o jogo.

![Mensagem de erro](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/3abdf333-4f43-4854-b56d-93756f2208a0)

Quando o usuário acertar 5 perguntas de cada nível ele é encaminhado para a pergunta final do jogo. Se ele acertar essa pergunta pele ganha o jogo e por consequência toca uma música de vitória.

![Mensagem da pergunta final](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/629df57b-01bc-409e-9144-5b16f0150c65)

Como a pergunta final ela é muito grande, não aparece inteira no display, portanto, roda umas 3 vezes no display para o usuário ver ela inteira e poder responder.

![Pergunta final](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/625ad836-1c72-4e02-94d5-75eaeaf502b1)

Caso o usuário acertar essa pergunta aparece uma mensagem de comemoração e toca uma música comemorando.

![Mensagem de Comemoração](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/437c0411-1094-43ae-84e6-3b0d55b76d53)

O usuário pode pular a pergunta a qualquer momento ou desistir do jogo a qualquer momento. Porém, se o usuário decidir pular a pergunta ele só tem direito a 3 pulos se pular mais do que isso perde o jogo. Além disso, toca uma música quando pula a questão e uma música diferente quando o usuário desiste do jogo.

![Mensagem de quando pula](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/bc2fd24b-72bc-40ea-87db-e9850f5ccea9)

![Mensagem de quando desiste do jogo](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/2b0726af-5be3-417e-ac9a-0e542264086d)

Mas, se o usuário pular a última pergunta o jogo considera que ele não ganhou e como pulo. Portanto, toca a música que ele pulou e aparece uma mensagem na tela.

![Mensagem de quando pula a última questão](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/5c32f656-989b-4a08-84cc-7d91e20fb9a1)

## VÍDEO DE DEMONSTRAÇÃO DO JOGO

https://youtu.be/QH3YqY2qIXg

## CONCLUSÃO
O nosso maior desafio foi programar o display, encontramos dificuldade justamente por ter perdido essa aula, mas conseguimos recuperar quando o professor clareou nossas mentes explicando sobre interrupção e utilizamos essa função em um botão, em particular, no de iníciar/desistir do jogo. Contudo, para as perguntas criamos duas arrays e colocamos as perguntas em um e as respostas em outro. Mas, para dizer qual pergunta é de cada nível delimitamos por números, ou seja, iria sortear que definirá seu nível. Ou melhor, para delimitarmos os níveis utilizamos intervalos, ou seja, do 0 a 7 era o nível fácil, do 8 ao 15 nível médio, do 16 ao 23 nível díficil. Além disso, para armazenar as perguntas que já foram teria uma variável que é um array que armazena as questões que foram concluídas ou que foram puladas. 
