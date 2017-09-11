# author Patrick Tinz
CC = g++

OBJ = CompanyGiroAccount.o Account.o  Menu.o PrivateGiroAccount.o Transaction.o TransactionsGenerator.o Management.o main.o

# program name
TARGET = bankManagement

FLAGS = -g -std=c++14 -Wall -MMD -fmessage-length=0

all: $(TARGET)

#"make clean" delete all *.o files
clean:
	rm bankManagement $(OBJ)

%.o : %.cpp
	$(CC) -c $(FLAGS) -o $@ $<

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)