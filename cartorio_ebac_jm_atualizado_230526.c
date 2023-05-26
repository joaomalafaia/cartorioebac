#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória (dados)
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cadastrar as strings

int registro() //função responsável pelo cadastro de usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem do programa
	
	char arquivo[11];
	char cpf[11];  // campos para o cadastro
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Cadastre aqui o seu CPF: "); // coletando as informações do usuário
	scanf("%s", cpf); // %s refere-se à captação de strings
	
	strcpy(arquivo, cpf); // responsável por copiar os valores das strings
	
	FILE *file; //acessa os arquivos e CRIA o arquivos, a função FILE ta criada já
	file = fopen(arquivo, "w"); // abre o arquivoe faz um arquivo novo, write
	fprintf(file, "CPF: ");
	fprintf(file,cpf); //salvo o valor da variável
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
	
	printf("Deseja cadastrar um novo usuário?\n\n");
	printf("\t1 - Sim\n");
	printf("\t2 - Não\n\n");
	printf("Opção: ");
	
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
				printf("Opção inválida, volte ao menu\n\n");
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
		
		printf("Arquivo não localizado");
		printf("\nEscolha:");
		printf("\n\t1 - Fazer uma nova consulta");
		printf("\n\t2 - Cadastrar usuário não encontrado\n\n");
		printf("Opção: ");
		
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
				printf("Opção inválida, volte ao menu\n\n");
				system("pause");
			break;
		}
	
	}
	
	while(fgets(conteudo, 200, file) != NULL) // enquanto -while- a máquina busca o arquivo -fgets- e estiver escrevendo na string conteúdo até 200 valores, enquanto tiver informação
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
	
	printf("Digite o CPF do usuário que deseja deletar: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usuário não encontrado. \n");
		system("pause");
	}
	
	else
	{
		int del=0;
		
		remove(cpf);
		printf("Usuário deletado com sucesso!\n");
		system("pause");
		
		system("cls");
		
		printf("Deseja deletar algum outro usuário?\n");
		printf("\t1 - Sim\n");
		printf("\t2 - Não\n\n");
		printf("Opção: ");
		
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
				printf("Opção inválida, volte ao menu\n\n");
				system("pause");
			break;
		}
	}
}
	

int main()
{
	int opcao=0;  // definindo variáveis
	int repet=1;
	
	for(repet=1;repet=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); // definindo a linguagem do programa
	
		printf("*** Cartório da EBAC ***\n\n"); // início do menu
	
		printf("Escolha a opção desejadada no menu abaixo:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n"); 
		printf("Opção: "); // final do menu
	
		scanf("%d", &opcao); // scanf vai escanear o que o usuário coloca, e o %d é para armazenar uma variável inteiro
	
		system("cls"); // limpa a tela após a escolha
		
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
				printf("Obrigado por utilizar o sistema\nAté mais!\n\n");
				return 0;
			break;
			
			default:
				printf("Opção inválida, volte ao menu\n\n");
				system("pause");
			break;
		}
				
	}
}
