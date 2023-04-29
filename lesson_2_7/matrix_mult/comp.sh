g++ -c main.cpp -funroll-loops -ftree-vectorize -ftree-vectorizer-verbose=1
g++ -c matrix.cpp -funroll-loops -ftree-vectorize -ftree-vectorizer-verbose=1
g++ -o mat main.o matrix.o
