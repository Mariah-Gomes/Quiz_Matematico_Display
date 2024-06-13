# Quiz Matemático Display

> Status do projeto: Finalizado

> Esse projeto nos foi proposto no 4ºSemestre na disciplina de Computação Móvel

> Programamos inicialmente esse projeto no tinkercad juntos, depois passamos para a IDE do Arduino logo que fizemos isso subimos o arquivo do Arduino IDE no GitHub  

### Tópicos

🔹[Descrição do Projeto](#pencil-descrição-do-projeto)

🔹[Funcionalidade](#mag_right-funcionalidade)

🔹[Tecnologias Utilizadas](#computer-tecnologias-utilizadas)

🔹[Desenvolvedores](#busts_in_silhouette-desenvolvedores)

## :pencil: Descrição do Projeto

<div align="justify">
      Nesse projeto nos foi proposto fazer um jogo de perguntas e respostas, onde elas aparecem em um display e o usuário aperta os botões de "sim" ou "não" para responder as perguntas. Além disso, o jogo emite sons em diversas situações.
<br>
O jogo deveria possuir 3 níveis de perguntas, ou seja, fácil, médio e difícil e o jogador deverá acertar 5 perguntas de cada nível. Mas, para ganhar o jogo precisaria acertar uma pergunta final.
<br>
O jogo utiliza 5 sons diferentes para 5 situações diferentes. Os casos são: quando acerta a questão, pula a questão, errou a questão, desistiu do jogo e venceu o jogo. Além disso, quando o tempo estiver acabando o led começa a piscar.
</div>

## :mag_right: Funcionalidade
1.  O jogo possui 4 botões, inclusive, um deles quando apertamos inícia o jogo. E aparece uma frase no display e o jogo começa a rodar.

<div align="center">
   <img width=400 height=250 src="https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/11f4bff3-5913-44e1-9e97-1c6a3d78c1b7"/>
</div>

2. Em seguida, o jogo começa a rodar perguntas do nível 1, a saber, que o jogo possui três níveis, ou seja, fácil, médio e díficil. Por isso, o usuário começa a responder as perguntas do nível 1 que seria o fácil e após ele responder e acertar 5 questões desse nível ele sobre o nível.

![Tela de níveis](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/ee49d95d-3e8c-4e69-aebe-7393da3c6b57)
   
3. A proxíma tela já começa a mostrar as perguntas, em suma, aparece a pergunta e o usuário tem um tempo para responder "sim" ou "não". Porventura, o usuário demorar para responder o LED vermelho vai começar a piscar e se o usuário não responder no tempo certo pula a pergunta e ele perde 1 pulo.

![Tela com a pergunta](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/62b28fc4-8ade-449d-8470-1d4f42560e0f)

![LED piscando quando o tempo está acabando](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/5cf877cf-1faa-4f71-94a5-70f027df8bac)

![Mensagem quando o tempo acaba](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/fa50e496-e3d9-40b3-b85d-67515d0ceb04)

![Mostra quantos pulos o usuário utilizou e ainda tem](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/4f65719e-6474-4f87-a6d7-7f17ffbf9139)

4. Quando o usuário acerta a questão, aparece uma mensagem na tela incentivando e mostrando a sua pontuação, além disso, toca uma música rápida de comemoração.

![Mensagem de acerto de questão](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/d578f306-bcd3-4061-9d52-b99b2177c3d5)

5. Se o usuário acertar as 5 perguntas do nível fácil, aparece uma mensagem na tela e conta um tempo para o usuário se preparar para o próximo nível que é mais díficil que o atual.

![Mensagem de comemoração](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/453f45a2-4e98-4efa-af2e-f5dc7b58f1ee)

6. Caso o usuário erre alguma pergunta do jogo ele perde. Portanto, o jogo reinicia e o usuário terá que iniciar o jogo novamente caso queria tentar ganhar. Além disso, toca uma música de derrota quando o usuário perde o jogo.

![Mensagem de erro](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/3abdf333-4f43-4854-b56d-93756f2208a0)

7. Quando o usuário acertar 5 perguntas de cada nível ele é encaminhado para a pergunta final do jogo. Se ele acertar essa pergunta pele ganha o jogo e por consequência toca uma música de vitória.

![Mensagem da pergunta final](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/629df57b-01bc-409e-9144-5b16f0150c65)

8. Como a pergunta final ela é muito grande, não aparece inteira no display, portanto, roda umas 3 vezes no display para o usuário ver ela inteira e poder responder.

![Pergunta final](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/625ad836-1c72-4e02-94d5-75eaeaf502b1)

9. Caso o usuário acertar essa pergunta aparece uma mensagem de comemoração e toca uma música comemorando.

![Mensagem de Comemoração](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/437c0411-1094-43ae-84e6-3b0d55b76d53)

10. O usuário pode pular a pergunta a qualquer momento ou desistir do jogo a qualquer momento. Porém, se o usuário decidir pular a pergunta ele só tem direito a 3 pulos se pular mais do que isso perde o jogo. Além disso, toca uma música quando pula a questão e uma música diferente quando o usuário desiste do jogo.

![Mensagem de quando pula](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/bc2fd24b-72bc-40ea-87db-e9850f5ccea9)

![Mensagem de quando desiste do jogo](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/2b0726af-5be3-417e-ac9a-0e542264086d)

11. Mas, se o usuário pular a última pergunta o jogo considera que ele não ganhou e como pulo. Portanto, toca a música que ele pulou e aparece uma mensagem na tela.

![Mensagem de quando pula a última questão](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/5c32f656-989b-4a08-84cc-7d91e20fb9a1)

## :computer: Tecnologias Utilizadas
- Para montarmos uma primeira ideia do projeto utilizamos o Tinkercad;
- A IDE que utilizamos foi a Arduino IDE;
- A linguagem que utilizamos foi C++;
- Os materiais que utilizamos para montar o circuito do tinkercad foi:
  - Arduino Uno;
  - 1 LED vermelho;
  - 4 botões;
  - Buzzer;
  - Display LCD 16x2;
  - Placa de ensaio;
  - 2 resistores;
  - 1 potenciômetro;

Com os materiais que iriamos utilizar em mente e com as perguntas feitas, dessa forma, começamos a desenvolver o projeto. Assim, fizemos o circuito no tinkercad, em seguida, desenvolvemos o código para realizar todas as funções do jogo e por último montamos o circuito no dia de sua entrega na aula.

## Circuitos Montados
### Circuito Tinkercad
![Circuito Tinkercad](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/ceec4e8e-82c0-47da-bf58-ef968e7b7ce5)
### Circuito Com Arduino UNO
![Circuito montado na aula](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/104e619f-c209-40fc-8598-2e0f96620624)

## :busts_in_silhouette: Desenvolvedores
| [<img loading="lazy" src="https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/e6827fd1-d8fe-4740-b6fc-fbbfccd05752" width=115><br><sub>Mariah Santos Gomes</sub>](https://github.com/Mariah-Gomes) | [<img loading="lazy" src="https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/66d7e656-b9e4-43b7-94fa-931b736df881" width=115><br><sub>Iago Rosa de Oliveira</sub>](https://github.com/iagorosa28) |
| :---: | :---: |
