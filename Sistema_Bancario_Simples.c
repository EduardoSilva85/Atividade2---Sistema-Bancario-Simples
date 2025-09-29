#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Disciplina : [Algoritmos e Pensamento Computacional]
// Professor  : Angela Perez Barcellos
// Descrição  : Sistema bancário simples com autenticação por senha 
// Autor(a)   : Eduardo Silva do Nascimento
// Data atual : 27/09/2025

void exibirMenu() {
//Função responsável por exibir o menu de opções do sistema;
    printf("\n=== Selecione o número da opção ===\n");
    printf("\n1. Consultar Saldo\n");
    printf("2. Depositar\n");
    printf("3. Sacar\n");
    printf("4. Sair\n");
    printf("\nEscolha uma opção: ");
}

int main(){

    char senha[10];
    int s_valida = 0;
	
//Mensagem inicial de boas-vindas;
    printf("\n=================================\n");
    printf("=  SEJA BEM-VINDO AO BANCO ESN  =\n");
    printf("=================================\n");
    
    printf("\nNo sistema do Banco ESN, será possivel Consultar Saldo, Depositar e Sacar.\n");
    
//Usando as estruturas de while, if, for, strlen e isdigit;
//Loop para validação da senha, garantindo que tenha 4 dígitos e apenas números;
    while(!s_valida) {
        
        printf("\nPara continuarmos crie sua senha com 4 digitos numéricos: \n");
        scanf("%s", senha);
        
        if (strlen(senha) != 4){
            printf("Erro: a senha deve ter exatamente 4 digitos.\n");
            continue; //Volta ao início do while se a senha não tiver 4 dígitos;
        }
        
        int i, apenasNumeros = 1;
        for (i = 0; i < 4; i++){
            if (!isdigit(senha[i])) {
                apenasNumeros = 0; //Verifica se cada caractere é um número;
                break;
            }
        }
        
        if (!apenasNumeros) {
            printf("Erro: a senha deve conter apenas Números.\n");
        } else {
            s_valida = 1; // Se Senha for válida, sai do loop;
        }
    }
    
    printf("\n==============================\n");
    printf("=  SENHA CRIADA COM SUCESSO  =\n");
    printf("==============================\n");
    
//Acesso com a senha que foi criada, fazendo a comparação da validação com a senha criada. Usando as estruturas de while e strcmp;
//Validação de login com a senha criada anteriormente;
	char verificacao[10];
	
	printf("Digite sua senha: \n");
	scanf(" %s", verificacao);
	  
    while (strcmp(verificacao, senha) != 0) { 
	    
	    //Compara as senhas; se diferente, solicita novamente;
	    printf("Erro: senha incorreta! Tente novamente.\n");
	    printf("\nDigite novamente sua senha de 4 digitos: \n");
	    scanf(" %s", verificacao);
	    
	}
	    
    printf("\n\t\t=== Acesso Liberado ===\t\t\n");
    printf("===============================================\n");

//Apresentação do menu com uso de switch, do-while, if, else, tolower (para verificação de saida y ou n maiusculo ou minuscula);
//Loop principal do sistema, permite realizar várias operações até o usuário decidir sair;
    
    int opcao;
    float saldo = 100.0; //Saldo inicial do usuário;
    float valor;
    char continuar = 'y';
    
    do {
        exibirMenu(); //Chama a função que exibe o menu;
        scanf("%d", &opcao);
            
        switch (opcao) { //Switch para tratar cada opção do menu;
            case 1: {
            //Consulta saldo;
                printf("Seu saldo atual é: R$ %.2f\n", saldo);
                break;
            }
            case 2:{
            //Depósito;
                printf("Digite o valor para depósito: R$ ");
                   
                float temp;
                if (scanf("%f", &temp) != 1) {
                //Validação para apenas números;
                    printf("Entrada inválida! Digite apenas números.\n");
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF); // limpa buffer;
                    break; // volta ao menu sem alterar saldo;
                }
                    
                int c;
                while ((c = getchar()) != '\n' && c != EOF); // limpa buffer;
                    
                char verificacao[10];
                	
                printf("Digite sua senha: \n");
                scanf(" %s", verificacao);
                
                while (strcmp(verificacao, senha) != 0) { 
                    
                    //Compara as senhas; se diferente, solicita novamente;
                    printf("Erro: senha incorreta! Tente novamente.\n");
                    printf("\nDigite novamente sua senha de 4 digitos: \n");
                    scanf(" %s", verificacao);
                }    
                 
                if (temp <= 0) {
                    printf("Valor inválido! O depósito deve ser maior que zero.\n");
                } else {
                    saldo += temp; //Atualiza saldo;
                    printf("Depósito realizado com sucesso! Seu saldo atual é: R$%.2f\n", saldo);
                }
                break;
            }
            case 3: { 
                //Saque;
                printf("Digite o valor para saque: R$ ");
                    
                float temp;
                if (scanf("%f", &temp) != 1) {
                    //Validação para apenas números;
                    printf("Entrada inválida! Digite apenas números.\n");
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);
                    break;
                }
                    
                int c;
                while ((c = getchar()) != '\n' && c != EOF); // limpa buffer;
                    
                char verificacao[10];
                	
                printf("Digite sua senha: \n");
                scanf(" %s", verificacao);
                
                while (strcmp(verificacao, senha) != 0) { 
                    
                    //Compara as senhas; se diferente, solicita novamente;
                    printf("Erro: senha incorreta! Tente novamente.\n");
                    printf("\nDigite novamente sua senha de 4 digitos: \n");
                    scanf(" %s", verificacao);
                }    
                   
                if (temp <= 0) {
                    printf("Valor inválido! O saque deve ser maior que zero.\n");
                } else if (temp > saldo) {
                    printf("Saldo insuficiente! Seu saldo atual é: R$%.2f\n", saldo);
                } else {
                    saldo -= temp; //Atualiza saldo após saque;
                    printf("Saque realizado com sucesso! Seu saldo atual é: R$%.2f\n", saldo);
                }
                break;
            }
            case 4: {
                //Finaliza o Programa;
                printf("Programa finalizado. Obrigado por usar o sistema do banco ESN!");
                continuar = 'n'; //Encerra o loop do menu;
                return 1;
            }
            default :{
                //Para qualquer outro caractere fora do menu, mensagem de inválida;
                printf("Opção inválida! tente novamente.\n");
            }
        }     
        if (opcao != 4) {
            //Pergunta ao usuário se deseja continuar usando o sistema;
            do {
                printf("\nDeseja realizar outras operações? (y/n): ");
                scanf(" %c", &continuar);
                continuar = tolower(continuar); //Converte para minúscula;
                
                int c;
                while ((c = getchar()) != '\n' && c != EOF); // limpa buffer;
                
                if (continuar != 'y' && continuar != 'n') {
                    printf("Entrada inválida! Digite apenas 'y' para sim ou 'n' para não.\n");
                }
                
            } while (continuar != 'y' && continuar != 'n'); //Repete até que seja digitado y ou n;
        }
    } while (continuar == 'y'); //Repete o menu enquanto o usuário desejar;
    
    printf("Programa finalizado. Obrigado por usar o sistema do banco ESN.\n");
    return 0;
}
