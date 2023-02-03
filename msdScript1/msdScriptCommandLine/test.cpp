#include "catch.hpp"
#include "expr.hpp"

TEST_CASE( "msdscript" ){
    SECTION("Equals"){
        //NumExpr
        CHECK( (new NumExpr(1))->equals(nullptr) == false );
        CHECK( (new NumExpr(1))->equals(new NumExpr(1)) == true );
        CHECK( (new NumExpr(1))->equals(new NumExpr(2)) == false );

        //AddExpr
        CHECK( (new AddExpr(new NumExpr(2),new NumExpr(3)))->equals(nullptr)==false );
        CHECK( (new AddExpr(new NumExpr(2),new NumExpr(3)))->equals(new AddExpr(new NumExpr(2),new NumExpr(3)))==true );
        CHECK( (new AddExpr(new NumExpr(2),new NumExpr(3)))->equals(new AddExpr(new NumExpr(3),new NumExpr(2)))==false );

        //MultExpr
        CHECK( (new MultExpr(new NumExpr(2),new NumExpr(2)))->equals(nullptr)==false );
        CHECK( (new MultExpr(new NumExpr(2),new NumExpr(2)))->equals(new MultExpr(new NumExpr(2),new NumExpr(2)))==true );
        CHECK( (new MultExpr(new NumExpr(2),new NumExpr(2)))->equals(new MultExpr(new NumExpr(1),new NumExpr(2)))==false );

        //VarExpr
        CHECK( (new VarExpr("ABC"))->equals(nullptr) == false );
        CHECK( (new VarExpr("ABC"))->equals(new VarExpr("ABC")) == true );
        CHECK( (new VarExpr("ABC"))->equals(new VarExpr("CBA")) == false );
    }

    SECTION("Interpret"){
        CHECK((new AddExpr(new NumExpr(2), new NumExpr(2)))->interp() == 4);
        CHECK((new AddExpr(new NumExpr(2), new NumExpr(3)))->interp() == 5);
        CHECK((new MultExpr(new NumExpr(2), new NumExpr(2)))->interp() == 4);
        CHECK((new MultExpr(new NumExpr(2), new NumExpr(3)))->interp() == 6);
        CHECK( (new MultExpr(new NumExpr(3), new NumExpr(2)))
                       ->interp()==6 );
        CHECK( (new AddExpr(new AddExpr(new NumExpr(10), new NumExpr(15)),new AddExpr(new NumExpr(20),new NumExpr(20))))
                       ->interp()==65);

        CHECK_THROWS_WITH( (new VarExpr("x"))->interp(), "Variables cannot be interpreted." );
    }

    SECTION("HasVariable"){
        CHECK((new NumExpr(1))->hasVariable() == false);
        CHECK((new VarExpr("x"))->hasVariable() == true);
        CHECK((new AddExpr(new VarExpr("y"), new NumExpr(2)))->hasVariable() == true);
        CHECK((new MultExpr(new VarExpr("z"), new NumExpr(3)))->hasVariable() == true);
    }

    SECTION("Subst"){
        CHECK( (new AddExpr(new VarExpr("x"), new NumExpr(7)))
                       ->subst("x", new VarExpr("y"))
                       ->equals(new AddExpr(new VarExpr("y"), new NumExpr(7))) );
        CHECK( (new VarExpr("x"))
                       ->subst("x", new AddExpr(new VarExpr("y"),new NumExpr(7)))
                       ->equals(new AddExpr(new VarExpr("y"),new NumExpr(7))) );
    }
}