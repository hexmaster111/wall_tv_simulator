#include <raylib.h>
#include <raymath.h>

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
    if (g_laser_state == 1)
        DrawPixel(g_x, g_y, YELLOW);

    // if (g_laser_state == 0)
    //     DrawPixel(g_x, g_y, PURPLE);
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

/*
 *     When calling a _draw'char' func,
 *          laser should be on
 *          in the bottem left corner of the start of the char
 *     _draw'char' will leave XDIR(POSITIVE)
 */

#define FORI(SOME) for (int i = 0; i < (SOME); i++)
#define CHAR_SIZE (20)
#define CHAR_PAD (5)

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

    for (int i = 0; i < (CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    LASER_OFF();

    SET_X_DIR(POSITIVE);

    for (int i = 0; i < (CHAR_SIZE); i++)
    {
        STEP_X();
    }

    LASER_ON();
}
void _drawK()
{
    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    SET_X_DIR(POSITIVE);
    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
        STEP_X();
    }

    SET_X_DIR(NEGITIVE);
    SET_Y_DIR(POSITIVE);
    LASER_OFF();
    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
        STEP_X();
    }
    LASER_ON();

    SET_X_DIR(POSITIVE);
    SET_Y_DIR(POSITIVE);

    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
        STEP_X();
    }

    SET_X_DIR(NEGITIVE);
    SET_Y_DIR(NEGITIVE);

    LASER_OFF();
    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
        STEP_X();
    }
    LASER_ON();

    SET_Y_DIR(NEGITIVE);

    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    LASER_OFF();
    SET_X_DIR(POSITIVE);
    SET_Y_DIR(POSITIVE);
    FORI(CHAR_SIZE * .5)
    {
        STEP_X();
        STEP_Y();
    }

    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
    }
    LASER_ON();
}
void _drawL()
{
    LASER_OFF();
    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }

    SET_Y_DIR(POSITIVE);
    LASER_ON();
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }

    FORI(CHAR_SIZE * .50)
    {
        STEP_X();
    }

    LASER_OFF();

    FORI(CHAR_SIZE * .50)
    {
        STEP_X();
    }

    LASER_ON();
}
void _drawM()
{
    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }

    SET_Y_DIR(POSITIVE);
    FORI(CHAR_SIZE * .5)
    {
        STEP_X();
        STEP_Y();
    }

    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE * .5)
    {
        STEP_X();
        STEP_Y();
    }
    SET_Y_DIR(POSITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }
}
void _drawN()
{

    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }

    SET_Y_DIR(POSITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_X();
        STEP_Y();
    }

    SET_Y_DIR(NEGITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }

    LASER_OFF();

    SET_Y_DIR(POSITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }

    LASER_ON();
}
void _drawO()
{

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    SET_Y_DIR(NEGITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }

    SET_X_DIR(NEGITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    SET_Y_DIR(POSITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }

    SET_X_DIR(POSITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }
}
void _drawP()
{
    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    SET_Y_DIR(POSITIVE);

    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    SET_X_DIR(NEGITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    LASER_OFF();
    SET_X_DIR(POSITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
    }
    LASER_ON();
}
void _drawQ()
{
    LASER_OFF();
    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE * .25)
    {
        STEP_Y();
    }
    LASER_ON();

    FORI(CHAR_SIZE * .75)
    {
        STEP_X();
    }

    FORI(CHAR_SIZE * .75)
    {
        STEP_Y();
    }

    SET_X_DIR(NEGITIVE);

    FORI(CHAR_SIZE * .75)
    {
        STEP_X();
    }

    SET_Y_DIR(POSITIVE);

    FORI(CHAR_SIZE * .75)
    {
        STEP_Y();
    }

    SET_X_DIR(POSITIVE);

    FORI(CHAR_SIZE * .75)
    {
        STEP_X();
    }

    SET_Y_DIR(NEGITIVE);
    SET_X_DIR(NEGITIVE);

    FORI(CHAR_SIZE * .25)
    {
        STEP_X();
        STEP_Y();
    }
    SET_X_DIR(POSITIVE);
    SET_Y_DIR(POSITIVE);

    FORI(CHAR_SIZE * .5)
    {
        STEP_X();
        STEP_Y();
    }
}
void _drawR()
{

    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    SET_Y_DIR(POSITIVE);

    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    SET_X_DIR(NEGITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    SET_X_DIR(POSITIVE);
    char blink = 0;
    FORI(CHAR_SIZE)
    {
        STEP_X();

        if (!blink)
        {
            STEP_Y();
            blink = 1;
        }
        else
        {
            blink = 0;
        }
    }
}
void _drawS()
{
    LASER_OFF();
    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_X();
        STEP_Y();
    }
    LASER_ON();

    SET_X_DIR(NEGITIVE);
    SET_Y_DIR(POSITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    SET_X_DIR(POSITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    SET_X_DIR(NEGITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    LASER_OFF();

    SET_X_DIR(POSITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    LASER_ON();
}
void _drawT()
{
    LASER_OFF();
    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    SET_X_DIR(NEGITIVE);

    FORI((CHAR_SIZE * .5))
    {
        STEP_X();
    }

    SET_Y_DIR(POSITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }

    LASER_OFF();

    SET_X_DIR(POSITIVE);

    FORI((CHAR_SIZE * .5))
    {
        STEP_X();
    }

    LASER_ON();
}
void _drawU()
{
    LASER_OFF();
    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();

    SET_Y_DIR(POSITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }
    FORI(CHAR_SIZE)
    {
        STEP_X();
    }
    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }

    LASER_OFF();
    SET_Y_DIR(POSITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();
}
void _drawV()
{
    LASER_OFF();
    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();

    SET_Y_DIR(POSITIVE);

    char blink = 0;
    FORI(CHAR_SIZE)
    {
        STEP_Y();

        if (!blink)
        {
            STEP_X();
            blink = 1;
        }
        else
        {
            blink = 0;
        }
    }

    SET_Y_DIR(NEGITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_Y();

        if (!blink)
        {
            STEP_X();
            blink = 1;
        }
        else
        {
            blink = 0;
        }
    }

    SET_Y_DIR(POSITIVE);
    LASER_OFF();
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();
}
void _drawW()
{
    LASER_OFF();
    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();

    SET_Y_DIR(POSITIVE);

    char blink = 0;

    FORI(CHAR_SIZE)
    {
        STEP_Y();

        if (!blink)
        {
            STEP_X();
            blink = 1;
        }
        else if (blink == 1)
        {
            blink = 2;
        }
        else
        {
            blink = 0;
        }
    }

    SET_Y_DIR(NEGITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_Y();

        if (!blink)
        {
            STEP_X();
            blink = 1;
        }
        else if (blink == 1)
        {
            blink = 2;
        }
        else
        {
            blink = 0;
        }
    }

    SET_Y_DIR(POSITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_Y();

        if (!blink)
        {
            STEP_X();
            blink = 1;
        }
        else if (blink == 1)
        {
            blink = 2;
        }
        else
        {
            blink = 0;
        }
    }

    SET_Y_DIR(NEGITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_Y();

        if (!blink)
        {
            STEP_X();
            blink = 1;
        }
        else if (blink == 1)
        {
            blink = 2;
        }
        else
        {
            blink = 0;
        }
    }

    LASER_OFF();
    SET_Y_DIR(POSITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();
}
void _drawX()
{
    LASER_OFF();
    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
        STEP_X();
    }
    LASER_ON();

    SET_X_DIR(NEGITIVE);
    SET_Y_DIR(POSITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_Y();
        STEP_X();
    }

    LASER_OFF();
    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();

    SET_X_DIR(POSITIVE);
    SET_Y_DIR(POSITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_Y();
        STEP_X();
    }
}
void _drawY()
{
    LASER_OFF();
    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();
    SET_Y_DIR(POSITIVE);
    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
        STEP_X();
    }
    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
        STEP_X();
    }
    LASER_OFF();
    SET_Y_DIR(POSITIVE);
    SET_X_DIR(NEGITIVE);
    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
        STEP_X();
    }
    LASER_ON();

    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
    }
    SET_X_DIR(POSITIVE);
    LASER_OFF();
    FORI(CHAR_SIZE * .5)
    {
        STEP_X();
    }
    LASER_ON();
}
void _drawZ()
{
    LASER_OFF();
    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();
    SET_Y_DIR(POSITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_X();
    }
    SET_X_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_X();
        STEP_Y();
    }
    SET_X_DIR(POSITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_X();
    }
}
void _draw0()
{
    SET_Y_DIR(NEGITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_Y();
        STEP_X();
    }

    LASER_OFF();

    SET_X_DIR(NEGITIVE);
    SET_Y_DIR(POSITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
        STEP_X();
    }
    SET_X_DIR(POSITIVE);
    LASER_ON();

    // O VVVV

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    SET_Y_DIR(NEGITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }

    SET_X_DIR(NEGITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    SET_Y_DIR(POSITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }

    SET_X_DIR(POSITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }
}
void _draw1()
{
    LASER_OFF();
    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
    }
    LASER_ON();
    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
        STEP_X();
    }

    SET_Y_DIR(POSITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }

    SET_X_DIR(NEGITIVE);
    FORI(CHAR_SIZE * .5)
    {
        STEP_X();
    }

    SET_X_DIR(POSITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_X();
    }
}
void _draw2()
{
    LASER_OFF();
    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    SET_Y_DIR(POSITIVE);
    SET_X_DIR(NEGITIVE);

    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    SET_X_DIR(POSITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }
}
void _draw3()
{
    LASER_OFF();
    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    SET_Y_DIR(POSITIVE);
    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    SET_X_DIR(NEGITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    SET_X_DIR(POSITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    SET_X_DIR(NEGITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    SET_X_DIR(POSITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }
}
void _draw4()
{
    LASER_OFF();
    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();

    SET_Y_DIR(POSITIVE);
    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    SET_Y_DIR(POSITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }
}
void _draw5() { _drawS(); }
void _draw6()
{
    LASER_OFF();
    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();

    SET_Y_DIR(POSITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    SET_X_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    LASER_OFF();
    SET_X_DIR(POSITIVE);
    SET_Y_DIR(POSITIVE);

    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
        STEP_X();
    }

    FORI(CHAR_SIZE * .5)
    {
        STEP_X();
    }
}
void _draw7()
{
    LASER_OFF();
    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();
    FORI(CHAR_SIZE)
    {
        STEP_X();
    }
    SET_Y_DIR(POSITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }
}
void _draw8()
{
    FORI(CHAR_SIZE)
    {
        STEP_X();
    }
    SET_X_DIR(NEGITIVE);

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }
    SET_X_DIR(POSITIVE);

    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }
    FORI(CHAR_SIZE)
    {
        STEP_X();
    }
    SET_Y_DIR(POSITIVE);
    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
    }
    SET_X_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_X();
    }
    SET_X_DIR(POSITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_X();
    }
    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
    }
}
void _draw9()
{
    LASER_OFF();
    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
    }
    LASER_ON();

    FORI(CHAR_SIZE)
    {
        STEP_X();
    }
    SET_X_DIR(NEGITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_X();
    }
    FORI(CHAR_SIZE * .5)
    {
        STEP_Y();
    }
    SET_X_DIR(POSITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_X();
    }
    SET_Y_DIR(POSITIVE);
    FORI(CHAR_SIZE)
    {
        STEP_Y();
    }
}
void _drawPoint()
{
    LASER_OFF();
    FORI(CHAR_SIZE)
    {
        STEP_X();
    }

    LASER_ON();

    SET_Y_DIR(NEGITIVE);
    FORI(CHAR_SIZE * .25)
    {
        STEP_Y();
    }

    SET_X_DIR(NEGITIVE);
    FORI(CHAR_SIZE * .25)
    {
        STEP_X();
    }

    SET_Y_DIR(POSITIVE);
    FORI(CHAR_SIZE * .25)
    {
        STEP_Y();
    }

    SET_X_DIR(POSITIVE);
    FORI(CHAR_SIZE * .25)
    {
        STEP_X();
    }
}

