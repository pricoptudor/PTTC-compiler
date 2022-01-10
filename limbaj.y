%{
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;

#define MAX_SIZE 100

int CURR_SCOPE=0;
int INC_SCOPE=1000;

struct var{
     char nume[MAX_SIZE];
     char valoare_sir[MAX_SIZE];
     double valoare_num; //default=0 in decalratie
     int tip;
     int constant; //default=0 in declaratie
     int scope;
};

struct fun{
     char nume[MAX_SIZE];
     int tip;
     struct parametri* param;
     struct var* return_val;
};

struct parametri{
     int param_nr;
     int param_tip[20];
};

struct structura{
     char nume[MAX_SIZE];
     int member_nr;
     char member_name[MAX_SIZE][MAX_SIZE];
     int var_decl_nr;
     char var_declared[MAX_SIZE][MAX_SIZE];
     int scope;
};

struct var* moveVar(char* i);
struct var* moveNum(double n, int tip);
struct var* expr_calc_single(struct var* e, int c);
struct var* expr_calc_double(struct var* e1, struct var* e2, int c);
struct var* array_get_value(char* id, int pos);
struct var* moveSir(char* str, int tip);
struct var* moveArray(struct var* a);
struct var* array_get_size(char *id);
struct var* moveFunc(struct var* v);
struct var* callFunctionSimple(char *id);
struct var* callFunctionComplex(char *id, struct parametri* p);
struct parametri* insertFirstParam(int tip);
struct var* moveStructMember(char* id, char* member);

int arr_count=0;
int arr_size[MAX_SIZE];
int var_count = 0;
int fun_count=0;
int struct_count=0;
struct var arr_table[MAX_SIZE][MAX_SIZE];
struct var var_table[MAX_SIZE];
struct fun fun_table[MAX_SIZE];
struct structura struct_table[MAX_SIZE];

%}
%token PROG_BEGIN PROG_END
%token GLOBAL_BEGIN GLOBAL_END
%token FNC_STR_BEGIN FNC_STR_END
%token MAIN_BEGIN MAIN_END 
%token CONST INT FLOAT CHAR STRING BOOL
%token ARRAY ARRAY_INSERT ARRAY_DELETE ARRAY_GET ARRAY_SIZE
%token ADUNARE SCADERE INMULTIRE IMPARTIRE INCREMENT DECREMENT
%token EQUAL NEQUAL LOWER LEQ GREATER GEQ AND OR
%token ASSIGN PRINT 
%token STRUCT_BEGIN STRUCT_END STRUCT_TYPE
%token FUNCTION_BEGIN FUNCTION_END FUNCTION_TYPE RETURN
%token COMMENT 
%token IF_BEGIN IF_END ELSE_BEGIN ELSE_END 
%token WHILE_BEGIN WHILE_END FOR_BEGIN FOR_END

%union 
{
	double num; 
	char nume_var[1000]; 
     char sir_var[1000];
	int type_id;
     struct var* strct;
     struct parametri* strct_param;
     struct fun* fnc;
} 

%token<num> NUMBER NUMBER_FLOAT 
%token<nume_var> ID
%token<sir_var> ANYTHING VALUE_CHR 

%type<strct> expr math_expr boolean_expr array_returns variable function_call call_param struct_member
%type<strct_param> lista_param call_param_list 
%type<type_id> param tip 
%type<fnc> function_decl 

%right ASSIGN

%left EQUAL NEQUAL
%left LOWER LEQ GREATER GEQ

%left AND OR

%left SCADERE ADUNARE
%left INMULTIRE IMPARTIRE 
 
%start progr

%%

afisare : PRINT expr                               { afisare_var($2); } 
        | PRINT '(' ANYTHING ')'                   { printf("Print: %s\n", $3); }
        | PRINT '(' ANYTHING ',' expr ')'          { afisare_sir_var($3,$5); }
        ;


function_decl : FUNCTION_BEGIN tip ID '(' ')' ':' block_function RETURN variable ';' FUNCTION_END                  { insertFun($2,$3,$9); }
              | FUNCTION_BEGIN tip ID '(' lista_param ')' ':' block_function RETURN variable ';' FUNCTION_END      { insertFunParam($2,$3,$5,$10); }
              ;

lista_param : param                     { $$ = insertFirstParam($1); }
            | lista_param ','  param    { insertParam($$,$3); }
            ;
            
param : tip ID                          { $$ = $1; }
      ; 


block_function : block_function main_statement
               | main_statement
               ;


structure : STRUCT_BEGIN ID ':' block_struct STRUCT_END     { def_structura($2); }
          ;

block_struct : block_struct struct_statement
             | struct_statement
             ;

struct_statement : tip ID                              ';'            { add_struct_member($2); }
                 | tip ID ASSIGN expr                  ';'            { add_struct_member($2); } 
                 | tip ID ASSIGN VALUE_CHR             ';'            { add_struct_member($2); }
                 | tip ID ASSIGN ANYTHING              ';'            { add_struct_member($2); }
                 | ARRAY tip ID                        ';'            { add_struct_member($3); }
                 | CONST tip ID                        ';'            { printf("Const variables must be initialized at declaration!\n"); yyerror($3); exit(0); }
                 | CONST tip ID ASSIGN expr            ';'            { add_struct_member($3); }
                 | CONST tip ID ASSIGN VALUE_CHR       ';'            { add_struct_member($3); }
                 | CONST tip ID ASSIGN ANYTHING        ';'            { add_struct_member($3); }
                 | CONST ARRAY tip ID                  ';'            { printf("Const arrays cannot be declared!\n"); yyerror($4); exit(0); }                     
                 | comment
                 ;

