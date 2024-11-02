#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca respons�vel pela aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

//as bibliotecas precisam ser inseridas primeiro

int registro()//Fun��o resposn�vel por inserir o usu�rio no sistema
{
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //colentando informa��o dos usu�rios
	scanf("%s", cpf); //%s refere-se � strings
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das trings
	
	FILE *file; //cria o arquivo no Banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo e escreve informa��es
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e atuliza o arquivo
	fprintf(file, ", "); //coloca uma v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //colentando informa��o dos usu�rios
	scanf("%s",nome); //%s refere-se � strings
	
	file = fopen(arquivo, "a"); //abre o arquivo e atuliza o arquivo
	fprintf(file,nome); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e atuliza o arquivo
	fprintf(file, ", "); //coloca uma v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //colentando informa��o dos usu�rios
	scanf("%s",sobrenome); //%s refere-se � strings
	
	file = fopen(arquivo, "a"); //abre o arquivo e atuliza o arquivo
	fprintf(file,sobrenome); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e atuliza o arquivo
	fprintf(file, ", "); //coloca uma v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo); //salvo o valor da vari�vel
	
	file = fopen(arquivo, "a"); //abre o arquivo e atuliza o arquivo
	fprintf(file,cargo); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e atuliza o arquivo
	fclose(file); //fecha o arquivo
	
	system("pause");
}

int consulta() //realiza consulta das informa��es
{
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem;
	
	char cpf[40]; 
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //colentando informa��o dos usu�rios
	scanf("%s",cpf); //salvo o valor da vari�vel
	
	FILE *file; //seleciona o arquivo no Banco de dados
	file = fopen(cpf,"r"); //abre o arquivo e faz a leitura
	
	if(file == NULL) //se o resultado for algum n�mero n�o existente:
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n"); 
	}
	
	while(fgets(conteudo, 200, file) != NULL) //instru��es para demonstrar o resultado
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //retorno da consulta
		printf("%s", conteudo); //salvo o valor da vari�vel
		printf("\n\n"); //espa�o ao final do texto
	}
	
	system("pause");
	
}

int deletar() //exclui as informa��es do usu�rio
{
	char cpf[40]; //defini��o da vari�vel
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //colentando informa��o dos usu�rios
	scanf("%s",cpf); //salvo o valor da vari�vel
	
	remove(cpf); //remove o cpf do banco de dados
	 
	
	FILE *file; //seleciona o arquivo
	file = fopen(cpf,"r"); //abre o arquivo selecionado e exclui
		
	if(file == NULL) // se o valor digitado ser algum que n�o consta na base de dados, retonar:
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
	
}


int main ()//Definindo vari�veis
{
	
	int opcao=0; //definindo vari�veis
	int laco=1;
		
	for(laco=1;laco=1;)
	{	
		system("cls"); //respons�vel por limpar a tela
		
				
		setlocale(LC_ALL, "Portuguese");//definindo a linguagem;
	
		printf("### Reposit�rio da EBAC ### \n\n"); //In�cio do menu;
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Excluir Nomes\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Op��o: "); //Fim do menu
		
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
		
		system("cls");
	
		switch(opcao) //in�cio da sele��o do menu
		{
			case 1:
				registro(); //chamada de fun��es			
				break;
				
			case 2:
				consulta(); //chamada de fun��es
				break;
				
			case 3:
				deletar(); //chamada de fun��es
				break;
				
			case 4:
				printf("Obrigada por utilizar o sistema!\n");
				return 0;
				break;
				
						
			default:
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
		} //fim da sele��o
	
	}

}

