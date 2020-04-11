#include "./LOGO.h"
#ifdef APPLE
#include <allegro5/allegro.h> //**
#endif



START_PROGRAM
PROGRAM_BEGIN_PRINT

/*MAKE var0 = NUMBER:23
MAKE var1 = WORD : "Dimitris"
MAKE var2 = BOOLEAN : TRUE
MAKE va = WORD:"lol";
MAKE lala = NUMBER: 1;

//va = WORD: "kek";
MAKE myMoves = LIST[WORD:"LA", lala, LIST[NUMBER: 19]]
;output(myMoves);
MAKE movez = LIST[WORD: "START", myMoves]
;output(movez);
MAKE book = SENTENCE(WORD: "_ENA_", WORD : "_DYO_ ", WORD : "_TRIA_ ")
;output(book);

;SETITEM({3,1}, myMoves, WORD: "LOT");


MAKE astakos = NUMBER : 5
MAKE xx = NUMBER: 15
MAKE www = WORD: "yolo"
MAKE ww = WORD: "yolo"
//;astakos = xx;
;cout << "AST1111111: " << astakos.getNumber();

ASSIGN xx = SUM(NUMBER: 1, NUMBER : 1, astakos);
MAKE fagget = DIFFERENCE(NUMBER: 5, NUMBER: 3);
cout << "XXXXXXXXXX: ";
output(xx);

//ASSIGN astakos = DIFFERENCE(NUMBER : 1, xx);
cout << "ASTAKOS: ";
;output(astakos);
cout <<endl;

IF OR(astakos == 5, ww == www) DO
	IF xx <= (NUMBER: 10) DO
	cout << "xx is 10\n";
	ELSE
	cout << "xx NOT 10\n";
	END
ELIF astakos == SUM (NUMBER:2, NUMBER: 1, NUMBER: 3) DO
	cout << "IS YOLO\n";
ELSE
	cout << "ELSE CASE\n";
END

MAKE lista = LIST[astakos, WORD: "second"]

REPEAT 5 TIMES DO
	MAKE zari = NUMBER: 6
END

IF astakos == ITEM({1}, lista) DO
	cout << "IF\n";
ELIF astakos != 5 DO
	cout << "ELIF\n";
ELSE
	MAKE vand = WORD: "ward"
END


MAKE trigona = SENTENCE(WORD: "alfadi")
//;cout << "TRIGONA  " << ff.getType()

;output(trigona);


//MAKE number1 = NUMBER:23
MAKE number2 = NUMBER: 5


MAKE minucVar = MINUS(number2);

cout << " MINUS: " << minucVar.getNumber() << endl;

MAKE producVar = PRODUCT(NUMBER: 1, NUMBER : 2, NUMBER : 3, NUMBER : 4,  NUMBER : 5);

MAKE producVar2 = PRODUCT(minucVar, NUMBER : 4, NUMBER : 5);
cout << " PRODUCT: " << producVar.getNumber() << " PRODUCT2: " << producVar2.getNumber() << endl;

*/
/*
MAKE e = QUOTIENT(NUMBER : 91, NUMBER : 3);
cout << " QUOTIENT: " << e.getNumber()  << endl;

MAKE ee = MODULO(NUMBER :90, NUMBER : 55);
cout << " MODULO: " << ee.getNumber() << endl;

MAKE g = WORD:"ena"
MAKE gg = NUMBER : 50;
MAKE t = BOOLEAN : TRUE
MAKE tt = BOOLEAN : FALSE;

if (g == gg)
{
	cout <<"EINAI ISA" << endl;
}
else {
	cout << "DEN EINAI ISA" << endl;
}

;MAKE mpamia = LIST[NUMBER: 0, NUMBER: 255, NUMBER: 255];
output(mpamia);
//mpamia = LIST[NUMBER: 2, NUMBER: 5, mpamia];
//output(mpamia);

const char *msg = "START";
init_GUI();
*/
/*
cout << gg.getType();
//SETPENCOLOR(mpamia);
//FORWARD(gg);
FORWARD gg
SETSCREENCOLOR mpamia
//SETSCREENCOLOR(LIST[NUMBER: 0, NUMBER: 255, NUMBER: 255]);
//set_screen_color(0, 255, 255);
;set_pen_color(0, 0, 0);
SETPENSIZE NUMBER: 1;
LEFT gg;
FORWARD NUMBER: 200;
//set_pen_thickness(0.1f);
//SETPENCOLOR[];
//SETSCREENCOLOR([NUMBER: 0, NUMBER: 255, NUMBER: 255]);
turtle_draw_label(msg);
CENTER
*/

/*
for (int i = 0; i < 360; i++)
{
turtle_mv_backward(2);
turtle_rotate(1);
}

pen_up();
turtle_go_to_position(200, 200);
pen_down();
turtle_draw_label("BREAKPOINT");
for (int i = 0; i < 4; i++)
{
turtle_mv_forward(100);
turtle_rotate(90);
}

pen_up();
turtle_go_to_position(200, 300);
pen_down();

msg = "END";
turtle_draw_label(msg);
*/
//destroy_GUI();

//MAKE v5 = LIST[NUMBER: 5, WORD: "pente"]
//MAKE v6 = LIST[NUMBER: 6, WORD: "eksi"]
//MAKE v10 = LIST[NUMBER: 10, v5]
//MAKE v15 = LIST[NUMBER: 99, v10]
MAKE v5 = ARRAY{NUMBER: 5, WORD: "negro"}
MAKE v6 = ARRAY{NUMBER: 6, WORD: "eksi"}
MAKE v10 = ARRAY{NUMBER: 10, v5}

SETITEM({2,2}, v10, WORD: "yo");
//SETITEM({2,2,2}, v15, v6);

;output(v10);
//;cout << "----------------------------\n";
//output(v15);


//IF AND(5 == 5) DO
//cout << "YO";
//END




;PROGRAM_END_PRINT
END_PROGRAM
