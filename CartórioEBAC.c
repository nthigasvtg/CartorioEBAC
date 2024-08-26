#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca responsável por cuidar das strings

// \t vai ser utilizado para dar espaçamentos.
// \n vai pular linhas de códigos.
// system("cls") = limpar tela
// scanf("%d", &opcao); = escaneia o número inteiro (%d) para selecionar uma opção (&opcao)
// printf ("(texto)"); = print "fala", mensagem do computador
// string é um conjunto de variaveis
// while = enquanto
// != igual a diferente ? != NULL / diferente de nulo
// fgets = buscar arquivo
//char = armazena valores inteiros

int registro() //função responsável por cadastrar os usuários no sistema
{
	//início criação de variáveis/strings
	char arquivo[40]; 
	char cpf[40];
	char nome[50];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/strings
	
	printf("Digite o CPF para cadastrar: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; // cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); // cria o arquivo  na pasta "file" || "w" = write/ escreve um novo arquivo
	fprintf(file,cpf); // Salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,","); // "," é usada para separar e incluir mais informações
	fclose(file);
	
		printf("Digite o nome para cadastrar: ");
		scanf("%s", nome);
		
		file = fopen(arquivo, "a"); // "a" = apply/atualização / atualiza o arquivo existente
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o sobrenome para cadastrar: ");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo, "a"); // "a" = apply/atualização / atualiza o arquivo existente
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
		printf("Não foi possível abrir o arquivo, não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL); 
	{
		printf("\nEssas são as informações do usuário: ");
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
		printf("O usuário não se encontra no sistema!\n\n");
		system("pause");
	}
	
		else
		{
			fclose(file);
		
		if(remove(cpf) == 0) //tenta remover o arquivo ao cpf
		{
			printf("\nUsuário deletado com sucesso!\n\n");
			system("pause");
		}
		
		else
		{
			printf("\nErro ao deletar o usuário.\n\n");
			system("pause");
		}
	}
}

int main()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
 		printf("### Cartório da EBAC ###\n\n"); //início do menu
 		printf("Escolha a opção desejada do menu: \n\n");
 		printf("\t1 - Registrar nomes\n");
 		printf("\t2 - Consultar nomes\n");
 		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); //final do menu
 	
 		scanf("%d", &opcao); //armazenando informações (escolha do usuário)
 	
 		system("cls"); //apaga informações do console
 		
 		switch(opcao) //inicio da seleção do menu
 		{
 			case 1:
 			registro();
			break; //quebra de código
			
			case 2:
			consulta(); //chamada de funções
 			break;
 			
 			case 3:
			deletar(); 	
			break;

			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
		} //fim da seleção
	}
}
