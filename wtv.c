#include <raylib.h>

enum edirection
{
    POSITIVE = 1,
    NEGITIVE = -1
};

int g_x, g_y;
int g_x_dir, g_y_dir; // -1 neg, +1 pos
int g_laser_state;

void _plot_point()
{
    if (g_laser_state)
        DrawPixel(g_x, g_y, YELLOW);
}

void STEP_X()
{
    g_x += g_x_dir;
    _plot_point();
}

void SET_X_DIR(enum edirection dir)
{
    if (dir != g_x_dir)
        g_x_dir = dir;
}

void STEP_Y()
{
    g_y += g_y_dir;
    _plot_point();
}

void SET_Y_DIR(enum edirection dir)
{
    if (dir != g_y_dir)
        g_y_dir = dir;
}

void LASER_ON()
{
    g_laser_state = 1;
}

void LASER_OFF()
{
    g_laser_state = 0;
}

#define CHAR_SIZE (20)
#define CHAR_PAD (5)

/*
 *     When calling a _draw'char' func,
 *          laser should be on
 *          in the bottem left corner of the start of the char
 *     _draw'char' will leave XDIR(POSITIVE)
 */

void _drawA()
{
    SET_X_DIR(POSITIVE);
    SET_Y_DIR(NEGITIVE);

    for (int i = 0; i < (.5 * CHAR_SIZE); i++)
    {
        STEP_Y();
    }

    for (int i = 0; i < (.5 * CHAR_SIZE); i++)
    {
        STEP_Y();
        STEP_X();
    }

    SET_Y_DIR(POSITIVE);

    for (int i = 0; i < (.5 * CHAR_SIZE); i++)
    {
        STEP_Y();
        STEP_X();
    }

    LASER_OFF();
    SET_X_DIR(NEGITIVE);
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X(); // MOVE_X
    }

    LASER_ON();

    SET_X_DIR(POSITIVE);
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X(); // MOVE_X
    }

    for (int i = 0; i < (.5 * CHAR_SIZE); i++)
    {
        STEP_Y();
    }
}
void _drawB()
{
    SET_Y_DIR(NEGITIVE);
    SET_X_DIR(POSITIVE);
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_Y();
    }

    for (int i = 0; i < (CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    SET_Y_DIR(POSITIVE);
    for (int i = 0; i < (CHAR_SIZE * .5); i++)
    {
        STEP_Y();
    }

    LASER_OFF();
    SET_X_DIR(NEGITIVE);
    for (int i = 0; i < (CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    LASER_ON();
    SET_X_DIR(POSITIVE);
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X();
    }

    for (int i = 0; i < (CHAR_SIZE * .5); i++)
    {
        STEP_Y();
    }

    LASER_OFF();

    SET_X_DIR(NEGITIVE);
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X();
    }

    LASER_ON();

    SET_X_DIR(POSITIVE);
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X();
    }
}
void _drawC()
{
    SET_X_DIR(POSITIVE);
    SET_Y_DIR(NEGITIVE);
    LASER_OFF();
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X();
        STEP_Y();
    }
    LASER_ON();
    SET_X_DIR(NEGITIVE);
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X();
    }
    SET_Y_DIR(POSITIVE);
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_Y();
    }
    SET_X_DIR(POSITIVE);
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X();
    }
}
void _drawD()
{
    SET_Y_DIR(NEGITIVE);
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_Y();
    }

    SET_Y_DIR(POSITIVE);

    for (int i = 0; i < (.5 * CHAR_SIZE); i++)
    {
        STEP_Y();
        STEP_X();
    }

    SET_X_DIR(NEGITIVE);
    for (int i = 0; i < (.5 * CHAR_SIZE); i++)
    {
        STEP_Y();
        STEP_X();
    }

    LASER_OFF();
    SET_X_DIR(POSITIVE);

    for (int i = 0; i < (.5 * CHAR_SIZE); i++)
    {
        STEP_X();
    }
}
void _drawE()
{
    SET_Y_DIR(NEGITIVE);
    SET_X_DIR(POSITIVE);

    LASER_OFF();

    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X();
        STEP_Y();
    }

    LASER_ON();
    SET_X_DIR(NEGITIVE);

    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X();
    }

    SET_Y_DIR(POSITIVE);

    for (int i = 0; i < (CHAR_SIZE * .5); i++)
    {
        STEP_Y();
    }

    SET_X_DIR(POSITIVE);

    for (int i = 0; i < (CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    SET_X_DIR(NEGITIVE);

    for (int i = 0; i < (CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    for (int i = 0; i < (CHAR_SIZE * .5); i++)
    {
        STEP_Y();
    }

    SET_X_DIR(POSITIVE);

    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X();
    }
}
void _drawF()
{
    SET_Y_DIR(NEGITIVE);
    SET_X_DIR(POSITIVE);

    LASER_OFF();

    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X();
        STEP_Y();
    }

    LASER_ON();
    SET_X_DIR(NEGITIVE);

    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X();
    }

    SET_Y_DIR(POSITIVE);

    for (int i = 0; i < (CHAR_SIZE * .5); i++)
    {
        STEP_Y();
    }

    SET_X_DIR(POSITIVE);

    for (int i = 0; i < (CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    SET_X_DIR(NEGITIVE);

    for (int i = 0; i < (CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    for (int i = 0; i < (CHAR_SIZE * .5); i++)
    {
        STEP_Y();
    }

    LASER_OFF();
    SET_X_DIR(POSITIVE);

    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X();
    }

    LASER_ON();
}
void _drawG()
{
    SET_X_DIR(POSITIVE);
    SET_Y_DIR(NEGITIVE);
    LASER_OFF();
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X();
        STEP_Y();
    }

    LASER_ON();
    SET_X_DIR(NEGITIVE);
    SET_Y_DIR(POSITIVE);

    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X();
    }

    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_Y();
    }

    SET_X_DIR(POSITIVE);

    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X();
    }

    SET_Y_DIR(NEGITIVE);

    for (int i = 0; i < (CHAR_SIZE * .5); i++)
    {
        STEP_Y();
    }

    SET_X_DIR(NEGITIVE);

    for (int i = 0; i < (CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    LASER_OFF();

    SET_X_DIR(POSITIVE);
    SET_Y_DIR(POSITIVE);

    for (int i = 0; i < (CHAR_SIZE * .5); i++)
    {
        STEP_X();
        STEP_Y();
    }
}
void _drawH()
{
    SET_Y_DIR(NEGITIVE);
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_Y();
    }

    LASER_OFF();

    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X();
    }

    LASER_ON();

    SET_Y_DIR(POSITIVE);
    for (int i = 0; i < (CHAR_SIZE * .5); i++)
    {
        STEP_Y();
    }

    SET_X_DIR(NEGITIVE);

    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X();
    }

    LASER_OFF();
    SET_X_DIR(POSITIVE);
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X();
    }

    LASER_ON();
    for (int i = 0; i < (CHAR_SIZE * .5); i++)
    {
        STEP_Y();
    }
}
void _drawI()
{
    SET_Y_DIR(NEGITIVE);
    LASER_OFF();
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X();
        STEP_Y();
    }
    LASER_ON();

    SET_X_DIR(NEGITIVE);
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X();
    }

    SET_X_DIR(POSITIVE);
    for (int i = 0; i < (CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    SET_Y_DIR(POSITIVE);
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_Y();
    }
    LASER_OFF();
    SET_X_DIR(NEGITIVE);
    for (int i = 0; i < (CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    LASER_ON();
    SET_X_DIR(POSITIVE);
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X();
    }
}
void _drawJ()
{
    LASER_OFF();
    SET_Y_DIR(NEGITIVE);
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_Y();
    }
    LASER_ON();
    SET_X_DIR(POSITIVE);

    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X();
    }

    SET_X_DIR(NEGITIVE);

    for (int i = 0; i < (CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    SET_Y_DIR(POSITIVE);

    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_Y();
    }

    SET_X_DIR(NEGITIVE);

    for (int i = 0; i < (CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    LASER_OFF();

    SET_X_DIR(POSITIVE);

    for (int i = 0; i < (CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    LASER_ON();
}
void _drawK()
{
    LASER_OFF();
    for (int i = 0; i < .1 * CHAR_SIZE; i++)
    {
        STEP_X();
    }
    LASER_ON();
    SET_Y_DIR(NEGITIVE);
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_Y();
    }

    LASER_OFF();

    SET_X_DIR(POSITIVE);

    for (int i = 0; i < CHAR_SIZE; i++)
        STEP_X();

    LASER_ON();
    SET_Y_DIR(POSITIVE);
    SET_X_DIR(NEGITIVE);
    for (int i = 0; i < CHAR_SIZE * .5; i++)
    {
        STEP_Y();
        STEP_X();
    }
    SET_X_DIR(POSITIVE);
    for (int i = 0; i < CHAR_SIZE * .5; i++)
    {
        STEP_Y();
        STEP_X();
    }
}
void _drawL() {}
void _drawM() {}
void _drawN() {}
void _drawO() {}
void _drawP() {}
void _drawQ() {}
void _drawR() {}
void _drawS() {}
void _drawT() {}
void _drawU() {}
void _drawV() {}
void _drawW() {}
void _drawX() {}
void _drawY() {}
void _drawZ() {}
void _drawSpace()
{
    LASER_OFF();
    SET_X_DIR(POSITIVE);
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        STEP_X();
    }
    LASER_ON();
}

void drawchar(char c)
{
    // clang-format off
    if(c == 'A' || c == 'a') _drawA();
    else if (c == 'B' || c == 'b') _drawB();
    else if (c == 'C' || c == 'c') _drawC();
    else if (c == 'D' || c == 'd') _drawD();
    else if (c == 'E' || c == 'e') _drawE();
    else if (c == 'F' || c == 'f') _drawF();
    else if (c == 'G' || c == 'g') _drawG();
    else if (c == 'H' || c == 'h') _drawH();
    else if (c == 'I' || c == 'i') _drawI();
    else if (c == 'J' || c == 'j') _drawJ();
    else if (c == 'K' || c == 'k') _drawK();
    else if (c == 'L' || c == 'l') _drawL();
    else if (c == 'M' || c == 'm') _drawM();
    else if (c == 'N' || c == 'n') _drawN();
    else if (c == 'O' || c == 'o') _drawO();
    else if (c == 'P' || c == 'p') _drawP();
    else if (c == 'Q' || c == 'q') _drawQ();
    else if (c == 'R' || c == 'r') _drawR();
    else if (c == 'S' || c == 's') _drawS();
    else if (c == 'T' || c == 't') _drawT();
    else if (c == 'U' || c == 'u') _drawU();
    else if (c == 'V' || c == 'v') _drawV();
    else if (c == 'W' || c == 'w') _drawW();
    else if (c == 'X' || c == 'x') _drawX();
    else if (c == 'Y' || c == 'y') _drawY();
    else if (c == 'Z' || c == 'z') _drawZ();
    else if (c == ' ') _drawSpace();

    LASER_OFF();
    for (int i = 0; i < CHAR_PAD; i++)
    {
        STEP_X();
    }
    LASER_ON();

    // clang-format on
}

#include <string.h>
void DrawString(const char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        drawchar(*str);
        str++;
    }
}

void DrawSquare()
{
    for (int i = 0; i < 300; i++)
    {
        STEP_X();
    }

    for (int i = 0; i < 300; i++)
    {
        STEP_Y();
    }

    SET_X_DIR(NEGITIVE);
    SET_Y_DIR(NEGITIVE);

    for (int i = 0; i < 300; i++)
    {
        STEP_X();
    }

    for (int i = 0; i < 300; i++)
    {
        STEP_Y();
    }
}

int main(int argc, char *argv[])
{

    InitWindow(800, 600, "");

    LASER_ON();

    while (!WindowShouldClose())
    {
        g_x = 50, g_y = 50;
        SET_X_DIR(POSITIVE), SET_Y_DIR(POSITIVE);

        BeginDrawing();
        ClearBackground(BLACK);

        DrawString("ABCDEFGHIJK L M N O P Q R S T U V W X Y Z 0 1 2 3 4 5 6 7 8 9 ! @ # $ % ^ & * ( ) -");

        EndDrawing();
    }

    CloseWindow();
    return 0;
}