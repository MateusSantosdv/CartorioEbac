#include <stdio.h> //biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria.
#include <locale.h> //biblioteca de aloca��es de texto por regi�o.
#include <string.h> //biblioteca respons�vel por cuidar das string.

int registro() //fun��o respons�vel por cadastrar o usu�rio no sistema.
{
	//in�cio da cria��o das vari�veis/string.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis.
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio.
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string.
	
	FILE *file; //cria o arquivo.
	file = fopen(arquivo, "w"); //cria o arquivo.
	fprintf(file,cpf); // salva o valor da vari�vel.
	fclose(file); //fecha o arquivo.
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //Coletando o nome do usu�rio.
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //atualizando o arquivo com o nome.
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualizando o arquivo com ",".
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome: "); //Coletando o sobrenome do usu�rio.
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //atualizando o arquivo com o sobrenome.
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualizando o arquivo com ",".
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo: "); //Coletando o cargo do usu�rio.
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //atualizando o arquivo com o cargo.
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualizando o arquivo com ",".
	fprintf(file,",");
	fclose(file);
	
	system("pause");
}

int consulta() //Fun��o respons�vel pela consulta de usu�rios no sistema.
{
	setlocale(LC_ALL,"Portuguese"); //definindo o idioma.
	
	//In�cio da cria��o de vi�veis.
	char cpf[40];
	char conteudo[200];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da cria��o de vari�veis.
	
	printf("Digite o cpf a ser consultado: "); //Coletando o CPF para consulta.
	scanf("%s",cpf);
	
	FILE *file; //Abertura de leitura do arquivo do CPF.
	file = fopen(cpf,"r");
	
	if(file == NULL) //Conferindo se o CPF est� cadastrado no sistema.
	{
		printf("\nCPF n�o cadastrado\n\n"); //Resultado para CPF n�o cadastrado.
	}

	while(fgets(conteudo, 200, file) != NULL) //Resultado para CPF j� cadastrado.
	{
		sscanf(conteudo, "%[^,],%[^,],%[^,],%[^,]", cpf, nome, sobrenome, cargo);
		printf("\nCPF: %s ", cpf);
		printf("\nNome: %s", nome);
		printf("\nSobrenome: %s", sobrenome);
		printf("\nCargo: %s", cargo);
		printf("\n\n");
	}
	system("pause");
	
} //Fim da fun��o

int excluir() //Fun��o respons�vel por excluir usu�rios do sistema.
{
	//in�cio da cria��o de vari�veis.
	char cpf[40];
	//Fim da cria��o de vari�veis.
		
	printf("Digite o CPF para excluir: "); //Coletando o CPF a ser exclu�do.
	scanf("%s", cpf);
	
	FILE *file; //Abertura e leitura do arquivo com o CPF.
	file = fopen(cpf,"r");

	if(file == NULL) //Conferindo se o CPF est� cadastrado no sistema.
	{
		printf("\nCPF n�o cadastrado.\n\n"); //Resposta para CPF n�o cadastrado.
		system("pause");
	}
	else //Resposta para CPF j� cadastrado.
	{
		fclose(file);
		remove(cpf);
		printf("\nUsu�rio exclu�do com sucesso!\n\n");
		system("pause");
	}
	
} //Fim da fun��o.

int main()
{
	int opcao=0; //definindo vari�veis.
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL,"Portuguese"); //definindo o idioma.
	
		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu.
		printf("Escolha a op��o desejada de menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Excluir nomes\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Op��o: "); //fim do menu.
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio.
	
		system("cls"); //Respons�vel por limpar a tela.
		
		switch(opcao) //In�cio da sele��o do menu.
		{
			case 1:
				registro(); //chamada de fun��es.
			break;
			
			case 2:
				consulta();
			break;
			
			case 3:
				excluir();
			break;
			
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
			break;
			
			default:
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
			break;	
			
		} //Fim da sele��o do menu.
	
	}
}


