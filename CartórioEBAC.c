#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas strings

int registrar() {
	//in�cio da cria��o de vari�veis e strings
	char arquivo[40]; //cria a vari�vel arquivo, onde ser�o armazenadas as informa��es
	char cpf[11]; //cria a vari�vel CPF
	char nome[40]; //cria a vari�vel NOME
	char sobrenome[40]; //cria a vari�vel SOBRENOME
	char cargo[40]; //cria a vari�vel CARGO
	//fim da cria��o de vari�veis e strings

	printf("Digite o CPF a ser registrado: \n\n"); //exibi��o na tela para o usu�rio
	scanf("%s", cpf); //%s refere-se a string e o scanf escaneia ela

	strcpy(arquivo, cpf); //strcpy copia os valores das string (por ex copia para a vari�vel arquivo o dado cpf)

	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //fopen abre o arquivo, arquivo do tipo write, arquivo novo, sem dados inseridos
	fprintf(file,cpf); //salva o valor da vari�vel cpf dentro do arquivo file //fprintf = file printf
	fclose(file); //fecha o arquivo

	file = fopen(arquivo, "a"); //comando "a" atualiza os dados do arquivo, (vai inserir mais informa��es no arquivo); comando "w" cria arquivo novo
	fprintf(file, ", Nome:"); //comando que insere um "v�rgula-espa�o" entre as informa��es
	fclose(file); //comando para fechar o arquivo que foi consultado

	printf("\nDigite o nome a ser registrado: \n\n");
	scanf("%s", nome);

	file = fopen(arquivo, "a");
	fprintf(file,nome); //salva o conte�do da vari�vel nome dentro do arquivo file
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ", Sobrenome:");
	fclose(file);

	printf("\n Digite o sobrenome a ser registrado: \n\n");
	scanf("%s", sobrenome);

	file = fopen(arquivo,"a");
	fprintf(file,sobrenome); //salva o valor da vari�vel sobrenome no arquivo file
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

	system("pause"); //aguarda comando do usu�rio, permitindo que ele leia o que est� na tela
}

int consultar() {

	setlocale(LC_ALL, "Portuguese"); //define a linguagem

	char cpf[11]; //consulta ser� atrav�s do CPF cadastrado
	char conteudo[100];

	printf("Digite o CPF a ser consultado: "); 
	scanf("%s",cpf);

	FILE *file;
	file = fopen(cpf,"r"); //abra o arquivo e leia (r) o que est� armazenado na vari�vel cpf

	if(file == NULL) { //se o arquivo n�o existir...
		printf("\nN�o foi possivel encontrar o cpf."); //...informar que n�o foi localizado
	}

	while(fgets(conteudo, 100, file) != NULL) //fgets = v� buscar o arquivo "conte�do", e enqto ele tiver conteudo na string, n�o pare

		printf("\nEssas s�o as informa��es do usu�rio:\n\n");
	printf("%s", conteudo);
	printf("\n\n");

	system("pause");

}

int deletar() { //fun��o respons�vel por deletar dados do banco

	char cpf[11];

	printf("Digite o usu�rio a ser deletado:");
	scanf("%s",cpf);

	FILE *file;
	file = fopen(cpf,"r"); //abra o arquivo "file", capture a informa��o de CPF e a leia (r)

	if(file == NULL) { //se o arquivo n�o for encontrado (usu�rio n�o cadastrado), informe:

		printf("\nUsu�rio n�o encontrado.\n\n");
		system("pause");
	}

	else {

		remove(cpf); //remove o arquivo
		printf("\nUsu�rio Deletado.\n\n");
		system("pause");

	}


}

int main()

{
	int opcao=0;  //definindo vari�veis
	int laco=1; //criando a vari�vel x para poder usar no comando "for"

	for(laco=1; laco=1;) { //ex: for(x=1;x=10;x++); (faz o c�d ser repetido da vez 1 at� a vez 10 // x++ acrescenta 1 a x

		system("cls"); //comando para limpar a tela para o usu�rio

		setlocale(LC_ALL, "Portuguese");//definindo linguagem

		printf("\t### Cart�rio da EBAC ### \n\n");//come�o do menu
		printf("Seleciona uma op��o: \n\n");
		printf("\t1 - Registrar nomes \n\n");
		printf("\t2 - Consultar CPF \n\n");
		printf("\t3 - Deletar nomes \n\n");
		printf("\t4 - Sair do programa \n\n");
		printf("Op��o: "); //fim do menu

		scanf("%d",&opcao); //armazena a op��o do usu�rio 

		system("cls"); //limpa a tela

		switch(opcao) { //definindo as op��es que o usu�rio pode escolher
			case 1: //se o usu�rio digitar "1",
				registrar(); //execute a fun��o "registro"
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
				printf("Op��o n�o existente\n");
				system("pause");
		}


	}
}
