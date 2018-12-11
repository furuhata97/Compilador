

#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include <stack>
//#include <llvm/Value.h>

using namespace std;

/*class Node {
virtual ~Node() {}
    virtual llvm::Value* codeGen(CodeGenContext& context) { }
};*/


class Type;

class Escopo{
  public:
  map<string, Escopo*> *mapEscopo;
  string id;

   virtual ~Escopo() {};

   virtual string Tipo(){};

   virtual Type* Typ(){ };
};

class Array{
 public: 
  Type *type;
  int size;

  Array(){};

  Array(Type *t, int s) {
    type = t;
    size = s;
  };
};


class EscopoGlobal : public Escopo {
public:
  string tipo = "global";

  EscopoGlobal(string i){
    id = i;
    mapEscopo = new map<string, Escopo*>;
  };

  string Tipo(){
    return tipo;
  }

  Type * Typ(){
    return nullptr;
  }
};

class EscopoVar : public Escopo {
 public: 
  string tipo = "var";
  Array *arr;
  Type *type;
  

  EscopoVar(string i, Type *t, int size){
    id = i;
    arr = new Array(t, size);
    type = t;
    mapEscopo = new map<string, Escopo*>;
  };

  EscopoVar(string i, Type *t){
    id = i;
    type = t;
    arr = nullptr;
    mapEscopo = new map<string, Escopo*>;
  };

   string Tipo(){
    return tipo;
  }

  Type* Typ(){
    return type;
  }
};

class EscopoFunc : public Escopo {
public:  
  string tipo = "func";
  Type *type;
  list<string> p;

  EscopoFunc(string i, Type *t){
    id = i;
    type = t;
    mapEscopo = new map<string, Escopo*>;
  };

   string Tipo(){
    return tipo;
  }

 Type* Typ(){
    return type;
  }
};

class EscopoProc : public Escopo {
public:
  string tipo = "proc";
  list<string> s;

  EscopoProc(string i){
    id = i;
    mapEscopo = new map<string, Escopo*>;
  };

   string Tipo(){
    return tipo;
  }

 Type* Typ(){
    return nullptr;
  }
};

class EscopoCmd : public Escopo {
public:
  string tipo = "comando";

  EscopoCmd(string i){
    id = i;
    mapEscopo = new map<string, Escopo*>;
  };

   string Tipo(){
    return tipo;
  }

 Type* Typ(){
    return nullptr;
  }
};

class Dec {
  public:
   virtual ~Dec() {};

   virtual void traducaoDec(stack<Escopo *> *tabela){};
};

class Type {
public:
  virtual string Nome(){ }
};

class pgm {
public:
  list<Dec *> *listDec;

  pgm(list<Dec *> *decs) {
    listDec = decs;
  };

  void traducao(){
    stack<Escopo *> *tabelaDeSimbolos = new stack<Escopo *>();

    EscopoGlobal *global = new EscopoGlobal("");

    tabelaDeSimbolos->push(global);

    for (Dec *v : *listDec){
      if(v != nullptr){
        v->traducaoDec(tabelaDeSimbolos);
      }
    }
  };

};

class Var {
  public:
   virtual ~Var() {};

   virtual void traducaoVar(stack<Escopo *> *tabela, Type *t){};
};

class Exp {
  public:
   virtual ~Exp() {};

   virtual string traducaoExp(stack<Escopo *> *tabela, int linha){};
};

class Cmd {
  public:
   virtual ~Cmd() {};

   virtual void traducaoCmd(stack<Escopo *> *tabela){}; 
};

class Param {
  public:
   virtual ~Param() {};

    virtual string Identificador(){} 
};

class ParamSimples : public Param {
  public:
    string *id;
  
    ParamSimples(string *id) : id(id) {  
    };

    string Identificador(){
      return *id;
    }  
};

class ParamArranjo : public Param {
  public:
    string *id;
  
    ParamArranjo(string *id) : id(id) { 
    };
    
    string Identificador(){
      return *id;
    }    
};

class Params {
public:  
    list<Param *> *param;
    Type *type;
    Params(list<Param *> *p, Type *t) {
      param = p;
      type = t;
    }; 

