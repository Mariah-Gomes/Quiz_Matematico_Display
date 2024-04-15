# Projeto Computação Móvel
Nome: Iago Rosa de Oliveira R.A.: 24.123.056-4

Nome: Mariah Santos Gomes R.A.: 24.222.027-5

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

# Código comentado

Circuito que montamos no Tinkercad

![Circuito Tinkercad](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/ceec4e8e-82c0-47da-bf58-ef968e7b7ce5)

Circuito montado na aula



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

Quando o usuário acerta a questão, aparece uma mensagem na tela incentivando e mostrando a sua pontuação, além disso, toca uma música rápida de comemoração

![Mensagem de acerto de questão](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/d578f306-bcd3-4061-9d52-b99b2177c3d5)

Se o usuário acertar as 5 perguntas do nível fácil, aparece uma mensagem na tela e conta um tempo para o usuário se preparar para o próximo nível que é mais díficil que o atual.

![Mensagem de comemoração](https://github.com/Mariah-Gomes/ProjetoCompMovel1/assets/141663285/453f45a2-4e98-4efa-af2e-f5dc7b58f1ee)


## CONCLUSÃO

