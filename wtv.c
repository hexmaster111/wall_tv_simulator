#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <raylib.h>
#include <raymath.h>

enum edirection
{
    // change me if things look wrong
    DRAW_X_NEGITIVE = -1,
    DRAW_X_POSITIVE = 1,

    // change me if things look wrong
    DRAW_Y_NEGITIVE = 1,
    DRAW_Y_POSITIVE = -1,
};

/* globals in arduino code */
int g_x, g_y;
int g_x_dir, g_y_dir; // -1 neg, +1 pos

/* Not in arduino code, real code uses digitalRead() */
int g_laser_state;

void _plot_point()
{
    if (g_laser_state == 1)
        DrawPixel(g_x, g_y, YELLOW);

    // if (g_laser_state == 0)
    //     DrawPixel(g_x, g_y, PURPLE);
}
// NOTE: Arduino API
void STEP_X()
{
    g_x += g_x_dir;
    _plot_point();
}

// NOTE: Arduino API
void SET_X_DIR(enum edirection dir)
{
    if (dir != g_x_dir)
        g_x_dir = dir;
}

// NOTE: Arduino API
void STEP_Y()
{
    g_y += g_y_dir;
    _plot_point();
}

// NOTE: Arduino API
void SET_Y_DIR(enum edirection dir)
{
    if (dir != g_y_dir)
        g_y_dir = dir;
}

// NOTE: Arduino API
void LASER_ON()
{
    g_laser_state = 1;
}

// NOTE: Arduino API
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

#define DRAW_FORI(SOME) for (int i = 0; i < (SOME); i++)
#define DRAW_CHAR_SIZE (20)
#define DRAW_CHAR_PAD (5)

