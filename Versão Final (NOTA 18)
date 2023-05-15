#include <stdio.h>
#include <stdlib.h>
#define N_PC 25

typedef struct {
    int id;
    char int_code[100][50];
    char description[100];
    char collaborator[50];
    int date[3];
    int i_date[100][3];
    int s_date[100][3];
    int status;
    float value;
    char summary[100][200];
    char summary_int[200];
    float int_cost;
    int pending;
    int finished;
}computer_info;

//--------------------Protipos de Vetores-------------------
void menu(computer_info computers[]);
int opc_menu(int opc,computer_info computers[]);
void add_computer(computer_info computers[]);
void solicitar_intervencao(int pc,computer_info computers[]);
void registar_intervencao(computer_info computers[]);
void list(computer_info computers[]);
void info(computer_info computers[]);
void gravar();
void test(int opc, computer_info computers[]);

//---------------------Variáveis globais--------------------
int counter[3]; // vetor de contadores

//------------------------------------------------------
//------------------------------------------------------

int main()
{
    int opc;
    FILE *fptr;
    computer_info computers[N_PC];

    for(int i=0;i<N_PC;i++){         //iniciliza todas as variáveis a 0
            for(opc=0;opc<9;opc++){
                computers[i].date[opc]=0;
                };
                computers[i].id = 0;
                computers[i].status = 0;
                computers[i].value = 0;
                computers[i].int_cost = 0;
                computers[i].pending = 0;
    };

    fptr = fopen("program.bin","rb");

        if ((fptr = fopen("program.bin","rb")) == NULL){
            printf("\nNovo registo\n");}
        else
        {
            fread(counter, sizeof(counter), 3, fptr);
            fread(computers, sizeof(computer_info), 25, fptr);
            }
    fclose(fptr);

    do{
        menu(computers);

        fflush(stdin);
        scanf("%d",&opc);

        opc_menu(opc,computers);

        printf("\n\n---------------------------------------------------------------");
    }
    while(opc!=0);


return 0;
}
//------------------------------------------------------
//---------------Funcões Secundárias--------------------

void menu(computer_info computers[])                 //Função que imprime o display do menu principal
{
   int i;
   float total_value=0;
   for(i=0;i<N_PC;i++){total_value += computers[i].value;} //contador para somar o valor total dos PC's criados

printf("\n\n\n\n\t\t\tGestao de Computadores Portateis\n\n");
printf("Total de Computadores: %d\t\t\t",counter[0]);
printf(" Valor dos Computadores(euros): %.2f\n",total_value);
printf("Intervencoes Solicitadas: %d \t\t\t\t",counter[1]);
printf("Intervencoes Efetuadas: %d \n\n",counter[2]);

printf("1. Novo Computador\n");
printf("2. Solicitar Intervencao\n");
printf("3. Registar Intervencao\n");
printf("4. Listar\n");
printf("5. Informacoes\n");
printf("6. Gravar\n");
printf("0. Sair\n");
printf("\nSelecione a Opcao:");
}

//-------------------------------------------------------

int opc_menu(int opc,computer_info computers[])  //Função que vai ler a opcção do utilizador e redirecioná-lo para o sub-menu correto
{
    switch(opc)
    {
    case 1:
        add_computer(computers);
        break;
    case 2:
        solicitar_intervencao(26,computers);
        break;
    case 3:
        registar_intervencao(computers);
        break;
    case 4:
        list(computers);
        break;
    case 5:
        info(computers);
        break;
    case 6:
        gravar(computers);
        break;
    case 0:
        sair(computers);
        break;

    default:
        printf("\n\nEscolha apenas uma das opcoes\n\n");
    }
    return opc;
}