    void traducaoParams(stack<Escopo *> *tabela){
      for(Param *p : *param){
        Escopo *e;
        if(dynamic_cast<ParamSimples*>(p) != nullptr){
          e = new EscopoVar(p->Identificador(), type);
        }else{
          e = new EscopoVar(p->Identificador(), type, 0);

        }
        if(dynamic_cast<EscopoFunc *>(tabela->top())){
          dynamic_cast<EscopoFunc *>(tabela->top())->p.push_back(type->Nome());
        }
        if(dynamic_cast<EscopoProc *>(tabela->top())){
          dynamic_cast<EscopoProc *>(tabela->top())->s.push_back(type->Nome());
        }
        tabela->top()->mapEscopo->insert(pair<string, Escopo *>(p->Identificador(), e));
      }
    };
};

class Bloco : public Cmd {
public:  
    list<Dec *> *listaDec;
    list<Cmd *> *listaCmd;

    Bloco(list<Dec *> *lDec, list<Cmd *> *lCmd) {
      listaDec = lDec;
      listaCmd = lCmd;
    };

    void traducaoCmd(stack<Escopo *> *tabela){
      if(listaDec != NULL){
        for(Dec *d : *listaDec){
        d->traducaoDec(tabela);
        }
      }

      if(listaCmd != NULL){
        for(Cmd *c : *listaCmd){
          c->traducaoCmd(tabela);
        }
      }
      
    };
};

class DecVar : public Dec {
public:  
    list<Var *> *ListVar;
    Type *t;
   
    DecVar(list<Var *> *listVar, Type *ty){
      ListVar = listVar;
      t = ty;
    };

    void traducaoDec(stack<Escopo *> *tabela){
      for (Var *v : *ListVar){
        if(v != nullptr){
          v->traducaoVar(tabela, t);
        }
          
        }
    };
};

class VarSimples : public Var {
public:  
    std::string *id;
    int line;
    VarSimples(std::string *v, int l) : id(v), line(l) {
    };

    void traducaoVar(stack<Escopo *> *tabela, Type *t){
      if(tabela->top()->mapEscopo->count(*id) == 0){
        EscopoVar *e = new EscopoVar(*id, t);
        tabela->top()->mapEscopo->insert(pair<string, Escopo *>(*id, e));
        return;
      }else{
        cout << "ERRO Linha " << line << " : A variável " << *id << " já foi declarada neste escopo" << endl;
        return;
      };
    };
};

class VarSimplesIni : public Var {
  public:
    string *id;
    Exp *valor;
    int linha;
  
    VarSimplesIni(string *v, Exp *val, int l) : id(v), valor(val), linha(l) {};

    void traducaoVar(stack<Escopo *> *tabela, Type *t){
      if(tabela->top()->mapEscopo->find(*id) == tabela->top()->mapEscopo->end()){
        string tipo = valor->traducaoExp(tabela, linha);
        if(tipo == t->Nome()){
          EscopoVar *e = new EscopoVar(*id, t);
          tabela->top()->mapEscopo->insert(pair<string, Escopo *>(*id, e));
          return;
        }else{
          if(tipo == "erro")
            return;
          else{
            cout << "ERRO Linha " << linha << " : Tipos incompativeis" << endl;
          }
        }
      }else{
        cout << "ERRO Linha " << linha << " : A variável " << *id << " já foi declarada neste escopo" << endl;
      };
    };

};

class VarArranjo : public Var {
  public:
    string *id;
    int tamanho;
    int linha;
  
    VarArranjo(string *v, int tamanho, int i) : id(v), tamanho(tamanho), linha(i){ };

    void traducaoVar(stack<Escopo *> *tabela, Type *t){
      if(tabela->top()->mapEscopo->count(*id) == 0){
          EscopoVar *e = new EscopoVar(*id, t, tamanho);
          tabela->top()->mapEscopo->insert(pair<string, Escopo *>(*id, e));
          return;
      }else{
        cout << "ERRO Linha " << linha << " : A variável " << *id << " já foi declarada neste escopo" << endl;
      };      
    };
};

class VarArranjoIni : public Var {
  public:
    string *id;
    int tamanho;
    list<Exp *> *listaValores;
    int linha;
  
