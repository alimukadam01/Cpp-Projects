#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double Convert(double degree)
{
    double pi = 3.14159265359;
    return (degree * (pi / 180));
}

class AbstractTerm
{
public:
    int coeffecient;
    int power;

    AbstractTerm()
    {}

    virtual AbstractTerm* derivative() = 0;

    virtual double evaluate(double x) = 0;

    virtual string toString() = 0;
};

struct ProjNode
{
    AbstractTerm* t;
    ProjNode* next;
};

class ProjLinkedList
{
public:
    ProjNode* head;

    // Default constructor
    ProjLinkedList()
    {
       head = new ProjNode(); 
       head->t = NULL;
       head->next = NULL;
    }

    // adding nodes
    ProjNode* add(ProjNode* head, AbstractTerm* t)
    {
        ProjNode* ptr = new ProjNode();
        ptr->t = head->t;
        ptr->next = head->next;
        head->next = ptr;
        head->t = t;
        return head;
    }

    // getting node at specified position
    AbstractTerm* getAt(ProjNode* head, int index)
    {
        ProjNode* ptr = head;

        int count = 0;
        while (ptr != NULL)
        {
            if (count == index)
                return (ptr->t);
            count++;
            ptr = ptr->next;
        }
        return NULL;
    }
};

enum TrigType
{
    SINE,
    COSINE
};

class ConstantTerm : public AbstractTerm
{
public:
    int coeffecient;
    int power = 0;

    ConstantTerm() {};
    ConstantTerm(int x)
    {
        coeffecient = x;
    }

    AbstractTerm* derivative()
    {
        AbstractTerm* d;
        d = NULL;
        return d;
    }

    string toString()
    {
        return "+" + to_string(coeffecient);
    }

    double evaluate(double x)
    {
        return coeffecient;
    }
};

class LinearTerm : public ConstantTerm
{
public:
    int coeffecient;
    int power = 1;
    
    LinearTerm() {};

    LinearTerm(int x)
    {
        coeffecient = x;
    }

    AbstractTerm* derivative()
    {

        AbstractTerm* d = new ConstantTerm(coeffecient);
        return d;
    }

    double evaluate(double x)
    {
        return coeffecient*x;
    }

    string toString()
    {
        if (coeffecient > 0){
            return "+" + to_string(coeffecient) + "x";
        }
        return to_string(coeffecient) + "x";
    }

};

class TrigTerm : public LinearTerm
{
public:
    int coeffecient;
    int power = -1;
    TrigType b;

    TrigTerm(const int a, const  TrigType b) {
        this->coeffecient = a;
        this->b = b;
    }

    AbstractTerm* derivative()
    {
        AbstractTerm* d;

        if (b == SINE)
        {
            AbstractTerm* d = new TrigTerm(coeffecient, COSINE);
            return d;
        }
        else
        {
            AbstractTerm* d = new TrigTerm(-coeffecient, SINE);
            return d;
        }
    }

    double evaluate(double x)
    {
        x = Convert(x);
        
        if (b == SINE)
        {
            return coeffecient * sin(x);
        }
        else
        {
            return coeffecient * cos(x);
        }
    }

    string toString()
    {
        if (coeffecient > 0){
            if (b == SINE){
                return "+" + to_string(coeffecient) + "sin(x)";
            }
            else
            {
                return "+" + to_string(coeffecient) + "cos(x)";
            }
        }
        else{
            if (b == SINE){
                return to_string(coeffecient) + "sin(x)";
            }
            else
            {
                return to_string(coeffecient) + "cos(x)";
            }
        }
    }
};

class PolynomialTerm : public LinearTerm
{
    int coeffecient;
    int power;
    
public:
    PolynomialTerm(int a, int b)
    {
        this->coeffecient = a;
        this->power = b;
    }

    AbstractTerm* derivative()
    {
        if (coeffecient == 2)
        {
            AbstractTerm* d = new LinearTerm(2 * coeffecient);
            return d;
        }
        else
        {
            AbstractTerm* d = new PolynomialTerm((coeffecient * power), (power - 1));
            return d;
        }
    }

    string toString()
    {
        return to_string(coeffecient) + "x^" + to_string(power);
    }

    double evaluate(double x)
    {
        return coeffecient * (pow(x, power));
    }
};

class Expression {

    public:
    ProjLinkedList Ats;

    Expression() {
        Ats = ProjLinkedList();
    }

    Expression* getDerivative() 
    {
        Expression* e =  new Expression();
        ProjNode* ptr = new ProjNode();
        ptr = Ats.head;
        
        while(ptr->next != NULL){
            if(ptr->t->derivative()!=0){
                e->Ats.add(e->Ats.head, ptr->t->derivative());
                ptr = ptr->next;
                
            }
        }
        return e;
    }

    double getEvaluation(double x) {
        double sum;
        ProjNode* ptr = new ProjNode();
        ptr = Ats.head;
        
        while(ptr->next != NULL){
            sum += ptr->t->evaluate(x);
            ptr = ptr->next;
        }
        return sum;
    }

    string toString() {
        string s;
        ProjNode* ptr = new ProjNode();
        ptr = Ats.head;
        while(ptr->next != NULL){
            s += ptr->t->toString();
            ptr = ptr->next;
        }
        return s;
    }

    Expression operator += (AbstractTerm* &b) {
        Expression e;
        this->Ats.add(Ats.head, b);
        return e;
    }
    
    ~Expression(){}
};


int main(){
    
    AbstractTerm* t1 = new LinearTerm(5);
    AbstractTerm* t2 = new PolynomialTerm(-4,3);
    AbstractTerm* t3 = new TrigTerm(-6, TrigType::COSINE);
    
    cout << t1->toString() << endl; // + 5x
    cout << t1->evaluate(5) << endl; // 25
    cout << t2->toString() << endl; // - 4x^3
    cout << t2->evaluate(2) << endl; // -32
    cout << t3->toString() << endl; // - 6cos(x)
    cout << t3->evaluate(45) << endl; // -4.24
    
    Expression* e1 = new Expression();
    (*e1) += t1;
    (*e1) += t2;
    (*e1) += t3;
    
    Expression* e2 = e1->getDerivative();
    
    cout << e1->toString() << endl; // - 4x^3 + 5x - 6cos(x)
    cout << e2->toString() << endl; // - 12x^2 + 5 + 6sin(x)
    cout << e1->getEvaluation(0) << endl; // -6
    cout << e2->getEvaluation(0) << endl; // 5
    
    delete e2;
    delete e1;
        
    return 0;
}