#include <stdio.h>
#include <stdlib.h>
#define N_PC 25
typedef struct {               //Estrutura que contem todas as variáveis
    int id;
    char int_code[50];
    char description[100];
    char collaborator[50];
    int date[15];
    int status;
    float value;
    char summary[200];
    char summary_int[200];
    int int_cost;
    int pending;
}computer_info;
void menu(computer_info computers[]);
int opc_menu(int opc,computer_info computers[]);
void add_computer(computer_info computers[]);
void solicitar_intervencao(int pc,computer_info computers[]);
void registar_intervencao(computer_info computers[]);
void list(computer_info computers[]);
void info(computer_info computers[]);
void gravar();

//Variáveis globais
int pc_counter = 0;   // inicializa o contador de pc's criados a 0
int solicit_counter=0; // inicializa o contador de pedidos de solicitação a 0
int int_counter=0;// inicializa o contador de intervençoesa 0

//------------------------------------------------------
//------------------------------------------------------

int main()
{
    int opc,i;
    computer_info computers[N_PC];  //inicializa todos os inteiros da struct a 0
    for(i=0;i<N_PC;i++){
                computers[i].id = 0;
                computers[i].status = 0;
                computers[i].value = 0;
                computers[i].int_cost = 0;
                computers[i].pending = 0;
    };

    do{
                for(opc=0;opc<13;opc++){
                computers[i].date[opc]=0;
                printf("\ndate %d : %d", i, computers[i].date[opc]);
                };

   /* for(i=0;i<pc_counter;i++){
            printf("\n%d",computers[i].id);
            printf("\n%d",computers[i].status);
    }; */

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
   int i,total_value=0;
   for(i=0;i<N_PC;i++){total_value += computers[i].value;} //contador para somar o valor total dos PC's criados

printf("\n\n\n\n\t\t\tGestao de Computadores Portateis\n\n");
printf("Total de Computadores: %d\t\t\t",pc_counter);
printf(" Valor dos Computadores(euros): %d\n",total_value);
printf("Intervencoes Solicitadas: %d \t\t\t\t",solicit_counter);
printf("Intervencoes Efetuadas: %d \n\n",int_counter);

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
        break;
    case 0:
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
            for(i=0;i<N_PC;i++){
            printf("\n%d",computers[i].id);
            printf("\n%d",computers[i].status);
    };
    printf("Teste--contador:%d\n",pc_counter);

    if(pc_counter == N_PC -1 ) //Máxima capacidade de computadores
        {
        printf("\n Capacidade maxima de computadores atingida. Nao e possivel adicionar mais.\n");
        return;
        }

    do{

        printf("\nIntroduza o Numero de Identificacao:\n");  //Adicionar Numero Identificação do Computador
        scanf("%d", &computers[pc_counter].id);
        repete = 1;
        for(i=0;i<pc_counter;i++){
                    if(computers[pc_counter].id == computers[i].id)
                        {
                            printf("Esse ID e igual ao de outro computador, insira outra");
                            repete=0;
                        }
        }
    }while(repete !=1);
    printf("ID VALIDO\n");
    printf("Introduza a Designacao do Computador:\n");  //Adicionar Designação do Computador
    fflush(stdin);
    scanf("%[^\n]s", computers[pc_counter].description);

    printf("Introduza o Nome do Colaborador que foi atribuido o portatil:\n");  //Adicionar Nome do Colaborador
    fflush(stdin);
    scanf("%[^\n]s", computers[pc_counter].collaborator);

    printf("Data de Atribuicao do Computador:\n");  //Adicionar Data em que foi atribuido o computador ao colaborador
        do{
            printf("\n\tDia:");
            fflush(stdin);
            scanf("%d",&computers[pc_counter].date[0]);}
        while(computers[pc_counter].date[0]<1 || computers[pc_counter].date[0] >31);
        do{
            printf("\tMes:");
            fflush(stdin);
            scanf("%d",&computers[pc_counter].date[1]);}
        while(computers[pc_counter].date[1]<1 || computers[pc_counter].date[1]>12);
        do{
            printf("\tAno:");
            fflush(stdin);
            scanf("%d",&computers[pc_counter].date[2]);}
        while(computers[pc_counter].date[2]<2000 || computers[pc_counter].date[2] >2100);

    do {
        printf("Estado do computador:\n 0-->operacional\n 1-->Por intervencionar\n 2-->avariado\n"); //Adicionar Estado do Computador
        scanf("%d",&computers[pc_counter].status);
    } while (computers[pc_counter].status > 2 || computers[pc_counter].status < 0);

   do{
    printf("Valor do Computador:");
    scanf("%f",&computers[pc_counter].value);}
    while(computers[pc_counter].value < 0);

    pc_counter++;         //soma +1 ao contador por cada vez que se adiciona um computador
}
/*--------------------------------------------------------------------------*/
void solicitar_intervencao(int pc,computer_info computers[])  //função que permite solicitar uma intervenção a um PC em específico
{
    int i, num=0,ans=3,security_check=0;             // as variaveis inicializadas a 3 é para nao haver lixo que posso corromper a lógica
    int repete;
    printf("%d", pc);
    printf("\n%d", num);

if(pc > 25){
    for(i=0;i<pc_counter;i++)  //mostra quais os ID's dos PC's já criados
            {
            printf("\nID do PC Numero %d : %d \n",i+1,computers[i].id);
            };

        printf("\nDigite o numero de identificacao do computador:");
        scanf("%d",&num);


           do{
                for(i=0;i<N_PC;i++)            //para o caso de nao haver um ID igual ao digitado e nao ficar preso na funcao
                {
                    if(computers[i].id == num)
                            security_check = 1;
                }
            }while(security_check != 1 && security_check != 0);

                if(security_check == 0){
                    do{
                        printf("Esse ID nao existe, pretende cria-lo? 1-Sim 0-Nao \n Resposta:");
                        scanf("%d",&ans);
                            if(ans == 1)

                                add_computer(computers);
                            if(ans == 0)
                                main();
                    }while(ans != 1 && ans !=0);
                                        }
        for(i=0;i<pc_counter;i++)            //para achar a solicitação correspondente ao ID
            {
               if(computers[i].id == num){
                    num = computers[i].id;
                    printf("\t Designacao do PC escolhido: ");
                    puts(computers[i].description);
                    printf("\t Numero de ID: %d \n",computers[i].id);
                    pc = i;
                    printf("\n\nEsse e o codigo do computador: N-%d\n",i+1);
                    }
            }
}
else{
    num = computers[pc].id;
}
        printf("Digite o codigo de intervencao especifico ao computador:");
    fflush(stdin);
    scanf("%[^\n]s", computers[pc].int_code);
        do{

            for(i=0;i<pc_counter;i++)            //para achar o computador correspondente ao numero

            {
               if(computers[i].id == num){
                     num = computers[i].id;
                    printf("Designacao do PC escolhido:");
                    puts(computers[i].description);
                    printf("Numero de ID: %d",computers[i].id);
                    repete = 1;
                    printf("\n\nEsse e o codigo do computador: N-%d",i+1);
                    computers[i].pending++; //Contador de solicitações espcificas de cada computador
                                        }
                    else{
                       printf("Esse computador nao existe");
                    }
            }
      }while(repete != 1);

    printf("\nData do Registo de Solicitacao:");
        do{
            printf("\n\tDia:");
            scanf("%d",&computers[solicit_counter].date[3]);}
        while(computers[solicit_counter].date[3]<1 || computers[solicit_counter].date[3] >31);
        do{
            printf("\tMes:");
            scanf("%d",&computers[solicit_counter].date[4]);}
        while(computers[solicit_counter].date[4]<1 || computers[solicit_counter].date[4]>12);
        do{
            printf("\tAno:");
            fflush(stdin);
            scanf("%d",&computers[solicit_counter].date[5]);}while(computers[solicit_counter].date[5]<2000 || computers[solicit_counter].date[5] >2100);

    printf("\nBreve Descricao do Problema:");
    fflush(stdin);
    scanf("%200[^\n]s", computers[solicit_counter].summary);

   printf("\n\nResumo do Pedido:");

        puts(computers[i].int_code);

        printf("\nNumero de Identicacao do Computador: %d", num);

        printf("\nData de Registo de Solicitacao: %d-%d-%d",computers[solicit_counter].date[3],computers[solicit_counter].date[4],computers[solicit_counter].date[5]);

        printf("\nBreve Descricao do Problema:");
        puts(computers[solicit_counter].summary);
        printf("\n\n\n\n\n\n\n");

    solicit_counter++; //soma +1 ao contador por cada vez que se adiciona uma solicitação de intervenção

    }
/*--------------------------------------------------------------------------*/
void registar_intervencao(computer_info computers[])   //funcção que pega permite registar as solicitações
{
    int answer,i,num,pc,security_check;  // as variaveis inicializadas a 3 é para nao haver lixo que posso corromper a lógica
        answer=3;
        security_check=0;
        for(i=0;i<solicit_counter;i++)       //mostra todos os computador com solicitações pendentes
        {
            printf("Solicitacoes Pendentes:\n");
            printf("\tComputador %d de ID '%d'",i+1,computers[i].id);
            printf("\tDesignacao:");
            puts(computers[i].description);
            printf("\tTem '%d' solicitacoes pendentes.",computers[i].pending);
        }


        do{
        printf("\nDigite o numero de identificacao do computador:");
        scanf("%d",&num);

            do{
                for(i=0;i<N_PC;i++)            //para o caso de nao haver um ID igual ao digitado e nao ficar preso na funcao
                {
                    if(computers[i].id == num)
                            security_check = 1;
                }
            }while(security_check != 1 && security_check != 0);

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
            security_check=0;

            for(i=0;i<pc_counter;i++)            //para achar a solicitação correspondente ao ID
            {
               if((computers[i].id == num) && (computers[i].pending > 0)){
                    num = computers[i].id;
                    printf("\t Designacao do PC escolhido: ");
                    puts(computers[i].description);
                    printf("\t Numero de ID: %d \n",computers[i].id);
                    security_check = 1;
                    pc = i;
                    printf("\n\nEsse e o codigo do computador: N-%d\n",i+1);
                    printf("Esse codigo tem %d solicitacoes pendentes",computers[i].pending);
                    computers[i].pending--;
                    solicit_counter--;
                    }
                    else{
                        printf("Esse computador nao tem uma solicitacao pendente");
                        printf("Pretende criar uma solicitacao? 1-Sim 0-Nao \n Resposta:");
                        scanf("%d", &answer);
                        solicitar_intervencao(26,computers);
                        return;
                    }
              }
      }while(security_check != 1);

    printf("\nIntroduza a data do registo da intervencao:");
        do{
            printf("\n\tDia:");
            fflush(stdin);
            scanf("%d",&computers[int_counter].date[6]);}
        while(computers[int_counter].date[6]<1 || computers[int_counter].date[6] >31);
        do{
            printf("\tMes:");
            fflush(stdin);
            scanf("%d",&computers[int_counter].date[7]);}
        while(computers[int_counter].date[7]<1 || computers[int_counter].date[7]>12);
        do{
            printf("\tAno:");
            fflush(stdin);
            scanf("%d",&computers[int_counter].date[8]);}
        while(computers[int_counter].date[8]<2000 || computers[int_counter].date[8] >2100);

    printf("Breve descricao da Intervencao:");
    fflush(stdin);
    scanf("%200[^\n]s",computers[int_counter].summary_int);


    printf("Custo da intervencao:");
    scanf("%d",&computers[int_counter].int_cost);


    answer=3;
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
                    solicitar_intervencao(pc,computers);
                    answer = 0;
                }
    }while(answer != 0);
    }
    int_counter++;