    VarArranjoIni(string *v, int tamanho, list<Exp *> *lValores, int l) : id(v), tamanho(tamanho), listaValores(lValores), linha(l){};

    void traducaoVar(stack<Escopo *> *tabela, Type *t){
      if(tabela->top()->mapEscopo->count(*id) == 0){
        list<string> valores;
        for(Exp *e : *listaValores){
          valores.push_back(e->traducaoExp(tabela, linha));
        }
        for(string s : valores){
          if(s != t->Nome()){
            cout << "ERRO Linha " << linha << " : Encontrado um valor do tipo " << s << " em uma variável do tipo " << t->Nome() << endl;
            return;
          }
        }
        if(valores.size() > tamanho){
          cout << "ERRO Linha " << linha << " : A quantidade de elementos excede o tamanho máximo da variável " << *id << endl;
          return;
        }    
        EscopoVar *e = new EscopoVar(*id, t, tamanho);
        tabela->top()->mapEscopo->insert(pair<string, Escopo *>(*id, e));
      }else{
        cout << "ERRO Linha " << linha << " : A variável " << *id << " já foi declarada neste escopo" << endl;
      };      
    };
};

class VarDecSimples : public Exp {
  public:
    string *id;
  
    VarDecSimples(string *v) : id(v){ };

    string traducaoExp(stack<Escopo *> *tabela, int linha){
      stack<Escopo *> t = *tabela;
      while(!t.empty()){
        if(t.top()->mapEscopo->find(*id) == t.top()->mapEscopo->end()){
          t.pop();
        }else{
          if(t.top()->mapEscopo->find(*id)->second->Tipo() == "var"){
            string tipo = t.top()->mapEscopo->find(*id)->second->Typ()->Nome();
            if(tipo == "int"){
              return "int";
            }
            if(tipo == "string"){
              return "string";
            }
            if(tipo == "bool"){
              return "bool";
            }
          }else{
            t.pop();
          }
        }
      }
      cout << "ERRO Linha " << linha << " : Variável " << *id << " inexistente" << endl;
      return "erro";
    }
};

class VarDecArranjo : public Exp {
  public:
    string *id;
    Exp *valor;
  
    VarDecArranjo(string *v, Exp *val): id(v), valor(val){};

    string traducaoExp(stack<Escopo *> *tabela, int linha){
      stack<Escopo *> t = *tabela;
      while(!t.empty()){
        if(t.top()->mapEscopo->find(*id) == t.top()->mapEscopo->end()){
          t.pop();
        }else{
          if(t.top()->mapEscopo->find(*id)->second->Tipo() == "var" && static_cast<EscopoVar*>(t.top()->mapEscopo->find(*id)->second)->arr != nullptr){
            string tipo = t.top()->mapEscopo->find(*id)->second->Typ()->Nome();
            string t = valor->traducaoExp(tabela, linha);
            if(t == "int"){
              if(tipo == "int"){
                return "int";
              }
              if(tipo == "string"){
                return "string";
              }
              if(tipo == "bool"){
                return "bool";
              }              
            }else{
              cout << "ERRO Linha " << linha << " : O valor do índice da variável " << *id << " precisa ser inteiro" << endl;
              return "erro";
            }
          }else{
            t.pop();
          }
        }
      }
      cout << "ERRO Linha " << linha << " : Variável " << *id << " inexistente" << endl;
      return "erro";
    }
};

class Number_node : public Exp {
  public:
    int valor;
  
    Number_node(int val) : valor(val) {
     };

    string traducaoExp(stack<Escopo *> *tabela, int linha){
      return "int";
    };
};

class Literal : public Exp{
  public:
    string *valor;
  
    Literal(string *v) : valor(v){
    };

    string traducaoExp(stack<Escopo *> *tabela, int linha){
      if(*valor == "true" || *valor == "false"){
        return "bool";
      }else
      return "string";
    };
};

class BinaryExpression : public Exp {
  public:
    Exp *v1;
    Exp *v2;
    string *op;

  
    BinaryExpression(Exp *v1, Exp *v2, string *op) : v1(v1), v2(v2), op(op) { 
    };

