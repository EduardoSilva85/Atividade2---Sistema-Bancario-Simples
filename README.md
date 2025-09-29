## SISTEMA BANCÁRIO SIMPLES
\
Iniciei o desenvolvimento para a atividade 2 no dia 27/09 com a ferramenta que gostei bastante por ser online, a ONLINEGDB. Precisei estudar mais algumas bibliotecas para me ajudar no que eu queria proporcionar ao usuário.\
\
1° Adicionei as bibliotecas:
```
#include <stdio.h>
#include <string.h>
#include <ctype.h>
```

2° Planejei fazer um menu com void em que o usuário consiga fazer as opções básicas de um sistema bancário como:
\
**- Consultar Saldo;**

**- Depositar;**

**- Sacar;**

**- Sair.**
\
De acordo com a atividade e o conteúdo, o usuário precisaria ter a opção de ir e voltar no menu ou sair quando quiser.\
\
3° Planejei adicionar uma estrutura para que o usuário cadastre a senha antes de entrar, de forma simples inicialmente, usando as estruturas while, if, for, strlen e isdigit.\
\
4° Após a validação da senha criada, adicionei a estrutura de comparação de strings usando strcmp dentro de um while. Dessa forma, o sistema exige que o usuário insira a senha correta antes de conseguir acessar as funcionalidades do menu. Isso garantiu uma camada simples de segurança inicial, obrigando a digitação correta para liberar o acesso.\
\
5° Depois de validar a entrada no sistema, iniciei a implementação do menu principal utilizando a função exibirMenu() para organizar melhor o código. O menu foi estruturado com o uso de switch dentro de um do-while, permitindo que o usuário navegue entre as opções quantas vezes desejar até escolher a opção de saída.\
\
6° Dentro do switch, desenvolvi as funcionalidades:
\
**- Consultar Saldo:** apenas exibe o saldo atual armazenado na variável saldo.\
\
**- Depositar:** solicita a senha novamente antes de confirmar a operação, garantindo mais segurança. O valor digitado passa por validação (deve ser maior que zero), e só então é somado ao saldo.\
\
**- Sacar:** também solicita a senha novamente antes de liberar a transação. Além disso, o valor passa por duas validações: deve ser maior que zero e não pode ultrapassar o saldo disponível.\
\
**- Sair:** finaliza o programa exibindo uma mensagem de agradecimento.\
\
7° Para evitar entradas inválidas que pudessem travar o sistema, utilizei a limpeza do buffer com:\
```
while ((c = getchar()) != '\n' && c != EOF);
```
Isso garantiu que, após qualquer entrada incorreta, o programa retornasse corretamente para o menu.\
\
8° Também implementei a funcionalidade de perguntar ao usuário se deseja realizar outra operação após cada execução. Para isso, usei a função tolower, que permite aceitar tanto ‘Y/N’ maiúsculo quanto ‘y/n’ minúsculo, dentro de um do-while de validação.\
\
9° Finalizei o sistema com mensagens de feedback claras ao usuário em cada etapa, como: confirmação de depósitos e saques, saldo insuficiente, senha incorreta e agradecimentos ao sair.\
\
### Conclusão:\
\
Com o desenvolvimento desta atividade, pude praticar e aplicar diversas estruturas da linguagem C em um mesmo sistema. Entre elas, utilizei:\
\
**Bibliotecas:** stdio.h, string.h e ctype.h, fundamentais para entradas e saídas, manipulação de strings e validações de caracteres.
\
**Estruturas de repetição:** while, do-while e for, para loops de validação, repetição do menu e checagem de caracteres da senha.
\
**Estruturas condicionais:** if, else if, else, para validar entradas e controlar o fluxo do programa.
\
**Switch-case:** que deixou o menu mais organizado e simplificou o tratamento das funcionalidades.
\
**Função exibirMenu():** ajudou a modularizar e organizar o código.
\
**Validação de strings:** strlen, isdigit e strcmp, que garantiram verificações e comparações seguras.
\
**Tratamento de entradas:** limpeza de buffer (getchar()), evitando travamentos.
\
**tolower():** aceitando diferentes formas de entrada (‘Y/y’ e ‘N/n’).
\
**Reforço de segurança:** solicitação da senha não só no login, mas também em saques e depósitos, reforçando a lógica de proteção das operações.
\
Com todas essas estruturas, aprendi não apenas a criar um programa funcional, mas também a importância da validação de dados para evitar erros, a clareza na interação com o usuário e como combinar diferentes recursos da linguagem C para formar um sistema coeso. Esse exercício me mostrou como é possível evoluir de comandos simples para um projeto mais completo e interativo, que reflete situações do mundo real.
