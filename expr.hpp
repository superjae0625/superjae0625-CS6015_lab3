#ifndef expr_hpp
#define expr_hpp

#include <stdio.h>
#include <iostream>
#include <string>


using namespace std;

class Expr{
public:
    virtual bool equals(Expr *e) = 0;
    virtual int interp() = 0;
    virtual bool hasVariable() = 0;
    virtual Expr* subst(string s, Expr* expr) = 0;

};

class NumExpr : public Expr {
public:
    int val;

    NumExpr(int val);
    bool equals(Expr *e);
    int interp();
    bool hasVariable();
    Expr* subst(string s, Expr* expr);
};

class AddExpr : public Expr{
public:
    Expr *lhs;
    Expr *rhs;

    AddExpr(Expr *lhs, Expr *rhs);
    bool equals(Expr *e);
    int interp();
    bool hasVariable();
    Expr* subst(string s, Expr* expr);
};

class MultExpr : public Expr{
public:
    Expr *lhs;
    Expr *rhs;
    
    MultExpr(Expr *lhs, Expr *rhs);
    bool equals(Expr *e);
    int interp();
    bool hasVariable();
    Expr* subst(string s, Expr* expr);
};

class VarExpr : public Expr {
public:
    string val;
    VarExpr(string val);
    bool equals(Expr *e);
    int interp();
    bool hasVariable();
    Expr* subst(string s, Expr* expr);
};

#endif /* expr_hpp */