progr : PROG_BEGIN global fnc_str main PROG_END        { print_tables(); printf("Exit succesfully\n"); exit(0); } 
      ;
     
global : GLOBAL_BEGIN block_global GLOBAL_END          { CURR_SCOPE=INC_SCOPE; }
       ;

block_global : block_global global_statement
             | global_statement
             ;

global_statement : declaratii ';'
                 | comment
                 ;


fnc_str : FNC_STR_BEGIN block_fnc_str FNC_STR_END      { CURR_SCOPE=1; }    
        ;


block_fnc_str : block_fnc_str fnc_str_statement
              | fnc_str_statement
              ;

fnc_str_statement : function_decl
                  | structure
                  | comment
                  ;

main : MAIN_BEGIN block_main MAIN_END
     ;

block_main : block_main main_statement
           | main_statement
           ;

main_statement : assignment              ';'
               | function_call           ';'
               | afisare                 ';'
               | declaratii              ';'
               | array_operation         ';'
               | comment
               | control_statement
               ;

function_call : FUNCTION_TYPE ID '(' ')'                    { $$ = callFunctionSimple($2); }
              | FUNCTION_TYPE ID '(' call_param_list ')'    { $$ = callFunctionComplex($2,$4); }
              ;

call_param_list : call_param_list ',' call_param  { insertParam($$, $3->tip); }
                | call_param                      { $$ = insertFirstParam($1->tip); }
                ;                     

call_param : expr             { $$ = $1; }
           ;


control_statement : control_if     
                  | control_while
                  | control_for
                  ;


control_if :  if_begin '(' boolean_expr ')' ':' block_if IF_END                  { CURR_SCOPE=1; }
           |  if_begin '(' boolean_expr ')' ':' block_if IF_END control_else     { CURR_SCOPE=1; }
           ;

if_begin : IF_BEGIN      { CURR_SCOPE=++INC_SCOPE; }
         ;

block_if : block_if main_statement      
         | main_statement               
         ;


control_else : else_begin block_else ELSE_END     { CURR_SCOPE=1; }
             ;

else_begin : ELSE_BEGIN  { CURR_SCOPE=++INC_SCOPE; }
           ;

block_else : block_else main_statement
           | main_statement
           ;


control_while : while_begin '(' boolean_expr ')' ':' block_while WHILE_END       { CURR_SCOPE=1; }
              ;

while_begin : WHILE_BEGIN     { CURR_SCOPE=++INC_SCOPE; }
            ;

block_while : block_while main_statement
            | main_statement
            ;


control_for : for_begin '(' for_condition ')' ':' block_for FOR_END        { CURR_SCOPE=1; }
            ;

for_begin : FOR_BEGIN    { CURR_SCOPE=++INC_SCOPE; }
          ;

for_condition : for_init ';' boolean_expr ';' for_increment
              ;

for_init : tip ID ASSIGN NUMBER
         ;

for_increment : assignment
              ;

block_for : block_for main_statement
          | main_statement
          ;


declaratii : tip ID                                { decl_var_simple($1, $2, 0); }
           | tip ID ASSIGN expr                    { decl_var_expr($1, $2, $4, 0); } 
           | tip ID ASSIGN VALUE_CHR               { decl_var_assign_str($1, $2, $4, 0); }
           | tip ID ASSIGN ANYTHING                { decl_var_assign_str($1, $2, $4, 0); }
           | ARRAY tip ID                          { decl_arr_simple($2, $3, 0); }
           | CONST tip ID                          { printf("Const variables must be initialized at declaration!\n"); yyerror($3); exit(0); }
           | CONST tip ID ASSIGN expr              { decl_var_expr($2, $3, $5, 1); }
           | CONST tip ID ASSIGN VALUE_CHR         { decl_var_assign_str($2, $3, $5, 1); }
           | CONST tip ID ASSIGN ANYTHING          { decl_var_assign_str($2, $3, $5, 1); }
           | CONST ARRAY tip ID                    { printf("Const arrays cannot be declared!\n"); yyerror($4); exit(0); }
           | STRUCT_TYPE ID ID                     { decl_struct_var($2, $3); }                  
           ;


tip  : INT     { $$=0; }
     | FLOAT   { $$=1; }
     | CHAR    { $$=2; }
     | STRING  { $$=3; }
     | BOOL    { $$=4; }
     ;

variable : ID                      { $$ = moveVar($1); }
	    | function_call           { $$ = moveFunc($1); }
         | NUMBER                  { $$ = moveNum($1, 0); }
         | NUMBER_FLOAT            { $$ = moveNum($1, 1); }
         | array_returns           { $$ = moveArray($1); }
         | VALUE_CHR               { $$ = moveSir($1, 2); }
         | ANYTHING                { $$ = moveSir($1, 3); }
         ;

expr : math_expr                   { $$ = $1; }
     | '(' expr ')'                { $$ = $2; }
     | boolean_expr                { $$ = $1; }
     ;    

