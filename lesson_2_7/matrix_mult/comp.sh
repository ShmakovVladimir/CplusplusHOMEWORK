g++ -c main.cpp -funroll-loops -ftree-vectorize -ftree-vectorizer-verbose=1 -pthread
g++ -c matrix.cpp -funroll-loops -ftree-vectorize -ftree-vectorizer-verbose=1 -pthread
g++ -o mat main.o matrix.o
