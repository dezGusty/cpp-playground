#pragma once

#include <iostream>

enum Color {red, green, blue, white, yellow};

struct Books
{
  int book_id;
  char title[50];
  char author[30];
};

void call_if();

void call_cascaded_if(int param);

void call_switch(Color param);

void call_while(int param);

bool call_for(const int input, int& out_sum);

bool call_for_updated(const int input, int& out_sum);

bool call_arrays();

bool call_struct(Books input);