#include "expr_node.h"
#include "print_lvl.h"
#include "var_decl_node.h"
#include "arg_node.h"
#include "statement_node.h"

class notof : public expression_node{

    public:
      void eval_ast(int lvl){

          int rank = lvl;
          printing_each_level(rank);

          string temp = "NOT OF UNARY STATEMENT: ";
          cout<< temp <<endl;

          if (expression_ != NULL){
              rank++;
              expression_ -> eval_ast(rank);
          }
      }
};

class block_node : public statement_node{
    protected:
        int *variablel_;
        int temp_level;
    public:

        void eval_ast(int lvl){

            int rank = lvl;
            printing_each_level(rank);

            string to_print = "BLOCK: ";
            cout<< to_print <<endl;

            while (iterator != variablel_ -> end()) {
                temp_level = lvl + 1;
                (*iterator)->eval_ast(temp_level);
                iterator++;
            }
        }

        temp_level = 0;
        statement_ = statementl;
};

class method_decl_node{
    protected:

        int temp_level;
        char *type_, *identifier_;

    public:
        method_decl_node(char *type, char *identifier, list<arg_node *> *argument_list, block_node *blk){
            block_ = blk;
            type_ = type;
        }
        void eval_ast(int lvl){

            temp_level = lvl;

            string temp1 = "METHOD:";

            int t1 = lvl + 1;

            string temp2 = "TYPE:";
            cout<< temp2 <<string(type_)<<endl;

            list <arg_node *>::iterator iterator = argument_list_ -> begin();

            string temp3 = "IDENTIFIER: ";
            cout<< temp3 <<string(identifier_)<<endl;

            while(iterator != argument_list_ -> end()) {
                (*iterator)->eval_ast(lvl+1);
                iterator++;
            }
        }

};


class identifier_List{

    public:
        int levels;
};

class field_decl_node{

    protected:
        int temp_level;

    public:
      void eval_ast(int lvl){

          temp_level = lvl;

          string temp1 =  "FIELD DECLARATION LIST\n";
          cout << temp1;

          temp_level = lvl + 1;

          list <identifier_List *>::iterator iterator = identifier_list -> begin();
          string temp2 = "Field Type :";
          cout << temp2 << Type << "\n";

          while( iterator != identifier_list -> end()) {
              (*iterator)->eval_ast(lvl+1);
              iterator++;
          }
      }

          Type = type;
          temp_level = 0;
};

class if_else_stmt : public statement_node{
    protected:
        expression_node *expn_;

    public:
        if_else_stmt(expression_node *expn, block_node *ifblock, block_node *elseblock){
            ifblock_ = ifblock;
            elseblock_ = elseblock;
            expn_ = expn;
        }
        void eval_ast (int lvl){
            printing_each_level(lvl);

            cout << "IF ELSE STATEMENT: " << endl;

            if (expn_ != NULL)
            {
                printing_each_level(lvl);
                cout<<"CONDITION"<<endl;
                expn_ -> eval_ast(lvl+1);
            }

            if (ifblock_ != NULL)
            {
                printing_each_level(lvl);
                cout<<"THEN"<<endl;
                ifblock_ -> eval_ast(lvl+1);
            }

            if (elseblock_ != NULL)
            {
                printing_each_level(lvl);
                cout<<"ELSE"<<endl;
                elseblock_ -> eval_ast(lvl+1);
            }
        }
};

class continue_statement : public statement_node {
    public:
        continue_statement () {}
        void eval_ast (int lvl){
            printing_each_level(lvl);

            string temp1 = "CONTINUE: ";
            cout << temp1 << endl;
        }
};

class for_statement : public statement_node{
    protected:
        expression_node *start_ , *end_;
        char *identifier_;

    public:

        void eval_ast (int lvl){

            int temp_level = lvl;
            printing_each_level(temp_level);

            string temp1 = "FOR STATEMENT: ";
            cout << temp1 << endl;

            temp_level = lvl + 1;
            printing_each_level(temp_level);

            string temp2 = "IDENTIFIER: " ;
            cout << temp2 << string(identifier_) << endl;

            if (start_ != NULL)
            {
                temp_level = lvl + 1;

                string temp3 = "START";
                cout<<  temp3 <<endl;
                start_ -> eval_ast(lvl+1);
            }

        }
};
