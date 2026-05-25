#include <stdio.h>	//biblioteca de comunicação com o usuário
#include <stdlib.h>	//biblioteca de alocação de espaço em memória
#include <locale.h>	//biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//inicio da criação das variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da criação de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado: ");//Coletando informaçõa do usuário
	scanf("%s", cpf); //%s armazena dentro de uma string
	
	strcpy(arquivo, cpf);//Responsável por copiar os valores das strings
	
	FILE * file; //Criando arquivo chamado file
	file = fopen(arquivo, "w"); //acessa o file, abre chamando a variavel arquivo ("w" é de write de ler em inglês)
	fprintf(file, cpf); //Salvo o valor da variavel 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" é de atualizar
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " ");
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");//ele pausa o programa para o usuário conseguir ler e amensagem exibida
}

int consulta()//Função responsável por consultar os usuários no sistema
{
	//Define a linguagem em português para podermos aplicar acentos
	setlocale(LC_ALL, "Portuguese");//definindo a linguagem
	
	//inicio da criação das variáveis/strings
	char cpf[40];
	char conteudo[200];
	//fim da criação das variáveis/strings
	
	printf("Digite o CPF a ser consultado: ");//Coletando informaçõa do usuário
	scanf("%s", cpf);//%s armazena dentro de uma string
	
	FILE * file;//Criando arquivo chamado file
	file = fopen(cpf, "r"); //"r" é de READ (ler em inglês)
	
	if(file == NULL)//Se a função file for exatamente igual a NULO
	{
		printf("Não foi possível abrir o arquivo, não localizado. \n");//mensagem a ser exibida par o usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL)//enquanto ele for diferente de NULO ele continua escrevendo
	{
		printf("\n Essas são as informações do usuário: ");//exibe as informações coletadas do usuário dentro do banco de dados
		printf("%s", conteudo);
		printf("\n\n");//\n pula linha
	}
	
	system("pause");//ele pausa o programa para o usuário conseguir ler e amensagem exibida
	
}

int deletar()//Função responsável por deletar os usuários no sistema
{
	//inicio da criação das variáveis/strings
	char cpf[40];
	//fim da criação das variáveis/strings
	
	
	printf("Digite o CPF do usuário a ser deletado: ");//Coletando informaçõa do usuário
	scanf("%s", cpf);//%s armazena dentro de uma string
	
	remove(cpf);//remove CPF cadastrado 
	
	FILE * file;//Criando arquivo chamado file
	file = fopen(cpf, "r");//"r" é de READ (ler em inglês)
	
	if(file == NULL)//Se a função file for exatamente igual a NULO
	{
		printf("O usuário não se encontra no sistema. \n");//mensagem a ser exibida par o usuário
		system("pause");//ele pausa o programa para o usuário conseguir ler e amensagem exibida
	}
}

int main ()
{
	int opcao=0;//definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");//limpa tudo que está na tela
		
		setlocale(LC_ALL, "Portuguese");//definindo a linguagem
		
		printf("### Cartório da EBAC ### \n\n");//inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");//fim do menu
		
		scanf("%d", &opcao);//armazenando a escolha do usuário
		
		system("cls");//limpa a tela após escolher alguma opção
		
		switch(opcao)//inicio da seleção do menu
		{
			case 1:
			registro();//chamada de funções
			break;
			
			case 2:
			consulta();//chamada de funções
			break;
			
			case 3:
			deletar();//chamada de funções
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema! \n");
			return 0;
			break;	
						
			default :
			printf("\nEssa opção não está disponível!\n\n");
			system("pause");
			break;	
		}	//fim da seleção
	}
}
