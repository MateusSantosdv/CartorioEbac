#include <stdio.h> //biblioteca de comunicação com o usuário.
#include <stdlib.h> //biblioteca de alocação de espaço em memória.
#include <locale.h> //biblioteca de alocações de texto por região.
#include <string.h> //biblioteca responsável por cuidar das string.

int registro() //função responsável por cadastrar o usuário no sistema.
{
	//início da criação das variáveis/string.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis.
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário.
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string.
	
	FILE *file; //cria o arquivo.
	file = fopen(arquivo, "w"); //cria o arquivo.
	fprintf(file,cpf); // salva o valor da variável.
	fclose(file); //fecha o arquivo.
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //Coletando o nome do usuário.
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //atualizando o arquivo com o nome.
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualizando o arquivo com ",".
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome: "); //Coletando o sobrenome do usuário.
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //atualizando o arquivo com o sobrenome.
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualizando o arquivo com ",".
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo: "); //Coletando o cargo do usuário.
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //atualizando o arquivo com o cargo.
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a"); //atualizando o arquivo com ",".
	fprintf(file,",");
	fclose(file);
	
	system("pause");
}

int consulta() //Função responsável pela consulta de usuários no sistema.
{
	setlocale(LC_ALL,"Portuguese"); //definindo o idioma.
	
	//Início da criação de viáveis.
	char cpf[40];
	char conteudo[200];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Fim da criação de variáveis.
	
	printf("Digite o cpf a ser consultado: "); //Coletando o CPF para consulta.
	scanf("%s",cpf);
	
	FILE *file; //Abertura de leitura do arquivo do CPF.
	file = fopen(cpf,"r");
	
	if(file == NULL) //Conferindo se o CPF está cadastrado no sistema.
	{
		printf("\nCPF não cadastrado\n\n"); //Resultado para CPF não cadastrado.
	}

	while(fgets(conteudo, 200, file) != NULL) //Resultado para CPF já cadastrado.
	{
		sscanf(conteudo, "%[^,],%[^,],%[^,],%[^,]", cpf, nome, sobrenome, cargo);
		printf("\nCPF: %s ", cpf);
		printf("\nNome: %s", nome);
		printf("\nSobrenome: %s", sobrenome);
		printf("\nCargo: %s", cargo);
		printf("\n\n");
	}
	system("pause");
	
} //Fim da função

int excluir() //Função responsável por excluir usuários do sistema.
{
	//início da criação de variáveis.
	char cpf[40];
	//Fim da criação de variáveis.
		
	printf("Digite o CPF para excluir: "); //Coletando o CPF a ser excluído.
	scanf("%s", cpf);
	
	FILE *file; //Abertura e leitura do arquivo com o CPF.
	file = fopen(cpf,"r");

	if(file == NULL) //Conferindo se o CPF está cadastrado no sistema.
	{
		printf("\nCPF não cadastrado.\n\n"); //Resposta para CPF não cadastrado.
		system("pause");
	}
	else //Resposta para CPF já cadastrado.
	{
		fclose(file);
		remove(cpf);
		printf("\nUsuário excluído com sucesso!\n\n");
		system("pause");
	}
	
} //Fim da função.

int main()
{
	int opcao=0; //definindo variáveis.
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL,"Portuguese"); //definindo o idioma.
	
		printf("### Cartório da EBAC ###\n\n"); //início do menu.
		printf("Escolha a opção desejada de menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Excluir nomes\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Opção: "); //fim do menu.
	
		scanf("%d", &opcao); //armazenando a escolha do usuário.
	
		system("cls"); //Responsável por limpar a tela.
		
		switch(opcao) //Início da seleção do menu.
		{
			case 1:
				registro(); //chamada de funções.
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
				printf("Essa opção não está disponível!\n");
				system("pause");
			break;	
			
		} //Fim da seleção do menu.
	
	}
}


