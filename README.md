If you want to link files dynamically follow this instructions!

1.First include file with prototypes in your main #include "Dynstrprot.h"

2.Second thing to do is creating shared object file with implementations of functions  | gcc -shared DynStrimp.c -o DynStrimp.so

3.The final step is to gcc your main file with your shared file | gcc yourfilename.c ./DynStrimp.so

Congratulations!!
