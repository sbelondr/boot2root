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
import cv2
import numpy as np

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

def lexer(data, pas, direction):
    if data[0] == Way.AVANCE:
        pas += data[1]
    if data[0] == Way.RECULE:
        pas -= data[1]
    if data[0] == Way.LEFT:
        direction -= data[1]
    if data[0] == Way.RIGHT:
        direction += data[1]
    if direction >= 360:
        direction -= 360
    return pas, direction

def draw(image, x, y, pas, direction):
    # Create a named colour
    red = [0,0,255]
    # Change one pixel
    if direction == 90:
        x += 1
        direction -= 90
    elif direction == -90:
        x-= 1
        direction += 90
    if pas > 0:
        y += pas
    else:
        y -= pas
    image[x,y]=red
    return image, x, y

def init_img():
    w=4000
    h=4000
    # Make empty black image
    image=np.zeros((h,w,3),np.uint8)
    return image

def print_img(image):
    # Save
    cv2.imwrite("result.png",image)

def main():
    pas = 0
    direction = 0
    image = init_img()
    x,y = 1000, 1000
    while (1):
        data = file.readline()
        if (data == ""):
            break
        result = parse(data)
        pas, direction = lexer(result, pas, direction)
        if x > 3000 or y > 3000:
            break
        image, x, y = draw(image, x, y,pas, direction)
    print_img(image)
#    print("Pas: " + str(pas) + ", direction: " + str(direction))


if __name__ == "__main__":
    main()
