#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das strings

// \t vai ser utilizado para dar espa�amentos.
// \n vai pular linhas de c�digos.
// system("cls") = limpar tela
// scanf("%d", &opcao); = escaneia o n�mero inteiro (%d) para selecionar uma op��o (&opcao)
// printf ("(texto)"); = print "fala", mensagem do computador
// string � um conjunto de variaveis
// while = enquanto
// != igual a diferente ? != NULL / diferente de nulo
// fgets = buscar arquivo
//char = armazena valores inteiros

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/strings
	char arquivo[40]; 
	char cpf[40];
	char nome[50];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de vari�veis/strings
	
	printf("Digite o CPF para cadastrar: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; // cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); // cria o arquivo  na pasta "file" || "w" = write/ escreve um novo arquivo
	fprintf(file,cpf); // Salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,","); // "," � usada para separar e incluir mais informa��es
	fclose(file);
	
		printf("Digite o nome para cadastrar: ");
		scanf("%s", nome);
		
		file = fopen(arquivo, "a"); // "a" = apply/atualiza��o / atualiza o arquivo existente
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o sobrenome para cadastrar: ");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo, "a"); // "a" = apply/atualiza��o / atualiza o arquivo existente
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
	
		printf("Digite o seu cargo: ");
		scanf("%s", cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
		system("pause");
}

int consulta()
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	FILE *file;
	file = fopen(cpf, "r"); // "r" = read / ler o arquivo
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL); 
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n\n");
		system("pause");
	}
	
		else
		{
			fclose(file);
		
		if(remove(cpf) == 0) //tenta remover o arquivo ao cpf
		{
			printf("\nUsu�rio deletado com sucesso!\n\n");
			system("pause");
		}
		
		else
		{
			printf("\nErro ao deletar o usu�rio.\n\n");
			system("pause");
		}
	}
}

int main()
{
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
 		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
 		printf("Escolha a op��o desejada do menu: \n\n");
 		printf("\t1 - Registrar nomes\n");
 		printf("\t2 - Consultar nomes\n");
 		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); //final do menu
 	
 		scanf("%d", &opcao); //armazenando informa��es (escolha do usu�rio)
 	
 		system("cls"); //apaga informa��es do console
 		
 		switch(opcao) //inicio da sele��o do menu
 		{
 			case 1:
 			registro();
			break; //quebra de c�digo
			
			case 2:
			consulta(); //chamada de fun��es
 			break;
 			
 			case 3:
			deletar(); 	
			break;

			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
		} //fim da sele��o
	}
}
