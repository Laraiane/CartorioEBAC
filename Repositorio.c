#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca responsável pela alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

//as bibliotecas precisam ser inseridas primeiro

int registro()//Função resposnável por inserir o usuário no sistema
{
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //colentando informação dos usuários
	scanf("%s", cpf); //%s refere-se à strings
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das trings
	
	FILE *file; //cria o arquivo no Banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo e escreve informações
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e atuliza o arquivo
	fprintf(file, ", "); //coloca uma vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //colentando informação dos usuários
	scanf("%s",nome); //%s refere-se à strings
	
	file = fopen(arquivo, "a"); //abre o arquivo e atuliza o arquivo
	fprintf(file,nome); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e atuliza o arquivo
	fprintf(file, ", "); //coloca uma vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //colentando informação dos usuários
	scanf("%s",sobrenome); //%s refere-se à strings
	
	file = fopen(arquivo, "a"); //abre o arquivo e atuliza o arquivo
	fprintf(file,sobrenome); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e atuliza o arquivo
	fprintf(file, ", "); //coloca uma vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo); //salvo o valor da variável
	
	file = fopen(arquivo, "a"); //abre o arquivo e atuliza o arquivo
	fprintf(file,cargo); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e atuliza o arquivo
	fclose(file); //fecha o arquivo
	
	system("pause");
}

int consulta() //realiza consulta das informações
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem;
	
	char cpf[40]; 
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //colentando informação dos usuários
	scanf("%s",cpf); //salvo o valor da variável
	
	FILE *file; //seleciona o arquivo no Banco de dados
	file = fopen(cpf,"r"); //abre o arquivo e faz a leitura
	
	if(file == NULL) //se o resultado for algum número não existente:
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n"); 
	}
	
	while(fgets(conteudo, 200, file) != NULL) //instruções para demonstrar o resultado
	{
		printf("\nEssas são as informações do usuário: "); //retorno da consulta
		printf("%s", conteudo); //salvo o valor da variável
		printf("\n\n"); //espaço ao final do texto
	}
	
	system("pause");
	
}

int deletar() //exclui as informações do usuário
{
	char cpf[40]; //definição da variável
	
	printf("Digite o CPF do usuário a ser deletado: "); //colentando informação dos usuários
	scanf("%s",cpf); //salvo o valor da variável
	
	remove(cpf); //remove o cpf do banco de dados
	 
	
	FILE *file; //seleciona o arquivo
	file = fopen(cpf,"r"); //abre o arquivo selecionado e exclui
		
	if(file == NULL) // se o valor digitado ser algum que não consta na base de dados, retonar:
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
	
}


int main ()//Definindo variáveis
{
	
	int opcao=0; //definindo variáveis
	int laco=1;
		
	for(laco=1;laco=1;)
	{	
		system("cls"); //responsável por limpar a tela
		
				
		setlocale(LC_ALL, "Portuguese");//definindo a linguagem;
	
		printf("### Repositório da EBAC ### \n\n"); //Início do menu;
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Excluir Nomes\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Opção: "); //Fim do menu
		
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls");
	
		switch(opcao) //início da seleção do menu
		{
			case 1:
				registro(); //chamada de funções			
				break;
				
			case 2:
				consulta(); //chamada de funções
				break;
				
			case 3:
				deletar(); //chamada de funções
				break;
				
			case 4:
				printf("Obrigada por utilizar o sistema!\n");
				return 0;
				break;
				
						
			default:
				printf("Essa opção não está disponível!\n");
				system("pause");
				break;
		} //fim da seleção
	
	}

}

