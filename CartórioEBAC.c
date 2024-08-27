#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável pelas strings

int registrar() {
	//início da criação de variáveis e strings
	char arquivo[40]; //cria a variável arquivo, onde serão armazenadas as informações
	char cpf[11]; //cria a variável CPF
	char nome[40]; //cria a variável NOME
	char sobrenome[40]; //cria a variável SOBRENOME
	char cargo[40]; //cria a variável CARGO
	//fim da criação de variáveis e strings

	printf("Digite o CPF a ser registrado: \n\n"); //exibição na tela para o usuário
	scanf("%s", cpf); //%s refere-se a string e o scanf escaneia ela

	strcpy(arquivo, cpf); //strcpy copia os valores das string (por ex copia para a variável arquivo o dado cpf)

	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //fopen abre o arquivo, arquivo do tipo write, arquivo novo, sem dados inseridos
	fprintf(file,cpf); //salva o valor da variável cpf dentro do arquivo file //fprintf = file printf
	fclose(file); //fecha o arquivo

	file = fopen(arquivo, "a"); //comando "a" atualiza os dados do arquivo, (vai inserir mais informações no arquivo); comando "w" cria arquivo novo
	fprintf(file, ", Nome:"); //comando que insere um "vírgula-espaço" entre as informações
	fclose(file); //comando para fechar o arquivo que foi consultado

	printf("\nDigite o nome a ser registrado: \n\n");
	scanf("%s", nome);

	file = fopen(arquivo, "a");
	fprintf(file,nome); //salva o conteúdo da variável nome dentro do arquivo file
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ", Sobrenome:");
	fclose(file);

	printf("\n Digite o sobrenome a ser registrado: \n\n");
	scanf("%s", sobrenome);

	file = fopen(arquivo,"a");
	fprintf(file,sobrenome); //salva o valor da variável sobrenome no arquivo file
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ", Cargo:");
	fclose(file);

	printf("\n Digite o cargo a ser registrado: \n\n");
	scanf("%s", cargo);

	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);

	system("pause"); //aguarda comando do usuário, permitindo que ele leia o que está na tela
}

int consultar() {

	setlocale(LC_ALL, "Portuguese"); //define a linguagem

	char cpf[11]; //consulta será através do CPF cadastrado
	char conteudo[100];

	printf("Digite o CPF a ser consultado: "); 
	scanf("%s",cpf);

	FILE *file;
	file = fopen(cpf,"r"); //abra o arquivo e leia (r) o que está armazenado na variável cpf

	if(file == NULL) { //se o arquivo não existir...
		printf("\nNão foi possivel encontrar o cpf."); //...informar que não foi localizado
	}

	while(fgets(conteudo, 100, file) != NULL) //fgets = vá buscar o arquivo "conteúdo", e enqto ele tiver conteudo na string, não pare

		printf("\nEssas são as informações do usuário:\n\n");
	printf("%s", conteudo);
	printf("\n\n");

	system("pause");

}

int deletar() { //função responsável por deletar dados do banco

	char cpf[11];

	printf("Digite o usuário a ser deletado:");
	scanf("%s",cpf);

	FILE *file;
	file = fopen(cpf,"r"); //abra o arquivo "file", capture a informação de CPF e a leia (r)

	if(file == NULL) { //se o arquivo não for encontrado (usuário não cadastrado), informe:

		printf("\nUsuário não encontrado.\n\n");
		system("pause");
	}

	else {

		remove(cpf); //remove o arquivo
		printf("\nUsuário Deletado.\n\n");
		system("pause");

	}


}

int main()

{
	int opcao=0;  //definindo variáveis
	int laco=1; //criando a variável x para poder usar no comando "for"

	for(laco=1; laco=1;) { //ex: for(x=1;x=10;x++); (faz o cód ser repetido da vez 1 até a vez 10 // x++ acrescenta 1 a x

		system("cls"); //comando para limpar a tela para o usuário

		setlocale(LC_ALL, "Portuguese");//definindo linguagem

		printf("\t### Cartório da EBAC ### \n\n");//começo do menu
		printf("Seleciona uma opção: \n\n");
		printf("\t1 - Registrar nomes \n\n");
		printf("\t2 - Consultar CPF \n\n");
		printf("\t3 - Deletar nomes \n\n");
		printf("\t4 - Sair do programa \n\n");
		printf("Opção: "); //fim do menu

		scanf("%d",&opcao); //armazena a opção do usuário 

		system("cls"); //limpa a tela

		switch(opcao) { //definindo as opções que o usuário pode escolher
			case 1: //se o usuário digitar "1",
				registrar(); //execute a função "registro"
				break; //pare

			case 2:
				consultar();
				break;

			case 3:
				deletar();
				break;
			
			case 4:
				printf("Obrigado por utilizar o sistema");
				return 0;
				break;

			default://ultimo caso
				printf("Opção não existente\n");
				system("pause");
		}


	}
}
