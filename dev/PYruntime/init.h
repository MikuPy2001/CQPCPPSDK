#pragma once

extern
bool init, err; 
extern
PyObject *runtime;
void load_runtime();

PyObject *getCQAPI();