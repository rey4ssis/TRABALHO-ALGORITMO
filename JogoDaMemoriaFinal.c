#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include<locale.h>
#include<windows.h>
#include<conio.h>

/*VARIAVEIS GLOBAIS*/
char table[4][8];
int i,j,c1,c2;
char printab[4][8];
int ganhou=0;
int dificult;
int cheat1=0;
int cheat2=0;

//Funcao embaralhamento atraves dr vetor
void mixtable();
//Funcao de menu do jogo
int menu();
//Funcao de validacao de jogadas
int jogadavalida();
//Funcao de preenchimento da matriz de print
void printcards();
//Funcao de cheat
void hack();
//Funcao manual do jogador leigo
void manual();

//Imprimir tabuleiro
void tabuleiro(char casas2[4][8]){

	printf("\n");
	  	printf("\n");
	  printf("\t\t  ----------------------------------------\n");
	  printf("\t\t  | %c || %c || %c || %c || %c || %c || %c || %c |\n", casas2[0][0], casas2[0][1], casas2[0][2], casas2[0][3], casas2[0][4], casas2[0][5], casas2[0][6], casas2[0][7]);
	  printf("\t\t  ---------------------------------------\n");
	  printf("\t\t  | %c || %c || %c || %c || %c || %c || %c || %c |\n", casas2[1][0], casas2[1][1], casas2[1][2], casas2[1][3], casas2[1][4], casas2[1][5], casas2[1][6], casas2[1][7]);
	  printf("\t\t  ----------------------------------------\n");
	  printf("\t\t  | %c || %c || %c || %c || %c || %c || %c || %c |\n", casas2[2][0], casas2[2][1], casas2[2][2], casas2[2][3], casas2[2][4], casas2[2][5], casas2[2][6], casas2[2][7]);
	  printf("\t\t  ----------------------------------------\n");
	  printf("\t\t  | %c || %c || %c || %c || %c || %c || %c || %c |\n", casas2[3][0], casas2[3][1], casas2[3][2], casas2[3][3], casas2[3][4], casas2[3][5], casas2[3][6], casas2[3][7]);
	  printf("\t\t  ----------------------------------------\n");
}