math_expr : ID                     { $$ = moveVar($1); }
          | NUMBER                 { $$ = moveNum($1, 0); }
          | NUMBER_FLOAT           { $$ = moveNum($1, 1); }
          | struct_member          { $$ = $1; }
          | array_returns          { $$ = $1; }
          | function_call          { $$ = $1; }
          | ADUNARE expr           { $$ = expr_calc_single($2, 0); }
          | SCADERE expr           { $$ = expr_calc_single($2, 1); }
          | expr ADUNARE expr      { $$ = expr_calc_double($1, $3, 0); }
          | expr SCADERE expr      { $$ = expr_calc_double($1, $3, 1); }
          | expr INMULTIRE expr    { $$ = expr_calc_double($1, $3, 2); }
          | expr IMPARTIRE expr    { $$ = expr_calc_double($1, $3, 3); }
          ;

struct_member : ID '.' ID          { $$ = moveStructMember($1, $3); }
              ;     



boolean_expr : expr EQUAL expr        { $$ = expr_calc_double($1, $3, 4); }
             | expr NEQUAL expr       { $$ = expr_calc_double($1, $3, 5); }
             | expr LOWER expr        { $$ = expr_calc_double($1, $3, 6); }
             | expr LEQ expr          { $$ = expr_calc_double($1, $3, 7); }
             | expr GREATER expr      { $$ = expr_calc_double($1, $3, 8); }
             | expr GEQ expr          { $$ = expr_calc_double($1, $3, 9); }
             | expr AND expr          { $$ = expr_calc_double($1, $3, 10); }
             | expr OR expr           { $$ = expr_calc_double($1, $3, 11); }
             ;
          
comment : COMMENT
        ;

array_operation : ID ARRAY_INSERT '(' ID ')'                             { array_insert_id($1, $4); }
                | ID ARRAY_INSERT '(' NUMBER ')'                         { array_insert_nr($1, $4, 0); }
                | ID ARRAY_INSERT '(' NUMBER_FLOAT ')'                   { array_insert_nr($1, $4, 1); }
                | ID ARRAY_INSERT '(' VALUE_CHR ')'                      { array_insert_str($1, $4, 2); }
                | ID ARRAY_INSERT '(' ANYTHING ')'                       { array_insert_str($1, $4, 3); }
                | ID ARRAY_INSERT '(' ID ',' NUMBER ')'                  { array_insert_id_pos($1, $4, $6); }
                | ID ARRAY_INSERT '(' NUMBER ',' NUMBER ')'              { array_insert_nr_pos($1, $4, $6, 0); }
                | ID ARRAY_INSERT '(' NUMBER_FLOAT ',' NUMBER ')'        { array_insert_nr_pos($1, $4, $6, 1); }
                | ID ARRAY_INSERT '(' VALUE_CHR ',' NUMBER ')'           { array_insert_str_pos($1, $4, $6, 2); }
                | ID ARRAY_INSERT '(' ANYTHING ',' NUMBER ')'            { array_insert_str_pos($1, $4, $6, 3); }
                | ID ARRAY_DELETE '(' NUMBER ')'                         { array_delete_pos($1, $4); }
                | ID ARRAY_DELETE '(' ')'                                { array_delete($1); }
                ;


array_returns : ID ARRAY_GET '(' NUMBER ')'                 { $$ = array_get_value($1, $4); }  
              | ID ARRAY_SIZE '(' ')'                       { $$ = array_get_size($1); }
              ;

assignment : ID ASSIGN expr	         { id_assign_var($1, $3); }
           | ID INCREMENT              { inc_dec_val($1, 1); }
           | ID DECREMENT              { inc_dec_val($1, -1); }
           | ID ASSIGN VALUE_CHR       { id_assign_str($1, $3, 2); }
           | ID ASSIGN ANYTHING        { id_assign_str($1, $3, 3); }
           ;
                
%%

