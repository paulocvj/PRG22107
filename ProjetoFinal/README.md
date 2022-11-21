## Projeto final - PRG22107

### Jogo de cartas in-between

Jogo de cartas que o objetivo é decidir se a carta que o jogador irá receber estará entre as duas cartas viradas na mesa. O jogo original funciona com apostas, onde é apostado o valor e caso a carta esteja entre as duas da mesa, o jogador recebe o dobro do que apostou. Nessa modalidade, para o projeto final, será utilizado esquema de pontuação, onde o jogador vai decidir se a carta que será virada estará entre as cartas do meio ou não. Acertando, ele aumenta sua pontuação e perdendo não pontua nada. Será feito um sistema de 10 rodadas, onde a maior pontuação será se o jogador acertar todas as vezes. A pontuação será guardada em um arquivo para sempre ter acesso, mesmo fechando o programa. O jogo poderá ser jogado por mais de um jogador, onde cada pontuação e será separada e cada carta recebida também.

O baralho não é sempre embaralhado, e as cartas utilizadas são jogadas em uma pilha de lixo.

Cada jogada quando se tem somente um jogador utiliza 3 cartas, as duas do meio e a recebida pelo jogador. Cada jogador a mais aumenta em 1 a quantidade de cartas utilizada no jogo. Para chegar a 10 rodadas sempre, a maior quantidade de jogadores será de 3 ao mesmo tempo, pois assim serão utilizadas 5 cartas a cada rodada, para não ultrapassar as 52 do baralho.

Poderá ser utilizado também dois baralhos, e dessa forma chega-se a 8 jogadores simultâneos, com as regras se mantendo as mesmas.

### Casos de uso

Uma partida é iniciada com a quantidade de jogadores selecionada. Se o número de jogadores for maior que 3, são utilizados dois baralhos, caso contrário, é utilizado apenas um baralho. O dealer (máquina) vira duas cartas do baralho no meio do tabuleiro. Cada jogador recebe uma carta virada para baixo e escolhe se essa carta está entre os valores da mesa ou não. Após todos os jogadores escolherem, as cartas são viradas e os jogadores que acertarem ganham 10 pontos. Os jogadores que errarem não ganham nenhum ponto. Após os pontos serem dados, as cartas utilizadas na rodada são jogadas na pilha de descarte e é iniciado uma nova rodada, até chegar a 10 rodadas. Cada rodada é marcada na tela, indicando em qual rodada o jogo está. Após as 10 rodadas, o jogador com maior pontuação vence a partida e a sua pontuação é guardada em um arquivo, junto com as maiores pontuações.

### Regras

O jogador, quando escolhe que sua carta está entre as duas cartas da mesa, pontua somente quando:
- A sua carta é maior que a mínima e menor que a máxima (min < carta < máx). Caso seja igual a uma das duas, o jogador não pontua.

O jogador, quando escolhe que sua carta NÃO está entre as duas cartas da mesa, pontua somente quando:
- A sua carta é menor ou igual a mínima e maior ou igual a máxima (carta <= min | carta >= máx).

A ordem das cartas segue o padrão onde o ás é a menor carta (valendo 1), e o rei é a maior carta (valendo 13).

### Exemplo de jogo

Um jogo é iniciado para dois jogadores. Como dois jogadores utilizam 4 cartas por rodada, é utilizado apenas um baralho. O baralho é embaralhado e o dealer dá as cartas, sendo as duas viradas para cima um 4 e um valete (11), e outras duas cartas viradas para baixo, uma para cada jogador. O jogador 1 decide que sua carta está entre as duas viradas para cima. O jogador 2 decide que sua carta não está entre as duas viradas para cima. As cartas são viradas e revelam que o jogador 1 recebeu um 7 e o jogador 2 recebeu um 4. Os dois jogadores pontuam. As cartas 4, valete, 7 e 4 são descartadas e não serão mais utilizadas durante o jogo. Portanto, agora restam somente duas cartas de valor 4 no baralho. O mesmo procedimento é refeito para as outras 9 rodadas, porém sem embaralhar o baralho, já que só é necessário embaralhar ele no início do jogo. Ao final das 10 rodadas, o jogador 2 venceu o jogador 1 por 70 pontos a 50. O jogador 2 coloca sua sigla e sua pontuação é colocada na lista de maiores pontuações.