/*Jogo*/
int main(){
	setlocale(LC_ALL, "portuguese");
int op,valido,cont1,cont2,rolou;
cont1=cont2=rolou=0;
char p1[30],p2[30];
//preenchendo inicial da matriz de print -que monstrará as cartas esolhidas;
for(i=0;i<4;i++){
for(j=0;j<8;j++){
  printab[i][j]=' ';}
}
//jogando a partir das seleções da funcoo menu
op=menu();
if(op==1){
printf("\t\t  !!!PARA COMEÇAR O JOGO OS JOGADORES DEVEM SE IDENTIFICAR!!!\n\n\t       \t\tPOR FAVOR CELEBRES JOGADORES NOS DIGAM SEUS NOMES:\n\n");
printf("SOBERANO, PLAYER 1 DIGITE SEU NOME:\n");
scanf("%s", p1);
printf("SUPREMO, PLAYER 2 DIGITE SEU NOME:\n");
scanf("%s", p2);

system("cls");

printf("\t %s É O PARTICIPANTE NUMERO 1 DO JOGO\n\n\t %s É O PARTICIPANTE NÚMERO 2 DO JOGO\n",p1,p2);
Sleep(900);

system("cls");
printf("\t\t     !!!!GRAVE O QUANTO PUDER HAHAHA!!!!\n\n\t\t       !!!!QUE OS JOGOS COMEÇEM!!!!\n");
	mixtable();
	system("cls");
	//O jogo durará enquanto o numero de pares descobertos for mernor que 16;
  while(ganhou<16){
    valido=0;
    while(valido==0 || valido==1 && ganhou<16){
    	if(rolou==0){
		 tabuleiro(printab);}
		else{
	  printcards();}
	  rolou=1;
       if(cheat1==12345){
      	printf("\n\t\t    PARECE QUE ALGUEM CONHECE AS REGRAS DO JOGO\n\n");
      	hack();
	  }
	  printf("\n\t\t\t     INDICAÇÕES DE CARTAS\n");
      printf("\n\t\t\tSOBERANO %s ESCOLHA SUAS CARTAS:\n\n",p1);
      valido=jogadavalida();
      if(table[c1/8][c1%8]==table[c2/8][c2%8] && c1!=c2){
        cont1+=1;}
		 else{
      valido=2;}
      ganhou=cont1+cont2;}
    Sleep(5000);
    system("cls");
    valido=0;

    if(ganhou<16){
    while(valido==0 || valido==1 && ganhou<16){
	  printcards();
      if(cheat2==54321){
      	printf("\n\t\t    PARECE QUE ALGUÉM CONHECE AS REGRAS DO JOGO\n\n");
      	hack();
	  }
	  	  printf("\n\t\t\t    INDICACOES DE CARTAS\n");
        printf("\n\t\t\tSUPREMO %s ESCOLHA SUAS CARTAS:\n\n",p2);
      valido=jogadavalida();
      if(table[c1/8][c1%8]==table[c2/8][c2%8] && c1!=c2){
        cont2+=1;
      }
      else{
      valido=2;}
      ganhou=cont1+cont2;
    }
}
    Sleep(5000);
    system("cls");

}
  if(cont1>cont2)
  	printf("\n\t\t  PARABÉNS SOBERANO %s VOCÊ GANHOU O JOGO\n\t\t  OBTEVE INCRÍVEIS %d ACERTOS",p1,cont1);
  else{
  	if(cont1<cont2)
  	printf("\n\t\t  PARABÉNS SUPREMO %s VOCÊ GANHOU O JOGO\n\t\t OBTEVE INCRÍVEIS %d ACERTOS",p2,cont2);
  	else{
  		printf("\n\t\t  AS HABILIDADES DOS SENHORES É IMPRESSIONANTE - O JOGO EMPATOU");
	  }
  }
  printf("\n\t\t  OBRIGADO POR JOGAR O ALFABETIC MEMORY GAME MEUS SENHORES");
}

  else{
    printf("\n\t\t  OK! VOLTE QUANDO TIVER MAIS SENSO CRITICO");
  }
  return 0;
}


//Apresentacao de jogadas
void printcards(){

printab[c1/8][c1%8]=table[c1/8][c1%8];
printab[c2/8][c2%8]=table[c2/8][c2%8];
/*for(i=0;i<4;i++){
  for(j=0;j<8;j++){
    printf(" [%c]",printab[i][j]);
  }printf("\n");
  }*/
 //printab tabuleiro estava aqui
  tabuleiro(printab);
  if(table[c1/8][c1%8]==table[c2/8][c2%8] && c1!=c2){
  /*05/12 excluindo valor permanentemente do table e somando ganhou*/
    printab[c1/8][c1%8]=table[c1/8][c1%8]='X';
    printab[c2/8][c2%8]=table[c2/8][c2%8]='X';
    printf("\n\t     PARABÉNS VOCÊ ACERTOU UM PAR - POR ISSO PODE JOGAR DENOVO \n\n\n");
    Sleep(3000);
    system("cls");
  }
  else{
  	if(printab[c1/8][c1%8]!='X' || c1==c2)
    printab[c1/8][c1%8]=' ';
    if(printab[c2/8][c2%8]!='X' || c1==c2)
    printab[c2/8][c2%8]=' ';}
}