struct var* moveStructMember(char* id, char* member)
{
     int index=-1;
     for(int i=0;i<struct_count;++i)
     {
          if(strcmp(struct_table[i].nume,id)==0)
          {
               index=i;
          }
     }
     if(index==-1)
     {
          printf("Structure not defined!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          int flag=-1;
          for(int i=0;i<struct_table[index].member_nr;++i)
          {
               if(strcmp(member,struct_table[index].member_name[i])==0)
               {
                    flag=0;
               }
          }
          if(flag==-1)
          {
               printf("Structure does not have that member!\n");
               yyerror(id);
               exit(0);
          }
          else
          {
               struct var* v=(struct var*)malloc(sizeof(struct var));
               v->valoare_num=0;
               v->tip=0;
               return v;
          }
     }
}

int init_global_scope()
{
     for(int i=0;i<var_count;++i)
     {
          var_table[i].scope=CURR_SCOPE;
     }

     for(int i=0;i<arr_count;++i)
     {
          for(int j=0;j<arr_size[i];++j)
          {
               arr_table[i][j].scope=CURR_SCOPE;        
          }
     }
}

int decl_struct_var(char *nume_struct, char* nume_var)
{
     int index=-1;
     for(int i=0;i<struct_count;++i)
     {
          if(strcmp(struct_table[i].nume,nume_struct)==0)
          {
               index=i;
          }
     }
     if(index==-1)
     {
          printf("Structure not defined!\n");
          yyerror(nume_struct);
          exit(0);
     }
     strcpy(struct_table[index].var_declared[struct_table[index].var_decl_nr],nume_var);
     struct_table[index].var_decl_nr++;
}

int def_structura(char* nume_struct)
{
     int index=-1;
     for(int i=0;i<struct_count;++i)
     {
          if(strcmp(struct_table[i].nume,nume_struct)==0)
          {
               index=i;
          }
     }
     if(index!=-1)
     {
          printf("Structure already defined!\n");
          yyerror(nume_struct);
          exit(0);
     }
     strcpy(struct_table[struct_count].nume,nume_struct);
     struct_table[struct_count].var_decl_nr=0;
     struct_count++;
}

int add_struct_member(char *nume)
{
     for(int i=0;i<struct_table[struct_count].member_nr;++i)
     {
          if(strcmp(struct_table[struct_count].member_name[i],nume)==0)
          {
               printf("Struct member already declared.\n");
               yyerror(nume);
               exit(0);
          }
     }
     struct_table[struct_count].member_nr++; 
     strcpy(struct_table[struct_count].member_name[struct_table[struct_count].member_nr-1],nume);
}

int decl_var_expr(int tip, char* id, struct var* v, int cnst)
{
     int index=get_var_index(id);
     if(index!=-1 && CURR_SCOPE==var_table[index].scope)
     {
          printf("Variable already declared!\n");
          yyerror(id);
          exit(0);
     }

     if(tip!=v->tip)
     {
          printf("Types not matching!\n");
          yyerror(id);
          exit(0);
     }

     strcpy(var_table[var_count].nume, id);

     var_table[var_count].valoare_num=v->valoare_num;
     var_table[var_count].tip=tip;

     var_table[var_count].constant=cnst;
     strcpy(var_table[var_count].valoare_sir, v->valoare_sir);

     var_table[var_count].scope=CURR_SCOPE;
     var_count++;
}

void print_tables()
{
     int fd;
     if(-1 == (fd=open("symbol_table.txt", O_CREAT | O_RDWR, 0777)))
     {
          printf("Eroare deschidere fisier symbol table.\n");
          exit(0);
     }

     char line[2*MAX_SIZE];
     for(int i=0;i<var_count;++i)
     {
          sprintf(line,"Nume: %s, ",var_table[i].nume);

          switch(var_table[i].tip)
          {
               case 0:
                    strcat(line,"tip: integer, ");
                    write(fd,line,strlen(line));
                    sprintf(line,"valoare: %.0f, ",var_table[i].valoare_num);
                    break;
               case 1:
                    strcat(line,"tip: float, ");
                    write(fd,line,strlen(line));
                    sprintf(line,"valoare: %lf, ",var_table[i].valoare_num);
                    break;
               case 2:
                    strcat(line,"tip: char, ");
                    write(fd,line,strlen(line));
                    sprintf(line,"valoare: %c, ",var_table[i].valoare_sir[0]);
                    break;
               case 3:
                    strcat(line,"tip: string, ");
                    write(fd,line,strlen(line));
                    sprintf(line,"valoare: %s, ",var_table[i].valoare_sir);
                    break;
               case 4:
                    strcat(line,"tip: bool, ");
                    write(fd,line,strlen(line));
                    if(var_table[i].valoare_num==0)
                    {
                         sprintf(line,"valoare: false, ");
                    }
                    else
                    {
                         sprintf(line,"valoare: true, ");
                    }
                    break;
          }

          if(var_table[i].constant==1)
          {
               strcat(line,"constant: 1\n");
          }
          else
          {
               strcat(line,"constant: 0\n");
          }
          write(fd,line,strlen(line));
     }

     for(int i=0;i<arr_count;++i)
     {
          sprintf(line,"Nume: %s, ",arr_table[i][0].nume);

          switch(arr_table[i][0].tip)
          {
               case 0:
                    strcat(line,"tip: array integer, ");
                    write(fd,line,strlen(line));
                    for(int j=0;j<arr_size[i];++j)
                    {
                         sprintf(line,"valoare %d: %.0f, ",j,arr_table[i][j].valoare_num);
                         write(fd,line,strlen(line));
                    }
                    break;
               case 1:
                    strcat(line,"tip: array float, ");
                    write(fd,line,strlen(line));
                    for(int j=0;j<arr_size[i];++j)
                    {
                         sprintf(line,"valoare %d: %lf, ",j,arr_table[i][j].valoare_num);
                         write(fd,line,strlen(line));
                    }
                    break;
               case 2:
                    strcat(line,"tip: array char, ");
                    write(fd,line,strlen(line));
                    for(int j=0;j<arr_size[i];++j)
                    {
                         sprintf(line,"valoare %d: %c, ",j,arr_table[i][j].valoare_sir[0]);
                         write(fd,line,strlen(line));
                    }
                    break;
               case 3:
                    strcat(line,"tip: array string, ");
                    write(fd,line,strlen(line));
                    for(int j=0;j<arr_size[i];++j)
                    {
                         sprintf(line,"valoare %d: %s, ",j,arr_table[i][j].valoare_sir);
                         write(fd,line,strlen(line));
                    }
                    break;
               case 4:
                    strcat(line,"tip: array bool, ");
                    write(fd,line,strlen(line));
                    for(int j=0;j<arr_size[i];++j)
                    {
                         if(arr_table[i][j].valoare_num==0)
                         {
                              sprintf(line,"valoare %d: false, ",j);
                         }
                         else
                         {
                              sprintf(line,"valoare %d: true, ",j);
                         }  
                         write(fd,line,strlen(line));
                    }
                    break;
          }

          if(arr_table[i][0].constant==1)
          {
               sprintf(line,"constant: 1\n");
          }
          else
          {
               sprintf(line,"constant: 0\n");
          }
          write(fd,line,strlen(line));
     }

     for(int i=0;i<struct_count;++i)
     {
          sprintf(line,"Nume structura: %s, ",struct_table[i].nume);
          write(fd,line,strlen(line));

          for(int j=0;j<struct_table[i].member_nr;++j)
          {
               sprintf(line,"Camp %d: %s, ",j,struct_table[i].member_name[j]);
               write(fd,line,strlen(line));
          }
     }

     close(fd);

     if(-1 == (fd=open("symbol_table_functions.txt", O_CREAT | O_RDWR, 0777)))
     {
          printf("Eroare deschidere fisier symbol table.\n");
          exit(0);
     }

     for(int i=0;i<fun_count;++i)
     {
          sprintf(line,"Nume: %s, ",fun_table[i].nume);

          switch(fun_table[i].tip)
          {
               case 0:
                    strcat(line,"tip: integer, ");
                    break;
               case 1:
                    strcat(line,"tip: float, ");
                    break;
               case 2:
                    strcat(line,"tip: char, ");
                    break;
               case 3:
                    strcat(line,"tip: string, ");
                    break;
               case 4:
                    strcat(line,"tip: bool, ");
                    break;
          }
          write(fd,line,strlen(line));

          for(int j=0;j<fun_table[i].param->param_nr;++j)
          {
               switch(fun_table[i].param->param_tip[j])
               {
                    case 0:
                         sprintf(line,"parametru %d: integer, ",j);
                         break;
                    case 1:
                         sprintf(line,"parametru %d: float, ",j);
                         break;
                    case 2:
                         sprintf(line,"parametru %d: char, ",j);
                         break;
                    case 3:
                         sprintf(line,"parametru %d: string, ",j);
                         break;
                    case 4:
                         sprintf(line,"parametru %d: bool, ",j);
                         break;
               }
               write(fd,line,strlen(line));
          }
     }

     close(fd);
}

struct parametri* insertFirstParam(int tip)
{
     struct parametri* p = (struct parametri*)malloc(sizeof(struct parametri));

