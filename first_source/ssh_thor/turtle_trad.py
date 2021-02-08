# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    turtle_trad.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samuel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/07 13:03:41 by samuel            #+#    #+#              #
#    Updated: 2021/02/07 14:04:44 by samuel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from enum import Enum
#import numpy as np
import turtle# import *
#from random import randint

class Way(Enum):
    AVANCE = 0
    RECULE = 1
    LEFT = 2
    RIGHT = 3
    EMPTY = 4

file = open("turtle", "r")


def parse(data):
    data = data.split()
    if len(data) < 1:
        return Way.EMPTY, 0
    if data[0] == "Tourne":
        return Way.LEFT if data[1] == 'gauche' else Way.RIGHT, int(data[3])
    elif data[0] == "Avance":
        return Way.AVANCE, int(data[1])
    elif data[0] == "Recule":
        return Way.RECULE, int(data[1])
    return Way.EMPTY, 0

def turtle_print(turtle_bis):
    turtle.penup()
    turtle.goto(0, 0)
    turtle.setheading(45)
    turtle.pendown()
    turtle.speed(0)

    for data in turtle_bis: 
        rgb_r = 255
        rgb_g = 0
        rgb_b = 0
        angle = 0
        nbpas = 0 

        if data[0] == Way.AVANCE:
            nbpas += data[1]
        if data[0] == Way.RECULE:
            nbpas -= data[1]
        if data[0] == Way.LEFT:
            angle -= data[1]
        if data[0] == Way.RIGHT:
            angle += data[1]
        turtle.color("blue")
        turtle.left(angle)
        turtle.forward(nbpas)
    turtle.done()


def main():
    pas = 0
    direction = 0
    result = list()
    while (1):
        data = file.readline()
        if (data == ""):
            break
        result.append(parse(data))
#        pas, direction = lexer(result, pas, direction)
    turtle_print(result)
#    print("Pas: " + str(pas) + ", direction: " + str(direction))


if __name__ == "__main__":
    main()