//verificador de jogadas
int jogadavalida(){
int line1,line2,col1,col2;
 int num1,num2;
 num1=0;
 num2=0;

  //preenchimento da matriz de indicação
  printf("\n");
  for(i=0;i<4;i++){
  	printf("\t\t  ");
    for(j=0;j<8;j++){
      printf(" [%d%d]",num1,num2);
      num2++;
	  if(num2>9){
	  num2=0;
     num1++;}}
	 printf("\n");}

  printf("\n");
  printf("\n\t\t  POR FAVOR MEU AMO, DIGITE A POSIÇÃO DAS CARTAS:");
  printf("\n A CARTA 1 É:");
  scanf(" %d",&c1);
  printf("\n A CARTA 2 É:");
  scanf(" %d",&c2);
  //transformaçao da posicao da carta em variavel
  line1=c1/8;
  line2=c2/8;
  col1=c1%8;
  col2=c2%8;

//validade das jogadas
  if(c1==c2){
  	system("cls");
    printf("\n\n\n\n\t\t  !!!!MEU CARO, VOCÊ NÃO PODE ESCOLHER A MESMA CARTA!!!!\n");
    printf("\n\t\t  !!!!PENALIDADE A VEZ AGORA É DO OUTRO JOGADOR!!!!\n");
    return 2;
  }
  	//Verificando se as posicoes escolhidas estao no limite e retornando um valor baseado em cada possibilidade
    if(line1<4 && col1<8 && line2<4 && col2<8){
    if(printab[line1][col1]!='X' && printab[line2][col2]!='X'){
    printcards();
      return 1;
    }
    else{
    	system("cls");
      printf("\n\n\n\n\t\t  !!!!MEU SENHOR, O SENHOR ESCOLHEU POSIÇÕES INVALIDAS!!!!\n");
      printf("\n\t\t  !!!!PENALIDADE A VEZ AGORA É DO OUTRO JOGADOR!!!!\n");
      return 2;}
    }
    else{
    	system("cls");
    printf("\n\t\t  INFELIZMENTE ESTAS SÃO COORDENADAS INVALIDAS\n");
    printf("\n\\t\t  !!!!SEREI BENEVOLENTE - TENTE OUTRA VEZ!!!!\n");
    printcards();
      return 0;
    }
  }


//menu do jogo
int menu(){
  char op;
  int ler;
  int nivel;

  printf("\t\t  !!!!BEM VINDO AO ALFABETIC MEMORY GAME!!!!\n\n");
  printf("\t\t\t      Pressione space\n\n\t\t\t  qualquer outra para sair:\n");
  scanf("%c",&op);
  system ("cls");
  printf("\t\t  DESEJA LER O MANUAL DO PEQUENO GARFANHOTO AVENTUREIRO?\n(1)SIM;\n(2)NÃO;\nDIGITE SUA SABIA ESCOLHA:");
  scanf(" %d",&ler);
  if(ler==1){
  system("cls");
  manual();
  Sleep(10000);
  system("cls");
}
else{
	system("cls");
}
   printf("\t\t  ESOLHA A DIFICULDADE\n\n\t\t  (1)Easy;\n\t\t  (2)Normal;\n\t\t  (3)Hard;\nDigite:");
   scanf(" %d",&nivel);
   switch(nivel){
   	case 1:
	   dificult=15000;
	   break;
	case 2:
		dificult=8000;
		break;
	case 3:
		dificult=2000;
		break;
   }
   system("cls");
   printf("\t\t  POSSUI ALGUM CÓDIGO DE CHEAT JOGADOR 1? \n\t\t  DIGITE SEU CÓDIGO:");
   scanf("%d",&cheat1);
   if(cheat1==12345)
   printf("MUITO BEM, VEJO QUE É UM JOGADOR SÁBIO - APROVEITE");
   else{
   	printf("DESCULPE, MAS PARECE QUE VOCE NÃO TEM O PASSAPORTE DOS DEUSES");
   }
    Sleep(3000);
    system("cls");
   printf("\t\t  POSSUI ALGUM CÓDIGO DE CHEAT JOGADOR 2? \n\t\t  DIGITE SEU CÓDIGO:");
   scanf("%d",&cheat2);
   if(cheat2==54321)
   printf("MUITO BEM, VEJO QUE É UM JOGADOR SÁBIO - APROVEITE");
   else{
   	printf("DESCULPE, MAS PARECE QUE VOCE NÃO TEM O PASSAPORTE DOS DEUSES");
   }
   Sleep(3000);
   system("cls");
  if(op==' '){
    return 1;
  }
  else{
    return 0;
  }
}