     p->param_nr=1;
     p->param_tip[0]=tip;

     return p;
}

struct var* moveFunc(struct var* v)
{
     int index=get_var_index(v->nume);
     if(index==-1)
     {
          printf("Function undeclared\n");
          yyerror(v->nume);
          exit(0);
     }
     else
     {
          struct var* aux=(struct var*)malloc(sizeof(struct var));
          memcpy(aux,v,sizeof(struct var));
          return aux;
     }
}

int verify_param(struct parametri* p,struct parametri* r)
{
     if(p->param_nr!=r->param_nr)
     {
          return 0;
     }
     for(int i=0;i<p->param_nr;++i)
     {
          if(p->param_tip[i]!=r->param_tip[i])
          {
               return 0;
          }
     }
     return 1;
}

int get_fun_index(char *id, struct parametri* p)
{
     if(p==NULL)
     {
          for(int i=0;i<fun_count;++i)
          {
               if(strcmp(id,fun_table[i].nume)==0)
               {
                    return i;
               }
          }
     }
     else
     {
          for(int i=0; i<fun_count; i++)
          {
               if(strcmp(id, fun_table[i].nume)==0 && verify_param(fun_table[i].param,p))
               {
                    return i;
               }
          }
     }
     
     return -1;
}

struct var* callFunctionSimple(char *id)
{
     int index=get_fun_index(id,NULL);
     if(index==-1)
     {
          printf("Function undeclared!\n");
          yyerror(id);
          exit(0);
     }

     struct var* v=(struct var*)malloc(sizeof(struct var));
     memcpy(v,fun_table[index].return_val,sizeof(struct var));

     return v;
}

struct var* callFunctionComplex(char *id, struct parametri* p)
{
     int index=get_fun_index(id,p);
     if(index==-1)
     {
          printf("Function undeclared\n");
          yyerror(id);
          exit(0);
     }

     struct var* v=(struct var*)malloc(sizeof(struct var));
     memcpy(v,fun_table[index].return_val,sizeof(struct var));

     return v;
}

struct var* array_get_size(char *id)
{
     struct var* v=(struct var*)malloc(sizeof(struct var));

     v->tip=0;

     int index=get_arr_index(id);
     if(index==-1)
     {
          printf("Array undeclared!\n");
          yyerror(id);
          exit(0);
     }
     v->valoare_num=arr_size[index];

