#include <ncurses.h>
#include <iostream>
#include <string>
#include "Scene.h"
#include "Stage.h"
#include <thread>
using std::this_thread::sleep_for;

Scene::Scene()
{
    Scene::width = 90;
    Scene::height = 100;
}

void Scene::startScene()
{
    initscr();
    resize_term(height, width);
    curs_set(0);
    noecho();
    border('|', '|', '-', '-', '*', '*', '*', '*');
    mvprintw(1, 3, "JEOJJEOL SNAKE");
    refresh();
    return;
}

WINDOW *Scene::gamingScene(int stage, Snake snake)
{
    WINDOW *winGaming;
    winGaming = newwin(23, 58, 4, 4);
    MapSet mapset;
    if (stage == 0)
    {
    }
    else if (stage == 1)
    {
        mapset.LoadMap(0);
        mapset.moveSnake(snake);
        mvwprintw(winGaming, 0, 0, "Stage One");
        for (int i = 0; i < mapset.getrow(); i++)
            mvwprintw(winGaming, i + 2, 0, mapset.getMap(i));
    }
    else if (stage == 2)
    {
        mapset.LoadMap(1);
        mapset.moveSnake(snake);
        mvwprintw(winGaming, 0, 0, "Stage Two");
        for (int i = 0; i < mapset.getrow(); i++)
            mvwprintw(winGaming, i + 2, 0, mapset.getMap(i));
    }
    else if (stage == 3)
    {
        mapset.LoadMap(2);
        mapset.moveSnake(snake);
        mvwprintw(winGaming, 0, 0, "Stage Three");
        for (int i = 0; i < mapset.getrow(); i++)
            mvwprintw(winGaming, i + 2, 0, mapset.getMap(i));
    }
    else if (stage == 4)
    {

        mapset.LoadMap(3);
        mapset.moveSnake(snake);
        mvwprintw(winGaming, 0, 0, "Stage Four");
        for (int i = 0; i < mapset.getrow(); i++)
            mvwprintw(winGaming, i + 2, 0, mapset.getMap(i));
    }
    wrefresh(winGaming);
    return winGaming;
}

WINDOW *Scene::changeScene(int stage, Snake snake)
{
    WINDOW *winScene;

    WINDOW *winUser;
    WINDOW *trash;

    winScene = newwin(25, 60, 3, 3);
    winUser = newwin(5, 15, 13, 70);

    MapSet mapset;
    start_color();

    init_pair(0, COLOR_BLUE, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);

    wborder(winScene, '*', '*', '*', '*', '*', '*', '*', '*');
    wborder(winUser, '|', '|', '-', '-', '+', '+', '+', '+');

    // Scene window control
    if (stage == 0)
    {
        wbkgd(winScene, COLOR_PAIR(0));
        wattron(winScene, COLOR_PAIR(0));
        mvwprintw(winScene, 5, 5, "Press Any Key To Start Snake Game!");
    }
    else if (stage == 1)
    {
        wbkgd(winScene, COLOR_PAIR(1));
        wattron(winScene, COLOR_PAIR(1));
        mvwprintw(winScene, 1, 1, "Stage One");
    }
    else if (stage == 2)
    {
        wbkgd(winScene, COLOR_PAIR(2));
        wattron(winScene, COLOR_PAIR(2));
        mvwprintw(winScene, 1, 1, "Stage Two");
    }
    else if (stage == 3)
    {
        wbkgd(winScene, COLOR_PAIR(3));
        wattron(winScene, COLOR_PAIR(3));
        mvwprintw(winScene, 1, 1, "Stage Three");
    }
    else
    {
        wbkgd(winScene, COLOR_PAIR(4));
        wattron(winScene, COLOR_PAIR(4));
        mvwprintw(winScene, 1, 1, "Stage Four");
    }

    // Mission Board
    mvwprintw(winUser, 1, 1, "Name:");
    mvwprintw(winUser, 2, 1, "User");

    wrefresh(winScene);

    // wrefresh(winScore);
    wrefresh(winUser);
    return winScene;
}
