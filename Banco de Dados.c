#include <stdio.h> //Biblioteca de comunica��o com o usuario
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o
#include <string.h> //Biblioteca responsavel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usuarios
{
	//Inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char telefone[40];
	char cep[40];
	//Final cria��o de variaveis/string

	printf("Digite o CPF\n"); //Coletando informa��o do usuario
	scanf("%s", &cpf); //%s refere-se a uma string
	
	strcpy(arquivo, cpf); //Responsavel por criar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //Salva o valor
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Cria o arquivo e o "a" significa atualizar
	fprintf(file,","); //Da espa�o
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome\n"); //Coletando informa��o do usuario
	scanf("%s", &nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o telefone\n"); //Coletando informa��o
	scanf("%s", &telefone);
	
	file = fopen(arquivo, "a");
	fprintf(file,telefone);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o CEP\n"); //Coletando informa��o
	scanf("%s", &cep);
	
	file = fopen(arquivo, "a");
	fprintf(file,cep);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	system("pause");
	
}

int consultar()
{
	char cpf[11];
	char conteudo[200];
	
	printf("Digite o CPF desejado\n");
	scanf("%s", &cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF n�o cadastrado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nUsuario cadastrado: ");
		printf("%s", &conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Qual usuario deseja deletar?\n"); //Coleta o CPF a ser apagado
	scanf("%s", &cpf);
		
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //usando o IF para caso o usuario n�o esteja registrado
	{
		printf("Usuario inexistente, tente novamente\n");
	}
    else //usando o else caso esteja registrado mostrar a mensagem e deletar
    {
    	remove(cpf); //deleta o usuario
    	printf("Usuario deletado com sucesso\n");
	}

	system("pause");
	
}

int main()
{
	int opcao=0; //Definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	    
		system("cls");
	
        setlocale(LC_ALL,"portuguese"); //Definindo linguagem

	    printf("*** Banco de dados ***\n\n"); //Inicio do menu
	    printf("Escolha a op��o do menu desejada:\n\n");
	    printf("\t1 - Registrar usu�rio\n");
	    printf("\t2 - Consultar usu�rio\n");
	    printf("\t3 - Deletar usu�rio\n");
	    printf("\t4 - Sair\n\n");
	    printf("Como posso te ajudar? "); //Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usuario
	
	    system("cls"); //responsavel por limpar a tela
	
	switch(opcao) //inicio da sele��o
	  {
	  	case 1:
	  	    registro(); //chamada de fun��es
		    break;
		
		case 2:
		    consultar();
	        break;
	    
	    case 3:
	        deletar();
    	    break;
    	    
    	case 4:
    		printf("Volte sempre\n");
    		return 0;
    		break;
    		
    	default:
            printf("Est� op��o � invalida, tente novamente\n");
    	    system("pause");
    	    break;
	  } //fim da sele��o

    }
    

}