     return v;
}

int array_insert_str(char* id, char* str, int tip)
{
     int arr_index=get_arr_index(id);
     if(arr_table[arr_index][0].tip!=tip)
     {
          printf("Array type clash!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          if(arr_size[arr_index]>=MAX_SIZE)
          {
               printf("Array insert position out of bound!\n");
               yyerror(id);
               exit(0);
          }
          else
          {
               strcpy(arr_table[arr_index][arr_size[arr_index]].valoare_sir, str);
               arr_table[arr_index][arr_size[arr_index]].tip=tip;
               arr_size[arr_index]++;
          }
     }
     return 1;
}

int array_insert_str_pos(char* id, char* val, int insert_pos, int tip)
{
     int arr_index=get_arr_index(id);
     if(arr_table[arr_index][0].tip!=tip)
     {
          printf("Array type clash!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          if(insert_pos<0 || insert_pos>=arr_size[arr_index] || arr_size[arr_index]>=MAX_SIZE)
          {
               printf("Array insert position out of bound!\n");
               yyerror(id);
               exit(0);
          }
          else
          {
               for(int i=arr_size[arr_index]; i>insert_pos; i--)
               {
                    memcpy(&arr_table[arr_index][i], &arr_table[arr_index][i-1], sizeof(struct var));
               }
               
               strcpy(arr_table[arr_index][insert_pos].valoare_sir, val);
               arr_table[arr_index][insert_pos].tip=tip;
               arr_size[arr_index]++;
          }
     }
     return 1;
}

int array_insert_nr_pos(char* id, double val, int insert_pos, int tip)
{
     int arr_index=get_arr_index(id);
     if(arr_table[arr_index][0].tip!=tip)
     {
          printf("Array type clash!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          if(insert_pos<0 || insert_pos>=arr_size[arr_index] || arr_size[arr_index]>=MAX_SIZE)
          {
               printf("Array insert position out of bound!\n");
               yyerror(id);
               exit(0);
          }
          else
          {
               for(int i=arr_size[arr_index]; i>insert_pos; i--)
               {
                    memcpy(&arr_table[arr_index][i], &arr_table[arr_index][i-1], sizeof(struct var));
               }

               arr_table[arr_index][insert_pos].valoare_num=val;
               arr_size[arr_index]++;
          }
     }
     return 1;
}


int array_insert_nr(char* id, double val, int tip)
{
     int arr_index=get_arr_index(id);
     if(arr_table[arr_index][0].tip!=tip)
     {
          printf("Type clash array insert!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          if(arr_size[arr_index]>=MAX_SIZE)
          {
               printf("Array insert over max size!\n");
               yyerror(id);
               exit(0);
          }
          else
          {
               arr_table[arr_index][arr_size[arr_index]].valoare_num=val;
               arr_size[arr_index]++;
          }
     }
     return 1;
}


int array_insert_id_pos(char* id, char* id_pos, int insert_pos)
{
     int var_index=get_var_index(id_pos);
     int arr_index=get_arr_index(id);
     if(var_table[var_index].tip!=arr_table[arr_index][0].tip)
     {
          printf("Type clash array insert!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          if(insert_pos<0 || insert_pos>=arr_size[arr_index] || arr_size[arr_index]>=MAX_SIZE)
          {
               printf("Array insert position out of bound!\n");
               yyerror(id);
               exit(0);
          }
          else
          {
               for(int i=arr_size[arr_index]; i>insert_pos; i--)
               {
                    memcpy(&arr_table[arr_index][i], &arr_table[arr_index][i-1], sizeof(struct var));
               }

               memcpy(&arr_table[arr_index][insert_pos], &var_table[var_index], sizeof(struct var));
               strcpy(arr_table[arr_index][insert_pos].nume,id);
               arr_size[arr_index]++;
          }
     }
     return 1;
}

int array_insert_id(char* id, char* id_pos)
{
     int var_index=get_var_index(id_pos);
     int arr_index=get_arr_index(id);
     if(var_table[var_index].tip!=arr_table[arr_index][0].tip)
     {
          printf("Types clash array insert!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          if(arr_size[arr_index]>=MAX_SIZE)
          {
               printf("Array insert position outside position!\n");
               yyerror(id);
               exit(0);
          }
          else
          {
               memcpy(&arr_table[arr_index][arr_size[arr_index]], &var_table[var_index], sizeof(struct var));
               strcpy(arr_table[arr_index][arr_size[arr_index]].nume,id);
               arr_size[arr_index]++;
          }
     }
     return 1;
}

int array_delete(char* id)
{
     int index=get_arr_index(id);
     if(arr_size[index]<=0)
     {
          printf("Array can't delete any element!\n");
          yyerror(id);
          exit(0);
     }
     arr_size[index]--;

}

int array_delete_pos(char* id, double pos)
{
     int index=get_arr_index(id);
     if(pos>=arr_size[index] || pos<0 || arr_size[index]<=0)
     {
          printf("Array delete position outside bounds!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          for(int i=(int)pos; i<arr_size[index]-1; i++)
          {
               memcpy(&arr_table[index][i], &arr_table[index][i+1], sizeof(struct var));
          }
          arr_size[index]--;

     }
}

int decl_arr_simple(int tip, char* id, int cnst)
{
     int index=get_arr_index(id);
     if(index!=-1 && CURR_SCOPE==var_table[index].scope)
     {
          printf("Array already declared!\n");
          yyerror(id);
          exit(0);
     }

     strcpy(arr_table[arr_count][0].nume, id);
     arr_table[arr_count][0].valoare_num=0;
     arr_table[arr_count][0].tip=tip;
     arr_table[arr_count][0].constant=cnst;
     arr_table[arr_count][0].scope=CURR_SCOPE;
     strcpy(arr_table[arr_count][0].valoare_sir, "");
     arr_size[arr_count]=0;
     arr_count++;

}

int decl_var_simple(int tip, char* id, int cnst)
{
     int index=get_var_index(id);
     if(index!=-1 && CURR_SCOPE==var_table[index].scope)
     {
          printf("Variable already declared!\n");
          yyerror(id);
          exit(0);
     }

     strcpy(var_table[var_count].nume, id);
     var_table[var_count].valoare_num=0;
     var_table[var_count].tip=tip;
     var_table[var_count].constant=cnst;
     strcpy(var_table[var_count].valoare_sir, "");
     var_table[var_count].scope=CURR_SCOPE;
     var_count++;


}

int decl_var_assign_str(int tip, char* id, char* val, int cnst)
{
     int index=get_var_index(id);
     if(index!=-1 && CURR_SCOPE==var_table[index].scope)
     {
          printf("Variable already declared!\n");
          yyerror(id);
          exit(0);
     }
     strcpy(var_table[var_count].nume, id);
     var_table[var_count].valoare_num=0;
     var_table[var_count].tip=tip;
     var_table[var_count].constant=cnst;
     var_table[var_count].scope=CURR_SCOPE;
     strcpy(var_table[var_count].valoare_sir, val);
     var_count++;
}

int id_assign_str(char* id, char* str, int tip)
{
     int index=get_var_index(id);
     if(index==-1)
     {
          printf("Variable not declared!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          if(var_table[index].tip!=tip)
          {
               printf("Assign types not matching.\n");
               yyerror(id);
               exit(0);
          }

          if(var_table[index].constant==1)
          {
               printf("Cannot modify constant variables!\n");
               yyerror(id);
               exit(0);
          }
          strcpy(var_table[index].valoare_sir, str);
     }
}

int id_assign_var(char* id, struct var* v)
{
     int index=get_var_index(id);
     if(index==-1)
     {
          printf("Variable not declared!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          if(var_table[index].tip!=v->tip && (var_table[index].tip!=4&&v->tip==0))
          {
               printf("Assign types not matching.\n");
               yyerror(id);
               exit(0);
          }

          if(var_table[index].constant==1)
          {
               printf("Cannot modify constant variables!\n");
               yyerror(id);
               exit(0);
          }

          int flag=0;
          if(var_table[index].tip==4)
          {
               flag=1;
          }
          memcpy(&var_table[index], v, sizeof(struct var));
          if(flag==1)
          {
               var_table[index].tip=4;
          }
          strcpy(var_table[index].nume,id);
     }
}

int inc_dec_val(char* id, double x)
{
     int index=get_var_index(id);
     if(index==-1)
     {
          printf("Variable not declared!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          if(var_table[index].constant==1)
          {
               printf("Cannot modify constant variables!\n");
               yyerror(id);
               exit(0);
          }

          var_table[index].valoare_num+=x;
     }
}

struct var * expr_calc_single(struct var* e, int c)
{
     struct var* v=(struct var*)malloc(sizeof(struct var));
     memcpy(v, e, sizeof(struct var));
     if(v->tip<2)
     {
          if(c==1)
          {
               v->valoare_num*=-1;
          }
     } 
     return v;  
}

struct var* expr_calc_double(struct var* e1, struct var* e2, int c)
{
     if(e1->tip>2||e2->tip>2)
     {
          printf("Expressions type not allowed.\n");
          char err[10];
          strcpy(err,'expr');
          yyerror(err);
          exit(0);
     }

     struct var* v=(struct var*)malloc(sizeof(struct var));
     memcpy(v, e1, sizeof(struct var));
     if(e2->tip == 1)
     {
          v->tip=1;
     }
     if(e1->tip<2 && e2->tip<2)
     {
          switch(c)
          {
               case 0:
                    v->valoare_num+=e2->valoare_num;
               break;
                 case 1:
                    v->valoare_num-=e2->valoare_num;
               break;
                 case 2:
                    v->valoare_num*=e2->valoare_num;
               break;
                 case 3:
                    v->valoare_num/=e2->valoare_num;
               break;
                 case 4:
                    v->valoare_num=(v->valoare_num==e2->valoare_num);
               break;
                 case 5:
                    v->valoare_num=(v->valoare_num!=e2->valoare_num);
               break;
                 case 6:
                    v->valoare_num=(v->valoare_num<e2->valoare_num);
               break;
                 case 7:
                    v->valoare_num=(v->valoare_num<=e2->valoare_num);
               break;
                 case 8:
                    v->valoare_num=(v->valoare_num>e2->valoare_num);
               break;
                 case 9:
                    v->valoare_num=(v->valoare_num>=e2->valoare_num);
               break;
                 case 10:
                    v->valoare_num=(v->valoare_num&&e2->valoare_num);
               break;
                 case 11:
                    v->valoare_num=(v->valoare_num||e2->valoare_num);
               break;
          }
     }
     return v;
}

struct var* moveVar(char* i)
{
     int index=get_var_index(i);
     if(index==-1)
     {
          printf("Variable undeclared!\n");
          yyerror(i);
          exit(0);
     }
     else
     {
          return &var_table[index];
     }
}

struct var* moveNum(double n, int tip)
{
     struct var* v=(struct var*)malloc(sizeof(struct var));

     v->valoare_num=n;
     v->tip=tip;

     return v;
}

struct var* moveSir(char* str, int tip)
{
     struct var* v=(struct var*)malloc(sizeof(struct var));

     strcpy(v->valoare_sir, str);
     v->tip=tip;

     return v;
}

struct var* moveArray(struct var* a)
{
     struct var* v = (struct var*)malloc(sizeof(struct var));
     memcpy(v, a, sizeof(struct var));
     return v;
}


struct var* array_get_value(char* id, int pos)
{
     struct var* v=(struct var*)malloc(sizeof(struct var));

     int index=get_arr_index(id);
     if(index==-1)
     {
          printf("Array undeclared!\n");
          yyerror(id);
          exit(0);
     }
     else
     {
          if(arr_size[index]<=pos)
          {
               printf("Array undeclared!\n");
               yyerror(id);
               exit(0);
          }
          else
          {
               
               memcpy(v, &arr_table[index][pos], sizeof(struct var));
          }
     }
     return v;
}


int insertParam(struct parametri* p, int x)
{
     p->param_tip[p->param_nr++]=x;
     return 1;
}

int insertFun(int tip, char* name, struct var* variabila)
{
     for(int i=0;i<fun_count;++i)
     {
          if(strcmp(name,fun_table[i].nume)==0 && tip==fun_table[i].tip && fun_table[i].param->param_nr==0)
          {
               printf("Function already declared!\n");
               yyerror(name);
               exit(0);
          }
     }

     strcpy(fun_table[fun_count].nume, name);
     fun_table[fun_count].tip=tip;
     fun_table[fun_count].return_val=(struct var*)malloc(sizeof(struct var));
     memcpy(fun_table[fun_count].return_val, variabila, sizeof(struct var));
     fun_table[fun_count].param=(struct parametri*)malloc(sizeof(struct parametri));
     fun_table[fun_count].param->param_nr=0;
     fun_count++;
     return 1;
}

int insertFunParam(int tip, char* name, struct parametri* lista, struct var* variabila)
{
     for(int i=0;i<fun_count;++i)
     {
          if(strcmp(name,fun_table[i].nume)==0 && tip==fun_table[i].tip && fun_table[i].param->param_nr==lista->param_nr)
          {
               int flag=1;
               for(int j=0;j<fun_table[i].param->param_nr;++j)
               {
                    if(fun_table[i].param->param_tip[j]!=lista->param_tip[j])
                    {
                         flag=-1;
                    }
               }
               if(flag==1)
               {
                    printf("Function already declared!\n");
                    yyerror(name);
                    exit(0);
               }
          }
     }
     

     strcpy(fun_table[fun_count].nume, name);
     fun_table[fun_count].tip=tip;
     fun_table[fun_count].return_val=(struct var*)malloc(sizeof(struct var));
     memcpy(fun_table[fun_count].return_val, variabila, sizeof(struct var));
     fun_table[fun_count].param=(struct parametri*)malloc(sizeof(struct parametri));
     memcpy(fun_table[fun_count].param, lista, sizeof(struct parametri));
     fun_count++;
     return 1;
}

int afisare_var(struct var* variabila)
{
     if(variabila->tip == 0)
     {
          printf("%.0f",variabila->valoare_num);
     }
     else if(variabila->tip == 1)
     {
          printf("%lf",variabila->valoare_num);
     }
     else if(variabila->tip == 2)
     {
          printf("%c",variabila->valoare_sir[0]);
     }
     else if(variabila->tip == 3)
     {
          printf("%s",variabila->valoare_sir);
     }
     else if(variabila->tip == 4)
     {
          if(variabila->valoare_num==0)
          {
               printf("false");
          }
          else
          {
               printf("true");
          }
     }
     printf("\n");
}

// int => 0 ; float => 1 ; char => 2 ; string => 3 ; bool => 4 ; 
int afisare_sir_var(char* sir, struct var* variabila)
{
     printf("%s ",sir);
     if(variabila->tip == 0)
     {
          printf("%.0f",variabila->valoare_num);
     }
     else if(variabila->tip == 1)
     {
          printf("%lf",variabila->valoare_num);
     }
     else if(variabila->tip == 2)
     {
          printf("%c",variabila->valoare_sir[0]);
     }
     else if(variabila->tip == 3)
     {
          printf("%s",variabila->valoare_sir);
     }
     else if(variabila->tip == 4)
     {
          if(variabila->valoare_num==0)
          {
               printf("false");
          }
          else
          {
               printf("true");
          }
     }
     printf("\n");
}

int get_var_index(char* name)
{
     for(int i=var_count-1; i>=0; i--)
     {
          if(strcmp(name, var_table[i].nume)==0 && (CURR_SCOPE==var_table[i].scope || var_table[i].scope<=1))
          {
               return i;
          }
     }
     return -1;
}

int get_arr_index(char* name)
{
     for(int i=0; i<arr_count; i++)
     {
          if(strcmp(name, arr_table[i][0].nume)==0)
          {
               return i;
          }
     }
     return -1;
}

int yyerror(char * s){
     printf("Eroare: '%s' la linia: %d\n",s,yylineno);
}

int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     yyparse();
} 