    string traducaoExp(stack<Escopo *> *tabela, int linha){
      string e1 = v1->traducaoExp(tabela, linha);
      string e2 = v2->traducaoExp(tabela, linha);

      if(*op == "+" || *op == "-" || *op == "*" || *op == "/" || *op == "%"){
        if(e1 == "int" && e2 == "int"){
          return "int";
        }else{
          cout << "ERRO Linha: " << linha << " : Operandos da operação aritmética não são do tipo int" << endl;
          return "erro";
        }
      }

      if(*op == ">" || *op == ">=" || *op == "<" || *op == "<="){
        if(e1 == "int" && e2 == "int"){
          return "bool";
        }else{
          cout << "ERRO Linha: " << linha << " : Operandos da operação relacional não são do tipo int" << endl;
          return "erro";
        }
      }

      if(*op == "==" || *op == "!="){
          return "bool";
      }

      if(*op == "&&" || *op == "||"){
        if(e1 == "bool" && e2 == "bool"){
          return "bool";
        }else{
          cout << "ERRO Linha: " << linha << " : Operandos da operação lógica não são do tipo bool" << endl;
          return "erro";
        }
      }
    };
};

class NegExpression : public Exp {
  public:
    Exp *valor;
  
    NegExpression(Exp *valor) : valor(valor) {
    };

    string traducaoExp(stack<Escopo *> *tabela, int linha){
      string e1 = valor->traducaoExp(tabela,linha);

      if(e1 == "int"){
        return "int";
      }else{
        cout << "ERRO Linha: " << linha << " : Operandos não são do tipo int" << endl;
          return "erro";
      }
    };

};

class NotExpression : public Exp {
  public:
    Exp *valor;
  
    NotExpression(Exp *valor) : valor(valor) { 
    };

    string traducaoExp(stack<Escopo *> *tabela, int linha){
      string e1 = valor->traducaoExp(tabela, linha);

      if(e1 == "bool"){
        return "bool";
      }else{
        cout << "ERRO Linha: " << linha << " : Operandos não são do tipo bool" << endl;
          return "erro";
      }
    };
};

class TernaryExpression : public Exp {
  public:
    Exp *v1;
    Exp *v2;
    Exp *v3;
  
    TernaryExpression(Exp *v1, Exp *v2, Exp *v3) : v1(v1), v2(v2), v3(v3) { 
    };

    string traducaoExp(stack<Escopo *> *tabela, int linha){
      string e1 = v1->traducaoExp(tabela, linha);
      string e2 = v2->traducaoExp(tabela, linha);
      string e3 = v3->traducaoExp(tabela, linha);

      if(e1 == "bool"){
        if(e2 == e3){
          return "bool";
        }else{
        cout << "ERRO Linha: " << linha << " : As expressões de se e senão apresentam tipos diferentes" << endl;
          return "erro";
        }
      }else{
        cout << "ERRO Linha: " << linha << " : A expressão ternária não resulta em tipo bool" << endl;
          return "erro";
      }
    };
};

class ProcSimples : public Dec {
  public:
    string *id;
    Bloco *bloco;
  
    ProcSimples(string *id, Bloco *bloco) : id(id), bloco(bloco) { 
    };

    void traducaoDec(stack<Escopo *> *tabela){
      EscopoProc *prc = new EscopoProc(*id);
      tabela->top()->mapEscopo->insert(pair<string, Escopo *>(*id, prc));
      tabela->push(prc);
      bloco->traducaoCmd(tabela);
      tabela->pop();
    };
};

class ProcIni : public Dec {
  public:
    list<Params *> *params; 
    string *id;
    Bloco *bloco;
  
    ProcIni(string *i, list<Params *> *p, Bloco *b) : params(p), bloco(b), id(i) {
    };

    void traducaoDec(stack<Escopo *> *tabela){
      EscopoProc *prc = new EscopoProc(*id);
      tabela->top()->mapEscopo->insert(pair<string, Escopo *>(*id, prc));
      tabela->push(prc);
      for(Params *p : *params){
        p->traducaoParams(tabela);
      }
      bloco->traducaoCmd(tabela);
      tabela->pop();
    };
};