/*--------------------------------------------------------------------------*/
void add_computer(computer_info computers[])      //Função para o primeiro sub-menu que tem o intuito de adicionar um PC à base de dados
{

    int repete=1,i;

    if(counter[0] == N_PC -1 ) //Máxima capacidade de computadores
        {
        printf("\n Capacidade maxima de computadores atingida. Nao e possivel adicionar mais.\n");
        return;
        }

    do{

        printf("\nIntroduza o Numero de Identificacao:\n");  //Adicionar Numero Identificação do Computador
        scanf("%d", &computers[counter[0]].id);
        repete = 1;
        for(i=0;i<counter[0];i++){
                    if(computers[counter[0]].id == computers[i].id)
                        {
                            printf("Esse ID e igual ao de outro computador, insira outra");
                            repete=0;
                        }
        }
    }while(repete !=1);
    printf("ID VALIDO\n");

    printf("Introduza a Designacao do Computador:\n");  //Adicionar Designação do Computador
    fflush(stdin);
    scanf("%[^\n]s", computers[counter[0]].description);

    printf("Introduza o Nome do Colaborador que foi atribuido o portatil:\n");  //Adicionar Nome do Colaborador
    fflush(stdin);
    scanf("%[^\n]s", computers[counter[0]].collaborator);


    printf("Data de Atribuicao do Computador:\n");  //Adicionar Data em que foi atribuido o computador ao colaborador
        do{
            printf("\tMes:");
            fflush(stdin);
            scanf("%d",&computers[counter[0]].date[1]);}
        while(computers[counter[0]].date[1]<1 || computers[counter[0]].date[1]>12);

        if (computers[counter[0]].date[1] == 1 ||computers[counter[0]].date[1] == 3 ||computers[counter[0]].date[1] == 5 ||computers[counter[0]].date[1] == 7 ||computers[counter[0]].date[1] == 8 ||
            computers[counter[0]].date[1] == 10 ||computers[counter[0]].date[1] == 12){
            do{
            printf("\n\tDia:");
            fflush(stdin);
            scanf("%d",&computers[counter[0]].date[0]);}
        while(computers[counter[0]].date[0]<1 || computers[counter[0]].date[0] >31);
            }
            else{
                if(computers[counter[0]].date[1] == 4||computers[counter[0]].date[1] == 6||computers[counter[0]].date[1] == 9||computers[counter[0]].date[1] == 11){
                   do{
            printf("\n\tDia:");
            fflush(stdin);
            scanf("%d",&computers[counter[0]].date[0]);}
        while(computers[counter[0]].date[0]<1 || computers[counter[0]].date[0] >30);
                }
                else{
                    do{
            printf("\n\tDia:");
            fflush(stdin);
            scanf("%d",&computers[counter[0]].date[0]);}
        while(computers[counter[0]].date[0]<1 || computers[counter[0]].date[0] >29);
                }
            }

        do{
            printf("\tAno:");
            fflush(stdin);
            scanf("%d",&computers[counter[0]].date[2]);}
        while(computers[counter[0]].date[2]<2000 || computers[counter[0]].date[2] >2100);


    do {
        printf("Estado do computador:\n 0-->operacional\n 1-->Por intervencionar\n 2-->avariado\n"); // o do while Garante uma resposta aceitável
        scanf("%d",&computers[counter[0]].status);
    } while (computers[counter[0]].status > 2 || computers[counter[0]].status < 0);


   do{                                         // o do while garante que não haja valores negativos.
        printf("Valor do Computador:");
        scanf("%f",&computers[counter[0]].value);}
    while(computers[counter[0]].value < 0);

    counter[0]++;         //soma +1 ao contador por cada vez que se adiciona um computador
}
/*--------------------------------------------------------------------------*/
void solicitar_intervencao(int pc,computer_info computers[])  //função que permite solicitar uma intervenção a um PC em específico
{
    int i, num=0,ans=3,security_check=0;             // as variaveis inicializadas a 3 é para nao haver lixo que posso corromper a lógica

    if(pc > 25){  //este if serve para quando na funcao registar se quiser criar outra solicitacao evitar escrever o mesmo id outra vez

        for(i=0;i<counter[0];i++)  //mostra quais os ID's dos PC's já criados
                {
                printf("\nID do PC Numero %d : %d \n",i+1,computers[i].id);
                };

            printf("\nDigite o numero de identificacao do computador:");
            scanf("%d",&num);

                security_check = 0;
                    for(i=0;i<N_PC;i++)            //para o caso de nao haver um ID igual ao digitado e nao ficar preso na funcao
                  {
                        if(computers[i].id == num)
                            {
                            security_check = 1;
                            pc = i;
                            }
                    }
                if(security_check == 0){
                    do{
                        printf("Esse ID nao existe, pretende cria-lo? 1-Sim 0-Nao \n Resposta:");
                        scanf("%d",&ans);
                            if(ans == 1){
                                add_computer(computers);
                                return;}
                            if(ans == 0)
                                return;
                    }while(ans != 1 && ans !=0);
                                        }
                    printf("\t Designacao do PC escolhido: ");
                    puts(computers[pc].description);
                    printf("\t Numero de ID: %d \n",computers[pc].id);
                    printf("\n\nEsse e o codigo do computador: N-%d\n",pc+1);
        }
        else{
                num = computers[pc].id;
            }

    security_check = computers[pc].pending;

        printf("Digite o codigo de intervencao especifico ao computador:");
        fflush(stdin);
        scanf("%[^\n]s", computers[pc].int_code[security_check]);

    printf("\nData do Registo de Solicitacao:");
        do{
            printf("\n\tMes:");
            scanf("%d",&computers[pc].s_date[security_check][1]);}
        while(computers[pc].s_date[security_check][1]<1 || computers[pc].s_date[security_check][1]>12);
        if (computers[pc].s_date[security_check][1] == 1 ||computers[pc].s_date[security_check][1] == 3 ||computers[pc].s_date[security_check][1] == 5 ||computers[pc].s_date[security_check][1] == 7 ||computers[pc].s_date[security_check][1] == 8 ||
            computers[pc].s_date[security_check][1] == 10 || computers[pc].s_date[security_check][1] == 12){
            do{
            printf("\n\tDia:");
            fflush(stdin);
            scanf("%d",&computers[pc].s_date[security_check][0]);}
        while(computers[pc].s_date[security_check][0]<1 || computers[pc].s_date[security_check][0] >31);
            }
            else{
                if(computers[pc].s_date[security_check][1] == 4||computers[pc].s_date[security_check][1] == 6||computers[pc].s_date[security_check][1] == 9||computers[pc].s_date[security_check][1] == 11){
                   do{
            printf("\n\tDia:");
            fflush(stdin);
            scanf("%d",&computers[pc].s_date[security_check][0]);}
        while(computers[pc].s_date[security_check][0]<1 || computers[pc].s_date[security_check][0] >30);
                }
                else{
                    do{
            printf("\n\tDia:");
            fflush(stdin);
            scanf("%d",&computers[pc].s_date[security_check][0]);}
        while(computers[pc].s_date[security_check][0]<1 || computers[pc].s_date[security_check][0] >29);
                }
            }
        do{
            printf("\tAno:");
            fflush(stdin);
            scanf("%d",&computers[pc].s_date[security_check][2]);}
        while(computers[pc].s_date[security_check][2]<2000 || computers[pc].s_date[security_check][2] >2100);

    printf("\nBreve Descricao do Problema:");
    fflush(stdin);
    scanf("%200[^\n]s", computers[pc].summary[security_check]);

    printf("\n\nResumo do Pedido:");

        printf("\nCodigo intervencao:");
        puts(computers[pc].int_code[security_check]);

        printf("\nNumero de Identicacao do Computador: %d", num);

        printf("\nData de Registo de Solicitacao: %d-%d-%d",computers[pc].s_date[security_check][0],computers[pc].s_date[security_check][1],computers[pc].s_date[security_check][2]);

        printf("\nBreve Descricao do Problema:");
        puts(computers[pc].summary[security_check]);
        printf("\n\n\n\n\n\n\n");

    computers[pc].pending++;
    counter[1]++; //soma +1 ao contador por cada vez que se adiciona uma solicitação de intervenção
}
/*--------------------------------------------------------------------------*/
void registar_intervencao(computer_info computers[])   //funcção que pega permite registar as solicitações
{
    int answer=3,i,num,pc;  // as variaveis inicializadas a 3 é para nao haver lixo que posso corromper a lógica
    float security_check=0;
    FILE *fptr;

        for(i=0;i<counter[1];i++)       //mostra todos os computador com solicitações pendentes
        {
            if(computers[i].pending > 0){
                printf("Solicitacoes Pendentes:\n");
                printf("\tComputador %d de ID '%d'",i+1,computers[i].id);
                printf("\tDesignacao:");
                puts(computers[i].description);
                printf("\tTem '%d' solicitacoes pendentes.",computers[i].pending);
            }
        }

        printf("\nDigite o numero de identificacao do computador:");
        scanf("%d",&num);

                for(i=0;i<N_PC;i++)            //para o caso de nao haver um ID igual ao digitado e nao ficar preso na funcao
                {
                    if(computers[i].id == num)
                            security_check = 1;
                }

                if(security_check == 0){
                    do{
                        printf("\nEsse ID nao existe, pretende cria-lo? 1-Sim 0-Nao \n Resposta:");
                        fflush(stdin);
                        scanf("%d", &answer);
                            if(answer == 1){
                                add_computer(computers);
                                return;
                            }
                            if(answer == 0){
                                return;
                            }
                    }while(answer != 1 && answer !=0);
                                        }
            pc = -1;
           for(i=0;i<counter[0];i++)            //para achar a solicitação correspondente ao ID
            {
               if(computers[i].id == num && computers[i].pending > 0){
                    printf("\t Designacao do PC escolhido: ");
                    puts(computers[i].description);
                    printf("\t Numero de ID: %d \n",computers[i].id);
                    pc = i;
                    printf("\n\nEsse e o codigo do computador: N-%d\n",i+1);
                    printf("Esse codigo tem %d solicitacoes pendentes",computers[i].pending);
                    computers[i].pending = 0;
                    }
              }
              if(pc == -1)
                {
                    do
                    {

                        printf("Esse computador nao tem uma solicitacao pendente\n");
                        printf("Pretende criar uma solicitacao? 1-Sim 0-Nao \n Resposta: ");
                        scanf("%d", &answer);
                        if (answer == 1)
                            {
                        solicitar_intervencao(26,computers); // pc toma o valor de 26 a entrar na função solicitar
                        return;
                            }
                        else{
                            if(answer == 0){
                               return;
                            }
                        }
                    }while(answer != 0 || answer != 1);
                }

    printf("\nIntroduza a data do registo da intervencao:\n");
        do{
            printf("\tMes:");
            fflush(stdin);
            scanf("%d",&computers[pc].i_date[counter[2]][1]);}
        while(computers[pc].i_date[counter[2]][1]<1 || computers[pc].i_date[counter[2]][1]>12);
            if(computers[pc].i_date[counter[2]][1] == 1 ||computers[pc].i_date[counter[2]][1] == 3 ||computers[pc].i_date[counter[2]][1] == 5 ||computers[pc].i_date[counter[2]][1] == 7 ||computers[pc].i_date[counter[2]][1] == 8 ||
            computers[pc].i_date[counter[2]][1] == 10 || computers[pc].i_date[counter[2]][1] == 12){
            do{
            printf("\n\tDia:");
            fflush(stdin);
            scanf("%d",&computers[pc].i_date[counter[2]][0]);}
            while(computers[pc].i_date[counter[2]][0]<1 || computers[pc].i_date[counter[2]][0] >31);
            }
            else{
                if(computers[pc].i_date[counter[2]][1] == 4||computers[pc].i_date[counter[2]][1] == 6||computers[pc].i_date[counter[2]][1] == 9||computers[pc].i_date[counter[2]][1] == 11){
                   do{
            printf("\n\tDia:");
            fflush(stdin);
            scanf("%d",&computers[pc].i_date[counter[2]][0]);}
        while(computers[pc].i_date[counter[2]][0]<1 || computers[pc].i_date[counter[2]][0] >30);
                }
                else{
                    do{
            printf("\n\tDia:");
            fflush(stdin);
            scanf("%d",&computers[pc].i_date[counter[2]][0]);}
        while(computers[pc].i_date[counter[2]][0]<1 || computers[pc].i_date[counter[2]][0] >29);
                }
            }
        do{
            printf("\tAno:");
            fflush(stdin);
            scanf("%d",&computers[pc].i_date[counter[2]][2]);}
        while(computers[pc].i_date[counter[2]][2]<2000 || computers[pc].i_date[counter[2]][2] >2100);

    printf("Breve descricao da Intervencao:");
    fflush(stdin);
    scanf("%200[^\n]s",computers[pc].summary_int);


    printf("Custo da intervencao:");
    scanf("%f",&security_check);   //Reutiliza-se Security para poupar a criação de outra variável
    computers[pc].int_cost += security_check;
    computers[pc].finished++;

    do{
        printf("A intervencao arranjou o computador? Caso nao tenha resultado sera considerado como avariado\n 1--Sim\n 0--Nao \n");
        printf("Resposta:");
        fflush(stdin);
        scanf("%d",&answer);

        if(answer == 0)
            {
            printf("Como nao foi arranjado, o seu estado vai passar a 'avariado'");
            computers[pc].status = 2;
            }
            else
                if(answer == 1)
                {
                printf("Como foi arranjado, o seu estado vai passar a 'Operacional'");
                computers[pc].status = 0;
                }
                    else
                        printf("Erro\n");

    }while(answer != 0 && answer != 1);

    if (answer == 0){
    do{
        printf("\nDeseja solicitar intervencao?\n 1--Sim\n 0--Nao \n");
        scanf("%d", &answer);
     if(answer == 1)
                {
                    computers[pc].status = 1;
                    solicitar_intervencao(pc,computers);
                    answer = 0;
                }
    }while(answer != 0);
                    }
/*
Os dados da intervenção, incluindo o nome do colaborador e o estado do computador,
deverão ser armazenados num “ficheiro de log” (ficheiro de texto). */

 fptr = fopen("log.txt","a+");

   if ((fptr = fopen("log.txt","a+")) == NULL){
       printf("Erro!");
       exit(1);}

      fprintf(fptr,"ID do PC: %d\n ", computers[pc].id);

      fprintf(fptr,"Nome do Colaborador: %s\n", computers[pc].collaborator);
      if(computers[pc].status == 0)
        {
      fprintf(fptr,"Estado do Computador: operacional\n");
        }else{
            if(computers[pc].status == 1){
                fprintf(fptr,"Estado do Computador: Por intervencao\n");
            }else{
                    fprintf(fptr,"Estado do Computador: avariado\n");
                 }
        }
      fprintf(fptr,"Dia da Intervenção: %d\n", computers[pc].i_date[counter[2]][0]);

      fprintf(fptr,"Mes da Intervenção: %d\n", computers[pc].i_date[counter[2]][1]);

      fprintf(fptr,"Ano da Intervenção: %d\n", computers[pc].i_date[counter[2]][2]);

      fprintf(fptr,"Descrição da Intervenção: %s\n", computers[pc].summary_int);

      printf("\nFicheiro Guardado");
      printf("ID:%d",computers[0].id);

   fclose(fptr);

   counter[2]++;
}
/*--------------------------------------------------------------------------*/
void list(computer_info computers[])     // função que imprime as informações gerais dos dados introduzidos
{
    int answer,a,i,y;
    char str[100];
    if(counter[0] >0){
        do
        {

            for(i=0;i<counter[0];i++)
            {
                printf("\n-->Computador N %d \n",i+1);
                printf("\t ID: %d\n",computers[i].id);
                printf("\t Designacao: %s\n", computers[i].description);
                printf("\t Nome do Colaborador: %s\n", computers[i].collaborator);
                printf("\t Data Atribuicao do Computador: %d-%d-%d\n", computers[i].date[0],computers[i].date[1],computers[i].date[2]);
                printf("\t Estado do computador: ");
                if(computers[i].status == 0)
                    printf("\tO PC esta operacional\n");
                    else
                        if(computers[i].status == 1)
                        printf("\t O PC esta por intervencionar\n");
                        else
                            if(computers[i].status == 2)
                            printf("\t O PC esta avariado\n");
                            else
                            printf("\t Erro, Estado não lido");
                printf("\t Valor do computador:%.2f euros \n",computers[i].value);
                printf("\t Numero de Solicitacoes Pendentesno computador N-%d: %d \n",i+1,computers[i].pending);
                printf("\t Numero de Intervencoes Efetuadas no computador N-%d: %d \n",i+1,computers[i].finished);
            }

            printf("\n \tPretende ver todas as solicitacoes de um determinado computador?\n\t\t Ou apenas uma intervencao especifica?\n \t\t Todas-1 Especifica-0 --> Resposta:");
            scanf("%d",&answer);
        }while(answer != 1 && answer != 0);
    /* IV. Dados das intervenções solicitadas num determinado computador (identificado pelo utilizador).*/

            if(answer == 1)
            {
                printf("\n\tE a solicitacao corresponde a que computador? ID: ");
                scanf("%d",&a);

                    for(i=0;i<counter[0];i++)            //para achar a solicitação correspondente ao ID
                    {
                        if(computers[i].id == a){
                            printf("\t Numero de ID: %d \n",computers[i].id);
                                printf("\n\nEsse e o codigo do computador: N-%d\n",i+1);
                                a=i;}
                    }

                                for(y=0;y<=computers[i].pending;y++)
                                {
                                        puts(computers[a].int_code[y]);
                                        printf("\nData de Registo de Solicitacao: %d-%d-%d",computers[a].s_date[y][0],computers[a].s_date[y][1],computers[a].s_date[y][2]);
                                        printf("\nBreve Descricao do Problema:");
                                        puts(computers[a].summary[y]);
                                }
                    }

    /*  V. Dados do computador correspondente ao registo de uma determinada solicitação (identificada pelo utilizador). */

            if(answer == 0){
                printf("\n\tE a solicitacao corresponde a que computador? ID: ");
                fflush(stdin);
                scanf("%d",&a);

                for(i=0;i<counter[0];i++)            //para achar a solicitação correspondente ao ID
                    {
                        if(computers[i].id == a){
                            printf("\t Numero de ID: %d \n",computers[i].id);
                            printf("\n\nEsse e o codigo do computador: N-%d\n",i+1);
                            a=i;
                                }
            for(i=0;i<computers[a].pending;i++)
                {
                printf("Codigo solicitacao %d: ",i+1);
                puts(computers[a].int_code[i]);
            }

            printf("Qual e o codigo da solicitacao em especifico?\n Codigo : ");
            fflush(stdin);
            scanf("%[^\n]s",&str);
            printf("\n%s\n", str);
                for(y=0;y<computers[a].pending;y++)
                {
                    if(strcmp(str, computers[a].int_code[y]) == 0)
                    {
                        printf("Designacao:");
                        puts(computers[a].int_code[y-1]);

                            printf("Resumo da Solicitacao:\n");
                                printf("Codigo(s) de Intervencao:");
                                puts(computers[a].int_code[y]);
                                printf("\nData de Registo de Solicitacao: %d-%d-%d",computers[a].s_date[y][0],computers[a].s_date[y][1],computers[a].s_date[y][2]);

                            printf("\nBreve Descricao do Problema:");
                                puts(computers[a].summary[y]);
                                printf("\n\n\n\n\n\n\n");
                    }
                }
                    }

                            }
        }
        else
            printf("Nao ha computadores criados");
        return;
}
/*--------------------------------------------------------------------------*/
void info(computer_info computers[])
{
int operacional=0,por_intervencionar=0,avariado=0,i,total_value=0,x,y,a=0,b,c,last_10=0,last_10_p=0,ans;
float avg_int=0;
int list_date[6];


if(counter[0]>0){

//I. Quantidade de computadores em cada estado

    printf("Estados dos computadores:\n");
        for(i=0;i<counter[0];i++)
        {
         if( computers[i].status == 0 )
             operacional++;
             else
                if( computers[i].status == 1 )
                    por_intervencionar++;
                    else
                        if( computers[i].status == 2 )
                        avariado++;
        }

    printf("Computadores Operacionais: %d \n",operacional);
    printf("Computadores por Intervencionar: %d \n",por_intervencionar);
    printf("Computadores Avariados: %d \n",avariado);

    //II. Custo médio por cada intervenção efetuada nos computadores

    for(i=0;i<counter[2];i++)
        {
            total_value += computers[i].int_cost;
        }
    avg_int = total_value/counter[0];
    printf("Custo medio das intervencoes : %.2f ",avg_int);


   //III. Intervenção(ões) com o menor custo.

    for(i=1;i<counter[2];i++)
        {
            if(computers[i].int_cost <= computers[i-1].int_cost)
                computers[i].int_cost = a;
        }

        printf("\nIntervencao mais barata: %d",a);

    //IV. Percentagem de intervenções efetuadas em menos de 10 dias.
    do{
        printf("\nPretende ver a percentagem de intervencoes efetuadas nos 10 dias antes da data que inserir?\n 1-Sim 0-Nao --> Resposta: ");
        scanf("%d",&ans);
    }while(ans != 0 && ans != 1);

    if(ans == 1){
        printf("\nPercentagem de intervencoes efetuadas nos 10 dias antes de:"); //assumimos que os meses são todos de 31 dias por uma questão de simplifição de código
            do{
                printf("\n\tDia:");
                fflush(stdin);
                scanf("%d",&list_date[0]);}
            while( list_date[0] <1 || list_date[0] >31);

            do{
                printf("\tMes:");
                fflush(stdin);
                scanf("%d",&list_date[1]);}
            while( list_date[1] <1 || list_date[1] >12);

            do{
                printf("\tAno:");
                fflush(stdin);
                scanf("%d",&list_date[2]);}
            while( list_date[2] <2000 || list_date[2] >2100);

            list_date[3] = list_date[0]; //guarda o dia inserido e o dia 10 dias antes
            list_date[4] = list_date[1]; //guarda o mes inserido e o mes 10 dias antes
            list_date[5] = list_date[2]; //guarda o ano inserido e o ano 10 dias antes

            printf("\nData 10 dias antes:");

                if(list_date[0]-10 >= 1)
                {
                    list_date[3] = list_date[0]-10;

                    printf("Dia %d",list_date[3]);
                    printf("Mes %d",list_date[4]);
                    printf("Ano %d",list_date[5]);
                }

                if(list_date[0] - 10 < 1) // caso retirar os 10 dias mude o mês
                {
                    x = list_date[0] - 10;
                    list_date[3] = 31 + x;
                    list_date[4]--;

                    printf("Dia %d",list_date[3]);
                    printf("Mes %d",list_date[4]);
                    printf("Ano %d",list_date[5]);

                    if(list_date[1] - 1 < 1) // caso retirar os 10 dias mude o mês e o ano
                        {
                            y = list_date[1] - 1;
                            list_date[4] = 12 + y;
                            list_date[5]--;
                        }
                }

                a = list_date[3];
                b = list_date[4];
                c = list_date[5];


                /*Sabendo a data falta interligar se houve intervencoes nesse dia*/

                    for(i=0;i<counter[2];i++) //como todas as datas sao inicializadas a 0 as que não forem 0 no espaço 6,7,8 do vetor sao datas de intervencao
                        {
                        if((computers[i].i_date[counter[2]][0]!=0)&&(computers[i].i_date[counter[2]][1]!=0)&&(computers[i].i_date[counter[2]][2]!=0))
                        {
                            if(computers[i].i_date[counter[2]][2]==c&&computers[i].i_date[counter[2]][1]== b&&list_date[0]<=computers[i].i_date[counter[2]][0]&&a>=computers[i].i_date[counter[2]][0])
                           last_10 ++;

                        }
                        }

                    last_10_p = ((counter[2] - last_10)/counter[2]) * 100 ;
                    printf("Percentagem de intervencoes efetuadas nos 10 dias antes de %d-%d-%d e: %d",list_date[0],list_date[1],list_date[2],last_10_p );
    }

    //V. Quantidade de computadores que já avariaram.

    printf("Quantidade de computadores que ja avariaram : %d", avariado);

    }
    else {
        printf("Nao ha computadores criados");
        main();
         }
}
/*--------------------------------------------------------------------------*/
void gravar(computer_info computers[])
{
FILE *fptr;

 fptr = fopen("program.bin","wb");

   if ((fptr = fopen("program.bin","wb")) == NULL){
       printf("Erro!");
       exit(1);}

      fwrite(counter, sizeof(counter), 3, fptr);
      fwrite(computers,sizeof(computer_info),25,fptr);

      printf("\nFicheiro Guardado");
      printf("ID:%d",computers[0].id);

   fclose(fptr);

}
/*--------------------------------------------------------------------------*/
void sair(computer_info computers[])
{
FILE *fptr;
int s;

    do{
        printf("Antes de sair pretende gravar um ficheiro? (Sim-1 Nao-0) : ");
        scanf("%d",&s);}
    while(s != 1 && s != 0);


    if(s == 1){

    fptr = fopen("program.bin","wb");

        if ((fptr = fopen("program.bin","wb")) == NULL){
            printf("Erro!");
            exit(1);}

        fwrite(counter, sizeof(counter), 3, fptr);
        fwrite(computers,sizeof(computer_info),25,fptr);

        printf("\nFicheiro Guardado");
        printf("ID:%d",computers[0].id);

     fclose(fptr);
         }
    return;
}