//funcao de cheat do sistema
void hack(){
	int i,j;
	for(i=0;i<4;i++){
printf("\t\t     ");
for(j=0;j<8;j++){
 printf("[%c] ",table[i][j]);}
 printf("\n");
}
printf("\n\n");}

//funcao de manual do jogador
void manual(){
 printf("\t\t\t\t\t  !!!!BEM VINDO AO ALFABETIC MEMORY GAME!!!!\n\n\n\n");
 printf("\t     BEM VINDO JOVEM AVENTUREIRO, AO AURÉLIO DO ALFABETIC, AQUI VOCÊ APRENDERÁ O SENTIDO DA VIDA\n\tQUAL O PROPOSITO DA SUA EXISTÊNCIA E TAMBÉM COMO FUNCIONA O UNIVERSO DO ---ALAFABETIC MEMRORY GAME--- \n\t\t\t\t         TALVEZ MAIS A SEGUNDA COISA QUE A PRIMEIRA\n\n\t          BEM A PRIMEIRA COISA QUE VOCE DEVE SABER E QUE O JOGO E COMPOSTO DE TRÊS DIFICULDADES\n\t\t\t ELAS DETERMINARAM A QUANTIDADE DE TEMPO QUE VOCÊ TERÁ PARA VER AS CARTAS\n\t\t\t\t\t DICA:(BONS JOGADORES USAM APENAS O HARD)\n\n\t       HÁ PORÉM UM CÓDIGO ESPECIAL QUE LHE GARANTIRÁ ACESSO A TABELA VERDADE DURANTE TODO O GAME\n\t\t\t  ENTRETANTO OS DEVs NUNCA LHE DARAM A CHAVE(HAHAHA NOS SOMOS OS DEVs)\n\n     BEM A SEGUNDA COISA QUE DEVE SABER E QUE VOCE DEVERÁ ESCOLHER AS CARTAS BASEANDO-SE NA MATRIZ DE INDICAÇÃO\n\t   ELA LHE AJUDARÁ A DECIDIR QUAL A POSIÇÃO DAS CARTAS DESEJADAS - E NÃO HÁ PROBLEMA DIGITAR 07 OU 7 -\n\n      O JOGO ACABARA QUANDO OS 16 PARES FOREM ENCONTRADOS E ENTAO SERÁ EXIBIDO QUEM ACERTOU MAIS PARES DE CARTAS\n\n\n\n\n\t\t\t\t            ---UMA HOMENAGEM A FABIO ASSUNCAO---\n\n\t\t\t\t\t          DEVELOPED BY VITOR E NEGHO");
}

//embaralhador de matriz
void mixtable(){
//Vetor de cartas
int cards[32]={'a','b','c','d','e','f','g','h','i','j','k','l','m','o','p','q','a','b','c','d','e','f','g','h','i','j','k','l','m','o','p','q'};
/*cards[32]={33,35,36,37,38,63,60,61,64,126,157,168,169,184,188,241,33,35,36,37,38,63,60,61,64,126,157,168,169,184,188,241};*/
int aux,r=0;
aux=0;
srand(time(NULL));
for(i=0;i<32;i++){
  r=rand()%32;
  aux=cards[i];
  cards[i]=cards[r];
  cards[r]=aux;
}

//Preenchendo Matriz inicial
aux=0;
for(i=0;i<4;i++){
  for(j=0;j<8;j++){
    table[i][j]=cards[aux];
    aux=aux+1;
  }
}
//Printando matriz

	tabuleiro(table);
printf("\n");
Sleep(dificult);
//for(i=0;i<80000;i++){printf("\a");}
}