void _drawA()
{
    SET_X_DIR(DRAW_X_POSITIVE);
    SET_Y_DIR(DRAW_Y_NEGITIVE);

    for (int i = 0; i < (.5 * DRAW_CHAR_SIZE); i++)
    {
        STEP_Y();
    }

    for (int i = 0; i < (.5 * DRAW_CHAR_SIZE); i++)
    {
        STEP_Y();
        STEP_X();
    }

    SET_Y_DIR(DRAW_Y_POSITIVE);

    for (int i = 0; i < (.5 * DRAW_CHAR_SIZE); i++)
    {
        STEP_Y();
        STEP_X();
    }

    LASER_OFF();
    SET_X_DIR(DRAW_X_NEGITIVE);
    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X(); // MOVE_X
    }

    LASER_ON();

    SET_X_DIR(DRAW_X_POSITIVE);
    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X(); // MOVE_X
    }

    for (int i = 0; i < (.5 * DRAW_CHAR_SIZE); i++)
    {
        STEP_Y();
    }
}
void _drawB()
{
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    SET_X_DIR(DRAW_X_POSITIVE);
    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_Y();
    }

    for (int i = 0; i < (DRAW_CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    SET_Y_DIR(DRAW_Y_POSITIVE);
    for (int i = 0; i < (DRAW_CHAR_SIZE * .5); i++)
    {
        STEP_Y();
    }

    LASER_OFF();
    SET_X_DIR(DRAW_X_NEGITIVE);
    for (int i = 0; i < (DRAW_CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    LASER_ON();
    SET_X_DIR(DRAW_X_POSITIVE);
    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X();
    }

    for (int i = 0; i < (DRAW_CHAR_SIZE * .5); i++)
    {
        STEP_Y();
    }

    LASER_OFF();

    SET_X_DIR(DRAW_X_NEGITIVE);
    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X();
    }

    LASER_ON();

    SET_X_DIR(DRAW_X_POSITIVE);
    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X();
    }
}
void _drawC()
{
    SET_X_DIR(DRAW_X_POSITIVE);
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    LASER_OFF();
    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X();
        STEP_Y();
    }
    LASER_ON();
    SET_X_DIR(DRAW_X_NEGITIVE);
    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X();
    }
    SET_Y_DIR(DRAW_Y_POSITIVE);
    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_Y();
    }
    SET_X_DIR(DRAW_X_POSITIVE);
    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X();
    }
}
void _drawD()
{
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_Y();
    }

    SET_Y_DIR(DRAW_Y_POSITIVE);

    for (int i = 0; i < (.5 * DRAW_CHAR_SIZE); i++)
    {
        STEP_Y();
        STEP_X();
    }

    SET_X_DIR(DRAW_X_NEGITIVE);
    for (int i = 0; i < (.5 * DRAW_CHAR_SIZE); i++)
    {
        STEP_Y();
        STEP_X();
    }

    LASER_OFF();
    SET_X_DIR(DRAW_X_POSITIVE);

    for (int i = 0; i < (.5 * DRAW_CHAR_SIZE); i++)
    {
        STEP_X();
    }
}
void _drawE()
{
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    SET_X_DIR(DRAW_X_POSITIVE);

    LASER_OFF();

    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X();
        STEP_Y();
    }

    LASER_ON();
    SET_X_DIR(DRAW_X_NEGITIVE);

    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X();
    }

    SET_Y_DIR(DRAW_Y_POSITIVE);

    for (int i = 0; i < (DRAW_CHAR_SIZE * .5); i++)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_POSITIVE);

    for (int i = 0; i < (DRAW_CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    SET_X_DIR(DRAW_X_NEGITIVE);

    for (int i = 0; i < (DRAW_CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    for (int i = 0; i < (DRAW_CHAR_SIZE * .5); i++)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_POSITIVE);

    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X();
    }
}
void _drawF()
{
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    SET_X_DIR(DRAW_X_POSITIVE);

    LASER_OFF();

    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X();
        STEP_Y();
    }

    LASER_ON();
    SET_X_DIR(DRAW_X_NEGITIVE);

    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X();
    }

    SET_Y_DIR(DRAW_Y_POSITIVE);

    for (int i = 0; i < (DRAW_CHAR_SIZE * .5); i++)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_POSITIVE);

    for (int i = 0; i < (DRAW_CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    SET_X_DIR(DRAW_X_NEGITIVE);

    for (int i = 0; i < (DRAW_CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    for (int i = 0; i < (DRAW_CHAR_SIZE * .5); i++)
    {
        STEP_Y();
    }

    LASER_OFF();
    SET_X_DIR(DRAW_X_POSITIVE);

    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X();
    }

    LASER_ON();
}
void _drawG()
{
    SET_X_DIR(DRAW_X_POSITIVE);
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    LASER_OFF();
    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X();
        STEP_Y();
    }

    LASER_ON();
    SET_X_DIR(DRAW_X_NEGITIVE);
    SET_Y_DIR(DRAW_Y_POSITIVE);

    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X();
    }

    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_POSITIVE);

    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X();
    }

    SET_Y_DIR(DRAW_Y_NEGITIVE);

    for (int i = 0; i < (DRAW_CHAR_SIZE * .5); i++)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_NEGITIVE);

    for (int i = 0; i < (DRAW_CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    LASER_OFF();

    SET_X_DIR(DRAW_X_POSITIVE);
    SET_Y_DIR(DRAW_Y_POSITIVE);

    for (int i = 0; i < (DRAW_CHAR_SIZE * .5); i++)
    {
        STEP_X();
        STEP_Y();
    }
}
void _drawH()
{
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_Y();
    }

    LASER_OFF();

    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X();
    }

    LASER_ON();

    SET_Y_DIR(DRAW_Y_POSITIVE);
    for (int i = 0; i < (DRAW_CHAR_SIZE * .5); i++)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_NEGITIVE);

    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X();
    }

    LASER_OFF();
    SET_X_DIR(DRAW_X_POSITIVE);
    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X();
    }

    LASER_ON();
    for (int i = 0; i < (DRAW_CHAR_SIZE * .5); i++)
    {
        STEP_Y();
    }
}
void _drawI()
{
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    LASER_OFF();
    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X();
        STEP_Y();
    }
    LASER_ON();

    SET_X_DIR(DRAW_X_NEGITIVE);
    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X();
    }

    SET_X_DIR(DRAW_X_POSITIVE);
    for (int i = 0; i < (DRAW_CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    SET_Y_DIR(DRAW_Y_POSITIVE);
    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_Y();
    }
    LASER_OFF();
    SET_X_DIR(DRAW_X_NEGITIVE);
    for (int i = 0; i < (DRAW_CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    LASER_ON();
    SET_X_DIR(DRAW_X_POSITIVE);
    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X();
    }
}
void _drawJ()
{
    LASER_OFF();
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_Y();
    }
    LASER_ON();
    SET_X_DIR(DRAW_X_POSITIVE);

    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_X();
    }

    SET_X_DIR(DRAW_X_NEGITIVE);

    for (int i = 0; i < (DRAW_CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    SET_Y_DIR(DRAW_Y_POSITIVE);

    for (int i = 0; i < DRAW_CHAR_SIZE; i++)
    {
        STEP_Y();
    }

    for (int i = 0; i < (DRAW_CHAR_SIZE * .5); i++)
    {
        STEP_X();
    }

    LASER_OFF();

    SET_X_DIR(DRAW_X_POSITIVE);

    for (int i = 0; i < (DRAW_CHAR_SIZE); i++)
    {
        STEP_X();
    }

    LASER_ON();
}
void _drawK()
{
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
        STEP_X();
    }

    SET_X_DIR(DRAW_X_NEGITIVE);
    SET_Y_DIR(DRAW_Y_POSITIVE);
    LASER_OFF();
    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
        STEP_X();
    }
    LASER_ON();

    SET_X_DIR(DRAW_X_POSITIVE);
    SET_Y_DIR(DRAW_Y_POSITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
        STEP_X();
    }

    SET_X_DIR(DRAW_X_NEGITIVE);
    SET_Y_DIR(DRAW_Y_NEGITIVE);

    LASER_OFF();
    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
        STEP_X();
    }
    LASER_ON();

    SET_Y_DIR(DRAW_Y_NEGITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    LASER_OFF();
    SET_X_DIR(DRAW_X_POSITIVE);
    SET_Y_DIR(DRAW_Y_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_X();
        STEP_Y();
    }

    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
    }
    LASER_ON();
}
void _drawL()
{
    LASER_OFF();
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }

    SET_Y_DIR(DRAW_Y_POSITIVE);
    LASER_ON();
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }

    DRAW_FORI(DRAW_CHAR_SIZE * .50)
    {
        STEP_X();
    }

    LASER_OFF();

    DRAW_FORI(DRAW_CHAR_SIZE * .50)
    {
        STEP_X();
    }

    LASER_ON();
}
void _drawM()
{
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }

    SET_Y_DIR(DRAW_Y_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_X();
        STEP_Y();
    }

    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_X();
        STEP_Y();
    }
    SET_Y_DIR(DRAW_Y_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }
}
void _drawN()
{

    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }

    SET_Y_DIR(DRAW_Y_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
        STEP_Y();
    }

    SET_Y_DIR(DRAW_Y_NEGITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }

    LASER_OFF();

    SET_Y_DIR(DRAW_Y_POSITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }

    LASER_ON();
}
void _drawO()
{

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    SET_Y_DIR(DRAW_Y_NEGITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_NEGITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    SET_Y_DIR(DRAW_Y_POSITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_POSITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }
}
void _drawP()
{
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    SET_Y_DIR(DRAW_Y_POSITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_NEGITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    LASER_OFF();
    SET_X_DIR(DRAW_X_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
    }
    LASER_ON();
}
void _drawQ()
{
    LASER_OFF();
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE * .25)
    {
        STEP_Y();
    }
    LASER_ON();

    DRAW_FORI(DRAW_CHAR_SIZE * .75)
    {
        STEP_X();
    }

    DRAW_FORI(DRAW_CHAR_SIZE * .75)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_NEGITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE * .75)
    {
        STEP_X();
    }

    SET_Y_DIR(DRAW_Y_POSITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE * .75)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_POSITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE * .75)
    {
        STEP_X();
    }

    SET_Y_DIR(DRAW_Y_NEGITIVE);
    SET_X_DIR(DRAW_X_NEGITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE * .25)
    {
        STEP_X();
        STEP_Y();
    }
    SET_X_DIR(DRAW_X_POSITIVE);
    SET_Y_DIR(DRAW_Y_POSITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_X();
        STEP_Y();
    }
}
void _drawR()
{

    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    SET_Y_DIR(DRAW_Y_POSITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_NEGITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    SET_X_DIR(DRAW_X_POSITIVE);
    char blink = 0;
    DRAW_FORI(DRAW_CHAR_SIZE)
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
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
        STEP_Y();
    }
    LASER_ON();

    SET_X_DIR(DRAW_X_NEGITIVE);
    SET_Y_DIR(DRAW_Y_POSITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_POSITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_NEGITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    LASER_OFF();

    SET_X_DIR(DRAW_X_POSITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    LASER_ON();
}
void _drawT()
{
    LASER_OFF();
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    SET_X_DIR(DRAW_X_NEGITIVE);

    DRAW_FORI((DRAW_CHAR_SIZE * .5))
    {
        STEP_X();
    }

    SET_Y_DIR(DRAW_Y_POSITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }

    LASER_OFF();

    SET_X_DIR(DRAW_X_POSITIVE);

    DRAW_FORI((DRAW_CHAR_SIZE * .5))
    {
        STEP_X();
    }

    LASER_ON();
}
void _drawU()
{
    LASER_OFF();
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();

    SET_Y_DIR(DRAW_Y_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }

    LASER_OFF();
    SET_Y_DIR(DRAW_Y_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();
}
void _drawV()
{
    LASER_OFF();
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();

    SET_Y_DIR(DRAW_Y_POSITIVE);

    char blink = 0;
    DRAW_FORI(DRAW_CHAR_SIZE)
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

    SET_Y_DIR(DRAW_Y_NEGITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
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

    SET_Y_DIR(DRAW_Y_POSITIVE);
    LASER_OFF();
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();
}
void _drawW()
{
    LASER_OFF();
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();

    SET_Y_DIR(DRAW_Y_POSITIVE);

    char blink = 0;

    DRAW_FORI(DRAW_CHAR_SIZE)
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

    SET_Y_DIR(DRAW_Y_NEGITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
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

    SET_Y_DIR(DRAW_Y_POSITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
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

    SET_Y_DIR(DRAW_Y_NEGITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
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
    SET_Y_DIR(DRAW_Y_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();
}
void _drawX()
{
    LASER_OFF();
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
        STEP_X();
    }
    LASER_ON();

    SET_X_DIR(DRAW_X_NEGITIVE);
    SET_Y_DIR(DRAW_Y_POSITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
        STEP_X();
    }

    LASER_OFF();
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();

    SET_X_DIR(DRAW_X_POSITIVE);
    SET_Y_DIR(DRAW_Y_POSITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
        STEP_X();
    }
}
void _drawY()
{
    LASER_OFF();
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();
    SET_Y_DIR(DRAW_Y_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
        STEP_X();
    }
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
        STEP_X();
    }
    LASER_OFF();
    SET_Y_DIR(DRAW_Y_POSITIVE);
    SET_X_DIR(DRAW_X_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
        STEP_X();
    }
    LASER_ON();

    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
    }
    SET_X_DIR(DRAW_X_POSITIVE);
    LASER_OFF();
    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_X();
    }
    LASER_ON();
}
void _drawZ()
{
    LASER_OFF();
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();
    SET_Y_DIR(DRAW_Y_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }
    SET_X_DIR(DRAW_X_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
        STEP_Y();
    }
    SET_X_DIR(DRAW_X_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }
}
void _draw0()
{
    SET_Y_DIR(DRAW_Y_NEGITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
        STEP_X();
    }

    LASER_OFF();

    SET_X_DIR(DRAW_X_NEGITIVE);
    SET_Y_DIR(DRAW_Y_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
        STEP_X();
    }
    SET_X_DIR(DRAW_X_POSITIVE);
    LASER_ON();

    // O VVVV

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    SET_Y_DIR(DRAW_Y_NEGITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_NEGITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    SET_Y_DIR(DRAW_Y_POSITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_POSITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }
}
void _draw1()
{
    LASER_OFF();
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
    }
    LASER_ON();
    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
        STEP_X();
    }

    SET_Y_DIR(DRAW_Y_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_X();
    }

    SET_X_DIR(DRAW_X_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }
}
void _draw2()
{
    LASER_OFF();
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    SET_Y_DIR(DRAW_Y_POSITIVE);
    SET_X_DIR(DRAW_X_NEGITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_POSITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }
}
void _draw3()
{
    LASER_OFF();
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    SET_Y_DIR(DRAW_Y_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_NEGITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    SET_X_DIR(DRAW_X_POSITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_NEGITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    SET_X_DIR(DRAW_X_POSITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }
}
void _draw4()
{
    LASER_OFF();
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();

    SET_Y_DIR(DRAW_Y_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    SET_Y_DIR(DRAW_Y_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }
}
void _draw5() { _drawS(); }
void _draw6()
{
    LASER_OFF();
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();

    SET_Y_DIR(DRAW_Y_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    LASER_OFF();
    SET_X_DIR(DRAW_X_POSITIVE);
    SET_Y_DIR(DRAW_Y_POSITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
        STEP_X();
    }

    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_X();
    }
}
void _draw7()
{
    LASER_OFF();
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }
    LASER_ON();
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }
    SET_Y_DIR(DRAW_Y_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }
}
void _draw8()
{
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }
    SET_X_DIR(DRAW_X_NEGITIVE);

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }
    SET_X_DIR(DRAW_X_POSITIVE);

    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }
    SET_Y_DIR(DRAW_Y_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
    }
    SET_X_DIR(DRAW_X_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }
    SET_X_DIR(DRAW_X_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }
    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
    }
}
void _draw9()
{
    LASER_OFF();
    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
    }
    LASER_ON();

    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }
    SET_X_DIR(DRAW_X_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }
    DRAW_FORI(DRAW_CHAR_SIZE * .5)
    {
        STEP_Y();
    }
    SET_X_DIR(DRAW_X_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }
    SET_Y_DIR(DRAW_Y_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_Y();
    }
}
void _drawPoint()
{
    LASER_OFF();
    DRAW_FORI(DRAW_CHAR_SIZE)
    {
        STEP_X();
    }

    LASER_ON();

    SET_Y_DIR(DRAW_Y_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE * .25)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_NEGITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE * .25)
    {
        STEP_X();
    }

    SET_Y_DIR(DRAW_Y_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE * .25)
    {
        STEP_Y();
    }

    SET_X_DIR(DRAW_X_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE * .25)
    {
        STEP_X();
    }
}
void _drawSpace()
{
    LASER_OFF();
    SET_X_DIR(DRAW_X_POSITIVE);
    DRAW_FORI(DRAW_CHAR_SIZE)
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
    for (int i = 0; i < DRAW_CHAR_PAD; i++)
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

    SET_X_DIR(DRAW_X_NEGITIVE);
    SET_Y_DIR(DRAW_Y_NEGITIVE);

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

    int gx_init = 700;
    float tmp = gx_init;
    while (!WindowShouldClose())
    {
        g_x = gx_init, g_y = 50;
        SET_X_DIR(DRAW_X_POSITIVE), SET_Y_DIR(DRAW_Y_POSITIVE);

        BeginDrawing();
        ClearBackground(BLACK);

        GuiSlider((Rectangle){10, 10, 300, 10}, "", "", &tmp, 0, GetScreenWidth());
        gx_init = tmp;

        DrawString("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        g_x = gx_init, g_y = g_y + DRAW_CHAR_SIZE + DRAW_CHAR_PAD;
        DrawString("0123456789!@#$%^&*()-");
        g_x = gx_init, g_y = g_y + DRAW_CHAR_SIZE + DRAW_CHAR_PAD;
        DrawString("1.123%");
        g_x = gx_init, g_y = g_y + DRAW_CHAR_SIZE + DRAW_CHAR_PAD;
        DrawString("To Error is turkey!");
        g_x = gx_init, g_y = g_y + DRAW_CHAR_SIZE + DRAW_CHAR_PAD;
        DrawString("Hello world!");

        EndDrawing();
    }

    CloseWindow();
    return 0;
}