class FuncSimples : public Dec {
  public:
    string *id;
    Bloco *bloco;
    Type *type;
  
    FuncSimples(string *i, Type *t, Bloco *b) : id(i), type(t), bloco(b) { 
    };

    void traducaoDec(stack<Escopo *> *tabela){
      EscopoFunc *fun = new EscopoFunc(*id, type);
      tabela->top()->mapEscopo->insert(pair<string, Escopo *>(*id, fun));
      tabela->push(fun);
      bloco->traducaoCmd(tabela);
      tabela->pop();
    };
};

class FuncIni : public Dec {
  public:
    string *id;
    list<Params *> *params; 
    Bloco *bloco;
    Type *type;
  
    FuncIni(string *i, list<Params *> *p, Type *t, Bloco *b) : id(i), params(p), bloco(b), type(t) {
    };

    void traducaoDec(stack<Escopo *> *tabela){
      EscopoFunc *fun = new EscopoFunc(*id, type);
      tabela->top()->mapEscopo->insert(pair<string, Escopo *>(*id, fun));
      tabela->push(fun);
      for(Params *p : *params){
        p->traducaoParams(tabela);
      }
      bloco->traducaoCmd(tabela);
      tabela->pop();
    };
};

class Atrib : public Cmd {
  public:
    Exp *variavel;
    Exp *exp;
    string *op;
    int linha;
  
    Atrib(Exp *variavel, Exp *exp, string *op, int linha) : variavel(variavel), exp(exp), op(op), linha(linha) {
    };

    void traducaoCmd(stack<Escopo *> *tabela){
      string s = variavel->traducaoExp(tabela, linha);
      string z = exp->traducaoExp(tabela, linha);

      if(s != "erro"){
        if(z != "erro"){
          if(s == z){
            return;
          }else{
            if(dynamic_cast<VarDecSimples*>(variavel) != nullptr)
              cout << "ERRO Linha " << linha << " : Incompatibilidade de tipos na variável " << *dynamic_cast<VarDecSimples*>(variavel)->id << ". Tipos " << s << " e " << z << endl;
            else
              cout << "ERRO Linha " << linha << " : Incompatibilidade de tipos na variável " << *dynamic_cast<VarDecArranjo*>(variavel)->id << ". Tipos " << s << " e " << z << endl;
            return;
          }
        }else{
          return;
        }
      }else{
        return;
      }
    };
};

class CmdIf : public Cmd {
  public:
    Exp *exp;
    Cmd *cmd;
    int linha;
  
    CmdIf(Exp *exp, Cmd *cmd, int l) : exp(exp), cmd(cmd), linha(l) {
    };

    void traducaoCmd(stack<Escopo *> *tabela){
      Escopo *e = new EscopoCmd("if");
      tabela->push(e);
      string s = exp->traducaoExp(tabela, linha);
      if(s != "bool"){
        cout << "ERRO Linha " << linha << " : Expressão precisa resultar em uma valor lógico" << endl;
      }
      cmd->traducaoCmd(tabela);
      tabela->pop();
    };
};

class CmdIfElse : public Cmd {
  public:
    Exp *exp;
    Cmd *cmd1;
    Cmd *cmd2;
    int linha;
  
    CmdIfElse(Exp *exp, Cmd *cmd1, Cmd *cmd2, int l) : exp(exp), cmd1(cmd1), cmd2(cmd2), linha(l) {
    };

    void traducaoCmd(stack<Escopo *> *tabela){
      Escopo *e = new EscopoCmd("if_else");
      tabela->push(e);
      string s = exp->traducaoExp(tabela, linha);
      if(s != "bool"){
        cout << "ERRO Linha " << linha << " : Expressão precisa resultar em uma valor lógico" << endl;
      }
      cmd1->traducaoCmd(tabela);
      cmd2->traducaoCmd(tabela);
      tabela->pop();
    };
};

class CmdWhile : public Cmd {
  public:
    Exp *exp;
    Cmd *cmd;
    int linha;
  
    CmdWhile(Exp *exp, Cmd *cmd, int l) : exp(exp), cmd(cmd), linha(l) {
    };

