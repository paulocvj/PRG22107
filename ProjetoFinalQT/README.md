## Projeto final - PRG22107

### Jogo de cartas in-between

Jogo de cartas que o objetivo é decidir se a carta que o jogador irá receber estará entre as duas cartas viradas na mesa. O jogo original funciona com apostas, onde é apostado o valor e caso a carta esteja entre as duas da mesa, o jogador recebe o dobro do que apostou. Nessa modalidade, para o projeto final, será utilizado esquema de pontuação, onde o jogador vai decidir se a carta que será virada estará entre as cartas do meio ou não. Acertando, ele aumenta sua pontuação e perdendo não pontua nada. Será feito um sistema de 10 rodadas, onde a maior pontuação será se o jogador acertar todas as vezes. O jogo poderá ser jogado por mais de um jogador, mas nessa versão será possível jogar somente no modo de um jogador.

O baralho não é sempre embaralhado, e as cartas utilizadas são jogadas em uma pilha de lixo.

Cada jogada quando se tem somente um jogador utiliza 3 cartas, as duas do meio e a recebida pelo jogador. Cada jogador a mais aumenta em 1 a quantidade de cartas utilizada no jogo. Para chegar a 10 rodadas sempre, a maior quantidade de jogadores será de 3 ao mesmo tempo, pois assim serão utilizadas 5 cartas a cada rodada, para não ultrapassar as 52 do baralho.

Poderá ser utilizado também dois baralhos, e dessa forma chega-se a 8 jogadores simultâneos, com as regras se mantendo as mesmas.

### Casos de uso

Uma partida é iniciada para um jogador. O dealer (máquina) vira duas cartas do baralho no meio do tabuleiro. O jogador recebe uma carta virada para baixo e escolhe se essa carta está entre os valores da mesa ou não. Após a escolha, a carta é virada e o jogador ganha 10 pontos caso tenha acertado sua previsão. Caso erre, não ganha nenhum ponto. Após os pontos serem dados, as cartas utilizadas na rodada são jogadas na pilha de descarte e é iniciado uma nova rodada, até chegar a 10 rodadas. Cada rodada é marcada na tela, indicando em qual rodada o jogo está. Após as 10 rodadas, a pontuação é mostrada na tela.

### Regras

O jogador, quando escolhe que sua carta está entre as duas cartas da mesa, pontua somente quando:
- A sua carta é maior que a mínima e menor que a máxima (min < carta < máx). Caso seja igual a uma das duas, o jogador não pontua.

O jogador, quando escolhe que sua carta NÃO está entre as duas cartas da mesa, pontua somente quando:
- A sua carta é menor ou igual a mínima e maior ou igual a máxima (carta <= min | carta >= máx).

A ordem das cartas segue o padrão onde o dois é a menor carta (valendo 2), e o ás é a maior carta (valendo 14).

### Exemplo de jogo

Um jogo é iniciado. O baralho é embaralhado e o dealer dá as cartas, sendo as duas viradas para cima um 4 e um valete (11), e outra carta virada para baixo. O jogador decide que sua carta está entre as duas viradas para cima. A carta do jogador é virada e revela que o jogador recebeu um 7. O jogador pontua. As cartas 4, valete e 7 são descartadas e não serão mais utilizadas durante o jogo. Portanto, agora restam somente três cartas de valor 4, 7 e 11 no baralho. O mesmo procedimento é refeito para as outras 9 rodadas, porém sem embaralhar o baralho, já que só é necessário embaralhar ele no início do jogo. Ao final das 10 rodadas, é mostrado na tela que o jogador fez 60 pontos.

## Diagrama de classes

Abaixo está o diagrama de classes do projeto no QT.

![Diagrama de classes](https://raw.githubusercontent.com/paulocvj/PRG22107/main/Class_diagram.png)