void _drawSpace()
{
    LASER_OFF();
    SET_X_DIR(POSITIVE);
    FORI(CHAR_SIZE)
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
    else if (c == '0') _draw0();
    else if (c == '1') _draw1();
    else if (c == '2') _draw2();
    else if (c == '3') _draw3();
    else if (c == '4') _draw4();
    else if (c == '5') _draw5();
    else if (c == '6') _draw6();
    else if (c == '7') _draw7();
    else if (c == '8') _draw8();
    else if (c == '9') _draw9();
    else if (c == '.') _drawPoint();
    else if (c == ' ') _drawSpace();
    // clang-format on

    // DrawCircle(g_x, g_y, 2.5, GREEN);

    LASER_OFF();
    for (int i = 0; i < CHAR_PAD; i++)
    {
        STEP_X();
    }
    LASER_ON();
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
    SetTargetFPS(15);

    LASER_ON();

    while (!WindowShouldClose())
    {
        g_x = 50, g_y = 50;
        SET_X_DIR(POSITIVE), SET_Y_DIR(POSITIVE);

        BeginDrawing();
        ClearBackground(BLACK);

        DrawString("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        g_x = 50, g_y = g_y + CHAR_SIZE + CHAR_PAD;
        DrawString("0123456789!@#$%^&*()-");
        g_x = 50, g_y = g_y + CHAR_SIZE + CHAR_PAD;
        DrawString("1.123%");
        g_x = 50, g_y = g_y + CHAR_SIZE + CHAR_PAD;
        DrawString("To Error is turkey!");
        g_x = 50, g_y = g_y + CHAR_SIZE + CHAR_PAD;
        DrawString("Hello world!");

        EndDrawing();
    }

    CloseWindow();
    return 0;
}