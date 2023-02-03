#include "expr.hpp"
#include <stdexcept>
////////////////////////////////NumExpr
NumExpr::NumExpr(int val){
    this->val = val;
}

bool NumExpr::equals(Expr *e){
    NumExpr *num = dynamic_cast<NumExpr*>(e);
    if (num == NULL) {
        return false;
    }else{
        return this->val == num->val;
    }
}

int NumExpr::interp() {
    return this->val;
}

bool NumExpr::hasVariable(){
    return false;
}

Expr *NumExpr::subst(string s, Expr *expr) {
    return new NumExpr(this->val);
    //return this
}

////////////////////////////////AddExpr
AddExpr::AddExpr(Expr *lhs, Expr *rhs){
    this->lhs = lhs;
    this->rhs = rhs;
}

bool AddExpr::equals(Expr *e){
    AddExpr *add = dynamic_cast<AddExpr*>(e);
    if (add == NULL) {
        return false;
    }else{
        return (this->lhs->equals(add->lhs) && this->rhs->equals(add->rhs));
    }
}

int AddExpr::interp(){
    return this->lhs->interp() + this->rhs->interp();
}

bool AddExpr::hasVariable() {
    return this->lhs->hasVariable() || this->rhs->hasVariable();
}

Expr *AddExpr::subst(string s, Expr *expr){
    return new AddExpr(this->lhs->subst(s, expr), this->rhs->subst(s,expr));
}

////////////////////////////////MultExpr
MultExpr::MultExpr(Expr *lhs, Expr *rhs){
    this->lhs = lhs;
    this->rhs = rhs;
}

bool MultExpr::equals(Expr *e){
    MultExpr *mult = dynamic_cast<MultExpr*>(e);
    if (mult == NULL) {
        return false;
    }else{
        return (this->lhs->equals(mult->lhs) && this->rhs->equals(mult->rhs));
    }
}

int MultExpr::interp(){
    return this->rhs->interp() * this->lhs->interp();
}

bool MultExpr::hasVariable() {
    return this->lhs->hasVariable() || this->rhs->hasVariable();
}

Expr *MultExpr::subst(string s, Expr *expr){
    return new MultExpr(this->lhs->subst(s, expr), this->rhs->subst(s,expr));
}

////////////////////////////////VarExpr
VarExpr::VarExpr(string val) {
    this->val = val;
}

bool VarExpr::equals(Expr *e){
    VarExpr *var = dynamic_cast<VarExpr*>(e);
    if (var == NULL) {
        return false;
    }else{
        return this->val == var->val;
    }
}

int VarExpr::interp() {
    throw std::runtime_error("Variables cannot be interpreted.");
}

bool VarExpr::hasVariable() {
    return true;
}

Expr *VarExpr::subst(string s, Expr *expr) {
    if (this->val == s) {
        return expr;
    }
    return new VarExpr(this->val);
}


