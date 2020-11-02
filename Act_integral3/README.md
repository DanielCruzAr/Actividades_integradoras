# Actividad integral 3
Para esta actividad edité el archivo de ventas para poder guardar todos los datos numéricos en vectores.
Después de que se guardan los datos en vectores, se crean cuatro árboles heap con los datos de los vectores.
Decidí hacerlo de esta manera para que los datos se ordenen por todos los atributos de la bitácora, excluyendo el producto.
## Casos prueba
Logs test;
string file = "ventas.txt";

test.lee("archivo.incorrecto"); //Despliega un mensaje de que el archivo no se ha encontrado

test.lee(file);

test.pop("producto"); //Despliega un mensaje de que no exixte ese heap

test.clear(); //Se borran todos los heaps

test.pop("fecha"); //Despliega un mensaje diciendo que no hay datos en el heap