    void traducaoCmd(stack<Escopo *> *tabela){
      Escopo *e = new EscopoCmd("while");
      tabela->push(e);
      string s = exp->traducaoExp(tabela, linha);
      if(s != "bool"){
        cout << "ERRO Linha " << linha << " : Expressão precisa resultar em uma valor lógico" << endl;
      }
      cmd->traducaoCmd(tabela);
      tabela->pop();
    };
};

class CmdFor : public Cmd {
  public:
    Cmd *a;
    Exp *exp;
    Cmd *b;
    Cmd *cmd;
    int linha;
  
    CmdFor(Cmd *a, Exp *exp, Cmd *b, Cmd *cmd, int linha) : a(a), exp(exp), b(b), cmd(cmd), linha(linha) {
    };

    void traducaoCmd(stack<Escopo *> *tabela){
      Escopo *e = new EscopoCmd("for");
      tabela->push(e);
      a->traducaoCmd(tabela);
      string s = exp->traducaoExp(tabela, linha);
      if(s != "bool"){
        cout << "ERRO Linha " << linha << " : Expressão precisa resultar em uma valor lógico" << endl;
      }
      b->traducaoCmd(tabela);
      cmd->traducaoCmd(tabela);
      tabela->pop();
    };
};

class CmdStop : public Cmd {
 public:
    int linha;

    CmdStop(int linha) : linha(linha){
    };

    void traducaoCmd(stack<Escopo *> *tabela){
      stack<Escopo *> t = *tabela;
      while(!t.empty()){
        if(t.top()->Tipo() != "for" && t.top()->Tipo() != "while"){
          t.pop();
        }else{
          return;
        }
      }
      cout << "ERRO Linha " << linha << " : Comando STOP deve ser usado dentro de um comando FOR ou WHILE" << endl;
      return;
    };
};

class CmdSkip : public Cmd {
 public: 
    int linha;
    CmdSkip(int l) : linha(l) {
    };

    void traducaoCmd(stack<Escopo *> *tabela){
      stack<Escopo *> t = *tabela;
      while(!t.empty()){
        if(t.top()->Tipo() != "for" && t.top()->Tipo() != "while"){
          t.pop();
        }else{
          return;
        }
      }
      cout << "ERRO Linha " << linha << " : Comando SKIP deve ser usado dentro de um comando FOR ou WHILE" << endl;
      return;
    };
};

class CmdReturn : public Cmd {
  public:
    Exp *exp;
    int linha;
  
    CmdReturn(Exp *exp, int linha) : exp(exp), linha(linha) {};

    void traducaoCmd(stack<Escopo *> *tabela){
      stack<Escopo *> t = *tabela;
      while (!t.empty()){
        if(t.top()->Tipo() == "func"){
          if(exp != NULL){
            string s = exp->traducaoExp(tabela, linha);
            if(t.top()->Typ()->Nome() != s){
              cout << "ERRO Linha " << linha << " : O tipo de retorno deve ser o mesmo da função. Retornando " << t.top()->Typ()->Nome() << " na função " << t.top()->id << endl;
              return;
            }else
              return;
          }else{
            cout << "ERRO Linha " << linha << " : Comando de retorno deve voltar um tipo dentro de função" << endl;
            return;
          }
        }else{
          if(t.top()->Tipo() == "proc"){
            if(exp != NULL){
              cout << "ERRO Linha " << linha << " : Procedimento não deve retornar uma expressão" << endl;
              return;
            }else
              return;
          }else{
            t.pop();
          }
        }        
      }
      cout << "ERRO Linha " << linha << " : O comando de retorno só pode ser usado dentro de Funções ou Procedimentos" << endl;
      return;
    };
};

class ChamadaProc : public Cmd {
  public:
    string *id;
    list<Exp *> *exps;
    int linha;
  
    ChamadaProc(string *id, list<Exp *> *exps, int linha) : id(id), exps(exps), linha(linha) { };