/*
Os dados da intervenção, incluindo o nome do colaborador e o estado do computador,
deverão ser armazenados num “ficheiro de log” (ficheiro de texto). */

}
/*--------------------------------------------------------------------------*/
void list(computer_info computers[])     // função que imprime as informações gerais dos dados introduzidos
{
    int answer,a,repete=0,i;

    //I. Dados completos de todos os computadores introduzidos, incluindo as quantidades de
    //        intervenções solicitadas e efetuadas para cada computador.

    if(pc_counter > 0){

        for(int i=0;i<3;i++)
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
        }
       // II. Dados de todas as intervenções solicitadas.

        printf("\t Numero de Solicitacoes Pendentes: %d \n",solicit_counter);
        /*Faltam coisas*/

       // III. Dados de todas as intervenções efetuadas.

        printf("\t Numero de Intervencoes Efetuadas: %d \n",int_counter);
        /*Faltam coisas*/

       // IV. Dados das intervenções solicitadas num determinado computador (identificado pelo utilizador).


       //  V. Dados do computador correspondente ao registo de uma determinada solicitação (identificada pelo utilizador). */

        printf("\n \tPretende ver os dados de alguma solicitacao de intervencao? Sim-1 Nao-0 \n Resposta:");
        scanf("%d",&answer);
            do{
            if(answer == 1)
            {
                printf("\tE a solicitacao corresponde a que computador? ID: ");
                scanf("%d",&a);

                do{
                    for(i=0;i<pc_counter;i++)            //para achar a solicitação correspondente ao ID

                    {
                        if(computers[i].id == a){
                            printf("\t Numero de ID: %d \n",computers[i].id);
                            repete = 1;
                            printf("\n\nEsse e o codigo do computador: N-%d\n",i+1);

                            printf("Resumo da Solicitação:");
                                printf("Codigo de Intervencao:");
                                puts(computers[i].int_code);
                                printf("\nData de Registo de Solicitacao: %d-%d-%d",computers[solicit_counter].date[3],computers[solicit_counter].date[4],computers[solicit_counter].date[5]);

                                printf("\nBreve Descricao do Problema:");
                                puts(computers[solicit_counter].summary);
                                printf("\n\n\n\n\n\n\n");

                                                }
                            else{
                                printf("Esse computador nao tem uma solicitação pendente");
                                }
                    }

                }while(repete != 1);
            }

                }while(answer != 1 && answer != 0);

                    }
        else {
        printf("Nao ha computadores criados");
        return;}
}
/*--------------------------------------------------------------------------*/
void info(computer_info computers[])
{
int operacional=0,por_intervencionar=0,avariado=0,i,total_value=0,avg_int=0,x,y,a,b,c,last_10=0,last_10_p=0;

if(pc_counter>0){

//I. Quantidade de computadores em cada estado

    printf("Estados dos computadores:\n");
        for(i=0;i<pc_counter;i++)
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

    for(i=0;i<int_counter;i++)
        {
            total_value += computers[i].int_cost;
        }
    avg_int = total_value/pc_counter;
    printf("Custo medio das intervencoes : %d ",avg_int);


   /*III. Intervenção(ões) com o menor custo.*/

    for(i=1;i<int_counter;i++)
        {
            if(computers[i].int_cost <= computers[i-1].int_cost)
                printf("Intervencao mais barata: %d",computers[i].int_cost);
        }

    //IV. Percentagem de intervenções efetuadas em menos de 10 dias.

    printf("Percentagem de intervencoes efetuadas nos 10 dias antes de:"); //assumimos que os meses são todos de 31 dias por uma questão de simplifição de código
        do{
            printf("\n\tDia:");
            fflush(stdin);
            scanf("%d",&computers[0].date[9]);}
        while(computers[0].date[9]<1 || computers[0].date[9] >31);

            computers[0].date[12] = computers[0].date[9];

        do{
            printf("\tMes:");
            fflush(stdin);
            scanf("%d",&computers[0].date[10]);}
        while(computers[0].date[10]<1 || computers[0].date[10]>12);

        computers[0].date[13] = computers[0].date[10];

        do{
            printf("\tAno:");
            fflush(stdin);
            scanf("%d",&computers[0].date[11]);}
        while(computers[0].date[11]<2000 || computers[0].date[11] >2100);

        computers[0].date[14] = computers[0].date[11];

        printf("Data 10 dias antes:");

            if(computers[0].date[12]-10 >= 1)
            {
                printf("Dia %d",computers[0].date[12]-10);
                printf("Mes %d",computers[0].date[13]);
                printf("Ano %d",computers[0].date[14]);
            }

            if(computers[0].date[12] - 10 < 1) // caso retirar os 10 dias mude o mês
            {
                x = computers[0].date[12] - 10;
                computers[0].date[12] = 31 + x;
                computers[0].date[13]--;
            }

                    if(computers[0].date[13] - 1 < 1) // caso retirar os 10 dias mude o ano
                    {
                        y = computers[0].date[13] - 1;
                        computers[0].date[13] = 12 + y;
                        computers[0].date[14]--;
                    }
                printf("Dia %d",computers[0].date[12]);
                printf("Mes %d",computers[0].date[13]);
                printf("Ano %d",computers[0].date[14]);

                a = computers[0].date[12];
                b = computers[0].date[13];
                c = computers[0].date[14];

                /*Sabendo a data falta interligar se houve intervencoes nesse dia*/

                for(i=0;i<int_counter;i++) //como todas as datas sao inicializadas a 0 as que não forem 0 no espaço 6,7,8 do vetor sao datas de intervencao
                    {
                    if(computers[i].date[6] != 0 && computers[i].date[7] != 0 && computers[i].date[8] != 0 )
                    {
                        if((computers[i].date[8] == c ) && (computers[i].date[7] == b ) && ( a-10 <= computers[i].date[6] && a >= computers[i].date[6]))
                           last_10 ++;

                        if(computers[i].date[8] == c )
                        {
                             if((computers[i].date[7] == b - 1 )&&(a-10 <= computers[i].date[6] && a >= computers[i].date[6]))
                                last_10 ++;
                        }

 /*                      if(computers[i].date[8] == c-1 )
    Falta Por            {
    isto a funcionar          if((b == 1) && (computers[i].date[7] == 12 ) && (computers[i].date[6] >31 ) )
                               last_10 ++;
                         }
*/                 }
                    }

                   last_10_p = ((last_10 - int_counter)/last_10) * 100 ;

    //V. Quantidade de computadores que já avariaram.

    printf("Quantidade de computadores que já avariaram : %d", avariado);

    }
    else {
        printf("Nao ha computadores criados");
        main();
         }
}
/*--------------------------------------------------------------------------*/
void gravar()
{

}
