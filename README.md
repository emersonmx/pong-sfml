# pong-sfml

Esta é mais umas implementação do clássico pong que foi desenvolvido com C++, 
SFML, Box2D e um pouco de preguiça.

O jogo possui os mesmo elementos do original (Raquetes, paredes e bola). Porém eu
resolvi adicionar um pouco de física na bola para que ela se comporte como uma
bola quadrada (https://www.youtube.com/watch?v=3fEZ1NzTSfo). Não se assute caso
você rebata a bola e ela volte sem aviso prévio :)

## Controles

- Cima e baixo para mover a raquete
- Enter para pausar ou selecionar uma opção do menu

## Construção

Eu adicionei um arquivo na raiz do projeto para construir, executar e gerar as tags pro vim :D
Assim pra fazer os paranauê é só executar o ```run.sh```. Por padrão ele constroi em modo de debug. O
que deixa uma tela verde durante o jogo. Para remover a tela verde execute ```run.sh Release```.