    void traducaoCmd(stack<Escopo *> *tabela){
      stack<Escopo *> t = *tabela;
      while(!t.empty()){
        if(t.top()->mapEscopo->count(*id) != 0 && t.top()->mapEscopo->find(*id)->second->Tipo() == "proc"){
          EscopoProc *p = static_cast<EscopoProc *>(t.top()->mapEscopo->find(*id)->second);
          if(exps == nullptr && !p->s.empty()){
            cout << "ERRO Linha " << linha << " : O procedimento " << *id << " deve ser chamado com no mínimo " << p->s.size() << " parâmetros" << endl;
            return;
          }
          if (p->s.size() == exps->size()){
              for(int i = 0; i < p->s.size(); i++){
                auto it1 = std::next(p->s.begin(), i);
                auto it2 = std::next(exps->begin(), i);
                Exp * ex = *it2;
                if(*it1 != ex->traducaoExp(tabela, linha)){
                  cout << "ERRO Linha " << linha << " : Os tipos dos argumentos da chamada do procedimento não batem com os tipos da declaração do procedimento" << endl;
                }
              }
              return;
          }else{
            cout << "ERRO Linha " << linha << " : Quantidade de argumentos na chamada do procedimento " << *id << " é inválido " << endl;
          }

        }else{
          t.pop();
        }
      }
      cout << "ERRO Linha " << linha << ": Procedimento " << *id << " não declarado" << endl;
      return;
    };
};

class ChamadaFunc : public Exp {
  public:
    string *id;
    list<Exp *> *exps;
  
    ChamadaFunc(string *id, list<Exp *> *exps) : id(id), exps(exps) { };

    string traducaoExp(stack<Escopo *> *tabela, int linha){
      stack<Escopo *> t = *tabela;
      while(!t.empty()){
        if(t.top()->mapEscopo->count(*id) != 0 && t.top()->mapEscopo->find(*id)->second->Tipo() == "func"){
          EscopoFunc *p = static_cast<EscopoFunc *>(t.top()->mapEscopo->find(*id)->second);
          if(exps == nullptr && !p->p.empty()){
            cout << "ERRO Linha " << linha << " : É necessário a passagem de parâmetros na chamada da função " << *id << endl;
            return "erro";
          }
          if (p->p.size() == exps->size()){
              for(int i = 0; i < p->p.size(); i++){
                auto it1 = std::next(p->p.begin(), i);
                auto it2 = std::next(exps->begin(), i);
                Exp * ex = *it2;
                if(*it1 != ex->traducaoExp(tabela, linha)){
                  cout << "ERRO Linha " << linha << " : Os tipos dos argumentos da chamada da função não batem com os tipos da declaração da função" << endl;
                  return "erro";
                }
              }
              return p->Typ()->Nome();
          }else{
            cout << "ERRO Linha " << linha << " : Quantidade de argumentos na chamada da função " << *id << " é inválido " << endl;
          }

        }else{
          t.pop();
        }
      }
      
      cout << "ERRO Linha " << linha << ": Função " << *id << " não declarada" << endl;
      return "erro";
    };
};

class CmdRead : public Cmd {
  public:
    Exp *var;
    int linha;
  
    CmdRead(Exp *var, int l) : var(var), linha(l) { };

    void traducaoCmd(stack<Escopo *> *tabela){
      var->traducaoExp(tabela, linha);
    }
};

class CmdWrite : public Cmd {
  public:
    list<Exp *> *exps;
    int linha;
    CmdWrite(list<Exp *> *exps, int l) : exps(exps), linha(l){ };

    void traducaoCmd(stack<Escopo *> *tabela){
      for(Exp *e : *exps){
        e->traducaoExp(tabela, linha);
      }
    }
};

class TypeInt : public Type {
  public:
    string *valor;
  
    TypeInt(string *v) {
      valor = v;
    };

    string Nome(){
      return *valor;
     };
};

class TypeString : public Type {
  public:
    string *s;
    int tamanho;
  
    TypeString(string *tipo, int t) {
      s = tipo;
      tamanho = t;
    };

    TypeString(string *tipo) {
      s = tipo;
      tamanho = 0;
    };

    string Nome(){
      return *s;
     };
};

class TypeBool : public Type {
  public:
    string *bo;
  
    TypeBool(string *b) {
      bo = b;
    };

    string Nome(){
      return *bo;
     };
};

