#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria (dados)
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cadastrar as strings

int registro() //fun��o respons�vel pelo cadastro de usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem do programa
	
	char arquivo[11];
	char cpf[11];  // campos para o cadastro
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Cadastre aqui o seu CPF: "); // coletando as informa��es do usu�rio
	scanf("%s", cpf); // %s refere-se � capta��o de strings
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores das strings
	
	FILE *file; //acessa os arquivos e CRIA o arquivos, a fun��o FILE ta criada j�
	file = fopen(arquivo, "w"); // abre o arquivoe faz um arquivo novo, write
	fprintf(file, "CPF: ");
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Cadastre aqui o seu nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Nome: ");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Cadastre aqui o seu sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Sobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Cadastre aqui o seu cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Cargo: ");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	system ("cls");
	
	int final=0;
	
	printf("Deseja cadastrar um novo usu�rio?\n\n");
	printf("\t1 - Sim\n");
	printf("\t2 - N�o\n\n");
	printf("Op��o: ");
	
	scanf("%d", &final);
		
		system("cls");
		
		switch(final)
		{
			case 1:
				registro();
			break;
			
			case 2:
				main();
			break;
			
			default:
				printf("Op��o inv�lida, volte ao menu\n\n");
				system("pause");
			break;
		}
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem do programa

	char cpf[11];
	char conteudo[200];
	
	printf("Digite o CPF que deja consultar: ");
	scanf("%s", cpf);
	
	FILE *file; 
	file = fopen (cpf, "r"); // consultar e ler o arquivo cpf
	
	if(file == NULL)
	{
		int escolha=0;
		
		printf("Arquivo n�o localizado");
		printf("\nEscolha:");
		printf("\n\t1 - Fazer uma nova consulta");
		printf("\n\t2 - Cadastrar usu�rio n�o encontrado\n\n");
		printf("Op��o: ");
		
		scanf("%d", &escolha);
		
		system("cls");
		
		switch(escolha)
		{
			case 1:
				consulta();
			break;
			
			case 2:
				registro();
			break;
			
			default:
				printf("Op��o inv�lida, volte ao menu\n\n");
				system("pause");
			break;
		}
	
	}
	
	while(fgets(conteudo, 200, file) != NULL) // enquanto -while- a m�quina busca o arquivo -fgets- e estiver escrevendo na string conte�do at� 200 valores, enquanto tiver informa��o
	{
		printf("\n");
		printf("%s", conteudo);
		printf("\n");
	}
	
	system ("pause");
}

int deletar()
{
	char cpf[11];
	
	printf("Digite o CPF do usu�rio que deseja deletar: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o encontrado. \n");
		system("pause");
	}
	
	else
	{
		int del=0;
		
		remove(cpf);
		printf("Usu�rio deletado com sucesso!\n");
		system("pause");
		
		system("cls");
		
		printf("Deseja deletar algum outro usu�rio?\n");
		printf("\t1 - Sim\n");
		printf("\t2 - N�o\n\n");
		printf("Op��o: ");
		
		scanf("%d", &del);
		
		system("cls");
		
		switch(del)
		{
			case 1:
				deletar();
			break;
			
			case 2:
				main();
			break;
			
			default:
				printf("Op��o inv�lida, volte ao menu\n\n");
				system("pause");
			break;
		}
	}
}
	

int main()
{
	int opcao=0;  // definindo vari�veis
	int repet=1;
	
	for(repet=1;repet=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); // definindo a linguagem do programa
	
		printf("*** Cart�rio da EBAC ***\n\n"); // in�cio do menu
	
		printf("Escolha a op��o desejadada no menu abaixo:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n"); 
		printf("Op��o: "); // final do menu
	
		scanf("%d", &opcao); // scanf vai escanear o que o usu�rio coloca, e o %d � para armazenar uma vari�vel inteiro
	
		system("cls"); // limpa a tela ap�s a escolha
		
		switch (opcao)
		{
			case 1:
				registro();
			break;
			
			case 2:
				consulta();
			break;
			
			case 3:
				deletar();
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema\nAt� mais!\n\n");
				return 0;
			break;
			
			default:
				printf("Op��o inv�lida, volte ao menu\n\n");
				system("pause");
			break;
		}
				
	}
}
