# CardWar
programa que descubra qual jogador é o vencedor de uma determinada distribuição de cartas do jogo de "guerra".


	**Regras**
A guerra é um jogo de cartas jogado entre dois jogadores. Cada jogador recebe um número variável de cartas do início do jogo: esse é o baralho do jogador. As cartas são colocadas viradas para baixo no topo de cada baralho.
 
Passo 1: a luta
A cada rodada do jogo, em uníssono, cada jogador revela a carta do topo de seu baralho – esta é uma “batalha” – e o jogador com a carta mais alta pega as duas cartas jogadas e as move para o fundo de sua pilha. As cartas são ordenadas por valor da seguinte forma, do mais fraco ao mais forte:
2,3,4,5,6,7,8,9,10,J,Q,K,UMA.
 
Passo 2: guerra
Se as duas cartas jogadas tiverem o mesmo valor, então há uma "guerra". Primeiro, ambos os jogadores colocam as três próximas cartas de sua pilha viradas para baixo . Então eles voltam para o passo 1 para decidir quem vai ganhar a guerra ( várias "guerras" podem ser encadeadas ). Assim que um jogador ganha uma "guerra", o vencedor adiciona todas as cartas da "guerra" ao seu baralho.
 
**Casos especiais:**
Se um jogador ficar sem cartas durante uma "guerra" (ao desistir das três cartas ou ao fazer a batalha), o jogo termina e ambos os jogadores são colocados igualmente em primeiro lugar.
Os casos de teste fornecidos neste quebra-cabeça são construídos de tal forma que um jogo sempre termina (você não precisa lidar com jogos infinitos)
Cada carta é representada pelo seu valor seguido do seu naipe: D,H,C,S. Por exemplo:4H,8C,COMO.

Quando um jogador vence uma batalha, ele coloca de volta as cartas no fundo de seu baralho em uma ordem precisa. Primeiro as cartas do primeiro jogador, depois a do segundo jogador (para uma "guerra", todas as cartas do primeiro jogador e depois todas as cartas do segundo jogador).

Por exemplo, se a distribuição de cartas for a seguinte:
Jogador 1:10D 9S 8D KH 7D 5H 6S
Jogador 2:10H 7H 5C QC 2C 4H 6D
Então, após um turno de jogo, será:
Jogador 1:5H 6S 10D 9S 8D KH 7D 10H 7H 5C QC 2C
Jogador 2:4H 6D

#Compilando o código:

cd src
g++ -std=c++11 war.cpp -o teste
