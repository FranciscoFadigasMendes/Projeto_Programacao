#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //biblioteca que permite usar acentos e caracteres especiais

void menu_inicial();

struct data {                 // Estruta geral especÃ­fica para as datas
    int dia,mes,ano;
};

struct geral {               //Estrutura que contÃ©m todas as variÃ¡veis
    int add_numero_id;
    char designacao[50];
    char nome_colab[50];
    struct data data_atribuicao;
    int estado_computsdor;
    float valor_equipamento;
    char codigo_int[50];
    int numero_id;
    struct data data_pedido;
    char descricao[200];
};
//------------------------------------------------------

int main()
{
int selecao_inicial;

    menu_inicial();

return 0;
}

//------------------------------------------------------

void menu_inicial()
{

setlocale(LC_ALL, "Portuguese"); //AVISO-------------TENTAR POR A ACEITAR ACENTOS E CARACTEREES

printf("\n\t\t\t\t\tGestão de Computadores Portáteis\n\n");
printf("Total de Computadores:(memoria a defenir)\t\t\t");
printf("Valor dos Computadores(euros):(memoria a defenir)\n");
printf("Intervenções Solicitadas:\t\t\t\t\t");
printf("Intervenções Efetuadas:(memoria a defenir)\n\n");

printf("1. Novo Computador\n");
printf("2. Solicitar Intervenção\n");
printf("3. Registar Intervenção\n");
printf("4. Listar\n");
printf("5. Informações\n");
printf("6. Gravar\n");
printf("0. Sair\n");
printf("\t\tSelecione a Opção:(memoria a defenir)");

}

