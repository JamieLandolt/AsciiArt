CC = gcc
CFLAGS = -Wall -pedantic -std=gnu99
LDFLAGS = -lm
OUT = main

all: $(OUT)

$(OUT): main.c
