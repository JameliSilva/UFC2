#include<stdio.h>
#include<stdlib.h>

int main() {
	char Matriz[3][3]; //Criei um vetor de matriz
	char O = 'O', X = 'X';
	int l = 0, j, i; //Basicamente é contadores


	for (i = 0; i<3; i++) //For utilizado para fazer a matriz
		for (j = 0; j<3; j++)
			Matriz[i][j] = ' ';

	while (l <= 9) // Para fazer o jogo rodar, caso algum jogador digite uam cordenada invalida ele manda digitar outra vez.
	{
		printf_s("JOGO DA VELHA \n"); //Printar nome do jogo

		for (i = 0; i<3; i++) //for usado para pritnar a matriz que foi feita com tabulaçao, e usando tabela Ascii com numeros hexadecimais
		{
			printf_s("\t     %c \xb3 %c \xb3 %c\n", Matriz[i][0], Matriz[i][1], Matriz[i][2]);

			if (i<2) {
				printf("\t    \xc4\xc4\xc4\xC5\xc4\xc4\xc4\xC5\xc4\xc4\xc4\n");
			}
		}

		printf_s("\nINSIRA AS COORDENADAS, ");

		if (l % 2)printf_s("jogador 2\nLINHA: ");

		else printf_s("Jogador 1\nLINHA: ");

		scanf_s("%d", &i);
		printf_s("COLUNA: ");
		scanf_s("%d", &j);

		if (Matriz[i - 1][j - 1] == ' ') // if usado apra comparar se aidna tem casas vazias para continuar o jogo
		{
			if (l % 2)Matriz[i - 1][j - 1] = X;
			else Matriz[i - 1][j - 1] = O;
			l++;
		}
		system("cls"); //Limpa a tela, para da ideia de autualizaçao do game



					   //ESSES if(s) sao usados para saber quem ganhou

		if ((Matriz[0][0] == O && Matriz[0][1] == O && Matriz[0][2] == O) ||
			(Matriz[1][0] == O && Matriz[1][1] == O && Matriz[1][2] == O) ||
			(Matriz[2][0] == O && Matriz[2][1] == O && Matriz[2][2] == O) ||
			(Matriz[0][0] == O && Matriz[1][0] == O && Matriz[2][0] == O) ||
			(Matriz[0][1] == O && Matriz[1][1] == O && Matriz[2][1] == O) ||
			(Matriz[0][2] == O && Matriz[1][2] == O && Matriz[2][2] == O) ||
			(Matriz[0][0] == O && Matriz[1][1] == O && Matriz[2][2] == O) ||
			(Matriz[0][2] == O && Matriz[1][1] == O && Matriz[2][0] == O))
		{
			printf_s("\a\t\tJogador 1, VOCE VENCEU!!!");// printa vencedor e o contra barra faz um som
			break;
		}
		if ((Matriz[0][0] == X && Matriz[0][1] == X && Matriz[0][2] == X) ||
			(Matriz[1][0] == X && Matriz[1][1] == X && Matriz[1][2] == X) ||
			(Matriz[2][0] == X && Matriz[2][1] == X && Matriz[2][2] == X) ||
			(Matriz[0][0] == X && Matriz[1][0] == X && Matriz[2][0] == X) ||
			(Matriz[0][1] == X && Matriz[1][1] == X && Matriz[2][1] == X) ||
			(Matriz[0][2] == X && Matriz[1][2] == X && Matriz[2][2] == X) ||
			(Matriz[0][0] == X && Matriz[1][1] == X && Matriz[2][2] == X) ||
			(Matriz[0][2] == X && Matriz[1][1] == X && Matriz[2][0] == X))
		{
			printf_s("\a\t\tJogador 2, VOCE VENCEU!!!");
			break;
		}

		if (l == 9)//If usado deposi de 9 jogadas se ninguem tiver ganhado da emapte ou seja veia
		{
			printf_s("\aPARTIDA EMPATADA");
			break;
		}

	}
	printf_s("\n");

	for (i = 0; i<3; i++) //for usado para pritnar  a matriz final, dizendo quem ganhou
	{
		printf_s("\t     %c \xb3 %c \xb3 %c\n", Matriz[i][0], Matriz[i][1], Matriz[i][2]);

		if (i<2) {
			printf_s("\t    \xc4\xc4\xc4\xC5\xc4\xc4\xc4\xC5\xc4\xc4\xc4\n");
		}
	}

	return(0);
}