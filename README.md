# mutex_task

To write two classes WorkerOne and WorkerTwo, which contain the object of the third class;
In the third class there is a print method which receives a tape parameter which writes a word hello + the received tape in the console;
The code in that method must use a mutex to synchronize access;
Classes WorkerOne and WorkerTwo pass their names to the print method (constant value).